/* input_block_get_reg10_low4  (FUN_a0123574)
 *
 * Return the low four bits of register 0x10 of an input block.
 * Returns: 0..15
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123574 @ 0xa0123574, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_unit_read8 is declared (int, int) returning int; the parameter is an int that is masked to
 * 8 bits before the call.
 */
extern int input_unit_read8(int, int);

/*
 * Return bits 0..3 of register 0x10 of an input block.
 *
 * No routine in the image calls it.
 */
int input_block_get_reg10_low4(int blk)
{
    blk &= 0xff;
    return input_unit_read8(blk, 0x10) & 0xf;
}
