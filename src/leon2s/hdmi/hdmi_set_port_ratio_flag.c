/* hdmi_set_port_ratio_flag  (FUN_a0083618)
 *
 * Store the per-port clock-ratio flag byte.
 *   phy
 *   value
 * Name basis: descriptive - byte array read by hdmi_eq_get_clock_ratio_mode; set to 1 by the port restart
 *   routines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083618 @ 0xa0083618, flags -mcpu=v8 -Os -g.
 */
extern unsigned char hdmi_eq_tmds_bit_ratio_guess[];

/*
 * Store one byte in hdmi_eq_tmds_bit_ratio_guess for a PHY (the byte hdmi_eq_get_clock_ratio_mode and hdmi_eq_get_scramble_mode
 * return when hdmi_eq_mode_override_flags is 1).
 *   phy: PHY index.  value: the byte. Called by hdmi_tmds_restart_port and hdmi_rx21_restart_port.
 */
void hdmi_set_port_ratio_flag(unsigned int phy, unsigned char value)

{
  hdmi_eq_tmds_bit_ratio_guess[(phy & 0xff)] = value;
}
