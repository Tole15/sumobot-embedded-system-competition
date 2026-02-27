/* =========================================================
 *  PIC18F4550 ? línea + encoders   (FW v1.5  23-may-2025)
 *  CPU 48 MHz  ?  UART 115 200 bps  (TX = RC6)  ? ATmega
 *  QTR-1 (delantero) : RD7?RD0                    ? line1
 *  QTR-2 (trasero)   : RE1 RE0 RB4 RB3 RB2 RC2 RC1 RC0 ? line2
 *  EncL : RB0(A) RB1(B)    · EncR : RB6(A) RB7(B)  (IOC)
 *  Trama 50 Hz : 0x55 line1 line2 dR dL chk   (chk = xor)
 * =======================================================*/
#define _XTAL_FREQ 48000000UL
#include <xc.h>
#include <stdint.h>


/* ---------- UART 115 200 ---------- */
static void uart_init(void)
{
    TRISCbits.TRISC6 = 0;                  /* RC6 = TX */
    TXSTA   = 0b00100100;                  /* BRGH=1, TXEN=1          */
    RCSTA   = 0b10010000;                  /* SPEN=1                  */
    BAUDCON = 0b00001000;                  /* BRG16=1                 */
    SPBRGH  = 0x00;
    SPBRG   = 0x67;                        /* 48 MHz/(4·(103+1)) ? 115 384 bps */
}
static inline void uart_put(uint8_t v){ while(!TXSTAbits.TRMT); TXREG = v; }

/* ---------- QTR ---------- */
static inline uint8_t leerLinea1(void){ return PORTD; }

static inline uint8_t leerLinea2(void)
{
    uint8_t c =  PORTC & 0x07;             /* RC2-RC0  ? bits 0-2 */
    uint8_t b = (PORTB & 0x04)<<1  |       /* RB2      ? bit 3    */
                (PORTB & 0x08)<<1  |       /* RB3      ? bit 4    */
                (PORTB & 0x10)<<1;         /* RB4      ? bit 5    */
    uint8_t e = (PORTE & 0x03) << 6;       /* RE0-RE1  ? bits 6-7 */
    return c | b | e;
}

/* ---------- encoders (¼-step) ---------- */
static const int8_t delta[16] = {
     0, +1, -1,  0,  -1,  0,  0, +1,
    +1,  0,  0, -1,   0, -1, +1,  0
};
volatile long cntL = 0, cntR = 0;

void __interrupt() isr(void)
{
    if (INTCONbits.RBIF){
        static uint8_t prev = 0;
        uint8_t rb = PORTB;                /* latch + clear mismatch */
        uint8_t edges = rb ^ prev;

        /* ---- Encoder L  (RB1:RB0) ---- */
        if (edges & 0x03){
            static uint8_t prevL = 0;
            uint8_t currL = rb & 0x03;
            cntL += delta[(prevL<<2)|currL];
            prevL = currL;
        }
        /* ---- Encoder R  (RB7:RB6) ---- */
        if (edges & 0xC0){
            static uint8_t prevR = 0;
            uint8_t currR = (rb>>6) & 0x03;
            cntR += delta[(prevR<<2)|currR];
            prevR = currR;
        }
        prev = rb;
        INTCONbits.RBIF = 0;
    }
}

/* ---------------- MAIN ---------------- */
void main(void)
{
    /* I/O digitales */
    ADCON1 = 0x0F;  CMCON = 0x07;
    TRISD  = 0xFF;                      /* QTR-1            */
    TRISC |= 0x07;                      /* RC2-RC0 in       */
    TRISB |= 0xDF;                      /* RB7-RB0 in (RB5 = boot) */
    TRISE |= 0x03;                      /* RE1-RE0 in       */
    INTCON2bits.RBPU = 0;               /* pull-ups RBx ON  */

    uart_init();

    /* IOC encoders */
    uint8_t dummy = PORTB; (void)dummy;
    INTCONbits.RBIF = 0; INTCONbits.RBIE = 1;
    RCONbits.IPEN   = 0; INTCONbits.GIE  = 1;

    long lastL = 0, lastR = 0;

    while(1)
    {
        uint8_t s1 = leerLinea1();
        uint8_t s2 = leerLinea2();

        /* copia atómica contadores */
        INTCONbits.GIE = 0;
        long curL = cntL, curR = cntR;
        INTCONbits.GIE = 1;

        int16_t dL = (int16_t)(curL - lastL);
        int16_t dR = (int16_t)(curR - lastR);
        lastL = curL;  lastR = curR;

        if(dL>127) dL=127; if(dL<-128) dL=-128;
        if(dR>127) dR=127; if(dR<-128) dR=-128;

        uint8_t chk = s1 ^ s2 ^ (uint8_t)dR ^ (uint8_t)dL;

        uart_put(0x55); uart_put(s1); uart_put(s2);
        uart_put((uint8_t)dR); uart_put((uint8_t)dL); uart_put(chk);

        __delay_ms(20);                 /* 50 Hz */
    }
}
