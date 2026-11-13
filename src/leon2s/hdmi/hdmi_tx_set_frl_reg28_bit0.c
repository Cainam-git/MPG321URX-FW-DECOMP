/* hdmi_tx_set_frl_reg28_bit0  (FUN_a0094ac4)
 *
 * Set or clear bit 0 of HDMI TX bank 4 register 0x28.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - callers the FRL training state steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094ac4 @ 0xa0094ac4 (-mcpu=v8 -Os -g)
 * Source form: the port and the flag are byte-wide parameters passed straight on.
 */
#define HDMI_TX_BANK_FRL 4              /* bank 4 of an HDMI transmitter's registers (the FRL registers) */

extern int hdmi_tx_reg_update_bits();

/*
 * Set or clear bit 0 of register 0x28 of bank 4.
 *   port: HDMI TX port 0/1
 *   on: 1 = set the bits, any other value = clear them
 * Called by the FRL link training steps LTS_2, LTS_3 and LTS_P.
 */
void hdmi_tx_set_frl_reg28_bit0(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,HDMI_TX_BANK_FRL,0x28,1,on);
  return;
}
