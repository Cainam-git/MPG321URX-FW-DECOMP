/* power_enter_app_state  (FUN_a0081ea8)
 *
 * Enter application power state 0..5 (on/off, power on, power saving)
 *   state: power state 0..5
 * Note: Jump table on the state; state 0 also handles the burn-in and factory reset cases.
 * Name basis: proven - texts 'APPSTATE_PWR_ONOFF', 'APPSTATE_PWR_ON', 'APPSetPowersaving 01/02'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0081ea8 @ 0xa0081ea8..0xa0082acc (777 words), flags -mcpu=v8 -O3 -g. The switch compiles to the
 * jump table at run-time 0x201EC (case address = entry + 0xA0060000).
 * Source forms the exact build depends on:
 *  - app_state_record halfwords +0 and +4 as bit-fields (flags_0x0: bit14, bits_11_13, bit10; sleep_word:
 *    sleep_state = bits 13..14, bit12), and the clear of the settings factory_mode bit as a bit-field;
 *  - the if/else around sys_api_set_flag_e403(1) / (0);
 *  - the store orders of the alarm_byte_0x1a1 / alarm_byte_0x1a2 tails and of the 0xFF byte groups;
 *  - case 5: the clear of app_state_record +6 bit 6 as a bit-field (flags_0x6.bit6 = 0), which gives the
 *    and/sth/or order at 0xA0082210..18;
 *  - case 5: the two four-byte 0xFF groups are calls input_rearm_port_event(4, 0). That routine (0xA00808AC) is
 *    defined in this file and inlined by GCC at -O3; the inlined body ends the then-blocks, so the read of
 *    settings byte +0xAC forms &user_settings again in the delay slot at 0xA00827C8, as in the firmware.
 */

/* The fields of the user settings record (user_settings, docs/RECORDS.md, 0x1FC bytes) used here. */
struct user_settings_record {
  union { unsigned int word_0x0;                                      /* +0x00 */
          struct { unsigned int high_bits : 17, factory_mode : 1, bit13 : 1, bit12 : 1, bits_10_11 : 2, bit9 : 1,
                   low_bits : 9; } bits_0x0; };
  unsigned char p004[0x1a];
  unsigned char input_source, pip_pbp_mode;                           /* +0x1E, +0x1F (0 = PIP/PBP off) */
  unsigned char p020[0x88];
  unsigned int gaming_flags;                                          /* +0xA8 SETTINGS_POWER_BUTTON_STANDBY */
  union { unsigned int settings_page_flags; unsigned char byte_0xac; }; /* +0xAC SETTINGS_HDMI_CEC_ON; byte_0xac
                                                                         = its first byte */
  unsigned char p0b0[0xe7];
  unsigned char alarm_table_0x197[4];                                 /* +0x197 indexed by the Alarm Clock choice */
  unsigned char alarm_table_0x19b[4];                                 /* +0x19B indexed by the Alarm Clock choice */
  unsigned char p19f;
  unsigned char alarm_clock, alarm_byte_0x1a1, alarm_byte_0x1a2;      /* +0x1A0 the Alarm Clock choice, then the
                                                                         two bytes taken from the tables above */
  unsigned char p1a3[0x32];
  unsigned char burn_in_flag, byte_0x1d6;                             /* +0x1D5, +0x1D6 */
  unsigned char p1d7[0xb];
  unsigned char byte_0x1e2;                                           /* +0x1E2 */
  unsigned char p1e3[3];
  unsigned char byte_0x1e6;                                           /* +0x1E6 */
  unsigned char p1e7[0xf];
  unsigned short factory_marker;                                      /* +0x1F6 FACTORY_MODE_MARKER / _OFF_MARKER */
};
/* The fields of the application state record (app_state_record) used here. */
struct app_state_record {
  union { unsigned short half_0x0;
          struct { unsigned short bit15 : 1, bit14 : 1, bits_11_13 : 3, bit10 : 1, low_bits : 10; } flags_0x0; };
  unsigned short half_0x2;
  union { unsigned short half_0x4;                                    /* app_state_record_sleep_word */
          struct { unsigned short bit15 : 1, sleep_state : 2, bit12 : 1, low_bits : 12; } sleep_word; };
  union { unsigned short half_0x6;
          struct { unsigned short high_bits : 9, bit6 : 1, low_bits : 6; } flags_0x6; };
  unsigned short half_0x8, half_0xa, half_0xc, half_0xe, halfword_0x10;
  unsigned char p012[7];
  unsigned char status_code;                                          /* +0x19 the LED light bar status code */
  unsigned char p01a[0x24];
  union { unsigned short half_0x3e; struct { unsigned char byte_0x3e, dialog_button_index; }; };  /* +0x3E, +0x3F */
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern unsigned char factory_record_byte_0x14;
extern unsigned char app_flags;
extern unsigned char app_port_last_states[4];
extern unsigned char hdmi_cec_vendor_id_bytes[4];
extern int dbg_printf();
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void sys_user_factory_reset(void);
extern void nvram_set_device_setting(int, int);
extern void nvram_api_store_by_selector(unsigned char);
extern void sys_user_reset_display_path(void);
extern void oled_power_reset_state(void);
extern void audio_user_update_routing(void);
extern void hdmi_cec_api_send_action(int);
extern void gpio_user_set_port2_bit2(void);
extern void gpio_set_port7_bit2_high(void);
extern void gpio_set_port6_bit2_high_copy(void);
extern void gpio_user_set_port7_bit1(unsigned char);
extern void gpio_set_port5_bit7_high(void);
extern void SYSAPI_SetPowerStatus(unsigned char);
extern void sys_api_restart_channel_at_level(int, int);
extern void ShowLogo(void);
extern void sys_set_key_blocked(int, int);
extern void sys_api_set_all_channels_flag25(void);
extern void sys_api_clear_all_channels_flag25(void);
extern unsigned short osd_get_menu_state(void);
extern void osd_close_menu(void);
extern void APPSetPowerOff(int);
extern unsigned char oled_power_get_field_12(void);
extern void App_Initialize(int);
extern void power_escape_fake_sleep(void);
extern void gpio_user_set_led_by_state(void);
extern void UserSetAuroraLEDBarBrightness(unsigned char);
extern unsigned char oled_power_get_state(void);
extern unsigned char oled_power_get_step(void);
extern void oled_power_set_field_0d(unsigned char);
extern void oled_power_set_field_0f(unsigned char);
extern void oled_power_task(void);
extern void gpio_set_aux_bit0_low(void);
extern void gpio_set_port4_bit7_low_if_allowed(void);
extern void gpio_set_port4_bit4_high_if_allowed(void);
extern void gpio_set_port4_bit7_high_if_allowed(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void gpio_set_port2_bit2_low(void);
extern void gpio_set_aux_bit1_low(void);
extern void sys_api_set_flag_e403(int);
extern void sys_poll_events_stub_copy19(void);
extern void gpio_set_port7_bit2_low(void);
extern void gpio_set_port5_bit7_low(void);
extern void gpio_set_aux_bit5_low(void);
extern void gpio_set_port7_bit1_low(void);
extern void gpio_set_port7_bit7_inverted(unsigned char);
extern void gpio_set_aux_bit7_high(void);
extern void gpio_set_port6_bit2_high(void);
extern void sys_poll_events_stub_copy8();
extern void gpio_set_aux_bit7_low(void);
extern void gpio_set_aux_bit2_low(void);
extern unsigned char panel_is_power_on_done(void);
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);
extern void hdmi_cec_api_reset(void);
extern void sys_poll_events_stub_copy7(void);
extern void gpio_set_port12_bit0_low(void);
extern void panel_blurfree_apply_user_mode(int);
extern void SYSAPI_PowerSaving(void);
extern int SYSAPI_WriteEEPROM();
extern void sys_app_timer_start(int, int);
extern unsigned char sys_api_get_channel_state_code(unsigned char);

/* The application power states (argument of power_enter_app_state). */
enum {
  APP_POWER_ONOFF  = 0,         /* "APPSTATE_PWR_ONOFF": power off or on by the sleep state */
  APP_POWER_OFF    = 1,         /* APPSetPowerOff, when a channel reports a state */
  APP_POWER_ON     = 2,         /* "APPSTATE_PWR_ON" */
  APP_POWER_SAVING = 3,         /* "APPSetPowersaving" */
  APP_POWER_STATE_4 = 4,        /* pins and the e403 flag only */
  APP_POWER_STATE_5 = 5         /* leave fake sleep; see below */
};

/* app_state_record.sleep_word.sleep_state (0 is also taken as "dc off"). */
#define SLEEP_STATE_DC_ON              1        /* the value taken here as "dc on" */
#define SLEEP_STATE_FAKE_SLEEP         2

#define FACTORY_MODE_MARKER            0x55aa   /* settings halfword +0x1F6 while factory mode is on */
#define FACTORY_MODE_OFF_MARKER        0xbb99   /* the value ddc_tool_set_factory_mode writes when it ends factory mode */
#define SETTINGS_WORD0_BIT9            0x200    /* user settings word +0, bit 9 */
#define SETTINGS_WORD0_BIT12           0x1000   /* user settings word +0, bit 12 */
#define SETTINGS_WORD0_FACTORY_MODE    0x4000   /* user settings word +0, bit 14: the factory mode flag */
#define SETTINGS_HDMI_CEC_ON           0x100000 /* settings word +0xAC bit 20: the HDMI CEC menu switch */
#define SETTINGS_POWER_BUTTON_STANDBY  0x8000   /* settings word +0xA8 bit 15: the Power Button menu choice,
                                                   0 = OFF, 1 = Standby */
#define FACTORY_STATUS_2_VALUE         0x55     /* settings byte +0x1D6 (factory tool status 2) */

#define MENU_STATE_PANEL_PROTECT       0x10a    /* menu state of the OLED panel protect prompt */
#define LAST_MENU_INDEX                0x14     /* input source menu indexes above this wrap round to source 0 */

#define APP_FLAG_LOGO_HOLD             1        /* app_flags bit 0 */
#define KEY_ALL                        0xff     /* sys_set_key_blocked: every key */

#define AFTER_SENSING_POWER_SAVING     1        /* oled_power_task: "Goto PowerSaving" after a sensing run */
#define PANEL_OFF                      0        /* SYSAPI_PanelOnOffControl: first argument */
#define WAIT_DONE                      1        /* SYSAPI_PanelOnOffControl: second argument */

#define EEPROM_AREA_CODE               0x30     /* first argument of SYSAPI_WriteEEPROM */
#define SETTINGS_SIZE                  0x1fc

/* Device settings cleared by the factory reset at "dc on" (the OLED use-time and run counters). */
#define DEVICE_SETTING_EL_COUNT        0xa
#define DEVICE_SETTING_OFFS_COUNT      0xb
#define DEVICE_SETTING_EL_HOURS        0xc
#define DEVICE_SETTING_OFFS_HOURS      0xd
#define DEVICE_SETTING_EL_RUNS         0xe
#define DEVICE_SETTING_OFFS_RUNS       0xf
#define DEVICE_SETTING_SENSING_TEST    0x10     /* factory menu switch "Sensing Test" */

#define ALL_PORTS                      4        /* input_rearm_port_event: every port 0..3 */
#define PORT_STATE_UNKNOWN             0xff

extern unsigned char app_port_rearm_bits;

/*
 * Mark the last state of one port (0..3), or of all four (port == ALL_PORTS), as unknown (0xFF).
 * With rearm == 1 the port's bit (bit n for port n, all four for ALL_PORTS) is also set in app_port_rearm_bits.
 * A port above 4 indexes app_port_last_states without a check.
 */
void input_rearm_port_event(unsigned char port, unsigned char rearm)
{
    if (port == ALL_PORTS) {
        app_port_last_states[0] = PORT_STATE_UNKNOWN;
        app_port_last_states[1] = PORT_STATE_UNKNOWN;
        app_port_last_states[2] = PORT_STATE_UNKNOWN;
        app_port_last_states[3] = PORT_STATE_UNKNOWN;
        if (rearm == 1)
            app_port_rearm_bits |= 0xf;
    } else {
        app_port_last_states[port] = PORT_STATE_UNKNOWN;
        if (rearm == 1) {
            if (port == 0)
                app_port_rearm_bits |= 1;
            else if (port == 1)
                app_port_rearm_bits |= 2;
            else if (port == 2)
                app_port_rearm_bits |= 4;
            else if (port == 3)
                app_port_rearm_bits |= 8;
        }
    }
}

/*
 * Carry out one application power state change.
 *
 *   state  APP_POWER_ONOFF .. APP_POWER_STATE_5; other values do nothing
 *
 * Callers: APPActionDispatcher, sys_run_app_timer_task, oled_power_task (APP_POWER_SAVING and APP_POWER_OFF at
 * the end of a sensing run), ddc_tool_set_power and ddc_tool_dispatch_command.
 *
 * APP_POWER_ONOFF, in order:
 *   1. Return at once while burn-in is on in factory mode.
 *   2. Sleep state 0 or fake sleep ("dc off"): update settings bytes +0x1E2 / +0x1E6 from app state halfword
 *      +0x10, end the logo hold, close the menu, save the settings and run APPSetPowerOff(0).
 *   3. Sleep state "dc on": clear the factory mode flag; after factory mode or burn-in, end factory mode and
 *      reset the settings and the OLED counters; restart the display path, set the pins of ports 2, 5, 6 and 7,
 *      store power status 1, show the logo where the settings ask for it, and end with sleep state 0.
 * APP_POWER_OFF: when at least one of the channels 0..3 reports a non-zero state code, end the logo hold, close
 *   the menu and run APPSetPowerOff(0).
 * APP_POWER_ON: sleep state 0, restart the display path, store power status 1, the logo as in "dc on", then
 *   App_Initialize(1).
 * APP_POWER_SAVING: let the OLED power state machine run first ("--->RETURN0" / "--->RETURN1" when it is busy),
 *   then set the pins of power saving, stop at "--->RETURN2" in fake sleep, else switch the panel off and enter
 *   SYSAPI_PowerSaving.
 * APP_POWER_STATE_4: set pins and clear the e403 flag; the panel is not switched here.
 * APP_POWER_STATE_5: leave fake sleep, restore the pins and the LED bar, and run App_Initialize(3) when power
 *   saving left app state +6 bit 6 set.
 *
 * In "dc on" and APP_POWER_ON app state bit 10 is set to the inverse of the factory mode flag (settings word +0
 * bit 14); APP_POWER_SAVING sets it to 1 at every exit. "The factory condition" in the comments means: factory marker set and settings byte +0x1D6 == 0x55. The gpio_set_aux_*
 * routines pass GPIO port 0xFF to gpio_write_pin, which writes nothing for ports above 17.
 */
void power_enter_app_state(unsigned int state)
{
  unsigned char saved = user_settings.input_source;
  unsigned char i, none;

  switch (state) {
  case APP_POWER_ONOFF:
    dbg_printf("APPSTATE_PWR_ONOFF\r\n");
    /* 1. Burn-in in factory mode: nothing to do. */
    if (user_settings.burn_in_flag != 0 && user_settings.factory_marker == FACTORY_MODE_MARKER)
      return;
    if (app_state_record.sleep_word.sleep_state == 0 || app_state_record.sleep_word.sleep_state == SLEEP_STATE_FAKE_SLEEP) {
      /* 2. "dc off". */
      dbg_printf("dc off\r\n");
      /* Copy app state halfword +0x10 (0..4) into settings byte +0x1E2 and clear +0x1E6, when the panel
         protect prompt is open or when the LED bar status code is 1. */
      if (app_state_record.halfword_0x10 <= 4 && osd_get_menu_state() == MENU_STATE_PANEL_PROTECT && user_settings.byte_0x1e2 != app_state_record.halfword_0x10) {
        user_settings.byte_0x1e2 = app_state_record.halfword_0x10;
        user_settings.byte_0x1e6 = 0;
      }
      if (app_state_record.halfword_0x10 <= 4 && user_settings.byte_0x1e2 != app_state_record.halfword_0x10 && app_state_record.status_code == 1) {
        user_settings.byte_0x1e2 = app_state_record.halfword_0x10;
        user_settings.byte_0x1e6 = 0;
      }
      /* End the logo hold: unblock the keys and clear flag 25 of the channels. */
      if (app_flags & APP_FLAG_LOGO_HOLD) {
        sys_set_key_blocked(KEY_ALL, 0);
        app_flags &= ~APP_FLAG_LOGO_HOLD;
        sys_api_clear_all_channels_flag25();
      }
      osd_close_menu();
      SYSAPI_WriteEEPROM(EEPROM_AREA_CODE, &user_settings, 0, SETTINGS_SIZE);
      APPSetPowerOff(0);
      return;
    }
    if (app_state_record.sleep_word.sleep_state != SLEEP_STATE_DC_ON)
      return;
    /* 3. "dc on". */
    dbg_printf("dc on\r\n");
    user_settings.bits_0x0.factory_mode = 0;
    /* After factory mode or burn-in: end factory mode, reset the settings and clear the OLED counters. */
    if (user_settings.factory_marker == FACTORY_MODE_MARKER || user_settings.burn_in_flag != 0) {
      user_settings.factory_marker = FACTORY_MODE_OFF_MARKER;
      user_settings.burn_in_flag = 0;
      sys_user_factory_reset();
      nvram_set_device_setting(8, 0);
      nvram_set_device_setting(9, 0);
      nvram_set_device_setting(6, 0);
      nvram_set_device_setting(7, 0);
      nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
      nvram_set_device_setting(DEVICE_SETTING_EL_COUNT, 0);
      nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
      nvram_set_device_setting(DEVICE_SETTING_EL_HOURS, 0);
      nvram_set_device_setting(DEVICE_SETTING_SENSING_TEST, 0);
      nvram_set_device_setting(DEVICE_SETTING_EL_RUNS, 0);
      nvram_set_device_setting(DEVICE_SETTING_OFFS_RUNS, 0);
      nvram_api_store_by_selector(1);
    }
    app_state_record.sleep_word.bit12 = 1;
    /* Restart the display path once with the next input source (wrapping round to source 0), then once
       with the selected one. */
    if (input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source) + 1) > LAST_MENU_INDEX)
      user_settings.input_source = input_api_menu_index_to_source_id(0);
    else
      user_settings.input_source = input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source) + 1);
    sys_user_reset_display_path();
    user_settings.input_source = saved;
    sys_user_reset_display_path();
    oled_power_reset_state();
    audio_user_update_routing();
    gpio_set_port4_bit4_low_if_allowed();
    gpio_set_port4_bit7_high_if_allowed();
    /* HDMI CEC on and PIP/PBP off: send CEC actions 2 and 3. */
    if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && user_settings.pip_pbp_mode == 0) {
      hdmi_cec_api_send_action(2);
      hdmi_cec_api_send_action(3);
    }
    /* Pins of ports 2, 7, 6 and 5. */
    gpio_user_set_port2_bit2();
    gpio_set_port7_bit2_high();
    gpio_set_port6_bit2_high_copy();
    gpio_user_set_port7_bit1(0);
    gpio_set_port5_bit7_high();
    SYSAPI_SetPowerStatus(1);
    sys_api_restart_channel_at_level(1, 1);
    /* Settings bit 12 set, factory mode off: show the logo and hold every key except 0x40 for 3000 ms
       (application timer 3). */
    if ((user_settings.word_0x0 & (SETTINGS_WORD0_FACTORY_MODE | SETTINGS_WORD0_BIT12)) == SETTINGS_WORD0_BIT12 && user_settings.factory_marker != FACTORY_MODE_MARKER) {
      dbg_printf("\nshow logo %d\r\n", 1);
      ShowLogo();
      sys_set_key_blocked(KEY_ALL, 1);
      sys_set_key_blocked(0x40, 0);
      app_flags |= APP_FLAG_LOGO_HOLD;
      sys_api_set_all_channels_flag25();
      sys_app_timer_start(3, 3000);
    }
    if ((user_settings.word_0x0 & (SETTINGS_WORD0_FACTORY_MODE | SETTINGS_WORD0_BIT12)) != SETTINGS_WORD0_BIT12 || user_settings.factory_marker == FACTORY_MODE_MARKER)
      sys_api_clear_all_channels_flag25();
    if (user_settings.word_0x0 & SETTINGS_WORD0_FACTORY_MODE)
      app_state_record.flags_0x0.bit10 = 0;
    else
      app_state_record.flags_0x0.bit10 = 1;
    user_settings.alarm_byte_0x1a1 = user_settings.alarm_table_0x197[user_settings.alarm_clock];
    user_settings.alarm_byte_0x1a2 = user_settings.alarm_table_0x19b[user_settings.alarm_clock];
    app_state_record.flags_0x0.bit14 = 0;
    app_state_record.sleep_word.sleep_state = 0;
    return;

  case APP_POWER_OFF:
    /* Only when at least one channel reports a state. */
    none = 1;
    for (i = 0; i <= 3; i++)
      if (sys_api_get_channel_state_code(i)) {
        none = 0;
        break;
      }
    if (none)
      return;
    if (app_flags & APP_FLAG_LOGO_HOLD) {
      sys_set_key_blocked(KEY_ALL, 0);
      app_flags &= ~APP_FLAG_LOGO_HOLD;
      sys_api_clear_all_channels_flag25();
    }
    osd_close_menu();
    APPSetPowerOff(0);
    return;

  case APP_POWER_ON:
    dbg_printf("APPSTATE_PWR_ON\r\n");
    app_state_record.sleep_word.sleep_state = 0;
    /* Restart the display path with the next input source, then with the selected one (as in "dc on"). */
    if (input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source) + 1) > LAST_MENU_INDEX)
      user_settings.input_source = input_api_menu_index_to_source_id(0);
    else
      user_settings.input_source = input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source) + 1);
    sys_user_reset_display_path();
    user_settings.input_source = saved;
    sys_user_reset_display_path();
    oled_power_reset_state();
    gpio_set_port4_bit4_low_if_allowed();
    gpio_set_port4_bit7_high_if_allowed();
    SYSAPI_SetPowerStatus(1);
    if ((user_settings.word_0x0 & (SETTINGS_WORD0_FACTORY_MODE | SETTINGS_WORD0_BIT12)) == SETTINGS_WORD0_BIT12 && user_settings.factory_marker != FACTORY_MODE_MARKER) {
      dbg_printf("\nshow logo %d\r\n", 1);
      ShowLogo();
      sys_set_key_blocked(KEY_ALL, 1);
      sys_set_key_blocked(0x40, 0);
      app_flags |= APP_FLAG_LOGO_HOLD;
      sys_api_set_all_channels_flag25();
      sys_app_timer_start(3, 3000);
    }
    App_Initialize(1);
    if (user_settings.word_0x0 & SETTINGS_WORD0_FACTORY_MODE)
      app_state_record.flags_0x0.bit10 = 0;
    else
      app_state_record.flags_0x0.bit10 = 1;
    user_settings.alarm_byte_0x1a1 = user_settings.alarm_table_0x197[user_settings.alarm_clock];
    user_settings.alarm_byte_0x1a2 = user_settings.alarm_table_0x19b[user_settings.alarm_clock];
    app_state_record.flags_0x0.bit14 = 0;
    return;

  case APP_POWER_SAVING:
    dbg_printf("APPSetPowersaving 01\r\n");
    app_state_record.dialog_button_index = 0;
    app_state_record.half_0xc = 0;
    /* The OLED power state machine is busy: leave it alone. */
    if (oled_power_get_state() || oled_power_get_step()) {
      dbg_printf("--->RETURN0\r\n");
      app_state_record.flags_0x0.bit10 = 1;
      return;
    }
    /* Power-down request = 1 and power saving after a sensing run, then run the state machine once. */
    osd_close_menu();
    oled_power_set_field_0d(1);
    oled_power_set_field_0f(AFTER_SENSING_POWER_SAVING);
    oled_power_task();
    /* It has started a sensing run or the power-down: it continues from there. */
    if (oled_power_get_state() || oled_power_get_step()) {
      dbg_printf("--->RETURN1\r\n");
      app_state_record.flags_0x0.bit10 = 1;
      return;
    }
    dbg_printf("APPSetPowersaving 02\r\n");
    app_state_record.half_0x3e &= ~0x8000;
    gpio_set_aux_bit0_low();
    /* Pins, skipped under the factory condition. */
    if (user_settings.factory_marker != FACTORY_MODE_MARKER || user_settings.byte_0x1d6 != FACTORY_STATUS_2_VALUE) {
      gpio_set_port4_bit7_low_if_allowed();
      gpio_set_port4_bit4_high_if_allowed();
    }
    if (user_settings.factory_marker != FACTORY_MODE_MARKER || user_settings.byte_0x1d6 != FACTORY_STATUS_2_VALUE)
      gpio_set_port2_bit2_low();
    gpio_set_aux_bit1_low();
    /* Power Button OFF and no fake sleep: pins of ports 7, 5 and 6. */
    if (!(user_settings.gaming_flags & SETTINGS_POWER_BUTTON_STANDBY) && !oled_power_get_field_12()) {
      if (user_settings.factory_marker != FACTORY_MODE_MARKER || user_settings.byte_0x1d6 != FACTORY_STATUS_2_VALUE) {
        gpio_set_port7_bit2_low();
        gpio_set_port5_bit7_low();
        gpio_set_aux_bit5_low();
        gpio_set_port7_bit7_inverted(0);
      }
      if (factory_record_byte_0x14 == 1 && user_settings.factory_marker == FACTORY_MODE_MARKER) {
        gpio_set_port7_bit2_high();
        gpio_set_aux_bit7_high();
        gpio_set_port6_bit2_high();
        sys_poll_events_stub_copy8(1);
      } else if (user_settings.factory_marker != FACTORY_MODE_MARKER || user_settings.byte_0x1d6 != FACTORY_STATUS_2_VALUE) {
        gpio_set_port7_bit2_low();
        gpio_set_aux_bit7_low();
        sys_poll_events_stub_copy8(0);
        gpio_set_aux_bit2_low();
      }
    }
    /* Fake sleep (OLED field +0x12 = 1): switch the panel off if it is on, and stop here. */
    if (oled_power_get_field_12() == 1) {
      if (panel_is_power_on_done())
        SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
      dbg_printf("--->RETURN2\r\n");
      app_state_record.flags_0x0.bit10 = 1;
      return;
    }
    /* HDMI CEC on and PIP/PBP off: fill the received CEC vendor bytes with 0xFF; otherwise, with Power Button
       OFF, clear the CEC control register (as in APPSetPowerOff). */
    if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && user_settings.pip_pbp_mode == 0) {
      hdmi_cec_vendor_id_bytes[3] = 0xff;
      hdmi_cec_vendor_id_bytes[2] = 0xff;
      hdmi_cec_vendor_id_bytes[1] = 0xff;
      hdmi_cec_vendor_id_bytes[0] = 0xff;
    } else if (!(user_settings.gaming_flags & SETTINGS_POWER_BUTTON_STANDBY))
      hdmi_cec_api_reset();
    if (user_settings.word_0x0 & SETTINGS_WORD0_BIT9)
      sys_api_set_flag_e403(1);
    else
      sys_api_set_flag_e403(0);
    /* App state +6 bit 7 set: panel off only, and bit 6 marks it for APP_POWER_STATE_5. Otherwise panel off
       and, outside the factory condition, power saving. */
    if (app_state_record.half_0x6 & 0x80) {
      SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
      app_state_record.half_0x6 |= 0x40;
    } else {
      SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
      sys_poll_events_stub_copy7();
      if (user_settings.factory_marker != FACTORY_MODE_MARKER || user_settings.byte_0x1d6 != FACTORY_STATUS_2_VALUE) {
        gpio_set_port12_bit0_low();
        panel_blurfree_apply_user_mode(1);
        SYSAPI_PowerSaving();
      }
    }
    app_state_record.flags_0x0.bit10 = 1;
    return;

  case APP_POWER_STATE_4:
    gpio_set_port4_bit7_low_if_allowed();
    gpio_set_port4_bit4_high_if_allowed();
    gpio_set_port2_bit2_low();
    gpio_set_aux_bit1_low();
    if (!(user_settings.gaming_flags & SETTINGS_POWER_BUTTON_STANDBY)) {
      gpio_set_port7_bit2_low();
      gpio_set_port5_bit7_low();
      gpio_set_aux_bit5_low();
      gpio_set_port7_bit1_low();
    }
    sys_api_set_flag_e403(0);
    sys_poll_events_stub_copy19();
    return;

  case APP_POWER_STATE_5:
    /* Fake sleep with settings bit 9 clear: leave it and mark every port's last state unknown. */
    if (app_state_record.sleep_word.sleep_state == SLEEP_STATE_FAKE_SLEEP && !(user_settings.word_0x0 & SETTINGS_WORD0_BIT9)) {
      power_escape_fake_sleep();
      input_rearm_port_event(ALL_PORTS, 0);
    }
    /* OLED fake-sleep field set and not menu state 0xFE: restore pins and the LED light bar. */
    if (oled_power_get_field_12() == 1 && osd_get_menu_state() != 0xfe) {
      if (!(user_settings.word_0x0 & SETTINGS_WORD0_BIT9)) {
        gpio_set_port4_bit4_low_if_allowed();
        gpio_set_port4_bit7_high_if_allowed();
        input_rearm_port_event(ALL_PORTS, 0);
      }
      gpio_user_set_port2_bit2();
      gpio_user_set_led_by_state();
      UserSetAuroraLEDBarBrightness(user_settings.byte_0xac);
    }
    /* Bit 6 left by APP_POWER_SAVING: restart the display path and initialise again (App_Initialize(3)). */
    if (app_state_record.half_0x6 & 0x40) {
      app_state_record.flags_0x6.bit6 = 0;
      if (input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source) + 1) > LAST_MENU_INDEX)
        user_settings.input_source = input_api_menu_index_to_source_id(0);
      else
        user_settings.input_source = input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source) + 1);
      sys_user_reset_display_path();
      user_settings.input_source = saved;
      sys_user_reset_display_path();
      gpio_set_port4_bit4_low_if_allowed();
      gpio_set_port4_bit7_high_if_allowed();
      SYSAPI_SetPowerStatus(1);
      App_Initialize(3);
    }
    return;
  }
}
