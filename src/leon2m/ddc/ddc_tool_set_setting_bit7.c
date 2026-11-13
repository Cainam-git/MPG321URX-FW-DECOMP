/* ddc_tool_set_setting_bit7  (FUN_a00d2a28)
 *
 * Tool command: write bit 7 of the settings word at +0x1EC and apply it when it changed.
 * Name basis: descriptive - gpio_user_set_port7_bit1; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d2a28 @ 0xa00d2a28-0xa00d2a98 (28 words), flags -mcpu=v8 -O3 -g.
 * Source form: the bit is a 1-bit bit-field of the settings word.
 */

/* The user settings record up to the word at +0x1EC (docs/RECORDS.md): bit 7 is Type C PD Charge. */
struct user_settings_record {
    unsigned char pad000[0x1ec];
    unsigned int bits_8_31 : 24, type_c_pd_charge : 1, bits_0_6 : 7;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern void gpio_user_set_port7_bit1(int);

#define TOOL_RESULT_DONE             0xe0       /* the command was carried out */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* osd_request_bits: settings changed */

/*
 * Factory tool command 0x23 (TOOL_CMD_TYPE_C_PD_CHARGE): set bit 7 of the settings word at +0x1EC (Type C PD
 * Charge) to (request byte 7 != 0). When the bit changed, run gpio_user_set_port7_bit1(0) and set
 * OSD_REQUEST_SETTINGS_CHANGED. The old bit is kept in osd_choice_row for the comparison. The settings are not
 * saved here.
 *
 *   p  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_setting_bit7(unsigned char *p)
{
    osd_choice_row = user_settings.type_c_pd_charge;
    user_settings.type_c_pd_charge = p[7] != 0;
    if (osd_choice_row != user_settings.type_c_pd_charge) {
        gpio_user_set_port7_bit1(0);
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    }
    return TOOL_RESULT_DONE;
}
