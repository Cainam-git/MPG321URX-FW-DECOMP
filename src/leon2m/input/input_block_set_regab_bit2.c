/* input_block_set_regab_bit2  (FUN_a0100468)
 *
 * Set or clear bit 2 of register 0xAB of an input block for codes 0xE1 and 0xE2.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0100468 @ 0xa0100468, flags -mcpu=v8 -O3 -g.
 * Source form: a separate call in each arm of the if/else; the code test is (unsigned char)(code + 0x1f) <= 1.
 */
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

/*
 * Set (on non-zero) or clear (on zero) bit 2 of register 0xAB of an input block, but only when code is 0xE1 or
 * 0xE2; for any other code nothing happens. 0xE1 and 0xE2 are values of input_block_get_signal_code.
 *
 *   blk   input block
 *   code  signal code of the block
 *   on    new value of the bit
 *
 * No routine in the image calls it.
 */
void input_block_set_regab_bit2(unsigned char blk, unsigned char code, unsigned char on)
{
    if ((unsigned char)(code + 0x1f) <= 1) {
        if (on)
            input_capture_update_bits(blk, 0xab, 4, 1);
        else
            input_capture_update_bits(blk, 0xab, 4, 0);
    }
}
