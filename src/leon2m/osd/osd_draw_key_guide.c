/* osd_draw_key_guide  (FUN_a00a9468)
 *
 * Draw the key guide icons at the right edge for a menu level.
 *   group: row group
 *   mode: guide kind
 * Name basis: derived - icons in column 0x37..0x3A; key guide texts 0x1928B0
 *   'Move|Enter|Switch|Adjust|Select|Save|Exit|Back'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a9468 @ 0xa00a9468, flags -mcpu=v8 -O3 -g.
 * Source form: an if / else-if chain in the order 6, 5, 4, 0, 1, 2, 3 (mode 6 runs its clear loop in the first
 * arm), followed by a separate "if (mode != 6)" around the loops of the other modes; the compiler threads the
 * known modes past the second test. The three cell values start as 0 (mode 4 leaves them 0).
 */
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN 0
#define PLANE_0         0
#define KEY_GUIDE_COLUMN 0x37    /* the guide occupies columns 0x37..0x3A */
#define CELL_BLANK      0x792

/* Draw the key guide cells at the right edge of the menu, in one of three
 * row groups: group 2 starts at row 6, group 0 at row 0xB, any other group at
 * row 0x10.
 *   mode 6:   clear 4 rows of 4 cells (CELL_BLANK, glyph byte 0);
 *   modes 0..3 and 5: three rows, with the cell at column 0x37 set to
 *             edge_left, the cell at column 0x3A set to edge_right and the two
 *             cells at 0x38, 0x39 set to middle. The values by mode are
 *             5: 0x399E / 0x792 / 0x992 (middle / left / right), 0: 0x3E9E /
 *             0x992 / 0x992, 1: 0x439E / 0x792 / 0x792, 2: 0x489E / 0x992 /
 *             0x792, 3: 0x4D9E / 0x992 / 0x992;
 *   mode 4 and any other value: the same three rows, all set to 0.
 * Called by the menu page drawers and key handlers. */
void osd_draw_key_guide(unsigned char group, unsigned char mode)
{
    unsigned char base;
    unsigned char k;
    unsigned short middle = 0;
    unsigned short edge_left = 0;
    unsigned short edge_right = 0;
    if (group == 2)
        base = 6;
    else
        base = group == 0 ? 0xb : 0x10;
    if (mode == 6) {
        for (k = 0; k <= 3; k++) {
            osd_api_fill_cells(KEY_GUIDE_COLUMN, base + k, 4, CELL_BLANK, MENU_LAYER_MAIN);
            osd_api_fill_cell_bytes(PLANE_0, KEY_GUIDE_COLUMN, base + k, 4, 0, MENU_LAYER_MAIN);
        }
    } else if (mode == 5) {
        middle = 0x399e; edge_left = 0x792; edge_right = 0x992;
    } else if (mode == 4) {
    } else if (mode == 0) {
        middle = 0x3e9e; edge_left = 0x992; edge_right = 0x992;
    } else if (mode == 1) {
        middle = 0x439e; edge_left = 0x792; edge_right = 0x792;
    } else if (mode == 2) {
        middle = 0x489e; edge_left = 0x992; edge_right = 0x792;
    } else if (mode == 3) {
        middle = 0x4d9e; edge_left = 0x992; edge_right = 0x992;
    }
    if (mode != 6) {
        for (k = 0; k <= 2; k++) {
            osd_api_fill_cells(KEY_GUIDE_COLUMN, base + k, 1, edge_left, MENU_LAYER_MAIN);
            osd_api_fill_cells(0x3a, base + k, 1, edge_right, MENU_LAYER_MAIN);
        }
        for (k = 0; k <= 2; k++)
            osd_api_fill_cells(0x38, base + k, 2, middle, MENU_LAYER_MAIN);
    }
}
