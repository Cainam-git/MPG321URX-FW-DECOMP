/* sys_ddr_search_cal_setting  (FUN_a00e2d8c)
 *
 * Step a calibration setting through its range; mode 0 picks the best one by its measured sums.
 * Note: A non-zero mode only sweeps and measures and leaves (1, 0x3f, 1) written; only the uncalled
 *   sys_ddr_calibrate_unit_* routines pass it.
 * Name basis: derived - works through four routine pointers set by sys_ddr_zq_calibrate_first / _second /
 *   _third
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2d8c @ 0xa00e2d8c-0xa00e312c (232 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - in the compare branch one 'value3 = 1' after the case chain: the firmware tails 'b 0xa00e2ddc; mov 1, %l3'
 *    (0xa00e2f74, 0xa00e2f88) are shared by both cases;
 *  - in the sweep branch the step from (0, 0, 0) to (1, 0, 1) is written 'value1 = 1; value3 = 1; value2 = 0;'
 *    (delay slot 'clr %l2' at 0xa00e2ee0);
 *  - saved_diff is set to 0 a second time at the start of the compare branch: the firmware keeps saved_diff in
 *    %i3, start_diff in %i4 and the high part of 0xA802D660 in %i5, an order the register allocator gives when
 *    saved_diff has two constant assignments before its first computed value (local-alloc.c doubles the live
 *    length for each one); with a single one saved_diff is allocated first and takes %i5. The firmware has one
 *    'clr %i3' (0xa00e2da4); the second assignment leaves no instruction.
 */

#define VALUE2_SWEEP_MAX  0x3f  /* sweep branch: last value2 */
#define VALUE2_STEP_LIMIT 0x13  /* compare branch: value2 above this ends the search */

extern unsigned int sys_ddr_cal_compare_mode;
extern unsigned int (*sys_ddr_run_cal_hook)(unsigned int);
extern void (*sys_ddr_set_n_adj_det_hook)(unsigned int, unsigned int, unsigned int);
extern unsigned int (*sys_ddr_wait_cal_idle_hook)(unsigned int);
extern void (*sys_ddr_set_adj_fields_hook)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

/* Write one trial setting into the calibration unit: the N values once, the three table fields twice. */
static void apply(unsigned int phy, unsigned int n_adj, unsigned int n_det, unsigned int value1, unsigned int value2, unsigned int value3)
{
    sys_ddr_set_n_adj_det_hook(phy, n_adj, n_det);
    sys_ddr_set_adj_fields_hook(phy, n_adj, n_det, value1, value2, value3);
    sys_ddr_set_adj_fields_hook(phy, n_adj, n_det, value1, value2, value3);
}

/*
 * Try settings (value1, value2, value3) of one calibration unit of memory interface phy and leave the chosen one
 * written. The unit is the one whose four routines the caller has stored in the hooks: the N values routine and
 * the field routine (sys_ddr_set_adj_table_fields_*, which writes value1, value2 and value3 into the fields its
 * tables give for n_adj) set a trial, the run_cal and wait_cal_idle routines return a measured value each.
 *
 * Callers: sys_ddr_zq_calibrate_first / _second / _third, with mode 0 and n_adj == n_det (a table index); and
 * sys_ddr_calibrate_unit_first / _second / _third, which pass their arguments through and have no caller.
 *
 * Every pass:
 *  1. write the trial setting (apply);
 *  2. measure: three run_cal results are summed into run_sum and three wait_cal_idle results into idle_sum,
 *     taken in turn; at the setting (0, 0, 0) start_diff = |idle_sum - run_sum|;
 *  3. choose the next setting, or stop.
 *
 * mode != 0 (sweep): value1 0 and value3 1 with value2 from 0x3f down to 0, then (0, 0, 0), then value1 1 and
 * value3 1 with value2 from 0 up to 0x3f. Returns after measuring (1, 0x3f, 1); the measurements are not used
 * to choose anything.
 *
 * mode == 0 (compare): starts at (0, 0, 0). Case 1 is run_sum < idle_sum (compare mode 0) or idle_sum < run_sum
 * (compare mode 1); case 2 is the other order. Equal sums end the search with the current setting.
 * Case 1 steps value2 up with value1 0, case 2 with value1 1 (the first step from (0, 0, 0) only changes value1
 * and value3). Each pass saves the setting and its difference before stepping. When the case changes from one
 * pass to the next, the search ends: of the last two settings the one with the smaller difference stays (the
 * current one on a tie). When value2 passes VALUE2_STEP_LIMIT without a change of case, the search ends and
 * (0, 0, 0) is written back if the last difference is larger than start_diff.
 */
void sys_ddr_search_cal_setting(unsigned int phy, unsigned int n_adj, unsigned int n_det, unsigned int mode)
{
    unsigned int idle_sum, run_sum;
    unsigned int value1, value3, value2;
    unsigned int saved_value1, saved_value3, saved_value2;
    int seen_case1, seen_case2;
    unsigned int saved_diff, start_diff, diff;

    saved_value1 = 0;
    saved_value3 = 0;
    saved_value2 = 0;
    saved_diff = 0;
    start_diff = 0;
    value1 = 0;
    if (mode) {
        value3 = 1;
        value2 = VALUE2_SWEEP_MAX;
    } else {
        value3 = 0;
        value2 = 0;
        saved_diff = 0;
    }
    seen_case1 = 0;
    seen_case2 = 0;
    for (;;) {
        /* 1. trial setting */
        apply(phy, n_adj, n_det, value1, value2, value3);
        /* 2. measure */
        run_sum = sys_ddr_run_cal_hook(phy);
        idle_sum = sys_ddr_wait_cal_idle_hook(phy);
        run_sum += sys_ddr_run_cal_hook(phy);
        idle_sum += sys_ddr_wait_cal_idle_hook(phy);
        run_sum += sys_ddr_run_cal_hook(phy);
        idle_sum += sys_ddr_wait_cal_idle_hook(phy);
        if ((value1 | value3 | value2) == 0)
            start_diff = idle_sum > run_sum ? idle_sum - run_sum : run_sum - idle_sum;
        /* 3. next setting */
        if (mode) {
            /* sweep */
            if (value1 == 0) {
                if (value3 == 0) {
                    /* after (0, 0, 0): second half */
                    value1 = 1;
                    value3 = 1;
                    value2 = 0;
                } else {
                    if (value2 == 0) {
                        value3 = 0;
                        value2 = 0;
                    } else {
                        value2--;
                        value3 = 1;
                    }
                }
            } else {
                if (value2 == VALUE2_SWEEP_MAX)
                    return;
                value2++;
                value1 = 1;
                value3 = 1;
            }
        } else {
            /* compare */
            if ((sys_ddr_cal_compare_mode == 0 && run_sum < idle_sum) || (sys_ddr_cal_compare_mode == 1 && idle_sum < run_sum)) {
                seen_case1 = 1;
                if (seen_case2 != 0) {
                    /* case changed: keep the setting with the smaller difference */
                    diff = idle_sum > run_sum ? idle_sum - run_sum : run_sum - idle_sum;
                    if (diff > saved_diff)
                        apply(phy, n_adj, n_det, saved_value1, saved_value2, saved_value3);
                    return;
                }
                saved_value1 = value1;
                saved_value3 = value3;
                saved_value2 = value2;
                saved_diff = idle_sum > run_sum ? idle_sum - run_sum : run_sum - idle_sum;
                if (value1 == 1) {
                    value1 = 0;
                } else if (value2 > VALUE2_STEP_LIMIT) {
                    /* range used up */
                    if (saved_diff > start_diff)
                        apply(phy, n_adj, n_det, 0, 0, 0);
                    return;
                } else if (value3 != 0) {
                    value2++;
                }
            } else if ((sys_ddr_cal_compare_mode == 0 && idle_sum < run_sum) || (sys_ddr_cal_compare_mode == 1 && run_sum < idle_sum)) {
                seen_case2 = 1;
                if (seen_case1 != 0) {
                    /* case changed: keep the setting with the smaller difference */
                    diff = idle_sum > run_sum ? idle_sum - run_sum : run_sum - idle_sum;
                    if (diff > saved_diff)
                        apply(phy, n_adj, n_det, saved_value1, saved_value2, saved_value3);
                    return;
                }
                saved_value1 = value1;
                saved_value3 = value3;
                saved_value2 = value2;
                saved_diff = idle_sum > run_sum ? idle_sum - run_sum : run_sum - idle_sum;
                if (value1 != 1) {
                    value1 = 1;
                } else if (value2 > VALUE2_STEP_LIMIT) {
                    /* range used up */
                    if (saved_diff > start_diff)
                        apply(phy, n_adj, n_det, 0, 0, 0);
                    return;
                } else {
                    value2++;
                }
            } else
                /* equal sums: keep the current setting */
                return;
            value3 = 1;
        }
    }
}
