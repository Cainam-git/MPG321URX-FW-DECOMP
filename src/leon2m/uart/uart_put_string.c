/* uart_put_string  (FUN_a00def40)
 *
 * Send a text to the debug serial port, character by character.
 * Name basis: proven - data register 0xC00B0000 after waiting for the ready bit of 0xC00B0014
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00def40 @ 0xa00def40-0xa00deffc (47 words), flags -mcpu=v8 -O3 -g.
 * Source form: the wait is a static helper with the loop 'for (t = 0; !(status & 0x20); ) if (++t > 0xffffe)
 * break;', called before each write; the character is read from s again for the write and for the '\n' test.
 */
extern int reg_read32(unsigned int);
extern void reg_write32(unsigned int, char);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_TX_READY 0x20               /* status bit 5: the data register can take a character */
#define UART_TX_POLL_LIMIT   0xffffe            /* most status polls to wait for UART_STATUS_TX_READY */

/* Wait until the data register can take a character, for at most UART_TX_POLL_LIMIT + 1 polls. */
static void uart_wait(void)
{
    unsigned int t;
    for (t = 0; !(reg_read32(UART_STATUS_REG) & UART_STATUS_TX_READY); )
        if (++t > UART_TX_POLL_LIMIT) break;
}

/*
 * Write a zero-terminated text to the data register, each character after the wait. After a '\n' it waits again
 * and writes a '\r'.
 *
 *   s  the text
 *
 * Called by dbg_command_shell and several dbg_* routines that print memory.
 */
void uart_put_string(const char *s)
{
    while (*s) {
        uart_wait();
        reg_write32(UART_DATA_REG, *s);
        if (*s == '\n') {
            uart_wait();
            reg_write32(UART_DATA_REG, '\r');
        }
        s++;
    }
}
