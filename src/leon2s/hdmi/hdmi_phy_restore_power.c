/* hdmi_phy_restore_power  (FUN_a0073be8)
 *
 * Re-run the PHY power-on sequence when bit 14 of PHY register 0x1F0C reads 0.
 * Note: Bit 14 is set by the power-on sequence of hdmi_phy_set_power and cleared by its power-off sequence.
 * Name basis: descriptive - hdmi_phy_set_power(p, 1) when bit 14 of PHY register 0x1F0C is 0; caller
 *   DRV_HDMI_EQDetect_Timer
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073be8 @ 0xa0073be8, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the routine is declared void but returns a value on both paths (CONCAT44(1, phy) on the "still on"
 *    path, the call of hdmi_phy_set_power on the other);
 *  - hdmi_phy_test_bit is declared without a prototype;
 *  - the unused local "unused" and its store are kept.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

#define PHY_REG_1F0C      0x1f0c
#define REG_1F0C_POWER_ON 14        /* set by the power-on sequence of hdmi_phy_set_power, cleared by its power-off */
#define POWER_ON          1         /* "on" argument of hdmi_phy_set_power */

extern void hdmi_phy_set_power(unsigned char port, unsigned char on, unsigned int arg_3, unsigned int arg_4,
                               unsigned int arg_5, unsigned int arg_6);
extern int hdmi_phy_test_bit();

/*
 * Switch an HDMI PHY on again when it has lost its power-on state.
 *
 *   port           the PHY (0..3; 2 and 3 are the HDMI 2.1 receivers 0 and 1)
 *   arg_2          not used
 *   arg_3..arg_6   passed on unchanged to hdmi_phy_set_power
 *
 * The test is bit 14 of PHY register 0x1F0C, which the power-on sequence of hdmi_phy_set_power sets and its
 * power-off sequence clears. Bit set: nothing to do. Bit clear: the whole power-on sequence runs again.
 * The only caller, the periodic equaliser check DRV_HDMI_EQDetect_Timer, calls it with the port alone for every
 * PHY whose power byte is not 0; the other arguments are whatever the registers hold then.
 */
void hdmi_phy_restore_power(unsigned char port, unsigned int arg_2, unsigned int arg_3, unsigned int arg_4,
                            unsigned int arg_5, unsigned int arg_6)
{
  int power_on;
  unsigned int unused;
  unsigned int phy;

  phy = (unsigned int)port;
  power_on = hdmi_phy_test_bit(REG_1F0C_POWER_ON, phy, PHY_REG_1F0C);
  if (power_on != 0) {
    return CONCAT44(1, phy);
  }
  unused = 1;
  return hdmi_phy_set_power(port, POWER_ON, arg_3, arg_4, arg_5, arg_6);
}
