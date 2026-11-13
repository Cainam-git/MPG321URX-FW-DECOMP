/* sys_ddr_wait_cal_idle_second  (FUN_a00e2b5c)
 *
 * Start the second calibration unit and wait until its status reads idle six times in a row.
 * Returns: result register
 * Name basis: derived - returns a register read; reached through sys_ddr_unit2_idle_wait_entry, the
 *   wait_cal_idle hook of sys_ddr_search_cal_setting
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2b5c @ 0xa00e2b5c (-mcpu=v8 -O2 -g)
 * Source form: the result is one expression; the status read is kept in an int.
 */
extern int sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_phy_read(unsigned int, unsigned int);

/*
 * Set bit 0 of register 0x1e2 of memory interface phy to 0, then read bit 0 of register 0x213 until
 * it has read 0 six times in a row (a 1 starts the count again; there is no time limit). Returns
 * (register 0x202 << 8) | register 0x201. The second parameter is not used.
 * Reached through sys_ddr_unit2_idle_wait_entry, the wait_cal_idle hook of the setting search
 * (sys_ddr_search_cal_setting), which adds three of its results into the sum y.
 */
unsigned int sys_ddr_wait_cal_idle_second(unsigned int phy, unsigned int unused)
{
    int count;
    int status;

    sys_ddr_phy_update_bits(phy, 0x1e2, 1, 0);
    do {
        count = 0;
        while (1) {
            status = sys_ddr_phy_read_masked(phy, 0x213, 1);
            count++;
            if (status != 0)
                break;
            if (count > 5)
                return (sys_ddr_phy_read(phy, 0x202) << 8) |
                       sys_ddr_phy_read(phy, 0x201);
        }
    } while (1);
}
