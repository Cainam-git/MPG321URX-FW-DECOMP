/* hdmi_get_scramble_lock  (FUN_a007cfec)
 *
 * Return the scrambler lock status bit of a port.
 *   phy
 * Returns: 1 when set
 * Name basis: descriptive - HDMI 2.1 record bit 0x10 or bit 0 of receiver register 0x2F6 (twin of
 *   hdmi_get_scramble_status)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007cfec @ 0xa007cfec-0xa007d054, flags -mcpu=v8 -Os -g.
 * Source form: the != 0 arm first, and the index as a separate local inside that arm (the hdmi_scdc_scrambling_enabled
 * form: keeps xor/addx/smul 0x34).
 */
/* One row of hdmi_rx21_reg_blocks: the register block addresses of an HDMI 2.1 receiver (0x34 bytes, 13 words). */
struct hdmi_rx21_reg_blocks { unsigned char pad[0xc]; unsigned int block3; unsigned char pad2[0x34 - 0x10]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned int reg_test_bit(unsigned int, unsigned int);

/*
 * Read bit 0 of register 0x2F6 of an HDMI 2.0 receiver; on an HDMI 2.1 PHY read bit 16 of the word at offset
 * 0x74 of register block 3 of that receiver (row 0 for PHY 2, row 1 for PHY 3).
 * It is the bit that hdmi_set_descramble_mode writes from its first value.
 *   phy: PHY index.  Returns 1 when the bit is set, else 0.
 * Used by hdmi_eq_get_scramble_mode.
 */
unsigned int hdmi_get_scramble_lock(unsigned char phy)
{
    if (hdmi_is_hdmi21_phy(phy) != 0)
    {
        unsigned int row = phy != 2;
        return reg_test_bit(0x10, ARR_a807db00[row].block3 + 0x74) != 0;
    }
    return hdmi_reg_read8(phy, 0x2f6) & 1;
}
