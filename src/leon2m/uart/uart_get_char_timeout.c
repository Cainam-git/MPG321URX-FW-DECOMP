/* uart_get_char_timeout  (FUN_a00df384)
 *
 * Wait up to 1000 polls for a character from the debug serial port and return it.
 * Returns: character or 0
 * Name basis: proven - 0 when nothing arrived; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df384 @ 0xa00df384-0xa00df3d0 (19 words).
 * Source form: the character is read into an unsigned int that starts at 0 and is returned as unsigned char.
 */
extern unsigned int reg_read32(unsigned int);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_RX_READY 0x01               /* status bit 0: a character has arrived */
#define UART_RX_POLL_COUNT   1000               /* status polls to wait for a character */

/*
 * Poll the status register up to UART_RX_POLL_COUNT times. As soon as it shows a character, return the low byte
 * of the data register.
 *
 * Returns 0 when no character arrived during the polls. Nothing calls it.
 */
unsigned char uart_get_char_timeout(void)
{
    unsigned int c = 0;
    int i;

    for (i = 0; i < UART_RX_POLL_COUNT; i++) {
        if (reg_read32(UART_STATUS_REG) & UART_STATUS_RX_READY) {
            c = reg_read32(UART_DATA_REG);
            break;
        }
    }
    return c;
}
