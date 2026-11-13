/* uart_get_char_blocking  (FUN_a00df420)
 *
 * Wait without a limit for a character from the debug serial port and return it.
 * Returns: the character (low byte of the data register)
 * Note: No routine calls it.
 * Name basis: derived - polls bit 0 of 0xC00B0014 until it is set, then returns the low byte of 0xC00B0000
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df420 @ 0xa00df420 (-mcpu=v8 -O2 -g)
 * Source form: the wait is a while loop with no limit.
 */
extern int reg_read32(unsigned int);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_RX_READY 0x01               /* status bit 0: a character has arrived */

/*
 * Wait, without a limit, until the status register shows that a character has arrived, then return the low byte
 * of the data register, which is the received character (not a 0 / 1 answer).
 *
 * Nothing calls it.
 */
int uart_get_char_blocking(void)
{
    while ((reg_read32(UART_STATUS_REG) & UART_STATUS_RX_READY) == 0)
        ;
    return reg_read32(UART_DATA_REG) & 0xff;
}
