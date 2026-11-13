/* osd_set_layout  (FUN_a00b50d8)
 *
 * Configure the menu layer for a layout and load its glyphs.
 *   layout: layout 0..5
 * Note: Layouts 0 main menu, 2, 3 overlays/messages, 4, 5; see font_load_layout<N>_glyphs.
 * Name basis: derived - called by App_Initialize, osd_factory_activate_item, osd_show_screen_overlays
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b50d8 @ 0xa00b50d8, flags -mcpu=v8 -O3 -g. Callers: App_Initialize, osd_factory_activate_item, sys_end_logo_restore_picture,
 * osd_show_screen_overlays, osd_draw_overlay_position_preview and others.
 * Source form: an if/else-if chain in the order 0, 2, 3, 5, 4; osd_api_cell_count_plus_one is declared int and
 * its result is cast to unsigned short where it is passed on.
 */
extern unsigned char osd_request_bits;
extern void osd_api_set_cell_size_mode(int, int);
extern void osd_api_set_layer_byte_pair(int, int, int);
extern void osd_load_layer_lookup_tables(void);
extern int osd_api_cell_count_plus_one(int, int);
extern void osd_api_write_reg24_group(int, int, int);
extern unsigned short panel_api_get_active_size(int);
extern void font_load_layout0_glyphs(void);
extern void font_load_layout2_glyphs(void);
extern void font_load_layout3_glyphs(void);
extern void font_load_layout5_glyphs(void);
extern void font_load_layout4_glyphs(void);

#define OSD_REQUEST_LAYOUT_CHANGED 0x80   /* bit 7 of osd_request_bits, set on every call */
#define CELL_WIDTH 24                     /* width of a cell in panel pixels */

/* Set up the menu layer for one of the layouts and load the glyphs that layout uses.
 *   layout: 0 main menu, 60 x 23 cells; 2 input quick menu, 22 x 17 cells (also the Navi key quick menus);
 *           3 screen overlays and messages, panel width / 24 + 1 columns by 61 rows;
 *           4 8 x 3 cells; 5 panel protect prompt, 56 x 27 cells. Layout 1 (and any other value) only runs
 *           the common part.
 * Common part: set bit 7 of osd_request_bits, select cell size mode 4, store the byte pair (1, 1) and load the
 * lookup tables of the layers. Then, for layouts 0, 2, 3 and 5, register group 0 of the layer is written with
 * columns * rows + 1 and groups 1 and 3 with fixed values (layout 0: 0xfec0 and 0x12fb0; 2 and 3: 0xf260
 * and 0x11c90; 5: 0xd400 and 0xfe30); layout 3 also writes 10 * 10 + 1 to group 0 of layer 1. Layout 4 writes
 * only group 1, the value 8 * 3 + 1. Last, the glyphs of the layout are loaded. */
void osd_set_layout(unsigned char layout)
{
    int cell_count;

    osd_request_bits |= OSD_REQUEST_LAYOUT_CHANGED;
    osd_api_set_cell_size_mode(4, 0);
    osd_api_set_layer_byte_pair(1, 1, 0);
    osd_load_layer_lookup_tables();
    if (layout == 0) {
        cell_count = osd_api_cell_count_plus_one(0x3c, 0x17);
        osd_api_write_reg24_group(0, (unsigned short)cell_count, 0);
        osd_api_write_reg24_group(1, 0xfec0, 0);
        osd_api_write_reg24_group(3, 0x12fb0, 0);
        font_load_layout0_glyphs();
    } else if (layout == 2) {
        cell_count = osd_api_cell_count_plus_one(0x16, 0x11);
        osd_api_write_reg24_group(0, (unsigned short)cell_count, 0);
        osd_api_write_reg24_group(1, 0xf260, 0);
        osd_api_write_reg24_group(3, 0x11c90, 0);
        font_load_layout2_glyphs();
    } else if (layout == 3) {
        cell_count = osd_api_cell_count_plus_one((unsigned short)(panel_api_get_active_size(0) / CELL_WIDTH + 1), 0x3d);
        osd_api_write_reg24_group(0, (unsigned short)cell_count, 0);
        osd_api_write_reg24_group(1, 0xf260, 0);
        osd_api_write_reg24_group(3, 0x11c90, 0);
        cell_count = osd_api_cell_count_plus_one(10, 10);
        osd_api_write_reg24_group(0, (unsigned short)cell_count, 1);
        font_load_layout3_glyphs();
    } else if (layout == 5) {
        cell_count = osd_api_cell_count_plus_one(0x38, 0x1b);
        osd_api_write_reg24_group(0, (unsigned short)cell_count, 0);
        osd_api_write_reg24_group(1, 0xd400, 0);
        osd_api_write_reg24_group(3, 0xfe30, 0);
        font_load_layout5_glyphs();
    } else if (layout == 4) {
        cell_count = osd_api_cell_count_plus_one(8, 3);
        osd_api_write_reg24_group(1, (unsigned short)cell_count, 0);
        font_load_layout4_glyphs();
    }
}
