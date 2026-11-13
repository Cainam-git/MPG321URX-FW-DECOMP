/* osd_select_next_pixel_shift_speed  (FUN_a009e3c8)
 *
 * Move to the next Pixel Shift speed (down key) and store it.
 * Note: Stores the row in settings byte +0x1DD at once.
 * Name basis: derived - handler table 0xA802422C: down on states 0xF1..0xF3; texts 0x18B5E0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e3c8, flags -mcpu=v8 -O3 -g.
 * Source form: the new row is computed in two statements (row, then row % 3) and the menu state is written from
 * it before the enabled test; the stored speed is written from the menu state, not from the row.
 */
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings_pixel_shift;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

#define MENU_STATE_PIXEL_SHIFT_SPEED_LIST 0xf1  /* + speed: the Pixel Shift speed list (states 0xF1..0xF3) */
#define PIXEL_SHIFT_SPEED_COUNT           3
#define CHOICE_ROW_EDGED                  1     /* osd_highlight_choice_row style: with edge glyphs */
#define CHOICE_MARK_LIST                  1     /* osd_draw_choice_mark: mark in a choice list */
#define CHOICE_MARK_OFF                   0
#define CHOICE_MARK_ON                    1

/*
 * Down key in the Pixel Shift speed list (menu states 0xF1 to 0xF3): go to the next speed, from the last back to
 * the first, skipping
 * speeds that osd_is_choice_enabled refuses, and store the speed at once in the settings (byte +0x1DD).
 *
 * The menu state is 0xF1 plus the speed, so the speed is the state minus 0xF1. The row cleared and highlighted
 * is that speed (the byte argument state + 0xF wraps to it). osd_edit_value holds the speed stored when the
 * list was opened; its mark is cleared while the cursor is on it and drawn again on the other speeds.
 */
void osd_select_next_pixel_shift_speed(void)
{
  int speed;

  osd_clear_choice_highlight(osd_menu_state + 0xf);
  do {
    speed = (unsigned short)osd_menu_state - 0xf0;
    speed = speed % PIXEL_SHIFT_SPEED_COUNT;
    osd_menu_state = speed + MENU_STATE_PIXEL_SHIFT_SPEED_LIST;
  } while (osd_is_choice_enabled(speed) != 1);
  osd_highlight_choice_row(osd_menu_state + 0xf, CHOICE_ROW_EDGED);
  user_settings_pixel_shift = osd_menu_state + 0xf;
  {
    unsigned char saved_speed = osd_edit_value;
    if (osd_menu_state - MENU_STATE_PIXEL_SHIFT_SPEED_LIST == saved_speed)
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved_speed, CHOICE_MARK_OFF);
    else
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved_speed, CHOICE_MARK_ON);
  }
}
