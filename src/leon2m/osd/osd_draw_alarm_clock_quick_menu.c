/* osd_draw_alarm_clock_quick_menu  (FUN_a00b89c4)
 *
 * Draw one page of the Alarm Clock quick menu: OFF and timers 1 to 3, or timer 4 alone.
 *   page: 0 = OFF and timers 0..2, 1 = timer 3
 * Note: The stored choice (settings alarm_clock) is highlighted only when it lies on the page drawn.
 * Name basis: derived - format 'n%d%d : %d%d'; callers osd_select_next/prev_quick_alarm_clock pass alarm_clock
 *   / 4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b89c4 @ 0xa00b89c4-0xa00b8ca8 (185 words), flags -mcpu=v8 -O3 -g (also -msoft-float).
 * Source form the exact build depends on: the page 1 branch counts the length with i, the page 0 branch with
 * k; the same loop is written out in each branch; the row of the mark is a copy of osd_choice_row & 3 in k.
 */
#define TEXT_ALIGN_CENTRE   2          /* text mode of the layer */
#define TEXT_COLUMN         6           /* column of the texts, 10 cells wide */
#define TEXT_WIDTH          0xa
#define FIRST_ROW           5           /* row of entry 0; every entry is two rows lower than the one before */
#define MARK_COLUMN         4           /* the choice mark: two cells, glyphs 0x1C and 0x1D */
#define MARK_GLYPH          0x1c
#define ROW_STORED          0           /* osd_highlight_quick_menu_row: second argument */
#define STORED_WINDOW       4           /* window of osd_api_set_window_enable that frames the stored row */

/* The user settings fields used here. */
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +0x08: menu language, index into the text tables */
    unsigned char pad09[0x198 - 9];
    unsigned char alarm_minutes[4];             /* +0x198: minutes of the four timers */
    unsigned char alarm_seconds[4];             /* +0x19C: seconds of the four timers */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_off_on_texts[];
extern void sprintf(unsigned char *, const char *, ...);
extern unsigned char osd_choice_row;
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_clear_quick_menu_rows(void);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned short, int, unsigned int, int);
extern void osd_highlight_quick_menu_row(unsigned char, unsigned char);
extern void osd_api_set_window_enable(int, int, int);

/*
 * Draw one page of the Alarm Clock quick menu on layer 0 (choices 0..3 are page 0, choice 4 is page 1), then the mark of the stored choice.
 *
 *   page  0: the text OFF (entry 0 of osd_off_on_texts, in the menu language) in the first row and timers 0..2
 *            in the next three entries; 1: timer 3 alone in the first row.
 *
 * Each timer is a text "mm : ss" built from the minutes and seconds bytes of the settings; its first byte is
 * the length byte of a menu text (characters after it). The stored choice is osd_choice_row (settings
 * alarm_clock): when its page (osd_choice_row >> 2) is the page drawn, its row (osd_choice_row & 3) is
 * highlighted and the mark is drawn in that row; otherwise the stored-row window is switched off.
 *
 * Called by osd_select_next_quick_alarm_clock, osd_select_prev_quick_alarm_clock (page = alarm_clock / 4, when
 * the choice moves to value 4 or 0) and osd_draw_navi_quick_menu.
 */
void osd_draw_alarm_clock_quick_menu(unsigned char page)
{
    unsigned char text[16];                     /* [0] = length byte, then the characters */
    unsigned char i, k;

    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, 0);
    osd_api_set_glyph_write_address(0x6f, 0);
    osd_clear_quick_menu_rows();
    if (page != 0) {
        sprintf(text, "n%d%d : %d%d", user_settings.alarm_minutes[3] / 10, user_settings.alarm_minutes[3] % 10,
                     user_settings.alarm_seconds[3] / 10, user_settings.alarm_seconds[3] % 10);
        /* Length byte: position of the end of the text, minus the placeholder 'n'. */
        for (i = 0; i <= 0xe; i++)
            if (text[i] == 0)
                break;
        text[0] = i - 1;
        osd_draw_text(0, TEXT_COLUMN, FIRST_ROW, TEXT_WIDTH, (unsigned int)text, 0);
    } else {
        osd_draw_text(0, TEXT_COLUMN, FIRST_ROW, TEXT_WIDTH, osd_get_text(osd_off_on_texts, user_settings.language), 0);
        for (i = 0; i <= 2; i++) {
            sprintf(text, "n%d%d : %d%d", user_settings.alarm_minutes[i] / 10, user_settings.alarm_minutes[i] % 10,
                         user_settings.alarm_seconds[i] / 10, user_settings.alarm_seconds[i] % 10);
            for (k = 0; k <= 0xe; k++)
                if (text[k] == 0)
                    break;
            text[0] = k - 1;
            osd_draw_text(0, TEXT_COLUMN, i * 2 + FIRST_ROW + 2, TEXT_WIDTH, (unsigned int)text, 0);
        }
    }
    if (page == osd_choice_row >> 2) {
        osd_highlight_quick_menu_row(osd_choice_row & 3, ROW_STORED);
        k = osd_choice_row & 3;
        if (k > 3)
            k -= 4;
        for (i = 0; i <= 1; i++)
            osd_api_fill_cell_bytes(0, i + MARK_COLUMN, k * 2 + FIRST_ROW, 1, i + MARK_GLYPH, 0);
    } else {
        osd_api_set_window_enable(STORED_WINDOW, 0, 0);
    }
}
