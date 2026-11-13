/* osd_draw_choice_notes  (FUN_a00aee44)
 *
 * Draw the notes under a choice list (conflicting functions, notices)
 *   mode: menu state
 *   sub: row
 * Note: Lists functions that are off or limited by the open setting, or the Notice text for Static Screen /
 *   detections.
 * Name basis: descriptive - texts 0x1832E4 'Adaptive-Sync|Brightness|HDCR|...', 0x183A70 'Notice : ...'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aee44 @ 0xa00aee44-0xa00af44c (1544 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the mode 0x23 loop reads row through an unsigned short copy (row is masked once before the loop);
 * n is incremented at the end of each loop body; the pointer sum 'reducing_texts + i * 29 + language' is
 * passed with the second argument 0.
 */
#define LANGUAGE_COUNT 29  /* languages per text entry */

/* Menu states handled here. */
#define MENU_STATE_GAME_MODE_ITEM   0x0e
#define MENU_STATE_PRO_MODE_ITEM    0x15
#define MENU_STATE_PIP_PBP_OFF      0x23
#define MENU_STATE_STATIC_LEVEL     0xbf   /* level list read through osd_get_oled_care_text */
/* States 0xf7, 0xf8, 0xf9 (the detection level sliders) are matched as (unsigned char)(state + 9) <= 2. */

#define NOTE_COLUMN       0x28   /* note text and its filler cells */
#define NOTE_TEXT_COLUMN  0x29   /* function names, one cell right of the marker cell */
#define NOTE_FIRST_ROW    6
#define NOTE_NOTICE_ROW     10     /* row used for the notice in states 0xbf and 0xf7..0xf9 */
#define NOTE_ENTRY_COUNT  12     /* entries 0..11 of osd_choice_note_function_texts */

/* Settings record (user_settings): the menu language. */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_choice_note_texts[], osd_choice_note_enabling_texts[], osd_choice_note_function_texts[], osd_choice_note_reducing_texts[];
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_window_effect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_api_set_window_rect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned short osd_get_last_text_width(void);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);

/* Draw the notes beside a choice list, in column 0x28 from row 6 (row 10 in the states with a notice).
 *   mode: the menu state of the open list.
 *   sub:  the choice row under the cursor; used only in state 0x0e.
 * What is drawn depends on the state:
 *   - 0x0e, 0x15 and 0x23: a heading text (osd_choice_note_enabling_texts) at row 6, followed by the
 *     names of functions (osd_choice_note_function_texts, entry numbers listed in the table
 *     'listed') that are affected. Which entries are listed:
 *     state 0x0e: sub 5 lists entries 3, 4 and 6; sub 2 lists entry 9; sub 6 lists entries 3 and 4;
 *     state 0x15: none; state 0x23: entries 0, 4, 6, 7, 8 and 11, written in the order
 *     5, 0, 4, 6, 7, 8, 11 (entry 5 is not listed in this state), then the routine returns.
 *   - 0xbf and 0xf7..0xf9: the notice text (osd_choice_note_texts) at row 10, and three further lines
 *     (osd_choice_note_reducing_texts, entries 0..2) at rows 12, 14 and 16.
 * Each list entry takes a filler row of cells (attribute 0xe96); each entry name gets a marker cell with
 * value 1 in column 0x28. In the generic list the seventh entry (n == 6) has its filler cells
 * placed at row + 0xe with width 10 instead of the usual position.
 * The heading's width is read back and window 5 is set over the heading row from x 0x3c0 to
 * x 0x3c0 + width. Callers: osd_open_static_screen_reduce_level, osd_show_detection_level_slider, osd_draw_item_choices. */
void osd_draw_choice_notes(unsigned char mode, unsigned char sub)
{
    unsigned char listed[15] = { 0 };
    unsigned char order[7] = { 5, 0, 4, 6, 7, 8, 11 };
    unsigned char row, i, n;
    unsigned short w, y;

    osd_api_set_glyph_write_address(0x120, 0);
    osd_api_set_text_mode(0, 0);
    row = NOTE_FIRST_ROW;
    if (mode == MENU_STATE_STATIC_LEVEL) {
        row = NOTE_NOTICE_ROW;
        osd_api_set_glyph_write_address(0x134, 0);
        osd_draw_text(0, NOTE_COLUMN, row, 1, osd_get_text(osd_choice_note_texts, user_settings.language), 0);
    }
    if ((unsigned char)(mode + 9) <= 2) {
        row = NOTE_NOTICE_ROW;
        osd_api_set_glyph_write_address(0x111, 0);
        osd_draw_text(0, NOTE_COLUMN, row, 1, osd_get_text(osd_choice_note_texts, user_settings.language), 0);
    }
    osd_api_fill_cells(NOTE_COLUMN, row, 0xc, 0xe96, 0);
    if (mode == MENU_STATE_GAME_MODE_ITEM || mode == MENU_STATE_PRO_MODE_ITEM || mode == MENU_STATE_PIP_PBP_OFF)
        osd_draw_text(0, NOTE_COLUMN, row, 1, osd_get_text(osd_choice_note_enabling_texts, user_settings.language), 0);
    w = osd_get_last_text_width();
    osd_api_set_window_enable(5, 0, 0);
    osd_api_set_window_effect(5, 0, 0, 0, 0, 0xf, 0, 0, 0, 0, 0);
    osd_api_set_window_rect(5, 0x3c0, row * 0x24 + 0x24, (unsigned short)(w + 0x3c0), row * 0x24 + 0x24, 0);
    osd_api_set_window_enable(5, 1, 0);
    if (mode == MENU_STATE_GAME_MODE_ITEM) {
        if (sub == 5) {
            listed[3] = 1;
            listed[4] = 1;
            listed[6] = 1;
        } else if (sub == 2)
            listed[9] = 1;
        else if (sub == 6) {
            listed[3] = 1;
            listed[4] = 1;
        }
    } else if (mode == MENU_STATE_PIP_PBP_OFF) {
        unsigned short r = row;

        listed[0] = 1;
        listed[4] = 1;
        listed[6] = 1;
        listed[7] = 1;
        listed[8] = 1;
        listed[11] = 1;
        for (i = 0, n = 0; i < 7; i++) {
            if (listed[order[i]]) {
                y = n * 2 + r + 2;
                osd_api_fill_cells(NOTE_COLUMN, y, 0xd, 0xe96, 0);
                osd_api_fill_cell_bytes(0, NOTE_COLUMN, y, 1, 1, 0);
                osd_draw_text(0, NOTE_TEXT_COLUMN, y, 1, osd_get_text(osd_choice_note_function_texts, order[i] * LANGUAGE_COUNT + user_settings.language), 0);
                n++;
            }
        }
        return;
    } else if (mode == MENU_STATE_STATIC_LEVEL) {
        for (i = 0; i < 3; i++) {
            y = i * 2 + row + 2;
            osd_api_fill_cells(NOTE_COLUMN, y, 0xd, 0xe96, 0);
            osd_draw_text(0, NOTE_COLUMN, y, 1, osd_get_text(osd_choice_note_reducing_texts + i * LANGUAGE_COUNT + user_settings.language, 0), 0);
        }
        return;
    }
    if ((unsigned char)(mode + 9) <= 2) {
        for (i = 0; i < 3; i++) {
            y = i * 2 + row + 2;
            osd_api_fill_cells(NOTE_COLUMN, y, 0xd, 0xe96, 0);
            osd_draw_text(0, NOTE_COLUMN, y, 1, osd_get_text(osd_choice_note_reducing_texts + i * LANGUAGE_COUNT + user_settings.language, 0), 0);
        }
    } else {
        for (i = 0, n = 0; i < NOTE_ENTRY_COUNT; i++) {
            if (listed[i]) {
                if (n == 6)
                    osd_api_fill_cells(NOTE_COLUMN, row + 0xe, 0xa, 0xe96, 0);
                else
                    osd_api_fill_cells(NOTE_COLUMN, n * 2 + row + 2, 0xd, 0xe96, 0);
                y = n * 2 + row + 2;
                osd_api_fill_cell_bytes(0, NOTE_COLUMN, y, 1, 1, 0);
                osd_draw_text(0, NOTE_TEXT_COLUMN, y, 1, osd_get_text(osd_choice_note_function_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
                n++;
            }
        }
    }
}
