/* pq_block_blank  (FUN_a0106ba8)
 *
 * Blank a picture block and switch its output path off.
 * Name basis: derived - latches the unit event, sets the block's flag, register 0x54 = 2, output path off;
 *   many callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106ba8 @ 0xa0106ba8, flags -mcpu=v8 -O2 -g (the section default; -O3 -g and -Os -g give the
 * same bytes).
 * Source form: the final call is a tail call (restore in its delay slot); parameters 3..6 are handed on in
 * the same registers. The four extra arguments, the unused local and the cast of the early return do not
 * change the bytes.
 */
extern void pq_block_write8();
extern int pq_block_set_output_path();
extern void pq_port_set_reg10_bit0();
extern int reg_set_channel_ctrl_bit();

#define LAST_BLOCK_INDEX 3          /* valid picture block indices are 0..3 */
#define BIT_SET 1                   /* 'set' argument of the two bit routines */
#define BLK_BLANK_MODE 0x54         /* picture block register: blank mode */
#define BLANK_MODE_ON 2             /* value written to BLK_BLANK_MODE to blank the block */
#define OUTPUT_PATH_OFF 0           /* pq_block_set_output_path: switch the output path off */

/*
 * Blank a picture block and switch its output path off.
 *
 *   block_index         picture block 0..3 (low 8 bits); a larger number does nothing and is returned
 *   unused_param_2      not read
 *   output_path_arg1..4 handed on to pq_block_set_output_path, which takes only two parameters
 *
 * Steps: bit block_index of 0xCF011FC0 set (reg_set_channel_ctrl_bit), bit 0 of register 0x10 set
 * (pq_port_set_reg10_bit0), BLK_BLANK_MODE = 2, output path off (pq_block_set_output_path(block, 0)).
 *
 * Callers: ddc_apply_maker_vcp_set, sys_shut_down_blocks, oled_power_task (four calls), sys_set_channel_port,
 * GlobalModeHandler and sys_mode_restart_channel.
 */
int pq_block_blank(unsigned int block_index, unsigned int unused_param_2, unsigned int output_path_arg1,
                      unsigned int output_path_arg2, unsigned int output_path_arg3,
                      unsigned int output_path_arg4)
{
  unsigned int unused_zero;
  
  block_index = block_index & 0xff;
  if (LAST_BLOCK_INDEX < block_index) {
    return (unsigned long long)block_index;
  }
  reg_set_channel_ctrl_bit(block_index, BIT_SET);
  pq_port_set_reg10_bit0(block_index, BIT_SET);
  pq_block_write8(block_index, BLK_BLANK_MODE, BLANK_MODE_ON);
  unused_zero = 0;
  return pq_block_set_output_path(block_index, OUTPUT_PATH_OFF, output_path_arg1, output_path_arg2,
                                  output_path_arg3, output_path_arg4);
}
