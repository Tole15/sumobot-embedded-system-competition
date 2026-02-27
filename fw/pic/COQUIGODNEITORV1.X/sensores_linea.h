<<<<<<< HEAD
#ifndef SENSORES_LINEA_H
#define SENSORES_LINEA_H

#include <stdint.h>

/**
 * Inicializa el ADC y prepara arrays de calibración.
 */
void sensores_linea_init(void);

/**
 * Ejecuta la rutina de calibración automática:
 * toma múltiples muestras para encontrar mínimos y máximos.
 */
void sensores_linea_calibrar(void);

/**
 * Lee valores crudos de cada sensor QTR en buffer[NUM_SENSORES_LINEA].
 */
void sensores_linea_leer_crudos(uint16_t* buffer);

/**
 * Lee valores normalizados [0?1000] en buffer[NUM_SENSORES_LINEA].
 */
void sensores_linea_leer_normalizados(uint16_t* buffer);

/**
 * Calcula posición ponderada de la línea. 
 * Devuelve -1 si no detecta línea, o rango 0..(NUM_SENSORES_LINEA-1)*1000.
 */
int16_t sensores_linea_posicion(void);

#endif // SENSORES_LINEA_H
=======
#ifndef SENSORES_LINEA_H
#define SENSORES_LINEA_H

#include <stdint.h>

/**
 * Inicializa el ADC y prepara arrays de calibración.
 */
void sensores_linea_init(void);

/**
 * Ejecuta la rutina de calibración automática:
 * toma múltiples muestras para encontrar mínimos y máximos.
 */
void sensores_linea_calibrar(void);

/**
 * Lee valores crudos de cada sensor QTR en buffer[NUM_SENSORES_LINEA].
 */
void sensores_linea_leer_crudos(uint16_t* buffer);

/**
 * Lee valores normalizados [0?1000] en buffer[NUM_SENSORES_LINEA].
 */
void sensores_linea_leer_normalizados(uint16_t* buffer);

/**
 * Calcula posición ponderada de la línea. 
 * Devuelve -1 si no detecta línea, o rango 0..(NUM_SENSORES_LINEA-1)*1000.
 */
int16_t sensores_linea_posicion(void);

#endif // SENSORES_LINEA_H
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
