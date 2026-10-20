/* leon2m FUN_a00f2b8c @ 0xa00f2b8c-0xa00f2c20 (37 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf. blk, reg, val (u8 each, and 0xff). blk == 8: for i = 0..3 write val to the
 * hw register 0xcf000000 | ((DAT_0019a2e4[i] + reg) << 2) (u16 table of 4 block bases);
 * else if blk <= 3: write val to 0xcf000000 | ((DAT_0019a2e4[blk] + reg) << 2); else nothing.
 * void. Twin of src/leon2m/FUN_a00f2c20.c (2-entry table 0x19a2e0, 'blk > 1' = all).
 * Fix vs the autoc draft (81.08): written like the f2c20 twin (u16 table array, u8 params,
 * do/while over i); volatile only on the 0xcf... hw register store. Aids: none.
 */
extern unsigned short DAT_0019a2e4[4];

void FUN_a00f2b8c(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;
    unsigned int addr;

    if (blk == 8) {
        i = 0;
        do {
            addr = DAT_0019a2e4[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (addr << 2)) = val;
            i++;
        } while (i <= 3);
    } else if (blk <= 3) {
        addr = DAT_0019a2e4[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (addr << 2)) = val;
    }
}
