/* osd_api_set_window_rect  (FUN_a0146870)
 *
 * Select window 0..7 of a menu layer and write its rectangle.
 * Name basis: derived - window index to bits 0-2 of register 0xA5, then the rectangle write that waits for a
 *   frame
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146870 @ 0xa0146870-0xa014692c (47 words), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with eight cases (jump table at 0xe3300), each a call with the constant window number; a
 * window number above 7 skips the call. The rectangle write is a tail call.
 */
extern void osd_select_window(unsigned int window, unsigned char layer);
extern void osd_set_window_rect_wait(unsigned short x, unsigned short y, unsigned short last_x,
                                     unsigned short last_y, unsigned char layer);

/* Make `window` (0..7) the selected window of the menu layer, then write its rectangle with
 * osd_set_window_rect_wait (x, y = left and top cell; last_x, last_y = last cell; that routine waits for a sync
 * pulse). A window number above 7 leaves the selection as it is. */
void osd_api_set_window_rect(unsigned char window, unsigned short x, unsigned short y, unsigned short last_x,
                  unsigned short last_y, unsigned char layer)
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
    osd_set_window_rect_wait(x, y, last_x, last_y, layer);
}
