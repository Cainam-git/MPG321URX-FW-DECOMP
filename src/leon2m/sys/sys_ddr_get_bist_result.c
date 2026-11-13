/* sys_ddr_get_bist_result  (FUN_a00e40f4)
 *
 * Check the self-test status registers and return the result 0..3.
 * Returns: 0..3
 * Name basis: proven - prints 'Error: unknown bit_mode %d'
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default). Source form: the 'return 1' after the zero test of the 0x395 value is a
 * goto to the error path's return, so the routine has one shared exit block for the result 1.
 */
extern int sys_ddr_check_phy_reg(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read(int phy, unsigned int addr);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);

/*
 * Read the result of a self-test run on memory interface phy. Returns 0, 1, 2 or 3; the callers
 * (sys_ddr_run_bist_read and _write) treat 1 and 3 as "run again" and anything else as the final result.
 *
 * bit_mode (0, 1 or 2) picks which status bit counts as a failure. Any other value prints "Error: unknown
 * bit_mode %d" and returns 1.
 *
 * Order: poll register 0x43 for bit 0x40 (sys_ddr_check_phy_reg, up to ten rounds).
 *  - Bit 0x40 never comes up: temporarily set the low three bits of register 0x3e to 1, read register 0x395,
 *    put the three bits back. Return 1 when bits 0xe0 of register 0x43 are set and differ from 0x80. Otherwise
 *    return 3 when the 0x395 value was 0, else 1.
 *  - Bit 0x40 came up: test one failure bit chosen by bit_mode (0: register 0x43 bit 0x80; 1: register 0x41
 *    bit 0x80; 2: register 0x41 bit 0x40) and return 1 when it is set. Otherwise return 2 when bit 0x20 of
 *    register 0x43 is set, else 0.
 */
int sys_ddr_get_bist_result(int phy, int bit_mode)
{
    unsigned int saved_field, reg_395;

    if (sys_ddr_check_phy_reg(phy, 0x43, 0x40, 0x40) == 0) {
        saved_field = sys_ddr_phy_read_masked(phy, 0x3e, 7);
        sys_ddr_phy_update_bits(phy, 0x3e, 7, 1);
        reg_395 = sys_ddr_phy_read(phy, 0x395);
        sys_ddr_phy_update_bits(phy, 0x3e, 7, saved_field);
        if (sys_ddr_phy_read_masked(phy, 0x43, 0xe0) != 0 && sys_ddr_phy_read_masked(phy, 0x43, 0xe0) != 0x80)
            return 1;
        if (reg_395 == 0)
            return 3;
        goto fail;
    }
    switch (bit_mode) {
    case 0:
        if (sys_ddr_phy_read_masked(phy, 0x43, 0x80) != 0)
            return 1;
        break;
    case 1:
        if (sys_ddr_phy_read_masked(phy, 0x41, 0x80) != 0)
            return 1;
        break;
    case 2:
        if (sys_ddr_phy_read_masked(phy, 0x41, 0x40) != 0)
            return 1;
        break;
    default:
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: unknown bit_mode %d\n", bit_mode);
    fail:
        return 1;
    }
    return (sys_ddr_phy_read_masked(phy, 0x43, 0x20) != 0) * 2;
}
