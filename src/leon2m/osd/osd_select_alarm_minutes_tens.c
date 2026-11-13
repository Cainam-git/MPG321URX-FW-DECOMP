/* osd_select_alarm_minutes_tens  (FUN_a0093910)
 *
 * Put the alarm time cursor on the tens digit of the minutes.
 * Note: Menu state 0xC5.
 * Name basis: derived - left from 0xC6; drawn at column 0x2A/0x2B/0x2D/0x2E of the mm:ss field by
 *   osd_draw_alarm_digit_cursor
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093910, flags -mcpu=v8 -O2 -g.
 * Source form: the routine takes six unsigned int parameters; the last four are passed on to
 * osd_draw_alarm_digit_cursor, which is declared without a prototype, as in the firmware.
 */
#define MENU_STATE_ALARM_TIME_EDITOR 0xc5       /* + digit 0..3: minutes tens, minutes units, seconds tens, seconds units */

extern unsigned int osd_menu_state;
extern int osd_draw_alarm_time_editor();
extern int osd_draw_alarm_digit_cursor();

/*
 * Alarm time editor: put the cursor on the tens digit of the minutes (digit 0). The menu state becomes
 * 0xC5 + digit, the time is redrawn without the editor frame (argument 0), and the cursor is placed on the digit.
 * Parameters 3 to 6 are passed on unchanged; parameters 1 and 2 are not used.
 */
void osd_select_alarm_minutes_tens(unsigned int unused_1, unsigned int unused_2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_menu_state = MENU_STATE_ALARM_TIME_EDITOR;
  osd_draw_alarm_time_editor(0);
  osd_draw_alarm_digit_cursor(0,1,arg3,arg4,arg5,arg6);
  return;
}
