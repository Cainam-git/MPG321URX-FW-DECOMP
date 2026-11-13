/* uart_put_char_crlf  (FUN_a00df3d0)
 *
 * Send one character to the debug serial port, a carriage return first for a line feed.
 * Name basis: proven - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df3d0 @ 0xa00df3d0-0xa00df420 (20 words).
 * Source form: the '\r' is sent by a recursive call; the wait is a while loop with no limit.
 */
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, signed char);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_TX_READY 0x20               /* status bit 5: the data register can take a character */

/*
 * Write one character to the data register. A '\n' is preceded by a '\r' (the routine calls itself with '\r').
 * It waits for UART_STATUS_TX_READY without a limit.
 *
 *   c  the character
 *
 * Nothing calls it.
 */
void uart_put_char_crlf(signed char c)
{
    if (c == '\n')
        uart_put_char_crlf('\r');
    while (!(reg_read32(UART_STATUS_REG) & UART_STATUS_TX_READY))
        ;
    reg_write32(UART_DATA_REG, c);
}
