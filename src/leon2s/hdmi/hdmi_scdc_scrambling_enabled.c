/* hdmi_scdc_scrambling_enabled  (FUN_a007af04)
 *
 * Return the source's SCDC scrambling-enable bit of a port.
 *   phy
 * Returns: 1 when enabled
 * Name basis: derived - bit 0 of register 0x2E1 (SCDC TMDS_Config); caller DRV_HDMI_EQScan_FSM_PHY_Init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007af04 @ 0xa007af04-0xa007af6c, flags -mcpu=v8 -Os -g.
 * Source form: the record index is a separate local 'row = phy != 2' (firmware: xor, addx, smul 0x34; an inline
 * index lets gcc rewrite it as 0x34 - (phy == 2) * 0x34).
 */
/* One row of hdmi_rx21_reg_blocks: the register block addresses of an HDMI 2.1 receiver (0x34 bytes, 13 words). */
struct hdmi_rx21_reg_blocks { unsigned char pad[0xc]; unsigned int block3; unsigned char pad2[0x34 - 0x10]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned int reg_test_bit(unsigned int, unsigned int);

/*
 * Read bit 0 of register 0x2E1 of an HDMI 2.0 receiver; on an HDMI 2.1 PHY read bit 8 of the word at offset
 * 0x60 of register block 3 of that receiver (row 0 for PHY 2, row 1 for PHY 3).
 * Used by DRV_HDMI_EQScan_FSM_PHY_Init; hdmi_eq_get_scramble_mode reads the same bit.
 *   phy: PHY index.  Returns 1 when the bit is set, else 0.
 */
unsigned int hdmi_scdc_scrambling_enabled(unsigned char phy)
{
    if (hdmi_is_hdmi21_phy(phy) != 0)
    {
        unsigned int row = phy != 2;
        return reg_test_bit(8, ARR_a807db00[row].block3 + 0x60) != 0;
    }
    return hdmi_reg_read8(phy, 0x2e1) & 1;
}
