/* osd_api_set_text_mode  (FUN_a0146b6c)
 *
 * Store the text drawing mode 1, 2 or 0 of a menu layer.
 * Name basis: descriptive - forwards to osd_set_text_mode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146b6c @ 0xa0146b6c-0xa0146bb0 (17 words), flags -mcpu=v8 -O3 -g.
 * The three calls stay separate in the firmware (one per selected value), each a tail call with %o7 saved in %g1.
 */
extern void osd_set_text_mode(unsigned char mode, unsigned char layer);

/* Store the text mode of the menu layer (0 or 1): 1 and 2 are kept, any other value is stored as 0. The modes
 * are TEXT_ALIGN_LEFT 0, TEXT_ALIGN_RIGHT 1 and TEXT_ALIGN_CENTRE 2 (see osd_ram_write_index_run). */
void osd_api_set_text_mode(unsigned char mode, unsigned char layer)
{
    switch (mode) {
    case 1: osd_set_text_mode(1, layer); break;
    case 2: osd_set_text_mode(2, layer); break;
    default: osd_set_text_mode(0, layer); break;
    }
}
