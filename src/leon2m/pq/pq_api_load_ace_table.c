/* pq_api_load_ace_table  (FUN_a01474b0)
 *
 * Select the picture window of a channel and write an ACE curve to it.
 * Returns: the channel number when the channel has no window; otherwise the result of pq_ace_write_curve
 * Name basis: descriptive - pq_select_window, then pq_ace_write_curve (table written through
 *   0xCF00EEC4/0xCF00EEC8); called from SetThemeMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01474b0 @ 0xa01474b0, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - six int-sized parameters, and the callee declared with six: curve goes in its first two argument registers
 *    and the parameters pass_2..pass_5 in the next four (pq_ace_write_curve reads only the first);
 *  - the channel helper lists case 1 before case 0 (the firmware's case tree is rooted at 1), and is called with
 *    'channel & 0xff';
 *  - the window field is read as a shift and mask of the whole first word; the result of the tail call is
 *    returned.
 */

/* The channel record (0x78 bytes), up to the field used here. */
struct channel_record { unsigned int status_word; unsigned char rest[0x74]; };   /* +0: window in bits 4-7 */
extern struct channel_record channel_records[4];
extern int dbg_printf(const char *fmt, ...);
extern int pq_select_window(int);
extern int pq_ace_write_curve(int, int, int, int, int, int);

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
 * Select the picture window of a channel and write an ACE curve to it (pq_ace_write_curve).
 *
 *   channel  0..3 (low byte); a larger value prints "SYS remapping channel OOR" and uses channel 0
 *   curve    address of the curve (struct ace_curve: last point number, then the 16-bit points); 0 writes
 *            pq_ace_default_curve
 *
 * A channel without a window (WINDOW_NONE) is left alone and the channel number is returned; otherwise the
 * value is what pq_ace_write_curve leaves. Callers: SetThemeMode (the ACE table of a theme preset, channels 0
 * and 1) and pq_apply_table_entry_both_channels (channels 1 and 0).
 */
int pq_api_load_ace_table(unsigned int channel, unsigned int curve, int pass_2,
                 unsigned int pass_3, unsigned int pass_4, unsigned int pass_5)
{
    unsigned char index = (unsigned char)remap_channel(channel & 0xff);
    unsigned int status;
    unsigned int window;

    if (index > 3) {
        dbg_printf("SYS remapping channel OOR\r\n");
        index = 0;
    }

    status = channel_records[index].status_word;
    window = (status >> CHANNEL_WINDOW_SHIFT) & 0xf;

    if (window == WINDOW_NONE) {
        return channel & 0xff;
    }

    pq_select_window(window);
    return pq_ace_write_curve(curve, curve, pass_2, pass_3, pass_4, pass_5);
}
