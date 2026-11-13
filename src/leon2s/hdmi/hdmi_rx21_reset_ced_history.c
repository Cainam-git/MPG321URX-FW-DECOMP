/* hdmi_rx21_reset_ced_history  (FUN_a0099560)
 *
 * Clear the character-error count history of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: derived - clears the CED history fields used by MAX_CED ('reset CED array'); samples per second
 *   = 100 / timer period
 *
 * Matching notes
 * --------------
 * FUN_a0099560 (leon2s 0xa0099560-0xa0099610, 176 bytes), flags -mcpu=v8 -Os -g.
 * Source form: every access names hdmi_rx21_lts_records[port & 0xff] directly; GCC keeps the first address in a temporary
 * and a copy for the loop, as the firmware does.
 */
#define CED_HISTORY_BYTES 0x50          /* 4 lanes x 10 halfwords */

/* The CED fields of the link-training record (0xb0 bytes per receiver, hdmi_rx21_lts_records); see hdmi_rx21_track_ced_errors. */
struct hdmi_rx21_lts_record {
    unsigned char pad_0x0[0x3e];
    unsigned char ced_history[CED_HISTORY_BYTES];   /* +0x3E: ten samples per lane */
    unsigned char ced_column;                       /* +0x8E: ring position of the next sample */
    unsigned char ced_sample_phase;                 /* +0x8F: a sample is taken when it is 0 */
    unsigned char ced_sample_divider;               /* +0x90 */
    unsigned char ced_history_full;                 /* +0x91: 1 once the ring has wrapped */
    unsigned char ced_max_reported[4];              /* +0x92: per lane */
    unsigned char rest[0xb0 - 0x96];
};
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned char hdmi_rx21_rx_detect_period;    /* period of the link-training timer */
extern void lib_memset(void *, int, int);

/*
 * Start the character error count (CED) history of an HDMI 2.1 receiver again: the ring position, the sample
 * phase, the history-full flag and the four per-lane reported maxima are cleared, the ten samples per lane are
 * cleared, and the sample divider is set to 100 / hdmi_rx21_rx_detect_period (0 when the period is 0).
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_track_ced_errors and DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable.
 */
void hdmi_rx21_reset_ced_history(unsigned int port)
{
    unsigned char i;

    hdmi_rx21_lts_records[port & 0xff].ced_column = 0;
    hdmi_rx21_lts_records[port & 0xff].ced_sample_phase = 0;
    hdmi_rx21_lts_records[port & 0xff].ced_history_full = 0;
    for (i = 0; i < 4; i++)
        hdmi_rx21_lts_records[port & 0xff].ced_max_reported[i] = 0;
    if (hdmi_rx21_rx_detect_period != 0)
        hdmi_rx21_lts_records[port & 0xff].ced_sample_divider = 100 / hdmi_rx21_rx_detect_period;
    else
        hdmi_rx21_lts_records[port & 0xff].ced_sample_divider = 0;
    lib_memset(hdmi_rx21_lts_records[port & 0xff].ced_history, 0, CED_HISTORY_BYTES);
}
