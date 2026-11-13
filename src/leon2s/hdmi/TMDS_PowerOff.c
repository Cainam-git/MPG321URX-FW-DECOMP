/* TMDS_PowerOff  (TMDS_PowerOff)
 *
 * Power off the receiver PHY of an HDMI port.
 *   p1: PHY
 *   p2: power-off mode
 * Note: Mode 1 then sets bits 2, 7, 16, 17 of PHY register 0x1C04, bit 24 of 0x1F40 and low byte 0xF9 of
 *   0x1000, other modes clear bit 7 of 0x1C04 and bit 0 of 0x1000; PHYs 2 and 3 get bit 7 of 0x2C04 the same
 *   way.
 * Name basis: proven - original name printed: 'TMDS_PowerOff %d'
 *
 * Matching notes
 * --------------
 * leon2s TMDS_PowerOff @ 0xa0074cf8, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the callees are declared without parameter lists, and the last call of each path also passes pass_5 and
 *    pass_6 (the firmware leaves them in their registers);
 *  - the PHY test is '(unsigned char)(phy - 2U) < 2'.
 */
extern int dbg_printf();
extern void hdmi_phy_set_power();
extern void hdmi_phy_set_power_flag();
extern void hdmi_phy_write_bit();
extern void hdmi_phy_update_reg();

#define PHY_OFF                 0       /* "on" argument of hdmi_phy_set_power / _set_power_flag */
#define POWER_OFF_MODE_1        1       /* passed by input_power_off_receivers_mode1; input_power_off_receivers_mode0,
                                           hdmi_tmds_run_link_state and hdmi_rx21_run_link_state pass 0 */
#define BIT_SET                 1       /* first argument of hdmi_phy_write_bit */
#define BIT_CLEAR               0

/* PHY registers (paged per PHY by hdmi_phy_write_bit / hdmi_phy_update_reg). */
#define PHY_REG_1000            0x1000
#define PHY_REG_1C04            0x1c04
#define PHY_REG_1F40            0x1f40
#define PHY_REG_2C04            0x2c04  /* written only on PHYs 2 and 3, the HDMI 2.1 receivers */
#define REG_1000_KEEP_HIGH      0xffffff00
#define REG_1000_LOW_BYTE       0xf9    /* the value TMDS_PowerOn writes */
#define REG_1000_KEEP_ALL_BUT_0 0xfffffffe

/*
 * Switch off the receiving PHY of an HDMI input.
 *
 *   phy            the PHY (0..3; 2 and 3 are the HDMI 2.1 receivers)
 *   mode           POWER_OFF_MODE_1 or 0, see below
 *   pass_3..pass_6 not used; pass_5 and pass_6 are only handed on to the last call
 *
 * Records the PHY as off (hdmi_phy_set_power_flag) and runs the power-off sequence (hdmi_phy_set_power).
 * Then, by mode:
 *   mode 1: set to the values of the power-on side: bit 7 of 0x1C04 (and of 0x2C04 on PHYs 2 and 3) and 0xF9
 *           in the low byte of 0x1000 as TMDS_PowerOn writes them; bits 2, 16 and 17 of 0x1C04 and bit 24 of
 *           0x1F40 as the power-on sequence of hdmi_phy_set_power sets them;
 *   mode 0: bit 7 of 0x1C04 (and of 0x2C04 on PHYs 2 and 3) and bit 0 of 0x1000 cleared.
 */
void TMDS_PowerOff(unsigned char phy, unsigned char mode, unsigned int pass_3, unsigned int pass_4,
                   unsigned int pass_5, unsigned int pass_6)
{
  hdmi_phy_set_power_flag(phy, PHY_OFF);
  dbg_printf("TMDS_PowerOff  %d  \015\012", phy);
  hdmi_phy_set_power(phy, PHY_OFF);
  if (mode == POWER_OFF_MODE_1) {
    hdmi_phy_write_bit(BIT_SET, 7, phy, PHY_REG_1C04);
    if ((unsigned char)(phy - 2U) < 2) {
      hdmi_phy_write_bit(BIT_SET, 7, phy, PHY_REG_2C04);
    }
    hdmi_phy_update_reg(phy, PHY_REG_1000, REG_1000_KEEP_HIGH, REG_1000_LOW_BYTE);
    hdmi_phy_write_bit(BIT_SET, 2, phy, PHY_REG_1C04);
    hdmi_phy_write_bit(BIT_SET, 0x10, phy, PHY_REG_1C04);
    hdmi_phy_write_bit(BIT_SET, 0x11, phy, PHY_REG_1C04);
    hdmi_phy_write_bit(BIT_SET, 0x18, phy, PHY_REG_1F40, pass_5, pass_6);
    return;
  }
  hdmi_phy_write_bit(BIT_CLEAR, 7, phy, PHY_REG_1C04);
  if ((unsigned char)(phy - 2U) < 2) {
    hdmi_phy_write_bit(BIT_CLEAR, 7, phy, PHY_REG_2C04);
  }
  hdmi_phy_update_reg(phy, PHY_REG_1000, REG_1000_KEEP_ALL_BUT_0, 0, pass_5, pass_6);
  return;
}
