/* pq_api_set_window_rect  (FUN_a0146e2c)
 *
 * Select the picture window of a channel and write its four 16-bit coordinates.
 * Name basis: derived - window index from the channel record (4 = none); registers 0xCF00EC88..0xCF00ECA4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146e2c @ 0xa0146e2c-0xa0146ef4 (50 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the channel helper lists case 1 before case 0 (the firmware's case tree is rooted at 1);
 *  - the window field is read as a shift and mask of the whole first word;
 *  - pq_window_set_rect takes four unsigned short arguments and is a tail call.
 */

/* The channel record (0x78 bytes), up to the field used here. */
struct channel_record { unsigned int status_word; unsigned char rest[0x74]; };   /* +0: window in bits 4-7 */
extern struct channel_record channel_records[4];
extern int dbg_printf(const char *fmt, ...);
extern int pq_select_window(int);
extern void pq_window_set_rect(unsigned short, unsigned short, unsigned short, unsigned short);

#define CHANNEL_WINDOW_SHIFT 4          /* the window is bits 4-7 of the channel's status word */
#define WINDOW_NONE          4          /* the window field of the channel record, 4 = no window */

/* Channel numbers 0 to 3 stay as they are, any other value becomes -1 (read as 0xFF in an unsigned char). */
static int remap_channel(int channel)
{
    switch (channel) {
    case 1: return 1;
    case 0: return 0;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Select the picture window of a channel (pq_select_window) and write its four coordinates
 * (pq_window_set_rect, registers 0xCF00EC88..0xCF00ECA4, low byte then high byte of x, width, y, height).
 *
 *   channel        0..3; a larger value prints "SYS remapping channel OOR" and uses channel 0
 *   x, y           the only caller passes 0, 0
 *   width, height  the only caller passes the two active sizes of the panel timing row (panel_api_get_active_size
 *                  0 and 1)
 *
 * A channel without a window (WINDOW_NONE) is left alone. Called by APPActionDispatcher for the main channel
 * before the picture is shown (APPATN_BEFOREDISPLAY_MAIN).
 */
void pq_api_set_window_rect(unsigned char channel, unsigned short x, unsigned short y, unsigned short width, unsigned short height)
{
    unsigned char index = (unsigned char)remap_channel(channel);
    unsigned int status;
    unsigned int window;

    if (index > 3) {
        dbg_printf("SYS remapping channel OOR\r\n");
        index = 0;
    }

    status = channel_records[index].status_word;
    window = (status >> CHANNEL_WINDOW_SHIFT) & 0xf;

    if (window == WINDOW_NONE)
        return;

    pq_select_window(window);
    pq_window_set_rect(x, y, width, height);
}
