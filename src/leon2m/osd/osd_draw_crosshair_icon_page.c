/* osd_draw_crosshair_icon_page  (FUN_a00ab0e0)
 *
 * Draw the Smart Crosshair icon choices.
 *   mode: draw mode
 * Note: Loads the icon glyphs (font_load_crosshair_page_icons) unless mode is 2.
 * Name basis: derived - texts 0x18F984; called by osd_open_crosshair_icon
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ab0e0 @ 0xa00ab0e0, flags -mcpu=v8 -O3 -g.
 * Source form: the mode test sits inside the loop (the compiler unswitches it into two loops); the
 * crosshair_icon test is an if/else with 'first_row = 5' written before 'first_icon = 7' in the nonzero arm.
 */
struct user_settings_head {
    unsigned char pad_0x0[8];
    unsigned char language;                     /* +8: text index = entry * 29 + language */
    unsigned char pad_0x9[0x190 - 9];
    unsigned char crosshair_icon;               /* +0x190: the Smart Crosshair icon */
};
extern struct user_settings_head user_settings;
extern unsigned int osd_crosshair_item_texts[];
extern void font_load_crosshair_page_icons(void);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char, unsigned char,
                         unsigned char);

#define ICON_MODE_SMALL        2        /* the other layout of the page: icons in column 10, no glyph loading */
#define ICON_COLUMN_MAIN       0x2d     /* column of the icon cells in the main layout */
#define ICON_COLUMN_SMALL      10       /* ... in mode 2 */
#define ICON_CELL_ATTR         0x796
#define ICON_FIRST_GLYPH       0x11     /* the first icon is 2 cells wide and uses glyphs 0x11, 0x12; each next one 2 more */
#define ICON_LAST              12       /* icons 0..12 in the main layout */

/*
 * Draw the icon choices of the Smart Crosshair page.
 *
 *   mode  2: the other layout of the page (see below); anything else: the page of the main menu
 *
 * Main layout (the only caller passes 0): load the page's icon glyphs (font_load_crosshair_page_icons), select
 * glyph write address 299 and text mode 2, write the text of entry 0 of osd_crosshair_item_texts at column
 * 0x2a, row 6, then draw icons 0..12 as two-cell runs in column 0x2d on the rows 7..19, glyphs
 * 0x11 + 2 * icon.
 *
 * Mode 2: no glyph loading; the icons are drawn in column 10. When crosshair_icon >> 2 is not 0, icons 7..12 go
 * on rows 5..10; otherwise the title text is written at column 8, row 6 and icons 0..6 go on rows 8..14. In
 * both cases the glyphs count from 0x11 again for the first icon drawn.
 */
void osd_draw_crosshair_icon_page(unsigned char mode)
{
    unsigned char first_icon, i, first_row, column;

    if (mode == ICON_MODE_SMALL) {
        column = ICON_COLUMN_SMALL;
        if (user_settings.crosshair_icon >> 2) {
            first_row = 5;
            first_icon = 7;
        } else {
            first_icon = 0;
            first_row = 8;
        }
        if (first_icon == 0)
            osd_draw_text(0, 8, 6, 0xd, osd_get_text(osd_crosshair_item_texts, user_settings.language), 0);
    } else {
        column = ICON_COLUMN_MAIN;
        font_load_crosshair_page_icons();
        osd_api_set_glyph_write_address(299, 0);
        osd_api_set_text_mode(2, 0);
        osd_draw_text(0, 0x2a, 6, 8, osd_get_text(osd_crosshair_item_texts, user_settings.language), 0);
        first_row = 7;
        first_icon = 0;
    }
    for (i = first_icon; i <= ICON_LAST; i++) {
        if (mode == ICON_MODE_SMALL) {
            if (first_icon == 0 && i > 6)
                break;
        }
        osd_draw_cell_run(1, 1, ICON_CELL_ATTR, column, i - first_icon + first_row, 2, (i - first_icon) * 2 + ICON_FIRST_GLYPH);
    }
}
