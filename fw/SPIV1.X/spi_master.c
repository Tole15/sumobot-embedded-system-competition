#include "spi_master.h"

void SPI_Master_Init(spi_clock_t div, spi_mode_t mode)
{
    /* --- pines digitales --- */
    ADCON1 = 0x0F;          /* todos analógicos -> digitales */
    CMCON  = 0x07;          /* comparadores off  */

    /* --- direcciones de TRIS --- */
    TRISBbits.TRISB0 = 1;   /* SDI (entrada)  */
    TRISBbits.TRISB1 = 0;   /* SCK (salida)   */
    TRISCbits.TRISC7 = 0;   /* SDO (salida)   */
    TRISAbits.TRISA5 = 0;   /* SS  (salida)   */

    LATAbits.LATA5 = 1;     /* SS inactivo (alto) */

    /* --- configuración de fase/polaridad --- */
    SSPSTATbits.SMP = 0;    /* muestreo en mitad del periodo        */
    SSPSTATbits.CKE = (mode == SPI_MODE_0 || mode == SPI_MODE_2); /* 1 en modo 0 o 2 */

    SSPCON1bits.CKP = (mode >= 2);   /* CKP = 1 en modo 2/3 */

    /* --- divisor + enable --- */
    SSPCON1 = (SSPCON1 & 0b11110000) | div;
    SSPCON1bits.SSPEN = 1;           /* habilita módulo SPI */
}

/*  Transmite un byte y devuelve de inmediato lo que llega por SDI.
    Bloquea hasta que el byte completo ha salido (BF=1).              */
uint8_t SPI_Master_TxRx(uint8_t dato)
{
    SSPBUF = dato;               /* carga byte a transmitir          */
    while(!SSPSTATbits.BF);      /* espera a que BF = 1 (byte listo) */
    return SSPBUF;               /* lee eco recibido desde el esclavo*/
}
