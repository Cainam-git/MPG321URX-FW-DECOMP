/* hdmi_rx21_status70_bit24  (FUN_a0096428)
 *
 * Return bit 24 of status word 0x70 of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - single bit of the register block
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0096428 @ 0xa0096428 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's types are kept; the function declares a second parameter that it does not use, and the
 * block address is read as an int from the 0x34-byte table entry.
 */
extern unsigned char hdmi_rx21_reg_blocks;      /* table of register block addresses, 0x34 bytes per receiver */
extern unsigned int reg_test_bit(unsigned int bit, int words);

/*
 * Return bit 24 of the register at offset 0x70 of block 0 of an HDMI 2.1 receiver (1 or 0).
 *   port: HDMI 2.1 receiver 0/1
 *   unused: not used
 * Called by hdmi_rx21_service_sync_events, which handles it as event 0x10.
 */
unsigned int hdmi_rx21_status70_bit24(unsigned int port, unsigned int unused)

{
  unsigned int bit;
  
  bit = reg_test_bit(0x18,*(int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34) + 0x70);
  return (unsigned int)(bit != 0);
}
