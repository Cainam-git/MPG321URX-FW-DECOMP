/* pq_api_config_ace  (FUN_a014737c)
 *
 * Configure ACE for the picture window of a channel.
 * Name basis: proven - forwards to the routine that prints 'Config ACE'; called from SetThemeMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014737c @ 0xa014737c-0xa01474b0 (77 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the channel check is a static switch helper returning -1 for any other value, stored in an unsigned char;
 *  - the 3-byte argument is a local struct passed by value, its fields filled in the order sum_count,
 *    config_bit6, config_bit7, after the selected window is read.
 */

#define WINDOW_NONE 4       /* the window field of the channel record, 4 = no window */

/* The channel record (0x78 bytes): the window field is bits 4..7 of its first word. */
struct channel_window { unsigned int hi24 : 24; unsigned int window : 4; unsigned int low4 : 4; unsigned char rest[0x74]; };
/* The argument of pq_ace_configure. */
struct ace_config_arg {
    unsigned char config_bit7;          /* goes to bit 7 of ACE_CONFIG */
    unsigned char config_bit6;          /* goes to bit 6 of ACE_CONFIG */
    unsigned char sum_count;            /* 8 and 16 select codes 1 and 2 in ACE_CONFIG bits 2..3; others code 0 */
};
extern struct channel_window channel_records[4];
extern int dbg_printf();
extern unsigned char pq_get_selected_window(void);
extern void pq_select_window(unsigned char);
extern void pq_ace_configure(struct ace_config_arg);

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
 * Configure ACE (pq_ace_configure) for the picture window of a channel, then select the window that was
 * selected before again.
 *
 *   channel  0..3; a larger value prints "SYS remapping channel OOR" and uses channel 0
 *   mode     gives sum_count: 0 -> 4, 1 -> 8, 3 -> 0x20, any other value -> 0x10
 *   bit7     config_bit7 of the argument
 *   bit6     config_bit6 of the argument
 *
 * A channel without a window (WINDOW_NONE) is left alone. The only caller, SetThemeMode, passes mode 2 and two
 * zeros for channel 0 and channel 1, each time before it loads the ACE table of the theme preset.
 */
void pq_api_config_ace(unsigned char channel, unsigned char mode, unsigned char bit7, unsigned char bit6)
{
    unsigned char index, sum_count, previous_window;
    struct ace_config_arg arg;

    index = remap_channel(channel);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    if (channel_records[index].window != WINDOW_NONE) {
        switch (mode) {
        case 0: sum_count = 4; break;
        case 1: sum_count = 8; break;
        case 3: sum_count = 0x20; break;
        default: sum_count = 0x10; break;
        }
        previous_window = pq_get_selected_window();
        arg.sum_count = sum_count;
        arg.config_bit6 = bit6;
        arg.config_bit7 = bit7;
        pq_select_window(channel_records[index].window);
        pq_ace_configure(arg);
        pq_select_window(previous_window);
    }
}
