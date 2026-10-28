/* leon2m FUN_a00def40 @ 0xa00def40-0xa00deffc (47 words), flags -mcpu=v8 -O3 -g.
 * Writes the zero-terminated string s character by character to register 0xC00B0000: before each character it
 * waits until bit 5 of register 0xC00B0014 is set, giving up after 0xFFFFF polls; after a '\n' the same wait and
 * a '\r'. Register access goes through func_0x4008c250 (read) / func_0x4008c25c (write).
 * Source form: the wait is a static helper with the loop of FUN_a00df170's uart_putc
 * ('for (t = 0; !(status & 0x20); ) if (++t > 0xffffe) break;'), called before each write; the character is read
 * from s again for the write and for the '\n' test.
 */
extern int func_0x4008c250(unsigned int);
extern void func_0x4008c25c(unsigned int, char);

static void uart_wait(void)
{
    unsigned int t;
    for (t = 0; !(func_0x4008c250(0xc00b0014) & 0x20); )
        if (++t > 0xffffe) break;
}

void FUN_a00def40(const char *s)
{
    while (*s) {
        uart_wait();
        func_0x4008c25c(0xc00b0000, *s);
        if (*s == '\n') {
            uart_wait();
            func_0x4008c25c(0xc00b0000, '\r');
        }
        s++;
    }
}
