/* leon2m FUN_a00f1374 @ 0xa00f1374-0xa00f14e4 (368 bytes), flags -mcpu=v8 -O3 -g. No direct callers found.
 * Read-modify-write of one register in one or all four register blocks whose bases are the halfwords
 * DAT_a8026a7e[0..3]: the register word is at 0xcf000000 | ((base + reg) << 2). blk == 4 = all blocks 0..3,
 * blk > 4 = nothing. set == 1 ORs mask in, else clears it; the low byte is written back.
 * Source form: same body as FUN_a00f232c (eight blocks at DAT_0019a2ec) with reg as unsigned short.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8026a7e[4];
void FUN_a00f1374(unsigned char blk, unsigned short reg, unsigned char mask, unsigned char set)
{
    unsigned char i; unsigned char v;
    if (blk == 4) {
        for (i = 0; i <= 3; i++) {
            v = R(DAT_a8026a7e[i] + reg);
            if (set == 1) v |= mask; else v &= ~mask;
            R(DAT_a8026a7e[i] + reg) = (unsigned char)v;
        }
    } else if (blk <= 3) {
        v = R(DAT_a8026a7e[blk] + reg);
        if (set == 1) v |= mask; else v &= ~mask;
        R(DAT_a8026a7e[blk] + reg) = (unsigned char)v;
    }
}
