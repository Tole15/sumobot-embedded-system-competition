/* 
 * File:   SPI_lib.h
 * Author: Tole Mendoza
 *
 * Created on 25 de abril de 2025, 05:05 PM
 */

#ifndef SPI_LIB_H
#define SPI_LIB_H

#include "config.h"
#include <stdint.h>

// Frecuencias de reloj (Master)
#define SPI_Clock_4    0   // Fosc/4
#define SPI_Clock_16   1   // Fosc/16
#define SPI_Clock_64   2   // Fosc/64
#define SPI_TMR2       3
#define SPI_Slave_R5   4
#define SPI_Slave_IO   5

// Modos de reloj / fase
#define MODO_1  '1'  // CKP=1, CKE=1
#define MODO_2  '2'  // CKP=0, CKE=1
#define MODO_3  '3'  // CKP=1, CKE=0
#define MODO_4  '4'  // CKP=0, CKE=0

// SMP (Sample bit)
#define DATO_Mitad 0  // muestreo en medio
#define DATO_Fin   1  // muestreo al final

/**
 * @brief Inicializa el MSSP en modo SPI Master.
 * @param reloj  Frecuencia de SPI (SPI_Clock_x).
 * @param modo   Polaridad/fase (MODO_x).
 * @param smp    Sample bit (DATO_Mitad o DATO_Fin).
 */
void SPI_Init_Master(char reloj, char modo, char smp);

/**
 * @brief Inicializa el MSSP en modo SPI Slave.
 * @param reloj  Selección de modo esclavo (SPI_Slave_R5 o SPI_Slave_IO).
 * @param modo   Polaridad/fase (MODO_x).
 */
void SPI_Init_Slave(char reloj, char modo);

/**
 * @brief Envía un byte via SPI, controlando SS y respetando tiempos.
 * @param dato  Byte a transmitir.
 *
 * Hace:
 *   PIN_SS = 0;
 *   SSPBUF = dato;
 *   while(!SSPSTATbits.BF);
 *   PIN_SS = 1;
 *   __delay_us(2);
 */
void SPI_Tx(char dato);

/**
 * @brief Recibe un byte via SPI (no controla SS).
 * @return El contenido de SSPBUF (dato recibido).
 */
char SPI_Rx(void);

#endif // SPI_LIB_H
