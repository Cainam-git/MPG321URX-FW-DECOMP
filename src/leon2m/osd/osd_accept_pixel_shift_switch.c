/* osd_accept_pixel_shift_switch  (FUN_a0099e44)
 *
 * Switch Pixel Shift off or on as highlighted and go back (OK)
 * Note: State 0xB8 clears, 0xB9 sets bit 29 of settings word +0x1DC.
 * Name basis: derived - handler table 0xA802422C: OK on states 0xB8/0xB9
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099e44 @ 0xa0099e44-0xa0099f20 (55 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a struct with the word at +0x1DC; the two arms that clear or set bit 29 are
 * out of line; the final call oled_user_apply_pixel_shift takes no arguments and is a tail call.
 */
struct user_settings_record { unsigned char pad[0x1dc]; unsigned int oled_care_flags; /* +0x1DC: bit 29 = Pixel Shift on */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void oled_user_apply_pixel_shift(void);

#define SETTINGS_PIXEL_SHIFT_ON  0x20000000 /* bit 29 of settings word +0x1DC */
#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page; Pixel Shift is state 0x34 */
#define MENU_STATE_PIXEL_SHIFT_OFF 0xb8 /* the OFF row of the Pixel Shift choices; ON is 0xB9 */
#define MENU_STATE_PIXEL_SHIFT_ON 0xb9
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */

/*
 * OK on OFF or ON in the Pixel Shift choices (states 0xB8, 0xB9): store the choice and go back to the Pixel
 * Shift item.
 *
 * State 0xB8 clears and state 0xB9 sets bit 29 of settings word +0x1DC (SETTINGS_PIXEL_SHIFT_ON). The
 * highlight is removed with osd_clear_choice_highlight(osd_choice_row + 0x48) and the mark of the row saved on
 * entry is cleared. The row of the stored choice gets the plain highlight and the mark, the menu state returns
 * to 0x34, the item row is highlighted as active, the key guide is redrawn and the setting is applied
 * (oled_user_apply_pixel_shift).
 */
void osd_accept_pixel_shift_switch(void)
{
  if (osd_menu_state == MENU_STATE_PIXEL_SHIFT_OFF)
    user_settings.oled_care_flags &= ~SETTINGS_PIXEL_SHIFT_ON;
  else if (osd_menu_state == MENU_STATE_PIXEL_SHIFT_ON)
    user_settings.oled_care_flags |= SETTINGS_PIXEL_SHIFT_ON;
  osd_clear_choice_highlight(osd_choice_row + 0x48);
  osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, MARK_CLEAR);
  osd_menu_state = PAGE_OLED_CARE_ITEMS;
  osd_highlight_choice_row(user_settings.oled_care_flags >> 29 & 1, CHOICE_ROW_PLAIN);
  osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.oled_care_flags >> 29 & 1, MARK_DRAW);
  osd_highlight_item_row(osd_menu_state - PAGE_OLED_CARE_ITEMS, ITEM_ROW_ACTIVE);
  osd_draw_key_guide(1, 2);
  osd_update_key_guide(0, 1);
  oled_user_apply_pixel_shift();
}
