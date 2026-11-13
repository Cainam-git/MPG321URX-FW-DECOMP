/* hdmi_tx_set_frl_reg28_bits  (FUN_a0094b0c)
 *
 * Set or clear bits 1, 3, 4 and 5 of HDMI TX bank 4 register 0x28.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - only caller hdmi_tx_run_step, in its FRL link step, always with on = 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094b0c @ 0xa0094b0c (-mcpu=v8 -Os -g)
 * Source form: the port and the flag are byte-wide parameters passed straight on.
 */
#define HDMI_TX_BANK_FRL 4              /* bank 4 of an HDMI transmitter's registers (the FRL registers) */

extern int hdmi_tx_reg_update_bits();

/*
 * Set or clear bits 1, 3, 4 and 5 of register 0x28 of bank 4.
 *   port: HDMI TX port 0/1
 *   on: 1 = set the bits, any other value = clear them
 * Called by hdmi_tx_run_step in TX_STEP_LINK_FRL (always with on = 1).
 */
void hdmi_tx_set_frl_reg28_bits(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,HDMI_TX_BANK_FRL,0x28,0x3a,on);
  return;
}
