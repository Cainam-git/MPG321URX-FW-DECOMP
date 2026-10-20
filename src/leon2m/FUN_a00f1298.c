/* leon2m FUN_a00f1298 @ 0xa00f1298 (-mcpu=v8 -O3 -g)
 * Writes the 16-bit val (low byte, then high byte) to register reg and reg + 1 of a block, register n of block b
 * being the word at 0xCF000000 + 4 * (DAT_a8026a7e[b] + n) (u16 base table in RAM, four entries).
 * blk 4 writes blocks 0, 1 and 2 (the loop runs to 3 but skips entry 3); blk 0..3 writes that block; larger blk
 * writes nothing. No direct callers found.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8026a7e[4];

void FUN_a00f1298(unsigned char blk, unsigned short reg, unsigned short val)
{
    unsigned char i;
    unsigned int a;

    if (blk == 4) {
        for (i = 0; i <= 3; i++) {
            if (i != 3) {
                a = DAT_a8026a7e[i] + reg;
                R(a) = (unsigned char)val;
                R(a + 1) = val >> 8;
            }
        }
    } else if (blk <= 3) {
        a = DAT_a8026a7e[blk] + reg;
        R(a) = (unsigned char)val;
        R(a + 1) = val >> 8;
    }
}
