/* hdmi_rx21_on_hdr_infoframe  (FUN_a00a157c)
 *
 * Mark the HDR InfoFrame received and read it when allowed.
 *   port: receiver
 * Name basis: derived - packet-event callback; calls hdmi_rx21_read_hdr_infoframe into record +0x114
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a157c, flags -mcpu=v8 -Os -g (section default).
 * Source form: 'seen' is assigned before 'update', which gives the firmware's store order (+0x157 first).
 */
/* HDR InfoFrame area of the receiver record: ends in three status bytes. */
struct rx21_hdr_infoframe {
    unsigned char data[0x43];
    unsigned char seen;                 /* +0x157 of the record: set to 1 here */
    unsigned char update;               /* +0x158: set to 1 here; read by hdmi_rx21_get_hdr_packet_flag */
    unsigned char hold;                 /* +0x159: while non-zero the InfoFrame is not read here */
    unsigned char _46[2];
};

/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records): the part used here. */
struct rx21_record {
    unsigned char _000[0x114];
    struct rx21_hdr_infoframe hdr_infoframe;    /* +0x114 */
    unsigned char _15c[0x34];
};
extern struct rx21_record hdmi_rx21_input_records[];
extern unsigned char hdmi_rx21_read_hdr_infoframe(unsigned char, struct rx21_hdr_infoframe *);

/*
 * Packet callback for the HDR InfoFrame of receiver `port` (event 0x35, slot 5 in
 * hdmi_rx21_service_packet_events): mark it seen and updated and, unless hold is set, read it with
 * hdmi_rx21_read_hdr_infoframe (a tail call). Same form as hdmi_rx21_on_audio_stream_packet.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_on_hdr_infoframe(unsigned char port)
{
    hdmi_rx21_input_records[port].hdr_infoframe.seen = 1;
    hdmi_rx21_input_records[port].hdr_infoframe.update = 1;
    if (hdmi_rx21_input_records[port].hdr_infoframe.hold == 0)
        hdmi_rx21_read_hdr_infoframe(port, &hdmi_rx21_input_records[port].hdr_infoframe);
}
