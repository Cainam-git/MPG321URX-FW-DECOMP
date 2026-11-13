/* input_block_get_reg6_bit6  (FUN_a00f8f34)
 *
 * Return bit 6 of register 6 of an input block's capture registers.
 * Returns: 0 or 1
 * Name basis: descriptive - input_capture_read8(block, 6) & 0x40; the bit that input_block_set_reg6_bit6 sets
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8f34 @ 0xa00f8f34, flags -mcpu=v8 -O2 -g.
 * Source form: the explicit "? 0 : 1" gives the "cmp %g0, %o0; addx %g0, 0, %i0" pattern of the firmware;
 * "!= 0" gives "and %o0, 1, %i0" instead.
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);

/* Return 1 when bit 6 of register 6 of the capture block is set, else 0 (the bit input_block_set_reg6_bit6
 * sets). */
int input_block_get_reg6_bit6(unsigned char block)
{
    int value = input_capture_read8(block, 6);
    return (value & 0x40) == 0 ? 0 : 1;
}
