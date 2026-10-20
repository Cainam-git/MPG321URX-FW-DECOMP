/* leon2m FUN_a00df170 @ 0xa00df170  debug printf to the UART (hand; called by FUN_a00dac38
 * and most of the firmware)
 *
 * Formats into an 80-byte stack buffer with FUN_a01595f4(buf, 0x50, fmt, ap) (vsnprintf-like, returns the length).
 * A result of length 1 whose first byte is 0 prints nothing. Each character: wait until UART status 0xC00B0014 bit 5
 * (transmitter ready) is set, giving up after 0xFFFFF polls, then write it to 0xC00B0000; after a '\n' the same wait
 * and a '\r'. Register access goes through the RAM-copy helpers func_0x4008c250 (read) / func_0x4008c25c (write).
 * Returns 0. BYTE-EXACT: the wait-and-send is a static helper used twice (the character, then '\r' after a
 * '\n'); its wait is 'for (t = 0; !(status & 0x20); ) if (++t > 0xffffe) break;'; the buffer is indexed through a
 * pointer local (p[i]), not walked.
 */
typedef __builtin_va_list va_list;
#define va_start(v, l) __builtin_va_start(v, l)
#define va_end(v) __builtin_va_end(v)
extern int FUN_a01595f4(char *, int, const char *, va_list);
extern unsigned int func_0x4008c250(unsigned int);
extern void func_0x4008c25c(unsigned int, char);
static void uart_putc(char c)
{
    unsigned int t;
    for (t = 0; !(func_0x4008c250(0xc00b0014) & 0x20); )
        if (++t > 0xffffe) break;
    func_0x4008c25c(0xc00b0000, c);
}
int FUN_a00df170(const char *fmt, ...)
{
    char buf[0x50];
    char *p = buf;
    va_list ap;
    int n, i;
    va_start(ap, fmt);
    n = FUN_a01595f4(p, 0x50, fmt, ap);
    if (n == 1 && p[0] == 0) return 0;
    for (i = 0; i < n; i++) {
        uart_putc(p[i]);
        if (p[i] == '\n') uart_putc('\r');
    }
    return 0;
}
