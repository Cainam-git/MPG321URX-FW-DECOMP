/* pq_api_set_fill_color  (FUN_a0145fe8)
 *
 * Set the fill colour of a port and switch the colour-fill path.
 * Name basis: derived - colour-fill path; used by the colour cycler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145fe8 @ 0xa0145fe8, flags -mcpu=v8 -O3 -g.
 * Source form: the channel check is a static switch helper returning -1 for any other value, stored in an unsigned
 * char; the port is read from the channel record again for each call; the last call is a tail call whose result
 * is returned.
 */

/* The channel record (0x78 bytes), up to the field used here. */
struct channel_record { unsigned int status_word; unsigned char rest[0x74]; };   /* +0: port in bits 12-15 */
extern struct channel_record channel_records[4];
extern void pq_set_color_fill_enable(int);
extern void pq_block_blank_with_color(int, int, int, int);
extern void pq_block_set_blank_color(int, int, int, int);
extern void pq_block_set_fill_color(int, int, int, int);
extern int pq_set_port_fill_color(int, int, int, int);

#define CHANNEL_PORT_SHIFT 12           /* the port is bits 12-15 of the channel's status word */
#define COLOR_FILL_OFF     0

/* Channel numbers 0 to 3 stay as they are, any other value becomes -1 (read as 0xFF in an unsigned char). */
static int remap_channel(int channel)
{
    switch (channel) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Write one colour as the blanking colour and the fill colour of the port of a channel.
 *
 *   channel           0..3; any other value returns at once (with the channel number) and does nothing
 *   red, green, blue  the colour
 *   blank             non-zero: first blank the port's picture block with this colour (pq_block_blank_with_color)
 *
 * The colour-fill path is switched off first (pq_set_color_fill_enable(0)). Then the colour goes to the
 * blanking colour and the fill colour of the picture block and to the port's fill colour bytes.
 *
 * Every caller passes channel 0. ShowLogo (black) and ddc_tool_set_fill_or_inspection (white) pass blank = 1.
 * The others pass blank = 0: panel_cycle_burnin_colour (its test colours), ddc_apply_maker_vcp_set (the colour of a
 * request), sys_end_logo_restore_picture and osd_dispatch_key_event (black).
 */
int pq_api_set_fill_color(unsigned char channel, unsigned char red, unsigned char green, unsigned char blue, unsigned char blank)
{
    unsigned char index = remap_channel(channel);
    if (index > 3)
        return channel;
    pq_set_color_fill_enable(COLOR_FILL_OFF);
    if (blank)
        pq_block_blank_with_color((channel_records[index].status_word >> CHANNEL_PORT_SHIFT) & 0xf, red, green, blue);
    pq_block_set_blank_color((channel_records[index].status_word >> CHANNEL_PORT_SHIFT) & 0xf, red, green, blue);
    pq_block_set_fill_color((channel_records[index].status_word >> CHANNEL_PORT_SHIFT) & 0xf, red, green, blue);
    return pq_set_port_fill_color((channel_records[index].status_word >> CHANNEL_PORT_SHIFT) & 0xf, red, green, blue);
}
