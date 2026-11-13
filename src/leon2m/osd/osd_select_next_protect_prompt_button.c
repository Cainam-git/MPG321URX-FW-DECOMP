/* osd_select_next_protect_prompt_button  (FUN_a00b27fc)
 *
 * Move to the next button of the panel protect prompt (right key)
 * Note: Skips buttons that do not apply; stores the choice in bit 15 of 0xA802D002 for buttons 0 and 1.
 * Name basis: derived - handler table 0xA802422C: right on state 0x10A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b27fc @ 0xa00b27fc-0xa00b2a1c (136 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Source form: the two bail-out tests on half_0x12 / half_0x10 and the two byte tests are separate ifs; the
 * wrap-around uses '& 3' in the layout 3 arm with bit 15 set and '% 3' elsewhere.
 */
/* Fields of the application state record used here. */
struct app_state_fields {
    unsigned char pad0[0xe];
    unsigned short half_0xe;           /* bit 15: the highlighted button is 0 or 1 (copied from osd_edit_value) */
    unsigned short half_0x10;
    unsigned short half_0x12;
    unsigned char pad14[4];
    struct { unsigned short bit15 : 1, rest : 15; } half_0x18;    /* bit 15 picks the step: see osd_select_next_protect_prompt_button */
    unsigned char pad1a[0x25];
    unsigned char dialog_button_index;   /* +0x3F */
};
/* Fields of the settings record used here. */
struct user_settings_record {
    unsigned char pad[0x1dc];
    unsigned int oled_care_flags;      /* bit 31 Panel Protect run, bit 30 Panel Protect request */
    unsigned char pad1e0[2];
    unsigned char byte_0x1e2, byte_0x1e3, byte_0x1e4, byte_0x1e5;
};
extern struct app_state_fields app_state_record;
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern void osd_highlight_dialog_button(unsigned char, unsigned char);

/* Right key on the panel protect prompt (menu state 0x10A): move the highlight to the next button.
 * Does nothing while (half_0x12 is 5, settings oled_care_flags bit 30 is set and dialog_button_index is 0),
 * or (half_0x10 is 4, bit 31 is set and dialog_button_index is 0), or settings byte +0x1E4 or +0x1E5 is 1.
 * Otherwise osd_edit_value (the highlighted button) is stepped on and the dialog is redrawn through
 * osd_highlight_dialog_button:
 *   dialog_button_index not 0: layout 3; the value goes up by 1 modulo 4 (half_0x18 bit 15 set) or modulo 3;
 *     when settings byte +0x1E2 is above 2 a value of 1 is moved on to 2;
 *   dialog_button_index 0: layout 2 (half_0x18 bit 15 set): the value goes up by 2 modulo 3, i.e. down by 1;
 *     layout 1 (bit clear): the value toggles between 0 and 1.
 * A choice of 0 or 1 is stored in bit 15 of half_0xe. Reached through the key handler table; no direct caller. */
void osd_select_next_protect_prompt_button(void)
{
    /* Nothing moves in these three cases (see the block comment). */
    if (app_state_record.half_0x12 == 5 && (user_settings.oled_care_flags & 0x40000000) && app_state_record.dialog_button_index == 0)
        return;
    if (app_state_record.half_0x10 == 4 && (int)user_settings.oled_care_flags < 0 && app_state_record.dialog_button_index == 0)
        return;
    if (user_settings.byte_0x1e4 == 1)
        return;
    if (user_settings.byte_0x1e5 == 1)
        return;
    if (app_state_record.dialog_button_index != 0) {
        /* Prompt with three or four buttons (dialog layout 3). */
        if (app_state_record.half_0x18.bit15)
            osd_edit_value = (osd_edit_value + 1) & 3;
        else
            osd_edit_value = (osd_edit_value + 1) % 3;
        /* Button 1 is skipped when settings byte +0x1E2 is above 2. */
        if (user_settings.byte_0x1e2 > 2 && osd_edit_value == 1)
            osd_edit_value++;
        osd_highlight_dialog_button(3, osd_edit_value);
    } else if (app_state_record.half_0x18.bit15) {
        osd_edit_value = (osd_edit_value + 2) % 3;
        osd_highlight_dialog_button(2, osd_edit_value);
    } else {
        osd_edit_value = 1 - osd_edit_value;
        osd_highlight_dialog_button(1, osd_edit_value);
    }
    /* A choice of 0 or 1 goes to bit 15 of half_0xe; 2 and 3 are not stored. */
    if ((unsigned char)(osd_edit_value - 2) > 1)
        app_state_record.half_0xe = (app_state_record.half_0xe & 0x7fff) | (osd_edit_value << 15);
}
