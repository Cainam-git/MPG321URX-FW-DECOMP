/* audio_clear_dp_status  (FUN_a008b8ac)
 *
 * Clear the audio status registers 3 and 4 of a DP receiver.
 *   port: DP receiver 0/1
 * Name basis: descriptive - writes 0xFF to both (write-one-to-clear)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b8ac @ 0xa008b8ac (-mcpu=v8 -Os -g).
 * Source form: dp_status_reg_write8 is declared without a prototype and the unused parameters 2 to 6 are kept;
 * the last call passes parameters 4 to 6 on, as the firmware does.
 */
extern int dp_status_reg_write8();

/*
 * Write 0xFF to registers 4 and 3 of the status block of a DP receiver.
 *   port: DP receiver 0 or 1
 * The other parameters are not used here; the last three are handed on to the second write.
 */
void audio_clear_dp_status(unsigned char port, unsigned int unused_2, unsigned int unused_3, unsigned int extra_4,
                 unsigned int extra_5, unsigned int extra_6)

{
  dp_status_reg_write8(port,4,0xff);
  dp_status_reg_write8(port,3,0xff,extra_4,extra_5,extra_6);
  return;
}
