/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Stdio demo, UART declarations
 *
 * $Id: uart.h 1008 2005-12-28 21:38:59Z joerg_wunsch $
 */

/*
 * Perform UART startup initialization.
 */
void	uart_init(int baud);

/*
 * Send one character to the UART.
 */
void	uart_putchar(char c);

/*
 * Get one character from the UART.
 */
int		uart_getchar(void);

/*
 * Is there any character in the UART.
 */
int uart_getchar_ready(void);

/*
 * Is interface ready to send character
 */
int uart_putchar_ready(void);
