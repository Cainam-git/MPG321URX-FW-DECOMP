/* hdmi_rx21_clear_mode_status  (FUN_a009c87c)
 *
 * Clear the detected-mode flags of an HDMI 2.1 receiver and mark audio not stable.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: derived - clears record bytes +1, +4, +0x2d, DRV_HDMI_Set_AudStatus(port, 0); called on sync
 *   loss and mode change
 *
 * Matching notes
 * --------------
 * FUN_a009c87c (leon2s 0xa009c87c-0xa009c8ac, 48 bytes, leaf with sibling call), flags -mcpu=v8 -Os -g.
 * Source form: the three clears are written in the order +1, +0x2d, +4; the scheduler moves the +4 store first, as in
 * the firmware. The audio call is a sibling call.
 */
#define RX21_RECORD_SIZE          400   /* bytes per entry of hdmi_rx21_input_records */
#define RX21_MODE_DETECTED        1     /* record byte +1 */
#define RX21_CVTEM_PRESENT        0x2d  /* record byte +0x2d */
#define RX21_BYTE_4               4     /* record byte +4 */

extern unsigned char hdmi_rx21_input_records[];    /* HDMI 2.1 receiver records */
extern void DRV_HDMI_Set_AudStatus(unsigned char, unsigned char);

/*
 * Clear bytes +1 (mode_detected), +0x2D (cvtem_present) and +4 of the record of an HDMI 2.1 receiver and mark its
 * audio as not stable (DRV_HDMI_Set_AudStatus with on = 0, which also mutes it).
 *   port: HDMI 2.1 receiver 0/1
 * Called when the mode detection of a receiver is thrown away: from hdmi_rx21_modedet_wait_eq_done, hdmi_rx21_detect_timing_change, hdmi_rx21_force_mode_detect_standby,
 * hdmi_rx21_modedet_watch_stable and hdmi_rx21_service_packet_events.
 */
void hdmi_rx21_clear_mode_status(unsigned char port)
{
    unsigned char *record = hdmi_rx21_input_records + port * RX21_RECORD_SIZE;

    record[RX21_MODE_DETECTED] = 0;
    record[RX21_CVTEM_PRESENT] = 0;
    record[RX21_BYTE_4] = 0;
    DRV_HDMI_Set_AudStatus(port, 0);
}
