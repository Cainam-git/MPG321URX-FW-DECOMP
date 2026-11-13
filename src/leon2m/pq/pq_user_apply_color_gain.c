/* pq_user_apply_color_gain  (FUN_a00d7de0)
 *
 * Apply the colour gain setting, limited to 100.
 * Name basis: derived - settings byte +0x0A mapped through a floating-point scale to pq_api_set_color_gain
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d7de0 @ 0xa00d7de0-0xa00d8034 (149 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - main_port_flag_test() and the mapping apply_contrast() are static helpers (inlined);
 *  - the "v > 70" arm of the mapping comes first;
 *  - the Pro-mode range test is the unsigned-byte expression (pro_mode - 4) <= 2; it stays
 *    because the compiler folds it into a single range test.
 */

#define CONTRAST_KNEE        70     /* below and above this value the mapping has another slope */
#define COLOR_GAIN_MAX       100    /* the setting is limited to 100 */
#define GAMING_FLAG_PRO_MODE 0x800  /* gaming_flags bit 11: Pro (1) / Game (0) */

struct user_settings_record {
    unsigned char pad0[0xa];
    unsigned char contrast;         /* +0xA: the Contrast setting, applied here as the colour gain */
    unsigned char pad0b[0xa8 - 0xb];
    unsigned int gaming_flags;      /* +0xA8 */
    unsigned char padac[0x178 - 0xac];
    unsigned char byte_0x178;       /* +0x178 */
    unsigned char pad179[0x181 - 0x179];
    unsigned char pro_mode;         /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;
extern const unsigned char user_settings_defaults_contrast;
extern void pq_api_enable_color_matrix(int, int);
extern unsigned char sys_api_get_channel_port_flag9(unsigned char ch);
extern unsigned char sys_api_get_channel_port_flag6(unsigned char ch);
extern unsigned char ipc_api_get_status_field(void);
extern void pq_api_set_color_gain(unsigned char);

/* True when the port of channel 0 has flag bit 9 set, or has flag bit 6 set while the mailbox status field
   reads 1..4 (ipc_api_get_status_field gives 4 for a value outside 0..3). */
static int main_port_flag_test(void)
{
    if (sys_api_get_channel_port_flag9(0) == 1)
        return 1;
    if (sys_api_get_channel_port_flag6(0) == 1) {
        switch (ipc_api_get_status_field()) {
        case 1: return 1;
        case 2: return 1;
        case 3: return 1;
        case 4: return 1;
        }
    }
    return 0;
}

/* Map a Contrast value 0..100 to the colour matrix scale (128 = 1.0) and apply it: 0 -> 28, 70 -> 128,
   100 -> 150, two straight lines meeting at 70 (soft-float). */
static void apply_contrast(unsigned char value)
{
    float f;

    if (value > CONTRAST_KNEE)
        f = (value - CONTRAST_KNEE) * 22.0f / 30.0f + 128.0f;
    else
        f = value * 100.0f / 70.0f + 28.0f;
    pq_api_set_color_gain((unsigned char)f);
}

/*
 * Apply the Contrast setting as the colour matrix scale.
 *
 * The Contrast setting byte (+0xA) is limited to 100 and written back, and the colour matrix is switched on for
 * channel 0. When the Pro mode is 4..6 and the Pro flag is set, nothing more is done. Otherwise the ROM default
 * Contrast is applied when main_port_flag_test() is true or byte +0x178 is 1, and the user's Contrast in every
 * other case. The default is applied by placing it in the setting for the call and putting the user's value back
 * afterwards. apply_contrast maps the value and hands it to pq_api_set_color_gain.
 *
 * Callers: App_Initialize, sys_user_factory_reset, sys_end_logo_restore_picture, UserSetProMode,
 * UserSetGameMode, the Contrast menu items, the factory menu, and the DDC/CI and UART commands that set the
 * contrast or the picture settings.
 */
void pq_user_apply_color_gain(void)
{
    unsigned char contrast = user_settings.contrast;

    if (contrast > COLOR_GAIN_MAX)
        contrast = COLOR_GAIN_MAX;
    user_settings.contrast = contrast;
    pq_api_enable_color_matrix(0, 0);
    if (main_port_flag_test()) {
        if ((unsigned char)(user_settings.pro_mode - 4) <= 2 && (user_settings.gaming_flags & GAMING_FLAG_PRO_MODE))
            return;
        contrast = user_settings.contrast;
        user_settings.contrast = user_settings_defaults_contrast;
        apply_contrast(user_settings.contrast);
        user_settings.contrast = contrast;
    } else {
        if ((unsigned char)(user_settings.pro_mode - 4) <= 2 && (user_settings.gaming_flags & GAMING_FLAG_PRO_MODE))
            return;
        if (user_settings.byte_0x178 == 1) {
            contrast = user_settings.contrast;
            user_settings.contrast = user_settings_defaults_contrast;
            apply_contrast(user_settings.contrast);
            user_settings.contrast = contrast;
        } else
            apply_contrast(user_settings.contrast);
    }
}
