/* osd_api_configure_window_reg30  (FUN_a014692c)
 *
 * Select window 0..7 of a menu layer and program register group 0x30.
 * Name basis: descriptive - forwards to osd_configure_reg30_group
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014692c @ 0xa014692c-0xa01469e0 (180 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with eight cases (jump table at 0xe3320); a window number above 7 skips the call. The
 * layer (the 7th parameter, read from the stack once at entry) is also the 6th argument of the tail call, which is
 * why the firmware keeps it in %i5 and the fifth value in %l0.
 */
extern void osd_select_window(unsigned int window, unsigned char layer);
extern void osd_configure_reg30_group(unsigned char sel, unsigned int b, unsigned int c, unsigned char d, unsigned int e, unsigned char layer);

/* Make `window` (0..7) the selected window of the menu layer, then pass the five values and the layer on to
 * osd_configure_reg30_group (sel, b, c, d, e as described there). A window number above 7 leaves the selection
 * as it is. */
void osd_api_configure_window_reg30(unsigned char window, unsigned char sel, unsigned char b, unsigned char c, unsigned char d,
                  unsigned char e, unsigned char layer)
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
    osd_configure_reg30_group(sel, b, c, d, e, layer);
}
