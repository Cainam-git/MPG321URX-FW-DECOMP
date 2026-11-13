/* hdmi_update_port_status_flags  (FUN_a006d61c)
 *
 * Refresh the VRR, signal and cable flags of an HDMI 2.0 port record.
 * Name basis: derived - VRR detector result into flag byte +0xD (bit 2 reaches the main processor's port bit);
 *   caller TMDS state machine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d61c @ 0xa006d61c, flags -mcpu=v8 -Os -g.
 * Source form: the port type test is written 'if (type != 5) {...} else ...' (other port first); each
 * flag is its own read-modify-write.
 */
/* Port record (20 bytes, input_port_records at 0xA807A824). */
struct port_record {
    unsigned char link_state;           /* +0: 5 = the port type that has its own audio test below */
    unsigned char byte_0x1;
    unsigned short half_0x2, half_0x4, half_0x6, half_0x8, half_0xa;
    unsigned char byte_0xc;
    unsigned char published_flags;      /* +0xd: sent to the main program */
    unsigned short status_0xe;          /* bit 14 / 15: see below */
    unsigned short half_0x10;
    unsigned short flags_0x12;          /* bit 6: see below */
};
extern unsigned char hdr_source_active_flag, hdcp_rx_status_mask;
extern unsigned char hdmi_detect_vrr_signalling(unsigned char);
extern unsigned char hdmi_get_restart_hint(unsigned char);
extern unsigned char hdmi_status134_bit1(unsigned char);
extern unsigned char audio_check_hdmi_rate_valid(unsigned char, unsigned char);

/* Rebuilds the status flags of one port record from the receiver's current state.
 * Flag byte +0xd (published_flags), set or cleared bit by bit from r, the result of
 * hdmi_detect_vrr_signalling:
 *   bit 2 = r bit 0 or r bit 2 (this bit is the one that reaches the main program's port bit),
 *   bit 3 = r bit 1, bit 4 = r bit 4, bit 7 = r bit 3,
 *   bit 6 = bit `port` of hdr_source_active_flag, bit 5 = bit `port` of hdcp_rx_status_mask.
 * Halfword +0xe: bit 14 = hdmi_get_restart_hint, bit 15 = hdmi_status134_bit1.
 * Halfword +0x12 bit 6: for a record whose link_state is 5, the result of audio_check_hdmi_rate_valid
 * (0, port); for any other, that routine is called with (1, port), its result is dropped and the bit is
 * cleared.
 *   rec:  the port record
 *   port: receiver index */
void hdmi_update_port_status_flags(struct port_record *rec, unsigned int port)
{
    unsigned char p = port;
    unsigned char r = hdmi_detect_vrr_signalling(p);

    if ((r & 1) || (r & 4)) rec->published_flags |= 4; else rec->published_flags &= ~4;
    if (r & 2) rec->published_flags |= 8; else rec->published_flags &= ~8;
    if (r & 0x10) rec->published_flags |= 0x10; else rec->published_flags &= ~0x10;
    if (r & 8) rec->published_flags |= 0x80; else rec->published_flags &= ~0x80;
    if (hdmi_get_restart_hint(p)) rec->status_0xe |= 0x4000; else rec->status_0xe &= ~0x4000;
    if (hdmi_status134_bit1(p)) rec->status_0xe |= 0x8000; else rec->status_0xe &= ~0x8000;
    if (rec->link_state != 5) {
        audio_check_hdmi_rate_valid(1, p);
        rec->flags_0x12 &= ~0x40;
    } else {
        if (audio_check_hdmi_rate_valid(0, p)) rec->flags_0x12 |= 0x40; else rec->flags_0x12 &= ~0x40;
    }
    if ((hdr_source_active_flag >> (unsigned char)port) & 1) rec->published_flags |= 0x40; else rec->published_flags &= ~0x40;
    if ((hdcp_rx_status_mask >> (unsigned char)port) & 1) rec->published_flags |= 0x20; else rec->published_flags &= ~0x20;
}
