/* hdr_is_source_hdr_active  (FUN_a00d2e00)
 *
 * Return whether the current source reports an HDR signal.
 * Returns: 0 or 1
 * Name basis: derived - source 0/1, 2/3 or 4/5 asked through its own receiver routine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d2e00 @ 0xa00d2e00-0xa00d2e9c (39 words), flags -mcpu=v8 -Os -g.
 * Source form: each pair of calls shares one call instruction (the 0 / 1 argument is set in the branch delay
 * slots).
 */
extern unsigned char hdr_source;
extern unsigned char hdmi_get_hdr_packet_flag(unsigned char);
extern unsigned char hdmi_rx21_get_hdr_packet_flag(unsigned char);
extern unsigned int dp_status_reg_read8(unsigned char, unsigned char);

#define DP_HDR_STATUS_REG  5            /* DisplayPort status register read for sources 4 and 5 */
#define DP_HDR_FLAG_BIT    8            /* bit 3 of it */

/*
 * Return 1 when the current source (hdr_source) reports an HDR signal, else 0. Sources 0 and 1 ask
 * hdmi_get_hdr_packet_flag with receiver 0 / 1, sources 2 and 3 ask hdmi_rx21_get_hdr_packet_flag with
 * receiver 0 / 1, sources 4 and 5 test bit 3 of DisplayPort status register 5 of port 0 / 1; any other value
 * gives 0. Called by hdr_task.
 */
unsigned char hdr_is_source_hdr_active(void)
{
    unsigned char active = 0;
    unsigned char source = hdr_source;

    if (source == 0)
        active = hdmi_get_hdr_packet_flag(0);
    else if (source == 1)
        active = hdmi_get_hdr_packet_flag(1);
    else if (source == 2)
        active = hdmi_rx21_get_hdr_packet_flag(0);
    else if (source == 3)
        active = hdmi_rx21_get_hdr_packet_flag(1);
    else if (source == 4) {
        if (dp_status_reg_read8(0, DP_HDR_STATUS_REG) & DP_HDR_FLAG_BIT)
            active = 1;
    } else if (source == 5) {
        if (dp_status_reg_read8(1, DP_HDR_STATUS_REG) & DP_HDR_FLAG_BIT)
            active = 1;
    }
    return active;
}
