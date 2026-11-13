/* hdmi_phy_read_clock_count  (FUN_a0074f60)
 *
 * Measure the incoming clock of a PHY and return the 13-bit count.
 *   phy
 * Returns: clock count
 * Name basis: derived - starts the counter in 0x1F00, waits, reads 0x1F04; compared by the EQ clock check
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0074f60 @ 0xa0074f60, flags -mcpu=v8 -Os -g.
 * Source form: the PHY byte is masked once into a local and kept across the calls.
 */
extern void hdmi_phy_update_reg(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern void timer_delay_units(unsigned int param_1);
extern unsigned int hdmi_phy_read_reg(unsigned int param_1, unsigned int param_2);

/* Sets field bits 16..19 of PHY register 0x1f00 to 4 and its top byte to 1, waits (delay value 5),
 * and returns bits 8..20 of register 0x1f04. hdmi_phy_clock_changed compares the result with the
 * clock value saved in the PHY record.
 *   phy: PHY page */
unsigned int hdmi_phy_read_clock_count(unsigned char phy)
{
  unsigned char local = phy & 0xff;
  hdmi_phy_update_reg(local, 0x1f00, 0xfff0ffff, 0x40000);
  hdmi_phy_update_reg(local, 0x1f00, 0xffffff, 0x1000000);
  timer_delay_units(5);
  return (hdmi_phy_read_reg(local, 0x1f04) >> 8) & 0x1fff;
}
