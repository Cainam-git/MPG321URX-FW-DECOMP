/* hdmi_phy_update_reg  (FUN_a00a7488)
 *
 * Read, mask and rewrite a paged HDMI PHY register.
 *   p1: PHY
 *   p2: register
 *   p3: keep mask
 *   p4: new bits
 * Name basis: proven - (value & keep mask) | new bits via hdmi_phy_read_reg / hdmi_phy_write_reg; used by
 *   TMDS_PowerOn/Off
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a7488 @ 0xa00a7488, flags -mcpu=v8 -Os -g.
 * Source form: the callees have no prototype; the routine takes six parameters and passes new_bits, param_5
 * and param_6 on to hdmi_phy_write_reg as extra arguments.
 */
extern int hdmi_phy_write_reg();
extern int hdmi_phy_read_reg();

/* Change register reg of PHY phy to (old value & keep_mask) | new_bits, using hdmi_phy_read_reg and
   hdmi_phy_write_reg. Used by TMDS_PowerOn and TMDS_PowerOff. The last two parameters are only passed on. */
void hdmi_phy_update_reg(unsigned int phy, unsigned short reg, unsigned int keep_mask, unsigned int new_bits,
                 unsigned int param_5, unsigned int param_6)

{
  int old_value;

  phy = phy & 0xff;
  old_value = hdmi_phy_read_reg(phy, reg);
  hdmi_phy_write_reg(phy, reg, old_value & keep_mask | new_bits, new_bits, param_5, param_6);
  return;
}
