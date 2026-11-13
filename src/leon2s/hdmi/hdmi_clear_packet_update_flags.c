/* hdmi_clear_packet_update_flags  (FUN_a008fa78)
 *
 * Clear the packet update flags of an HDMI receiver record.
 *   port: receiver
 * Name basis: derived - record bytes 0x58 (AVI), 0x69 (audio), 0x42 (SPD), 0x8B (vendor packet)
 *
 * Matching notes
 * --------------
 * FUN_a008fa78 (leon2s, 0xa008fa78-0xa008faa0, 40 bytes, 10 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * Source form: the store order 0x58, 0x69, 0x42, 0x8b (the firmware order is 8b, 58, 69, 42): in a -Os block of
 * independent byte clears the firmware emits the last source store first, then the others in source order.
 */

/* Offsets in struct hdmi_rx_record (see hdmi_poll_rx_status). */
#define HDMI_RX_RECORD_SIZE   176
#define RX_AVI_UPDATE         0x58
#define RX_AUDIO_UPDATE       0x69
#define RX_SPD_UPDATE         0x42
#define RX_VENDOR_UPDATE      0x8b

extern unsigned char hdmi_rx_records[];

/* Clears the update flag of the AVI, audio, SPD and vendor packet areas of receiver "port". The HDR area has
   its own flag, which is not touched here. Called on the way from STABLE to READY and from the input port
   service. */
void hdmi_clear_packet_update_flags(unsigned int port)
{
    unsigned char *rec = hdmi_rx_records + (port & 0xff) * HDMI_RX_RECORD_SIZE;
    rec[RX_AVI_UPDATE] = 0;
    rec[RX_AUDIO_UPDATE] = 0;
    rec[RX_SPD_UPDATE] = 0;
    rec[RX_VENDOR_UPDATE] = 0;
}
