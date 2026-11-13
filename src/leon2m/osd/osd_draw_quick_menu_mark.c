/* osd_draw_quick_menu_mark  (FUN_a00b3614)
 *
 * Draw or clear the current-value mark in a quick menu row.
 *   entry: entry number; 4 and up are reduced by 4, the mark row is entry * 2 + 5
 *   on: draw or clear
 * Name basis: descriptive - called by osd_draw_night_vision_quick_menu / osd_draw_crosshair_quick_menu
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3614 @ 0xa00b3614, flags -mcpu=v8 -O3 -g.
 * Source form: one loop with the 'on' test inside; the compiler unswitches it into two loops, and the
 * resulting block order gives the firmware's register choice (the 'on == 0' arm comes first).
 */
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define PLANE_0                  0
#define MARK_COLUMN              4       /* the mark is two cells wide: columns 4 and 5 */
#define MARK_GLYPH               0x1c    /* glyphs 0x1C and 0x1D */
#define QUICK_MENU_PAGE_ENTRIES  4

/* Draw or clear the two-cell mark that shows the stored entry of a quick menu list.
 *   entry: entry number; numbers from 4 up are reduced by 4 (the second page starts again at the top row).
 *   on:    non-zero draws glyphs 0x1C, 0x1D; zero writes glyph 0 over both cells.
 * The mark sits on row entry * 2 + 5, the middle row of the entry. Called by the Night Vision and Crosshair
 * quick menu drawers. */
void osd_draw_quick_menu_mark(unsigned char entry, unsigned char on)
{
    unsigned char i;
    unsigned short row;

    if (entry > QUICK_MENU_PAGE_ENTRIES - 1)
        entry -= QUICK_MENU_PAGE_ENTRIES;
    row = entry * 2 + 5;
    for (i = 0; i < 2; i++)
        if (!on)
            osd_api_fill_cell_bytes(PLANE_0, i + MARK_COLUMN, row, 1, 0, 0);
        else
            osd_api_fill_cell_bytes(PLANE_0, i + MARK_COLUMN, row, 1, i + MARK_GLYPH, 0);
}
