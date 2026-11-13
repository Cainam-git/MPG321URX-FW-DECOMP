/* osd_api_set_window_blend_level  (FUN_a01469e0)
 *
 * Select window 0..7 of a menu layer and set its level.
 * Name basis: descriptive - forwards to osd_set_window_blend_level; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01469e0 @ 0xa01469e0-0xa0146a80 (40 words), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with eight cases (jump table at 0xe3340); a window number above 7 skips the call. The
 * level call is a tail call.
 */
extern void osd_select_window(unsigned int window, unsigned char layer);
extern void osd_set_window_blend_level(unsigned char level, unsigned char layer);

/* Make `window` (0..7) the selected window of the menu layer, then set the level (0..8) with
 * osd_set_window_blend_level. Nothing calls this routine and no stored address points at it. */
void osd_api_set_window_blend_level(unsigned char window, unsigned char level, unsigned char layer)
{
    switch (window) {
    case 0: osd_select_window(0, layer); break;
    case 1: osd_select_window(1, layer); break;
    case 2: osd_select_window(2, layer); break;
    case 3: osd_select_window(3, layer); break;
    case 4: osd_select_window(4, layer); break;
    case 5: osd_select_window(5, layer); break;
    case 6: osd_select_window(6, layer); break;
    case 7: osd_select_window(7, layer); break;
    }
    osd_set_window_blend_level(level, layer);
}
