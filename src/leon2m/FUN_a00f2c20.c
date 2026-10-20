/* leon2m FUN_a00f2c20 @ 0xa00f2c20  MATCH (-mcpu=v8 -O2 -g)
 * 
 */
extern unsigned short DAT_0019a2e0[8];

void FUN_a00f2c20(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;
    unsigned int addr;

    if ((unsigned int)blk > 1U) {
        i = 0;
        do {
            addr = DAT_0019a2e0[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (addr << 2)) = val;
            i++;
        } while (i <= 1);
    } else {
        addr = DAT_0019a2e0[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (addr << 2)) = val;
    }
}
