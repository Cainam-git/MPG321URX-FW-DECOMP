/* osd_select_next_navi_key_function  (FUN_a009cfd4)
 *
 * Move to the next allowed Navi Key function (down key)
 * Note: 12 functions OFF .. KVM; redraws the page when the list scrolls (7 rows shown).
 * Name basis: derived - handler table 0xA802422C: down on states 0x86..0x91; texts 0x1935BC
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: the page flag is tested as 'page_redrawn == 1'; with 'if (page_redrawn)' the cold blocks are placed
 * in another order. The last comparison has the osd_choice_row side first.
 */

#define MENU_STATE_NAVI_FUNCTION_LIST 0x86   /* the 12 functions are the menu states 0x86..0x91 */
#define NAVI_FUNCTION_COUNT           12
#define CHOICES_PER_PAGE              7      /* page 0 = rows 0..6, page 1 = rows 7..11 */

/* Settings: the four Navi Key functions start at +0x18A (up, down, left, right); +0x1A3 holds the key being edited. */
struct navi_key_settings {
    unsigned char pad0[0x18a];
    unsigned char navi_key_function[0x1a3 - 0x18a];
    unsigned char byte_0x1a3;
};
extern struct navi_key_settings user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_clear_choice_column(void);
extern void osd_draw_navi_key_function_choices(unsigned char);
extern void osd_mark_settings_changed(void);

/*
 * Move the highlight to the next Navi Key function that osd_is_choice_enabled allows (down key). The menu state is
 * MENU_STATE_NAVI_FUNCTION_LIST + the function number. The next entry is found by adding 1 and wrapping; the step
 * repeats while osd_is_choice_enabled rejects it. The function number is stored at once in the settings, in the
 * slot of the key being edited (byte_0x1a3).
 * The list shows CHOICES_PER_PAGE rows. The page is drawn again when the highlight lands on row 7 (stepping down
 * from page 0 to page 1: choice column cleared, page 1 drawn) or on row 0 (wrapped round: page 0 drawn).
 * After such a redraw, the stored choice (osd_choice_row) gets its row highlighted again with mode 0 if it is on
 * that page. Then the new row is highlighted and, when the stored choice is on the page shown, its mark is
 * redrawn: last argument 0 when the highlight is on it, 1 otherwise. The settings are marked as changed at the end.
 */
void osd_select_next_navi_key_function(void)
{
    int entry;
    unsigned char page_redrawn = 0;

    osd_clear_choice_highlight((osd_menu_state - MENU_STATE_NAVI_FUNCTION_LIST) % CHOICES_PER_PAGE);
    do {
        entry = ((unsigned short)osd_menu_state - (MENU_STATE_NAVI_FUNCTION_LIST - 1)) % NAVI_FUNCTION_COUNT;
        osd_menu_state = entry + MENU_STATE_NAVI_FUNCTION_LIST;
    } while (osd_is_choice_enabled(entry) != 1);
    user_settings.navi_key_function[user_settings.byte_0x1a3] = osd_menu_state + 0x7a;
    if (osd_menu_state == MENU_STATE_NAVI_FUNCTION_LIST + CHOICES_PER_PAGE) {
        osd_clear_choice_column();
        osd_draw_navi_key_function_choices(1);
        page_redrawn = 1;
    } else if (osd_menu_state == MENU_STATE_NAVI_FUNCTION_LIST) {
        osd_clear_choice_column();
        osd_draw_navi_key_function_choices(0);
        page_redrawn = 1;
    }
    if (page_redrawn == 1) {
        if (user_settings.navi_key_function[user_settings.byte_0x1a3] / CHOICES_PER_PAGE == osd_choice_row / CHOICES_PER_PAGE)
            osd_highlight_choice_row(osd_choice_row % CHOICES_PER_PAGE, 0);
    }
    osd_highlight_choice_row((osd_menu_state - MENU_STATE_NAVI_FUNCTION_LIST) % CHOICES_PER_PAGE, 1);
    {
        unsigned char stored_row = osd_choice_row;
        if ((unsigned char)(stored_row / CHOICES_PER_PAGE) == (osd_menu_state - MENU_STATE_NAVI_FUNCTION_LIST) / CHOICES_PER_PAGE) {
            if (osd_menu_state - MENU_STATE_NAVI_FUNCTION_LIST == stored_row)
                osd_draw_choice_mark(1, stored_row % CHOICES_PER_PAGE, 0);
            else
                osd_draw_choice_mark(1, stored_row % CHOICES_PER_PAGE, 1);
        }
    }
    osd_mark_settings_changed();
}
