/* hdmi_rx21_restart_port  (FUN_a00a22d4)
 *
 * Restart an HDMI 2.1 receiver port: flag it, clear its controls, reset PHY errors.
 *   p1: receiver 0/1
 * Name basis: derived - HDMI 2.1 path of mailbox command 0x12 (restart one input port); PHYs 2/3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a22d4, flags -mcpu=v8 -Os -g (section default). The return statement for ports above 1 is kept as
 * the firmware has it (the second parameter is only used there); the function is declared void.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

extern void hdmi_phy_reset_error_counters(unsigned char phy);
extern int hdmi_set_port_ratio_flag();
extern int hdmi_rx21_clear_port_ctrl_bits();

/*
 * Restart HDMI 2.1 receiver `port` (the HDMI 2.1 branch of mailbox command 0x12): receiver 0 uses PHY 2,
 * receiver 1 PHY 3. For those two, in this order: hdmi_set_port_ratio_flag(phy, 1),
 * hdmi_rx21_clear_port_ctrl_bits(port), hdmi_phy_reset_error_counters(phy). Any other port number returns
 * without a call. Called by ipc_dispatch_command.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_restart_port(unsigned char port, unsigned int unused)
{
  unsigned char phy;

  phy = 2;
  if ((port != '\0') && (phy = 3, port != '\x01')) {
    return CONCAT44(unused, 3);
  }
  hdmi_set_port_ratio_flag(phy, 1);
  hdmi_rx21_clear_port_ctrl_bits(port);
  return hdmi_phy_reset_error_counters((unsigned char)phy);
}
