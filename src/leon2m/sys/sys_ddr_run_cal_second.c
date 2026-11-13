/* sys_ddr_run_cal_second  (FUN_a00e2cac)
 *
 * Trigger a measurement of the second calibration unit and return its result.
 * Returns: result
 * Name basis: derived - start bit, status poll, result read; reached through sys_ddr_unit2_measure_entry, the
 *   run_cal hook of sys_ddr_search_cal_setting
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2cac @ 0xa00e2cac (-mcpu=v8 -O2 -g)
 * Source form: the callees are declared with int parameters; the two result reads are kept in separate locals,
 * the high one first.
 */
extern int sys_ddr_phy_update_bits(int, int, int, int);
extern unsigned int sys_ddr_phy_read_masked(int, int, int);
extern unsigned int sys_ddr_phy_read(int, int);

/*
 * Set bit 0 of register 0x1e2 of memory interface phy to 1, then read bit 0 of register 0x213 until
 * it has read 0 six times in a row (a 1 starts the count again; there is no time limit). Returns
 * (register 0x202 << 8) | register 0x201.
 * Reached through sys_ddr_unit2_measure_entry, the run_cal hook of the setting search
 * (sys_ddr_search_cal_setting), which adds three of its results into the sum x.
 */
unsigned int sys_ddr_run_cal_second(unsigned int phy)
{
    unsigned int status;
    unsigned int high;
    int count;

    sys_ddr_phy_update_bits(phy, 0x1e2, 1, 1);
    do {
        count = 0;
        while (1) {
            status = sys_ddr_phy_read_masked(phy, 0x213, 1);
            count++;
            if (status != 0)
                break;
            if (count > 5) {
                high = sys_ddr_phy_read(phy, 0x202) << 8;
                status = sys_ddr_phy_read(phy, 0x201);
                return high | status;
            }
        }
    } while (1);
}
