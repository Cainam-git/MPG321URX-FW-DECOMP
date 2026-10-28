/* leon2m FUN_a00df278 @ 0xa00df278-0xa00df368 (240 bytes), flags -mcpu=v8 -O3 -g.
 * String form of FUN_a00df170: n = FUN_a0157858(p) (string length); returns 0 for a null p, or when n is 1 and
 * p[0] is 0. Otherwise each of the n characters: wait until bit 5 of register 0xC00B0014 is set, giving up after
 * 0xFFFFF polls, then write it to 0xC00B0000; after a '\n' the same wait and a '\r'. Register access goes through
 * func_0x4008c250 (read) / func_0x4008c25c (write). Returns 0.
 * Source form: the same static wait-and-send helper as FUN_a00df170, used twice; the length is taken before the
 * null test.
 */
extern int FUN_a0157858(const char *);
extern unsigned int func_0x4008c250(unsigned int);
extern void func_0x4008c25c(unsigned int, char);
static void uart_putc(char c)
{
    unsigned int t;
    for (t = 0; !(func_0x4008c250(0xc00b0014) & 0x20); )
        if (++t > 0xffffe) break;
    func_0x4008c25c(0xc00b0000, c);
}
int FUN_a00df278(const char *p)
{
    int n, i;

    n = FUN_a0157858(p);
    if (p == 0) return 0;
    if (n == 1 && p[0] == 0) return 0;
    for (i = 0; i < n; i++) {
        uart_putc(p[i]);
        if (p[i] == '\n') uart_putc('\r');
    }
    return 0;
}
