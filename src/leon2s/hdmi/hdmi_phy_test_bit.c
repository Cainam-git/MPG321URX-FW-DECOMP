/* hdmi_phy_test_bit  (FUN_a00a7468)
 *
 * Return one bit of a paged HDMI PHY register.
 *   bit
 *   phy
 *   reg: register
 * Returns: bit value
 * Name basis: proven - hdmi_phy_map_reg then reg_test_bit
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a7468 @ 0xa00a7468, flags -mcpu=v8 -Os -g.
 * A tail call; bit is passed through unchanged.
 */
extern unsigned int hdmi_phy_map_reg(unsigned int, unsigned int);
extern unsigned int reg_test_bit(unsigned int, int);

/* Return bit number bit of register reg of PHY phy: the page is selected with hdmi_phy_map_reg and the bit
   is tested in the word it returns. */
unsigned int hdmi_phy_test_bit(unsigned int bit, unsigned char phy, unsigned short reg)
{
    return reg_test_bit(bit, hdmi_phy_map_reg(phy, reg));
}
