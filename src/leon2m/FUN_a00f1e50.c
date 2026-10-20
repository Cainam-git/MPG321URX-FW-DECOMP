/* leon2m FUN_a00f1e50 @ 0xa00f1e50 (-mcpu=v8 -O3 -g)
 * Writes val to the hardware register 0xCF000000 + 4 * (DAT_0019a30c[blk] + reg). When blk > 7 it writes to the
 * registers of all 8 table entries; otherwise only to the selected entry.
 * Source form: written like FUN_a00f2c20 (do/while over a u8 index, u8 parameters).
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
