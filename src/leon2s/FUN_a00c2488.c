/* FUN_a00c2488 (leon2s 0xa00c2488-0xa00c255c, 212 bytes), flags -mcpu=v8 -Os -g.
 * port (u8), buf. When bit 5 of func_0xa0fb7fa0(port, 2) is set: calls func_0xa0fb7ee0(port, reg, value) with
 * (2, 0x40), (3, 0), (4, 0x66), (5, 0x80), (5, 0), reads func_0xa0fb7fa0(port, 7) once, then 64 times stores
 * func_0xa0fb7fa0(port, 6) to buf[(0x3f - i) * 2 + 1] and func_0xa0fb7fa0(port, 7) to buf[(0x3f - i) * 2] for
 * i = 0..63, and returns 1. Otherwise returns 0.
 * Source form: result and loop counter are unsigned char locals both initialised to 0 at their declarations
 * (the firmware copies the result register's 0 into the counter); the result is returned as 'k & 1'.
 */
extern unsigned int func_0xa0fb7fa0(unsigned char, unsigned char);
extern void func_0xa0fb7ee0(unsigned char, unsigned char, unsigned char);

unsigned char FUN_a00c2488(unsigned char port, unsigned char *buf)
{
    unsigned char k = 0;
    unsigned char i = 0;
    unsigned char v;

    if (func_0xa0fb7fa0(port, 2) & 0x20) {
        func_0xa0fb7ee0(port, 2, 0x40);
        func_0xa0fb7ee0(port, 3, 0);
        func_0xa0fb7ee0(port, 4, 0x66);
        func_0xa0fb7ee0(port, 5, 0x80);
        func_0xa0fb7ee0(port, 5, 0);
        func_0xa0fb7fa0(port, 7);
        for (i = 0; i < 0x40; i++) {
            v = func_0xa0fb7fa0(port, 6);
            buf[((0x3f - i) * 2) + 1] = v;
            buf[(0x3f - i) * 2] = func_0xa0fb7fa0(port, 7);
        }
        k = 1;
    }
    return k & 1;
}
