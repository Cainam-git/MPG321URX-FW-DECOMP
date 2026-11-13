/* osd_leave_static_screen_choices  (FUN_a0099dd8)
 *
 * Leave the Static Screen Detection list and return to the item (left)
 * Note: Returns to state 0x37.
 * Name basis: derived - handler table 0xA802422C: left on states 0xBB..0xBF
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099dd8 @ 0xa0099dd8, flags -mcpu=v8 -O3 -g.
 * Source form: the choice row is written (osd_menu_state + 0x45U & 0xff) and the mark as
 * (flags >> 0xf & 1); the exact build depends on these forms.
 */

#define MENU_STATE_STATIC_SCREEN_ITEM   0x37    /* item of the MSI OLED Care page; item row = state - 0x34 */
#define OLED_CARE_STATIC_SCREEN_SHIFT   15      /* bit 15 of settings +0x1DC: Static Screen Detection on */
#define STATIC_SCREEN_CHOICE_BASE       0xbb    /* choice rows 0..4 are states 0xBB..0xBF; row = state - 0xBB */
#define LIST_KIND_CHOICES               1       /* osd_draw_choice_mark: a choice list */
#define HIGHLIGHT_ACTIVE                1       /* osd_highlight_item_row: cursor in the item list */

extern unsigned int osd_menu_state;
extern unsigned int user_settings_oled_care_flags;
extern int osd_draw_choice_mark();
extern void osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern int osd_draw_key_guide();
extern int osd_update_key_guide();

/*
 * Left key in the Static Screen Detection choice list (menu states 0xBB..0xBF): leave the list and return to
 * the Static Screen Detection item (state 0x37) of the MSI OLED Care page.
 *
 * The highlight of the open choice row (state - 0xBB) is removed and the mark is redrawn on the row given by bit
 * 15 of settings +0x1DC (Static Screen Detection off or on). Item row 3 is highlighted as active, then the key
 * guide is drawn and updated.
 * Called through osd_menu_key_table (column 1, the left key).
 */
void osd_leave_static_screen_choices(void)
{
    osd_clear_choice_highlight(osd_menu_state + 0x45U & 0xff);
    osd_draw_choice_mark(LIST_KIND_CHOICES, user_settings_oled_care_flags >> OLED_CARE_STATIC_SCREEN_SHIFT & 1, 1);
    osd_menu_state = MENU_STATE_STATIC_SCREEN_ITEM;
    osd_highlight_item_row(3, HIGHLIGHT_ACTIVE);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
}
