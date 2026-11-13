/* osd_open_change_notice  (FUN_a00a01b8)
 *
 * Show the mode change notice (menu state 0x116)
 * Note: No reference to it was found in the handler or event tables.
 * Name basis: derived - state 0x116 is closed by osd_close_change_notice; same sequence inside
 *   osd_enter_game_mode_choices
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a01b8, flags -mcpu=v8 -O3 -g.
 * Source form: the request bit is set with '|= 2' on the byte; the tick value is stored as an unsigned short.
 */
extern unsigned char osd_request_bits;
extern unsigned char user_settings_notice_button;
extern unsigned short osd_message_ticks;
extern unsigned int osd_menu_state;
extern void osd_show_change_notice(void);
extern unsigned short timer_get_ticks16(void);

#define MENU_STATE_CHANGE_NOTICE   0x116        /* the mode change notice is shown */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * Show the mode change notice dialog (osd_show_change_notice) and set menu state 0x116. Also sets the
 * settings-changed request bit, clears settings byte +0x1AA (the notice button) and stores the present time
 * in osd_message_ticks.
 *
 * No handler or event table refers to this routine.
 */
void osd_open_change_notice(void)
{
  osd_show_change_notice();
  osd_menu_state = MENU_STATE_CHANGE_NOTICE;
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
  user_settings_notice_button = 0;
  osd_message_ticks = timer_get_ticks16();
}
