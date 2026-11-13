/* UserSetProMode  (FUN_a00db738)
 *
 * Apply the picture mode of the Professional menu.
 * Name basis: proven - prints the mode (original name from the firmware's text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00db738 @ 0xa00db738-0xa00dbcf0 (366 words), flags -mcpu=v8 -O3 -g.
 * The routines input_user_has_rate_mode (input_user_has_rate_mode), pq_user_reset_response_level (pq_user_reset_response_level) and
 * sys_user_apply_auto_level (sys_user_apply_auto_level) are written in this file so that their inlined copies come out as in
 * the firmware; pq_user_reset_response_level is written in the form that its inlined copy needs (the standalone
 * pq_user_reset_response_level is not matched with this source).
 * Source forms: the Image Enhancement nibble of halfword +0x34 is a bit-field (a mask narrows the load to a
 * byte); the limited sharpness is an unsigned short passed as (unsigned char)sharpness * 3; the preset switch
 * lists default first; the mode byte copies are written high byte first; pq_user_reset_response_level tests the
 * 0/1 result of input_user_has_rate_mode as '== 1'.
 */
/* The fields of the user settings record used here (docs/RECORDS.md). The two flag words are bit-fields; the
   record is stored with the most significant bit first. */
struct professional_flags_bits {
    unsigned int auto_level : 1;        /* bit 31: automatic level */
    unsigned int rest : 31;
};
struct gaming_flags_bits {
    unsigned int p0 : 20;
    unsigned int pro_selected : 1;          /* bit 11: Pro (1) / Game (0) mode */
    unsigned int pro_selected_copy_1 : 1;   /* bit 10: kept with mode copy 1 */
    unsigned int pro_selected_copy_2 : 1;   /* bit 9:  kept with mode copy 2 */
    unsigned int pro_selected_copy_3 : 1;   /* bit 8:  kept with mode copy 3 */
    unsigned int p1 : 8;
};
struct user_settings_record {
    unsigned char pad0[0x19];
    unsigned char response_time;        /* +0x19 */
    unsigned char pad1a[0x1f - 0x1a];
    unsigned char pip_pbp_mode;         /* +0x1F: 0 = off */
    unsigned char pad20[0x34 - 0x20];
    struct {
        unsigned short p : 12;
        unsigned short level : 4;       /* bits 0..3: Image Enhancement level */
    } image_enhancement;                /* +0x34 */
    unsigned char pad36[0x49 - 0x36];
    unsigned char sharpness;            /* +0x49 */
    unsigned char optix_scope;          /* +0x4A: Optix Scope switch */
    unsigned char pad4b[0x8f - 0x4b];
    unsigned char byte_0x8f;            /* +0x8F: holds the limited response time while it is switched off */
    unsigned char pad90[0xa8 - 0x90];
    struct gaming_flags_bits gaming_flags;          /* +0xA8 */
    unsigned int settings_page_flags;               /* +0xAC */
    unsigned int blur_free_mode;                    /* +0xB0: blur reduction setting */
    unsigned char padb4[0x11c - 0xb4];
    struct professional_flags_bits professional_flags;  /* +0x11C */
    unsigned char pad120[0x174 - 0x120];
    unsigned int word_0x174;            /* +0x174: bit 15 = AI Vision */
    unsigned char pad178[0x181 - 0x178];
    unsigned char pro_mode;             /* +0x181 */
    unsigned char game_mode;            /* +0x182 */
    unsigned char pro_mode_copy_1;      /* +0x183 */
    unsigned char game_mode_copy_1;     /* +0x184 */
    unsigned char pro_mode_copy_2;      /* +0x185 */
    unsigned char game_mode_copy_2;     /* +0x186 */
    unsigned char pro_mode_copy_3;      /* +0x187 */
    unsigned char game_mode_copy_3;     /* +0x188 */
};

/* Item numbers of sys_user_select_mode_setting: each loads one setting from its per-mode table. */
enum {
    MODE_ITEM_BRIGHTNESS      = 0,      /* +0x09 */
    MODE_ITEM_CONTRAST        = 1,      /* +0x0A */
    MODE_ITEM_RESPONSE_TIME   = 2,      /* +0x19 */
    MODE_ITEM_NIGHT_VISION    = 3,      /* +0x15B */
    MODE_ITEM_BLUR_FREE       = 4,      /* +0xB0 */
    MODE_ITEM_IMAGE_ENHANCE   = 5,      /* +0x34 bits 0..3 */
    MODE_ITEM_SHARPNESS       = 6,      /* +0x49 */
    MODE_ITEM_AUTO_LEVEL      = 7,      /* +0x11C bit 31 */
    MODE_ITEM_LOW_BLUE_LIGHT  = 8       /* +0x11C bit 4 */
};

#define AI_VISION_BIT        0x8000     /* word +0x174 bit 15 */
#define SHARPNESS_MAX        5
#define WINDOW_ITEM_SHARPNESS 0xd       /* pq_api_set_window_item item 13: pq_block_set_sharpness_field */
#define RESPONSE_LEVEL_OFF   5          /* pq_api_set_response_level(5) switches the function off */
#define RESPONSE_TIME_MAX    3
#define AUTO_LEVEL_OFF       0
#define SECOND_TABLE_FLAG    0x80       /* bit 7 of the halfword app_state_record_half_0xa: sys_user_select_mode_setting then
                                           reads the second set of per-mode tables; UserGetCECSourceMode sets and
                                           clears it */
#define MAIN_CHANNEL         0
#define SECOND_CHANNEL       1
extern struct user_settings_record user_settings;
extern unsigned short app_state_record_half_0xa;
extern int dbg_printf(const char *fmt, ...);
extern void sys_user_select_mode_setting(unsigned char);
extern void SetThemeMode(int);
extern void pq_user_apply_gamma(void);
extern void pq_user_apply_color_settings(void);
extern void sys_user_apply_brightness(void);
extern void pq_user_apply_color_gain(void);
extern void sys_user_apply_dimming_mode(void);
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);
extern void ldc_hw_api_set_enable_mode(unsigned char);
extern void sys_api_set_channel_scaling_mode(unsigned char, unsigned char);
extern void pq_api_set_window_item(unsigned char ch, unsigned char item, unsigned char v);
extern void sys_api_set_channel_source_enable(unsigned char, unsigned char);
extern void sys_api_enable_channel_port(int, int);
extern void pq_api_set_auto_level_mode(unsigned char);
extern void pq_api_set_response_level(int);
extern int pq_select_rate_mode();
extern int input_api_get_timing_field();

/* The following routines have their own copies in the firmware; here they are written so that the compiler
   inlines them into the mode routine below. */

/* 1 when blur reduction may run at the main channel's refresh rate (timing field 1, tenths of Hz, passed in Hz
   to pq_select_rate_mode). The two parameters are not used. */
unsigned int input_user_has_rate_mode(unsigned int unused_1, unsigned int unused_2)
{
    unsigned int refresh_rate;

    refresh_rate = input_api_get_timing_field(0, 1);
    return (pq_select_rate_mode((unsigned short)refresh_rate / 10) != 0);
}

/* Not called by this routine. */
static int busy(void)
{
    if (user_settings.blur_free_mode != 0 && input_user_has_rate_mode(0, 1))
        return 1;
    return 0;
}

/* Switch the response level off once, leaving the response time setting as it was (limited to 3). Skipped
   while a blur reduction setting is on and the refresh rate allows blur reduction. */
void pq_user_reset_response_level(void)
{
    unsigned char level = user_settings.response_time;

    if (user_settings.blur_free_mode && input_user_has_rate_mode(0, 1) == 1)
        return;
    if (level > RESPONSE_TIME_MAX)
        level = RESPONSE_TIME_MAX;
    user_settings.byte_0x8f = level;
    if (level != 0)
        user_settings.response_time = 0;
    else
        user_settings.response_time = level;
    pq_api_set_response_level(RESPONSE_LEVEL_OFF);
    user_settings.response_time = user_settings.byte_0x8f;
}

/* Apply the automatic level setting (word +0x11C bit 31); it is forced off while main_port_flagged() would
   return 1. With the setting off, the brightness is applied again. */
void sys_user_apply_auto_level(void)
{
    unsigned char mode = user_settings.professional_flags.auto_level;
    unsigned char setting = mode;

    user_settings.professional_flags.auto_level = setting;
    switch (setting) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    }
    if (sys_api_get_channel_port_flag9(MAIN_CHANNEL) == 1)
        mode = AUTO_LEVEL_OFF;
    else if (sys_api_get_channel_port_flag6(MAIN_CHANNEL) == 1) {
        switch (ipc_api_get_status_field()) {
        case 1: mode = 0; break;
        case 2: mode = 0; break;
        case 3: mode = 0; break;
        case 4: mode = 0; break;
        }
    }
    pq_api_set_auto_level_mode(mode & 3);
    if (!user_settings.professional_flags.auto_level)
        sys_user_apply_brightness();
}

/* 1 when the port of the main channel has flag 9 set, or flag 6 while the mailbox status field reads 1..4
   (4 also stands for an out-of-range field). The same test as in sys_user_apply_dimming_mode. */
static int main_port_flagged(void)
{
    if (sys_api_get_channel_port_flag9(MAIN_CHANNEL) == 1)
        return 1;
    if (sys_api_get_channel_port_flag6(MAIN_CHANNEL) == 1) {
        switch (ipc_api_get_status_field()) {
        case 1: return 1;
        case 2: return 1;
        case 3: return 1;
        case 4: return 1;
        }
    }
    return 0;
}

/*
 * Apply the Professional mode (settings byte +0x181) and every setting that belongs to it.
 *
 * Called when the Pro Mode changes or is applied again: the menu (choices, cancel, change notice), the PC-tool
 * command, DDC/CI requests, APPBeforeDisplay_TriggerBySystem, APPActionDispatcher, the picture settings reset
 * and the factory reset. UserSetGameMode is the same routine for the Game Mode.
 *
 * Phases, in order:
 *   1. Load the settings of the current mode from their per-mode tables (sys_user_select_mode_setting):
 *      brightness, contrast, Night Vision, image enhancement, sharpness, automatic level, Low Blue Light;
 *      response time and blur reduction only with PIP/PBP off.
 *   2. Print the mode and apply its theme preset: Pro modes 1 / 2 / 3 use preset 6 / 7 / 8, the others 1.
 *   3. Apply gamma, colour settings, brightness (only with blur reduction and automatic level both off),
 *      colour gain and dimming mode.
 *   4. The grid block enable (the steps of ldc_user_apply_grid_enable): mode 0 while main_port_flagged(),
 *      1 with AI Vision on, else 0; each followed by the dimming mode again.
 *   5. Scaling mode of channels 0 and 1 from the Image Enhancement level; sharpness limited to 5 and passed
 *      as three times its value.
 *   6. With PIP/PBP off: the response level reset; and when the blur reduction setting differs from its low
 *      byte saved at the start and main_port_flagged() is 0, Optix Scope is switched off if it and blur
 *      reduction are both on, together with channel 1's source and port while PIP/PBP is still off.
 *   7. The automatic level.
 *   8. Keep a copy of the Pro/Game choice (word +0xA8 bit 11) and of both mode bytes in one of three places:
 *      copy 1 while SECOND_TABLE_FLAG is set, copy 3 while main_port_flagged(), else copy 2.
 *      UserGetCECSourceMode reads copies 1 and 2 back.
 */
void UserSetProMode(void)
{
    unsigned char old_blur_free = user_settings.blur_free_mode;
    int preset;
    unsigned short sharpness;

    /* 1. The settings of this mode. */
    sys_user_select_mode_setting(MODE_ITEM_BRIGHTNESS);
    sys_user_select_mode_setting(MODE_ITEM_CONTRAST);
    if (user_settings.pip_pbp_mode == 0) {
        sys_user_select_mode_setting(MODE_ITEM_RESPONSE_TIME);
        sys_user_select_mode_setting(MODE_ITEM_BLUR_FREE);
    }
    sys_user_select_mode_setting(MODE_ITEM_NIGHT_VISION);
    sys_user_select_mode_setting(MODE_ITEM_IMAGE_ENHANCE);
    sys_user_select_mode_setting(MODE_ITEM_SHARPNESS);
    sys_user_select_mode_setting(MODE_ITEM_AUTO_LEVEL);
    sys_user_select_mode_setting(MODE_ITEM_LOW_BLUE_LIGHT);

    /* 2. Theme preset. */
    dbg_printf("\x1b[1;33mUserSetProMode %x\r\n\x1b[m", user_settings.pro_mode);
    switch (user_settings.pro_mode) {
    default: preset = 1; break;
    case 3: preset = 8; break;
    case 2: preset = 7; break;
    case 1: preset = 6; break;
    }
    SetThemeMode(preset);

    /* 3. Picture settings. */
    pq_user_apply_gamma();
    pq_user_apply_color_settings();
    if (user_settings.blur_free_mode == 0 && !user_settings.professional_flags.auto_level)
        sys_user_apply_brightness();
    pq_user_apply_color_gain();
    sys_user_apply_dimming_mode();

    /* 4. Grid block enable. */
    if (main_port_flagged()) {
        ldc_hw_api_set_enable_mode(0);
        sys_user_apply_dimming_mode();
    } else if (user_settings.word_0x174 & AI_VISION_BIT) {
        ldc_hw_api_set_enable_mode(1);
        sys_user_apply_dimming_mode();
    } else {
        ldc_hw_api_set_enable_mode(0);
        sys_user_apply_dimming_mode();
    }

    /* 5. Scaling mode and sharpness. */
    sys_api_set_channel_scaling_mode(MAIN_CHANNEL, user_settings.image_enhancement.level);
    sys_api_set_channel_scaling_mode(SECOND_CHANNEL, user_settings.image_enhancement.level);
    sharpness = user_settings.sharpness;
    if (sharpness > SHARPNESS_MAX)
        sharpness = SHARPNESS_MAX;
    user_settings.sharpness = sharpness;
    pq_api_set_window_item(MAIN_CHANNEL, WINDOW_ITEM_SHARPNESS, (unsigned char)sharpness * 3);

    /* 6. Response level; Optix Scope off when the blur reduction setting changed. */
    if (user_settings.pip_pbp_mode == 0) {
        pq_user_reset_response_level();
        if (old_blur_free != user_settings.blur_free_mode && !main_port_flagged()) {
            if (user_settings.optix_scope != 0 && user_settings.blur_free_mode != 0) {
                user_settings.optix_scope = 0;
                if (user_settings.pip_pbp_mode == 0) {
                    sys_api_set_channel_source_enable(SECOND_CHANNEL, 0);
                    sys_api_enable_channel_port(SECOND_CHANNEL, 0);
                }
            }
        }
    }

    /* 7. */
    sys_user_apply_auto_level();

    /* 8. Keep the choice and both mode bytes. */
    if (app_state_record_half_0xa & SECOND_TABLE_FLAG) {
        user_settings.gaming_flags.pro_selected_copy_1 = user_settings.gaming_flags.pro_selected;
        user_settings.game_mode_copy_1 = user_settings.game_mode;
        user_settings.pro_mode_copy_1 = user_settings.pro_mode;
    } else if (main_port_flagged()) {
        user_settings.gaming_flags.pro_selected_copy_3 = user_settings.gaming_flags.pro_selected;
        user_settings.game_mode_copy_3 = user_settings.game_mode;
        user_settings.pro_mode_copy_3 = user_settings.pro_mode;
    } else {
        user_settings.gaming_flags.pro_selected_copy_2 = user_settings.gaming_flags.pro_selected;
        user_settings.game_mode_copy_2 = user_settings.game_mode;
        user_settings.pro_mode_copy_2 = user_settings.pro_mode;
    }
}
