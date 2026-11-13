/* hdmi_eq_get_scramble_mode  (FUN_a007d054)
 *
 * Return the scrambling mode the EQ steps should use for a port.
 *   phy
 * Name basis: descriptive - same form as hdmi_eq_get_clock_ratio_mode with the scrambling tests; callers PLL,
 *   PHY init and Done steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007d054 @ 0xa007d054-0xa007d140, flags -mcpu=v8 -Os -g.
 * Source form: early returns with an unsigned int result; hdmi_get_scramble_lock declared returning unsigned char
 * (the firmware masks its result); the register-block index is a separate local 'row = phy != 2' as in
 * hdmi_scdc_scrambling_enabled.
 */
/* The 0x18-byte record of a PHY (hdmi_phy_records): only the option byte at +7 is used here. */
struct hdmi_phy_record {
    unsigned char bytes_0_to_6[7];
    unsigned char option;               /* +7: stored by mailbox command 0x15 */
    unsigned char rest[0x18 - 8];
};
/* One row of hdmi_rx21_reg_blocks: the register block addresses of an HDMI 2.1 receiver (0x34 bytes, 13 words). */
struct hdmi_rx21_reg_blocks { unsigned char pad[0xc]; unsigned int block3; unsigned char pad2[0x34 - 0x10]; };
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_eq_mode_override_flags[];
extern unsigned char hdmi_eq_tmds_bit_ratio_guess[];
extern unsigned char hdmi_get_port_mode_byte(unsigned int);
extern unsigned char hdmi_get_scramble_lock(unsigned char);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned int reg_test_bit(unsigned int, unsigned int);

/*
 * Return the scrambling value the EQ steps use for a PHY. Same order as hdmi_eq_get_clock_ratio_mode:
 *   - 0 when the PHY record's option byte is 1;
 *   - when the PHY's only-scramble guess mode byte (hdmi_get_port_mode_byte) is set: 1 for PHY 2, else
 *     hdmi_get_scramble_lock;
 *   - when hdmi_eq_mode_override_flags[phy] is 1: the stored hdmi_eq_tmds_bit_ratio_guess[phy];
 *   - otherwise the live bit that hdmi_scdc_scrambling_enabled reads, written out in place (HDMI 2.1 block bit,
 *     or bit 0 of receiver register 0x2E1).
 * phy: PHY index. Called by hdmi_eq_check_error_regs, DRV_HDMI_EQScan_FSM_PHY_PLL, DRV_HDMI_EQScan_FSM_Done
 * and DRV_HDMI_EQScan_FSM_PHY_Init.
 */
unsigned int hdmi_eq_get_scramble_mode(unsigned char phy)
{
    if (hdmi_phy_records[phy].option == 1)
        return 0;
    if (hdmi_get_port_mode_byte(phy)) {
        if (phy == 2)
            return 1;
        return hdmi_get_scramble_lock(phy);
    }
    if (hdmi_eq_mode_override_flags[phy] == 1)
        return hdmi_eq_tmds_bit_ratio_guess[phy];
    if (hdmi_is_hdmi21_phy(phy) != 0) {
        unsigned int row = phy != 2;
        return reg_test_bit(8, ARR_a807db00[row].block3 + 0x60) != 0;
    }
    return hdmi_reg_read8(phy, 0x2e1) & 1;
}
