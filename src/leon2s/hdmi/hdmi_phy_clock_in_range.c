/* hdmi_phy_clock_in_range  (FUN_a0078fe8)
 *
 * Return whether a clock is detected and its count is within the valid range.
 *   p1: PHY
 * Returns: 1 when valid
 * Name basis: derived - clock-detect bit of 0x1C04 and hdmi_phy_read_clock_count in 11..599; caller
 *   hdmi_eq_run_scan_fsm
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0078fe8 @ 0xa0078fe8, flags -mcpu=v8 -Os -g.
 * Source form: the clock count is read twice (two calls), each time as a halfword; param_2 is not used.
 */
#define CLOCK_COUNT_MAX 0x257   /* highest count accepted (the count must also be above 10) */

extern unsigned int hdmi_phy_read_clock_count(unsigned char param_1);
extern unsigned int hdmi_phy_test_bit(unsigned int param_1, unsigned char param_2, unsigned short param_3);

/* Returns 1 when bit 28 of PHY register 0x1c04 is set and the clock count (hdmi_phy_read_clock_count)
 * lies between 11 and 599, otherwise 0.
 *   phy:    PHY page (low 8 bits used)
 *   unused: not read */
unsigned int hdmi_phy_clock_in_range(unsigned int phy, unsigned int unused)
{
    unsigned int bit_set;
    unsigned int phy_masked;

    phy_masked = phy & 0xff;
    bit_set = hdmi_phy_test_bit(0x1c, (unsigned char)phy_masked, 0x1c04);
    if (bit_set != 0) {
        if ((unsigned short)hdmi_phy_read_clock_count((unsigned char)phy) > 10) {
            if ((unsigned short)hdmi_phy_read_clock_count((unsigned char)phy) <= CLOCK_COUNT_MAX) {
                return 1;
            }
        }
    }
    return 0;
}
