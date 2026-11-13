/* hdmi_rx21_reset_rsed_history  (FUN_a0099610)
 *
 * Clear the Reed-Solomon error count history of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: derived - clears the RSED history fields used by MAX_RSED ('reset RSED array')
 *
 * Matching notes
 * --------------
 * FUN_a0099610 (leon2s 0xa0099610-0xa009967c, 108 bytes), flags -mcpu=v8 -Os -g.
 * Source form: record struct, stores in this order (GCC schedules the division first); the history clear is a tail
 * call.
 */
#define RSED_HISTORY_BYTES 0x14         /* 10 halfwords */

/* The RSED fields of the link-training record (0xb0 bytes per receiver, hdmi_rx21_lts_records); see hdmi_rx21_track_rsed_errors. */
struct hdmi_rx21_lts_record {
    unsigned char pad_0x0[0x96];
    unsigned char rsed_history[RSED_HISTORY_BYTES]; /* +0x96: ten samples */
    unsigned char rsed_column;                      /* +0xAA: ring position of the next sample */
    unsigned char rsed_sample_phase;                /* +0xAB: a sample is taken when it is 0 */
    unsigned char rsed_sample_divider;              /* +0xAC */
    unsigned char rsed_history_full;                /* +0xAD: 1 once the ring has wrapped */
    unsigned char byte_0xae, byte_0xaf;             /* flags that hdmi_rx21_track_rsed_errors sets */
};
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned char hdmi_rx21_rx_detect_period;    /* period of the link-training timer */
extern void *lib_memset(void *, int, unsigned int);

/*
 * Start the Reed-Solomon error count (RSED) history of an HDMI 2.1 receiver again: the ring position, the sample
 * phase, the history-full flag and the two flag bytes are cleared, the ten samples are cleared, and the sample
 * divider is set to 100 / hdmi_rx21_rx_detect_period.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_track_rsed_errors and DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable.
 */
void hdmi_rx21_reset_rsed_history(unsigned char port)
{
    hdmi_rx21_lts_records[port].rsed_column = 0;
    hdmi_rx21_lts_records[port].rsed_sample_phase = 0;
    hdmi_rx21_lts_records[port].rsed_history_full = 0;
    hdmi_rx21_lts_records[port].byte_0xae = 0;
    hdmi_rx21_lts_records[port].byte_0xaf = 0;
    hdmi_rx21_lts_records[port].rsed_sample_divider = 100 / hdmi_rx21_rx_detect_period;
    lib_memset(hdmi_rx21_lts_records[port].rsed_history, 0, RSED_HISTORY_BYTES);
}
