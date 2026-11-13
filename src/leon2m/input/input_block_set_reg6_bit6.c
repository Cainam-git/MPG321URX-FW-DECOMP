/* input_block_set_reg6_bit6  (FUN_a00f8ef4)
 *
 * Set bit 6 of register 6 of an input block.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8ef4 @ 0xa00f8ef4, flags -mcpu=v8 -O2 -g.
 */
extern int input_capture_update_bits();

/* Set bit 6 of register 6 of the capture block. */
void input_block_set_reg6_bit6(unsigned char block)
{
    input_capture_update_bits(block, 6, 0x40, 1);
    return;
}
