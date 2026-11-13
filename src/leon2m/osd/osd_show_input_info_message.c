/* osd_show_input_info_message  (FUN_a009e894)
 *
 * Show the input information banner (input name, console, HDR) after a signal change.
 * Note: Menu state 0x10F unless the Screen Size item (0x1C) is open and sys_user_get_picture_state returns 0;
 *   draws page 0x1E or 0x11 via osd_draw_input_info_banner.
 * Name basis: derived - application event table 0xA80241B0 entry 0x0E; osd_draw_signal_message page 0x1E texts
 *   0x196B24 / 0x192860 (input, CEC device)
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: sys_user_get_picture_state and osd_draw_input_info_banner take no argument; the 'mov 0x10f,%o0'
 * in the delay slot after the first test is the store value, and the 1/0 set-up before osd_draw_input_info_banner
 * belongs to the hoisted osd_api_enable(1, 0) call.
 */

#define MENU_STATE_SCREEN_SIZE_ITEM   0x1c    /* Screen Size item of the Image tab */
#define MENU_STATE_INPUT_INFO_MESSAGE 0x10f   /* state the input information banner runs in */
#define APP_STATE_AFTER_DISPLAY       0x100   /* bit 8 of the first halfword of app_state_record */

extern unsigned int osd_menu_state;
extern unsigned short app_state_record;       /* first halfword of the application state record */
extern unsigned short osd_message_ticks;      /* tick count when the banner was drawn */
extern void osd_draw_input_info_banner(void);
extern int sys_user_get_picture_state(void);
extern void osd_api_enable(unsigned int, unsigned int);
extern unsigned short timer_get_ticks16(void);

/*
 * Show the input information banner. The menu state is set to MENU_STATE_INPUT_INFO_MESSAGE, except when the
 * state is the Screen Size item and sys_user_get_picture_state returns 0: then that item stays open and
 * osd_api_enable(1, 0) is called. The banner is drawn by osd_draw_input_info_banner, the tick count of that moment is
 * saved in osd_message_ticks, and bit 8 of the first halfword of app_state_record is set.
 */
void osd_show_input_info_message(void)
{
    if (osd_menu_state != MENU_STATE_SCREEN_SIZE_ITEM || sys_user_get_picture_state() != 0)
        osd_menu_state = MENU_STATE_INPUT_INFO_MESSAGE;
    if (osd_menu_state == MENU_STATE_SCREEN_SIZE_ITEM)
        osd_api_enable(1, 0);
    osd_draw_input_info_banner();
    osd_message_ticks = timer_get_ticks16();
    app_state_record = app_state_record | APP_STATE_AFTER_DISPLAY;
}
