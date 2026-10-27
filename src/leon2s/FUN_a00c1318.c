/* leon2s FUN_a00c1318 @ 0xa00c1318-0xa00c1550, -mcpu=v8 -Os -g.
 * (port, key, buf), void; port = low byte of param 1. Saves the low bytes of the registers 0xcf011674,
 * 0xcf011438, 0xcf01143c, 0xcf00f21c and of func_0xa0fb6bb8(port, 0x487); keeps func_0xa0fb6bb8(port, 0x32) | 8.
 * Clears bits 3-4 of 0xcf00f21c, sets bits 3-4 of 0xcf011674 and bit 2 of 0xcf011438,
 * func_0xa0fb6c98(port, 0x487, 1, 1), clears bit 0 of 0xcf01143c, func_0xa0fb6c98(port, 0x32, 0x30, port != 0).
 * Writes key[0..4] to registers 0x280..0x284 (func_0xa0fb6c00), writes 0xf to 0xe9 and waits until the low
 * nibble of 0xe9 reads 0, writes key[0..4] to 0xe8. Saves 0xcf011780, writes 6 to it, 0 to 0xcf011784,
 * 0xcf011788 and 0xcf00bfcc, and the 0x11a bytes buf[] one by one to 0xcf01178c. Restores everything in the
 * order 0xcf011780, 0xcf011674, 0xcf011438, register 0x487, 0xcf01143c, register 0x32 (saved value | 8),
 * 0xcf00f21c. Same register-access helpers as FUN_a00c1550.
 * Source form: each arm of the port test holds its complete call; the | 8 is applied at the read.
 */
extern unsigned int func_0xa0fb6bb8(unsigned int, unsigned int);
extern void func_0xa0fb6c00(unsigned int, unsigned short, unsigned int);
extern void func_0xa0fb6c98(unsigned int, unsigned int, unsigned int, unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00c1318(unsigned int port, unsigned char *key, unsigned char *buf)
{
    unsigned char s674, s438, v487, s43c, v32, s21c, s780;
    unsigned short k;

    port &= 0xff;
    s674 = R(0xcf011674);
    s438 = R(0xcf011438);
    v487 = func_0xa0fb6bb8(port, 0x487);
    s43c = R(0xcf01143c);
    v32 = func_0xa0fb6bb8(port, 0x32) | 8;
    s21c = R(0xcf00f21c);
    R(0xcf00f21c) &= ~0x18;
    R(0xcf011674) |= 0x18;
    R(0xcf011438) |= 4;
    func_0xa0fb6c98(port, 0x487, 1, 1);
    R(0xcf01143c) &= ~1;
    if (port == 0)
        func_0xa0fb6c98(port, 0x32, 0x30, 0);
    else
        func_0xa0fb6c98(port, 0x32, 0x30, 1);
    for (k = 0; k < 5; k++)
        func_0xa0fb6c00(port, 0x280 + k, key[k]);
    func_0xa0fb6c00(port, 0xe9, 0xf);
    while (func_0xa0fb6bb8(port, 0xe9) & 0xf)
        ;
    for (k = 0; k < 5; k++)
        func_0xa0fb6c00(port, 0xe8, key[k]);
    s780 = R(0xcf011780);
    R(0xcf011780) = 6;
    R(0xcf011784) = 0;
    R(0xcf011788) = 0;
    R(0xcf00bfcc) = 0;
    for (k = 0; k < 0x11a; k++)
        R(0xcf01178c) = buf[k];
    R(0xcf011780) = s780;
    R(0xcf011674) = s674;
    R(0xcf011438) = s438;
    func_0xa0fb6c00(port, 0x487, v487);
    R(0xcf01143c) = s43c;
    func_0xa0fb6c00(port, 0x32, v32);
    R(0xcf00f21c) = s21c;
}
