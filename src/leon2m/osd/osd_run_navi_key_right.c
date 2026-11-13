/* osd_run_navi_key_right  (FUN_a00a0508)
 *
 * Open the quick menu set for the Navi Key right direction (menu closed)
 * Note: Function = settings byte +0x18D (1..11 -> quick menu states 0xFA..0x104); in factory mode it selects
 *   an input.
 * Name basis: derived - handler table 0xA802422C: right on states 0 (menu closed) and 0x106; Navi Key Right
 *   item, texts 0x1935BC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a0508 @ 0xa00a0508-0xa00a0780 (158 words), flags -mcpu=v8 -O3 -g.
 * One of four twins (osd_run_navi_key_right / _left / _down / _up: navi_key_function[3 / 2 / 1 / 0],
 * input_api_menu_index_to_source_id(0 / 2 / 3 / 1), osd_draw_navi_quick_menu(3 / 2 / 1 / 0)). No parameters (the
 * firmware never reads %i0 / %i1).
 * Source forms the exact build depends on:
 *  - bit 15 of the sleep word written '(short)(x & 0x8000)' (firmware: sethi 0xffff8000; and; sll 16; cmp);
 *  - the pointer settings = &user_settings taken right before the first NAVI_FUNCTION_PIP_PBP test and used for
 *    the rest (the firmware keeps one base register from there);
 *  - input_user_has_rate_mode declared without arguments;
 *  - bit 31 of word +0x1F4 as a 1-bit bit-field, and the PIP/PBP tests written 'if (function == PIP_PBP) { if
 *    (sys_user_get_picture_state() != 0) return; }' then 'if (function == PIP_PBP && bit31) return;' then the
 *    Night Vision test (firmware 0xa00a0694: ld; cmp; bl ret; b to the Optix Scope test).
 */

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char p000[0x1e];
    unsigned char input_source;                 /* +0x1E: the selected Input Source */
    unsigned char p01f[0xb0 - 0x1f];
    unsigned int blur_free_mode;                /* +0xB0 */
    unsigned char p0b4[0x11c - 0xb4];
    int professional_flags;                     /* +0x11C: bit 31 = auto_level (automatic level) */
    unsigned char p120[0x174 - 0x120];
    unsigned int word_0x174;                    /* +0x174 */
    unsigned char p178[0x18a - 0x178];
    unsigned char navi_key_function[4];         /* +0x18A..+0x18D: Navi Key up, down, left, right (NAVI_FUNCTION_*) */
    unsigned char p18e[0x1a9 - 0x18e];
    unsigned char byte_0x1a9;                   /* +0x1A9: 1 = ask with the change notice */
    unsigned char byte_0x1aa;                   /* +0x1AA: the button highlighted in the change notice */
    unsigned char p1ab[0x1d4 - 0x1ab];
    unsigned int word_0x1d4;                    /* +0x1D4: byte +0x1D5 burn_in_flag, byte +0x1D6 factory status 2 */
    unsigned char p1d8[0x1f4 - 0x1d8];
    union {
        struct { unsigned short half_0x1f4, factory_marker; } halves;    /* +0x1F6: FACTORY_MODE_MARKER */
        struct { unsigned int bit31 : 1, rest : 31; } bits;
    } word_0x1f4;
};

/* The fields of the application state record used here. */
struct app_state_record {
    unsigned short flags_0x0;                   /* +0x00: APP_STATE_FLAG0_BIT10 */
    unsigned short half_0x2;
    unsigned short sleep_word;                  /* +0x04: SLEEP_WORD_* */
    unsigned char p6[4];
    unsigned char notice_origin;                /* +0x0A: NOTICE_FROM_* */
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern unsigned short osd_message_ticks;
extern unsigned char input_api_menu_index_to_source_id(unsigned char v);
extern void sys_user_reset_display_path(void);
extern void input_rearm_port_event(int, int);
extern unsigned int sys_get_channel_state(unsigned int);
extern unsigned int input_user_has_rate_mode(void);
extern int sys_user_get_picture_state(void);
extern void osd_draw_navi_quick_menu(int);
extern void osd_show_menu_layer(void);
extern void osd_hide_menu(void);
extern void osd_show_change_notice(void);
extern unsigned short timer_get_ticks16(void);

/* Navi key directions: index of navi_key_function and argument of osd_draw_navi_quick_menu. */
#define NAVI_KEY_UP     0
#define NAVI_KEY_DOWN   1
#define NAVI_KEY_LEFT   2
#define NAVI_KEY_RIGHT  3

/* Navi Key functions (the menu's Navi Key choices); function + MENU_STATE_NAVI_BASE = its quick menu state. */
enum {
    NAVI_FUNCTION_OFF          = 0,
    NAVI_FUNCTION_BRIGHTNESS   = 1,
    NAVI_FUNCTION_GAME_MODE    = 2,
    NAVI_FUNCTION_PIP_PBP      = 6,
    NAVI_FUNCTION_NIGHT_VISION = 9,
    NAVI_FUNCTION_OPTIX_SCOPE  = 10
};
#define MENU_STATE_NAVI_BASE    0xf9    /* quick menu states 0xFA..0x104 for functions 1..11 */
#define MENU_STATE_CLOSED       0
#define MENU_STATE_CHANGE_NOTICE 0x116  /* the mode change notice */

#define FACTORY_MODE_MARKER     0x55aa  /* user settings +0x1F6 while factory mode is on */
#define FACTORY_BYTES_MASK      0xffff00        /* bytes +0x1D5 and +0x1D6 of word_0x1d4 */
#define FACTORY_BYTES_SELECT    0x5500  /* burn-in off and factory status 2 = 0x55 */

#define APP_STATE_FLAG0_BIT10   0x400   /* app_state_record halfword +0, bit 10 */
#define SLEEP_WORD_BIT15        0x8000  /* when set, closing the menu re-arms the port events */
#define SLEEP_WORD_BIT10        0x400   /* set together with that re-arm */
#define NOTICE_FROM_NAVI_KEY    5       /* a Navi key whose function is Game Mode */
#define NOTICE_BUTTON_NO        0       /* byte_0x1aa: No highlighted */
#define ASK_WITH_NOTICE         1       /* byte_0x1a9 */
#define ALL_PORTS               4       /* input_rearm_port_event: every port */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* osd_request_bits bit 1 */
#define MODE_WAITMODECHANGE     12      /* raw channel state (sys_get_channel_state) */
#define WORD_0X174_BIT15        0x8000

#define THIS_KEY                NAVI_KEY_RIGHT
#define FACTORY_SOURCE          0       /* source given to input_api_menu_index_to_source_id in factory mode */

/*
 * Handler of the right key while the menu is closed (menu states 0 and 0x106 of osd_menu_key_table): open the
 * quick menu of the function set for the Navi Key right direction.
 *
 * Phases, in order:
 *   1. Factory mode (marker set) with burn-in off and factory status 2 = 0x55: the key selects input source 0
 *      instead, restarts the display path and marks the settings changed. With the marker set but those two
 *      bytes different, the key goes on to phase 3.
 *   2. Otherwise: nothing while bit 10 of app_state_record halfword 0 is set. When the function is Game Mode and
 *      the change notice is asked for, the menu closes and the change notice opens (No highlighted).
 *   3. Checks: the main channel must be in raw state MODE_WAITMODECHANGE and a function must be set. Brightness
 *      is refused while auto_level is set, while a blur reduction mode is set and input_user_has_rate_mode
 *      returns 1 (pq_select_rate_mode gives a mode other than 0 for the main channel's refresh rate), or while sys_user_get_picture_state is not 0; PIP/PBP, Night Vision and Optix Scope are
 *      refused while that state is not 0; PIP/PBP also while bit 31 of settings word +0x1F4 is set, Night Vision
 *      while bit 15 of settings word +0x174 is set.
 *   4. Draw the function's quick menu, set its menu state and switch the menu layer on.
 */
void osd_run_navi_key_right(void)
{
    struct user_settings_record *settings;

    /* 1. Factory mode: the key picks an input source. */
    if (user_settings.word_0x1f4.halves.factory_marker == FACTORY_MODE_MARKER) {
        if ((user_settings.word_0x1d4 & FACTORY_BYTES_MASK) == FACTORY_BYTES_SELECT) {
            user_settings.input_source = input_api_menu_index_to_source_id(FACTORY_SOURCE);
            sys_user_reset_display_path();
            input_rearm_port_event(ALL_PORTS, 0);
            osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
            return;
        }
    } else {
        /* 2. Not in factory mode. */
        if (app_state_record.flags_0x0 & APP_STATE_FLAG0_BIT10)
            return;
        if (user_settings.byte_0x1a9 == ASK_WITH_NOTICE && user_settings.navi_key_function[THIS_KEY] == NAVI_FUNCTION_GAME_MODE) {
            /* Game Mode with the notice: ask first. */
            app_state_record.notice_origin = NOTICE_FROM_NAVI_KEY;
            /* The steps of osd_close_menu. */
            if ((short)(app_state_record.sleep_word & SLEEP_WORD_BIT15)) {
                app_state_record.sleep_word |= SLEEP_WORD_BIT10;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
            osd_show_change_notice();
            osd_menu_state = MENU_STATE_CHANGE_NOTICE;
            osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
            user_settings.byte_0x1aa = NOTICE_BUTTON_NO;
            osd_message_ticks = timer_get_ticks16();
            return;
        }
    }

    /* 3. Checks. */
    if ((sys_get_channel_state(0) & 0xff) != MODE_WAITMODECHANGE)
        return;
    if (user_settings.navi_key_function[THIS_KEY] == NAVI_FUNCTION_OFF)
        return;
    if (user_settings.navi_key_function[THIS_KEY] == NAVI_FUNCTION_BRIGHTNESS) {
        if (user_settings.professional_flags < 0)
            return;
        if (user_settings.blur_free_mode != 0 && (unsigned char)input_user_has_rate_mode() == 1)
            return;
        if (sys_user_get_picture_state() != 0)
            return;
    }
    settings = &user_settings;
    if (settings->navi_key_function[THIS_KEY] == NAVI_FUNCTION_PIP_PBP) {
        if (sys_user_get_picture_state() != 0)
            return;
    }
    if (settings->navi_key_function[THIS_KEY] == NAVI_FUNCTION_PIP_PBP && settings->word_0x1f4.bits.bit31)
        return;
    if (settings->navi_key_function[THIS_KEY] == NAVI_FUNCTION_NIGHT_VISION) {
        if (sys_user_get_picture_state() != 0)
            return;
        if (settings->word_0x174 & WORD_0X174_BIT15)
            return;
    }
    if (settings->navi_key_function[THIS_KEY] == NAVI_FUNCTION_OPTIX_SCOPE) {
        if (sys_user_get_picture_state() != 0)
            return;
    }

    /* 4. Open the quick menu. */
    osd_draw_navi_quick_menu(THIS_KEY);
    osd_menu_state = settings->navi_key_function[THIS_KEY] + MENU_STATE_NAVI_BASE;
    osd_show_menu_layer();
}
