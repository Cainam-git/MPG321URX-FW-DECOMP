/* hdmi_rx21_get_hdr_packet_flag  (FUN_a00a268c)
 *
 * Return the HDR InfoFrame received flag of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 1 when received
 * Name basis: derived - record byte +0x158, set by hdmi_rx21_on_hdr_infoframe; caller hdr_is_source_hdr_active
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a268c, flags -mcpu=v8 -Os -g (section default). Leaf without a register window (no save).
 */
/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records): the field used here. */
struct rx21_record {
    unsigned char _000[0x158];
    unsigned char hdr_update;           /* +0x158: set by hdmi_rx21_on_hdr_infoframe */
    unsigned char _159[0x37];
};
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Return the hdr_update byte of receiver `port` (record offset 0x158): 1 when the HDR InfoFrame callback
 * hdmi_rx21_on_hdr_infoframe has run since hdmi_rx21_service_packet_events last cleared it. Called by
 * hdr_is_source_hdr_active.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_get_hdr_packet_flag(unsigned char port)
{
    return hdmi_rx21_input_records[port].hdr_update;
}
