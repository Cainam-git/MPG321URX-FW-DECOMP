/* osd_api_set_cell_size_mode  (FUN_a0146298)
 *
 * Select one of five character cell modes for a menu layer.
 * Name basis: descriptive - forwards to osd_set_cell_size_mode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146298, flags -mcpu=v8 -O3 -g; leaf (sibling call).
 * Jump table for cases 0..4. GCC copies the call into every case (order in the image 3, 4, 0, 1, 2; the default
 * enters case 3's copy after its 'mov 3'), each copy masking the layer to a byte. k is an unsigned char initialised
 * to mode in its declaration, the switch assigns k in every case (default: k = mode), and one call follows.
 */
extern void osd_set_cell_size_mode(unsigned int mode, unsigned int layer);

/* Select the cell size mode (0..4) of a menu layer; calls osd_set_cell_size_mode. A mode above 4 is passed on
 * unchanged.
 *   mode:  cell size mode
 *   layer: menu layer number
 * Called by osd_setup_window_full and osd_draw_factory_info_page, which pass mode 4 for the main menu layer.
 */
void osd_api_set_cell_size_mode(unsigned char mode, unsigned char layer)
{
    unsigned char k = mode;
    switch (mode) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 1;
        break;
    case 2:
        k = 2;
        break;
    case 3:
        k = 3;
        break;
    case 4:
        k = 4;
        break;
    default:
        k = mode;
        break;
    }
    osd_set_cell_size_mode(k, layer);
}
