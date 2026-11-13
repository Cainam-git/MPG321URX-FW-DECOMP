/* sys_ddr_run_cal_third  (FUN_a00e2d1c)
 *
 * Trigger a measurement of the third calibration unit and return its result.
 * Returns: result
 * Name basis: derived - start bit, status poll, result read; reached through sys_ddr_unit3_measure_entry, the
 *   run_cal hook of sys_ddr_search_cal_setting
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2d1c @ 0xa00e2d1c (-mcpu=v8 -O2 -g)
 * Source form: the result is one expression, which places the shift of the first read before the second call.
 */
extern int sys_ddr_phy_read(unsigned int, unsigned int);
extern int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Set bit 0 of register 0x216 of memory interface phy to 1, then read bit 0 of register 0x23b until
 * it has read 0 six times in a row (a 1 starts the count again; there is no time limit). Returns
 * (register 0x227 << 8) | register 0x226. The second parameter is not used.
 * Reached through sys_ddr_unit3_measure_entry, the run_cal hook of the setting search
 * (sys_ddr_search_cal_setting), which adds three of its results into the sum x.
 */
unsigned int sys_ddr_run_cal_third(unsigned int phy, unsigned int unused)
{
    unsigned int status;
    int count;

    sys_ddr_phy_update_bits(phy, 0x216, 1, 1);
    do {
        count = 0;
        while (1) {
            status = sys_ddr_phy_read_masked(phy, 0x23b, 1);
            count = count + 1;
            if (status != 0) break;
            if (5 < count) {
                return (sys_ddr_phy_read(phy, 0x227) << 8) | sys_ddr_phy_read(phy, 0x226);
            }
        }
    } while (1);
}
