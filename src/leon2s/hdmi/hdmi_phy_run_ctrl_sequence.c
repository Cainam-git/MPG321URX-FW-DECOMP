/* hdmi_phy_run_ctrl_sequence  (FUN_a0073738)
 *
 * Run the timed bit sequence on PHY control register 0x361C.
 * Name basis: descriptive - seven bit writes, 50-unit delay, two field writes; callers hdmi_phy_set_power and
 *   DRV_HDMI_InitialSettings
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073738 @ 0xa0073738, flags -mcpu=v8 -Os -g.
 * Source form: the callees are declared without parameter lists.
 */
extern void hdmi_phy_write_bit();
extern int hdmi_phy_update_reg();
extern int timer_delay_long_units();

/* Writes PHY register 0x361c: clears bits 0 and 1, sets bits 4, 5, 7, 0 and 1, waits (delay value 0x32),
 * clears bit 7, then sets bits 8..9 to 3 (value 0x300) and bits 12..13 to 3 (value 0x3000).
 *   phy: PHY page */
void hdmi_phy_run_ctrl_sequence(unsigned char phy)

{
  
  hdmi_phy_write_bit(0,0,phy,0x361c);
  hdmi_phy_write_bit(0,1,phy,0x361c);
  hdmi_phy_write_bit(1,4,phy,0x361c);
  hdmi_phy_write_bit(1,5,phy,0x361c);
  hdmi_phy_write_bit(1,7,phy,0x361c);
  hdmi_phy_write_bit(1,0,phy,0x361c);
  hdmi_phy_write_bit(1,1,phy,0x361c);
  timer_delay_long_units(0x32);
  hdmi_phy_write_bit(0,7,phy,0x361c);
  hdmi_phy_update_reg(phy,0x361c,0xfffff8ff,0x300);
  hdmi_phy_update_reg(phy,0x361c,0xffff8fff,0x3000);
  return;
}