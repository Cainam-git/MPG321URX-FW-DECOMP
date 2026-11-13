/* osd_factory_close_menu  (FUN_a009e820)
 *
 * Close the factory menu and hide the menu layer (left key)
 * Note: Clears application flag bit 3 and the menu state; re-arms all port events when Burn In is on.
 * Name basis: derived - handler table 0xA802422C: left on state 0x111 (factory menu)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e820, flags -mcpu=v8 -O3 -g. No direct callers (reached through the key handler table).
 * Exact form: the two bits are 1-bit bit-fields of the halfword at app_state_record + 4, cleared bit 7 first,
 * then bit 15 (the compiler merges them into one 'and' with 0x7f7f; the mask form or the other order puts the
 * halfword store after the word store). The last call is a tail call.
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

#define MAIN_CHANNEL          0
#define CHANNEL_STATE_CODE_10 10        /* channel state code (sys_api_get_channel_state_code) */
#define ALL_PORTS             4         /* port argument of input_rearm_port_event: all ports */

/*
 * Left key in the factory menu (menu state 0x111): close the menu.
 *
 * Clears application flag bit 3, clears bits 7 and 15 of the halfword at +4 of the application state record,
 * sets the menu state to 0 and hides the menu layer. When the burn-in flag (settings byte +0x1D5) is on and
 * channel 0 does not
 * report state code 10, the last-state bytes of all ports are reset (input_rearm_port_event).
 */
void osd_factory_close_menu(void)
{
    sys_set_app_flag_bit3(0);
    app_state_record.bit7 = 0;
    app_state_record.bit15 = 0;
    osd_menu_state = 0;
    osd_hide_menu();
    if (user_settings_burn_in_flag != 0 && sys_api_get_channel_state_code(MAIN_CHANNEL) != CHANNEL_STATE_CODE_10)
        input_rearm_port_event(ALL_PORTS, 0);
}
