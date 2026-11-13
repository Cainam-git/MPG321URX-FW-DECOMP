/* hdmi_rx21_clear_reg8_bit2  (FUN_a00a2bec)
 *
 * Clear bit 2 of control register 8 of an HDMI 2.1 receiver.
 *   p1: receiver
 * Returns: 0
 * Name basis: descriptive - caller hdmi_rx21_set_port_enable
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2bec @ 0xa00a2bec, flags -mcpu=v8 -Os -g.
 * Source form: the row array is the byte symbol hdmi_rx21_reg_blocks indexed by hand; the return value is the unused
 * second parameter shifted left by 32 as a 64-bit value (low word 0), which gives the firmware's return of 0.
 */
extern unsigned char hdmi_rx21_reg_blocks;     /* rows of 0x34 bytes, word 0 = block 0 of the receiver */
extern int reg_clear_bit();

/* Clear bit 2 of the word at offset 8 of register block 0 of the HDMI 2.1 receiver (0 or 1). Called by
   hdmi_rx21_set_port_enable. The second parameter is unused; the result is 0. */
unsigned int hdmi_rx21_clear_reg8_bit2(unsigned int receiver, unsigned int unused)
{
    reg_clear_bit(2, *(int *)(&hdmi_rx21_reg_blocks + (receiver & 0xff) * 0x34) + 8);
    return (unsigned long long)unused << 0x20;
}
