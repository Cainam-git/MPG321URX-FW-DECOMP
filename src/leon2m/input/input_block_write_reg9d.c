/* input_block_write_reg9d  (FUN_a00f98f4)
 *
 * Write register 0x9D of an input block.
 * Name basis: descriptive - used by the low-resolution path set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f98f4 @ 0xa00f98f4, flags -mcpu=v8 -O2 -g.
 */
extern int input_capture_write8();

/* Write register 0x9D of the capture block. */
void input_block_write_reg9d(unsigned char block, unsigned char value)
{
  input_capture_write8(block, 0x9d, value);
  return;
}
