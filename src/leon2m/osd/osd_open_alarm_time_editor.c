/* osd_open_alarm_time_editor  (FUN_a0093884)
 *
 * Open the minutes:seconds editor for the highlighted alarm timer.
 * Note: Copies the timer's preset (settings arrays +0x198/+0x19C) to the edit bytes +0x8C/+0x8D; state 0xC5.
 * Name basis: derived - OK/right on states 0x58..0x5B; editor draws mm:ss (osd_draw_alarm_clock_choices 'n%d%d
 *   : %d%d')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093884, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a struct with the two 4-byte timer tables as array fields (a flat byte
 * array gives load/store/load/store); the copy to +0x8C comes first in the source and both table loads are done
 * before both stores. The menu state is stored with the constant 0xC5 after the cursor row is stored.
 */
#define MENU_STATE_ALARM_TIME_LIST   0x58       /* + row: the Alarm Clock time list, one state per timer */
#define MENU_STATE_ALARM_TIME_EDITOR 0xc5       /* + digit 0..3: minutes tens, minutes units, seconds tens, seconds units */
#define KEY_TEXT_ADJUST              3          /* key guide texts: Move, Enter, Switch, Adjust, Select, Save, ... */
#define KEY_TEXT_SAVE                5

/* The fields of the user settings record used here. */
struct user_settings_record {
  unsigned char pad[0x8c];
  unsigned char byte_0x8c;                      /* +0x8C: receives the timer's minutes */
  unsigned char byte_0x8d;                      /* +0x8D: receives the timer's seconds */
  unsigned char pad2[0x198 - 0x8e];
  unsigned char alarm_minutes_table[4];         /* +0x198: minutes of timers 1..4 */
  unsigned char alarm_seconds_table[4];         /* +0x19C: seconds of timers 1..4 */
  unsigned char pad3[0x1a3 - 0x1a0];
  unsigned char alarm_cursor_row;               /* +0x1A3: the timer being edited (0..3) */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern void osd_draw_key_guide(int, int);
extern void osd_draw_key_guide_text(int);
extern void osd_update_key_guide(int, int);
extern void osd_draw_alarm_time_editor(int);
extern void osd_draw_alarm_digit_cursor(int, int);

/*
 * OK or right key on a timer of the Alarm Clock time list (menu states 0x58..0x5B): open the minutes:seconds
 * editor for that timer. The timer's row (state - 0x58) is stored in settings byte +0x1A3, the menu state
 * becomes 0xC5 (the first digit), the time is drawn with the editor frame (argument 1) and the cursor is put on
 * the first digit. The timer's minutes and seconds are copied to settings +0x8C and +0x8D, and the key guide is
 * drawn with the texts Adjust and Save.
 */
void osd_open_alarm_time_editor(void)
{
  struct user_settings_record *settings = &user_settings;

  settings->alarm_cursor_row = osd_menu_state - MENU_STATE_ALARM_TIME_LIST;
  osd_menu_state = MENU_STATE_ALARM_TIME_EDITOR;
  osd_draw_alarm_time_editor(1);
  osd_draw_alarm_digit_cursor(0, 1);
  settings->byte_0x8c = settings->alarm_minutes_table[settings->alarm_cursor_row];
  settings->byte_0x8d = settings->alarm_seconds_table[settings->alarm_cursor_row];
  osd_draw_key_guide(2, 1);
  osd_draw_key_guide(0, 0);
  osd_draw_key_guide(1, 3);
  osd_draw_key_guide_text(0);
  osd_update_key_guide(KEY_TEXT_ADJUST, KEY_TEXT_SAVE);
}
