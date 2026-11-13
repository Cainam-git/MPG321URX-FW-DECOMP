/* DRV_HDMI21_PHY_INV_PICDR_Reset  (DRV_HDMI21_PHY_INV_PICDR_Reset)
 *
 * Reset the clock-recovery (PI-CDR) blocks of the HDMI 2.1 lanes.
 *   port: PHY
 * Name basis: proven - original name printed: 'DRV_HDMI21_PHY_INV_PICDR_Reset'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_PHY_INV_PICDR_Reset @ 0xa007aca0, flags -mcpu=v8 -Os -g.
 * Source form: the callees are declared without parameter lists (the firmware passes the arguments
 * unconverted), and the print format is the data object DAT_a00678c8.
 */
#define HDMI_MSG_HDMI21 0x800   /* debug message bit: '[HDMI21]' lines (dbg_hdmi_message_flags) */

extern unsigned int DAT_a00678c8;
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf();
extern void hdmi_phy_update_reg();
extern int timer_delay_long_units();

/* Sets bits 16..23 (value 2) of the registers 0x2028/0x2428/0x2828/0x3028 and 0x2008/0x2408/0x2808/0x3008
 * (offsets 0x28 and 0x08 in each of the four lane areas), waits, then clears the same bit fields,
 * the 0x..08 registers first. Called by DRV_HDMI21_PHY_PICDR_Reset
 * when the PHY's link-rate byte is 3 or less.
 *   port: PHY page of the HDMI 2.1 receiver */
void DRV_HDMI21_PHY_INV_PICDR_Reset(unsigned char port)

{
  
  if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0) {
    dbg_printf(&DAT_a00678c8,"DRV_HDMI21_PHY_INV_PICDR_Reset");
  }
  hdmi_phy_update_reg(port,0x2028,0xff00ffff,0x20000);
  hdmi_phy_update_reg(port,0x2428,0xff00ffff,0x20000);
  hdmi_phy_update_reg(port,0x2828,0xff00ffff,0x20000);
  hdmi_phy_update_reg(port,0x3028,0xff00ffff,0x20000);
  hdmi_phy_update_reg(port,0x2008,0xff00ffff,0x20000);
  hdmi_phy_update_reg(port,0x2408,0xff00ffff,0x20000);
  hdmi_phy_update_reg(port,0x2808,0xff00ffff,0x20000);
  hdmi_phy_update_reg(port,0x3008,0xff00ffff,0x20000);
  timer_delay_long_units(1);
  hdmi_phy_update_reg(port,0x2008,0xff00ffff,0);
  hdmi_phy_update_reg(port,0x2408,0xff00ffff,0);
  hdmi_phy_update_reg(port,0x2808,0xff00ffff,0);
  hdmi_phy_update_reg(port,0x3008,0xff00ffff,0);
  hdmi_phy_update_reg(port,0x2028,0xff00ffff,0);
  hdmi_phy_update_reg(port,0x2428,0xff00ffff,0);
  hdmi_phy_update_reg(port,0x2828,0xff00ffff,0);
  hdmi_phy_update_reg(port,0x3028,0xff00ffff,0);
  return;
}