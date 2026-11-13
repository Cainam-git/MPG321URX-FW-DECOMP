/* pq_user_apply_color_settings  (FUN_a00d9764)
 *
 * Limit and apply the colour temperature and the three custom colour values.
 * Name basis: derived - settings bytes +0x11..+0x14; picture mode code chosen by +0x11
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d9764 @ 0xa00d9764-0xa00d9978 (133 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - choice is an unsigned short and the switch takes its low byte; choices 1, 8 and 10..14 use the
 *    default arm;
 *  - the Pro-mode 4..6 test is written as nested ifs (an && chain folds into a range test);
 *  - main_port_flag_test() is a static helper with one return per case (inlined).
 */

#define COLOR_TEMPERATURE_MAX 14       /* the Color Temperature choice is limited to 14 */
#define COLOR_GAIN_MAX        100      /* each custom colour value is limited to 100 */

#define RGB_RED   0                    /* channel argument of pq_api_set_rgb_gain */
#define RGB_GREEN 1
#define RGB_BLUE  2

#define GAMING_FLAG_PRO_MODE 0x800     /* gaming_flags bit 11: Pro (1) / Game (0) */
#define PICTURE_MODE_MASK    0x1f      /* the picture mode code is its low 5 bits */

/* Picture mode codes: the four Color Temperature presets. */
#define PICTURE_MODE_WARM    1
#define PICTURE_MODE_NORMAL  4
#define PICTURE_MODE_COOL    7
#define PICTURE_MODE_CUSTOM  0x17

struct user_settings_record {
    unsigned char pad0[0x11];
    unsigned char color_temperature;    /* +0x11: the Color Temperature choice */
    unsigned char red_gain;             /* +0x12: the custom red gain */
    unsigned char green_gain;           /* +0x13: the custom green gain */
    unsigned char blue_gain;            /* +0x14: the custom blue gain */
    unsigned char pad15[0xa8 - 0x15];
    unsigned int gaming_flags;          /* +0xA8 */
    unsigned char padac[0x181 - 0xac];
    unsigned char pro_mode;             /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);
extern void pq_api_enable_color_matrix(int, int);
extern void pq_api_set_rgb_gain(int, unsigned char);
extern void pq_api_set_picture_mode(unsigned char);
extern void pq_user_apply_color_temperature(void);

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

/* Limit the custom blue value to 100, apply it, and re-apply the colour temperature. */
void pq_user_set_custom_blue(void)
{
    struct user_settings_record *p = &user_settings;
    unsigned short value = p->blue_gain;

    if (value > COLOR_GAIN_MAX)
        value = COLOR_GAIN_MAX;
    p->blue_gain = value;
    pq_api_set_rgb_gain(RGB_BLUE, value);
    pq_user_apply_color_temperature();
}

/*
 * Limit and apply the colour temperature and the three custom colour values.
 *
 * The Color Temperature choice (settings byte +0x11) is limited to 14 and stored back, and the
 * colour matrix is switched on for channel 0 (pq_api_enable_color_matrix(0, 0)). When
 * main_port_flag_test() is true the red, green and blue gains are all set to 100 and the stored
 * values are left alone; otherwise each of the three custom values +0x12..+0x14 is limited to
 * 100, stored back and applied to its channel (pq_user_set_custom_blue does the blue, and also
 * applies the colour temperature once already).
 *
 * The choice then selects the picture mode code handed to pq_api_set_picture_mode: Cool 0 ->
 * PICTURE_MODE_COOL, Warm 2 -> PICTURE_MODE_WARM, Customization 3 -> PICTURE_MODE_CUSTOM,
 * 4 -> 0x18, 5 -> 5, 6 -> 6, 7 -> 8, 9 -> 0x0F; Normal 1, 8 and 10..14 -> PICTURE_MODE_NORMAL.
 * When the choice is Normal (1), the Pro mode is 4, 5 or 6 and the Pro flag is set, the code is
 * 0x0F, 0x10 or 0x11 instead. Finally the colour temperature is applied.
 *
 * Callers: App_Initialize, sys_user_factory_reset, UserSetProMode, UserSetGameMode, the colour
 * temperature and low blue light menu items, the factory menu, and the DDC/CI and UART commands
 * that set colour values.
 */
void pq_user_apply_color_settings(void)
{
    unsigned short choice = user_settings.color_temperature;
    unsigned char mode_code;

    if (choice > COLOR_TEMPERATURE_MAX)
        choice = COLOR_TEMPERATURE_MAX;
    user_settings.color_temperature = choice;
    pq_api_enable_color_matrix(0, 0);
    if (main_port_flag_test()) {
        pq_api_set_rgb_gain(RGB_RED, COLOR_GAIN_MAX);
        pq_api_set_rgb_gain(RGB_GREEN, COLOR_GAIN_MAX);
        pq_api_set_rgb_gain(RGB_BLUE, COLOR_GAIN_MAX);
    } else {
        struct user_settings_record *p = &user_settings;
        unsigned short value;

        value = p->red_gain;
        if (value > COLOR_GAIN_MAX)
            value = COLOR_GAIN_MAX;
        p->red_gain = value;
        pq_api_set_rgb_gain(RGB_RED, value);
        value = p->green_gain;
        if (value > COLOR_GAIN_MAX)
            value = COLOR_GAIN_MAX;
        p->green_gain = value;
        pq_api_set_rgb_gain(RGB_GREEN, value);
        pq_user_set_custom_blue();
    }
    switch ((unsigned char)choice) {
    case 0: mode_code = PICTURE_MODE_COOL; break;
    case 2: mode_code = PICTURE_MODE_WARM; break;
    case 3: mode_code = PICTURE_MODE_CUSTOM; break;
    case 4: mode_code = 0x18; break;
    case 5: mode_code = 5; break;
    case 6: mode_code = 6; break;
    case 7: mode_code = 8; break;
    case 9: mode_code = 0xf; break;
    default: mode_code = PICTURE_MODE_NORMAL; break;
    }
    if (user_settings.color_temperature == 1) {
        /* In Normal, Pro modes 4..6 give dedicated picture mode codes. */
        unsigned char pro_mode = user_settings.pro_mode;
        if (pro_mode > 3)
            if (pro_mode <= 6)
                if (user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) {
                    if (pro_mode == 4)
                        mode_code = 0xf;
                    else if (pro_mode == 5)
                        mode_code = 0x10;
                    else if (pro_mode == 6)
                        mode_code = 0x11;
                }
    }
    pq_api_set_picture_mode(mode_code & PICTURE_MODE_MASK);
    pq_user_apply_color_temperature();
}
