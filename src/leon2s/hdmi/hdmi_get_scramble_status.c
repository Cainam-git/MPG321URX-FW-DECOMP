/* hdmi_get_scramble_status  (FUN_a007ae94)
 *
 * Return a scrambler status bit of a port.
 *   phy
 * Returns: 1 when set
 * Name basis: descriptive - HDMI 2.1 record bit 0x12 or bit 2 of receiver register 0x2F6; caller
 *   hdmi_eq_get_clock_ratio_mode
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007ae94 @ 0xa007ae94-0xa007af04, flags -mcpu=v8 -Os -g.
 * Source form: early returns, each test as 'if (...) return 1; return 0;' (as hdmi_eq_get_clock_ratio_mode); the record index is
 * a separate local 'i = p != 2' inside the != 0 arm (as hdmi_scdc_scrambling_enabled).
 */
/* One row of hdmi_rx21_reg_blocks: the register block addresses of an HDMI 2.1 receiver (0x34 bytes, 13 words). */
struct hdmi_rx21_reg_blocks { unsigned char pad[0xc]; unsigned int block3; unsigned char pad2[0x34 - 0x10]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned int reg_test_bit(unsigned int, unsigned int);

/*
 * Read bit 2 of register 0x2F6 of an HDMI 2.0 receiver; on an HDMI 2.1 PHY read bit 18 of the word at offset
 * 0x74 of register block 3 of that receiver (row 0 for PHY 2, row 1 for PHY 3).
 * It is the bit that hdmi_set_descramble_mode writes from its second value.
 *   phy: PHY index.  Returns 1 when the bit is set, else 0.
 * Used by hdmi_eq_get_clock_ratio_mode.
 */
unsigned int hdmi_get_scramble_status(unsigned char phy)
{
    if (hdmi_is_hdmi21_phy(phy) != 0)
    {
        unsigned int row = phy != 2;
        if (reg_test_bit(0x12, ARR_a807db00[row].block3 + 0x74))
            return 1;
        return 0;
    }
    if (hdmi_reg_read8(phy, 0x2f6) & 4)
        return 1;
    return 0;
}
