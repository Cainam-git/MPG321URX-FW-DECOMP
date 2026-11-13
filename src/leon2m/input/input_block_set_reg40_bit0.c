/* input_block_set_reg40_bit0  (FUN_a0121b50)
 *
 * Set or clear bit 0 of register 0x40 of an input block.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121b50 @ 0xa0121b50, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_measure_update_bits is declared as an unprototyped int-returning routine; the 'on' arm
 * returns early after its call.
 */
extern int input_measure_update_bits();

/*
 * Set (on non-zero) or clear (on zero) bit 0 of register 0x40 of the measure block of an input block.
 * input_block_set_reg40_field writes bit 1 of the same register.
 *
 *   blk  input block
 *   on   new value of the bit
 *
 * Called from input_load_block_source_registers.
 */
void input_block_set_reg40_bit0(unsigned char blk, unsigned char on)
{
    if (on != 0) {
        input_measure_update_bits(blk, 0x40, 1, 1);
        return;
    }
    input_measure_update_bits(blk, 0x40, 1, 0);
}
