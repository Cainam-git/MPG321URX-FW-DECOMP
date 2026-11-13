/* osd_draw_slider_label_row  (FUN_a00b60cc)
 *
 * Draw the label cells of a slider row in active or normal colours.
 *   active
 * Note: No reference to it was found; same block as inside the slider drawers.
 * Name basis: descriptive - row 6, columns 0x28..0x32
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b60cc @ 0xa00b60cc, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the cell value is set in both arms (as in the slider drawers); the parameter is tested as
 * (param & 0xff) with no entry mask; prototypes take unsigned char/unsigned int arguments.
 */
extern void osd_draw_key_guide(unsigned int row_group, unsigned int guide_kind);
extern void osd_api_fill_cells(unsigned int column, unsigned int row, unsigned char count, unsigned int value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned int plane, unsigned int column, unsigned int row, unsigned char count, unsigned char value, unsigned char layer);

#define PLANE_0              0
#define MENU_LAYER_MAIN      0
#define SLIDER_ROW           6
#define CELL_SLIDER_ACTIVE   0x742   /* cell value of the row while its slider is being adjusted */
#define CELL_BLANK           0x792

/* Draw the label cells of the slider row 6 (the same block the slider drawers contain): three cells at
 * column 0x28 and one cell each at columns 0x2B and 0x32, with cell value CELL_SLIDER_ACTIVE and the key guide
 * kind 3 when 'active' is non-zero, or CELL_BLANK and key guide kind 2 when it is zero. The cells at columns
 * 0x2B and 0x32 also get glyph bytes 0x3F and 0x40 in plane 0. Nothing in the image calls it. */
void osd_draw_slider_label_row(unsigned int active)
{
    unsigned short cell_value;

    if ((active & 0xff) != 0) {
        cell_value = CELL_SLIDER_ACTIVE;
        osd_draw_key_guide(1, 3);
    } else {
        cell_value = CELL_BLANK;
        osd_draw_key_guide(1, 2);
    }
    osd_api_fill_cells(0x28, SLIDER_ROW, 3, cell_value, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x2b, SLIDER_ROW, 1, cell_value, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, 0x2b, SLIDER_ROW, 1, 0x3f, 0);
    osd_api_fill_cells(0x32, SLIDER_ROW, 1, cell_value, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, 0x32, SLIDER_ROW, 1, 0x40, 0);
}
