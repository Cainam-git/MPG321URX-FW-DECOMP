/* hdmi_rx21_set_reg1f0c_bit18  (FUN_a00a1734)
 *
 * Set bit 18 of PHY register 0x1F0C.
 * Name basis: descriptive - caller hdmi_rx21_write_reg1f0c_bit18 (debug menu)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1734, flags -mcpu=v8 -Os -g (section default). The return statement is kept as the firmware has
 * it: the value returned is always 0 (the shift by 32 leaves nothing in the low word).
 */
extern int hdmi_phy_write_bit();

/*
 * Set bit 18 of register 0x1F0C of PHY 0 (hdmi_phy_write_bit with mode 1). Called by
 * hdmi_rx21_write_reg1f0c_bit18. The parameters are not used.
 */
unsigned int hdmi_rx21_set_reg1f0c_bit18(unsigned int unused1, unsigned int unused2)
{
  hdmi_phy_write_bit(1,0x12,0,0x1f0c);
  return (unsigned long long)unused2 << 0x20;
}
