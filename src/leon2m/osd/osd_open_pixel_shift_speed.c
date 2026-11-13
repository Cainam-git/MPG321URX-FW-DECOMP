/* osd_open_pixel_shift_speed  (FUN_a009a198)
 *
 * Open the Pixel Shift speed list (Slow, Normal, Fast) from the on/off list.
 * Note: States 0xF1..0xF3; draws the choice list with osd_draw_oled_care_choices.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0xBA
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a198 @ 0xa009a198-0xa009a1ec (21 words), flags -mcpu=v8 -O3 -g.
 * osd_draw_oled_care_choices takes ONE argument (the second argument register of that call holds a left-over
 * value, the 'mov 1, %i1' in its delay slot belongs to the tail call). Source form: the speed byte is reached
 * through a struct pointer and read again after the calls.
 */
struct user_settings_record { unsigned char pad[0x1dd]; unsigned char pixel_shift_speed; /* +0x1DD */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_column(void);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_oled_care_choices(unsigned int);

#define MENU_STATE_PIXEL_SHIFT_SPEED 0xba /* the Pixel Shift speed row of the Pixel Shift choices */
#define MENU_STATE_PIXEL_SHIFT_SPEED_LIST 0xf1 /* + speed: the Pixel Shift speed list (states 0xF1..0xF3) */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on state 0xBA of the Pixel Shift choices: open the Pixel Shift speed list (Slow, Normal, Fast) on
 * the speed now stored (settings byte +0x1DD).
 *
 * The speed is saved in osd_edit_value for the left key. The highlight of the cursor row (state - 0xB8, written
 * as state + 0x48 in the byte argument) is removed, the choice column is cleared and the choices of state 0xBA
 * are drawn (osd_draw_oled_care_choices). The menu state becomes 0xF1 plus the speed and the speed's row is
 * highlighted with edge glyphs.
 */
void osd_open_pixel_shift_speed(void)
{
  struct user_settings_record *p = &user_settings;

  osd_edit_value = p->pixel_shift_speed;
  osd_clear_choice_highlight(osd_menu_state + 0x48);
  osd_clear_choice_column();
  osd_draw_oled_care_choices(MENU_STATE_PIXEL_SHIFT_SPEED);
  osd_menu_state = p->pixel_shift_speed + MENU_STATE_PIXEL_SHIFT_SPEED_LIST;
  osd_highlight_choice_row(p->pixel_shift_speed, CHOICE_ROW_EDGED);
}
