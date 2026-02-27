#ifndef SPI_MASTER_H
#define SPI_MASTER_H

#include <xc.h>
#include <stdint.h>

/*------------- divisores de reloj (SSPCON1<3:0>) -------------*/
typedef enum {
    SPI_CLK_DIV_4   = 0b0000,   /* Fosc / 4   */
    SPI_CLK_DIV_16  = 0b0001,   /* Fosc / 16  */
    SPI_CLK_DIV_64  = 0b0010,   /* Fosc / 64  */
    SPI_CLK_T2OUT   = 0b0011    /* esclavo-únicamente */
} spi_clock_t;

/*------------- modos CPOL/CPHA (CKP, CKE) --------------------*/
typedef enum {
    SPI_MODE_0 = 0,   /* CKP = 0, CKE = 1 : flanco de subida */
    SPI_MODE_1 = 1,   /* CKP = 0, CKE = 0 : flanco de bajada */
    SPI_MODE_2 = 2,   /* CKP = 1, CKE = 1 : flanco de bajada */
    SPI_MODE_3 = 3    /* CKP = 1, CKE = 0 : flanco de subida */
} spi_mode_t;

/*------------- prototipos -----------------------------------*/
void    SPI_Master_Init(spi_clock_t div, spi_mode_t mode);
uint8_t SPI_Master_TxRx(uint8_t dato);      /* transmite y devuelve eco */

#endif /* SPI_MASTER_H */
