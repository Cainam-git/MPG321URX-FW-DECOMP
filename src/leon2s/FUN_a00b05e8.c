/* leon2s FUN_a00b05e8 @ 0xa00b05e8-0xa00b06e0 (62 words incl. the unreachable ret/restore pair
 * FUN_a00b06d8), flags -mcpu=v8 -Os -g.
 * port, force (u8). Unless byte ARR_a8079318[port] == 1 and force == 0: FUN_a00b0540(port);
 * FUN_a00ae3a0(port); FUN_a0083f04(port, 1, 1); if force: FUN_a0084d04(port); FUN_a0083fb8(port); if
 * FUN_a008d800() > 0x80: FUN_a00a6c00(port, 0x21d, 0x84), FUN_a00a6c98(port, 0xc0, 0x80, 0),
 * FUN_a00a6c98(port, 0xda, 0x10, 1); else FUN_a00848cc(port); FUN_a00abb30(port); ARR_a8079318[port] = 1;
 * tail FUN_a00b0518(port). void.
 * Source form: the '> 0x80' arm comes first.
 */
extern unsigned char ARR_a8079318[];
extern void FUN_a00b0540(unsigned char);
extern void FUN_a00ae3a0(unsigned char);
extern void FUN_a0083f04(unsigned char, unsigned char, unsigned char);
extern void FUN_a0084d04(unsigned char);
extern void FUN_a0083fb8(unsigned char);
extern unsigned char FUN_a008d800(void);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00848cc(unsigned char);
extern void FUN_a00abb30(unsigned char);
extern void FUN_a00b0518(unsigned char);

void FUN_a00b05e8(unsigned char port, unsigned char force)
{
    if (ARR_a8079318[port] != 1 || force != 0) {
        FUN_a00b0540(port);
        FUN_a00ae3a0(port);
        FUN_a0083f04(port, 1, 1);
        if (force != 0)
            FUN_a0084d04(port);
        FUN_a0083fb8(port);
        if (FUN_a008d800() > 0x80) {
            FUN_a00a6c00(port, 0x21d, 0x84);
            FUN_a00a6c98(port, 0xc0, 0x80, 0);
            FUN_a00a6c98(port, 0xda, 0x10, 1);
        } else {
            FUN_a00848cc(port);
        }
        FUN_a00abb30(port);
        ARR_a8079318[port] = 1;
        FUN_a00b0518(port);
    }
}
