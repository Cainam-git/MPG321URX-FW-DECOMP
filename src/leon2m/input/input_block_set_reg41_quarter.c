/* input_block_set_reg41_quarter  (FUN_a00f8cc4)
 *
 * Write a quarter of a value to register 0x41 of an input block.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8cc4 @ 0xa00f8cc4, flags -mcpu=v8 -O2 -g.
 */
extern int input_format_write16();

/* Write a quarter of the value (value / 4) to 16-bit register 0x41 of the format block. */
void input_block_set_reg41_quarter(unsigned char block, unsigned short value)
{
    input_format_write16(block, 0x41, (value & 0xffff) >> 2);
    return;
}
