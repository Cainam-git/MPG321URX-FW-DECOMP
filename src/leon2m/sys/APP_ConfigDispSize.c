/* APP_ConfigDispSize  (FUN_a00d6054)
 *
 * Compute the display window of a channel for the current mode, aspect and layout.
 * Name basis: proven - prints 'APP_ConfigDispSize_%d_bg : %d %d %d %d' (original name)
 *
 * Matching notes
 * --------------
 * leon2m unit: sys_user_map_setting_to_float @ 0xa00d3d30 + FUN_a00d6054 @ 0xa00d6054 APP_ConfigDispSize, one source file.
 * Flags -mcpu=v8 -O3 -g. sys_user_map_setting_to_float (own source in src/leon2m/sys/sys_user_map_setting_to_float.c) is the function compiled before
 * FUN_a00d6054 in the same unit; it is repeated here because its float constants come first in the unit's constant
 * pool. The block copy of the screen_size_ratios table is a gcc 'memcpy' libcall (fw memcpy = memcpy).
 * APP_ConfigDispSize uses the jump tables at 0xa00d3a64, 0xa00d3a78 and 0xa00d3a98.
 * Source form:
 *   - The ratio tables are locals of the small inline helpers, so every lookup builds them again (the firmware
 *     does this); window_ratios is written as unsigned short [3][3].
 *   - The result goes through 'struct disp_win *window' (eight named halfwords), written in field order.
 *   - base_window_size, channel 1: modes 5 and 6 share one case body; mode 7 has its own copy of the same body.
 *   - The channel 2 corner switch reads the 4-bit field pip_location.f.second_location (promoted to int: fw
 *     a00d7158 signed 'ble').
 *   - pip_size2_lines() calls input_api_get_timing_field(1, 4) and returns 0x21c; the call's result is not used,
 *     as in the firmware.
 *   - Screen Size 4 / 8: the 'does not fit' arm writes the full-panel values itself; 5 and 6 jump to 'full'.
 *   - base_window_position, channel 1, location Customize works through 'struct user_settings_record
 *     *settings = &user_settings' (fw keeps the address in %l2, a00d7088).
 *   - Custom PIP size: 'width = size * 15; height = size * 8 + 0x137; width = (width + 0x228) & ~1;'.
 *   - window_width_mode reads the input size through get_input_size() without using it (the firmware makes those
 *     calls).
 */
extern unsigned char user_settings_contrast;

/*
 * Copy of sys_user_map_setting_to_float (see the matching notes): the contrast setting mapped onto two straight
 * lines that meet at 70.
 */
unsigned char sys_user_map_setting_to_float(void)
{
    unsigned char contrast = user_settings_contrast;
    float value;
    if (contrast > 70)
        value = (float)(contrast - 70) * 22.0f / 30.0f + 128.0f;
    else
        value = (float)(int)contrast * 100.0f / 70.0f + 28.0f;
    return value;
}

/* One row of a ratio table: horizontal and vertical ratio (10000 = 1.0) and flags. */
struct window_ratio { unsigned short h_ratio, v_ratio, flags; };

/* Columns of a window_ratios row (the same three values as struct window_ratio). */
#define RATIO_H     0
#define RATIO_V     1
#define RATIO_FLAGS 2

/*
 * The fields of the user settings record used here (docs/RECORDS.md). The record is stored with the most
 * significant bit first, so the first bit-field of a word is its bit 31.
 */
struct user_settings_record {
    unsigned int word_0x0;              /* +0x000: bit 5 = SETTINGS_VIDEO_WALL */
    unsigned char pad004[0x1b];
    unsigned char pip_pbp_mode;         /* +0x01F: PIP/PBP mode (PIP_PBP_*) */
    unsigned char pad020[0xf];
    unsigned char pbp_layout;           /* +0x02F: the PBP layout (PBP_LAYOUT_*) */
    union {
        unsigned int word;
        struct {
            unsigned int byte_0x30 : 8;         /* bits 24..31 */
            unsigned int pip_size : 8;          /* bits 16..23 (byte +0x31): size and window_ratios row of
                                                   channel 1 in modes PIP and 4 */
            unsigned int ratio_row : 4;         /* bits 12..15: window_ratios row of channel 0 (modes 2, 5, 6,
                                                   7) and of channel 1 (modes 2 and 3) */
            unsigned int second_pip_size : 4;   /* bits 8..11: size and window_ratios row of channel 2 in mode 4 */
            unsigned int location : 4;          /* bits 4..7: the PIP location (PIP_LOCATION_*) */
            unsigned int second_location : 4;   /* bits 0..3: the corner of channel 2 in mode 4 */
        } f;
    } pip_location;                     /* +0x030 */
    /* +0x034: bits 28..31 / 24..27 / 20..23 = window_ratios rows of channels 1 / 2 / 3 in the PBP-type modes;
       bits 16..19 are the Image Enhancement level. */
    unsigned int image_enhancement;
    unsigned char pad038[2];
    unsigned char byte_0x3a;            /* +0x03A: added to the shown width with SETTINGS_VIDEO_WALL */
    unsigned char byte_0x3b;            /* +0x03B: offset_x = (3 - value) * 8 with SETTINGS_VIDEO_WALL */
    unsigned char byte_0x3c;            /* +0x03C: added to the shown height with SETTINGS_VIDEO_WALL */
    unsigned char byte_0x3d;            /* +0x03D: offset_y = 3 - value with SETTINGS_VIDEO_WALL */
    unsigned char pad03e[0xd];
    unsigned char scope_size;           /* +0x04B: the Optix Scope size */
    unsigned char pad04c[8];
    unsigned short pip_custom_x;        /* +0x054: channel 1 position for location Customize */
    unsigned short pip_custom_y;        /* +0x056 */
    unsigned char pad058[0x14c];
    unsigned char screen_size;          /* +0x1A4: Screen Size (SCREEN_SIZE_*) */
    unsigned char pad1a5[0x4b];
    unsigned short pbp_channel0_width;  /* +0x1F0: width of channel 0 with PBP_LAYOUT_CUSTOM */
};

extern struct user_settings_record user_settings;
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a013c910");   /* gcc's block-copy libcalls go to the firmware memcpy memcpy (asm-label declaration, no code) */
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern unsigned short panel_api_get_active_size(unsigned char);
extern int dbg_printf(const char *fmt, ...);
extern int input_check_ch1_size_order();

#define SETTINGS_VIDEO_WALL 0x20        /* word +0 bit 5; pq_update_input_window crops the input by the video-wall
                                           tile when it is set */

/* PIP/PBP mode (settings +0x1F). The menu list is 'OFF', 'PIP', 'PBP'; the other values are named by number. */
#define PIP_PBP_OFF     0
#define PIP_PBP_PIP     1
#define PIP_PBP_PBP     2
#define PIP_PBP_MODE_4  4               /* channels 1 and 2 as two windows of a PIP size */
#define PIP_PBP_MODE_5  5
#define PIP_PBP_MODE_6  6
#define PIP_PBP_MODE_7  7               /* four quarter windows */

/* PBP layout (settings +0x2F); the PBP mode list is 'Mode 1', 'Mode 2', 'Customize'. */
#define PBP_LAYOUT_0       0
#define PBP_LAYOUT_1       1
#define PBP_LAYOUT_CUSTOM  2            /* split at pbp_channel0_width */

/* PIP location (settings word +0x30 bits 4..7), in the order of the menu list 'Left Top', 'Right Top',
   'Left Bottom', 'Right Bottom', 'Customize'. The corner of channel 2 in mode 4 (bits 0..3) uses 0..3 the same way. */
#define PIP_LOCATION_LEFT_TOP      0
#define PIP_LOCATION_RIGHT_TOP     1
#define PIP_LOCATION_LEFT_BOTTOM   2
#define PIP_LOCATION_RIGHT_BOTTOM  3
#define PIP_LOCATION_CUSTOMIZE     4

/* Fixed PIP window sizes for size values 0, 1 and 2; larger values give a computed size. */
#define PIP_SIZE0_WIDTH  0x6c0          /* 1728 */
#define PIP_SIZE0_LINES  0x3cc          /* 972 */
#define PIP_SIZE1_WIDTH  0x540          /* 1344 */
#define PIP_SIZE1_LINES  0x2f4          /* 756 */
#define PIP_SIZE2_WIDTH  0x3c0          /* 960; the lines come from pip_size2_lines() */

/* Screen Size (settings +0x1A4), by what this routine does with the value. The menu list is 'Auto', '4:3',
   '16:9', '16:10', '1:1' and the menu stores the position of the chosen entry (osd_accept_screen_size). */
#define SCREEN_SIZE_INPUT_ASPECT  0     /* full height, width from the input's aspect */
#define SCREEN_SIZE_4_3           1     /* full height, width = height * 4 / 3 */
#define SCREEN_SIZE_1_1           4     /* the input's own size, centred, when it fits */
#define SCREEN_SIZE_2992X1680     5     /* a fixed 2992 x 1680 window, centred, when the input fits */
#define SCREEN_SIZE_3296X1852     6     /* a fixed 3296 x 1852 window, centred, when the input fits */
#define SCREEN_SIZE_1_1_B         8     /* the same as 4 */
#define SCREEN_SIZE_4_3_B         9     /* the same as 1 */

/* Height and width modes, from the flags of a ratio row (height: bits 3..4, width: bits 1..2). */
#define HEIGHT_FROM_INPUT         1     /* input lines * v_ratio */
#define HEIGHT_KEEP_INPUT_ASPECT  2     /* base width * input lines / input width, at most the base height */
                                        /* any other value: base height * v_ratio */
#define WIDTH_FIT                 1     /* base width, or the input's aspect at the shown height */
#define WIDTH_FROM_HEIGHT         2     /* shown height * h_ratio */
                                        /* any other value: base width * h_ratio */

#define RATIO_ONE        10000          /* 1.0 in the ratio tables */
#define RATIO_ROUND      5000           /* half of RATIO_ONE, added before the division */
#define RATIO_4_3        13333          /* 4 / 3 */

#define STATE_CODE_MODESEARCH 5         /* sys_api_get_channel_state_code of channel state MODE_MODESEARCH; codes
                                           above it are MODE_CAPTURE and later */
#define PANEL_SIZE_WIDTH 0              /* panel_api_get_active_size arguments */
#define PANEL_SIZE_LINES 1
#define TIMING_WIDTH     7              /* input_api_get_timing_field fields */
#define TIMING_HEIGHT    8

/*
 * The two ratio tables. screen_size_ratios is indexed by the Screen Size value (only 6 rows: values 6 and up
 * read past it); window_ratios is indexed by the row fields of the settings (only 3 rows).
 */
#define WINDOW_RATIO_TABLES \
    struct window_ratio screen_size_ratios[6] = { {10000, 10000, 0}, {10000, 10000, 3}, {13333, 10000, 5}, \
                        {13333, 10000, 5}, {10000, 10000, 11}, {7500, 7500, 17} }; \
    unsigned short window_ratios[3][3] = { {10000, 10000, 0x11}, {7500, 7500, 0x11}, {5000, 5000, 0x11} }

/* Height mode of the channel's window: bit 3 of the row flags (bits 3..4 in the PBP cases that test it). */
static __inline__ unsigned char window_height_mode(unsigned char channel)
{
    WINDOW_RATIO_TABLES;
    unsigned char mode = user_settings.pip_pbp_mode;
    unsigned char height_mode = 1;

    if (mode != PIP_PBP_OFF) {
        switch (channel) {
        case 0:
            if (user_settings.pip_pbp_mode == PIP_PBP_PBP || user_settings.pip_pbp_mode == PIP_PBP_MODE_5 || user_settings.pip_pbp_mode == PIP_PBP_MODE_6 || user_settings.pip_pbp_mode == PIP_PBP_MODE_7) {
                if (user_settings.pip_pbp_mode == PIP_PBP_PBP)
                    height_mode = (window_ratios[(user_settings.pip_location.word >> 12) & 0xf][RATIO_FLAGS] >> 3) & 3;
                else
                    height_mode = (window_ratios[(user_settings.pip_location.word >> 12) & 0xf][RATIO_FLAGS] >> 3) & 1;
            } else
                height_mode = (screen_size_ratios[user_settings.screen_size].flags >> 3) & 1;
            break;
        case 1:
            if (mode == PIP_PBP_PIP || mode == PIP_PBP_MODE_4)
                height_mode = (window_ratios[(user_settings.pip_location.word >> 16) & 0xff][RATIO_FLAGS] >> 3) & 1;
            else if (mode == PIP_PBP_PBP && ((unsigned char)(user_settings.pbp_layout - 1) <= 1 ||
                                (user_settings.pbp_layout == PBP_LAYOUT_0 && !(unsigned char)input_check_ch1_size_order())))
                height_mode = (window_ratios[(user_settings.pip_location.word >> 12) & 0xf][RATIO_FLAGS] >> 3) & 3;
            else
                height_mode = (window_ratios[(user_settings.pip_location.word >> 12) & 0xf][RATIO_FLAGS] >> 3) & 1;
            break;
        case 2:
            if (mode == PIP_PBP_MODE_4)
                height_mode = (window_ratios[(user_settings.pip_location.word >> 8) & 0xf][RATIO_FLAGS] >> 3) & 1;
            else
                height_mode = (window_ratios[(user_settings.image_enhancement >> 24) & 0xf][RATIO_FLAGS] >> 3) & 1;
            break;
        case 3:
            height_mode = (window_ratios[(user_settings.image_enhancement >> 20) & 0xf][RATIO_FLAGS] >> 3) & 1;
            break;
        }
    } else if (channel == 0)
        height_mode = (screen_size_ratios[user_settings.screen_size].flags >> 3) & 1;
    return height_mode & 3;
}


/* Input size of the channel: the measured size once the channel is past MODE_MODESEARCH, else the panel size. */
static __inline__ void get_input_size(unsigned char channel, unsigned short *width, unsigned short *height)
{
    if (sys_api_get_channel_state_code(channel) > STATE_CODE_MODESEARCH) {
        *width = input_api_get_timing_field(channel, TIMING_WIDTH);
        *height = input_api_get_timing_field(channel, TIMING_HEIGHT);
    } else {
        *width = panel_api_get_active_size(PANEL_SIZE_WIDTH);
        *height = panel_api_get_active_size(PANEL_SIZE_LINES);
    }
}

/* Width mode of the channel's window: bits 1..2 of the row flags. */
static __inline__ unsigned char window_width_mode(unsigned char channel)
{
    WINDOW_RATIO_TABLES;
    unsigned short input_width, input_height;
    unsigned char mode;
    unsigned char width_mode = 0;

    get_input_size(channel, &input_width, &input_height);
    mode = user_settings.pip_pbp_mode;
    if (mode != PIP_PBP_OFF) {
        switch (channel) {
        case 0:
            if (user_settings.pip_pbp_mode == PIP_PBP_PBP || user_settings.pip_pbp_mode == PIP_PBP_MODE_5 || user_settings.pip_pbp_mode == PIP_PBP_MODE_6 || user_settings.pip_pbp_mode == PIP_PBP_MODE_7)
                width_mode = 1;
            else
                width_mode = (screen_size_ratios[user_settings.screen_size].flags >> 1) & 3;
            break;
        case 1:
            if (mode == PIP_PBP_PBP)
                width_mode = 1;
            else if (mode == PIP_PBP_PIP || mode == PIP_PBP_MODE_4)
                width_mode = (window_ratios[(user_settings.pip_location.word >> 16) & 0xff][RATIO_FLAGS] >> 1) & 3;
            else
                width_mode = (window_ratios[user_settings.image_enhancement >> 28][RATIO_FLAGS] >> 1) & 3;
            break;
        case 2:
            if (mode == PIP_PBP_MODE_4)
                width_mode = (window_ratios[(user_settings.pip_location.word >> 8) & 0xf][RATIO_FLAGS] >> 1) & 3;
            else
                width_mode = (window_ratios[(user_settings.image_enhancement >> 24) & 0xf][RATIO_FLAGS] >> 1) & 3;
            break;
        case 3:
            width_mode = (window_ratios[(user_settings.image_enhancement >> 20) & 0xf][RATIO_FLAGS] >> 1) & 3;
            break;
        }
    } else {
        if (channel == 0)
            width_mode = (screen_size_ratios[user_settings.screen_size].flags >> 1) & 3;
        else
            width_mode = 1;
    }
    return width_mode & 3;
}


/* Vertical ratio of the channel's window (RATIO_ONE = 1.0). */
static __inline__ unsigned short window_v_ratio(unsigned char channel)
{
    unsigned short ratio = RATIO_ONE;
    WINDOW_RATIO_TABLES;
    unsigned char mode = user_settings.pip_pbp_mode;

    if (mode != PIP_PBP_OFF) {
        switch (channel) {
        case 0:
            if (mode != PIP_PBP_PIP && mode != PIP_PBP_MODE_4)
                ratio = window_ratios[(user_settings.pip_location.word >> 12) & 0xf][RATIO_V];
            else
                ratio = screen_size_ratios[user_settings.screen_size].v_ratio;
            break;
        case 1:
            if (mode == PIP_PBP_PIP || mode == PIP_PBP_MODE_4)
                ratio = window_ratios[(user_settings.pip_location.word >> 16) & 0xff][RATIO_V];
            else
                ratio = window_ratios[user_settings.image_enhancement >> 28][RATIO_V];
            break;
        case 2:
            if (mode == PIP_PBP_MODE_4)
                ratio = window_ratios[(user_settings.pip_location.word >> 8) & 0xf][RATIO_V];
            else
                ratio = window_ratios[(user_settings.image_enhancement >> 24) & 0xf][RATIO_V];
            break;
        case 3:
            ratio = window_ratios[(user_settings.image_enhancement >> 20) & 0xf][RATIO_V];
            break;
        }
    } else
        ratio = screen_size_ratios[user_settings.screen_size].v_ratio;
    return ratio;
}

/* Horizontal ratio of the channel's window (RATIO_ONE = 1.0). */
static __inline__ unsigned short window_h_ratio(unsigned char channel)
{
    unsigned short ratio = RATIO_ONE;
    WINDOW_RATIO_TABLES;
    unsigned char mode = user_settings.pip_pbp_mode;

    if (mode != PIP_PBP_OFF) {
        switch (channel) {
        case 0:
            if (mode != PIP_PBP_PIP && mode != PIP_PBP_MODE_4)
                ratio = window_ratios[(user_settings.pip_location.word >> 12) & 0xf][RATIO_H];
            else
                ratio = screen_size_ratios[user_settings.screen_size].h_ratio;
            break;
        case 1:
            if (mode == PIP_PBP_PIP || mode == PIP_PBP_MODE_4)
                ratio = window_ratios[(user_settings.pip_location.word >> 16) & 0xff][RATIO_H];
            else
                ratio = window_ratios[user_settings.image_enhancement >> 28][RATIO_H];
            break;
        case 2:
            if (mode == PIP_PBP_MODE_4)
                ratio = window_ratios[(user_settings.pip_location.word >> 8) & 0xf][RATIO_H];
            else
                ratio = window_ratios[(user_settings.image_enhancement >> 24) & 0xf][RATIO_H];
            break;
        case 3:
            ratio = window_ratios[(user_settings.image_enhancement >> 20) & 0xf][RATIO_H];
            break;
        }
    } else
        ratio = screen_size_ratios[user_settings.screen_size].h_ratio;
    return ratio;
}


/* Lines of the PIP window for size 2. Timing field 4 of channel 1 is read and not used. */
static __inline__ unsigned short pip_size2_lines(void)
{
    input_api_get_timing_field(1, 4);
    return 0x21c;       /* 540 */
}

/*
 * Base window size of the channel: the whole panel, or the share of it that the PIP/PBP mode gives the channel.
 *   channel 0: PBP by the layout (about 3/4, 1/2, pbp_channel0_width, else 1/2 of the width); mode 5 half the
 *              width; modes 6 and 7 a quarter (half width, half height).
 *   channel 1: PIP/PBP off: a centred square of 1/4, 1/3 or 1/2 of the panel lines by the Optix Scope size;
 *              PIP and mode 4: the PIP size; PBP: the rest of the width by the layout; modes 5..7 a quarter;
 *              mode 3 the whole panel.
 *   channel 2: mode 4 by the second PIP size; modes 5 and 7 a quarter; mode 6 half the width.
 *   channel 3: mode 7 a quarter.
 */
static __inline__ void base_window_size(unsigned char channel, unsigned short *width_out, unsigned short *height_out)
{
    unsigned short width, height;
    unsigned char size;

    width = panel_api_get_active_size(PANEL_SIZE_WIDTH);
    height = panel_api_get_active_size(PANEL_SIZE_LINES);
    switch (channel) {
    case 0:
        switch (user_settings.pip_pbp_mode) {
        case PIP_PBP_PBP:
            if (user_settings.pbp_layout == PBP_LAYOUT_0)
                width = ((width * 3) >> 5) << 3;
            else if (user_settings.pbp_layout == PBP_LAYOUT_1)
                width = (width >> 4) << 3;
            else if (user_settings.pbp_layout == PBP_LAYOUT_CUSTOM)
                width = user_settings.pbp_channel0_width;
            else
                width = width >> 1;
            break;
        case PIP_PBP_MODE_5:
            width = width >> 1;
            break;
        case PIP_PBP_MODE_6:
            width = width >> 1;
            height = height >> 1;
            break;
        case PIP_PBP_MODE_7:
            width = width >> 1;
            height = height >> 1;
            break;
        }
        break;
    case 1:
        switch (user_settings.pip_pbp_mode) {
        case PIP_PBP_OFF:
            /* A square sized by the Optix Scope size. */
            if (user_settings.scope_size == 0) {
                width = panel_api_get_active_size(PANEL_SIZE_LINES) >> 2;
                height = panel_api_get_active_size(PANEL_SIZE_LINES) >> 2;
            } else if (user_settings.scope_size == 1) {
                width = panel_api_get_active_size(PANEL_SIZE_LINES) / 3;
                height = panel_api_get_active_size(PANEL_SIZE_LINES) / 3;
            } else {
                width = panel_api_get_active_size(PANEL_SIZE_LINES) >> 1;
                height = panel_api_get_active_size(PANEL_SIZE_LINES) >> 1;
            }
            break;
        case PIP_PBP_PIP:
            size = (user_settings.pip_location.word >> 16) & 0xff;
            if (size == 0) {
                width = PIP_SIZE0_WIDTH;
                height = PIP_SIZE0_LINES;
            } else if (size == 1) {
                width = PIP_SIZE1_WIDTH;
                height = PIP_SIZE1_LINES;
            } else if (size == 2) {
                width = PIP_SIZE2_WIDTH;
                height = pip_size2_lines();
            } else {
                /* Computed size; the width is kept even. */
                width = size * 15;
                height = size * 8 + 0x137;
                width = (width + 0x228) & ~1;
            }
            break;
        case PIP_PBP_PBP:
            if (user_settings.pbp_layout == PBP_LAYOUT_0)
                width = (width >> 5) << 3;
            else if (user_settings.pbp_layout == PBP_LAYOUT_1)
                width = (width >> 4) << 3;
            else if (user_settings.pbp_layout == PBP_LAYOUT_CUSTOM)
                width = width - user_settings.pbp_channel0_width;
            else
                width = width >> 1;
            break;
        case PIP_PBP_MODE_5:
        case PIP_PBP_MODE_6:
            width = width >> 1;
            height = height >> 1;
            break;
        case 3:
            break;
        case PIP_PBP_MODE_7:
            width = width >> 1;
            height = height >> 1;
            break;
        case PIP_PBP_MODE_4:
            size = (user_settings.pip_location.word >> 16) & 0xff;
            if (size == 0) {
                width = PIP_SIZE0_WIDTH;
                height = PIP_SIZE0_LINES;
            } else if (size == 1) {
                width = PIP_SIZE1_WIDTH;
                height = PIP_SIZE1_LINES;
            } else if (size == 2) {
                width = PIP_SIZE2_WIDTH;
                height = pip_size2_lines();
            } else {
                width = size * 15;
                height = size * 8 + 0x137;
                width = (width + 0x228) & ~1;
            }
            break;
        }
        break;
    case 2:
        switch (user_settings.pip_pbp_mode) {
        case PIP_PBP_MODE_4:
            /* second_pip_size: 0, 1, anything else = size 2. */
            if ((user_settings.pip_location.word & 0xf00) == 0) {
                width = PIP_SIZE0_WIDTH;
                height = PIP_SIZE0_LINES;
            } else if ((user_settings.pip_location.word & 0xf00) == 0x100) {
                width = PIP_SIZE1_WIDTH;
                height = PIP_SIZE1_LINES;
            } else {
                width = PIP_SIZE2_WIDTH;
                height = pip_size2_lines();
            }
            break;
        case PIP_PBP_MODE_5:
            width = width >> 1;
            height = height >> 1;
            break;
        case PIP_PBP_MODE_6:
            width = width >> 1;
            break;
        case PIP_PBP_MODE_7:
            width = width >> 1;
            height = height >> 1;
            break;
        }
        break;
    case 3:
        if (user_settings.pip_pbp_mode == PIP_PBP_MODE_7) {
            width = width >> 1;
            height = height >> 1;
        }
        break;
    }

    *width_out = width;
    *height_out = height;
}

/*
 * Base window position of the channel on the panel. Channel 0 is always at 0, 0.
 *   channel 1: PIP/PBP off: centred; PIP and mode 4: by the PIP location (Customize: pip_custom_x / _y, pulled
 *              back and stored when the window would leave the panel); PBP and mode 5: y 0, x by the layout
 *              (about 3/4, 1/2, pbp_channel0_width, else 1/2 of the width); modes 6 and 7: x 0, y half the
 *              height.
 *   channel 2: mode 4: by its corner; mode 5: x and y half the panel; modes 6 and 7: x half the width, y 0.
 *   channel 3: mode 7: x and y half the panel.
 */
static __inline__ void base_window_position(unsigned char channel, unsigned short width, unsigned short height,
                                     unsigned short *x_out, unsigned short *y_out)
{
    unsigned short panel_width, panel_height, x, y;
    unsigned char size;

    panel_width = panel_api_get_active_size(PANEL_SIZE_WIDTH);
    panel_height = panel_api_get_active_size(PANEL_SIZE_LINES);
    x = 0;
    y = 0;
    switch (channel) {
    case 0:
        x = 0;
        break;
    case 1:
        if (user_settings.pip_pbp_mode == PIP_PBP_OFF) {
            x = (panel_width - width) / 2;
            y = (panel_height - height) / 2;
        } else if (user_settings.pip_pbp_mode == PIP_PBP_PIP || user_settings.pip_pbp_mode == PIP_PBP_MODE_4) {
            switch ((user_settings.pip_location.word >> 4) & 0xf) {
            case PIP_LOCATION_CUSTOMIZE:
                {
                /* The stored position, limited so that the window of the current PIP size stays on the
                   panel; a limited value is written back. */
                struct user_settings_record *settings = &user_settings;
                size = (settings->pip_location.word >> 16) & 0xff;
                if (size == 0) {
                    x = settings->pip_custom_x;
                    y = settings->pip_custom_y;
                    if (x > panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE0_WIDTH) {
                        x = panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE0_WIDTH;
                        settings->pip_custom_x = x;
                    }
                    if (y > panel_api_get_active_size(PANEL_SIZE_LINES) - PIP_SIZE0_LINES) {
                        y = panel_api_get_active_size(PANEL_SIZE_LINES) - PIP_SIZE0_LINES;
                        settings->pip_custom_y = y;
                    }
                } else if (size == 1) {
                    x = settings->pip_custom_x;
                    y = settings->pip_custom_y;
                    if (x > panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE1_WIDTH) {
                        x = panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE1_WIDTH;
                        settings->pip_custom_x = x;
                    }
                    if (y > panel_api_get_active_size(PANEL_SIZE_LINES) - PIP_SIZE1_LINES) {
                        y = panel_api_get_active_size(PANEL_SIZE_LINES) - PIP_SIZE1_LINES;
                        settings->pip_custom_y = y;
                    }
                } else if (size == 2) {
                    x = settings->pip_custom_x;
                    y = settings->pip_custom_y;
                    if (x > panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE2_WIDTH) {
                        x = panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE2_WIDTH;
                        settings->pip_custom_x = x;
                    }
                    if (y > panel_api_get_active_size(PANEL_SIZE_LINES) - pip_size2_lines()) {
                        y = panel_api_get_active_size(PANEL_SIZE_LINES) - pip_size2_lines();
                        settings->pip_custom_y = y;
                    }
                }
                /* A computed size (above 2) leaves the window at 0, 0. */
                }
                break;
            case PIP_LOCATION_RIGHT_TOP:
                x = panel_width - width;
                y = 0;
                break;
            case PIP_LOCATION_LEFT_BOTTOM:
                x = 0;
                size = (user_settings.pip_location.word >> 16) & 0xff;
                if (size == 0)
                    y = panel_height - PIP_SIZE0_LINES;
                else if (size == 1)
                    y = panel_height - PIP_SIZE1_LINES;
                else {
                    y = panel_height - pip_size2_lines();
                }
                break;
            case PIP_LOCATION_RIGHT_BOTTOM:
                x = panel_width - width;
                size = (user_settings.pip_location.word >> 16) & 0xff;
                if (size == 0)
                    y = panel_height - PIP_SIZE0_LINES;
                else if (size == 1)
                    y = panel_height - PIP_SIZE1_LINES;
                else {
                    y = panel_height - pip_size2_lines();
                }
                break;
            case PIP_LOCATION_LEFT_TOP:
                x = 0;
                y = 0;
                break;
            default:
                break;
            }
        } else if (user_settings.pip_pbp_mode == PIP_PBP_PBP || user_settings.pip_pbp_mode == PIP_PBP_MODE_5) {
            if (user_settings.pbp_layout == PBP_LAYOUT_0)
                x = ((panel_width * 3) >> 5) << 3;
            else if (user_settings.pbp_layout == PBP_LAYOUT_1)
                x = panel_width >> 1;
            else if (user_settings.pbp_layout == PBP_LAYOUT_CUSTOM)
                x = user_settings.pbp_channel0_width;
            else
                x = panel_width >> 1;
            y = 0;
        } else if (user_settings.pip_pbp_mode == PIP_PBP_MODE_6 || user_settings.pip_pbp_mode == PIP_PBP_MODE_7) {
            x = 0;
            y = panel_height >> 1;
        }
        break;
    case 2:
        if (user_settings.pip_pbp_mode == PIP_PBP_MODE_4) {
            /* A window wider or taller than half the panel is pulled in to the right or bottom edge;
               a smaller one starts at the middle. */
            switch (user_settings.pip_location.f.second_location) {
            case PIP_LOCATION_LEFT_TOP:
                x = 0;
                break;
            case PIP_LOCATION_RIGHT_TOP:
                x = (width > (panel_width >> 1)) ? panel_width - width : panel_width >> 1;
                y = 0;
                break;
            case PIP_LOCATION_LEFT_BOTTOM:
                x = 0;
                y = (height > (panel_height >> 1)) ? panel_height - height : panel_height >> 1;
                break;
            case PIP_LOCATION_RIGHT_BOTTOM:
                x = (width > (panel_width >> 1)) ? panel_width - width : panel_width >> 1;
                y = (height > (panel_height >> 1)) ? panel_height - height : panel_height >> 1;
                break;
            }
        } else if (user_settings.pip_pbp_mode == PIP_PBP_MODE_5) {
            x = panel_width >> 1;
            y = panel_height >> 1;
        } else if (user_settings.pip_pbp_mode == PIP_PBP_MODE_6 || user_settings.pip_pbp_mode == PIP_PBP_MODE_7) {
            x = panel_width >> 1;
        }
        break;
    case 3:
        if (user_settings.pip_pbp_mode == PIP_PBP_MODE_7) {
            x = panel_width >> 1;
            y = panel_height >> 1;
        }
        break;
    }

    *x_out = x;
    *y_out = y;
}

/* The window handed back: eight halfwords; input_store_capture_window reads the same layout. */
struct disp_win {
    unsigned short shown_width, shown_height;   /* size of the window actually shown */
    unsigned short base_width, base_height;     /* size of the base window */
    unsigned short base_x, base_y;              /* position of the base window on the panel */
    unsigned short offset_x, offset_y;          /* offset of the shown window inside the base window */
};

/*
 * Compute the display window of one channel from the PIP/PBP settings, the Screen Size and the input size, and
 * write it to *window.
 *
 * channel: 0 = the main picture, 1..3 = the other windows. window: filled with the eight values of struct
 * disp_win. Called by UserSetPIPMode, sys_user_factory_reset and the sys_user_*_window_channel1 / _channel2
 * routines, which pass the result on to input_api_set_capture_window; startup_register_app_callbacks also
 * registers it as callback 3.
 *
 * Phases, in order:
 *   1. Sizes: the input size (measured once the channel is past MODE_MODESEARCH, else the panel size), the
 *      panel size, the base window size and position (base_window_size, base_window_position), the two
 *      aspect ratios width * 100 / height of the base window and of the input; print the base window.
 *   2. PIP/PBP modes other than OFF, PIP and 4: the shown window comes from the ratio tables. Height by the
 *      height mode, rounded down to a multiple of 4 and printed, at most the panel height; width by the width
 *      mode; the shown window is centred in the base window.
 *   3. Otherwise, channel 0 only: with SETTINGS_VIDEO_WALL set, the whole panel plus the four adjustments
 *      +0x3A..+0x3D; else by the Screen Size value.
 *   4. Otherwise (channels 1..3 in modes OFF, PIP and 4): the shown window is the base window.
 *   5. Write the eight values.
 */
void APP_ConfigDispSize(unsigned char channel, struct disp_win *window)
{
    unsigned short input_width, input_height, panel_width, panel_height;
    unsigned short base_width = 0, base_height = 0, base_x = 0, base_y = 0, offset_x = 0, offset_y = 0;
    unsigned short shown_width, shown_height, base_ratio, input_ratio;
    unsigned int remainder;   /* shown_height % 4 */

    /* 1. Input, panel and base window. */
    if (sys_api_get_channel_state_code(channel) > STATE_CODE_MODESEARCH) {
        input_width = input_api_get_timing_field(channel, TIMING_WIDTH);
        input_height = input_api_get_timing_field(channel, TIMING_HEIGHT);
    } else {
        input_width = panel_api_get_active_size(PANEL_SIZE_WIDTH);
        input_height = panel_api_get_active_size(PANEL_SIZE_LINES);
    }
    panel_width = panel_api_get_active_size(PANEL_SIZE_WIDTH);
    panel_height = panel_api_get_active_size(PANEL_SIZE_LINES);
    base_window_size(channel, &base_width, &base_height);
    base_window_position(channel, base_width, base_height, &base_x, &base_y);

    shown_width = base_width;
    shown_height = base_height;
    base_ratio = (unsigned int)(base_width * 100) / base_height;
    input_ratio = (unsigned int)(input_width * 100) / input_height;
    dbg_printf("APP_ConfigDispSize_%d_bg : %d %d %d %d\r\n", channel, base_width, base_height, base_x, base_y);

    if (user_settings.pip_pbp_mode > PIP_PBP_PIP && user_settings.pip_pbp_mode != PIP_PBP_MODE_4) {
        /* 2. Scale by the ratio tables. Height first. */
        switch (window_height_mode(channel)) {
        default:
            shown_height = (unsigned int)(base_height * window_v_ratio(channel) + RATIO_ROUND) / RATIO_ONE;
            break;
        case HEIGHT_FROM_INPUT:
            shown_height = (unsigned int)(input_height * window_v_ratio(channel) + RATIO_ROUND) / RATIO_ONE;
            break;
        case HEIGHT_KEEP_INPUT_ASPECT:
            if (input_height == 0 || input_width == 0)
                shown_height = base_height;
            else {
                shown_height = (unsigned int)(shown_width * input_height) / input_width;
                if (shown_height > base_height)
                    shown_height = base_height;
            }
            break;
        }
        remainder = shown_height & 3;
        if (remainder)
            shown_height -= remainder;
        dbg_printf("\x1b[1;35m(%d)height(%d) %d\r\n\x1b[m", channel, window_height_mode(channel), shown_height);
        if (shown_height > panel_height)
            shown_height = panel_height;
        /* Then the width. */
        switch (window_width_mode(channel)) {
        default:
            shown_width = (unsigned int)(base_width * window_h_ratio(channel) + RATIO_ROUND) / RATIO_ONE;
            break;
        case WIDTH_FIT:
            if (input_ratio > base_ratio || shown_height < panel_height)
                shown_width = base_width;
            else
                shown_width = (unsigned int)(shown_height * input_width) / input_height;
            break;
        case WIDTH_FROM_HEIGHT:
            shown_width = (unsigned int)(shown_height * window_h_ratio(channel) + RATIO_ROUND) / RATIO_ONE;
            break;
        }
        offset_x = (base_width - shown_width) >> 1;
        offset_y = (base_height - shown_height) >> 1;
    } else if (channel == 0) {
        /* 3. Main picture in modes OFF, PIP and 4. */
        if (user_settings.word_0x0 & SETTINGS_VIDEO_WALL) {
            base_width = panel_width;
            base_height = panel_height;
            shown_width = panel_width;
            shown_width += user_settings.byte_0x3a;
            shown_height = panel_height;
            shown_height += user_settings.byte_0x3c;
            offset_x = (3 - user_settings.byte_0x3b) * 8;
            offset_y = 3 - user_settings.byte_0x3d;
        } else {
            switch (user_settings.screen_size) {
            case SCREEN_SIZE_INPUT_ASPECT:
                shown_height = panel_height;
                shown_width = (unsigned int)(panel_height * input_width) / input_height;
                base_height = panel_height;
                if (shown_width > panel_width)
                    shown_width = panel_width;
                base_width = panel_width;
                base_x = 0;
                base_y = 0;
                offset_x = (base_width - shown_width) >> 1;
                offset_y = 0;
                break;
            case SCREEN_SIZE_4_3:
                shown_height = panel_height;
                shown_width = (unsigned int)(panel_height * RATIO_4_3 + RATIO_ROUND) / RATIO_ONE;
                base_height = panel_height;
                base_width = panel_width;
                offset_x = (base_width - shown_width) >> 1;
                base_x = 0;
                base_y = 0;
                offset_y = 0;
                break;
            case SCREEN_SIZE_1_1:
            case SCREEN_SIZE_1_1_B:
                if (input_width > panel_width || input_height > panel_height) {
                    /* Does not fit: whole panel. */
                    shown_width = panel_width;
                    shown_height = panel_height;
                    base_width = panel_width;
                    base_height = panel_height;
                    base_x = 0;
                    base_y = 0;
                    offset_x = 0;
                    offset_y = 0;
                    break;
                }
                base_height = panel_height;
                shown_height = input_height;
                base_width = panel_width;
                base_x = 0;
                base_y = 0;
                shown_width = input_width;
                offset_x = (base_width - input_width) >> 1;
                offset_y = (base_height - input_height) >> 1;
                break;
            case SCREEN_SIZE_2992X1680:
                if (input_width > panel_width || input_height > panel_height)
                    goto full;
                shown_width = 0xbb0;
                shown_height = 0x690;
                base_width = panel_width;
                base_height = panel_height;
                base_x = 0;
                base_y = 0;
                offset_x = (base_width - shown_width) >> 1;
                offset_y = (base_height - shown_height) >> 1;
                break;
            case SCREEN_SIZE_3296X1852:
                if (input_width > panel_width || input_height > panel_height)
                    goto full;
                shown_width = 0xce0;
                shown_height = 0x73c;
                base_width = panel_width;
                base_height = panel_height;
                base_x = 0;
                base_y = 0;
                offset_x = (base_width - shown_width) >> 1;
                offset_y = (base_height - shown_height) >> 1;
                break;
            case SCREEN_SIZE_4_3_B:
                shown_height = panel_height;
                shown_width = (unsigned int)(panel_height * RATIO_4_3 + RATIO_ROUND) / RATIO_ONE;
                base_height = panel_height;
                base_width = panel_width;
                offset_x = (base_width - shown_width) >> 1;
                base_x = 0;
                base_y = 0;
                offset_y = 0;
                break;
            default:    /* 2, 3, 7 and above 9: whole panel */
            full:
                shown_width = panel_width;
                shown_height = panel_height;
                base_width = panel_width;
                base_height = panel_height;
                base_x = 0;
                base_y = 0;
                offset_x = 0;
                offset_y = 0;
                break;
            }
        }
    }
    /* 4. Channels 1..3 in modes OFF, PIP and 4 keep shown = base and offsets 0. */

    /* 5. Result. */
    window->shown_width = shown_width;
    window->shown_height = shown_height;
    window->base_width = base_width;
    window->base_height = base_height;
    window->base_x = base_x;
    window->base_y = base_y;
    window->offset_x = offset_x;
    window->offset_y = offset_y;
}
