/* ddc_tool_set_contrast  (FUN_a00d1f20)
 *
 * Set the contrast the factory tool sends (at most 100)
 *   p: request
 * Returns: 0xE0
 * Name basis: proven - settings byte +0xA, pq_user_apply_color_gain
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1f20, flags -mcpu=v8 -O3 (no -g: with -g a nop follows the final call).
 * Source form: the settings record is accessed through a pointer local (a direct access lets GCC merge the
 * two stores into one conditional move).
 */

/* The user settings record up to the byte used here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned char pad000[9];
    unsigned char brightness;                   /* +0x09: Brightness */
    unsigned char contrast;                     /* +0x0A: Contrast */
};
extern struct user_settings_record user_settings;
extern void pq_user_apply_color_gain(void);

#define TOOL_RESULT_DONE 0xe0                   /* the command was carried out */
#define PERCENT_MAX      100                    /* brightness and contrast are limited to 100 */

/*
 * Factory tool command 0x0F (TOOL_CMD_CONTRAST): store request byte 7, limited to 100, as the Contrast setting
 * and apply it (pq_user_apply_color_gain). The settings are not saved here.
 *
 *   p  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_contrast(unsigned char *p)
{
    struct user_settings_record *settings = &user_settings;

    if (p[7] > PERCENT_MAX)
        settings->contrast = PERCENT_MAX;
    else
        settings->contrast = p[7];
    pq_user_apply_color_gain();
    return TOOL_RESULT_DONE;
}
