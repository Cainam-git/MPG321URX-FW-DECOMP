/* hdmi_rx21_clear_detect_flags  (FUN_a0096aa4)
 *
 * Clear seven detection flags of an HDMI 2.1 receiver record.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - 400-byte record bytes 0x186, 0xA1, 0xE6, 0x157, 0x10C, 0xB8, 0x181
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0096aa4 @ 0xa0096aa4-0xa0096ad8 (13 words), flags -mcpu=v8 -Os -g. Leaf.
 * Source form: the +0x186 clear is last in the source (the scheduler hoists the last store of the block to the
 * front; same pattern as sys_dsc_dec_build_hdmi21_config): source order a1, e6, 157, 10c, b8, 181, 186.
 */
#define RX21_RECORD_SIZE 400            /* bytes per entry of hdmi_rx21_input_records */

extern unsigned char hdmi_rx21_input_records[];    /* HDMI 2.1 receiver records */

/*
 * Clear seven flag bytes of the record of an HDMI 2.1 receiver: +0xA1, +0xE6, +0x157, +0x10C, +0xB8, +0x181 and
 * +0x186. Six of them are the first of the three status bytes at the end of the AVI, audio InfoFrame, HDR
 * InfoFrame, SPD InfoFrame, audio stream and CVTEM blocks of the record; a successful packet read sets them
 * to 1 again (see DRV_HDMI_ModeDetect_FSM_Complete). +0xB8 lies in the block at +0xA4.
 *   port: HDMI 2.1 receiver 0/1
 * Called by DRV_HDMI_ModeDetect_FSM_Complete and hdmi_rx21_modedet_wait_eq_done, each followed by hdmi_rx21_clear_status_flags.
 */
void hdmi_rx21_clear_detect_flags(unsigned char port)
{
    unsigned char *record = &hdmi_rx21_input_records[port * RX21_RECORD_SIZE];

    record[0xa1] = 0;
    record[0xe6] = 0;
    record[0x157] = 0;
    record[0x10c] = 0;
    record[0xb8] = 0;
    record[0x181] = 0;
    record[0x186] = 0;
}
