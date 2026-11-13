/* input_block_set_capture_reg12  (FUN_a00f8e0c)
 *
 * Write 16-bit register 0x12 of an input block's capture unit.
 * Name basis: descriptive - mechanics only; sys_api_set_channel_position_field passes position field 12
 *   (channel record +0x1E)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8e0c @ 0xa00f8e0c, flags -mcpu=v8 -O2 -g.
 */
extern int input_capture_write16();

/* Write 16-bit register 0x12 of the capture block (read back by input_block_get_capture_reg12). */
void input_block_set_capture_reg12(unsigned char block, unsigned short height)
{
    input_capture_write16(block, 0x12, height);
    return;
}
