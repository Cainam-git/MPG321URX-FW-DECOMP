/* osd_cancel_pixel_shift_speed  (FUN_a009a270)
 *
 * Restore the Pixel Shift speed saved on entry and go back (left)
 * Note: Writes 0xA8025C55 back into settings byte +0x1DD.
 * Name basis: derived - handler table 0xA802422C: left on states 0xF1..0xF3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a270 @ 0xa009a270-0xa009a2d0 (24 words), flags -mcpu=v8 -O3 -g.
 * Source form: the saved speed is an unsigned char local (the firmware re-extends the loaded byte with 'and 0xff'
 * for the call while storing the raw register); the speed byte is reached through a struct pointer.
 */
struct user_settings_record { unsigned char pad[0x1dd]; unsigned char pixel_shift_speed; /* +0x1DD */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);

#define MENU_STATE_PIXEL_SHIFT_ITEM 0x34 /* Pixel Shift item of the MSI OLED Care page (item row 0) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN_2       2      /* osd_highlight_choice_row style 2 */

/*
 * Left key in the Pixel Shift speed list (states 0xF1..0xF3): put back the speed saved on entry and go back to
 * the Pixel Shift item.
 *
 * The highlight of the cursor row (state - 0xF1, written as state + 0xF in the byte argument) is removed and
 * settings byte +0x1DD gets the speed saved in osd_edit_value. That speed's row gets highlight style 2 and the
 * mark, the menu state returns to 0x34 and the item row is highlighted as active.
 */
void osd_cancel_pixel_shift_speed(void)
{
  struct user_settings_record *p;
  unsigned char saved_speed;

  osd_clear_choice_highlight(osd_menu_state + 0xf);
  p = &user_settings;
  saved_speed = osd_edit_value;
  p->pixel_shift_speed = saved_speed;
  osd_highlight_choice_row(saved_speed, CHOICE_ROW_PLAIN_2);
  osd_draw_choice_mark(CHOICE_MARK_LIST, p->pixel_shift_speed, MARK_DRAW);
  osd_menu_state = MENU_STATE_PIXEL_SHIFT_ITEM;
  osd_highlight_item_row(0, ITEM_ROW_ACTIVE);
}
