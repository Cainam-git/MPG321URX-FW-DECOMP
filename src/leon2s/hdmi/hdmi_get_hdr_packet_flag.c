/* hdmi_get_hdr_packet_flag  (FUN_a0090f0c)
 *
 * Return the HDR InfoFrame update flag of an HDMI receiver record.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - record byte +0x20, set with +0x1F when the HDR (0x87) packet arrives
 *
 * Matching notes
 * --------------
 * FUN_a0090f0c (leon2s 0xa0090f0c-0xa0090f28, 28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Leaf routine without a register window (no save). The record is declared as a struct with the byte at +0x20
 * named, 0xb0 bytes in all.
 */

/* Receiver record (see struct hdmi_rx_record in hdmi_poll_rx_status): the HDR packet array is 0x1f bytes at +0,
   followed by the seen flag at +0x1f and the update flag at +0x20. */
struct hdmi_rx_record_hdr {
    unsigned char hdr_packet[0x1f];
    unsigned char hdr_seen;
    unsigned char hdr_update;
    unsigned char rest[0x8f];
};
extern struct hdmi_rx_record_hdr hdmi_rx_records[];

/* Returns the update flag of the HDR packet (hdmi_poll_rx_status sets it to 1 when status register 0x84 reports a new
   HDR packet and clears it when that register is non-zero without the HDR bit). Called by hdr_is_source_hdr_active. */
unsigned char hdmi_get_hdr_packet_flag(unsigned char port)
{
    return hdmi_rx_records[port].hdr_update;
}
