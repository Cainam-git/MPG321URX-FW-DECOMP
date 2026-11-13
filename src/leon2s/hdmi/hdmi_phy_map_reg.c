/* hdmi_phy_map_reg  (FUN_a00a7368)
 *
 * Select the page of an HDMI PHY register and return its address.
 *   phy: PHY 0..3
 *   reg: register
 * Returns: register address
 * Name basis: proven - used by hdmi_phy_write_bit / hdmi_phy_test_bit
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a7368 @ 0xa00a7368, flags -mcpu=v8 -Os -g.
 * The result is declared int.
 */
/* Select the page of register reg of PHY 0..3 (write the high byte of reg to the page register at
   0xCF000000 | ((0xF401 + phy) << 2)) and return the address of its word: 0xCE008100 + (phy << 8) + low byte
   of reg. The page stays selected. Called by hdmi_phy_write_bit and hdmi_phy_test_bit. */
int hdmi_phy_map_reg(unsigned int phy, unsigned short reg)
{
    unsigned int phy_number = phy & 0xff;
    *(volatile unsigned int *)(0xcf000000 | ((0xf401 + phy_number) << 2)) = (reg >> 8) & 0xff;
    return (phy_number << 8) + ((unsigned char)reg) + 0xce008100;
}
