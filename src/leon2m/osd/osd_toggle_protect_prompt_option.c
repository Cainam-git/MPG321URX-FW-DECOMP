/* osd_toggle_protect_prompt_option  (FUN_a00b2c18)
 *
 * Move the highlight to the other button of the panel protect prompt and redraw both buttons.
 * Note: Flips bit 15 of app state halfword +0xE; does nothing in three cases (pending protect requests,
 *   settings byte +0x1E4 or +0x1E5 = 1). Nothing in the image refers to it.
 * Name basis: descriptive - flips bit 15 of 0xA802D002 and calls osd_highlight_dialog_button(1, bit)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b2c18 @ 0xa00b2c18, flags -mcpu=v8 -O3 -g. Leaf routine; the call to
 * osd_highlight_dialog_button is a tail call. Nothing in the image refers to it (no call, branch, address
 * constant or address word).
 * Source form: bit 15 of the halfword at +0xE is a one-bit bit-field set to (unsigned char)(1 - bit); the sign
 * test of the settings word is written (word >> 31) on the signed int (arithmetic shift), which gives the
 * firmware's block order.
 */
struct half_0xe_bits { unsigned short first_button_selected:1, rest:15; };
struct app_state_record_layout { unsigned char pad0[0xe]; struct half_0xe_bits half_0xe; unsigned short half_0x10, half_0x12; };
struct user_settings_record { unsigned char pad0[0x1dc]; int oled_care_flags; unsigned char pad1e0[4]; unsigned char byte_0x1e4, byte_0x1e5; };
extern struct app_state_record_layout app_state_record;
extern struct user_settings_record user_settings;
extern void osd_highlight_dialog_button(unsigned char dialog_layout, unsigned char selected);

#define OLED_CARE_PANEL_PROTECT_REQUEST 0x40000000   /* oled_care_flags bit 30 (bit 31 is the run flag) */
#define DIALOG_LAYOUT_PROTECT_PROMPT    1             /* osd_highlight_dialog_button layout 1: two buttons on row 0x16 */

/* Flip which of the two buttons of the panel protect prompt is highlighted (bit 15 of app_state_record
 * halfword +0xE; set = first button) and redraw the frames. Nothing happens when any of these holds:
 * app_state_record halfword +0x12 is 5 and the Panel Protect request bit is set; halfword +0x10 is 4 and the
 * Panel Protect run bit (bit 31) is set; user_settings byte +0x1E4 or +0x1E5 is 1. */
void osd_toggle_protect_prompt_option(void)
{
    if (app_state_record.half_0x12 == 5 && (user_settings.oled_care_flags & OLED_CARE_PANEL_PROTECT_REQUEST))
        return;
    if (app_state_record.half_0x10 == 4 && (user_settings.oled_care_flags >> 31))
        return;
    if (user_settings.byte_0x1e4 == 1 || user_settings.byte_0x1e5 == 1)
        return;
    app_state_record.half_0xe.first_button_selected = (unsigned char)(1 - app_state_record.half_0xe.first_button_selected);
    if (app_state_record.half_0xe.first_button_selected)
        osd_highlight_dialog_button(DIALOG_LAYOUT_PROTECT_PROMPT, 1);
    else
        osd_highlight_dialog_button(DIALOG_LAYOUT_PROTECT_PROMPT, 0);
}
