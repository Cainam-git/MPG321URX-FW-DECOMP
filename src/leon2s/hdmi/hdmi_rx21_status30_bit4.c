/* hdmi_rx21_status30_bit4  (FUN_a0097ed0)
 *
 * Return bit 4 of status word 0x30 of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - single bit; callers hdmi_rx21_detect_timing_change, hdmi_rx21_update_mode_info and
 *   hdmi_rx21_read_audio_status
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0097ed0 @ 0xa0097ed0 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's types are kept; the function declares a second parameter that it does not use.
 */
extern unsigned char hdmi_rx21_reg_blocks;      /* table of register block addresses, 0x34 bytes per receiver */
extern unsigned int reg_test_bit(unsigned int bit, int words);

/*
 * Return bit 4 of the register at offset 0x30 of block 0 of an HDMI 2.1 receiver (1 or 0).
 *   port: HDMI 2.1 receiver 0/1
 *   unused: not used
 * hdmi_rx21_detect_timing_change compares the result with the hdmi_mode byte of the receiver's record, hdmi_rx21_update_mode_info
 * stores it as the first byte of the mode info, and hdmi_rx21_read_audio_status copies it into its block.
 */
unsigned int hdmi_rx21_status30_bit4(unsigned int port, unsigned int unused)

{
  unsigned int bit;
  
  bit = reg_test_bit(4,*(int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34) + 0x30);
  return (unsigned int)(bit != 0);
}
