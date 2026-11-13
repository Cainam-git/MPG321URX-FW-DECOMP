/* audio_set_dp_rx_level  (FUN_a008a9ec)
 *
 * Write a 16-bit audio level to a DisplayPort receiver.
 *   port: DP receiver 0/1
 *   v: 16-bit level
 * Name basis: descriptive - DP receiver registers 0x52/0x53; callers audio_set_output_level,
 *   audio_set_input_levels
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008a9ec @ 0xa008a9ec (-mcpu=v8 -Os -g).
 * Source form: dp_reg_write8 is declared without a prototype and the unused parameters 3 to 6 are kept; the
 * second call passes parameters 4 to 6 on, as the firmware does.
 */
extern int dp_reg_write8();

#define DP_AUDIO_LEVEL_LOW_REG  0x53    /* receiver register that gets the low byte of the level */
#define DP_AUDIO_LEVEL_HIGH_REG 0x52    /* receiver register that gets the high byte */

/*
 * Write a 16-bit audio level to one DP receiver: low byte first, then high byte.
 *   port:  DP receiver 0 or 1
 *   level: 16-bit level
 * The other four parameters are not used here; the last three are handed on to the second write.
 * Called by audio_set_output_level and audio_set_input_levels.
 */
void audio_set_dp_rx_level(unsigned char port, unsigned short level, unsigned int unused_3, unsigned int extra_4,
                 unsigned int extra_5, unsigned int extra_6)

{
  dp_reg_write8(port,DP_AUDIO_LEVEL_LOW_REG,level & 0xff);
  dp_reg_write8(port,DP_AUDIO_LEVEL_HIGH_REG,(level & 0xffff) >> 8,extra_4,extra_5,extra_6);
  return;
}
