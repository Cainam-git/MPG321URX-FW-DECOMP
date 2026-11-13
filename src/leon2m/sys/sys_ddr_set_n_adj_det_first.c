/* sys_ddr_set_n_adj_det_first  (FUN_a00e2588)
 *
 * Write the N_adj and N_det values (0..9) of the first calibration unit.
 * Name basis: proven - prints 'error: N_adj=%d, should be 0~9.' / 'error: N_det=%d, should be 0~9.'; called
 *   through sys_ddr_set_n_adj_det_hook, which sys_ddr_zq_calibrate_first fills
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2588 @ 0xa00e2588-0xa00e260c (33 words), flags -mcpu=v8 -O3 -g.
 * Source form: both limit tests print through sys_ddr_print_step and sys_ddr_print_error_prefix (no arguments)
 * and return; the two field writes are tail-style calls with five arguments each.
 */
extern int dbg_printf();
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Set the two 4-bit counts of the first calibration unit of memory interface phy: n_adj in bits 4..7 of
 * register 0x1c0 and n_det in bits 0..3 of register 0x1f0. Both must be 0..9; otherwise the routine prints the
 * current step, the "ddr_err: " prefix and an "error: N_adj=%d" or "error: N_det=%d" message, and changes
 * nothing. The setup of the first unit (sys_ddr_unit1_n_values_entry) hands it out as the N values hook.
 */
void sys_ddr_set_n_adj_det_first(unsigned int phy, unsigned int n_adj, unsigned int n_det)
{
    if (n_adj > 9) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("error: N_adj=%d, should be 0~9.", n_adj);
        return;
    }
    if (n_det > 9) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("error: N_det=%d, should be 0~9.", n_det);
        return;
    }
    sys_ddr_phy_write_field(phy, 0x1c0, 0xf0, 4, n_adj);
    sys_ddr_phy_write_field(phy, 0x1f0, 0x0f, 0, n_det);
}
