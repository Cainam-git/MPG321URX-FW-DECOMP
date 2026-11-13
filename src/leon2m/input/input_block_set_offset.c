/* input_block_set_offset  (FUN_a00f8e2c)
 *
 * Store the per-block offset.
 * Name basis: descriptive - halfword table at 0xA802B7D8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8e2c @ 0xa00f8e2c, flags -mcpu=v8 -O2 -g.
 */
extern unsigned short input_block_offsets[];

/* Store the offset of a block in the halfword table at 0xA802B7D8. input_block_set_capture_reg0e adds it
 * to the width it writes to register 0x0E. */
void input_block_set_offset(unsigned int block, unsigned short offset)
{
    input_block_offsets[(block & 0xff)] = offset;
    return;
}
