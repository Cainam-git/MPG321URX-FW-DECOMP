/* leon2m FUN_a00f18d4 @ 0xa00f18d4-0xa00f19a4 (208 bytes), flags -mcpu=v8 -O3 -g.
 * Register n of block b is the word at 0xCF000000 + 4 * (DAT_a8026a7a[b] + n) (u16 base table, as in
 * FUN_a00f1690). Writes the low byte of val to register reg and the high byte to register reg + 1:
 * blk 2 writes blocks 0 and 1, any other blk writes block blk.
 * Same form as FUN_a00f1298 (other table, no range check). Old-style (K&R) parameter declarations: the
 * promoted reg/val arguments are copied at entry and zero-extended at each use (a prototype gives an and-mask).
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8026a7a[2];

void FUN_a00f18d4(blk, reg, val)
unsigned char blk;
unsigned short reg;
unsigned short val;
{
    unsigned char i;
    unsigned int a;

    if (blk == 2) {
        for (i = 0; i <= 1; i++) {
            a = DAT_a8026a7a[i] + reg;
            R(a) = val & 0xff;
            R(a + 1) = val >> 8;
        }
    } else {
        a = DAT_a8026a7a[blk] + reg;
        R(a) = val & 0xff;
        R(a + 1) = val >> 8;
    }
}
