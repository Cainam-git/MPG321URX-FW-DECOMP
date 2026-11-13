/* input_block_set_reg40_field  (FUN_a0121b98)
 *
 * Write register 0x40 of an input block as (old bit 0) | value << 1; all other bits end up 0.
 * Note: Its only caller input_load_block_source_registers passes 0, 2 and 3, which gives bits 1..2 = 0, 4 and
 *   6.
 * Name basis: descriptive - input_measure_write8(block, 0x40, (old & 1) | value << 1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121b98 @ 0xa0121b98, flags -mcpu=v8 -O3 -g.
 * Source form: the 'and 1' is on the value read, not on blk; the write is a tail call to a callee that takes
 * three arguments (void, unsigned char x3).
 */
extern unsigned char input_measure_read8(unsigned char, unsigned char);
extern void input_measure_write8(unsigned char, unsigned char, unsigned char);

/*
 * Rewrite register 0x40 of the measure block of an input block as (old bit 0) | (on << 1). Bit 1 takes the value
 * of on; bit 0 is kept; all other bits are cleared.
 *
 *   blk  input block
 *   on   0 or 1
 *
 * Called from input_load_block_source_registers.
 */
void input_block_set_reg40_field(unsigned char blk, unsigned char on)
{
    unsigned char reg;

    reg = input_measure_read8(blk, 0x40);
    input_measure_write8(blk, 0x40, (reg & 1) | (on << 1));
}
