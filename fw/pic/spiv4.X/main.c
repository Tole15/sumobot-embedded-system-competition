#include <xc.h>
#define _XTAL_FREQ 20000000UL

#pragma config PLLDIV   = 5
#pragma config CPUDIV   = OSC1_PLL2
#pragma config USBDIV   = 2
#pragma config FOSC     = HSPLL_HS
#pragma config FCMEN    = OFF
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BOR      = ON
#pragma config BORV     = 3
#pragma config VREGEN   = ON
#pragma config WDT      = OFF
#pragma config WDTPS    = 32768
#pragma config MCLRE    = ON
#pragma config LPT1OSC  = OFF
#pragma config PBADEN   = OFF       
#pragma config STVREN   = ON
#pragma config LVP      = OFF
#pragma config XINST    = OFF       
#pragma config CP0      = OFF
#pragma config CP1      = OFF
#pragma config CPB      = OFF
#pragma config WRT0     = OFF
#pragma config WRT1     = OFF
#pragma config WRTB     = OFF
#pragma config WRTC     = OFF
#pragma config EBTR0    = OFF
#pragma config EBTR1    = OFF
#pragma config EBTRB    = OFF

static void SPI_Init_Master(void)
{
    ADCON1 = 0x0F;
    CMCON  = 0x07;

    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 0;
    TRISCbits.RC7 = 0;
    TRISAbits.RA5 = 0;

    LATAbits.LATA5 = 1;

    SSPSTATbits.CKE = 1;
    SSPCON1 = 0b00100001;
}

static void SPI_Tx(uint8_t dato)
{
    SSPBUF = dato;
    while(!SSPSTATbits.BF);
    (void)SSPBUF;
}

void main(void)
{
    SPI_Init_Master();

    for(;;)
    {
        LATAbits.LATA5 = 0;
        SPI_Tx(0x00);
        LATAbits.LATA5 = 1;
        __delay_ms(500);

        LATAbits.LATA5 = 0;
        SPI_Tx(0x80);
        LATAbits.LATA5 = 1;
        __delay_ms(500);
    }
}