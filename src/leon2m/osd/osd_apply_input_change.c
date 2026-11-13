/* osd_apply_input_change  (FUN_a00b8804)
 *
 * Restart the display path for a new input, mark settings changed and close the menu.
 * Note: Sets bit 10 of halfword 0xA802CFF4 and re-arms the port events.
 * Name basis: derived - callers osd_select_input_hdmi1/hdmi2/dp/type_c, osd_accept_input_quick_menu
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b8804 @ 0xa00b8804 (-mcpu=v8 -O3 -g)
 * Source form the exact build depends on: the six parameters exist and are passed on to osd_close_menu, which is
 * declared without a parameter list; the callers pass none, two (0, 1) or other values.
 */
#define APP_STATE_BIT10 0x400                   /* app_state_record flag bit set when the input changes */
#define OSD_REQUEST_SETTINGS_CHANGED 2          /* osd_request_bits bit 1 */

extern unsigned char osd_request_bits;
extern unsigned short app_state_record;         /* flag halfword at +0 */
extern int input_rearm_port_event();
extern int osd_close_menu();
extern int sys_user_reset_display_path();

/*
 * Make the display path follow a newly chosen input, then close the menu.
 *
 * In this order: restart the display path (channels, ports and panel), set bit 10 of the application state
 * flags (osd_draw_input_info_banner tests it afterwards), re-arm the event of port 0 without forcing it (arguments 0, 0), request
 * "settings changed" and close the menu.
 *
 * Called by osd_select_input_hdmi1/hdmi2/dp/type_c and osd_accept_input_quick_menu. The six parameters are only
 * handed on to osd_close_menu, which does not use them; some callers pass (0, 1).
 */
void osd_apply_input_change(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                            unsigned int arg5, unsigned int arg6)
{
    sys_user_reset_display_path();
    app_state_record = app_state_record | APP_STATE_BIT10;
    input_rearm_port_event(0, 0);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
    osd_close_menu(arg1, arg2, arg3, arg4, arg5, arg6);
}
