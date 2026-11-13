/* hdmi_tx_set_frl_reg28_bit2  (FUN_a0094ae8)
 *
 * Set or clear bit 2 of HDMI TX bank 4 register 0x28.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - only caller hdmi_tx_run_step, in its FRL link step, always with on = 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094ae8 @ 0xa0094ae8 (-mcpu=v8 -Os -g)
 * Source form: the port and the flag are byte-wide parameters passed straight on.
 */
#define HDMI_TX_BANK_FRL 4              /* bank 4 of an HDMI transmitter's registers (the FRL registers) */

extern int hdmi_tx_reg_update_bits();

/*
 * Set or clear bit 2 of register 0x28 of bank 4.
 *   port: HDMI TX port 0/1
 *   on: 1 = set the bits, any other value = clear them
 * Called by hdmi_tx_run_step in TX_STEP_LINK_FRL (always with on = 1).
 */
void hdmi_tx_set_frl_reg28_bit2(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,HDMI_TX_BANK_FRL,0x28,4,on);
  return;
}
