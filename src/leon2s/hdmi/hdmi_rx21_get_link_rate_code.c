/* hdmi_rx21_get_link_rate_code  (FUN_a00a20a8)
 *
 * Return the link rate code of an HDMI 2.1 receiver (0 TMDS, 1..6 FRL rates).
 *   port: receiver
 * Returns: rate code
 * Name basis: derived - byte +1 of the 0xB0 record; audio_calc_hdmi21_sample_rate maps 1..6 to 166..666 MHz
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a20a8, flags -mcpu=v8 -Os -g (section default).
 */
/* Link training record of one receiver (0xB0 bytes, table at 0xA807D680): the fields used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0 */
    unsigned char frl_rate;             /* +1 */
    unsigned char rest[0xb0 - 2];
};
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];

/*
 * Return the FRL rate of receiver `port` from its link training record: 0 for TMDS, 1..6 for the FRL rates
 * (audio_calc_hdmi21_sample_rate maps 1..6 to the clocks). Also called by hdmi_rx21_is_frl_mode.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_get_link_rate_code(unsigned int port)
{
    return hdmi_rx21_lts_records[port & 0xff].frl_rate;
}
