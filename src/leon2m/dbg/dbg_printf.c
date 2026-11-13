/* dbg_printf  (FUN_a00df170)
 *
 * Format a message and send it to the debug serial port.
 * Name basis: proven - printf-style: formats into 80 bytes, then sends each byte; called from all over the
 *   program
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df170 @ 0xa00df170, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the wait-and-send is a static helper used twice (the character,
 * then '\r' after a '\n'); its wait is 'for (t = 0; !(status & 0x20); ) if (++t > 0xffffe) break;'; the
 * buffer is indexed through a pointer local (p[i]), not walked; the register access goes through the
 * RAM-copy helpers (reg_read32, reg_write32).
 */
typedef __builtin_va_list va_list;
#define va_start(v, l) __builtin_va_start(v, l)
#define va_end(v) __builtin_va_end(v)
extern int vsnprintf(char *, int, const char *, va_list);
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, char);

#define DEBUG_UART_DATA   0xc00b0000    /* debug serial port: data register */
#define DEBUG_UART_STATUS 0xc00b0014    /* debug serial port: status register */
#define UART_TX_READY     0x20          /* status bit 5: the port can take another byte */
#define UART_WAIT_LIMIT   0xffffe       /* polls of the status bit before the byte is sent anyway */
#define DEBUG_LINE_SIZE   0x50          /* size of the buffer vsnprintf formats into */

/* Send one byte to the debug port. Waits for the transmit-ready bit, but gives up after UART_WAIT_LIMIT polls. */
static void uart_putc(char c)
{
    unsigned int polls;
    for (polls = 0; !(reg_read32(DEBUG_UART_STATUS) & UART_TX_READY); )
        if (++polls > UART_WAIT_LIMIT) break;
    reg_write32(DEBUG_UART_DATA, c);
}

/*
 * Print a message on the debug serial port. 'fmt' and the arguments after it are a printf-style format; the
 * result is formatted into an 80-byte buffer by vsnprintf and sent byte by byte, as many bytes as vsnprintf returns. Every '\n' is
 * followed by an extra '\r'. A formatted result that is a single zero byte prints nothing. Always returns 0.
 * Called from all over the firmware.
 */
int dbg_printf(const char *fmt, ...)
{
    char buf[DEBUG_LINE_SIZE];
    char *p = buf;
    va_list ap;
    int length, i;
    va_start(ap, fmt);
    length = vsnprintf(p, DEBUG_LINE_SIZE, fmt, ap);
    if (length == 1 && p[0] == 0) return 0;
    for (i = 0; i < length; i++) {
        uart_putc(p[i]);
        if (p[i] == '\n') uart_putc('\r');
    }
    return 0;
}
