/* hdmi_clear_descramble_override  (FUN_a007ebd0)
 *
 * Clear bit 0 of receiver register 0x136; on an HDMI 2.1 PHY set bit 16 of block-1 word +0x34 instead.
 *   phy
 * Note: The two arms act in opposite directions; what the HDMI 2.1 bit does is not shown.
 * Name basis: descriptive - bit 0 of receiver register 0x136 cleared (HDMI 2.0 PHYs) or bit 16 of register
 *   block 1 word +0x34 set (HDMI 2.1); caller DRV_HDMI_EQScan_FSM_PHY_Init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007ebd0 @ 0xa007ebd0, flags -mcpu=v8 -Os -g.
 * Source form: hdmi_rx21_reg_blocks is declared as a word array; the row is index * 13 words.
 */
extern unsigned int hdmi_is_hdmi21_phy(unsigned int phy);
extern void hdmi_reg_update_bits(unsigned int port, unsigned int reg, unsigned int mask, unsigned int mode);
extern void reg_set_bit(unsigned int bit, unsigned int words);
extern unsigned int hdmi_rx21_reg_blocks[];

/*
 * On an HDMI 2.1 PHY: set bit 16 of the word at offset 0x34 of register block 1 of its receiver (row 0 for
 * PHY 2, row 1 for PHY 3; hdmi_rx21_reg_blocks has 13 words per row, block 1 is word 1). On an HDMI 2.0 PHY: clear
 * bit 0 of register 0x136 of its receiver.
 *   phy: PHY index. Called by DRV_HDMI_EQScan_FSM_PHY_Init.
 */
void hdmi_clear_descramble_override(unsigned int phy)
{
    unsigned int port;
    unsigned int is_hdmi21;
    unsigned int row;

    port = phy & 0xff;
    is_hdmi21 = hdmi_is_hdmi21_phy(port);

    if (is_hdmi21 & 0xff) {
        row = (port != 2) ? 1 : 0;
        reg_set_bit(0x10, hdmi_rx21_reg_blocks[row * 13 + 1] + 0x34);
        return;
    }

    hdmi_reg_update_bits(port, 0x136, 1, 0);
}
