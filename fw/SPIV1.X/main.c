#include <xc.h>
#include <stdint.h>
#include "spi_master.h"

#define _XTAL_FREQ 48000000UL 

void main(void)
{
    SPI_Master_Init(SPI_CLK_DIV_64, SPI_MODE_0);

    /* par de bytes: CONTROL 0x13, DUTY 0x80 */
    LATAbits.LATA5 = 0;                /* SS bajo */
    (void)SPI_Master_TxRx(0x10);
    LATAbits.LATA5 = 1;                /* SS alto */
    __delay_us(50);

    LATAbits.LATA5 = 0;
    (void)SPI_Master_TxRx(0xF0);
    LATAbits.LATA5 = 1;
    __delay_ms(100);

}
