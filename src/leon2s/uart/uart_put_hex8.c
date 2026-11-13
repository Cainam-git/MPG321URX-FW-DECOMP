/* uart_put_hex8  (FUN_a00613cc)
 *
 * Print a byte as two hexadecimal digits on the debug console.
 *   x: byte
 * Name basis: proven - 2 nibbles through the digit table s_a00b3a08 to 0xC00C0000; caller
 *   dbg_dump_memory_bytes
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: the character send is a static copy of the uart_put_char body, inlined.
 */
/* Debug console UART registers (leon2s). */
#define UART_DATA_REG   (*(volatile unsigned int *)0xc00c0000) /* write: character to send; read: received byte */
#define UART_STATUS_REG (*(volatile unsigned int *)0xc00c0014)
#define UART_STATUS_RX_READY 0x01 /* a received byte is waiting */
#define UART_STATUS_TX_READY 0x20 /* the transmitter can take a character */
/* Give up waiting for TX_READY after this many polls. */
#define UART_TX_POLL_LIMIT 0xffffe
extern const char s_a00b3a08[]; /* digit table "0123456789ABCDEF" */

/* Same wait-and-write as uart_put_char. */
static void put_char(unsigned char c)
{
    unsigned int polls = 0;

    while ((UART_STATUS_REG & UART_STATUS_TX_READY) == 0) {
        if (++polls > UART_TX_POLL_LIMIT)
            break;
    }
    UART_DATA_REG = c;
}

/* Send the two hexadecimal digits of x, high digit first, with no prefix and no line end. */
void uart_put_hex8(unsigned char x)
{
    int i;

    for (i = 0; i < 2; i++)
        put_char(s_a00b3a08[(x >> (4 - i * 4)) & 0xf]);
}
