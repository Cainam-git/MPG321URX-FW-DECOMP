/* osd_show_no_signal_with_input  (FUN_a009e91c)
 *
 * Show the input name with 'No Signal' when the active input has no signal.
 * Note: Menu state 0x10D; only when word 0xA802E1A0 is negative; drawn by osd_draw_no_signal_with_input (page
 *   0x19).
 * Name basis: derived - application event table 0xA80241B0 entry 4; osd_draw_signal_message page 0x19 texts
 *   0x196B24 + 0x193008 'No Signal'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e91c, flags -mcpu=v8 -O3 -g. No direct callers (reached through the application event table).
 * Source form: user_settings is declared as a plain unsigned word (only word 0 is read); device_settings as a
 * signed int, so that the power status bit tests as negative; the byte at +1 of the application state record
 * is written through a bare data label. The last call is a tail call.
 */
extern unsigned int user_settings;
extern unsigned int osd_menu_state;
extern int device_settings;
extern unsigned char DAT_a802cff5;
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern void osd_draw_no_signal_with_input(void);

#define MAIN_CHANNEL            0
#define CHANNEL_STATE_CODE_10   10      /* channel state code (sys_api_get_channel_state_code) */
#define SETTINGS_WORD0_BIT9     0x200   /* bit 9 of user settings word 0 */
#define MENU_STATE_FE           0xfe
#define MENU_STATE_NO_SIGNAL    0x10d   /* the no-signal message */

/*
 * Application event 4 (event table at 0xA80241B0): show the input name with 'No Signal'.
 *
 * Nothing happens unless the power status bit (bit 31) of the device settings word 0 is set. Beyond that, the
 * message is shown when channel 0 reports state code 10, or user settings word 0 has bit 9 set, or the menu
 * state is not 0xFE. It sets menu state 0x10D, clears the byte at +1 of the application state record and
 * draws the message (osd_draw_no_signal_with_input).
 */
void osd_show_no_signal_with_input(void)
{
    if ((sys_api_get_channel_state_code(MAIN_CHANNEL) == CHANNEL_STATE_CODE_10 || (user_settings & SETTINGS_WORD0_BIT9) || osd_menu_state != MENU_STATE_FE) && device_settings < 0) {
        osd_menu_state = MENU_STATE_NO_SIGNAL;
        DAT_a802cff5 = 0;
        osd_draw_no_signal_with_input();
    }
}
