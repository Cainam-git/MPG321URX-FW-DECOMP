/* audio_clear_main_enable  (FUN_a008a7a0)
 *
 * Clear bit 0 of the main audio control register.
 * Name basis: descriptive - 0xCF011008 bit 0; callers the receiver power-off routines and audio_configure
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008a7a0 @ 0xa008a7a0 (-mcpu=v8 -Os -g)
 */
#define reg_audio_main_control (*(volatile unsigned int *)0xcf011008)

/*
 * Clear the main enable (bit 0) of the main audio control register 0xCF011008; the other bits below bit 8 are
 * kept and the bits above bit 7 are cleared. Called by audio_configure and by the receiver power-off routines
 * (input_power_off_receivers_mode0 and _mode1).
 */
void audio_clear_main_enable(void)
{
  reg_audio_main_control = reg_audio_main_control & 0xfe;
  return;
}
