/* sys_mode_restart_channel  (FUN_a01518c8)
 *
 * Run the entry actions of global mode handler state 5: reset and restart a channel.
 * Name basis: derived - header: state 5 entry (channel restart); converter lock off, then
 *   panel_output_set_source_select(0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01518c8 @ 0xa01518c8-0xa01519b4 (59 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record switch lists the cases in the order 'case 0: default:', 1, 2, 3; the result of
 * panel_get_active_row is not used, and the call is kept. The fill-colour callees take (u8, u8, int, u8) and
 * (u8, u8, u8, int); other prototypes change the argument set-up. The word at +0x68 is reached through the
 * unclamped channel number, like the original.
 */
/* Channel record (0x78 bytes); word 0: state in bits 28..31, port in bits 12..15; word +0x68 is cleared in part. */
struct channel_record {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x68 - 0x04];
    unsigned int word_0x68;
    unsigned char p6c[0x78 - 0x6c];
};
extern struct channel_record channel_records[4];
extern unsigned short panel_output_rate;
extern unsigned char *panel_get_active_row(void);
extern void pq_block_set_fill_color(unsigned char, unsigned char, int, unsigned char);
extern void pq_set_port_fill_color(unsigned char, unsigned char, unsigned char, int);
extern void pq_block_blank(unsigned char);
extern void panel_output_set_source_select(unsigned char);
extern void sys_frc_setup_lock(unsigned char lock, unsigned char unused, unsigned short p3, unsigned short vfreq);

#define WORD_0X68_BIT20 0x100000

/*
 * Entry actions of channel state 5 for one channel (called by GlobalModeHandler, GlobalModeHandler, when the channel
 * enters that state): set the fill colours of the channel's port to 0, blank its picture block, clear bit 20 of
 * word +0x68 of the channel record, set the frame-rate converter up with the lock off (channel 0 only, with
 * panel_output_rate) and select source 0 at the output stage.
 *
 *   channel  0..3; any other value uses channel record 0 for the port number
 */
void sys_mode_restart_channel(unsigned char channel)
{
    unsigned char port;

    panel_get_active_row();
    switch (channel) {
    case 0: default: port = channel_records[0].u.b.port; break;
    case 1: port = channel_records[1].u.b.port; break;
    case 2: port = channel_records[2].u.b.port; break;
    case 3: port = channel_records[3].u.b.port; break;
    }
    pq_block_set_fill_color(port, 0, 0, 0);
    pq_set_port_fill_color(port, 0, 0, 0);
    pq_block_blank(port);
    channel_records[channel].word_0x68 &= ~WORD_0X68_BIT20;
    if (channel == 0)
        sys_frc_setup_lock(0, 0, 0, panel_output_rate);
    panel_output_set_source_select(0);
}
