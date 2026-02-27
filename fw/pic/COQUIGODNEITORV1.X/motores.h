<<<<<<< HEAD
/* 
 * File:   motores.h
 * Author: Tole Mendoza
 *
 * Created on 25 de abril de 2025, 05:24 PM
 */

#ifndef MOTORES_H
#define MOTORES_H

#include <stdint.h>

// Identificadores de motor
#define MOTOR_R         0x01   // Motor derecho
#define MOTOR_L         0x02   // Motor izquierdo

// Direcciones de giro
#define DIR_HORARIO     0x00   // Adelante (CW)
#define DIR_ANTIHORARIO 0x01   // Reversa (CCW)

// Selección de canal PWM en el CPLD
#define PWM1            0x00
#define PWM2            0x01

// Códigos de activación
#define ACT_R           0x00   // Solo motor derecho
#define ACT_L           0x01   // Solo motor izquierdo
#define ACT_AMBOS       0x02   // Ambos motores

/**
 * @brief Inicializa la interfaz SPI y prepara los pines para el control de motores.
 */
void motores_init(void);

/**
 * @brief Configura la dirección de giro de un motor.
 * @param motor  MOTOR_R o MOTOR_L
 * @param dir    DIR_HORARIO o DIR_ANTIHORARIO
 */
void setDireccion(uint8_t motor, uint8_t dir);

/**
 * @brief Selecciona el canal PWM que usará un motor.
 * @param motor  MOTOR_R o MOTOR_L
 * @param sel    PWM1 o PWM2
 */
void setPWMsel(uint8_t motor, uint8_t sel);

/**
 * @brief Define qué motores estarán activos.
 * @param act_code  ACT_R, ACT_L o ACT_AMBOS
 */
void setAct(uint8_t act_code);

/**
 * @brief Ajusta el duty cycle de un motor (0?100%).
 * @param motor  MOTOR_R o MOTOR_L
 * @param pct    Porcentaje de 0 a 100
 */
void setDuty(uint8_t motor, uint8_t pct);

/**
 * @brief Envía la trama SPI de 2 bytes al CPLD usando los valores configurados.
 */
void enviarTrama(void);

/**
 * @brief Atajo: configura todo de una vez y envía la trama SPI.
 * @param act_code    ACT_R, ACT_L o ACT_AMBOS
 * @param dirR        Dirección motor derecho
 * @param dirL        Dirección motor izquierdo
 * @param selR        Selección PWM motor derecho
 * @param selL        Selección PWM motor izquierdo
 * @param dutyR_pct   Duty % motor derecho
 * @param dutyL_pct   Duty % motor izquierdo
 */
void configurarMotores(uint8_t act_code,
                       uint8_t dirR, uint8_t dirL,
                       uint8_t selR, uint8_t selL,
                       uint8_t dutyR_pct, uint8_t dutyL_pct);

#endif // MOTORES_H
=======
/* 
 * File:   motores.h
 * Author: Tole Mendoza
 *
 * Created on 25 de abril de 2025, 05:24 PM
 */

#ifndef MOTORES_H
#define MOTORES_H

#include <stdint.h>

// Identificadores de motor
#define MOTOR_R         0x01   // Motor derecho
#define MOTOR_L         0x02   // Motor izquierdo

// Direcciones de giro
#define DIR_HORARIO     0x00   // Adelante (CW)
#define DIR_ANTIHORARIO 0x01   // Reversa (CCW)

// Selección de canal PWM en el CPLD
#define PWM1            0x00
#define PWM2            0x01

// Códigos de activación
#define ACT_R           0x00   // Solo motor derecho
#define ACT_L           0x01   // Solo motor izquierdo
#define ACT_AMBOS       0x02   // Ambos motores

/**
 * @brief Inicializa la interfaz SPI y prepara los pines para el control de motores.
 */
void motores_init(void);

/**
 * @brief Configura la dirección de giro de un motor.
 * @param motor  MOTOR_R o MOTOR_L
 * @param dir    DIR_HORARIO o DIR_ANTIHORARIO
 */
void setDireccion(uint8_t motor, uint8_t dir);

/**
 * @brief Selecciona el canal PWM que usará un motor.
 * @param motor  MOTOR_R o MOTOR_L
 * @param sel    PWM1 o PWM2
 */
void setPWMsel(uint8_t motor, uint8_t sel);

/**
 * @brief Define qué motores estarán activos.
 * @param act_code  ACT_R, ACT_L o ACT_AMBOS
 */
void setAct(uint8_t act_code);

/**
 * @brief Ajusta el duty cycle de un motor (0?100%).
 * @param motor  MOTOR_R o MOTOR_L
 * @param pct    Porcentaje de 0 a 100
 */
void setDuty(uint8_t motor, uint8_t pct);

/**
 * @brief Envía la trama SPI de 2 bytes al CPLD usando los valores configurados.
 */
void enviarTrama(void);

/**
 * @brief Atajo: configura todo de una vez y envía la trama SPI.
 * @param act_code    ACT_R, ACT_L o ACT_AMBOS
 * @param dirR        Dirección motor derecho
 * @param dirL        Dirección motor izquierdo
 * @param selR        Selección PWM motor derecho
 * @param selL        Selección PWM motor izquierdo
 * @param dutyR_pct   Duty % motor derecho
 * @param dutyL_pct   Duty % motor izquierdo
 */
void configurarMotores(uint8_t act_code,
                       uint8_t dirR, uint8_t dirL,
                       uint8_t selR, uint8_t selL,
                       uint8_t dutyR_pct, uint8_t dutyL_pct);

#endif // MOTORES_H
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
