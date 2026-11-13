/* pq_api_enable_channel_window  (FUN_a0146ef4)
 *
 * Switch the picture window of a channel on or off.
 * Name basis: derived - window index from the channel record; set / clear of the window enable bits; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146ef4 @ 0xa0146ef4-0xa0146fdc (58 words), flags -mcpu=v8 -O3 -g.
 * Source form: the channel check is a static switch helper returning -1 for any other value, stored in an unsigned
 * char; the window field is a 4-bit bit-field read into an unsigned int in its own block; both calls are tail calls.
 */

#define WINDOW_NONE 4       /* the window field of the channel record, 4 = no window */

/* The channel record (0x78 bytes): the window field is bits 4..7 of its first word. */
struct channel_window { unsigned int hi24 : 24; unsigned int window : 4; unsigned int low4 : 4; unsigned char rest[0x74]; };
extern struct channel_window channel_records[4];
extern void pq_window_enable(unsigned int);
extern void pq_window_disable(unsigned int);
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
 * Switch the picture window of a channel on or off.
 *
 *   channel  0..3; a larger value prints "SYS remapping channel OOR" and uses channel 0
 *   on       1: pq_window_enable; any other value: pq_window_disable
 *
 * A channel without a window (WINDOW_NONE) is left alone. Nothing in the firmware calls this routine;
 * pq_api_enable_window does the same for a window number.
 */
void pq_api_enable_channel_window(unsigned char channel, unsigned char on)
{
    unsigned char index;

    index = remap_channel(channel);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    {
        unsigned int window = channel_records[index].window;

        if (window != WINDOW_NONE) {
            if (on == 1)
                pq_window_enable(window);
            else
                pq_window_disable(window);
        }
    }
}
