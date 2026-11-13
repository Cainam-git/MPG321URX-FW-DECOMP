/* sys_user_factory_reset  (FUN_a00dc3dc)
 *
 * Reload all user settings from their defaults and apply every one of them.
 * Name basis: proven - 0x1FC-byte settings record at 0xA802D290 from the defaults table, a few fields kept
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dc3dc @ 0xa00dc3dc-0xa00dcd38 (599 words), flags -mcpu=v8 -O3 -g.
 * Source form: the same-file routines it calls are written here as static copies of their matched bodies, so
 * that they are inlined as in the firmware: panel_user_set_output_on(0) at the start (its folded 'mode == 1'
 * early return is why the high part of the user_settings address is formed twice in the entry block,
 * 'mov %l0,%l7' at 0xa00dc3f4), sys_user_apply_pip_sources(1), pq_user_reset_response_level in UserSetProMode's
 * form, osd_user_apply_transparency, osd_user_apply_menu_timeout, sys_user_apply_config_bit31,
 * sys_user_rebuild_window_channel1, pq_user_set_custom_blue, gpio_user_set_port2_bit2, gpio_user_set_led_by_state,
 * UserSetAuroraLEDBarBrightness, gpio_user_set_port7_bit1 and sys_user_apply_mode_byte. Record accesses are
 * written on user_settings itself; transparency and custom blue reach it through a local pointer and keep the
 * limited value in an unsigned short.
 * main_port_flagged() is used three times: before the grid block enable (if/else chain), inside
 * sys_user_apply_auto_level as 'if (main_port_flagged()) mode = 0;' (0xa00dc624..0xa00dc654 and its second copy
 * 0xa00dca78..0xa00dca94; sys_user_apply_auto_level compiles to its own bytes in this form as well) and at
 * 0xa00dc928 before the SECOND_TABLE_FLAG test. With the sys_user_apply_auto_level test written as five
 * 'mode = 0' arms the out-of-line blocks at 0xa00dcbe4..0xa00dcc6c (sys_user_save_mode_slot, SYSAPI_WriteEEPROM,
 * UserSwitchEDID, the FACTORY_MODE_MARKER_CLEARED store, was_screen_size_3 = 1) come out in a different order.
 */

/* Two neighbouring bytes of the settings record, kept together across the reset. */
struct byte_pair {
    unsigned char first;
    unsigned char second;
};
/* Settings word +0; the record is stored with the most significant bit first. */
struct settings_word0_bits {
    unsigned int hi : 22;
    unsigned int bit9 : 1;                      /* bit 9: applied to configuration bit 31 */
    unsigned int lo : 9;
};
/* Settings word +0xA8, the gaming flags. */
struct gaming_flags_bits {
    unsigned int p0 : 20;
    unsigned int pro_selected : 1;              /* bit 11: Pro (1) / Game (0) mode */
    unsigned int pro_selected_copy_1 : 1;       /* bit 10 */
    unsigned int pro_selected_copy_2 : 1;       /* bit 9 */
    unsigned int pro_selected_copy_3 : 1;       /* bit 8 */
    unsigned int p1 : 8;
};
/* Settings word +0x11C, the professional flags. */
struct professional_flags_bits {
    unsigned int auto_level : 1;                /* bit 31: automatic level */
    unsigned int rest : 31;
};
/* Settings word +0x1D4. */
struct word_0x1d4_bits {
    unsigned int p0 : 25;
    _Bool cec_pwm_adjust : 1;                   /* bit 6: set when the factory menu item CEC PWM Adjust is opened */
    unsigned int p1 : 6;
};
/* The fields of the user settings record used here (docs/RECORDS.md). */
struct user_settings_record {
    struct settings_word0_bits word0;           /* +0x00 */
    unsigned char pad004[8 - 4];
    unsigned char language;                     /* +0x08: the menu language */
    unsigned char brightness;                   /* +0x09: Brightness */
    unsigned char pad00a[0xc - 0xa];
    unsigned char osd_timeout;                  /* +0x0C: OSD Time out */
    unsigned char pad00d[0xf - 0xd];
    unsigned char transparency;                 /* +0x0F: menu Transparency */
    unsigned char pad010[0x12 - 0x10];
    unsigned char red_gain;                     /* +0x12: the custom gains, 0..100 */
    unsigned char green_gain;                   /* +0x13 */
    unsigned char blue_gain;                    /* +0x14 */
    unsigned char pad015[0x19 - 0x15];
    unsigned char response_time;                /* +0x19: the response time level */
    unsigned char pad01a[0x1e - 0x1a];
    unsigned char input_source;                 /* +0x1E: the selected Input Source */
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP/PBP mode, 0 = off */
    unsigned char second_source;                /* +0x20: source of channel 1 */
    unsigned char byte_0x21;                    /* +0x21: source of channel 2 */
    unsigned char byte_0x22;                    /* +0x22: source of channel 3 */
    unsigned char pad023[0x34 - 0x23];
    struct {
        unsigned short p : 12;
        unsigned short level : 4;               /* bits 0..3: Image Enhancement level */
    } image_enhancement;                        /* +0x34 */
    unsigned char pad036[0x4a - 0x36];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char pad04b[0x8f - 0x4b];
    unsigned char byte_0x8f;                    /* +0x8F: holds the limited response time while it is switched off */
    unsigned char pad090[0xa8 - 0x90];
    union {
        unsigned int word;
        struct gaming_flags_bits bits;
    } gaming_flags;                             /* +0xA8 */
    unsigned char byte_0xac;                    /* +0xAC: top byte of the settings page flags word */
    unsigned char pad0ad[0xb0 - 0xad];
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned char pad0b4[0x11c - 0xb4];
    struct professional_flags_bits professional_flags;  /* +0x11C */
    unsigned char pad120[0x174 - 0x120];
    unsigned int word_0x174;                    /* +0x174: bit 15 = AI Vision */
    unsigned char pad178[0x181 - 0x178];
    unsigned char pro_mode;                     /* +0x181: the Professional mode */
    unsigned char game_mode;                    /* +0x182: the Game Mode */
    unsigned char pad183[0x187 - 0x183];
    unsigned char pro_mode_copy_3;              /* +0x187 */
    unsigned char game_mode_copy_3;             /* +0x188 */
    unsigned char pad189[0x1a0 - 0x189];
    unsigned char alarm_clock;                  /* +0x1A0: the Alarm Clock timer choice */
    unsigned char pad1a1[0x1a4 - 0x1a1];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
    unsigned char pad1a5[0x1d4 - 0x1a5];
    union {
        unsigned int word;
        struct word_0x1d4_bits bits;
        unsigned char bytes[4];                 /* bytes[1] = +0x1D5 burn_in_flag, bytes[2] = +0x1D6 */
    } word_0x1d4;                               /* +0x1D4 */
    unsigned char byte_0x1d8;                   /* +0x1D8: the brightness loaded by CEC PWM Adjust */
    unsigned char pad1d9;
    unsigned short brightness_knee;             /* +0x1DA: the knee of the brightness mapping line */
    unsigned char pad1dc[0x1e2 - 0x1dc];
    struct byte_pair bytes_0x1e2;               /* +0x1E2, +0x1E3 */
    unsigned char pad1e4[2];
    struct byte_pair bytes_0x1e6;               /* +0x1E6, +0x1E7 */
    unsigned char pad1e8[0x1ec - 0x1e8];
    unsigned int boundary_detection;            /* +0x1EC as a word: bit 7 = Type C PD Charge */
    unsigned char pad1f0[0x1f4 - 0x1f0];
    union {
        unsigned int word;                      /* bit 31 = DSC switch, bit 30 = the mode byte */
        unsigned short halves[2];               /* halves[1] = +0x1F6, the factory-mode marker */
    } word_0x1f4;                               /* +0x1F4 */
};
/* The factory record (0x1C bytes). */
struct factory_record_fields {
    unsigned char pad[0x14];
    unsigned char byte_0x14;                    /* +0x14 */
};
/* The application state record. */
struct app_state_fields {
    unsigned char pad[9];
    unsigned char alarm_slot_index;             /* +0x09: the alarm clock timer slot (0..4) */
    unsigned short half_0xa;                    /* +0x0A: bit 7 = SECOND_TABLE_FLAG */
};
extern struct user_settings_record user_settings;
extern struct factory_record_fields factory_record;
extern struct app_state_fields app_state_record;
extern unsigned char sys_led_bar_tx_frame[11];
extern const unsigned char user_settings_defaults[];

#define USER_SETTINGS_SIZE          0x1fc
#define GAMING_FLAG_LED_STATE       0x20        /* bit 5: tested by gpio_user_set_led_by_state */
#define GAMING_FLAG_PORT2_PIN2      0x40        /* bit 6: level of pin 2 of GPIO port 2 */
#define GAMING_FLAG_ADAPTIVE_SYNC_SHIFT 7       /* bit 7: Adaptive-Sync */
#define GAMING_FLAG_PRO_MODE        0x800       /* bit 11: Pro (1) / Game (0) mode */
#define GAMING_FLAG_BIT14           0x4000      /* bit 14: mute the sound before a source is selected */
#define WORD_0x1D4_CEC_PWM_ADJUST   0x40        /* bit 6 of word +0x1D4 */
#define WORD_0x1F4_MODE_BYTE        0x40000000  /* bit 30 of word +0x1F4 */
#define AI_VISION_BIT               0x8000      /* word +0x174 bit 15 */
#define SECOND_TABLE_FLAG           0x80        /* app_state_record halfword +0xA bit 7 (UserSetProMode) */
#define FACTORY_MODE_MARKER         0x55aa      /* settings halfword +0x1F6 */
#define FACTORY_MODE_MARKER_CLEARED 0xbb99
#define BURN_IN_FLAG                1           /* index of burn_in_flag in word_0x1d4.bytes */
#define BYTE_0x1D6                  2           /* index of +0x1D6 in word_0x1d4.bytes */
#define SCREEN_SIZE_3               3           /* the Screen Size value with an EDID variant of its own
                                                   (UserSwitchEDID picks variant 6 for it) */
#define TRANSPARENCY_MAX            5
#define RGB_GAIN_MAX                100
#define RGB_RED                     0           /* channel numbers of pq_api_set_rgb_gain */
#define RGB_GREEN                   1
#define RGB_BLUE                    2
#define RESPONSE_TIME_MAX           3
#define RESPONSE_LEVEL_OFF          5           /* pq_api_set_response_level(5) switches the function off */
#define CHANNEL_ALL                 4           /* sys_api_set_channel_timeout: all four channels */
#define DISPLAY_DELAY_TICKS         1000
#define EEPROM_AREA_SETTINGS        0x30
#define FACTORY_RECORD_OFFSET       0x2e0
#define FACTORY_RECORD_SIZE         0x1c
#define STORE_DEVICE_SETTINGS       1           /* nvram_api_store_by_selector(1): write the device settings */
#define LED_BAR_UART_PORT           2           /* the 8051 serial port the LED bar frames go out on */
#define MAIN_CHANNEL                0
#define SECOND_CHANNEL              1

extern void *memcpy(void *, const void *, unsigned int);
extern void gpio_set_aux_bit0_low(void);
extern void gpio_set_aux_bit0_high(void);
extern void oled_controller_disable(void);
extern void SYSAPI_PanelOnOffControl(int, int);
extern void audio_api_set_mute(unsigned char);
extern void sys_user_save_mode_slot(void);
extern void sys_user_apply_brightness(void);
extern void pq_user_apply_color_gain(void);
extern void pq_user_apply_gamma(void);
extern void pq_api_set_rgb_gain(int, unsigned char);
extern void pq_user_apply_color_temperature(void);
extern void pq_user_apply_color_settings(void);
extern void osd_api_set_level_all_windows(unsigned char);
extern void osd_set_seconds_countdown(unsigned short);
extern void sys_user_apply_dimming_mode(void);
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);
extern void ldc_hw_api_set_enable_mode(unsigned char);
extern void pq_api_set_auto_level_mode(unsigned char);
extern void pq_update_input_window(int);
extern void sys_user_reset_display_path(void);
extern void sys_api_set_config_bit31(unsigned char);
extern void sys_api_select_channel_source(int, unsigned char);
extern void UserSetPIPMode(void);
extern void APP_ConfigDispSize(int, void *);
extern void input_api_set_capture_window(int, void *);
extern void sys_api_rebuild_channel_window(unsigned char);
extern void UserSwitchEDID(int, int);
extern void sys_api_set_channel_timeout(int, int, int);
extern void sys_user_apply_startup_settings(void);
extern void sys_api_restart_channel_at_level(int, int);
extern void gpio_set_port2_bit2_high(void);
extern void gpio_set_port2_bit2_low(void);
extern void sys_poll_events_stub_copy9(void);
extern void sys_poll_events_stub_copy10(void);
extern unsigned char oled_power_get_state(void);
extern unsigned char oled_power_get_step(void);
extern int dbg_printf(const char *fmt, ...);
extern void uart_api_send_bytes(unsigned char, int, unsigned char *);
extern void ipc_8051_tx_queue_flush(void);
extern int pq_select_rate_mode();
extern int input_api_get_timing_field();
extern void pq_api_set_response_level(int);
extern void sys_api_set_channel_scaling_mode(unsigned char, unsigned char);
extern void sys_api_set_channel_source_enable(unsigned char, unsigned char);
extern void sys_api_enable_channel_port(int, int);
extern void gpio_set_port7_bit1_high(void);
extern void gpio_set_port7_bit1_low(void);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void sys_set_mode_byte_c9f8(unsigned char);
extern void gpio_set_port4_bit7_high_if_allowed(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void UserSetProMode(void);
extern void UserSetGameMode(void);
extern void nvram_set_device_setting(int, int);
extern void nvram_api_store_by_selector(int);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);

/* Copies of routines that have their own copies in the firmware; written here so that they are inlined. */

/* 1: gpio_set_aux_bit0_high (GPIO port number 0xFF: no pin changes). Else: gpio_set_aux_bit0_low, the OLED
   controller off, the panel off. */
static void panel_user_set_output_on(unsigned char mode)
{
    if (mode == 1) {
        gpio_set_aux_bit0_high();
        return;
    }
    gpio_set_aux_bit0_low();
    oled_controller_disable();
    SYSAPI_PanelOnOffControl(0, 0);
}

/* Give channel 1, 2 or 3 its source from the settings; with gaming flag bit 14 set, the sound is muted first. */
static void sys_user_apply_pip_sources(unsigned char channel)
{
    if (user_settings.gaming_flags.word & GAMING_FLAG_BIT14)
        audio_api_set_mute(1);
    switch (channel) {
    case 1:
        sys_api_select_channel_source(1, user_settings.second_source);
        break;
    case 2:
        sys_api_select_channel_source(2, user_settings.byte_0x21);
        break;
    case 3:
        sys_api_select_channel_source(3, user_settings.byte_0x22);
        break;
    }
}

/* Limit the menu transparency to 5 and apply it to both menu layers and their windows. */
static void osd_user_apply_transparency(void)
{
    struct user_settings_record *settings = &user_settings;
    unsigned short level = settings->transparency;
    if (level > TRANSPARENCY_MAX)
        level = TRANSPARENCY_MAX;
    settings->transparency = level;
    osd_api_set_level_all_windows(level);
}

/* Start the menu's one-second countdown from the OSD Time out setting. */
static void osd_user_apply_menu_timeout(void)
{
    osd_set_seconds_countdown(user_settings.osd_timeout);
}

/* Settings word 0 bit 9 becomes configuration bit 31. */
static void sys_user_apply_config_bit31(void)
{
    sys_api_set_config_bit31(user_settings.word0.bit9);
}

/* Compute the display window of channel 1, hand it to the channel as its capture window and rebuild it. */
static void sys_user_rebuild_window_channel1(void)
{
    unsigned long long window[2];
    unsigned long long capture_window[2];
    APP_ConfigDispSize(1, window);
    capture_window[0] = window[0];
    capture_window[1] = window[1];
    input_api_set_capture_window(1, capture_window);
    sys_api_rebuild_channel_window(1);
}

/* Limit the custom blue gain to 100, apply it, then the colour temperature again. */
static void pq_user_set_custom_blue(void)
{
    struct user_settings_record *settings = &user_settings;
    unsigned short gain = settings->blue_gain;

    if (gain > RGB_GAIN_MAX)
        gain = RGB_GAIN_MAX;
    settings->blue_gain = gain;
    pq_api_set_rgb_gain(RGB_BLUE, gain);
    pq_user_apply_color_temperature();
}

/* Pin 2 of GPIO port 2 follows gaming flag bit 6. */
static void gpio_user_set_port2_bit2(void)
{
    if ((user_settings.gaming_flags.word & GAMING_FLAG_PORT2_PIN2) != 0) {
        gpio_set_port2_bit2_high();
        return;
    }
    gpio_set_port2_bit2_low();
}

/* Calls one of two routines by the OLED power state, its step and gaming flag bit 5. Both routines are empty
   in this firmware. */
static void gpio_user_set_led_by_state(void)
{
    if (oled_power_get_state() != 0) {
        sys_poll_events_stub_copy9();
        return;
    }
    if (oled_power_get_step() != 0) {
        sys_poll_events_stub_copy9();
        return;
    }
    if ((user_settings.gaming_flags.word & GAMING_FLAG_LED_STATE) != 0) {
        sys_poll_events_stub_copy9();
        return;
    }
    sys_poll_events_stub_copy10();
}

/* Send the LED light bar its brightness: value = level * 20 + 20, sent as the 11 characters "5b00740", three
   decimal digits of value and a carriage return. */
static void UserSetAuroraLEDBarBrightness(unsigned char level)
{
    unsigned char value = level * 20 + 20;

    dbg_printf("UserSetAuroraLEDBarBrightness %d\r\n", value);
    {
        unsigned char hundreds, rest, tens, ones;
        hundreds = value / 100;
        rest = value - hundreds * 100;
        tens = rest / 10;
        ones = rest - tens * 10;
        sys_led_bar_tx_frame[0] = '5';
        sys_led_bar_tx_frame[1] = 'b';
        sys_led_bar_tx_frame[2] = '0';
        sys_led_bar_tx_frame[3] = '0';
        sys_led_bar_tx_frame[4] = '7';
        sys_led_bar_tx_frame[5] = '4';
        sys_led_bar_tx_frame[6] = '0';
        sys_led_bar_tx_frame[7] = hundreds + '0';
        sys_led_bar_tx_frame[8] = tens + '0';
        sys_led_bar_tx_frame[9] = ones + '0';
        sys_led_bar_tx_frame[10] = '\r';
    }
    uart_api_send_bytes(LED_BAR_UART_PORT, 11, sys_led_bar_tx_frame);
    ipc_8051_tx_queue_flush();
}

/* Pin 1 of GPIO port 7 goes high only with the Type C PD Charge bit set and force_low 0. */
static void gpio_user_set_port7_bit1(unsigned char force_low)
{
    if (((user_settings.boundary_detection >> 7 ^ 1) & 1) != 0 || force_low != '\0') {
        gpio_set_port7_bit1_low();
        return;
    }
    gpio_set_port7_bit1_high();
}

/* The mode byte at 0xA802C9F8 follows bit 30 of settings word +0x1F4. */
static void sys_user_apply_mode_byte(void)
{
    if ((user_settings.word_0x1f4.word & WORD_0x1F4_MODE_BYTE) != 0) {
        sys_set_mode_byte_c9f8(1);
        return;
    }
    sys_set_mode_byte_c9f8(0);
}

/* 1 when the port of the main channel has flag 9 set, or flag 6 while the mailbox status field reads 1..4
   (4 also stands for an out-of-range field). The same test as in UserSetProMode. */
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

/* Apply the automatic level setting; it is forced off while main_port_flagged() is 1. With the setting off,
   the brightness is applied again. */
static void sys_user_apply_auto_level(void)
{
    unsigned char mode = user_settings.professional_flags.auto_level;
    unsigned char setting = mode;

    user_settings.professional_flags.auto_level = setting;
    switch (setting) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    }
    if (main_port_flagged())
        mode = 0;
    pq_api_set_auto_level_mode(mode & 3);
    if (!user_settings.professional_flags.auto_level)
        sys_user_apply_brightness();
}

/* 1 when pq_select_rate_mode gives a non-zero mode for the main channel's refresh rate (timing field 1,
   tenths of Hz, passed in Hz). The two parameters are not used. */
static unsigned int input_user_has_rate_mode(unsigned int unused_1, unsigned int unused_2)
{
    unsigned int refresh_rate;

    refresh_rate = input_api_get_timing_field(0, 1);
    return (pq_select_rate_mode((unsigned short)refresh_rate / 10) != 0);
}

/* Switch the response level off once, leaving the response time setting as it was (limited to 3). Skipped
   while a blur reduction setting is on and input_user_has_rate_mode() is 1. */
static void pq_user_reset_response_level(void)
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

/*
 * Reset the user settings record to the defaults in ROM and apply every setting again.
 *
 * Callers: the menu Reset (osd_run_settings_reset), the factory menu (osd_factory_activate_item), the PC-tool
 * commands (uart_cmd_reset_settings, uart_cmd_dispatch_set), DDC/CI (ddc_handle_request, ddc_apply_maker_vcp_set,
 * ddc_tool_run_factory_reset), power_enter_app_state and App_CoolInitialize.
 *
 * Phases, in order:
 *   1. Output off: the panel output is switched off (panel_user_set_output_on(0)) and the sound muted.
 *   2. Keep: the factory-mode marker (+0x1F6) and the Adaptive-Sync bit are noted for later; the input
 *      source, the language, byte +0x1D8, the brightness knee, bit 6 of word +0x1D4 and the bytes
 *      +0x1E2/+0x1E3 and +0x1E6/+0x1E7 survive the copy; whether Screen Size was 3 is noted.
 *   3. Copy the 0x1FC-byte defaults over the record and put the kept fields back. With bit 6 of word +0x1D4
 *      set (CEC PWM Adjust), the brightness becomes byte +0x1D8 and sys_user_save_mode_slot copies the
 *      picture settings into a mode slot.
 *   4. Picture: the alarm clock slot of app_state_record takes the Alarm Clock setting; brightness, colour
 *      gain, gamma, the three custom gains (each limited to 100), colour settings, menu transparency and
 *      time-out, dimming mode; the grid block enable (0 while main_port_flagged(), 1 with AI Vision on,
 *      else 0), each followed by the dimming mode again; the automatic level.
 *   5. Display path: the input window of port 0, a restart of the display path, configuration bit 31, the
 *      source of channel 1, the PIP/PBP mode and the window of channel 1. When Screen Size was 3, the EDID
 *      is chosen again and all four channels get a display delay of 1000 ticks. Then the start-up settings
 *      and a restart of channel 0 at level 1.
 *   6. Other outputs: pin 2 of GPIO port 2, the LED routine, the LED bar brightness (byte +0xAC), the
 *      response level reset, the scaling mode of channels 0 and 1 from the Image Enhancement level. Optix
 *      Scope is switched off when it and blur reduction are both on, and with PIP/PBP off channel 1's source
 *      and port too. Pin 1 of GPIO port 7.
 *   7. When the Adaptive-Sync bit changed, the DSC setting is applied again.
 *   8. While main_port_flagged() is 1 and SECOND_TABLE_FLAG is clear, the Pro/Game choice and both mode
 *      bytes come back from copy 3 (the copy UserSetProMode / UserSetGameMode keep in that case). Then the
 *      mode byte, the two conditional pins of GPIO port 4, and the Game Mode or Pro Mode is applied.
 *   9. Clean-up: the burn-in flag (+0x1D5) and byte +0x1D6 are cleared; when the record holds
 *      FACTORY_MODE_MARKER at this point (the field is not kept across the copy), it becomes
 *      FACTORY_MODE_MARKER_CLEARED. When the marker was set on entry, device settings 6 and
 *      7 become 0 and the device settings record is stored. A non-zero factory record byte +0x14 is cleared
 *      and the factory record written to the EEPROM. Last, channels 0 and 1 are restarted at level 1.
 */
void sys_user_factory_reset(void)
{
    unsigned short marker_on_entry = user_settings.word_0x1f4.halves[1];
    unsigned char adaptive_sync_on_entry, kept_cec_pwm_adjust, was_screen_size_3;
    struct byte_pair kept_0x1e2, kept_0x1e6;
    unsigned char kept_input_source, kept_language, kept_byte_0x1d8;
    unsigned short kept_brightness_knee;
    unsigned short gain;

    /* 1. Output off. */
    panel_user_set_output_on(0);
    audio_api_set_mute(1);

    /* 2. Note the fields that survive the reset. */
    adaptive_sync_on_entry = (user_settings.gaming_flags.word >> GAMING_FLAG_ADAPTIVE_SYNC_SHIFT) & 1;
    kept_cec_pwm_adjust = (user_settings.word_0x1d4.word >> 6) & 1;
    kept_0x1e2.first = user_settings.bytes_0x1e2.first;
    kept_0x1e2.second = user_settings.bytes_0x1e2.second;
    kept_0x1e6.first = user_settings.bytes_0x1e6.first;
    kept_0x1e6.second = user_settings.bytes_0x1e6.second;
    was_screen_size_3 = 0;
    kept_input_source = user_settings.input_source;
    kept_language = user_settings.language;
    kept_byte_0x1d8 = user_settings.byte_0x1d8;
    kept_brightness_knee = user_settings.brightness_knee;
    if (user_settings.screen_size == SCREEN_SIZE_3)
        was_screen_size_3 = 1;

    /* 3. Defaults, then the kept fields back. */
    memcpy(&user_settings, user_settings_defaults, USER_SETTINGS_SIZE);
    user_settings.input_source = kept_input_source;
    user_settings.language = kept_language;
    user_settings.word_0x1d4.bits.cec_pwm_adjust = kept_cec_pwm_adjust;
    user_settings.byte_0x1d8 = kept_byte_0x1d8;
    user_settings.brightness_knee = kept_brightness_knee;
    if (user_settings.word_0x1d4.word & WORD_0x1D4_CEC_PWM_ADJUST) {
        user_settings.brightness = kept_byte_0x1d8;
        sys_user_save_mode_slot();
    }
    user_settings.bytes_0x1e2.first = kept_0x1e2.first;
    user_settings.bytes_0x1e2.second = kept_0x1e2.second;
    user_settings.bytes_0x1e6.first = kept_0x1e6.first;
    user_settings.bytes_0x1e6.second = kept_0x1e6.second;

    /* 4. Picture settings. */
    app_state_record.alarm_slot_index = user_settings.alarm_clock;
    sys_user_apply_brightness();
    pq_user_apply_color_gain();
    pq_user_apply_gamma();
    gain = user_settings.red_gain;
    if (gain > RGB_GAIN_MAX)
        gain = RGB_GAIN_MAX;
    user_settings.red_gain = gain;
    pq_api_set_rgb_gain(RGB_RED, gain);
    gain = user_settings.green_gain;
    if (gain > RGB_GAIN_MAX)
        gain = RGB_GAIN_MAX;
    user_settings.green_gain = gain;
    pq_api_set_rgb_gain(RGB_GREEN, gain);
    pq_user_set_custom_blue();
    pq_user_apply_color_settings();
    osd_user_apply_transparency();
    osd_user_apply_menu_timeout();
    sys_user_apply_dimming_mode();
    /* Grid block enable. */
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
    sys_user_apply_auto_level();

    /* 5. Display path. */
    pq_update_input_window(0);
    sys_user_reset_display_path();
    sys_user_apply_config_bit31();
    sys_user_apply_pip_sources(1);
    UserSetPIPMode();
    sys_user_rebuild_window_channel1();
    if (was_screen_size_3) {
        /* Screen Size 3 had an EDID variant of its own: choose the EDID again for the reset settings. */
        UserSwitchEDID(2, 0);
        sys_api_set_channel_timeout(CHANNEL_ALL, 1, DISPLAY_DELAY_TICKS);
    }
    sys_user_apply_startup_settings();
    sys_api_restart_channel_at_level(MAIN_CHANNEL, 1);

    /* 6. Other outputs. */
    gpio_user_set_port2_bit2();
    gpio_user_set_led_by_state();
    UserSetAuroraLEDBarBrightness(user_settings.byte_0xac);
    pq_user_reset_response_level();
    sys_api_set_channel_scaling_mode(MAIN_CHANNEL, user_settings.image_enhancement.level);
    sys_api_set_channel_scaling_mode(SECOND_CHANNEL, user_settings.image_enhancement.level);
    if (user_settings.optix_scope != 0 && user_settings.blur_free_mode != 0) {
        user_settings.optix_scope = 0;
        if (user_settings.pip_pbp_mode == 0) {
            sys_api_set_channel_source_enable(SECOND_CHANNEL, 0);
            sys_api_enable_channel_port(SECOND_CHANNEL, 0);
        }
    }
    gpio_user_set_port7_bit1(0);

    /* 7. Adaptive-Sync changed: apply the DSC setting again. */
    if (adaptive_sync_on_entry != ((user_settings.gaming_flags.word >> GAMING_FLAG_ADAPTIVE_SYNC_SHIFT) & 1))
        sys_user_apply_adaptive_sync_setting();

    /* 8. Picture mode. */
    if (main_port_flagged() && !(app_state_record.half_0xa & SECOND_TABLE_FLAG)) {
        user_settings.gaming_flags.bits.pro_selected = user_settings.gaming_flags.bits.pro_selected_copy_3;
        user_settings.game_mode = user_settings.game_mode_copy_3;
        user_settings.pro_mode = user_settings.pro_mode_copy_3;
    }
    sys_user_apply_mode_byte();
    gpio_set_port4_bit7_high_if_allowed();
    gpio_set_port4_bit4_low_if_allowed();
    if (!(user_settings.gaming_flags.word & GAMING_FLAG_PRO_MODE))
        UserSetGameMode();
    else
        UserSetProMode();

    /* 9. Clean-up. */
    if (user_settings.word_0x1d4.bytes[BURN_IN_FLAG])
        user_settings.word_0x1d4.bytes[BURN_IN_FLAG] = 0;
    if (user_settings.word_0x1f4.halves[1] == FACTORY_MODE_MARKER)
        user_settings.word_0x1f4.halves[1] = FACTORY_MODE_MARKER_CLEARED;
    if (marker_on_entry == FACTORY_MODE_MARKER) {
        nvram_set_device_setting(6, 0);
        nvram_set_device_setting(7, 0);
        nvram_api_store_by_selector(STORE_DEVICE_SETTINGS);
    }
    if (user_settings.word_0x1d4.bytes[BYTE_0x1D6])
        user_settings.word_0x1d4.bytes[BYTE_0x1D6] = 0;
    if (factory_record.byte_0x14 != 0) {
        factory_record.byte_0x14 = 0;
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    }
    sys_api_restart_channel_at_level(MAIN_CHANNEL, 1);
    sys_api_restart_channel_at_level(SECOND_CHANNEL, 1);
}
