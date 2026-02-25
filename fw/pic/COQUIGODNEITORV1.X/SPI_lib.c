/* 
 * File:   SPI_lib.c
 * Author: Tole Mendoza
 *
 * Created on 25 de abril de 2025, 05:05 PM
 */

#include <xc.h>
#include "config.h"
#include "SPI_lib.h"


void SPI_Init_Master(char reloj, char modo, char smp) {
    
    ADCON1 = 0x0F;   

    TRISBbits.RB0 = 1;    
    TRISBbits.RB1 = 0;    
    TRISAbits.TRISA5 = 0; 
    TRISCbits.TRISC7 = 0; 

    
    SSPCON1bits.SSPM = reloj & 0x0F;

    
    switch (modo) {
        case MODO_1:
            SSPCON1bits.CKP  = 1;
            SSPSTATbits.CKE = 1;
            break;
        case MODO_2:
            SSPCON1bits.CKP  = 0;
            SSPSTATbits.CKE = 1;
            break;
        case MODO_3:
            SSPCON1bits.CKP  = 1;
            SSPSTATbits.CKE = 0;
            break;
        case MODO_4:
        default:
            SSPCON1bits.CKP  = 0;
            SSPSTATbits.CKE = 0;
            break;
    }

    // Sample bit
    SSPSTATbits.SMP = (smp ? 1 : 0);

    // Habilitar MSSP
    SSPCON1bits.SSPEN = 1;

    // Asegurar SS inactivo
    PIN_SS = 1;
}

void SPI_Init_Slave(char reloj, char modo) {
    ADCON1 = 0x0F;   // Todos digitales

    TRISBbits.RB0 = 1;    // SDI
    TRISBbits.RB1 = 1;    // SCK
    TRISAbits.TRISA5 = 1; // SS
    TRISCbits.TRISC7 = 0; // SDO

    SSPCON1bits.SSPM = reloj & 0x0F;

    switch (modo) {
        case MODO_1:
            SSPCON1bits.CKP  = 1;
            SSPSTATbits.CKE = 1;
            break;
        case MODO_2:
            SSPCON1bits.CKP  = 0;
            SSPSTATbits.CKE = 1;
            break;
        case MODO_3:
            SSPCON1bits.CKP  = 1;
            SSPSTATbits.CKE = 0;
            break;
        case MODO_4:
        default:
            SSPCON1bits.CKP  = 0;
            SSPSTATbits.CKE = 0;
            break;
    }

    SSPCON1bits.SSPEN = 1;
}


void SPI_Tx(char dato) {
    // SS
    PIN_SS = 0;
    // Enviar dato
    SSPBUF = dato;
    while (!SSPSTATbits.BF);
    PIN_SS = 1;
    __delay_us(2);
}

char SPI_Rx(void) {
    return SSPBUF;
}
