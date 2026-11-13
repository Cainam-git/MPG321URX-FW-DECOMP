/* ddc_tool_set_brightness  (FUN_a00d1ed8)
 *
 * Set the brightness the factory tool sends (at most 100)
 *   p: request
 * Returns: 0xE0
 * Name basis: proven - settings byte +0x9, sys_user_apply_brightness
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1ed8, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is accessed through a pointer local (a direct access lets GCC merge the
 * two stores into one conditional move).
 */

/* The user settings record up to the two bytes used here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned char pad000[9];
    unsigned char brightness;                   /* +0x09: Brightness */
    unsigned char contrast;                     /* +0x0A: Contrast */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void sys_user_apply_brightness(void);

#define TOOL_RESULT_DONE     0xe0               /* the command was carried out */
#define PERCENT_MAX          100                /* brightness and contrast are limited to 100 */
#define OSD_REQUEST_EVENT_83 0x04               /* osd_request_bits: event 0x83 */

/*
 * Factory tool command 0x0E (TOOL_CMD_BRIGHTNESS): store request byte 7, limited to 100, as the Brightness
 * setting, apply it (sys_user_apply_brightness) and set the OSD request bit OSD_REQUEST_EVENT_83. The settings
 * are not saved here.
 *
 *   p  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_brightness(unsigned char *p)
{
    struct user_settings_record *settings = &user_settings;

    if (p[7] > PERCENT_MAX)
        settings->brightness = PERCENT_MAX;
    else
        settings->brightness = p[7];
    sys_user_apply_brightness();
    osd_request_bits |= OSD_REQUEST_EVENT_83;
    return TOOL_RESULT_DONE;
}
