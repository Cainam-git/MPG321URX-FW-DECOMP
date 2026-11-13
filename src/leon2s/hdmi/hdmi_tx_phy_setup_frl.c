/* hdmi_tx_phy_setup_frl  (FUN_a008ecb8)
 *
 * Load the HDMI TX PHY settings for FRL operation.
 *   port: HDMI TX port
 *   rate: FRL rate
 * Name basis: descriptive - fixed PHY field values, one depending on the FRL rate; TX command 11
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008ecb8 @ 0xa008ecb8, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes; the unused words are the decompiler's pass-through of
 * the argument registers (the last call forwards three of them).
 */
extern void hdmi_tx_set_lane_regs_7b_9f();
extern void hdmi_tx_set_regs_08_98();
extern void hdmi_tx_set_regs_0e_9b();
extern int hdmi_tx_set_regs_0a_99();
extern int hdmi_tx_set_regs_7c_9a();
extern void hdmi_tx_set_regs_39_30();
extern int hdmi_tx_set_reg3b_mode();
extern void hdmi_tx_reg_update_bits();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Load the HDMI TX PHY registers for FRL operation, in this order: bit 7 of register 0x7D set; registers 0x39
 * and 0x30 for mode 2 (hdmi_tx_set_regs_39_30); registers 0x7B, 0x9D..0x9F = 0x1B; registers 0x08, 0x98, 0x99
 * for mode 3 with level 0x0B; registers 0x0E and 0x9B = 0x44; registers 0x7C and 0x9A = 0 for FRL rate 1 or 2
 * and 0x30 for any other rate; register 0x3B for mode 1; registers 0x0A and 0x99 for mode 3 with level 2.
 *   port: HDMI TX port.  rate: the channel record's FRL rate.  unused_3 to unused_6: not used here; the last
 *   three are passed on in the last call.
 * Called by hdmi_tx_run_step (the TX_STEP_LINK_FRL step).
 */
void hdmi_tx_phy_setup_frl(unsigned char port, char rate, unsigned int unused_3, unsigned int unused_4,
                 unsigned int unused_5, unsigned int unused_6)

{
  unsigned char reg7c_value;
  
  hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x7d, 0x80, 1);
  hdmi_tx_set_regs_39_30(port, 2);
  hdmi_tx_set_lane_regs_7b_9f(port, 0x1b);
  hdmi_tx_set_regs_08_98(port, 3, 0xb);
  hdmi_tx_set_regs_0e_9b(port, 0x44);
  reg7c_value = 0;
  if (1 < (unsigned char)(rate - 1U)) {
    reg7c_value = 0x30;
  }
  hdmi_tx_set_regs_7c_9a(port, reg7c_value);
  hdmi_tx_set_reg3b_mode(port, 1);
  hdmi_tx_set_regs_0a_99(port, 3, 2, unused_4, unused_5, unused_6);
}
