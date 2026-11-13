/* hdmi_rx21_clear_status_flags  (FUN_a0096ad8)
 *
 * Clear six status flags of an HDMI 2.1 receiver record.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - 400-byte record bytes 0xA2, 0xE7, 0x10D, 0xB9, 0x182, 0x187
 *
 * Matching notes
 * --------------
 * FUN_a0096ad8 (leon2s, 0xa0096ad8-0xa0096b08, 48 bytes, 12 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * Store order: in this -Os block of independent byte clears the firmware emits the last source store first, then
 * the others in source order (the last of those in the retl delay slot); as in the twins hdmi_clear_packet_update_flags /
 * hdmi_clear_packet_seen_flags.
 */
#define RX21_RECORD_SIZE 400            /* bytes per entry of hdmi_rx21_input_records */

extern unsigned char hdmi_rx21_input_records[];    /* HDMI 2.1 receiver records */

/*
 * Clear six flag bytes of the record of an HDMI 2.1 receiver: +0xA2, +0xE7, +0x10D, +0xB9, +0x182 and +0x187.
 * Five of them are the second of the three status bytes at the end of the AVI, audio InfoFrame, SPD InfoFrame,
 * audio stream and CVTEM blocks (the neighbours of the bytes hdmi_rx21_clear_detect_flags clears); +0xB9 lies
 * in the block at +0xA4.
 *   port: HDMI 2.1 receiver 0/1
 * Called by DRV_HDMI_ModeDetect_FSM_Complete, hdmi_rx21_modedet_wait_eq_done and, for both receivers, input_poll_port_services.
 */
void hdmi_rx21_clear_status_flags(unsigned int port)
{
    unsigned char *record = &hdmi_rx21_input_records[(port & 0xff) * RX21_RECORD_SIZE];
    record[0xa2] = 0;
    record[0xe7] = 0;
    record[0x10d] = 0;
    record[0xb9] = 0;
    record[0x182] = 0;
    record[0x187] = 0;
}
