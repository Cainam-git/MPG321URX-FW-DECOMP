/* hdmi_phy_set_input_enable  (FUN_a007ae30)
 *
 * Set or clear the input enable bit 7 of the PHY (and its HDMI 2.1 twin).
 *   phy
 *   on: 1 = on
 * Name basis: descriptive - bit 7 of 0x1C04 (and 0x2C04 for PHYs 2/3), the bits TMDS_PowerOn sets; caller
 *   ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007ae30 @ 0xa007ae30, flags -mcpu=v8 -Os -g.
 * Source form: the externs are implicit; the routine is declared void and ends in 'return enable;', as the
 * decompiler wrote it (the returned value is not used).
 */
/*
 * Set or clear bit 7 of PHY register 0x1C04; on the HDMI 2.1 PHYs (2 and 3) also of register 0x2C04.
 * This is what mailbox command 0x11 (ipc_enable_hdmi_phy_input) runs.
 *   phy: PHY index.  on: 1 = set the bit, any other value = clear it.
 * Called by DRV_HDMI_InitialSettings and ipc_dispatch_command.
 */
void hdmi_phy_set_input_enable(unsigned int phy, unsigned char on)
{
    unsigned int is_hdmi21;
    unsigned int set;
    unsigned int port;

    set = (on == 1);
    port = phy & 0xff;
    hdmi_phy_write_bit(set, 7, port, 0x1c04);
    is_hdmi21 = hdmi_is_hdmi21_phy(port);
    if ((is_hdmi21 & 0xff) != 0) {
        hdmi_phy_write_bit(set, 7, port, 0x2c04);
    }
    return set;
}
