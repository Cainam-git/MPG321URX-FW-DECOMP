/* uart_put_string  (FUN_a0061280)
 *
 * Send a zero-terminated string on the debug console, adding a carriage return after each line feed.
 *   s: text to print
 * Name basis: proven - writes each byte to 0xC00C0000, extra 0x0D after 0x0A; callers CED_ALL crash dump and
 *   console
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: the string character is sent by an open-coded wait and store (the firmware reads *s at the
 * store and again for the '\n' test); the '\r' goes through a static inline helper with an int parameter.
 */
/* Debug console UART registers (leon2s). */
#define UART_DATA_REG   (*(volatile unsigned int *)0xc00c0000) /* write: character to send; read: received byte */
#define UART_STATUS_REG (*(volatile unsigned int *)0xc00c0014)
#define UART_STATUS_RX_READY 0x01 /* a received byte is waiting */
#define UART_STATUS_TX_READY 0x20 /* the transmitter can take a character */
/* Give up waiting for TX_READY after this many polls. */
#define UART_TX_POLL_LIMIT 0xffffe

/* Same wait-and-write as uart_put_char; used here for the carriage return. */
static inline void put_cr_char(int c)
{
    unsigned int polls = 0;

    while ((UART_STATUS_REG & UART_STATUS_TX_READY) == 0) {
        if (++polls > UART_TX_POLL_LIMIT)
            break;
    }
    UART_DATA_REG = c;
}

/*
 * Send the characters of s up to the terminating zero. Each line feed is followed by a carriage return.
 */
void uart_put_string(const unsigned char *s)
{
    unsigned int polls;

    while (*s != 0) {
        polls = 0;
        while ((UART_STATUS_REG & UART_STATUS_TX_READY) == 0) {
            if (++polls > UART_TX_POLL_LIMIT)
                break;
        }
        UART_DATA_REG = *s;
        if (*s == '\n')
            put_cr_char('\r');
        s++;
    }
}
