/* audio_reset_dp_fifo  (FUN_a008b6f4)
 *
 * Reset the audio FIFO of a DP receiver.
 *   port: DP receiver 0/1
 * Name basis: derived - pulses bit 7 of regs 0x5A and 0x50 and clears status reg 0x54; part of the 'DP fifo
 *   mute off' path
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b6f4 @ 0xa008b6f4 (-mcpu=v8 -Os -g).
 * Source form: dp_reg_write8 and dp_reg_update_bits are declared without a prototype and the unused
 * parameters 2 to 6 are kept; the last call passes parameters 4 to 6 on, as the firmware does.
 */
extern int dp_reg_write8();
extern void dp_reg_update_bits();

/*
 * Reset the audio FIFO of a DP receiver: bit 7 of registers 0x5A and 0x50 is cleared and set again, then
 * 0xFF is written to register 0x54.
 *   port: DP receiver 0 or 1
 * The other parameters are not used here; the last three are handed on to the final write.
 * Called by audio_enable_unit_dp and audio_unmute_dp_fifo.
 */
void audio_reset_dp_fifo(unsigned char port, unsigned int unused_2, unsigned int unused_3, unsigned int extra_4,
                 unsigned int extra_5, unsigned int extra_6)

{
  dp_reg_update_bits(port,0x5a,0x80,0);
  dp_reg_update_bits(port,0x50,0x80,0);
  dp_reg_update_bits(port,0x5a,0x80,1);
  dp_reg_update_bits(port,0x50,0x80,1);
  dp_reg_write8(port,0x54,0xff,extra_4,extra_5,extra_6);
  return;
}
