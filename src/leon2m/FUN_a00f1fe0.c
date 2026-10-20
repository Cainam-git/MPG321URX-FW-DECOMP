/* leon2m FUN_a00f1fe0 @ 0xa00f1fe0  MATCH (-mcpu=v8 -O2 -g)
 * Writes val to register reg of block blk: address 0xCF000000 | ((DAT_0019a2fc[blk] + reg) << 2), DAT_0019a2fc
 * being a table of 8 halfword block bases. For blk > 7 the same register of all 8 blocks is written (loop i =
 * 0..7). Same addressing as FUN_a00f2c20 and FUN_a00f1ad4.
 */
// FUN_a00f1fe0 at 0xa00f1fe0
extern unsigned short DAT_0019a2fc[8];

void FUN_a00f1fe0(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;
    unsigned int addr;

    if ((unsigned int)blk > 7U) {
        i = 0;
        do {
            addr = DAT_0019a2fc[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (addr << 2)) = val;
            i++;
        } while (i <= 7);
    } else {
        addr = DAT_0019a2fc[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (addr << 2)) = val;
    }
}
