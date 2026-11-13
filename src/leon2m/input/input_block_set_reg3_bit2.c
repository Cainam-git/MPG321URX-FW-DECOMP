/* input_block_set_reg3_bit2  (FUN_a0123304)
 *
 * Set or clear bit 2 of register 3 of an input block.
 * Name basis: descriptive - tail call to the block bit write; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123304 @ 0xa0123304, flags -mcpu=v8 -O2 -g.
 * Source form: a separate call in each arm of the if/else (tail calls); the test is 'on == 1'.
 */
extern void input_unit_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

/*
 * Set bit 2 of register 3 of an input block when on is 1, clear it for any other value.
 *
 * No routine in the image calls it.
 */
void input_block_set_reg3_bit2(unsigned char blk, unsigned char on)
{
    if (on == 1)
        input_unit_update_bits(blk, 3, 4, 1);
    else
        input_unit_update_bits(blk, 3, 4, 0);
}
