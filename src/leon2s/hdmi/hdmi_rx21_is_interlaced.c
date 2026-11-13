/* hdmi_rx21_is_interlaced  (FUN_a009c3bc)
 *
 * Return whether the HDMI 2.1 receiver reports an interlaced picture.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 1 when interlaced
 * Name basis: derived - stored as the 'P/I' field of the mode info printed by H_Total
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c3bc @ 0xa009c3bc (-mcpu=v8 -Os -g)
 * Source form: Ghidra's types are kept; the function declares a second parameter that it does not use.
 */
extern unsigned char hdmi_rx21_reg_blocks;      /* table of register block addresses, 0x34 bytes per receiver */
extern unsigned int reg_test_bit(unsigned int bit, int words);

/*
 * Return bit 10 of the register at offset 0x54 of block 0 of an HDMI 2.1 receiver (1 or 0). The caller stores it
 * as the 'P/I' field of the mode info.
 *   port: HDMI 2.1 receiver 0/1
 *   unused: not used
 * Called by hdmi_rx21_update_mode_info.
 */
unsigned int hdmi_rx21_is_interlaced(unsigned int port, unsigned int unused)

{
  unsigned int bit;
  
  bit = reg_test_bit(10,*(int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34) + 0x54);
  return (unsigned int)(bit != 0);
}
