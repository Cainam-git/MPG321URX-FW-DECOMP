/* sys_ddr_wait_cal_idle_third  (FUN_a00e2bcc)
 *
 * Start the third calibration unit and wait until its status reads idle six times in a row.
 * Returns: result register
 * Name basis: derived - returns a register read; reached through sys_ddr_unit3_idle_wait_entry, the
 *   wait_cal_idle hook of sys_ddr_search_cal_setting
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2bcc @ 0xa00e2bcc (-mcpu=v8 -O2 -g)
 * Source form: the loop counter is a signed int, which gives the signed branch for 'count > 5'; the two result
 * reads are kept in separate locals, the high one first.
 */
extern int sys_ddr_phy_read(unsigned int, unsigned int);
extern int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Set bit 0 of register 0x216 of memory interface phy to 0, then read bit 0 of register 0x23b until
 * it has read 0 six times in a row (a 1 starts the count again; there is no time limit). Returns
 * (register 0x227 << 8) | register 0x226. The second parameter is not used.
 * Reached through sys_ddr_unit3_idle_wait_entry, the wait_cal_idle hook of the setting search
 * (sys_ddr_search_cal_setting), which adds three of its results into the sum y.
 */
unsigned int sys_ddr_wait_cal_idle_third(unsigned int phy, unsigned int unused)
{
    int count;

    sys_ddr_phy_update_bits(phy, 0x216, 1, 0);

    do {
        count = 0;
        while (1) {
            unsigned int status = sys_ddr_phy_read_masked(phy, 0x23b, 1);
            count++;
            if (status != 0)
                break;
            if (count > 5) {
                unsigned int high = sys_ddr_phy_read(phy, 0x227) << 8;
                unsigned int low = sys_ddr_phy_read(phy, 0x226);
                return high | low;
            }
        }
    } while (1);
}
