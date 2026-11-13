/* hdmi_rx21_on_audio_stream_packet  (FUN_a00a1104)
 *
 * Mark the audio stream packet received and read it when allowed.
 *   port: receiver
 * Name basis: derived - packet-event callback; calls hdmi_rx21_read_audio_stream_packet into record +0x162
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1104, flags -mcpu=v8 -Os -g (section default).
 * Source form: the 'seen' flag is assigned before 'update', which gives the firmware's store order (+0x181 first).
 */
/* Audio stream packet area of the receiver record: ends in three status bytes. */
struct rx21_audio_stream {
    unsigned char data[0x1f];
    unsigned char seen;                 /* +0x181 of the record: set to 1 here */
    unsigned char update;               /* +0x182: set to 1 here */
    unsigned char hold;                 /* +0x183: while non-zero the packet is not read here */
};

/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records): the part used here. */
struct rx21_record {
    unsigned char _000[0x162];
    struct rx21_audio_stream audio_stream;      /* +0x162 */
    unsigned char _184[0xc];
};
extern struct rx21_record hdmi_rx21_input_records[];
extern unsigned char hdmi_rx21_read_audio_stream_packet(unsigned char, struct rx21_audio_stream *);

/*
 * Packet callback for the audio stream packet of receiver `port` (event 9, slot 1 in
 * hdmi_rx21_service_packet_events): mark the packet as seen and updated and, unless hold is set, read it with
 * hdmi_rx21_read_audio_stream_packet (a tail call).
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_on_audio_stream_packet(unsigned char port)
{
    hdmi_rx21_input_records[port].audio_stream.seen = 1;
    hdmi_rx21_input_records[port].audio_stream.update = 1;
    if (hdmi_rx21_input_records[port].audio_stream.hold == 0)
        hdmi_rx21_read_audio_stream_packet(port, &hdmi_rx21_input_records[port].audio_stream);
}
