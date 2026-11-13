/* input_capture_write8  (FUN_a00f1ad4)
 *
 * Write an 8-bit register of one input capture block, or of all eight.
 * Name basis: proven - block base addresses from the ROM table at 0x19A31C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1ad4 @ 0xa00f1ad4, flags -mcpu=v8 -O3 -g.
 */

extern unsigned short input_capture_reg_bases[8];

/*
 * Write val to register reg of input capture block blk (0..7); a block number above 7 writes it to the
 * same register of all eight blocks. Addressing as in input_capture_read8.
 */
void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;

    if ((unsigned int)blk > 7U) {
        for (i = 0; i <= 7; i++) {
            *(volatile unsigned int *)(0xcf000000 | (((unsigned int)input_capture_reg_bases[i] + reg) << 2)) = val;
        }
    } else {
        *(volatile unsigned int *)(0xcf000000 | (((unsigned int)input_capture_reg_bases[blk] + reg) << 2)) = val;
    }
}
