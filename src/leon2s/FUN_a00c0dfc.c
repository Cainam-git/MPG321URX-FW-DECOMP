/* FUN_a00c0dfc (leon2s 0xa00c0dfc-0xa00c0ecc, 208 bytes), flags -mcpu=v8 -Os -g.
 * Through the ROM register routines of port: func_0xa0fb6aa0(port, 0x40, 8, 1); a[0..4] to registers
 * 0x1a..0x1e with func_0xa0fb69fc; a read of register 0xa0 (func_0xa0fb69b4, result unused) and 0xa0 = 0xe0;
 * then for i = 0..0x119: 0xa1 = low byte of i, 0xa2 = high byte of i, 0xa3 = b[i].
 * Same data sizes as the direct register version FUN_a00c0a88. Source form: unsigned short loop counter.
 */
extern void func_0xa0fb6aa0(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned int func_0xa0fb69b4(unsigned char, unsigned short);
extern void func_0xa0fb69fc(unsigned char, unsigned short, unsigned char);

void FUN_a00c0dfc(unsigned char port, unsigned char *a, unsigned char *b)
{
    unsigned short i;

    func_0xa0fb6aa0(port, 0x40, 8, 1);
    for (i = 0; i < 5; i++)
        func_0xa0fb69fc(port, i + 0x1a, a[i]);
    func_0xa0fb69b4(port, 0xa0);
    func_0xa0fb69fc(port, 0xa0, 0xe0);
    for (i = 0; i < 0x11a; i++) {
        func_0xa0fb69fc(port, 0xa1, i);
        func_0xa0fb69fc(port, 0xa2, i >> 8);
        func_0xa0fb69fc(port, 0xa3, b[i]);
    }
}
