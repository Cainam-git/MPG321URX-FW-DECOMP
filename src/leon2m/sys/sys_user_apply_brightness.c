/* sys_user_apply_brightness  (FUN_a00d8cd4)
 *
 * Apply the brightness setting for the current mode, picture state and input.
 * Name basis: derived - chooses the value by the picture state and mode, then the luminance mode and the
 *   brightness write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8cd4 @ 0xa00d8cd4-0xa00d8ffc (202 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three helpers below are static copies of the matched routines (the stored knee is the record
 * member brightness_knee, fw 'lduh [%o3 + 0x1da]' at 0xa00d8fa8), inlined; the auto-knee conversion is a static
 * helper with both knee formulas in one if/else and one shared return expression (fw: one scaling tail at
 * 0xa00d8db8 for all three formulas); the rate-limit result is compared '== 1' like the port-flag results; the
 * brightness and the percentage are unsigned short (fw 'mov %l0, %o5' copy of the helper parameter at
 * 0xa00d8d74, one 'and 0xff' per formula tail at 0xa00d8df0).
 */
/* Panel brightness levels run from LEVEL_MIN to LEVEL_MAX; the helpers return a percentage of that range. */
#define LEVEL_MIN    126
#define LEVEL_MAX    0x3ff                  /* 1023 */
#define LEVEL_RANGE  897                    /* LEVEL_MAX - LEVEL_MIN */
#define KNEE_SETTING 70                     /* the brightness setting (0..100) at which the line bends */

#define GAMING_FLAG_PRO_MODE 0x800          /* bit 11 of settings word +0xA8: 1 = Professional modes, 0 = Game modes */
#define PRO_MODE_7           7
#define WORD_0x1D4_BIT6      0x40           /* bit 6 of settings word +0x1D4; its meaning is not shown */

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x09];
    unsigned char brightness;               /* +0x09: Brightness, 0..100 */
    unsigned char pad0a[0xa8 - 0x0a];
    unsigned int gaming_flags;              /* +0xA8: bit 11 = GAMING_FLAG_PRO_MODE */
    unsigned int settings_page_flags;       /* +0xAC: bits 18 and 19 are tested here */
    unsigned int blur_free_mode;            /* +0xB0: the blur reduction mode, 0 = off */
    unsigned char padb4[0x181 - 0xb4];
    unsigned char pro_mode;                 /* +0x181: the Professional mode */
    unsigned char pad182[0x1d4 - 0x182];
    unsigned int word_0x1d4;                /* +0x1D4 */
    unsigned char pad1d8[2];
    unsigned short brightness_knee;         /* +0x1DA: level where the brightness line bends */
};
extern struct user_settings_record user_settings;
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);
extern int pq_select_rate_mode();
extern int input_api_get_timing_field();
extern void oled_set_lum_mode(unsigned char);
extern void panel_api_set_brightness(unsigned char);

/*
 * 1 when pq_select_rate_mode gives a non-zero mode for the refresh rate of channel 0 (timing field 1, tenths of
 * a hertz, passed in whole hertz). Both parameters are unused.
 */
static unsigned int input_user_has_rate_mode(unsigned int unused_1, unsigned int unused_2)
{
    unsigned int refresh_rate;

    refresh_rate = input_api_get_timing_field(0, 1);
    return (pq_select_rate_mode((unsigned short)refresh_rate / 10) != 0);
}

/* Brightness setting 0..100 to a percentage of the level range, the bend at the level stored in the settings. */
static unsigned char panel_user_map_brightness_knee(unsigned char setting)
{
    unsigned short level;

    if (setting > KNEE_SETTING - 1)
        level = (unsigned int)((setting - KNEE_SETTING) * (LEVEL_MAX - user_settings.brightness_knee) + 15) / 30 + user_settings.brightness_knee;
    else
        level = (unsigned int)(setting * (user_settings.brightness_knee - LEVEL_MIN) + 35) / KNEE_SETTING + LEVEL_MIN;
    return (level - LEVEL_MIN) * 100 / LEVEL_RANGE;
}

/* The same with a fixed bend: level 272 in Professional mode 7, level 879 in every other mode. */
static unsigned char panel_user_map_brightness_knee_auto(unsigned char setting)
{
    unsigned short level;

    if ((user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) && user_settings.pro_mode == PRO_MODE_7) {
        if (setting > KNEE_SETTING - 1)
            level = (unsigned int)((setting - KNEE_SETTING) * (LEVEL_MAX - 272) + 15) / 30 + 272;
        else
            level = (unsigned int)(setting * (272 - LEVEL_MIN) + 35) / KNEE_SETTING + LEVEL_MIN;
    } else {
        if (setting > KNEE_SETTING - 1)
            level = (unsigned int)((setting - KNEE_SETTING) * (LEVEL_MAX - 879) + 15) / 30 + 879;
        else
            level = (unsigned int)(setting * (879 - LEVEL_MIN) + 35) / KNEE_SETTING + LEVEL_MIN;
    }
    return (level - LEVEL_MIN) * 100 / LEVEL_RANGE;
}

/*
 * Picture state of channel 0, 0..5. It is 4 when port flag 9 of channel 0 is set. Otherwise, when port flag 6
 * is set, it follows the status field read from the mailbox: 1, 2 and 3 give 1, 2 and 3, 4 gives 5 and
 * everything else gives 0. With neither flag it is 0.
 */
static int sys_user_get_picture_state(void)
{
    int state = 5;

    if (sys_api_get_channel_port_flag9(0) == 1)
        state = 4;
    else if (sys_api_get_channel_port_flag6(0) == 1) {
        switch (ipc_api_get_status_field()) {
        case 1: state = 1; break;
        case 2: state = 2; break;
        case 3: state = 3; break;
        case 4: state = 5; break;
        default: state = 0; break;
        }
    } else
        state = 0;
    return state;
}

/*
 * Apply the Brightness setting: work out the brightness percentage for the panel and set the luminance mode of
 * the OLED controller.
 *
 * The setting (settings byte +9) is first limited to 100 and written back. The percentage sent to
 * panel_api_set_brightness is then, in this order:
 *   - 100 when the picture state is not 0, so the setting has no effect then;
 *   - 100 when a blur reduction mode is on (+0xB0 not 0) and the input is rate-limited (see
 *     input_user_has_rate_mode);
 *   - the setting through the stored knee (+0x1DA) when bit 6 of settings word +0x1D4 is set and the Professional
 *     mode 7 is active (+0xA8 bit 11 set and +0x181 equal to 7);
 *   - otherwise the setting through the fixed knee: level 272 in Professional mode 7, else level 879.
 * The luminance mode is 2 when the picture state is 0. With a non-zero picture state it is 0 when one of bits
 * 18 or 19 of settings word +0xAC is set and 1 when neither is.
 *
 * Callers include the DDC/CI request handler, UserSetGameMode, UserSetProMode, sys_user_factory_reset and
 * sys_user_apply_auto_level.
 */
void sys_user_apply_brightness(void)
{
    unsigned short setting = user_settings.brightness;
    unsigned short percent;

    if (setting > 100)
        setting = 100;
    user_settings.brightness = setting;
    if (sys_user_get_picture_state())
        percent = 100;
    else if (user_settings.blur_free_mode != 0 && input_user_has_rate_mode(0, 1) == 1)
        percent = 100;
    else if ((user_settings.word_0x1d4 & WORD_0x1D4_BIT6) && (user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) && user_settings.pro_mode == PRO_MODE_7)
        percent = panel_user_map_brightness_knee(setting);
    else
        percent = panel_user_map_brightness_knee_auto(setting);
    if (sys_user_get_picture_state()) {
        if (user_settings.settings_page_flags & 0xc0000)
            oled_set_lum_mode(0);
        else
            oled_set_lum_mode(1);
    } else
        oled_set_lum_mode(2);
    panel_api_set_brightness(percent);
}
