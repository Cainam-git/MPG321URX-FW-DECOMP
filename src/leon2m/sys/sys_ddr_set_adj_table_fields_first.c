/* sys_ddr_set_adj_table_fields_first  (FUN_a00e2714)
 *
 * Write three table fields of the first calibration unit at entry n_adj (0..9).
 * Name basis: derived - prints 'error: N_adj=%d, should be 0~9.'; called through sys_ddr_set_adj_fields_hook,
 *   which sys_ddr_zq_calibrate_first fills
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2714 @ 0xa00e2714-0xa00e285c (82 words), flags -mcpu=v8 -O3 -g.
 * Source form: each field write has its own 'if (n_adj == 0xffffffff) call(table addresses); else call(table
 * entries);'; the compiler merges the three tests into one. The
 * parameters named value1 .. value3 are the 4th to 6th.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_step(void);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_error_prefix(void);
extern unsigned int sys_ddr_unit1_value3_regs[10], sys_ddr_unit1_value3_masks[10], sys_ddr_unit1_value3_shifts[10];
extern unsigned int sys_ddr_unit1_value1_regs[10], sys_ddr_unit1_value1_masks[10], sys_ddr_unit1_value1_shifts[10];
extern unsigned int sys_ddr_unit1_value2_regs[10], sys_ddr_unit1_value2_masks[10], sys_ddr_unit1_value2_shifts[10];

/*
 * Write the three value fields of the first calibration unit of memory interface phy for the count n_adj (0..9).
 * Each field lies in the register, under the mask and at the shift that the unit's tables
 * (sys_ddr_unit1_value<k>_regs / _masks / _shifts) hold at entry n_adj; the field gets value1, value2 or
 * value3. The search sys_ddr_search_cal_setting passes its three trial values in this order (its a, c, b).
 * n_det is only range-checked (0..9). Both limits are checked first; out of range, the routine prints the
 * current step, the "ddr_err: " prefix and an "error: N_adj=%d" or "error: N_det=%d" message and writes
 * nothing. The branch for n_adj == 0xffffffff passes the table addresses themselves; the range check
 * excludes it. Reached through sys_ddr_unit1_adj_fields_entry, the field hook of the setting search.
 */
void sys_ddr_set_adj_table_fields_first(unsigned int phy, unsigned int n_adj, unsigned int n_det, unsigned int value1, unsigned int value2, unsigned int value3)
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
    if (n_adj == 0xffffffff)
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_unit1_value3_regs, (unsigned int)sys_ddr_unit1_value3_masks, (unsigned int)sys_ddr_unit1_value3_shifts, value3);
    else
        sys_ddr_phy_write_field(phy, sys_ddr_unit1_value3_regs[n_adj], sys_ddr_unit1_value3_masks[n_adj], sys_ddr_unit1_value3_shifts[n_adj], value3);
    if (n_adj == 0xffffffff)
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_unit1_value1_regs, (unsigned int)sys_ddr_unit1_value1_masks, (unsigned int)sys_ddr_unit1_value1_shifts, value1);
    else
        sys_ddr_phy_write_field(phy, sys_ddr_unit1_value1_regs[n_adj], sys_ddr_unit1_value1_masks[n_adj], sys_ddr_unit1_value1_shifts[n_adj], value1);
    if (n_adj == 0xffffffff)
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_unit1_value2_regs, (unsigned int)sys_ddr_unit1_value2_masks, (unsigned int)sys_ddr_unit1_value2_shifts, value2);
    else
        sys_ddr_phy_write_field(phy, sys_ddr_unit1_value2_regs[n_adj], sys_ddr_unit1_value2_masks[n_adj], sys_ddr_unit1_value2_shifts[n_adj], value2);
}
