/* leon2m FUN_a00f176c @ 0xa00f176c-0xa00f18d4 (360 bytes), flags -mcpu=v8 -O3 -g. No direct callers found.
 * Read-modify-write of one register in one or both register blocks whose bases are the halfwords
 * DAT_a8026a7a[0..1]: the register word is at 0xcf000000 | ((base + reg) << 2). blk == 2 = blocks 0 and 1; any
 * other blk indexes DAT_a8026a7a directly (no range test). set == 1 ORs mask in, else clears it; the low byte is
 * written back.
 * Source form: same body as FUN_a00f232c and FUN_a00f1374, with a plain else for the single block.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8026a7a[];
void FUN_a00f176c(unsigned char blk, unsigned short reg, unsigned char mask, unsigned char set)
{
    unsigned char i; unsigned char v;
    if (blk == 2) {
        for (i = 0; i <= 1; i++) {
            v = R(DAT_a8026a7a[i] + reg);
            if (set == 1) v |= mask; else v &= ~mask;
            R(DAT_a8026a7a[i] + reg) = (unsigned char)v;
        }
    } else {
        v = R(DAT_a8026a7a[blk] + reg);
        if (set == 1) v |= mask; else v &= ~mask;
        R(DAT_a8026a7a[blk] + reg) = (unsigned char)v;
    }
}
