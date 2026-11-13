/* hdmi_rx21_get_status_byte7  (FUN_a00a2978)
 *
 * Return status byte +7 of the record of an HDMI 2.1 receiver.
 *   receiver
 * Returns: byte
 * Name basis: descriptive - a 1 -> 0 change makes hdmi_rx21_modedet_watch_stable restart detection; caller
 *   hdmi_rx21_update_port_status_flags
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2978 @ 0xa00a2978, flags -mcpu=v8 -Os -g.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[7];
    unsigned char event16_seen;                  /* +0x7 */
    unsigned char after[400 - 7 - 1];
};
extern struct rx21_record hdmi_rx21_input_records[];

/* Byte +7 of the input record: 1 when event 0x16 was pending in the last pass of hdmi_rx21_service_sync_events. receiver is 0 or 1. */
unsigned char hdmi_rx21_get_status_byte7(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].event16_seen;
}
