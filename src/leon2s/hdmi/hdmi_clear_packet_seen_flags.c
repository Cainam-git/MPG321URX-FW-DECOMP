/* hdmi_clear_packet_seen_flags  (FUN_a008faa0)
 *
 * Clear the packet received flags of an HDMI receiver record.
 *   port: receiver
 * Name basis: derived - record bytes 0x57, 0x68, 0x1F, 0x41, 0x8A, set by the status poll
 *
 * Matching notes
 * --------------
 * FUN_a008faa0 (leon2s, 0xa008faa0-0xa008facc, 44 bytes, 11 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * Source form: the store order 0x57, 0x68, 0x1f, 0x41, 0x8a (the firmware order is 8a, 57, 68, 1f, 41): in a -Os
 * block of independent byte clears the firmware emits the last source store first, then the others in source
 * order.
 */

/* Offsets in struct hdmi_rx_record (see hdmi_poll_rx_status). */
#define HDMI_RX_RECORD_SIZE   176
#define RX_AVI_SEEN           0x57
#define RX_AUDIO_SEEN         0x68
#define RX_HDR_SEEN           0x1f
#define RX_SPD_SEEN           0x41
#define RX_VENDOR_SEEN        0x8a

extern unsigned char hdmi_rx_records[];

/* Twin of hdmi_clear_packet_update_flags: clears the "seen" flag of the AVI, audio, HDR, SPD and vendor packet
   areas of receiver "port". Called on the way from STABLE to READY. */
void hdmi_clear_packet_seen_flags(unsigned int port)
{
    unsigned char *rec = hdmi_rx_records + (port & 0xff) * HDMI_RX_RECORD_SIZE;
    rec[RX_AVI_SEEN] = 0;
    rec[RX_AUDIO_SEEN] = 0;
    rec[RX_HDR_SEEN] = 0;
    rec[RX_SPD_SEEN] = 0;
    rec[RX_VENDOR_SEEN] = 0;
}
