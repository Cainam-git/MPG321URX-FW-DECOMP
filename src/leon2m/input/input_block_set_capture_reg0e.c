/* input_block_set_capture_reg0e  (FUN_a00f8e44)
 *
 * Write register 0x0E of an input block's capture unit: the stored block offset plus the value.
 * Note: One more on blocks 6/7 when three tests pass.
 * Name basis: descriptive - register 0x0E = offset + value; sys_api_set_channel_position_field passes position
 *   field 16 (channel record +0x20)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8e44 @ 0xa00f8e44, flags -mcpu=v8 -O3 -g. The last call is a tail call.
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short input_block_offsets[];

/* Write value to 16-bit register 0x0C of the capture block and, with the block's offset
 * (input_block_set_offset) added, to register 0x0E. The callers pass the channel's vertical start
 * (sys_api_set_channel_position_field: position field 16; panel_output_setup_channel_timing).
 * On blocks 6 and 7 the value is first increased by one when bits 4-5 of register 3 are clear, the low four
 * bits of register 4 are below 2 and bit 0 of register 0x5C is clear (tested in that order). */
void input_block_set_capture_reg0e(unsigned char block, unsigned short value)
{
    if ((unsigned char)(block - 6) <= 1) {
        if ((input_capture_read8(block, 3) & 0x30) == 0) {
            if ((input_capture_read8(block, 4) & 0xf) < 2) {
                if ((input_capture_read8(block, 0x5c) & 1) == 0)
                    value = value + 1;
            }
        }
    }
    input_capture_write16(block, 0xe, input_block_offsets[block] + value);
    input_capture_write16(block, 0xc, value);
}
