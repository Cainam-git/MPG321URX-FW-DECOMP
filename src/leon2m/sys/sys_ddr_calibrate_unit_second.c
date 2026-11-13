/* sys_ddr_calibrate_unit_second  (FUN_a00e317c)
 *
 * Run the setting search with the routines of the second calibration unit.
 * Name basis: derived - stores the four routine pointers, then sys_ddr_search_cal_setting; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e317c @ 0xa00e317c-0xa00e31cc (20 words), flags -mcpu=v8 -O3 -g.
 * Source form: the hook values are symbol addresses (extern char), so each store gets its own 'sethi %hi'; the
 * call of sys_ddr_search_cal_setting is a tail call (the caller's return address is handed on; the last word is
 * the nop the compiler places behind such a call sequence).
 */
extern unsigned int sys_ddr_run_cal_hook;
extern unsigned int sys_ddr_set_n_adj_det_hook;
extern unsigned int sys_ddr_wait_cal_idle_hook;
extern unsigned int sys_ddr_set_adj_fields_hook;
extern void sys_ddr_search_cal_setting(unsigned int, unsigned int, unsigned int, unsigned int);

extern char sys_ddr_unit2_n_values_entry, sys_ddr_unit2_adj_fields_entry, sys_ddr_unit2_idle_wait_entry, sys_ddr_unit2_measure_entry;

/*
 * Point the four hooks of the setting search at the routines of the second calibration unit (N values, field
 * write, wait_cal_idle and run_cal) and run sys_ddr_search_cal_setting with the same four arguments. The
 * zq calibration routine of this unit (sys_ddr_zq_calibrate_second) stores the same four values before each of its
 * searches. Nothing in the image calls this routine.
 */
void sys_ddr_calibrate_unit_second(unsigned int phy, unsigned int p1, unsigned int p2, unsigned int mode)
{
    sys_ddr_set_n_adj_det_hook = (unsigned int)&sys_ddr_unit2_n_values_entry;
    sys_ddr_set_adj_fields_hook = (unsigned int)&sys_ddr_unit2_adj_fields_entry;
    sys_ddr_wait_cal_idle_hook = (unsigned int)&sys_ddr_unit2_idle_wait_entry;
    sys_ddr_run_cal_hook = (unsigned int)&sys_ddr_unit2_measure_entry;
    sys_ddr_search_cal_setting(phy, p1, p2, mode);
}
