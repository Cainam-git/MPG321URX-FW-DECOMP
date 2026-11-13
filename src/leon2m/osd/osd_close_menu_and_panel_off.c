/* osd_close_menu_and_panel_off  (FUN_a009e780)
 *
 * Close the quick menu or message and switch the panel off unless channel 0 is in state 10.
 * Note: Same start as osd_factory_close_menu; panel off via SYSAPI_PanelOnOffControl(0, 0).
 * Name basis: derived - handler table 0xA802422C: OK on the quick menus 0xFA..0x105 and the messages 0x10B,
 *   0x10D..0x10F (all keys on 0x10F)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e780, flags -mcpu=v8 -O3 -g. No direct callers (reached through the key handler table).
 * Exact form: the two bits are 1-bit bit-fields of the halfword at app_state_record + 4, cleared bit 7 first,
 * then bit 15 (the compiler merges them into one 'and' with 0x7f7f; the mask form or the other order puts the
 * halfword store after the word store). The first five statements are the same as in osd_factory_close_menu.
 */
/* The halfword at +4 of the application state record; only bits 7 and 15 (counted from the low end) are used here. */
struct app_state_record_head { unsigned char pad[4]; unsigned short bit15 : 1, mid : 7, bit7 : 1, low : 7; };
extern struct app_state_record_head app_state_record;
extern unsigned int osd_menu_state;
extern unsigned char user_settings_burn_in_flag;
extern void sys_set_app_flag_bit3(int);
extern void osd_hide_menu(void);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern void input_rearm_port_event(int, int);
extern void SYSAPI_PanelOnOffControl(int, int);

#define MAIN_CHANNEL        0
#define CHANNEL_STATE_CODE_10 10        /* channel state code (sys_api_get_channel_state_code) */
#define ALL_PORTS           4           /* port argument of input_rearm_port_event: all ports */

/*
 * OK on the quick menus and messages that this handler serves (menu states 0xFA to 0x105 and 0x10B, 0x10D to
 * 0x10F): close the menu and switch the panel off, unless channel 0 reports state code 10.
 *
 * The first steps are those of osd_factory_close_menu: clear application flag bit 3, clear bits 7 and 15 of
 * the halfword at +4 of the application state record, set the menu state to 0 and hide the menu layer. When the
 * burn-in flag (settings byte +0x1D5) is on, the last-state bytes of all ports are then reset
 * (input_rearm_port_event).
 */
void osd_close_menu_and_panel_off(void)
{
    sys_set_app_flag_bit3(0);
    app_state_record.bit7 = 0;
    app_state_record.bit15 = 0;
    osd_menu_state = 0;
    osd_hide_menu();
    if (user_settings_burn_in_flag != 0 && sys_api_get_channel_state_code(MAIN_CHANNEL) != CHANNEL_STATE_CODE_10)
        input_rearm_port_event(ALL_PORTS, 0);
    if (sys_api_get_channel_state_code(MAIN_CHANNEL) != CHANNEL_STATE_CODE_10)
        SYSAPI_PanelOnOffControl(0, 0);
}
