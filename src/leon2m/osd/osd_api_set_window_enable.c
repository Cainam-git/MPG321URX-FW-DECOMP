/* osd_api_set_window_enable  (FUN_a0146c40)
 *
 * Switch one window of a menu layer on or off, or all eight.
 * Name basis: derived - forwards to osd_enable_window / osd_disable_window
 *
 * Matching notes
 * --------------
 * leon2m @ 0xa0146c40-0xa0146dc0 (96 words), flags -mcpu=v8 -O3 -g.
 * Source form: one case per window 0..7 (jump table at 0x000e3360), each with its own on test and tail calls.
 * The default case enables windows 0..7 one by one when `on` is set, and otherwise makes the single call
 * osd_disable_window(8, blk).
 */
extern void osd_enable_window(unsigned int, unsigned char);
extern void osd_disable_window(unsigned int, unsigned char);

/*
 * Switch a window of menu layer `blk` on or off.
 *   ch  : window 0..7 = that window; any other value = all eight windows
 *   on  : non-zero = switch on, zero = switch off
 *   blk : menu layer 0 or 1
 * Switching all windows off is one call to osd_disable_window with 8 (its "all" value); switching all
 * on is eight calls, one per window.
 * Called with ch = 8 and on = 0 to switch every window off (e.g. osd_setup_window_short), and with window 6 (the
 * split line window) by the split-view routines.
 */
void osd_api_set_window_enable(unsigned char ch, unsigned char on, unsigned char blk)
{
    switch (ch) {
    case 0:
        if (on)
            osd_enable_window(0, blk);
        else
            osd_disable_window(0, blk);
        break;
    case 1:
        if (on)
            osd_enable_window(1, blk);
        else
            osd_disable_window(1, blk);
        break;
    case 2:
        if (on)
            osd_enable_window(2, blk);
        else
            osd_disable_window(2, blk);
        break;
    case 3:
        if (on)
            osd_enable_window(3, blk);
        else
            osd_disable_window(3, blk);
        break;
    case 4:
        if (on)
            osd_enable_window(4, blk);
        else
            osd_disable_window(4, blk);
        break;
    case 5:
        if (on)
            osd_enable_window(5, blk);
        else
            osd_disable_window(5, blk);
        break;
    case 6:
        if (on)
            osd_enable_window(6, blk);
        else
            osd_disable_window(6, blk);
        break;
    case 7:
        if (on)
            osd_enable_window(7, blk);
        else
            osd_disable_window(7, blk);
        break;
    default:
        if (on) {
            osd_enable_window(0, blk);
            osd_enable_window(1, blk);
            osd_enable_window(2, blk);
            osd_enable_window(3, blk);
            osd_enable_window(4, blk);
            osd_enable_window(5, blk);
            osd_enable_window(6, blk);
            osd_enable_window(7, blk);
        } else
            osd_disable_window(8, blk);
        break;
    }
}
