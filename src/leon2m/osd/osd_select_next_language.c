/* osd_select_next_language  (FUN_a009d4e8)
 *
 * Move to the next allowed menu language (down key)
 * Note: 29 languages, 7 rows shown; redraws the page when the list scrolls.
 * Name basis: derived - handler table 0xA802422C: down on states 0x92..0xAE
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: the page flag is tested as 'page_redrawn == 1' (the plain 'if (page_redrawn)' predicts the block
 * differently and changes the block order).
 */

#define MENU_STATE_LANGUAGE_LIST 0x92   /* the 29 languages are the menu states 0x92..0xAE */
#define LANGUAGE_COUNT           29
#define CHOICES_PER_PAGE         7      /* 5 pages: 4 of 7 rows and a last page with one row */

/* Settings byte +8 is the menu language. */
struct language_settings {
    unsigned char pad0[8];
    unsigned char language;
};
extern struct language_settings user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_clear_choice_column(void);
extern void osd_draw_language_list(unsigned char);
extern void osd_redraw_settings_page(void);
extern void osd_mark_settings_changed(void);

/*
 * Move the highlight to the next menu language that osd_is_choice_enabled allows (down key). The menu state is
 * MENU_STATE_LANGUAGE_LIST + the language number. The next entry is found by adding 1 and wrapping; the step repeats
 * while osd_is_choice_enabled rejects it. The language byte of the settings changes at once.
 * The list shows CHOICES_PER_PAGE rows. The page is drawn again when the highlight lands on the first row of a page
 * (rows 7, 14, 21, 28: page 1..4 is drawn) or on row 0 (wrapped round: page 0 is drawn); the choice column is
 * cleared first. After such a redraw, the stored choice (osd_choice_row) gets its row highlighted again with mode 0
 * if it is on that page. Then the new row is highlighted, the Settings page is redrawn in the new language and, when
 * the stored choice is on the page shown, its mark is redrawn: last argument 0 when the highlight is on it, 1
 * otherwise. The settings are marked as changed at the end.
 */
void osd_select_next_language(void)
{
    int entry;
    unsigned char page_redrawn = 0;

    osd_clear_choice_highlight((osd_menu_state - MENU_STATE_LANGUAGE_LIST) % CHOICES_PER_PAGE);
    do {
        entry = ((unsigned short)osd_menu_state - (MENU_STATE_LANGUAGE_LIST - 1)) % LANGUAGE_COUNT;
        osd_menu_state = entry + MENU_STATE_LANGUAGE_LIST;
    } while (osd_is_choice_enabled(entry) != 1);
    user_settings.language = osd_menu_state + 0x6e;
    if (osd_menu_state == MENU_STATE_LANGUAGE_LIST + 4 * CHOICES_PER_PAGE) {
        osd_clear_choice_column();
        osd_draw_language_list(4);
        page_redrawn = 1;
    } else if (osd_menu_state == MENU_STATE_LANGUAGE_LIST + 3 * CHOICES_PER_PAGE) {
        osd_clear_choice_column();
        osd_draw_language_list(3);
        page_redrawn = 1;
    } else if (osd_menu_state == MENU_STATE_LANGUAGE_LIST + 2 * CHOICES_PER_PAGE) {
        osd_clear_choice_column();
        osd_draw_language_list(2);
        page_redrawn = 1;
    } else if (osd_menu_state == MENU_STATE_LANGUAGE_LIST + CHOICES_PER_PAGE) {
        osd_clear_choice_column();
        osd_draw_language_list(1);
        page_redrawn = 1;
    } else if (osd_menu_state == MENU_STATE_LANGUAGE_LIST) {
        osd_clear_choice_column();
        osd_draw_language_list(0);
        page_redrawn = 1;
    }
    if (page_redrawn == 1) {
        if (user_settings.language / CHOICES_PER_PAGE == osd_choice_row / CHOICES_PER_PAGE)
            osd_highlight_choice_row(osd_choice_row % CHOICES_PER_PAGE, 0);
    }
    osd_highlight_choice_row((osd_menu_state - MENU_STATE_LANGUAGE_LIST) % CHOICES_PER_PAGE, 1);
    osd_redraw_settings_page();
    {
        unsigned char stored_row = osd_choice_row;
        if ((osd_menu_state - MENU_STATE_LANGUAGE_LIST) / CHOICES_PER_PAGE == (unsigned char)(stored_row / CHOICES_PER_PAGE)) {
            if (osd_menu_state - MENU_STATE_LANGUAGE_LIST == stored_row)
                osd_draw_choice_mark(1, stored_row % CHOICES_PER_PAGE, 0);
            else
                osd_draw_choice_mark(1, stored_row % CHOICES_PER_PAGE, 1);
        }
    }
    osd_mark_settings_changed();
}
