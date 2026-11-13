/* osd_draw_hdmi_cec_switch  (FUN_a00b7980)
 *
 * Draw the HDMI CEC switch, shown off while PIP/PBP is on.
 * Note: Value = bit 20 of settings word +0xAC and PIP/PBP byte +0x1F == 0.
 * Name basis: proven - row 6 of the Settings items (first page)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7980 @ 0xa00b7980-0xa00b79cc (19 words; the firmware nop at 0xa00b79cc is padding), flags
 * -mcpu=v8 -O3 -g.
 * Source form: one record user_settings reached through a struct pointer (the firmware builds the address once
 * and both reads go off it); the callee is declared void; both draw calls are tail calls.
 */
#define SETTINGS_ITEM_HDMI_CEC 6                /* item number on the Settings page */
#define HDMI_CEC_BIT 0x100000                   /* bit 20 of settings word +0xAC */

struct user_settings_record {
    unsigned char pad[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = one picture */
    unsigned char pad20[0x8c];
    unsigned int  settings_page_flags;          /* +0xAC */
};
extern struct user_settings_record user_settings;
extern void osd_draw_toggle_switch(int, int);

/* Draw the HDMI CEC switch: on only when bit 20 of settings word +0xAC is set and the PIP/PBP mode byte is 0;
   otherwise it is drawn off. */
void osd_draw_hdmi_cec_switch(void)
{
    struct user_settings_record *settings = &user_settings;

    if ((settings->settings_page_flags & HDMI_CEC_BIT) != 0 && settings->pip_pbp_mode == 0) {
        osd_draw_toggle_switch(SETTINGS_ITEM_HDMI_CEC, 1);
        return;
    }
    osd_draw_toggle_switch(SETTINGS_ITEM_HDMI_CEC, 0);
}
