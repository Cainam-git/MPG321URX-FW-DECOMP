/* pq_api_enable_color_matrix  (FUN_a0145ee8)
 *
 * Switch the colour matrix on for the picture window of a channel, or off.
 * Name basis: descriptive - option bit 0 of the matrix flags; selects the channel's picture window when
 *   switching on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145ee8 @ 0xa0145ee8-0xa0145fac (49 words), flags -mcpu=v8 -O3 -g.
 * Source form: the channel check is a static switch helper returning -1 for any other value, stored in an unsigned
 * char (-1 becomes 0xFF, above 3); the window field is a 4-bit bit-field read into an unsigned int in its own block.
 */

#define WINDOW_NONE 4       /* the window field of the channel record, 4 = no window */

/* The channel record (0x78 bytes): the window field is bits 4..7 of its first word. */
struct channel_window { unsigned int hi24 : 24; unsigned int window : 4; unsigned int low4 : 4; unsigned char rest[0x74]; };
extern struct channel_window channel_records[4];
extern void pq_select_window(unsigned int);
extern void pq_color_matrix_set_enable_flag(int);
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
 * Set or clear the on flag of the colour matrix (pq_color_matrix_flags bit 0).
 *
 *   channel  0..3; a larger value prints "SYS remapping channel OOR" and uses channel 0
 *   off      non-zero: clear the flag and return; 0: set it
 *
 * When switching on, the channel's picture window is also selected (pq_select_window), unless the channel has
 * none (WINDOW_NONE). The flag reaches the hardware with the next pq_color_matrix_write.
 * Every caller passes channel 0 and off 0: App_Initialize, ddc_apply_maker_vcp_set, pq_user_apply_color_gain and
 * pq_user_apply_color_settings.
 */
void pq_api_enable_color_matrix(unsigned char channel, unsigned char off)
{
    unsigned char index;

    if (off) {
        pq_color_matrix_set_enable_flag(0);
        return;
    }
    pq_color_matrix_set_enable_flag(1);
    index = remap_channel(channel);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    {
        unsigned int window = channel_records[index].window;

        if (window != WINDOW_NONE)
            pq_select_window(window);
    }
}
