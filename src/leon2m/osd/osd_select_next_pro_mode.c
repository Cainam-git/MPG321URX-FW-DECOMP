/* osd_select_next_pro_mode  (FUN_a009c22c)
 *
 * Move to the next allowed Pro mode (down key) and preview it.
 * Note: Wraps inside the states 0x5C..0x63; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0x5C..0x63; applies with UserSetProMode;
 *   texts 0x1951DC
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: the wrap-around is the int 'entry = (low halfword of menu state - 91) % 8', stored back as
 * 'entry + 0x5c' and also the index tested by osd_is_choice_enabled. osd_step_pro_mode_index is called again for
 * every use of the stored mode's position; the calls are not shared in a local.
 */
#define MENU_STATE_PRO_MODE_LIST 0x5c   /* list rows are the menu states 0x5C..0x63 */
#define PRO_MODE_COUNT           8
#define CHOICES_PER_PAGE         7      /* the list shows 7 rows; the 8th mode is on page 1 */
#define USER_SETTINGS_COLOR_TEMPERATURE 0x11
#define USER_SETTINGS_PRO_MODE          0x181

extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern unsigned char osd_saved_choice_value, osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);
extern void osd_draw_pro_mode_choices(unsigned char);
extern void UserSetProMode(void);
extern void osd_draw_item_row_state(int, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/*
 * Move the highlight to the next Pro mode that osd_is_choice_enabled allows (down key) and apply it
 * as a preview. The menu state is the highlighted list position (MENU_STATE_PRO_MODE_LIST + position); the next
 * position is found by adding 1 and wrapping, and the step repeats while osd_is_choice_enabled rejects it.
 * osd_step_pro_mode_index(x, 1) turns a list position into the Pro mode value and (x, 0) turns a mode value back into
 * its list position. The new mode value is stored in the settings (pro_mode) at once. When the new position lies on
 * another page of CHOICES_PER_PAGE rows, that page is redrawn. Pro mode values 4 to 6 set the colour temperature
 * byte to 1; any other value puts back the value osd_saved_choice_value held when the list was opened. Then
 * UserSetProMode applies the mode, the item row is redrawn and the new row highlighted. Last, when the page shows
 * the stored mode (osd_choice_row, the value from before the list was opened), its mark is redrawn: last argument 0
 * when the highlight is on it, 1 otherwise.
 */
void osd_select_next_pro_mode(void)
{
    int entry;
    unsigned char page;

    page = (osd_menu_state - MENU_STATE_PRO_MODE_LIST) / CHOICES_PER_PAGE;
    osd_clear_choice_highlight((osd_menu_state - MENU_STATE_PRO_MODE_LIST) % CHOICES_PER_PAGE);
    do {
        entry = (unsigned short)osd_menu_state - (MENU_STATE_PRO_MODE_LIST - 1);
        entry = entry % PRO_MODE_COUNT;
        osd_menu_state = entry + MENU_STATE_PRO_MODE_LIST;
    } while (osd_is_choice_enabled(entry) != 1);
    user_settings[USER_SETTINGS_PRO_MODE] = osd_step_pro_mode_index(osd_menu_state - MENU_STATE_PRO_MODE_LIST, 1);
    if (page != (osd_menu_state - MENU_STATE_PRO_MODE_LIST) / CHOICES_PER_PAGE)
        osd_draw_pro_mode_choices((osd_menu_state - MENU_STATE_PRO_MODE_LIST) / CHOICES_PER_PAGE);
    if (user_settings[USER_SETTINGS_PRO_MODE] >= 4 && user_settings[USER_SETTINGS_PRO_MODE] <= 6) {
        if (user_settings[USER_SETTINGS_COLOR_TEMPERATURE] != 1)
            user_settings[USER_SETTINGS_COLOR_TEMPERATURE] = 1;
    } else
        user_settings[USER_SETTINGS_COLOR_TEMPERATURE] = osd_saved_choice_value;
    UserSetProMode();
    osd_draw_item_row_state(2, 1);
    osd_highlight_choice_row((osd_menu_state - MENU_STATE_PRO_MODE_LIST) % CHOICES_PER_PAGE, 1);
    if ((osd_menu_state - MENU_STATE_PRO_MODE_LIST) / CHOICES_PER_PAGE == osd_step_pro_mode_index(osd_choice_row, 0) / CHOICES_PER_PAGE) {
        if (osd_menu_state - MENU_STATE_PRO_MODE_LIST == osd_step_pro_mode_index(osd_choice_row, 0))
            osd_draw_choice_mark(1, osd_step_pro_mode_index(osd_choice_row, 0) % CHOICES_PER_PAGE, 0);
        else
            osd_draw_choice_mark(1, osd_step_pro_mode_index(osd_choice_row, 0) % CHOICES_PER_PAGE, 1);
    }
}
