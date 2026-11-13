/* osd_draw_crosshair_quick_menu  (FUN_a00adaf4)
 *
 * Draw the Smart Crosshair quick menu list.
 * Name basis: derived - quick menu state 0xFC; called by its up/down handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00adaf4 @ 0xa00adaf4-0xa00adc98 (420 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the seventh argument of osd_draw_cell_run is written '(i - first_icon) * 2 + 0x11 + first_icon * 2';
 * the firmware computes the sum as i * 2 + 0x11 (0xa00adb9c, 0xa00adba0). Written as 'i * 2 + 0x11' the widened
 * first_icon and the stop flag share %i1 and first_icon is in %i0; the firmware has the widened first_icon in %i0
 * (0xa00adb74), the flag in %i1 (0xa00adb98) and first_icon in %l0.
 */

#define QUICK_MENU_COLUMN 10
#define CROSSHAIR_ICON_PAGE_SHIFT 2  /* page = icon >> 2 */

/* Settings record (user_settings): the fields used here. */
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                 /* +8 */
    unsigned char pad2[0x190 - 9];
    unsigned char crosshair_icon;           /* +0x190: Smart Crosshair icon (1..6) */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_crosshair_item_texts[];
extern void panel_wait_sync_pulse(void);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void osd_highlight_quick_menu_row(unsigned char, unsigned char);
extern void osd_draw_quick_menu_mark(unsigned char, unsigned char);

/* Draw the list of the Smart Crosshair quick menu (menu state 0xFC). The quick menu area (rows
 * 4..11) is cleared, then the icon glyph pairs are drawn: osd_choice_row >> 2 and the crosshair
 * icon >> 2 give the page. Page 0 (icon number below 4) shows the title text in row 5 and icon
 * entries 0..5 in rows 6..11; page 1 shows entries 6..12 in rows 4..10. Each entry is a run of two
 * glyphs starting at glyph entry * 2 + 0x11, drawn at column 10 with attribute 0x796.
 * When the page of the stored cursor row (osd_choice_row >> 2) is the page of the current icon,
 * the cursor row (osd_choice_row & 3) is highlighted and marked; otherwise the highlight window 4
 * is switched off. No parameters; called by the up/down handlers of this quick menu. */
void osd_draw_crosshair_quick_menu(void)
{
    unsigned char i;
    unsigned char first_entry;
    unsigned char first_row = 4;

    panel_wait_sync_pulse();
    for (i = 4; i <= 0xb; i++) {
        osd_api_fill_cell_bytes(0, 3, i, 0x10, 0, 0);
        osd_api_fill_cells(3, i, 0x10, 0x792, 0);
    }
    if ((user_settings.crosshair_icon >> CROSSHAIR_ICON_PAGE_SHIFT) != 0)
        first_entry = 6;
    else {
        first_entry = 0;
        first_row = 6;
    }
    if (first_entry == 0) {
        osd_api_set_text_mode(2, 0);
        osd_api_set_glyph_write_address(0x6f, 0);
        osd_draw_text(0, 6, 5, 10, osd_get_text(osd_crosshair_item_texts, user_settings.language), 0);
    }
    for (i = first_entry; i <= 12; i++) {
        /* Page 0 stops after entry 5. */
        if (first_entry == 0 && i > 5)
            break;
        osd_draw_cell_run(1, 1, 0x796, QUICK_MENU_COLUMN, i - first_entry + first_row, 2, (i - first_entry) * 2 + 0x11 + first_entry * 2);
    }
    if ((osd_choice_row >> 2) == (user_settings.crosshair_icon >> CROSSHAIR_ICON_PAGE_SHIFT)) {
        osd_highlight_quick_menu_row(osd_choice_row & 3, 0);
        osd_draw_quick_menu_mark(osd_choice_row & 3, 1);
    } else
        osd_api_set_window_enable(4, 0, 0);
}
