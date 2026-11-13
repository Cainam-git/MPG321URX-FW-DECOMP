/* hdmi_rx21_config_bch  (FUN_a007f634)
 *
 * Configure BCH error correction for an HDMI 2.1 PHY.
 *   phy
 * Name basis: derived - DRV_HDMI_Config_BCH(port != 2, 1) for PHYs 2/3; caller DRV_HDMI_EQScan_FSM_Done
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007f634 @ 0xa007f634, flags -mcpu=v8 -Os -g.
 * The range includes the ret/restore at 0xa007f668 that the zero branch reaches; GCC computes phy ^ 2 before
 * the test (the value of the 'phy != 2' argument). The call is a tail call.
 */
extern int DRV_HDMI_Config_BCH();
extern int hdmi_is_hdmi21_phy();

/*
 * On an HDMI 2.1 PHY, call DRV_HDMI_Config_BCH(receiver, 1) with receiver 0 for PHY 2 and 1 for PHY 3. Nothing
 * happens on the other PHYs.
 *   phy: PHY index. Called by DRV_HDMI_EQScan_FSM_Done.
 */
void hdmi_rx21_config_bch(unsigned int phy)
{
    unsigned int port;
    unsigned int is_hdmi21;

    port = phy & 0xff;
    is_hdmi21 = hdmi_is_hdmi21_phy(port);
    if ((is_hdmi21 & 0xff) == 0) {
        return;
    }
    DRV_HDMI_Config_BCH((port ^ 2) != 0, 1);
}
