/* leon2s FUN_a00c1550 @ 0xa00c1550 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Twin of FUN_a00c0f88 on the other register bank
 * (0x400-0x406 via 0xa0fb6c00 / 0xa0fb6c98). Saves the low byte of control register 0xcf00f21c
 * and clears its bits 3-4, then streams four blocks into the port's protection engine: 320
 * bytes from param_5 (backwards), 522 bytes from param_3, 24 zero bytes plus 16 bytes from
 * param_2 (backwards), and the fixed 11-byte table at 0xa8078610. Restores the saved byte at
 * the end. The saved value must be a byte variable to match.
 */
extern void func_0xa0fb6c00(unsigned int, unsigned int, unsigned int);
extern void func_0xa0fb6c98(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned char _DAT_a8078610[];

#define _DAT_cf00f21c (*(volatile unsigned int *)0xcf00f21c)

void FUN_a00c1550(unsigned int i0, unsigned char *i1, unsigned char *i2, int i3, unsigned char *i4)
{
    unsigned int tmp2;
    unsigned char tmp1;
    unsigned short l0;
    unsigned char byte;

    tmp1 = _DAT_cf00f21c;
    tmp2 = _DAT_cf00f21c;
    tmp2 &= ~0x18;
    i0 &= 0xff;
    _DAT_cf00f21c = tmp2;

    func_0xa0fb6c00(i0, 0x400, 0);
    func_0xa0fb6c00(i0, 0x403, 0);
    func_0xa0fb6c98(i0, 0x402, 0x80, 1);

    l0 = 0;
    do {
        byte = i4[0x13f - l0];
        func_0xa0fb6c00(i0, 0x401, byte);
    } while (++l0 <= 0x13f);

    func_0xa0fb6c00(i0, 0x406, 0x80);
    func_0xa0fb6c00(i0, 0x400, 2);
    func_0xa0fb6c00(i0, 0x403, 0);
    func_0xa0fb6c98(i0, 0x402, 0x80, 1);

    l0 = 0;
    do {
        byte = i2[l0];
        func_0xa0fb6c00(i0, 0x401, byte);
    } while (++l0 <= 0x209);

    func_0xa0fb6c00(i0, 0x400, 0x11);
    func_0xa0fb6c00(i0, 0x403, 0);
    func_0xa0fb6c98(i0, 0x402, 0x80, 1);

    l0 = 0;
    do {
        func_0xa0fb6c00(i0, 0x401, 0);
    } while (++l0 <= 0x17);

    l0 = 0;
    do {
        byte = i1[0xf - l0];
        func_0xa0fb6c00(i0, 0x401, byte);
    } while (++l0 <= 0xf);

    func_0xa0fb6c00(i0, 0x400, 3);
    func_0xa0fb6c00(i0, 0x403, 0);
    func_0xa0fb6c98(i0, 0x402, 0x80, 1);

    l0 = 0;
    do {
        byte = _DAT_a8078610[l0];
        func_0xa0fb6c00(i0, 0x401, byte);
    } while (++l0 <= 0xa);

    _DAT_cf00f21c = tmp1;
}
