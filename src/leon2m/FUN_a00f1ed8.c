/* leon2m FUN_a00f1ed8 @ 0xa00f1ed8-0xa00f1f9c (49 words).
 * Template FUN_a00f1d48: Write 16-bit value (low byte to reg, high to reg+1) to 0x19A31C-table block blk; blk >= 8
 * writes all eight blocks.
 * This function is the same code as FUN_a00f1d48 (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0x19a31c -> 0x19a30c
 */
extern unsigned short DAT_0019a30c[8];
void FUN_a00f1ed8(unsigned char blk, unsigned char reg, unsigned short val)
{
    unsigned char i;
    unsigned int a;
    if (blk > 7) {
        for (i = 0; i <= 7; i++) {
            a = DAT_0019a30c[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (a << 2)) = (unsigned char)val;
            *(volatile unsigned int *)(0xcf000000 | ((a + 1) << 2)) = val >> 8;
        }
    } else {
        a = DAT_0019a30c[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (a << 2)) = (unsigned char)val;
        *(volatile unsigned int *)(0xcf000000 | ((a + 1) << 2)) = val >> 8;
    }
}
