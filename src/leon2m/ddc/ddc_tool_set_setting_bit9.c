/* ddc_tool_set_setting_bit9  (FUN_a00d29c0)
 *
 * Tool command: write settings bit 9 and apply it when it changed.
 * Name basis: descriptive - sys_user_apply_config_bit31; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d29c0 @ 0xa00d29c0-0xa00d2a28 (26 words), flags -mcpu=v8 -O3 -g.
 * Source form: the bit is a 1-bit bit-field of the settings word.
 */

/* Settings word +0 (docs/RECORDS.md): bit 9 is the one written here. */
struct user_settings_record {
    unsigned int bits_10_31 : 22, bit9 : 1, bits_0_8 : 9;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern void sys_user_apply_config_bit31(void);

#define TOOL_RESULT_DONE             0xe0       /* the command was carried out */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* osd_request_bits: settings changed */

/*
 * Factory tool command 0x22 (TOOL_CMD_SETTINGS_BIT9): set bit 9 of settings word +0 to (request byte 7 != 0).
 * When the bit changed, apply it (sys_user_apply_config_bit31) and set OSD_REQUEST_SETTINGS_CHANGED. The old
 * bit is kept in osd_choice_row for the comparison. The settings are not saved here.
 *
 *   p  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_setting_bit9(unsigned char *p)
{
    osd_choice_row = user_settings.bit9;
    user_settings.bit9 = p[7] != 0;
    if (osd_choice_row != user_settings.bit9) {
        sys_user_apply_config_bit31();
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    }
    return TOOL_RESULT_DONE;
}
