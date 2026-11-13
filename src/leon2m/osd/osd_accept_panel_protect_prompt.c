/* osd_accept_panel_protect_prompt  (FUN_a00b2d04)
 *
 * Run the chosen panel protect button: Execute, Cancel, Later or More Info.
 * Note: Updates the protect step bytes +0x1E2..+0x1E7 and the request bits of +0x1DC.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x10A; texts 0x190184; also called by
 *   osd_run_periodic_task and uart_cmd_answer_panel_protect
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b2d04 @ 0xa00b2d04-0xa00b3070, flags -mcpu=v8 -O3 -g. Called by osd_run_periodic_task and
 * uart_cmd_answer_panel_protect; also reached through the key handler table (OK on state 0x10A).
 * Source form: set_flag_and_clear_after_display() (store 1 through a byte pointer, then clear bit 8 of flags_0x0) is
 * a static helper inlined for +0x1e5 and +0x1e6; the bit-31 test is written 'w >> 31'; the care word is a
 * union of the plain word and bit-fields; 'osd_edit_value = 1 - osd_edit_value; first_bit15 = osd_edit_value;'.
 */
/* Fields of the application state record used here. */
struct app_state_fields {
    unsigned short flags_0x0;          /* bit 8 is cleared when a request byte is set */
    unsigned short h2, h4, h6, h8, ha, hc;
    unsigned short half_0xe_bit15 : 1, half_0xe_rest : 15;
    unsigned short half_0x10, half_0x12;
    unsigned char pad14[0x3f - 0x14];
    unsigned char dialog_button_index;
};
/* Fields of the settings record used here. */
struct user_settings_record {
    unsigned char pad[0x1dc];
    union { unsigned int w; struct { unsigned int run : 1, request : 1, rest : 30; } f; } oled_care_flags;   /* bit 31 Panel Protect run, bit 30 request */
    unsigned char pad1e0[2];
    unsigned char byte_0x1e2, byte_0x1e3, byte_0x1e4, byte_0x1e5, byte_0x1e6, byte_0x1e7;
    unsigned char pad1e8[6];
    unsigned char protect_notice;      /* +0x1EE */
};
extern struct app_state_fields app_state_record;
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value, osd_choice_row;
extern unsigned char osd_request_bits;
extern void osd_close_menu(void);
extern void osd_draw_panel_protect_dialog(unsigned char, unsigned char);
extern void osd_set_menu_state(unsigned short);
extern void oled_user_request_panel_refresh(unsigned char);

#define OSD_REQUEST_SETTINGS_CHANGED 0x02    /* bit 1 of osd_request_bits */
#define MENU_STATE_PANEL_PROTECT_PROMPT 0x10a

static void set_flag_and_clear_after_display(unsigned char *flag)
{
    *flag = 1;
    app_state_record.flags_0x0 &= ~0x100;
}

/* OK key on the panel protect prompt (menu state 0x10A), also called from osd_run_periodic_task and
 * uart_cmd_answer_panel_protect: carry out the highlighted button and store the result in the settings.
 * osd_edit_value is the highlighted button, dialog_button_index (+0x3F) 0 for the dialogs with two or three
 * buttons and not 0 for the prompt with three or four buttons, osd_choice_row 0 or 1 says which of the two
 * stored steps (+0x1E2 with +0x1E6, or +0x1E3 with +0x1E7) is being answered.
 * Order:
 *  1. When settings byte +0x1E4 or +0x1E5 is 1, clear the one(s) that are 1, request a settings save and close
 *     the menu; nothing else happens.
 *  2. Otherwise close the menu and read the button. In the prompt (dialog_button_index not 0), button 3, or
 *     button 2 when settings byte +0x1E2 is above 2, does not leave the menu: bit 15 of half_0xe is set,
 *     dialog_button_index cleared, osd_draw_panel_protect_dialog draws the next page (second argument
 *     min(+0x1E2, 3)) and the menu state goes to 0x10A. Button 2 otherwise clears bit 15 of half_0xe, sets
 *     Protect Notice (+0x1EE) and sets the Panel Protect run and request bits. Buttons 0 and 1 set bit 15 of
 *     half_0xe to 1 and 0 (osd_edit_value is flipped first). In the dialogs (dialog_button_index 0) button 2
 *     does the same as above, other buttons change nothing here.
 *  3. With both Panel Protect bits set: row 0 copies half_0x10 to +0x1E2 and writes bit 15 of half_0xe to
 *     +0x1E6; row 1 copies half_0x12 to +0x1E3 and sets +0x1E7 to 0 or 1 by the same bit. Setting +0x1E6 or
 *     +0x1E7 to 1 clears bit 8 of flags_0x0.
 *  4. When bit 15 of half_0xe is set: if the run bit is clear, set +0x1E4 to 1; if the request bit is clear,
 *     set +0x1E5 to 1 (both clear bit 8 of flags_0x0); then call oled_user_request_panel_refresh(row).
 *  5. Set the run and request bits and request a settings save. */
void osd_accept_panel_protect_prompt(void)
{
    if (user_settings.byte_0x1e4 == 1 || user_settings.byte_0x1e5 == 1) {
        if (user_settings.byte_0x1e4 == 1)
            user_settings.byte_0x1e4 = 0;
        if (user_settings.byte_0x1e5 == 1)
            user_settings.byte_0x1e5 = 0;
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        osd_close_menu();
        return;
    }
    osd_close_menu();
    if (osd_edit_value == 2 && app_state_record.dialog_button_index == 0) {
        app_state_record.half_0xe_bit15 = 0;
        user_settings.protect_notice = 1;
        user_settings.oled_care_flags.f.run = 1;
        user_settings.oled_care_flags.f.request = 1;
    } else if (app_state_record.dialog_button_index != 0) {
        if (osd_edit_value == 3 || (user_settings.byte_0x1e2 > 2 && osd_edit_value == 2)) {
            app_state_record.half_0xe_bit15 = 1;
            app_state_record.dialog_button_index = 0;
            if (user_settings.byte_0x1e2 > 2)
                osd_draw_panel_protect_dialog(osd_choice_row, 3);
            else
                osd_draw_panel_protect_dialog(osd_choice_row, user_settings.byte_0x1e2);
            osd_set_menu_state(MENU_STATE_PANEL_PROTECT_PROMPT);
            return;
        }
        if (osd_edit_value == 2) {
            app_state_record.half_0xe_bit15 = 0;
            user_settings.protect_notice = 1;
            user_settings.oled_care_flags.f.run = 1;
            user_settings.oled_care_flags.f.request = 1;
        } else {
            osd_edit_value = 1 - osd_edit_value;
            app_state_record.half_0xe_bit15 = osd_edit_value;
        }
    }
    if (osd_choice_row == 0 && (user_settings.oled_care_flags.w & 0xc0000000) == 0xc0000000) {
        user_settings.byte_0x1e2 = app_state_record.half_0x10;
        if (!app_state_record.half_0xe_bit15)
            user_settings.byte_0x1e6 = 0;
        else
            set_flag_and_clear_after_display(&user_settings.byte_0x1e6);
    }
    if (osd_choice_row == 1 && (user_settings.oled_care_flags.w & 0xc0000000) == 0xc0000000) {
        user_settings.byte_0x1e3 = app_state_record.half_0x12;
        if (!app_state_record.half_0xe_bit15)
            user_settings.byte_0x1e7 = 0;
        else {
            user_settings.byte_0x1e7 = osd_choice_row;
            app_state_record.flags_0x0 &= ~0x100;
        }
    }
    if (app_state_record.half_0xe_bit15) {
        if (!(user_settings.oled_care_flags.w >> 31)) {
            app_state_record.flags_0x0 &= ~0x100;
            user_settings.byte_0x1e4 = 1;
        }
        if (!(user_settings.oled_care_flags.w & 0x40000000))
            set_flag_and_clear_after_display(&user_settings.byte_0x1e5);
        oled_user_request_panel_refresh(osd_choice_row);
    }
    user_settings.oled_care_flags.f.run = 1;
    user_settings.oled_care_flags.f.request = 1;
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
