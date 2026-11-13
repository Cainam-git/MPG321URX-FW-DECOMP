/* hdmi_scdc_bit_ratio_40  (FUN_a007af6c)
 *
 * Return the source's SCDC TMDS bit-clock-ratio bit (1/40 mode) of a port.
 *   phy
 * Returns: 1 when set
 * Name basis: derived - bit 1 of register 0x2E1 (SCDC TMDS_Config) on an HDMI 2.0 PHY, bit 9 of block-3 word
 *   +0x60 on an HDMI 2.1 PHY; callers hdmi_eq_check_clock_detect and DRV_HDMI_EQScan_FSM_PHY_Init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007af6c @ 0xa007af6c-0xa007afdc, flags -mcpu=v8 -Os -g.
 * Source form: early returns, each test as 'if (...) return 1; return 0;' (as hdmi_eq_get_clock_ratio_mode); the record index is
 * a separate local 'row = phy != 2' inside the != 0 arm (as hdmi_scdc_scrambling_enabled).
 */
/* One row of hdmi_rx21_reg_blocks: the register block addresses of an HDMI 2.1 receiver (0x34 bytes, 13 words). */
struct hdmi_rx21_reg_blocks { unsigned char pad[0xc]; unsigned int block3; unsigned char pad2[0x34 - 0x10]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned int reg_test_bit(unsigned int, unsigned int);

/*
 * Read bit 1 of register 0x2E1 of an HDMI 2.0 receiver; on an HDMI 2.1 PHY read bit 9 of the word at offset
 * 0x60 of register block 3 of that receiver (row 0 for PHY 2, row 1 for PHY 3).
 * Used by hdmi_eq_check_clock_detect and DRV_HDMI_EQScan_FSM_PHY_Init; hdmi_eq_get_clock_ratio_mode reads the same bit.
 *   phy: PHY index.  Returns 1 when the bit is set, else 0.
 */
unsigned int hdmi_scdc_bit_ratio_40(unsigned char phy)
{
    if (hdmi_is_hdmi21_phy(phy) != 0)
    {
        unsigned int row = phy != 2;
        if (reg_test_bit(0x9, ARR_a807db00[row].block3 + 0x60))
            return 1;
        return 0;
    }
    if (hdmi_reg_read8(phy, 0x2e1) & 2)
        return 1;
    return 0;
}
