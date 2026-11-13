/* dp_tx_phy_write_edp_options  (FUN_a00aa308)
 *
 * Write registers 0x3D/0x60/0x83/0xA6 of the eDP PHY unit from stored option bytes.
 * Name basis: descriptive - bytes 3..6 of 0xA807D3D1 when its byte 0 is 0xA0, else 0x10; caller
 *   dp_tx_init_ctl_banks
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. The last register write is a tail call.
 */
extern unsigned char dp_tx_phy_edp_options[];
extern void dp_tx_phy_reg_write8(unsigned int, unsigned short, unsigned int);

#define EDP_OPTIONS_SET 0xa0        /* value of byte 0 that selects the stored bytes */

/*
 * Write registers 0x3D, 0x60, 0x83 and 0xA6 of PHY unit 1 (the unit of the eDP outputs). When byte 0 of
 * dp_tx_phy_edp_options is 0xA0 the values are its bytes 3, 4, 5 and 6; otherwise each register gets 0x10.
 * Called by dp_tx_init_ctl_banks.
 */
void dp_tx_phy_write_edp_options(void)
{
    if (dp_tx_phy_edp_options[0] == EDP_OPTIONS_SET) {
        dp_tx_phy_reg_write8(1, 0x3d, dp_tx_phy_edp_options[3]);
        dp_tx_phy_reg_write8(1, 0x60, dp_tx_phy_edp_options[4]);
        dp_tx_phy_reg_write8(1, 0x83, dp_tx_phy_edp_options[5]);
        dp_tx_phy_reg_write8(1, 0xa6, dp_tx_phy_edp_options[6]);
    } else {
        dp_tx_phy_reg_write8(1, 0x3d, 0x10);
        dp_tx_phy_reg_write8(1, 0x60, 0x10);
        dp_tx_phy_reg_write8(1, 0x83, 0x10);
        dp_tx_phy_reg_write8(1, 0xa6, 0x10);
    }
}
