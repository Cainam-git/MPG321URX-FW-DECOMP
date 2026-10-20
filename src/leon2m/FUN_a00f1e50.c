/* leon2m FUN_a00f1e50 @ 0xa00f1e50 (-mcpu=v8 -O2 -g)
 * The function writes a value to a hardware register at 0xCF000000 + 4*(table[block]+reg). If the block index is 8 or more, it writes to all 8 table entries; otherwise it writes to just the selected entry. The main uncertainty is whether the original used a do-while loop with the index masked to 8 bits (as in the reference functions) or a different loop form; the structure here follows the proven byte-exact pattern from FUN_a00f2c20.
 */
extern unsigned short DAT_0019a30c[8];

void FUN_a00f1e50(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;
    unsigned int addr;

    if ((unsigned int)blk > 7U) {
        i = 0;
        do {
            addr = DAT_0019a30c[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (addr << 2)) = val;
            i++;
        } while (i <= 7);
    } else {
        addr = DAT_0019a30c[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (addr << 2)) = val;
    }
}
