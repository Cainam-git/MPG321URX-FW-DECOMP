/* osd_cancel_navi_key_function  (FUN_a0098618)
 *
 * Restore the Navi Key function saved on entry and go back (left)
 * Note: Writes 0xA8025C56 back into settings byte +0x18A + row.
 * Name basis: derived - handler table 0xA802422C: left on states 0x86..0x91
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098618 @ 0xa0098618-0xa0098794 (95 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a struct whose array navi_key_function (+0x18A) is followed by the byte at
 * +0x1A3; both are indexed as below. Same record as osd_accept_navi_key_function. The two arms of the page
 * test have separate bodies.
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x18a];
    unsigned char navi_key_function[0x1a3 - 0x18a];     /* +0x18A: up, down, left, right, ... */
    unsigned char edited_key;                           /* +0x1A3: the Navi key direction being edited */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_column(void);
extern void osd_draw_navi_key_function_choices(unsigned char);

#define PAGE_NAVI_KEY_ITEMS          0x26       /* first item state of the Navi Key page; item row = state - 0x26 */
#define MENU_STATE_NAVI_FUNCTION_LIST 0x86      /* + function: the function list of a Navi key (states 0x86..0x91) */
#define CHOICES_PER_PAGE             7          /* rows of one page of the function list */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * Left key in the function list of a Navi key (menu states 0x86..0x91): put back the function that was saved when
 * the list was opened (osd_choice_row) and return to the item of that direction.
 *
 * When the function of the direction (byte +0x1A3) and the saved one are on different pages of the list (function
 * divided by 7 differs), the choice column is cleared and the page of the saved function is drawn again (page 0
 * or page 1). The saved function is then written back, the highlight leaves the list row of the present state, the
 * restored function's row is highlighted and marked, and the menu state returns to the item of the direction
 * (0x26 plus the direction) with its item row highlighted.
 */
void osd_cancel_navi_key_function(void)
{
    if (user_settings.navi_key_function[user_settings.edited_key] / CHOICES_PER_PAGE != osd_choice_row / CHOICES_PER_PAGE) {
        if (osd_choice_row / CHOICES_PER_PAGE == 0) {
            osd_clear_choice_column();
            osd_draw_navi_key_function_choices(0);
        } else {
            osd_clear_choice_column();
            osd_draw_navi_key_function_choices(1);
        }
    }
    user_settings.navi_key_function[user_settings.edited_key] = osd_choice_row;
    osd_clear_choice_highlight((osd_menu_state - MENU_STATE_NAVI_FUNCTION_LIST) % CHOICES_PER_PAGE);
    osd_highlight_choice_row(user_settings.navi_key_function[user_settings.edited_key] % CHOICES_PER_PAGE, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.navi_key_function[user_settings.edited_key] % CHOICES_PER_PAGE, CHOICE_MARK_ON);
    osd_menu_state = user_settings.edited_key + PAGE_NAVI_KEY_ITEMS;
    osd_highlight_item_row(user_settings.edited_key, HIGHLIGHT_ITEM_ACTIVE);
}
