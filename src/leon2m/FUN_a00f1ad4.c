/* leon2m FUN_a00f1ad4 @ 0xa00f1ad4 (-mcpu=v8 -O2 -g)
 * Writes val to the register word 0xCF000000 | ((DAT_0019a31c[blk] + reg) << 2). blk > 7 writes the register in
 * all eight blocks of the table. The `blk > 7` branch with the loop comes first in the source, matching the
 * target's branch order.
 */
extern unsigned short DAT_0019a31c[8];

void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;

    if ((unsigned int)blk > 7U) {
        for (i = 0; i <= 7; i++) {
            *(volatile unsigned int *)(0xcf000000 | (((unsigned int)DAT_0019a31c[i] + reg) << 2)) = val;
        }
    } else {
        *(volatile unsigned int *)(0xcf000000 | (((unsigned int)DAT_0019a31c[blk] + reg) << 2)) = val;
    }
}
