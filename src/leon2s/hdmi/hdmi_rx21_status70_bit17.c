/* hdmi_rx21_status70_bit17  (FUN_a009c6e4)
 *
 * Return bit 17 of status register 0x70 of an HDMI 2.1 receiver.
 *   param_1: HDMI 2.1 receiver 0/1
 * Returns: bit value
 * Name basis: descriptive - last field of the audio status block; read only when hdmi_rx21_status30_bit4 is
 *   set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c6e4 @ 0xa009c6e4 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's types are kept; the function declares a second parameter that it does not use.
 */
extern unsigned char hdmi_rx21_reg_blocks;      /* table of register block addresses, 0x34 bytes per receiver */
extern unsigned int reg_test_bit(unsigned int bit, int words);

/*
 * Return bit 17 of the register at offset 0x70 of block 0 of an HDMI 2.1 receiver (1 or 0).
 *   port: HDMI 2.1 receiver 0/1
 *   unused: not used
 * Called by hdmi_rx21_read_audio_status, only when hdmi_rx21_status30_bit4 is set.
 */
unsigned int hdmi_rx21_status70_bit17(unsigned int port, unsigned int unused)

{
  unsigned int bit;
  
  bit = reg_test_bit(0x11,*(int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34) + 0x70);
  return (unsigned int)(bit != 0);
}
