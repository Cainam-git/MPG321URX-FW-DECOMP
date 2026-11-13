/* hdmi_phy_write_bit  (FUN_a00a7424)
 *
 * Set or clear one bit of a paged HDMI PHY register.
 *   mode: 1 = set, 0 = clear
 *   bit
 *   phy
 *   reg: register
 * Name basis: proven - hdmi_phy_map_reg then reg_set_bit (mode 1) or reg_clear_bit (mode 0)
 *
 * Matching notes
 * --------------
 * FUN_a00a7424 (leon2s 0xa00a7424), flags -mcpu=v8 -Os -g.
 * Both arms call hdmi_phy_map_reg, which returns a word (retl add %o4,%o0,%o0), and pass it as the second
 * argument of a tail call (restore %g0,%o0,%o1).
 */
extern unsigned int hdmi_phy_map_reg(unsigned int, unsigned short);
extern void reg_set_bit(unsigned int, unsigned int);
extern void reg_clear_bit(unsigned int, unsigned int);

/* Set (mode 1) or clear (any other mode) one bit of register reg of PHY phy: the page is selected with
   hdmi_phy_map_reg and the bit is changed in the word it returns. */
void hdmi_phy_write_bit(int mode, unsigned int bit, unsigned char phy, unsigned short reg)
{
  if (mode == 1)
    reg_set_bit(bit, hdmi_phy_map_reg(phy, reg));
  else
    reg_clear_bit(bit, hdmi_phy_map_reg(phy, reg));
}
