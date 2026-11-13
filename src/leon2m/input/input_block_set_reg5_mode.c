/* input_block_set_reg5_mode  (FUN_a00fe820)
 *
 * Switch register 5 of input block 6 or 7 between its two modes.
 * Name basis: descriptive - bit 0 and bit 3 exchanged; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe820 @ 0xa00fe820, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the test is '!on' with the (reg & ~8) | 1 arm first (if/else); the
 * 'default then override' form and the 'if (on)' order give other block layouts. input_capture_read8 is declared
 * returning unsigned int (its value is used unmasked). The firmware also holds an unreachable ret/restore pair
 * after the routine (FUN_a00fe878).
 */
extern unsigned int input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);

/*
 * Register 5 of input block 6 or 7 holds one of two modes, kept in bit 0 and bit 3: exactly one of the two
 * bits is set. Any other block number is ignored.
 *
 *   blk  input block; only 6 and 7 are handled
 *   on   0: set bit 0 and clear bit 3; non-zero: set bit 3 and clear bit 0
 *
 * No routine in the image calls it.
 */
void input_block_set_reg5_mode(unsigned char blk, unsigned char on)
{
    unsigned int reg;
    unsigned int value;

    if ((unsigned char)(blk - 6) > 1)
        return;
    reg = input_capture_read8(blk, 5);
    if (!on)
        value = (reg & ~8) | 1;
    else
        value = (reg & ~1) | 8;
    input_capture_write8(blk, 5, value);
}
