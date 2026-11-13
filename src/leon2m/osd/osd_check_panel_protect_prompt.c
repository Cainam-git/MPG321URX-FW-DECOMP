/* osd_check_panel_protect_prompt  (FUN_a009f184)
 *
 * Show the OLED panel protect prompt (Execute, Cancel, Later) when it is due.
 * Note: Compares the Protect Notice setting (+0x1EE) and settings byte +0x1E2 with halfword 0xA802D004; state
 *   0x10A.
 * Name basis: derived - sets menu state 0x10A whose handlers draw texts 0x190184 'Execute|Cancel|Later|More
 *   Info'; called by osd_run_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: the 0x10a store comes once after the inner if/else; in the 'byte_0x1e2 > 2' arm dialog_button_index
 * is written before bit 15 of half_0x18. The bit-fields are tested and set as members of a record (each halfword as a
 * bit-field struct).
 */

#define MENU_STATE_PANEL_PROTECT_PROMPT 0x10a   /* Execute / Cancel / Later / More Info */
#define OSD_REQUEST_SETTINGS_CHANGED    0x02    /* bit 1 of osd_request_bits */

struct bit15_half { unsigned short bit15 : 1, rest : 15; };

/* Application state record: the halfwords and bytes used here. */
struct app_state_fields {
    unsigned char pad[4];
    unsigned short bit15 : 1, bits14_11 : 4, bit10 : 1, rest : 10;   /* halfword +4 */
    unsigned char pad6[0xe - 6];
    struct bit15_half half_0xe;        /* bit 15: first-highlighted button (1 Execute, 0 Cancel) */
    unsigned short half_0x10;          /* 0xA802D004: compared with the stored settings byte +0x1E2 */
    unsigned char pad12[0x18 - 0x12];
    struct bit15_half half_0x18;       /* bit 15: Later button shown */
    unsigned char pad1a[0x3f - 0x1a];
    unsigned char dialog_button_index;
};

/* Settings: the Panel Protect step and its flags, and the Protect Notice. */
struct protect_settings {
    unsigned char pad0[0x1e2];
    unsigned char byte_0x1e2;
    unsigned char pad1e3;
    unsigned char byte_0x1e4;
    unsigned char pad1e5;
    unsigned char byte_0x1e6;
    unsigned char pad1e7[0x1ee - 0x1e7];
    unsigned char protect_notice;
};
extern struct app_state_fields app_state_record;
extern struct protect_settings user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_edit_value, osd_choice_row;
extern unsigned char osd_request_bits;
extern void input_rearm_port_event(unsigned char n, unsigned char f);
extern void osd_hide_menu(void);
extern unsigned char sys_led_bar_get_flag10(void);
extern unsigned char sys_led_bar_get_status_code(unsigned char p);
extern void sys_led_bar_send_mode_command(unsigned char n);
extern void osd_draw_panel_protect_prompt(unsigned char id, unsigned char m);
extern void osd_draw_panel_protect_dialog(unsigned char, unsigned char);

/*
 * Decide whether the OLED panel protect prompt is due, and show it. Called from the periodic task, with no
 * parameters and no result.
 * Three cases, tested in this order:
 *   1. Protect Notice is 1, byte_0x1e2 differs from half_0x10 and half_0x10 is at most 3: byte_0x1e2 takes over
 *      half_0x10, a settings save is requested and that is all.
 *   2. byte_0x1e2 differs from half_0x10, or byte_0x1e6 is 1, and half_0x10 is not 0: the menu is closed and the
 *      prompt is shown (menu state 0x10A), unless LED bar flag 10 is set, in which case only the LED bar mode
 *      command is sent. When byte_0x1e2 equals half_0x10, byte_0x1e6 is 1 and byte_0x1e2 is not 0, the dialog page
 *      is drawn instead of the prompt.
 *   3. Otherwise, when byte_0x1e4 is set: the menu is closed and dialog page 0 is drawn with mode 4 (or the LED bar
 *      command is sent, as above).
 * In cases 2 and 3 a settings save is requested at the end.
 */
void osd_check_panel_protect_prompt(void)
{
    /* Protect Notice on and the stored step is behind: take over the step (at most 3) and only save; no prompt. */
    if (user_settings.protect_notice == 1 && user_settings.byte_0x1e2 != app_state_record.half_0x10 && app_state_record.half_0x10 <= 3) {
        user_settings.byte_0x1e2 = app_state_record.half_0x10;
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        return;
    }
    /* The step changed (or byte_0x1e6 is 1) and the step is not 0: close the menu and show the prompt. */
    if ((user_settings.byte_0x1e2 != app_state_record.half_0x10 || user_settings.byte_0x1e6 == 1) && app_state_record.half_0x10 != 0) {
        /* Bit 15 of the halfword at +4 set: set its bit 10 and re-arm the ports. */
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(4, 0);
        }
        osd_menu_state = 0;
        osd_hide_menu();
        /* LED bar flag 10 set: no prompt; the LED bar gets its mode command instead. */
        if (sys_led_bar_get_flag10() == 1) {
            osd_choice_row = 0;
            sys_led_bar_send_mode_command(sys_led_bar_get_status_code(0));
        } else {
            app_state_record.half_0xe.bit15 = 1;
            osd_choice_row = 0;
            /* Same step as stored, byte_0x1e6 is 1 and the step is not 0: dialog page for step 0x1E2 - 1 (byte_0x1e4 cleared). */
            if (user_settings.byte_0x1e2 == app_state_record.half_0x10 && user_settings.byte_0x1e6 == 1 && user_settings.byte_0x1e2 != 0) {
                if (user_settings.byte_0x1e4 != 0)
                    user_settings.byte_0x1e4 = 0;
                osd_draw_panel_protect_dialog(osd_choice_row, user_settings.byte_0x1e2 - 1);
            } else {
                /* Otherwise the prompt itself: above step 2 the Later button is hidden and variant 3 is drawn. */
                if (user_settings.byte_0x1e2 > 2) {
                    app_state_record.dialog_button_index = 2;
                    app_state_record.half_0x18.bit15 = 0;
                    osd_draw_panel_protect_prompt(0, 3);
                } else {
                    app_state_record.dialog_button_index = 1;
                    if (user_settings.protect_notice == 0)
                        app_state_record.half_0x18.bit15 = 1;
                    else
                        app_state_record.half_0x18.bit15 = 0;
                    osd_draw_panel_protect_prompt(0, user_settings.byte_0x1e2);
                }
                osd_edit_value = 0;
            }
            osd_menu_state = MENU_STATE_PANEL_PROTECT_PROMPT;
        }
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    } else if (user_settings.byte_0x1e4 != 0) {
        /* No new step, but byte_0x1e4 is set: the same close-menu steps, then dialog page 0 with mode 4 (Execute). */
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(4, 0);
        }
        osd_menu_state = 0;
        osd_hide_menu();
        if (sys_led_bar_get_flag10() == 1) {
            osd_choice_row = 0;
            sys_led_bar_send_mode_command(sys_led_bar_get_status_code(0));
        } else {
            osd_draw_panel_protect_dialog(0, 4);
            osd_menu_state = MENU_STATE_PANEL_PROTECT_PROMPT;
        }
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    }
}
