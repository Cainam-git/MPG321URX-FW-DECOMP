/* leon2s FUN_a00c255c @ 0xa00c255c-0xa00c2758, -mcpu=v8 -Os -g.
 * (u8 port), void. With w = func_0xa0fb7ee0(port, reg, val) and r = func_0xa0fb7fa0(port, reg) (ROM register
 * access outside the image), a = DAT_a8078eb9 and b = a + 0x20, c = DAT_a8078cb8: w(0xc, 0x18), w(0xc, 0x10),
 * b[0..0x5e] written to reg 0xd, w(0xa, 0x44), wait while bit 2 of r(0xa) is set (u8 counter from 0xff),
 * w(0xc, 0x28), w(0xc, 0x20), c[i] = r(0xd) ^ a[i] for i = 0..0x1f, w(0xc, 0x18), w(0xc, 0x10), c[0..0x1f]
 * written to reg 0xd, w(0xa, 0x42), wait while bit 1 of r(0xa) is set, w(0xc, 0x28), w(0xc, 0x20), then 0x5f
 * reads of reg 0xd of which reads 0x4e..0x5e give c[i - 0x4e] = b[i] ^ value; ends with the ROM print
 * func_0xa0f83044(s_9f1b7570, c[0]).
 * Source form: the two table pointers a and b are locals (declared around the counters); i = 0 at its
 * declaration for the first loop.
 */
extern unsigned char DAT_a8078eb9[];
extern unsigned char DAT_a8078cb8[];
extern const char s_9f1b7570[];
extern int func_0xa0f83044(const char *, ...);
extern void func_0xa0fb7ee0(unsigned char, unsigned int, unsigned char);
extern unsigned char func_0xa0fb7fa0(unsigned char, unsigned int);

void FUN_a00c255c(unsigned char port)
{
    unsigned char *a = DAT_a8078eb9;
    unsigned char i = 0, t, x;
    unsigned char *b = a + 0x20;

    func_0xa0fb7ee0(port, 0xc, 0x18);
    func_0xa0fb7ee0(port, 0xc, 0x10);
    for (; i <= 0x5e; i++)
        func_0xa0fb7ee0(port, 0xd, b[i]);
    func_0xa0fb7ee0(port, 0xa, 0x44);
    t = 0xff;
    while (func_0xa0fb7fa0(port, 0xa) & 4) {
        t--;
        if (t == 0)
            break;
    }
    func_0xa0fb7ee0(port, 0xc, 0x28);
    func_0xa0fb7ee0(port, 0xc, 0x20);
    for (i = 0; i <= 0x1f; i++)
        DAT_a8078cb8[i] = func_0xa0fb7fa0(port, 0xd) ^ a[i];
    func_0xa0fb7ee0(port, 0xc, 0x18);
    func_0xa0fb7ee0(port, 0xc, 0x10);
    for (i = 0; i <= 0x1f; i++)
        func_0xa0fb7ee0(port, 0xd, DAT_a8078cb8[i]);
    func_0xa0fb7ee0(port, 0xa, 0x42);
    t = 0xff;
    while (func_0xa0fb7fa0(port, 0xa) & 2) {
        t--;
        if (t == 0)
            break;
    }
    func_0xa0fb7ee0(port, 0xc, 0x28);
    func_0xa0fb7ee0(port, 0xc, 0x20);
    for (i = 0; i <= 0x5e; i++) {
        x = func_0xa0fb7fa0(port, 0xd);
        if (i > 0x4d)
            DAT_a8078cb8[i - 0x4e] = b[i] ^ x;
    }
    func_0xa0f83044(s_9f1b7570, DAT_a8078cb8[0]);
}
