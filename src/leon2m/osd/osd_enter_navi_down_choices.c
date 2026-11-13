/* osd_enter_navi_down_choices  (FUN_a0098794)
 *
 * Open the function list of the Navi Key direction being edited (OK / right on the Down item).
 * Note: Direction = settings byte +0x1A3, its function = byte +0x18A + direction. Same code as
 *   osd_enter_navi_up_choices.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x27 = 'Down' (texts 0x19158C); texts
 *   0x1935BC (OFF, Brightness, Game Mode, ..., KVM)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098794 @ 0xa0098794-0xa0098850 (47 words), flags -mcpu=v8 -O3 -g.
 * Same instructions and constants as osd_enter_navi_up_choices; only the call displacements differ because the
 * code lies at another address. Source form as there: the settings record is a byte array and the function
 * byte is read again for each use.
 */
extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define USER_SETTINGS_NAVI_KEY_FUNCTIONS 0x18a /* navi_key_function[4]: up, down, left, right */
#define USER_SETTINGS_EDITED_KEY     0x1a3      /* the Navi key direction being edited (shared byte, see the Navi Key tab) */
#define PAGE_NAVI_KEY_ITEMS          0x26       /* first item state of the Navi Key page; item row = state - 0x26 */
#define MENU_STATE_NAVI_FUNCTION_LIST 0x86      /* + function: the function list of a Navi key (states 0x86..0x91) */
#define CHOICES_PER_PAGE             7          /* rows of one page of the function list */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_OFF              0
#define HIGHLIGHT_ITEM_LIST_OPEN     2          /* item row highlight while its choice list is open */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * A second copy of osd_enter_navi_up_choices at another address: open the list of functions for the Navi key
 * direction in settings byte +0x1A3.
 *
 * The function now set for that direction (+0x18A + direction) is saved in osd_choice_row. The mark of the
 * function's row (function modulo 7) is cleared, the item row is highlighted in the "list open" style, the menu
 * state becomes 0x86 plus the function and the function's row is highlighted.
 */
void osd_enter_navi_down_choices(void)
{
    osd_choice_row = user_settings[user_settings[USER_SETTINGS_EDITED_KEY] + USER_SETTINGS_NAVI_KEY_FUNCTIONS];
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings[user_settings[USER_SETTINGS_EDITED_KEY] + USER_SETTINGS_NAVI_KEY_FUNCTIONS] % CHOICES_PER_PAGE, CHOICE_MARK_OFF);
    osd_highlight_item_row(osd_menu_state - PAGE_NAVI_KEY_ITEMS, HIGHLIGHT_ITEM_LIST_OPEN);
    osd_menu_state = user_settings[user_settings[USER_SETTINGS_EDITED_KEY] + USER_SETTINGS_NAVI_KEY_FUNCTIONS] + MENU_STATE_NAVI_FUNCTION_LIST;
    osd_highlight_choice_row(user_settings[user_settings[USER_SETTINGS_EDITED_KEY] + USER_SETTINGS_NAVI_KEY_FUNCTIONS] % CHOICES_PER_PAGE, CHOICE_ROW_EDGED);
}
