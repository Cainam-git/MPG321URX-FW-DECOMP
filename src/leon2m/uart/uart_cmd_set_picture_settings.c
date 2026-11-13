/* uart_cmd_set_picture_settings  (FUN_a00c68d8)
 *
 * Set several picture settings from one PC tool command.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b001e (26-byte frame); skipped bytes 0 / 0xFF keep a field; colour temperature, gains,
 *   contrast, sharpness, low blue light, ...
 * Name basis: proven - set row 0x8d; writes +0x11..+0x14, +0xA, +0x49, +0x11C, +0x34 ... with the same apply
 *   routines as the single commands
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c68d8 @ 0xa00c68d8-0xa00c762c (3412 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers, frame_byte_is_set() and rx_byte() are defined in this file, so GCC inlines them at
 *    -O3 (as in uart_cmd_set_pip_pbp_settings);
 *  - each frame byte is read through rx_byte() into an unsigned int and tested through
 *    frame_byte_is_set(unsigned char); the value is computed into an unsigned short and the bit-fields are
 *    assigned its unsigned char value;
 *  - the colour temperature result is kept in an unsigned char that is copied from the raw byte before the test;
 *  - the Adaptive-Sync change is tested as (bit ^ old) & 1;
 *  - alarm_running of the application state is set through a 1-bit field.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': a value byte of the frame is the value plus 0x30 */
#define FRAME_BYTE_UNSET          0         /* a frame byte of 0 or 0xFF leaves its setting as it is */
#define FRAME_BYTE_UNSET_FF       0xff

/* Frame bytes of the 26-byte command and what each one sets (value = byte - 0x30, largest accepted value). */
#define FRAME_BLUR_FREE           0x08      /* blur_free_mode, 0..1 */
#define FRAME_AUTO_LEVEL          0x09      /* professional_flags.auto_level, 0..1 */
#define FRAME_REFRESH_RATE        0x0a      /* gaming_flags bit 12 (Refresh Rate display), 0..1 */
#define FRAME_REFRESH_RATE_LOC    0x0b      /* refresh_rate_location, 0..4 */
#define FRAME_ALARM_CLOCK         0x0c      /* alarm_clock, 0..4 */
#define FRAME_ALARM_CLOCK_LOC     0x0d      /* alarm_clock_location, 0..4 */
#define FRAME_CROSSHAIR_ICON      0x0e      /* crosshair_icon, 0..12 */
#define FRAME_ADAPTIVE_SYNC       0x0f      /* gaming_flags bit 7 (Adaptive-Sync), 0..1 */
#define FRAME_LOW_BLUE_LIGHT      0x10      /* professional_flags.low_blue_light, 0..1 */
#define FRAME_IMAGE_ENHANCEMENT   0x11      /* image_enhancement, 0..4 */
#define FRAME_BRIGHTNESS          0x12      /* brightness, 0..100 */
#define FRAME_CONTRAST            0x13      /* contrast, 0..100 */
#define FRAME_SHARPNESS           0x14      /* sharpness, no limit */
#define FRAME_COLOR_TEMPERATURE   0x15      /* color_temperature, 0..3 */
#define FRAME_RED_GAIN            0x16      /* red_gain, 0..100, read only with Customization */
#define FRAME_GREEN_GAIN          0x17      /* green_gain, 0..100 */
#define FRAME_BLUE_GAIN           0x18      /* blue_gain, 0..100 */
#define FRAME_BYTE_0x140          0x06      /* settings byte +0x140, 0..10 */
#define FRAME_RESPONSE_TIME       0x07      /* response_time, 0..2 */

#define COLOR_TEMP_CUSTOMIZATION  3         /* Color Temperature "Customization": the custom gains are used */
#define ON_OFF_MAX                1
#define LEVEL_MAX                 100       /* gains, contrast and brightness */
#define COLOR_TEMP_MAX            3
#define IMAGE_ENHANCEMENT_MAX     4
#define RESPONSE_TIME_MAX         2
#define BYTE_0x140_MAX            10
#define LOCATION_MAX              4         /* overlay locations 0..4 */
#define ALARM_CHOICE_MAX          4         /* 0 = off, 1..4 = one of the four timers */
#define CROSSHAIR_ICON_MAX        12

#define GAMING_FLAG_ADAPTIVE_SYNC 0x80      /* user settings +0xA8 bit 7: Adaptive-Sync */
#define GAMING_FLAG_REFRESH_RATE  0x1000    /* user settings +0xA8 bit 12: Refresh Rate display */
#define SETTINGS_INFO_ON_SCREEN   0x400000  /* user settings +0xAC bit 22: Info. On Screen */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The application state record (0xA802CFF4) as far as it is used here: halfword +0 and the sleep word +4. */
struct app_state_record {
    unsigned short flags_bit15 : 1,
                   alarm_running : 1,           /* +0 bit 14: an alarm clock timer runs */
                   flags_rest : 14;
    unsigned short half_0x2;
    unsigned short sleep_bit15 : 1,
                   sleep_state : 2,             /* +4 bits 13..14 (2 = fake sleep) */
                   sleep_rest : 13;
};
extern struct app_state_record app_state_record;

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[9];
    unsigned char brightness, contrast;         /* +0x09 Brightness, +0x0A Contrast */
    unsigned char pad00b[0x11 - 0xb];
    unsigned char color_temperature;            /* +0x11: Color Temperature */
    unsigned char red_gain, green_gain, blue_gain;  /* +0x12..+0x14: the custom gains */
    unsigned char pad015[0x19 - 0x15];
    unsigned char response_time;                /* +0x19: the response time level */
    unsigned char pad01a[0x1f - 0x1a];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 off, 1 PIP, 2 PBP */
    unsigned char pad020[0x34 - 0x20];
    unsigned int bits_31_20 : 12,
                 image_enhancement : 4,         /* +0x34 bits 16..19: Image Enhancement level */
                 bits_15_0 : 16;
    unsigned char pad038[0x49 - 0x38];
    unsigned char sharpness, optix_scope;       /* +0x49 Sharpness, +0x4A the Optix Scope switch */
    unsigned char pad04b[0xa8 - 0x4b];
    union {
        unsigned int word;
        struct {
            unsigned int bits_31_13 : 19,
                         refresh_rate_display : 1,  /* bit 12 */
                         bits_11_8 : 4,
                         adaptive_sync : 1,     /* bit 7 */
                         bits_6_0 : 7;
        } bits;
    } gaming_flags;                             /* +0xA8 */
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned char pad0b4[0x11c - 0xb4];
    struct {
        unsigned int auto_level : 1,            /* bit 31: automatic level */
                     bits_30_5 : 26,
                     low_blue_light : 1,        /* bit 4: Low Blue Light */
                     bits_3_0 : 4;
    } professional_flags;                       /* +0x11C */
    unsigned char pad120[0x13e - 0x120];
    unsigned char refresh_rate_location;        /* +0x13E: location of the Refresh Rate overlay */
    unsigned char alarm_clock_location;         /* +0x13F: location of the Alarm Clock overlay */
    unsigned char byte_0x140;                   /* +0x140 */
    unsigned char pad141[0x178 - 0x141];
    unsigned char byte_0x178;                   /* +0x178: cleared when Low Blue Light is switched on */
    unsigned char pad179[0x190 - 0x179];
    unsigned char crosshair_icon;               /* +0x190: the Smart Crosshair icon */
    unsigned char pad191[0x197 - 0x191];
    /* alarm_minutes_table (+0x198) and alarm_seconds_table (+0x19C) seen one byte early, so that entry
       [choice] is the time of timer `choice` (1..4). */
    unsigned char alarm_minutes_by_choice[4];   /* +0x197 */
    unsigned char alarm_seconds_by_choice[5];   /* +0x19B */
    unsigned char alarm_clock;                  /* +0x1A0: the Alarm Clock timer choice */
    unsigned char alarm_minutes;                /* +0x1A1: minutes of the chosen timer */
    unsigned char alarm_seconds;                /* +0x1A2: seconds of the chosen timer */
    unsigned char byte_0x1a3;
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
};
extern struct user_settings_record user_settings;
extern int sys_user_get_picture_state(void);
extern int pq_user_apply_color_gain(void);
extern void pq_user_apply_color_settings(void);
extern void sys_user_apply_channel0_scaling_mode(void);
extern void sys_user_apply_channel1_scaling_mode(void);
extern int pq_user_apply_sharpness(void);
extern void sys_user_apply_auto_level(void);
extern void sys_user_clear_second_picture_request(void);
extern void sys_user_apply_second_picture_enable(int);
extern void sys_poll_events_stub_copy(void);
extern void sys_user_apply_brightness(void);
extern void pq_user_reset_response_level(void);
extern void osd_open_menu_state_0x106(void);
extern void osd_close_menu(void);
extern unsigned char sys_user_save_mode_slot();
extern void audio_mute_outputs(void);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void panel_user_set_output_on(int);
extern void sys_api_restart_channel_at_level(int, int);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void pq_update_input_window(int);
extern void osd_mark_settings_changed_copy(void);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/* Put the acknowledge "5600+\r" into the reply frame of the port. */
void uart_cmd_build_ok_reply(unsigned char port)
{
    if (port == 2) {
        uart_cmd_tx_frame_port2[0] = '5';
        uart_cmd_tx_frame_port2[1] = '6';
        uart_cmd_tx_frame_port2[2] = '0';
        uart_cmd_tx_frame_port2[3] = '0';
        uart_cmd_tx_frame_port2[4] = '+';
        uart_cmd_tx_frame_port2[5] = '\r';
    } else if (port == 3) {
        uart_cmd_tx_frame_port3[0] = '5';
        uart_cmd_tx_frame_port3[1] = '6';
        uart_cmd_tx_frame_port3[2] = '0';
        uart_cmd_tx_frame_port3[3] = '0';
        uart_cmd_tx_frame_port3[4] = '+';
        uart_cmd_tx_frame_port3[5] = '\r';
    } else {
        uart_cmd_tx_frame[0] = '5';
        uart_cmd_tx_frame[1] = '6';
        uart_cmd_tx_frame[2] = '0';
        uart_cmd_tx_frame[3] = '0';
        uart_cmd_tx_frame[4] = '+';
        uart_cmd_tx_frame[5] = '\r';
    }
}

/* Make the port ready for the next command: clear its receive state byte and bytes 0, 1, 7, 10 and 0x19 of its
   receive record. */
void uart_cmd_clear_rx(unsigned char port)
{
    if (port == 2) {
        uart_cmd_rx_state_port2 = 0;
        uart_cmd_rx_record_port2[0] = 0;
        uart_cmd_rx_record_port2[1] = 0;
        uart_cmd_rx_record_port2[7] = 0;
        uart_cmd_rx_record_port2[10] = 0;
        uart_cmd_rx_record_port2[0x19] = 0;
    } else if (port == 3) {
        uart_cmd_rx_state_port3 = 0;
        uart_cmd_rx_record_port3[0] = 0;
        uart_cmd_rx_record_port3[1] = 0;
        uart_cmd_rx_record_port3[7] = 0;
        uart_cmd_rx_record_port3[10] = 0;
        uart_cmd_rx_record_port3[0x19] = 0;
    } else {
        uart_cmd_rx_count = 0;
        uart_cmd_rx_record[0] = 0;
        uart_cmd_rx_record[1] = 0;
        uart_cmd_rx_record[7] = 0;
        uart_cmd_rx_record[10] = 0;
        uart_cmd_rx_record[0x19] = 0;
    }
}

/* Send the first `length` bytes of the port's reply frame through the 8051. */
void uart_cmd_send_tx_buffer(unsigned char port, unsigned char length)
{
    if (port == 2)
        uart_api_send_bytes(2, length, uart_cmd_tx_frame_port2);
    else if (port == 3)
        uart_api_send_bytes(3, length, uart_cmd_tx_frame_port3);
    else
        uart_api_send_bytes(port, length, uart_cmd_tx_frame);
}

/* A frame byte of 0 or 0xFF means "leave this setting as it is". */
static int frame_byte_is_set(unsigned char frame_byte)
{
    return frame_byte != FRAME_BYTE_UNSET && frame_byte != FRAME_BYTE_UNSET_FF;
}

/* Byte `index` of the port's receive record. */
static unsigned char rx_byte(unsigned char port, int index)
{
    if (port == 2)
        return uart_cmd_rx_record_port2[index];
    if (port == 3)
        return uart_cmd_rx_record_port3[index];
    return uart_cmd_rx_record[index];
}

/*
 * Set row 0x8D (141) of uart_cmd_dispatch_set, the 26-byte frame "5b001e": set up to nineteen picture and overlay
 * settings from one frame of the PC tool and apply them.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) as soon as one value is above its
 * limit; then nothing is replied here and the dispatcher answers "5600-". The settings handled before the refused
 * one keep their new values. Every frame byte that is 0 or 0xFF is skipped and leaves its setting unchanged; the
 * FRAME_* list above gives each byte's setting and limit.
 *
 * Phases, in the order of the code:
 *   1. Colour: Color Temperature; only when the frame's own Color Temperature byte is set and says Customization
 *      (3) are the red, green and blue gains read. Then Low Blue Light (switching it on clears settings byte
 *      +0x178) and Contrast, applied together through pq_user_apply_color_gain and pq_user_apply_color_settings.
 *   2. Image Enhancement (applied to channels 0 and 1 through the scaling-mode routines) and Sharpness.
 *   3. Automatic level: switching it on also clears the blur reduction mode. sys_user_apply_auto_level runs
 *      whether or not the byte was set.
 *   4. Blur reduction mode: a changed value switches Optix Scope and the automatic level off. While the mode is
 *      on, PIP/PBP is switched off and Screen Size 4..6 is set back to 0, both with the picture output switched
 *      off first. These two steps run whenever the byte is set, also when the value did not change.
 *   5. Response time: stored only with the blur reduction mode off (or a picture state other than 0), PIP/PBP
 *      off and a changed value. Byte +0x140. Brightness: stored only with the blur reduction mode and the
 *      automatic level off.
 *   6. Overlays: Refresh Rate display, its location, the Alarm Clock timer (choosing a timer copies its time
 *      and marks the alarm as running), its location and the crosshair icon. When the sleep state is 0 the
 *      menu is closed and the screen overlays are drawn (menu state 0x106); when no overlay is on, the menu is
 *      closed again.
 *   7. Adaptive-Sync: when it changed, mute the sound, switch the picture output off and apply the DSC setting;
 *      switching it on also clears the blur reduction mode.
 *   8. Copy the settings into the picture mode slot, request a save and reply "5600+\r".
 */
int uart_cmd_set_picture_settings(unsigned char port)
{
    unsigned char color_temp;
    unsigned char old_adaptive_sync;
    unsigned int frame_byte;
    unsigned short value;

    old_adaptive_sync = user_settings.gaming_flags.bits.adaptive_sync;

    /* Phase 1: Color Temperature. A skipped byte leaves color_temp at 0 or 0xFF, so the gains are skipped too. */
    frame_byte = rx_byte(port, FRAME_COLOR_TEMPERATURE);
    color_temp = frame_byte;
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        color_temp = value;
        if (color_temp > COLOR_TEMP_MAX)
            return UART_CMD_REFUSED;
        user_settings.color_temperature = value;
    }
    if (color_temp == COLOR_TEMP_CUSTOMIZATION) {
        frame_byte = rx_byte(port, FRAME_RED_GAIN);
        if (frame_byte_is_set(frame_byte)) {
            value = frame_byte - VALUE_CHAR_BASE;
            if ((unsigned char)value > LEVEL_MAX)
                return UART_CMD_REFUSED;
            user_settings.red_gain = value;
        }
        frame_byte = rx_byte(port, FRAME_GREEN_GAIN);
        if (frame_byte_is_set(frame_byte)) {
            value = frame_byte - VALUE_CHAR_BASE;
            if ((unsigned char)value > LEVEL_MAX)
                return UART_CMD_REFUSED;
            user_settings.green_gain = value;
        }
        frame_byte = rx_byte(port, FRAME_BLUE_GAIN);
        if (frame_byte_is_set(frame_byte)) {
            value = frame_byte - VALUE_CHAR_BASE;
            if ((unsigned char)value > LEVEL_MAX)
                return UART_CMD_REFUSED;
            user_settings.blue_gain = value;
        }
    }
    /* Low Blue Light. */
    frame_byte = rx_byte(port, FRAME_LOW_BLUE_LIGHT);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > ON_OFF_MAX)
            return UART_CMD_REFUSED;
        user_settings.professional_flags.low_blue_light = (unsigned char)value;
        if (user_settings.professional_flags.low_blue_light)
            user_settings.byte_0x178 = 0;
    }
    /* Contrast. */
    frame_byte = rx_byte(port, FRAME_CONTRAST);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > LEVEL_MAX)
            return UART_CMD_REFUSED;
        user_settings.contrast = value;
    }
    pq_user_apply_color_gain();
    pq_user_apply_color_settings();

    /* Phase 2: Image Enhancement, then Sharpness (taken without a limit). */
    frame_byte = rx_byte(port, FRAME_IMAGE_ENHANCEMENT);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > IMAGE_ENHANCEMENT_MAX)
            return UART_CMD_REFUSED;
        user_settings.image_enhancement = (unsigned char)value;
        sys_user_apply_channel0_scaling_mode();
        sys_user_apply_channel1_scaling_mode();
    }
    frame_byte = rx_byte(port, FRAME_SHARPNESS);
    if (frame_byte_is_set(frame_byte)) {
        user_settings.sharpness = frame_byte - VALUE_CHAR_BASE;
        pq_user_apply_sharpness();
    }

    /* Phase 3: automatic level; it cannot stay on together with the blur reduction mode. */
    frame_byte = rx_byte(port, FRAME_AUTO_LEVEL);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > ON_OFF_MAX)
            return UART_CMD_REFUSED;
        user_settings.professional_flags.auto_level = (unsigned char)value;
        if (user_settings.professional_flags.auto_level && user_settings.blur_free_mode != 0) {
            user_settings.blur_free_mode = 0;
            sys_user_clear_second_picture_request();
        }
    }
    sys_user_apply_auto_level();

    /* Phase 4: blur reduction mode. */
    frame_byte = rx_byte(port, FRAME_BLUR_FREE);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > ON_OFF_MAX)
            return UART_CMD_REFUSED;
        if (user_settings.blur_free_mode != (unsigned char)value) {
            user_settings.blur_free_mode = (unsigned char)value;
            /* A changed mode switches Optix Scope off ... */
            if (user_settings.optix_scope != 0) {
                user_settings.optix_scope = 0;
                sys_user_apply_second_picture_enable(0);
            }
            /* ... and, when the mode is now on, the automatic level. */
            if (user_settings.professional_flags.auto_level && user_settings.blur_free_mode != 0) {
                user_settings.professional_flags.auto_level = 0;
                sys_user_apply_auto_level();
            }
            sys_user_clear_second_picture_request();
        }
        /* With the mode on: PIP/PBP off, both channels restarted, then the PIP/PBP mode applied. */
        if (user_settings.pip_pbp_mode != 0 && user_settings.blur_free_mode != 0) {
            user_settings.pip_pbp_mode = 0;
            panel_user_set_output_on(0);
            sys_api_restart_channel_at_level(0, 1);
            sys_api_restart_channel_at_level(1, 1);
            UserSetPIPMode();
        }
        /* With the mode on: Screen Size 4, 5 or 6 goes back to 0 and the input window of port 0 is recomputed. */
        if (sys_is_mode_4_to_6() == 1 && user_settings.blur_free_mode != 0) {
            panel_user_set_output_on(0);
            user_settings.screen_size = 0;
            pq_update_input_window(0);
        }
    }

    /* Phase 5: response time. */
    frame_byte = rx_byte(port, FRAME_RESPONSE_TIME);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > RESPONSE_TIME_MAX)
            return UART_CMD_REFUSED;
        if ((user_settings.blur_free_mode == 0 || sys_user_get_picture_state() != 0) && user_settings.pip_pbp_mode == 0
            && user_settings.response_time != (unsigned char)value) {
            user_settings.response_time = value;
            pq_user_reset_response_level();
        }
    }
    /* Settings byte +0x140; the routine called after it is empty. */
    frame_byte = rx_byte(port, FRAME_BYTE_0x140);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > BYTE_0x140_MAX)
            return UART_CMD_REFUSED;
        user_settings.byte_0x140 = value;
        sys_poll_events_stub_copy();
    }
    /* Brightness: the value is checked in any case but stored only while neither the blur reduction mode nor the
       automatic level is on. */
    frame_byte = rx_byte(port, FRAME_BRIGHTNESS);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > LEVEL_MAX)
            return UART_CMD_REFUSED;
        if (user_settings.blur_free_mode == 0 && !user_settings.professional_flags.auto_level) {
            user_settings.brightness = value;
            sys_user_apply_brightness();
        }
    }

    /* Phase 6: the screen overlays. */
    frame_byte = rx_byte(port, FRAME_REFRESH_RATE);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > ON_OFF_MAX)
            return UART_CMD_REFUSED;
        user_settings.gaming_flags.bits.refresh_rate_display = (unsigned char)value;
    }
    frame_byte = rx_byte(port, FRAME_REFRESH_RATE_LOC);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > LOCATION_MAX)
            return UART_CMD_REFUSED;
        user_settings.refresh_rate_location = value;
    }
    /* Alarm Clock: the chosen timer's minutes and seconds become the running time. With choice 0 (off) bytes
       +0x197 and +0x19B are copied. */
    frame_byte = rx_byte(port, FRAME_ALARM_CLOCK);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > ALARM_CHOICE_MAX)
            return UART_CMD_REFUSED;
        user_settings.alarm_clock = value;
        user_settings.alarm_minutes = user_settings.alarm_minutes_by_choice[(unsigned char)value];
        user_settings.alarm_seconds = user_settings.alarm_seconds_by_choice[(unsigned char)value];
        app_state_record.alarm_running = 1;
    }
    frame_byte = rx_byte(port, FRAME_ALARM_CLOCK_LOC);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > LOCATION_MAX)
            return UART_CMD_REFUSED;
        user_settings.alarm_clock_location = value;
    }
    frame_byte = rx_byte(port, FRAME_CROSSHAIR_ICON);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > CROSSHAIR_ICON_MAX)
            return UART_CMD_REFUSED;
        user_settings.crosshair_icon = value;
    }
    /* With sleep state 0: close the menu and draw the screen overlays. */
    if (app_state_record.sleep_state == 0) {
        osd_close_menu();
        osd_open_menu_state_0x106();
    }
    /* No overlay is on: close the menu again. */
    if (user_settings.crosshair_icon == 0 && !(user_settings.gaming_flags.word & GAMING_FLAG_REFRESH_RATE) && user_settings.alarm_clock == 0
        && !(user_settings.settings_page_flags & SETTINGS_INFO_ON_SCREEN) && app_state_record.sleep_state == 0)
        osd_close_menu();

    /* Phase 7: Adaptive-Sync. */
    frame_byte = rx_byte(port, FRAME_ADAPTIVE_SYNC);
    if (frame_byte_is_set(frame_byte)) {
        value = frame_byte - VALUE_CHAR_BASE;
        if ((unsigned char)value > ON_OFF_MAX)
            return UART_CMD_REFUSED;
        user_settings.gaming_flags.bits.adaptive_sync = (unsigned char)value;
    }
    if ((user_settings.gaming_flags.bits.adaptive_sync ^ old_adaptive_sync) & 1) {
        audio_mute_outputs();
        panel_user_set_output_on(0);
        sys_user_apply_adaptive_sync_setting();
        if ((user_settings.gaming_flags.word & GAMING_FLAG_ADAPTIVE_SYNC) && user_settings.blur_free_mode != 0)
            user_settings.blur_free_mode = 0;
    }

    /* Phase 8. */
    sys_user_save_mode_slot();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
