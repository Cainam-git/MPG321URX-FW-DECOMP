/* uart_put_string_crlf  (FUN_a00df278)
 *
 * Send a text to the debug serial port, adding a carriage return after each line feed.
 * Returns: 0
 * Name basis: proven - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df278 @ 0xa00df278-0xa00df368 (240 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the same static wait-and-send helper as dbg_printf, used twice; the length is taken before the
 * null test.
 */
extern int strlen(const char *);
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, char);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_TX_READY 0x20               /* status bit 5: the data register can take a character */
#define UART_TX_POLL_LIMIT   0xffffe            /* most status polls to wait for UART_STATUS_TX_READY */

/* Write one character once the data register can take it (at most UART_TX_POLL_LIMIT + 1 polls; written even
   then). */
static void uart_putc(char c)
{
    unsigned int t;
    for (t = 0; !(reg_read32(UART_STATUS_REG) & UART_STATUS_TX_READY); )
        if (++t > UART_TX_POLL_LIMIT) break;
    reg_write32(UART_DATA_REG, c);
}

/*
 * Write a text to the data register, character by character; after each '\n' it also writes a '\r'. The length
 * is taken with strlen before the null test.
 *
 *   p  the text; a null pointer sends nothing
 *
 * Returns 0. Nothing calls it.
 */
int uart_put_string_crlf(const char *p)
{
    int n, i;

    n = strlen(p);
    if (p == 0) return 0;
    if (n == 1 && p[0] == 0) return 0;
    for (i = 0; i < n; i++) {
        uart_putc(p[i]);
        if (p[i] == '\n') uart_putc('\r');
    }
    return 0;
}
