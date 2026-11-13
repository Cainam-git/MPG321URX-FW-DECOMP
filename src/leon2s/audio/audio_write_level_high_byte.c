/* audio_write_level_high_byte  (FUN_a008a95c)
 *
 * Write a level byte to the audio register 0xCF0110E4.
 *   value: byte
 * Name basis: descriptive - callers audio_set_output_level and audio_set_input_levels
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008a95c @ 0xa008a95c (-mcpu=v8 -Os -g)
 */
#define reg_audio_level_high (*(volatile unsigned int *)0xcf0110e4)

/*
 * Write a byte to the audio register 0xCF0110E4 (audio_init_ctrl_registers loads it with 0x54 at start-up).
 * Called by audio_set_output_level and audio_set_input_levels with bits 8..15 of the level.
 *   value: the byte (only the low 8 bits are used)
 */
void audio_write_level_high_byte(unsigned int value)
{
  reg_audio_level_high = value & 0xff;
  return;
}
