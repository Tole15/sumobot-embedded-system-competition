<<<<<<< HEAD
#ifndef USART_H
#define USART_H

/**
 * @brief Inicializa el EUSART a 9600 bps, 8N1.
 *        Fosc = 48 MHz, BRG16 = 0, BRGH = 0, SPBRG = 76.
 */
void usart_init(void);

/**
 * @brief Envía un carácter por UART.
 * @param c Carácter a transmitir.
 */
void usart_send_char(char c);

/**
 * @brief Envía una cadena NUL-terminada por UART.
 * @param s Puntero a la cadena.
 */
void usart_send_string(const char* s);

#endif // USART_H
=======
#ifndef USART_H
#define USART_H

/**
 * @brief Inicializa el EUSART a 9600 bps, 8N1.
 *        Fosc = 48 MHz, BRG16 = 0, BRGH = 0, SPBRG = 76.
 */
void usart_init(void);

/**
 * @brief Envía un carácter por UART.
 * @param c Carácter a transmitir.
 */
void usart_send_char(char c);

/**
 * @brief Envía una cadena NUL-terminada por UART.
 * @param s Puntero a la cadena.
 */
void usart_send_string(const char* s);

#endif // USART_H
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
