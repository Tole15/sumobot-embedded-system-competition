#include <xc.h>
#include "config.h"
#include "SPI_lib.h"
#include "motores.h"

// Variables internas que guardan la última configuración
static uint8_t dirR = 0, dirL = 0;
static uint8_t selR = 0, selL = 0;
static uint8_t act  = 0;
static uint8_t dutyR = 0, dutyL = 0;

/**
 * Inicializa SPI y deja lista la línea SS.
 */
void motores_init(void) {
    // SPI_lib configura pines SDO, SCK y SS
    SPI_Init_Master(SPI_Clock_16, MODO_2, DATO_Mitad);
}

/**
 * Ve setDireccion, setPWMsel, setAct, setDuty.
 */
void setDireccion(uint8_t motor, uint8_t d) {
    if (motor == MOTOR_R) dirR = d & 0x01;
    else                 dirL = d & 0x01;
}

void setPWMsel(uint8_t motor, uint8_t s) {
    if (motor == MOTOR_R) selR = s & 0x01;
    else                 selL = s & 0x01;
}

void setAct(uint8_t a) {
    act = a & 0x03;
}

void setDuty(uint8_t motor, uint8_t pct) {
    // Convierte 0?100% a 0x0?0xF linealmente
    uint8_t val = (pct > 100)
                  ? 0x0F
                  : (uint8_t)(((uint32_t)pct * 0x0F + 50) / 100);
    if (motor == MOTOR_R) dutyR = val;
    else                  dutyL = val;
}

/**
 * Empaqueta los bits en dos bytes y llama a SPI_Tx.
 */
void enviarTrama(void) {
    uint8_t byte1 = (dirR << 0)
                  | (selR << 1)
                  | (dirL << 2)
                  | (selL << 3)
                  | (act  << 4);
    uint8_t byte2 = (dutyR << 4) | (dutyL & 0x0F);

    SPI_Tx(byte1);
    SPI_Tx(byte2);
}

/**
 * Atajo completo para configurar y enviar la trama.
 */
void configurarMotores(uint8_t act_code,
                       uint8_t dR, uint8_t dL,
                       uint8_t sR, uint8_t sL,
                       uint8_t pctR, uint8_t pctL) {
    setAct(act_code);
    setDireccion(MOTOR_R, dR);
    setDireccion(MOTOR_L, dL);
    setPWMsel(MOTOR_R, sR);
    setPWMsel(MOTOR_L, sL);
    setDuty(MOTOR_R, pctR);
    setDuty(MOTOR_L, pctL);
    enviarTrama();
}
