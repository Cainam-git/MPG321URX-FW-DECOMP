/* hdmi_eq_check_error_regs  (FUN_a007d140)
 *
 * Read the channel error registers up to three times and report a bad value.
 *   port: PHY
 * Returns: 0 on a bad value
 * Name basis: descriptive - three readings of the error registers, all must be good, debug print on failure;
 *   callers Check_MEQ_Done and PHY_ChkError
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007d140 @ 0xa007d140-0xa007d21c, flags -mcpu=v8 -Os -g.
 * Source form: hdmi_eq_get_scramble_mode is declared returning unsigned char (the firmware tests only its low
 * byte).
 */
extern unsigned char hdmi_eq_get_scramble_mode(unsigned char port);
extern unsigned int hdmi_phy_read_reg(unsigned int param_1, unsigned short param_2);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);

/*
 * Check three times that the PHY's error registers 0x1E98 and 0x1E9C hold the expected values.
 * Nothing is read when hdmi_eq_get_scramble_mode is 0 (result 1). A reading is bad when byte 3 of 0x1E98 is not
 * 0x18, when the low nibble of byte 0 of 0x1E9C is above 1, or when bits 4..7 of byte 0 or of byte 1 of 0x1E9C
 * are above 1. A bad reading prints the three values and
 * "Need Retrain" on the debug console and ends the check with 0.
 *   port: PHY index.  Returns 1 when all three readings are good, 0 on the first bad one.
 * Called by DRV_HDMI_EQScan_FSM_PHY_ChkError and DRV_HDMI_EQScan_FSM_Check_MEQ_Done.
 */
unsigned char hdmi_eq_check_error_regs(unsigned char port)
{
    unsigned char i;
    unsigned char reg_1e98_byte3;
    unsigned char reg_1e9c_byte0;
    unsigned char reg_1e9c_byte1;

    if (hdmi_eq_get_scramble_mode(port)) {
        for (i = 0; i < 3; i++) {
            reg_1e98_byte3 = hdmi_phy_read_reg(port, 0x1e98) >> 24;
            reg_1e9c_byte0 = hdmi_phy_read_reg(port, 0x1e9c);
            reg_1e9c_byte1 = hdmi_phy_read_reg(port, 0x1e9c) >> 8;
            if (reg_1e98_byte3 != 0x18 || (reg_1e9c_byte0 & 0xf) > 1 || (reg_1e9c_byte0 & 0xf0) > 0x1f || (reg_1e9c_byte1 & 0xf0) > 0x1f) {
                dbg_printf("Port%c 0x1E98=0x%02X, 0x1E9C=0x%02X, 0x1E9D=0x%02X\n", (char)(port + 'A'), reg_1e98_byte3, reg_1e9c_byte0, reg_1e9c_byte1);
                dbg_print_string("\033[31;1mNeed Retrain\n");
                return 0;
            }
        }
    }
    return 1;
}
