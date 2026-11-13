/* hdmi_rx21_pulse_ctrl_bit  (FUN_a007a050)
 *
 * Pulse bit 16 of PHY register 0x2E60 with bit 20 set.
 *   port: PHY
 * Name basis: descriptive - set bits 20 and 16, wait 100, clear bit 16; callers lane EQ apply and the link
 *   training checks
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007a050 @ 0xa007a050, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes, as the decompiler wrote them.
 */
extern void hdmi_phy_write_bit();
extern int timer_delay_units();

#define PHY_REG_2E60 0x2e60

/*
 * Pulse bit 16 of PHY register 0x2E60: set bits 20 and 16, wait 100 delay units, clear bit 16. Bit 20 stays set.
 * port: PHY index. Called by hdmi_rx21_apply_lane_eq and hdmi_rx21_restart_lanes, and by
 * DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable.
 */
void hdmi_rx21_pulse_ctrl_bit(unsigned char port)
{
  hdmi_phy_write_bit(1, 0x14, port, PHY_REG_2E60);
  hdmi_phy_write_bit(1, 0x10, port, PHY_REG_2E60);
  timer_delay_units(100);
  hdmi_phy_write_bit(0, 0x10, port, PHY_REG_2E60);
}
