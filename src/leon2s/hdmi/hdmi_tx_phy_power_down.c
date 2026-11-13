/* hdmi_tx_phy_power_down  (FUN_a008e6b8)
 *
 * Apply the HDMI TX PHY power-down settings.
 *   port: HDMI TX port 0/1
 * Name basis: proven - prints '[HDMI_TX]: PHY Power Down Setting'; calls each PHY field setter with 0; TX
 *   command 9
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e6b8 @ 0xa008e6b8, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes. The unused words are the decompiler's pass-through of
 * the argument registers; the last call forwards three of them.
 */
extern unsigned int DAT_a0068d40;
extern int dbg_print_string();
extern void hdmi_tx_set_reg7c_low_nibble();
extern void hdmi_tx_set_reg08_bit3();
extern void hdmi_tx_set_reg7f_bit0();
extern void hdmi_tx_phy_set_power();
extern int hdmi_tx_set_reg09_mode();
extern int hdmi_tx_set_reg05_enable();
extern void hdmi_tx_set_lane_regs_7b_9f();
extern void hdmi_tx_set_regs_0e_9b();
extern void hdmi_tx_set_regs_7c_9a();

/*
 * Power down the HDMI TX PHY. Prints "[HDMI_TX]:  PHY Power Down Setting" (in colour) on the debug console, then
 * writes 0 through each of these setters, in this order: register 0x7C (hdmi_tx_set_reg7c_low_nibble),
 * registers 0x7C and 0x9A, registers 0x7B and 0x9D..0x9F, registers 0x0E and 0x9B, bit 0 of register 0x7F,
 * hdmi_tx_phy_set_power(port, 0, 0), bit 3 of register 8, register 5, register 9.
 *   port: HDMI TX port 0/1.  unused_2 to unused_6: not used here; the last three are passed on in the last call.
 * Called by hdmi_tx_run_step (the TX_STEP_STOP step).
 */
void hdmi_tx_phy_power_down(unsigned char port, unsigned int unused_2, unsigned int unused_3, unsigned int unused_4,
                 unsigned int unused_5, unsigned int unused_6)

{
  dbg_print_string(&DAT_a0068d40);
  hdmi_tx_set_reg7c_low_nibble(port, 0);
  hdmi_tx_set_regs_7c_9a(port, 0);
  hdmi_tx_set_lane_regs_7b_9f(port, 0);
  hdmi_tx_set_regs_0e_9b(port, 0);
  hdmi_tx_set_reg7f_bit0(port, 0);
  hdmi_tx_phy_set_power(port, 0, 0);
  hdmi_tx_set_reg08_bit3(port, 0);
  hdmi_tx_set_reg05_enable(port, 0);
  hdmi_tx_set_reg09_mode(port, 0, unused_3, unused_4, unused_5, unused_6);
}
