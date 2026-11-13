/* osd_accept_pixel_shift_speed  (FUN_a009a1ec)
 *
 * Keep the highlighted Pixel Shift speed and go back to the item (OK)
 * Note: Speed = settings byte +0x1DD; returns to state 0x34; texts 0x18B5E0.
 * Name basis: derived - handler table 0xA802422C: OK on states 0xF1..0xF3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a1ec @ 0xa009a1ec-0xa009a270 (33 words), flags -mcpu=v8 -O3 -g.
 * osd_draw_choice_mark(1, osd_edit_value, 0) runs BEFORE osd_clear_choice_highlight. Source form: the speed byte is
 * reached through a struct pointer.
 */
struct user_settings_record { unsigned char pad[0x1dd]; unsigned char pixel_shift_speed; /* +0x1DD */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void oled_user_apply_pixel_shift_speed(void);

#define MENU_STATE_PIXEL_SHIFT_ITEM 0x34 /* Pixel Shift item of the MSI OLED Care page (item row 0) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN_2       2      /* osd_highlight_choice_row style 2 */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK in the Pixel Shift speed list (states 0xF1..0xF3): go back to the Pixel Shift item.
 *
 * The mark of the row saved on entry (osd_edit_value) is cleared and the highlight of the cursor row
 * (state - 0xF1, written as state + 0xF in the byte argument) is removed. The row of the speed stored in
 * settings byte +0x1DD gets highlight style 2 and the mark, the menu state returns to 0x34, the item row is
 * highlighted as active and the speed is applied (oled_user_apply_pixel_shift_speed). The routine ends by
 * reporting a settings change.
 */
void osd_accept_pixel_shift_speed(void)
{
  struct user_settings_record *p;

  osd_draw_choice_mark(CHOICE_MARK_LIST, osd_edit_value, MARK_CLEAR);
  osd_clear_choice_highlight(osd_menu_state + 0xf);
  p = &user_settings;
  osd_highlight_choice_row(p->pixel_shift_speed, CHOICE_ROW_PLAIN_2);
  osd_draw_choice_mark(CHOICE_MARK_LIST, p->pixel_shift_speed, MARK_DRAW);
  osd_menu_state = MENU_STATE_PIXEL_SHIFT_ITEM;
  osd_highlight_item_row(0, ITEM_ROW_ACTIVE);
  oled_user_apply_pixel_shift_speed();
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
