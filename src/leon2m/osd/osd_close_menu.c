/* osd_close_menu  (FUN_a0090fd8)
 *
 * Close the on-screen menu and clear the menu state.
 * Note: When bit 15 of the status halfword 0xA802CFF8 is set, also re-arms all port events.
 * Name basis: derived - clears the menu state and hides the menu window (osd_hide_menu); called by many menu
 *   exits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0090fd8, flags -mcpu=v8 -O3 -g.
 * Called from many routines (ShowLogo, osd_show_change_notice, uart_cmd_set_refresh_rate_custom_position and others). The halfword is a union of a
 * plain halfword (for the | 0x400) and a bit-field view (bit 15).
 */

#define APP_STATE_HALF4_BIT10  0x400            /* bit 10 of the halfword at app_state_record + 4 */
#define MENU_STATE_CLOSED      0

union app_state_half { unsigned short value; struct { unsigned short bit15 : 1, rest : 15; } bits; };
struct app_state_record_layout { unsigned char pad0[4]; union app_state_half half_0x4; };
extern struct app_state_record_layout app_state_record;
extern unsigned int osd_menu_state;
extern void input_rearm_port_event(int, int);
extern void osd_hide_menu(void);

/*
 * Close the menu. When bit 15 of the halfword at app_state_record + 4 is set, bit 10 of it is set first and
 * input_rearm_port_event(4, 0) is called (port 4 stands for all ports). Then the menu state becomes 0 and the
 * menu layer is hidden.
 */
void osd_close_menu(void)
{
    if (app_state_record.half_0x4.bits.bit15) {
        app_state_record.half_0x4.value |= APP_STATE_HALF4_BIT10;
        input_rearm_port_event(4, 0);
    }
    osd_menu_state = MENU_STATE_CLOSED;
    osd_hide_menu();
}
