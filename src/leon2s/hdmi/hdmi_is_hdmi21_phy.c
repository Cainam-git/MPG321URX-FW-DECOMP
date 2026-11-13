/* hdmi_is_hdmi21_phy  (FUN_a0073520)
 *
 * Return whether a PHY index belongs to an HDMI 2.1 receiver (2 or 3).
 *   phy
 * Returns: 1 for PHY 2 or 3
 * Name basis: derived - PHYs 2/3 get the 'H21 Trim' and extra HDMI 2.1 register writes in
 *   DRV_HDMI_InitialSettings and TMDS_PowerOff
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073520 @ 0xa0073520, flags -mcpu=v8 -Os -g.
 * The test is on the unsigned byte of v - 2 (the firmware masks with 'and 0xff' after the add);
 * parameter and result are unsigned char.
 */
/* Returns 1 when the PHY index is 2 or 3, otherwise 0.
 *   phy: PHY index */
unsigned char hdmi_is_hdmi21_phy(unsigned char phy)
{
    if ((unsigned char)(phy - 2) <= 1)
        return 1;
    return 0;
}
