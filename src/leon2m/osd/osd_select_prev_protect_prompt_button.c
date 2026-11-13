/* osd_select_prev_protect_prompt_button  (FUN_a00b2a1c)
 *
 * Move to the previous button of the panel protect prompt (left key)
 * Note: Skips buttons that do not apply; stores the choice in bit 15 of 0xA802D002 for buttons 0 and 1.
 * Name basis: derived - handler table 0xA802422C: left on state 0x10A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b2a1c @ 0xa00b2a1c-0xa00b2c18 (127 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Source form: the two bail-out tests on half_0x12 / half_0x10 and the two byte tests are separate ifs; the
 * backward steps are written '+ 3' / '+ 2' with '& 3', '+ 1' with '% 3' and '+ 1' with '& 1'.
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

/* Left key on the panel protect prompt (menu state 0x10A): move the highlight to the previous button.
 * The mirror of osd_select_next_protect_prompt_button, with the same bail-out conditions:
 *   dialog_button_index not 0: layout 3; the value goes up by 3 modulo 4 (down by 1; half_0x18 bit 15 set) or
 *     by 2 modulo 4; when settings byte +0x1E2 is above 2 a value of 1 is moved back to 0;
 *   dialog_button_index 0: layout 2 (half_0x18 bit 15 set): the value goes up by 1 modulo 3; layout 1 (bit
 *     clear): the value toggles between 0 and 1.
 * A choice of 0 or 1 is stored in bit 15 of half_0xe. Reached through the key handler table; no direct caller. */
void osd_select_prev_protect_prompt_button(void)
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
            osd_edit_value = (osd_edit_value + 3) & 3;
        else
            osd_edit_value = (osd_edit_value + 2) & 3;
        /* Button 1 is skipped when settings byte +0x1E2 is above 2. */
        if (user_settings.byte_0x1e2 > 2 && osd_edit_value == 1)
            osd_edit_value--;
        osd_highlight_dialog_button(3, osd_edit_value);
    } else if (app_state_record.half_0x18.bit15) {
        osd_edit_value = (osd_edit_value + 1) % 3;
        osd_highlight_dialog_button(2, osd_edit_value);
    } else {
        osd_edit_value = (osd_edit_value + 1) & 1;
        osd_highlight_dialog_button(1, osd_edit_value);
    }
    /* A choice of 0 or 1 goes to bit 15 of half_0xe; 2 and 3 are not stored. */
    if ((unsigned char)(osd_edit_value - 2) > 1)
        app_state_record.half_0xe = (app_state_record.half_0xe & 0x7fff) | (osd_edit_value << 15);
}
