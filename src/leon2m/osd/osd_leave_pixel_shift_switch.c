/* osd_leave_pixel_shift_switch  (FUN_a0099d74)
 *
 * Leave the Pixel Shift on/off list and return to the item (left)
 * Note: States 0xB8..0xBA; returns to state 0x34.
 * Name basis: derived - handler table 0xA802422C: left on states 0xB8..0xBA
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099d74 @ 0xa0099d74, flags -mcpu=v8 -O3 -g.
 * Source form: the choice row is written (osd_menu_state + 0x48U & 0xff) and the mark as
 * (flags >> 0x1d & 1); the exact build depends on these forms.
 */

#define MENU_STATE_PIXEL_SHIFT_ITEM 0x34    /* item of the MSI OLED Care page; item row = state - 0x34 */
#define OLED_CARE_PIXEL_SHIFT_BIT   29      /* bit 29 of settings +0x1DC: the mark of this list */
#define PIXEL_SHIFT_CHOICE_BASE     0xb8    /* choice rows 0..2 are states 0xB8..0xBA; row = state - 0xB8 */
#define LIST_KIND_CHOICES           1       /* osd_draw_choice_mark: a choice list */
#define HIGHLIGHT_ACTIVE            1       /* osd_highlight_item_row: cursor in the item list */

extern unsigned int osd_menu_state;
extern unsigned int user_settings_oled_care_flags;
extern int osd_draw_choice_mark();
extern void osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern int osd_draw_key_guide();
extern int osd_update_key_guide();

/*
 * Left key in the Pixel Shift choice list (menu states 0xB8..0xBA): leave the list and return to the Pixel
 * Shift item (state 0x34) of the MSI OLED Care page.
 *
 * The highlight of the open choice row (state - 0xB8) is removed and the mark is redrawn on the row given by bit
 * 29 of settings +0x1DC. Item row 0 is highlighted as active, then the key guide is drawn and updated.
 * Called through osd_menu_key_table (column 1, the left key).
 */
void osd_leave_pixel_shift_switch(void)
{
    osd_clear_choice_highlight(osd_menu_state + 0x48U & 0xff);
    osd_draw_choice_mark(LIST_KIND_CHOICES, user_settings_oled_care_flags >> OLED_CARE_PIXEL_SHIFT_BIT & 1, 1);
    osd_menu_state = MENU_STATE_PIXEL_SHIFT_ITEM;
    osd_highlight_item_row(0, HIGHLIGHT_ACTIVE);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
}
