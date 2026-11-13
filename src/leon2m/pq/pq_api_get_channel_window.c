/* pq_api_get_channel_window  (FUN_a0147064)
 *
 * Return the picture window index stored for a channel.
 * Returns: window index, 4 = none
 * Name basis: derived - bits 4..7 of the first word of the channel record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147064 @ 0xa0147064-0xa01470fc (38 words), flags -mcpu=v8 -O3 -g.
 * Source form: the channel check is a static switch helper returning -1 for any other value, stored in an unsigned
 * char; the window field is read as a shift and mask of the whole first word. sys_api_get_channel_flag29 has the
 * same code for bit 29 of the word at +0x70.
 */

/* The channel record (0x78 bytes). */
struct channel_record {
    unsigned int status_word;           /* +0: window in bits 4-7 */
    unsigned char pad[0x6c];
    unsigned int flags;                 /* +0x70 */
    unsigned int display_delay;         /* +0x74 */
};
extern struct channel_record channel_records[4];
extern int dbg_printf();

#define CHANNEL_WINDOW_SHIFT 4          /* the window is bits 4-7 of the channel's status word */

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
 * Return the picture window of a channel (bits 4-7 of its status word; 4 = WINDOW_NONE).
 *
 *   channel  0..3; a larger value prints "SYS remapping channel OOR" and uses channel 0
 *
 * Nothing in the firmware calls this routine; pq_api_set_channel_window is its setter.
 */
unsigned char pq_api_get_channel_window(unsigned char channel)
{
    unsigned char index = remap_channel(channel);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    return (channel_records[index].status_word >> CHANNEL_WINDOW_SHIFT) & 0xf;
}
