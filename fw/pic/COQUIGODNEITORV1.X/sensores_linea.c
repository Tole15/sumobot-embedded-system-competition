<<<<<<< HEAD
#include <xc.h>
#include "config.h"
#include "sensores_linea.h"

// Canales ADC usados (ANx): AN0, AN1, AN5, AN6, AN7, AN11
static const uint8_t canales_qtr[NUM_SENSORES_LINEA] = {
    0,  1,  5,  6,  7, 11
};

static uint16_t calibracion_min[NUM_SENSORES_LINEA];
static uint16_t calibracion_max[NUM_SENSORES_LINEA];

/** Inicializa el módulo A/D. */
static void adc_init(void) {
    ADCON1 = 0x0E;   // Vdd/Vss referencias, AN0?AN? según ANSEL
    ADCON2 = 0xA9;   // Fosc/8, 4 TAD, right-justified
}

/**
 * Lee el canal 'canal' (0?15) y devuelve valor de 10 bits.
 */
static uint16_t leer_adc(uint8_t canal) {
    ADCON0 = (canal << 2);    // selecciona canal
    ADCON0bits.ADON = 1;      // enciende A/D
    __delay_us(10);           // estabilización
    ADCON0bits.GO_nDONE = 1;  // inicia conversión
    while (ADCON0bits.GO_nDONE);
    ADCON0bits.ADON = 0;      // apaga A/D para ahorrar energía
    return ((ADRESH << 8) | ADRESL);
}

void sensores_linea_init(void) {
    adc_init();
    for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
        calibracion_min[i] = 1023;
        calibracion_max[i] = 0;
    }
}

void sensores_linea_calibrar(void) {
    uint16_t lectura;
    for (uint8_t iter = 0; iter < 80; iter++) {
        for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
            lectura = leer_adc(canales_qtr[i]);
            if (lectura < calibracion_min[i]) calibracion_min[i] = lectura;
            if (lectura > calibracion_max[i]) calibracion_max[i] = lectura;
        }
        __delay_ms(5);
    }
}

void sensores_linea_leer_crudos(uint16_t* buffer) {
    for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
        buffer[i] = leer_adc(canales_qtr[i]);
    }
}

void sensores_linea_leer_normalizados(uint16_t* buffer) {
    uint16_t lect;
    for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
        lect = leer_adc(canales_qtr[i]);
        if (calibracion_max[i] > calibracion_min[i]) {
            uint32_t tmp = (uint32_t)(lect - calibracion_min[i]) * 1000;
            tmp /= (calibracion_max[i] - calibracion_min[i]);
            buffer[i] = (tmp > 1000) ? 1000 : (uint16_t)tmp;
        } else {
            buffer[i] = 0;
        }
    }
}

int16_t sensores_linea_posicion(void) {
    uint16_t vals[NUM_SENSORES_LINEA];
    int32_t num = 0, den = 0;
    sensores_linea_leer_normalizados(vals);
    for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
        num += (int32_t)vals[i] * (i * 1000);
        den += vals[i];
    }
    if (den == 0) return -1;
    return (int16_t)(num / den);
}
=======
#include <xc.h>
#include "config.h"
#include "sensores_linea.h"

// Canales ADC usados (ANx): AN0, AN1, AN5, AN6, AN7, AN11
static const uint8_t canales_qtr[NUM_SENSORES_LINEA] = {
    0,  1,  5,  6,  7, 11
};

static uint16_t calibracion_min[NUM_SENSORES_LINEA];
static uint16_t calibracion_max[NUM_SENSORES_LINEA];

/** Inicializa el módulo A/D. */
static void adc_init(void) {
    ADCON1 = 0x0E;   // Vdd/Vss referencias, AN0?AN? según ANSEL
    ADCON2 = 0xA9;   // Fosc/8, 4 TAD, right-justified
}

/**
 * Lee el canal 'canal' (0?15) y devuelve valor de 10 bits.
 */
static uint16_t leer_adc(uint8_t canal) {
    ADCON0 = (canal << 2);    // selecciona canal
    ADCON0bits.ADON = 1;      // enciende A/D
    __delay_us(10);           // estabilización
    ADCON0bits.GO_nDONE = 1;  // inicia conversión
    while (ADCON0bits.GO_nDONE);
    ADCON0bits.ADON = 0;      // apaga A/D para ahorrar energía
    return ((ADRESH << 8) | ADRESL);
}

void sensores_linea_init(void) {
    adc_init();
    for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
        calibracion_min[i] = 1023;
        calibracion_max[i] = 0;
    }
}

void sensores_linea_calibrar(void) {
    uint16_t lectura;
    for (uint8_t iter = 0; iter < 80; iter++) {
        for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
            lectura = leer_adc(canales_qtr[i]);
            if (lectura < calibracion_min[i]) calibracion_min[i] = lectura;
            if (lectura > calibracion_max[i]) calibracion_max[i] = lectura;
        }
        __delay_ms(5);
    }
}

void sensores_linea_leer_crudos(uint16_t* buffer) {
    for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
        buffer[i] = leer_adc(canales_qtr[i]);
    }
}

void sensores_linea_leer_normalizados(uint16_t* buffer) {
    uint16_t lect;
    for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
        lect = leer_adc(canales_qtr[i]);
        if (calibracion_max[i] > calibracion_min[i]) {
            uint32_t tmp = (uint32_t)(lect - calibracion_min[i]) * 1000;
            tmp /= (calibracion_max[i] - calibracion_min[i]);
            buffer[i] = (tmp > 1000) ? 1000 : (uint16_t)tmp;
        } else {
            buffer[i] = 0;
        }
    }
}

int16_t sensores_linea_posicion(void) {
    uint16_t vals[NUM_SENSORES_LINEA];
    int32_t num = 0, den = 0;
    sensores_linea_leer_normalizados(vals);
    for (uint8_t i = 0; i < NUM_SENSORES_LINEA; i++) {
        num += (int32_t)vals[i] * (i * 1000);
        den += vals[i];
    }
    if (den == 0) return -1;
    return (int16_t)(num / den);
}
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
