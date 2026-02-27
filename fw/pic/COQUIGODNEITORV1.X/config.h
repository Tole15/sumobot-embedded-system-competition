<<<<<<< HEAD
#ifndef CONFIG_H
#define CONFIG_H

#define _XTAL_FREQ 48000000UL    // 20 MHz cristal × PLL

// === SPI Master (MSSP) ===
#define PIN_SS       LATAbits.LA5
#define TRIS_SS      TRISAbits.TRISA5
#define PIN_SDO      LATCbits.LATC7
#define TRIS_SDO     TRISCbits.TRISC7
#define PIN_SCK      LATBbits.LATB1
#define TRIS_SCK     TRISBbits.TRISB1

// === SoftI2C (bit-banging) ===
#define SDA_LAT      LATDbits.LATD0
#define SDA_TRIS     TRISDbits.TRISD0
#define SDA_PORT     PORTDbits.RD0
#define SCL_LAT      LATDbits.LATD1
#define SCL_TRIS     TRISDbits.TRISD1
#define SCL_PORT     PORTDbits.RD1

// === VL53L0X ===
#define VL53L0X_MAX_DIST_MM 1000   // 100 cm máximo útil

// === Encoders de mouse reciclado ===
// Derecho
#define ENC_R_A_PORT PORTAbits.RA2
#define ENC_R_B_PORT PORTAbits.RA3
#define ENC_R_A_TRIS TRISAbits.TRISA2
#define ENC_R_B_TRIS TRISAbits.TRISA3
// Izquierdo
#define ENC_L_A_PORT PORTBbits.RB2
#define ENC_L_B_PORT PORTBbits.RB3
#define ENC_L_A_TRIS TRISBbits.TRISB2
#define ENC_L_B_TRIS TRISBbits.TRISB3

// === Sensores de línea QTR-8A (6 totales) ===
#define NUM_SENSORES_LINEA 6

// Botón de calibración manual
#define BOTON_CALIB_PORT PORTDbits.RD2
#define BOTON_CALIB_TRIS TRISDbits.TRISD2

// === Parámetros geométricos (encoders) ===
#define PULSOS_POR_VUELTA   72u
#define DIAMETRO_LLANTA_MM  59.0f
#define TRACK_MM            165.0f
#define PI_VAL              3.14159265f
#define CIRC_MM             (PI_VAL * DIAMETRO_LLANTA_MM)
#define MM_POR_PULSO        (CIRC_MM / PULSOS_POR_VUELTA)
#define DEG_POR_PULSO_DIFF  ((MM_POR_PULSO / TRACK_MM) * 57.2957795f)

#endif // CONFIG_H
=======
#ifndef CONFIG_H
#define CONFIG_H

#define _XTAL_FREQ 48000000UL    // 20 MHz cristal × PLL

// === SPI Master (MSSP) ===
#define PIN_SS       LATAbits.LA5
#define TRIS_SS      TRISAbits.TRISA5
#define PIN_SDO      LATCbits.LATC7
#define TRIS_SDO     TRISCbits.TRISC7
#define PIN_SCK      LATBbits.LATB1
#define TRIS_SCK     TRISBbits.TRISB1

// === SoftI2C (bit-banging) ===
#define SDA_LAT      LATDbits.LATD0
#define SDA_TRIS     TRISDbits.TRISD0
#define SDA_PORT     PORTDbits.RD0
#define SCL_LAT      LATDbits.LATD1
#define SCL_TRIS     TRISDbits.TRISD1
#define SCL_PORT     PORTDbits.RD1

// === VL53L0X ===
#define VL53L0X_MAX_DIST_MM 1000   // 100 cm máximo útil

// === Encoders de mouse reciclado ===
// Derecho
#define ENC_R_A_PORT PORTAbits.RA2
#define ENC_R_B_PORT PORTAbits.RA3
#define ENC_R_A_TRIS TRISAbits.TRISA2
#define ENC_R_B_TRIS TRISAbits.TRISA3
// Izquierdo
#define ENC_L_A_PORT PORTBbits.RB2
#define ENC_L_B_PORT PORTBbits.RB3
#define ENC_L_A_TRIS TRISBbits.TRISB2
#define ENC_L_B_TRIS TRISBbits.TRISB3

// === Sensores de línea QTR-8A (6 totales) ===
#define NUM_SENSORES_LINEA 6

// Botón de calibración manual
#define BOTON_CALIB_PORT PORTDbits.RD2
#define BOTON_CALIB_TRIS TRISDbits.TRISD2

// === Parámetros geométricos (encoders) ===
#define PULSOS_POR_VUELTA   72u
#define DIAMETRO_LLANTA_MM  59.0f
#define TRACK_MM            165.0f
#define PI_VAL              3.14159265f
#define CIRC_MM             (PI_VAL * DIAMETRO_LLANTA_MM)
#define MM_POR_PULSO        (CIRC_MM / PULSOS_POR_VUELTA)
#define DEG_POR_PULSO_DIFF  ((MM_POR_PULSO / TRACK_MM) * 57.2957795f)

#endif // CONFIG_H
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
