/* dp_tx_phy_write_dptx_option  (FUN_a00aa2d0)
 *
 * Write register 0x37 of the DPTX PHY unit from a stored option byte.
 * Name basis: descriptive - 0xA0 or 0x10 by byte 0xA807D3B9 == 0xA0; caller dp_tx_init_ctl_banks
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */

extern unsigned char dp_tx_phy_dptx_option;
extern void dp_tx_phy_reg_write8(unsigned int unit, unsigned short reg, unsigned int value);

#define DPTX_OPTION_SET 0xa0        /* value of dp_tx_phy_dptx_option that selects the stored setting */

/*
 * Write register 0x37 of PHY unit 0 (DPTX): 0xA0 when the stored option byte dp_tx_phy_dptx_option is 0xA0,
 * otherwise 0x10. Called by dp_tx_init_ctl_banks for output 0.
 */
void dp_tx_phy_write_dptx_option(void)
{
    if (dp_tx_phy_dptx_option == DPTX_OPTION_SET) {
        dp_tx_phy_reg_write8(0, 0x37, 0xa0);
    } else {
        dp_tx_phy_reg_write8(0, 0x37, 0x10);
    }
}
