/* audio_unmute_dp_fifo  (FUN_a008b9b0)
 *
 * Reset and unmute the audio FIFO of a DP receiver.
 *   port: DP receiver 0/1
 *   on: non-zero = act
 * Name basis: derived - audio_reset_dp_fifo then clears reg 0x50 bit 6; called before the 'DP fifo mute off'
 *   print
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b9b0 @ 0xa008b9b0-0xa008b9ec (60 bytes, with the merged ret/restore tail at 0xa008b9e4),
 * flags -mcpu=v8 -Os -g.
 * The call to dp_reg_update_bits is a tail call (call + restore).
 */
extern void audio_reset_dp_fifo(unsigned char);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);

/*
 * Reset the audio FIFO of a DP receiver and clear bit 6 of its register 0x50 (the bit audio_mute_dp_fifo sets).
 * Does nothing when "on" is 0.
 *   port: DP receiver 0 or 1
 *   on:   non-zero = do it
 */
void audio_unmute_dp_fifo(unsigned char port, unsigned char on)
{
  if (on != 0) {
    audio_reset_dp_fifo(port);
    dp_reg_update_bits(port, 0x50, 0x40, 0);
  }
}
