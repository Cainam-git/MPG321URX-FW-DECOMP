/* osd_leave_protect_notice_choices  (FUN_a009a078)
 *
 * Leave the Protect Notice choices and return to the item (left)
 * Note: Returns to state 0x36.
 * Name basis: derived - handler table 0xA802422C: left on states 0xC3/0xC4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a078 @ 0xa009a078, flags -mcpu=v8 -O3 -g.
 * Source form: the choice row is written (osd_menu_state + 0x3dU & 0xff); the exact build depends on this form.
 */

#define MENU_STATE_PROTECT_NOTICE_ITEM  0x36    /* item of the MSI OLED Care page; item row = state - 0x34 */
#define PROTECT_NOTICE_CHOICE_BASE      0xc3    /* choice rows 0 and 1 are states 0xC3 and 0xC4; row = state - 0xC3 */
#define LIST_KIND_CHOICES               1       /* osd_draw_choice_mark: a choice list */
#define HIGHLIGHT_ACTIVE                1       /* osd_highlight_item_row: cursor in the item list */

extern unsigned char user_settings_protect_notice;
extern unsigned int osd_menu_state;
extern int osd_draw_choice_mark();
extern void osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern int osd_draw_key_guide();
extern int osd_update_key_guide();

/*
 * Left key in the Protect Notice choice list (menu states 0xC3 and 0xC4): leave the list and return to the
 * Protect Notice item (state 0x36) of the MSI OLED Care page.
 *
 * The highlight of the open choice row (state - 0xC3) is removed and the mark is redrawn on the row given by the
 * Protect Notice setting (settings +0x1EE). Item row 2 is highlighted as active, then the key guide is drawn and
 * updated.
 * Called through osd_menu_key_table (column 1, the left key).
 */
void osd_leave_protect_notice_choices(void)
{
    osd_clear_choice_highlight(osd_menu_state + 0x3dU & 0xff);
    osd_draw_choice_mark(LIST_KIND_CHOICES, user_settings_protect_notice, 1);
    osd_menu_state = MENU_STATE_PROTECT_NOTICE_ITEM;
    osd_highlight_item_row(2, HIGHLIGHT_ACTIVE);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
}
