/* dp_tx_phy_power_down_dptx_unit  (FUN_a00aa200)
 *
 * Clear the enable bits of the DPTX transmitter PHY unit.
 * Name basis: derived - ten dp_tx_phy_reg_update_bits(0, .., 0) clears; callers
 *   input_power_off_receivers_mode0/1
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. The routine ends at 0xa00aa2d0, where dp_tx_phy_write_dptx_option starts.
 */
extern void dp_tx_phy_reg_update_bits(unsigned int unit, short reg, unsigned int mask, unsigned int mode);

/*
 * Clear bits of ten registers of PHY unit 0 (DPTX), in the order written below; registers 0x4A and 0x44 are
 * cleared twice with different masks. Called by the two receiver power-off routines
 * (input_power_off_receivers_mode0 / mode1).
 */
void dp_tx_phy_power_down_dptx_unit(void)
{
    dp_tx_phy_reg_update_bits(0, 0x3e, 1, 0);
    dp_tx_phy_reg_update_bits(0, 0x4a, 0xf0, 0);
    dp_tx_phy_reg_update_bits(0, 0x44, 0xf0, 0);
    dp_tx_phy_reg_update_bits(0, 0x44, 0xf, 0);
    dp_tx_phy_reg_update_bits(0, 0x35, 1, 0);
    dp_tx_phy_reg_update_bits(0, 0x4a, 0xf0, 0);
    dp_tx_phy_reg_update_bits(0, 0x3c, 0x40, 0);
    dp_tx_phy_reg_update_bits(0, 0x34, 0x44, 0);
    dp_tx_phy_reg_update_bits(0, 0x33, 0x40, 0);
    dp_tx_phy_reg_update_bits(0, 0x30, 1, 0);
}
