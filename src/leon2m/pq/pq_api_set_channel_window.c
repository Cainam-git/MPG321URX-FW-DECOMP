/* pq_api_set_channel_window  (FUN_a01470fc)
 *
 * Store the picture window index for a channel.
 * Name basis: derived - bits 4..7 of the first word of the channel record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01470fc @ 0xa01470fc-0xa01471a0 (41 words), flags -mcpu=v8 -O3 -g.
 * Source form: the channel check is a static switch helper returning -1 for any other value, stored in an unsigned
 * char; the window field is a 4-bit bit-field.
 */

/* The channel record (0x78 bytes): the window field is bits 4..7 of its first word. */
struct channel_window { unsigned int hi24 : 24; unsigned int window : 4; unsigned int low4 : 4; unsigned char rest[0x74]; };
extern struct channel_window channel_records[4];
extern int dbg_printf();

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
 * Store the picture window of a channel: the low 4 bits of window go to bits 4-7 of its status word.
 *
 *   channel  0..3; a larger value prints "SYS remapping channel OOR" and uses channel 0
 *
 * Nothing in the firmware calls this routine; pq_api_get_channel_window reads the field back.
 */
void pq_api_set_channel_window(unsigned char channel, unsigned int window)
{
    unsigned char index = remap_channel(channel);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    channel_records[index].window = window;
}
