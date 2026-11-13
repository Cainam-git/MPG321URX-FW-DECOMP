/* audio_read_dp_maud  (FUN_a008b838)
 *
 * Return the audio M value (Maud) of a DP receiver.
 *   port: DP receiver 0/1
 * Returns: Maud
 * Name basis: derived - stable read of reg 0x63 through dp_reg_read24_stable; numerator in
 *   audio_calc_dp_sample_rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b838 @ 0xa008b838-0xa008b84c (20 bytes), flags -mcpu=v8 -Os -g.
 * Tail call of dp_reg_read24_stable with register 99.
 */
extern int dp_reg_read24_stable(unsigned char, unsigned short);

#define DP_AUDIO_MAUD_REG 99            /* 0x63 */

/*
 * Return the audio M value (Maud) of a DP receiver: DP receiver register 0x63 as read by dp_reg_read24_stable.
 * The caller audio_calc_dp_sample_rate uses the whole returned value.
 *   port: DP receiver 0 or 1
 */
int audio_read_dp_maud(unsigned char port)

{
  return dp_reg_read24_stable(port,DP_AUDIO_MAUD_REG);
}
