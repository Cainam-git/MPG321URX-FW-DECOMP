/* sys_run_app_timer_task  (FUN_a0085984)
 *
 * Run the timed application checks: OLED errors, fake sleep, power saving, USB, PIP.
 * Note: Main-loop task; each pass also runs input_resend_link_bytes_on_pin_change, uart_cmd_run_tool_task,
 *   uart_cmd_poll_port2 and UsbModeSelectRoutine.
 * Name basis: proven - docs/MAP.md: main loop's timer routine; texts 'fake sleep count start', 'Vx1 is
 *   abnormal'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0085984 (APPTimerRoutine) @ 0xA0085984..0xA00869B0 (1,035 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - no goto. Both power-saving chains keep their own copies of the shared steps: each "enter power saving" arm
 *    ends with its own power_enter_app_state(APP_POWER_SAVING) and its own clear of APP_PORT_FLAG_DELAYED_ALL,
 *    and the DELAYED_ALL chain starts APP_TIMER_B with 1000 ms in both arms of the sleep_state test. GCC
 *    cross-jumps the copies into the firmware's shared code;
 *  - the last three calls are nested (input_resend_link_bytes_on_pin_change(0)'s result is the argument of
 *    uart_cmd_run_tool_task, whose result is the argument of uart_cmd_poll_port2): the firmware leaves each
 *    result in the argument register. The compiled code holds two copies of these three calls;
 *  - SYSAPI_WriteEEPROM declared int-returning (gives the firmware's delay-slot fill);
 *  - byte +6 of the application state record is cleared through a byte pointer to half_0x6.
 */

/* Application timers (sys_app_timer_start / sys_app_timer_read; millisecond down-counters, app_timers). */
#define APP_TIMER_SAVE_REQUESTS     1       /* paces the save requests of app_flags_second: once a second */
#define APP_TIMER_LOGO_HOLD         3       /* started with 3000 ms by power_enter_app_state when it shows the logo */
#define APP_TIMER_B                 0xb     /* steps of the two delayed-all chains (burn-in, no signal, power saving) */
#define APP_TIMER_PBP_INPUT_CHECK   0x11    /* 200 ms between the PBP checks of channel 1's input */
#define APP_TIMER_FAKE_SLEEP_MINUTE 0x12    /* one minute of the fake-sleep count */
#define APP_TIMER_LED_BAR_QUERY     0x13    /* 20 s between queries to the LED light bar */
#define APP_TIMER_CEC_SOURCE_HOLD   0x14    /* started with 5000 ms together with APP_STATE_CEC_SOURCE_HOLD */
#define APP_TIMER_AUX0_TIME         0x15    /* 20 s steps of the minute and hour count in the factory record */
#define APP_TIMER_USB_HUB_POWER_ON  0x16    /* started with 1000 ms by UsbModeSelectRoutine ("OT2211 Power ON") */

#define MINUTE_MS                   60000
#define LED_BAR_QUERY_MS            20000
#define AUX0_TIME_STEP_MS           20000   /* three steps make one minute */

/* power_enter_app_state: the states used here. */
#define APP_POWER_OFF               1       /* APPSetPowerOff */
#define APP_POWER_ON                2       /* "APPSTATE_PWR_ON" */
#define APP_POWER_SAVING            3       /* "APPSetPowersaving" */

/* SYSAPI_PanelOnOffControl arguments. */
#define PANEL_OFF                   0
#define PANEL_ON                    1
#define WAIT_DONE                   1       /* return only when the switching is finished */

/* SYSAPI_WriteEEPROM: the one area code it knows, and where the two records lie in that area. */
#define EEPROM_AREA                 0x30
#define USER_SETTINGS_OFFSET        0
#define USER_SETTINGS_SIZE          0x1fc
#define FACTORY_RECORD_OFFSET       0x2e0
#define FACTORY_RECORD_SIZE         0x1c

#define FACTORY_MODE_MARKER         0x55aa  /* settings halfword +0x1F6 while the factory tool's factory mode is on */
#define SETTINGS_WORD0_BIT9         0x200   /* user settings word +0, bit 9: when set, no "No Signal" step here */
#define GAMING_FLAG_BIT6            0x40    /* gaming_flags bit 6: the level gpio_user_set_port2_bit2 drives */
#define GAMING_FLAG_BIT15           0x8000  /* gaming_flags bit 15: fake sleep instead of power saving */
#define SETTINGS_PAGE_FLAG_BIT20    0x100000 /* settings_page_flags bit 20: the CEC commands are acted on */
#define DEVICE_SETTING_PHY_CTS_AUTO 2       /* factory menu switch "PHY CTS AUTO": fake sleep instead of power saving */

/* app_port_flags bits set by the dispatcher's actions for the events APP_EV_DELAYED_ALL and
   APP_EV_DELAYED_ALL_INACTIVE; each action also starts APP_TIMER_B with 5000 ms. */
#define APP_PORT_FLAG_DELAYED_ALL          0x10    /* bit 4 */
#define APP_PORT_FLAG_DELAYED_ALL_INACTIVE 0x4000  /* bit 14 */

#define APP_FLAG_LOGO_HOLD          1       /* app_flags bit 0: set with the logo, keys blocked but 0x40 */

/* app_flags_second: requests to save, served once a second. */
#define APP_FLAG44_STORE_MODES_2    0x01    /* nvram_api_store_by_selector(2): the mode row of the shown channel */
#define APP_FLAG44_SAVE_SETTINGS    0x02    /* the user settings record */
#define APP_FLAG44_STORE_MODES_0    0x04    /* nvram_api_store_by_selector(0): the part record */
#define APP_FLAG44_STORE_MODES_1    0x08    /* nvram_api_store_by_selector(1): the device settings record */

/* Bits of the application state record. */
#define APP_STATE_BIT10             0x400   /* half_0x0: set when a CEC request has changed the input source */
#define SLEEP_WORD_BURNIN_STARTED   0x200   /* sleep_word bit 9: set by the first burn-in step */
#define SLEEP_WORD_USB_HUB_POWER_ON 0x800   /* sleep_word bit 11: set with APP_TIMER_USB_HUB_POWER_ON */
#define HALF6_BIT5                  0x20    /* half_0x6 (byte +7) bit 5: replaced by bit 4 when it is seen */
#define HALF6_BIT4                  0x10
#define APP_STATE_CEC_SOURCE_HOLD   0x40    /* half_0xa bit 6: CEC source requests are ignored while it is set */

#define SLEEP_STATE_AWAKE           0       /* app_state_record sleep_state */
#define SLEEP_STATE_FAKE_SLEEP      2

/* OLED power state machine (oled_power_state): values stored here. */
#define AFTER_SENSING_POWER_SAVING  1       /* after_sensing (+0x0F): "Goto PowerSaving" */
#define RUN_END_POWER_SAVING_OR_OFF 2       /* byte_0x11: a run has ended towards power saving or power off */

/* Channel state codes (sys_api_get_channel_state_code); 10 is channel state 12, the last one. */
#define CHANNEL_CODE_LAST           10
#define CHANNEL_STATE_LAST          12      /* sys_get_channel_state */
#define CHANNEL_CODE_7              7
#define CHANNEL_CODE_8              8
#define CHANNEL_CODE_5              5

#define MENU_STATE_INPUT_QUICK_MENU 0xfe    /* osd_open_input_quick_menu */
#define SIGNAL_MESSAGE_NO_SIGNAL    0x19    /* osd_draw_signal_message: input name and 'No Signal' */
#define MENU_STATE_CLOSED           0

#define KEY_ID_ALL                  0xff    /* sys_set_key_blocked: every key */
#define LEVEL_MAX                   0x3ff   /* SetBrightness: the highest panel level */
#define FAKE_SLEEP_NOT_COUNTING     0xff    /* sys_fake_sleep_minutes, sys_fake_sleep_led_flag */
#define FAKE_SLEEP_LAST_MINUTE      10
#define AUX0_TIME_STEPS_PER_MINUTE  3
#define MINUTES_PER_HOUR            60
#define PBP_INPUT_CHECK_MS          200
#define PBP_PORT_CODE_D             0xd     /* port code of channel 1 for which the PBP check runs */

/* CEC commands (hdmi_cec_api_get_command), by the message the receive step (hdmi_cec_receive_and_reply)
   stored them for: the first message byte, and the flag bit it set. */
enum {
    CEC_CMD_NONE            = 0,
    CEC_CMD_FLAG0           = 1,    /* receive flag bit 0; the receive step itself does not set it */
    CEC_CMD_MSG_36          = 2,    /* message 0x36 */
    CEC_CMD_ACTIVATE_SOURCE = 3,    /* message 0x82 or 0x84, header low nibble 0xF, sender byte not 0:
                                       "_SYS_CECRequest_ActivateSC" */
    CEC_CMD_MSG_44_OP40     = 5,    /* message 0x44 (header low nibble not 0xF) with operand 0x40 */
    CEC_CMD_VENDOR_ID       = 6,    /* message 0x87, header low nibble 0xF: "_SYS_CECRequest_VendorID" */
    CEC_CMD_MSG_47          = 7     /* message 0x47 (header low nibble not 0xF): five bytes kept */
};
/* The sender byte of an activate-source request (the byte after the message code) and the input source taken. */
#define CEC_SENDER_1                0x10
#define CEC_SENDER_2                0x20
#define CEC_SENDER_3                0x30
#define CEC_SENDER_4                0x40
#define CEC_SOURCE_1                5       /* user_settings.input_source values */
#define CEC_SOURCE_2                6
#define CEC_SOURCE_3                7
#define CEC_SOURCE_4                8

#define MAIN_CHANNEL                0
#define SECOND_CHANNEL              1
#define CHANNEL_3                   3
#define RESTART_LEVEL_1             1       /* sys_api_restart_channel_at_level */

/* The user settings record (docs/RECORDS.md), up to the fields used here. */
struct user_settings_record
{
  unsigned int word_0x0;                /* +0x000 */
  unsigned char p004[0x1a];
  unsigned char input_source;           /* +0x01E Input Source (menu index) */
  unsigned char pip_pbp_mode;           /* +0x01F 0 off, 1 PIP, 2 PBP */
  unsigned char second_source;          /* +0x020 source of the second picture */
  unsigned char p021[0xe];
  unsigned char pbp_layout;             /* +0x02F */
  unsigned char p030[0x1a];
  unsigned char optix_scope;            /* +0x04A Optix Scope switch */
  unsigned char p04b[0x5d];
  unsigned int gaming_flags;            /* +0x0A8 */
  unsigned int settings_page_flags;     /* +0x0AC */
  unsigned char p0b0[0x125];
  unsigned char burn_in_flag;           /* +0x1D5 factory menu "Burn In": 0 off, 1..3 the step pace below */
  unsigned char p1d6[0x20];
  unsigned short factory_mode_marker;   /* +0x1F6 FACTORY_MODE_MARKER in factory mode */
};
/* The application state record (0xA802CFF4), up to the fields used here. */
struct app_state_record
{
  unsigned short half_0x0;              /* +0x00 */
  unsigned short half_0x2;              /* +0x02 */
  union
  {
    unsigned short sleep_word;          /* +0x04 */
    struct
    {
      unsigned short bit15 : 1;
      unsigned short sleep_state : 2;   /* bits 13..14: SLEEP_STATE_* */
      unsigned short low_bits : 13;
    } sleep;
  };
  unsigned short half_0x6;              /* +0x06 high byte (+6) = pressed_key_bit of the key scan */
  unsigned short half_0x8;              /* +0x08 */
  unsigned short half_0xa;              /* +0x0A */
  unsigned char p00c[8];
  union
  {
    unsigned short half_0x14;           /* +0x14 */
    struct
    {
      unsigned short bit15 : 1;
      unsigned short bit14 : 1;         /* the bit-14 burn-in step waits while it is set */
      unsigned short low_bits : 14;
    } bits;
  } u014;
};
/* The factory record (docs/RECORDS.md), up to the fields used here. */
struct factory_record
{
  unsigned char p00[0x11];
  unsigned char panel_error_count;      /* +0x11 counted here as minutes, 0..59 */
  unsigned short check_status;          /* +0x12 counted here as hours, up to 0xFFFF */
  unsigned char byte_0x14;              /* +0x14 */
  unsigned char byte_0x15;              /* +0x15 OLED error detections stored */
  unsigned short half_0x16;             /* +0x16 OLED controller register 0x10 at the stored detection */
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern struct factory_record factory_record;
extern unsigned char app_flags;
extern unsigned char app_flags_second;
extern unsigned char DAT_a802af46;      /* only read here: above 2 makes the burn-in step pace 2 fast (100 ms) */
extern unsigned char sys_aux0_time_step_count;      /* the 20 s steps of the current minute, 1..3 */
extern unsigned char sys_oled_error_stored;      /* 1 once an OLED error detection has been stored */
extern unsigned short app_port_flags;
extern unsigned char sys_fake_sleep_led_flag;
extern unsigned char sys_fake_sleep_minutes;
extern unsigned char hdmi_cec_vendor_id_bytes[4];
extern unsigned char hdmi_cec_source_name[];
/* The device settings record, word +0. */
struct device_settings_record
{
  unsigned int power_status : 1;        /* bit 31: stored by SYSAPI_SetPowerStatus, 1 after "dc on" */
  unsigned int rest : 31;
};
extern struct device_settings_record device_settings;
extern int dbg_printf();
extern unsigned char gpio_is_port13_bit5_high(void);
extern unsigned char gpio_is_port13_bit7_low(void);
extern unsigned char gpio_is_port10_bit2_high(void);
extern unsigned char sys_get_channel_state(int);
extern unsigned char panel_is_power_on_done(void);
extern unsigned char panel_vx1_is_locked(void);
extern unsigned char oled_power_get_state(void);
extern unsigned char oled_power_get_step(void);
extern unsigned char oled_power_get_field_0c(void);
extern unsigned char oled_power_get_field_12(void);
extern unsigned char oled_power_get_field_11(void);
extern unsigned char sys_api_get_channel_state_code(int);
extern unsigned char hdmi_cec_api_get_command(void);
extern unsigned char hdmi_cec_api_get_sender(void);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char input_api_get_channel_port_code(int);
extern unsigned char input_api_source_id_to_menu_index(int);
extern unsigned char gpio_is_aux_bit0_high(void);
extern unsigned char sys_get_channel_source_class(int);
extern unsigned short sys_app_timer_read(int);
extern unsigned short oled_read_reg_10(void);
extern unsigned short osd_get_menu_state(void);
extern unsigned short nvram_get_device_setting(int);
extern int sys_user_get_picture_state(void);
extern unsigned int hdmi_cec_api_get_message_word(void);
extern void SYSAPI_PanelOnOffControl(int, int);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);
extern void panel_request_power(int);
extern void power_enter_app_state(int);
extern void oled_frc_task(void);
extern void oled_power_task(void);
extern void sys_app_timer_start(int, int);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void oled_power_set_field_0f(int);
extern void oled_power_set_field_09(int);
extern void oled_power_set_field_0a(int);
extern void oled_power_set_field_11(int);
extern void oled_power_set_field_12(int);
extern void sys_api_set_all_channels_flag25(void);
extern void oled_set_off_sensing(int);
extern void oled_power_set_field_0d(int);
extern void oled_power_set_field_0c(int);
extern void gpio_set_port4_bit7_high_if_allowed(void);
extern void sys_led_bar_send_query(void);
extern void panel_user_set_output_on(int);
extern void sys_api_restart_channel_at_level(int, int);
extern void osd_close_menu(void);
extern void UserSetPIPMode(void);
extern void nvram_api_store_by_selector(unsigned char);
extern void UsbModeSelectRoutine(int);
extern void sys_api_set_channel_source_enable(int, int);
extern void sys_poll_events_stub_copy8(int);
extern void sys_end_logo_restore_picture(void);
extern void sys_set_key_blocked(int, int);
extern void sys_api_clear_all_channels_flag25(void);
extern void gpio_set_port4_bit7_low_if_allowed(void);
extern void gpio_set_port4_bit4_high_if_allowed(void);
extern void gpio_user_set_port2_bit2(void);
extern void panel_cycle_burnin_colour(void);
extern void SetBrightness(int);
extern void audio_user_apply_level(void);
extern void audio_unmute_outputs(void);
extern void gpio_set_port7_bit2_high(void);
extern void gpio_set_port5_bit7_high(void);
extern void gpio_set_aux_bit5_high(void);
extern void sys_frc_set_channel_bit_triple(unsigned char, int);
extern void sys_frc_set_channel_enable(unsigned char, int);
extern void gpio_set_port2_bit2_low(void);
extern void osd_draw_signal_message(int);
extern void osd_set_menu_state(int);
extern void uart_cmd_poll_port2(int);
extern void pq_detect_ch1_input_change(int);
extern void sys_user_reset_display_path(void);
extern void hdmi_cec_api_copy_message(void *);
extern int input_resend_link_bytes_on_pin_change(int);
extern int uart_cmd_run_tool_task(int);

/*
 * The application's timer task (APPTimerRoutine): the checks and jobs that run on every pass of the main loop,
 * most of them paced by the application timers. Called once per pass by sys_run_app_main_task, after the
 * event pump and the periodic menu task. It takes no arguments and returns nothing.
 *
 * The phases, in order:
 *   1. OLED panel signals (only while pin 5 of GPIO port 13 reads high):
 *      - pin 7 of port 13 not low: print "IsOLED_ACPowerDet = true -> AC_DET low", switch the panel off and
 *        stop in an endless loop;
 *      - pin 2 of port 10 high: print "IsOLED_ERRDetection = true -> DC off", read register 0x10 of the OLED
 *        controller, store the first detection after start-up in the factory record, and, outside factory
 *        mode and with a register value other than 0, switch the panel off and power the monitor off.
 *   2. "Vx1 is abnormal": printed when channel 0 is in its last state (12), the panel is on, the V-by-One
 *      status does not read 4 (panel_vx1_is_locked) and the OLED power state machine is idle. Nothing else
 *      is done.
 *   3. The OLED refresh-rate task and the OLED power state machine run once.
 *   4. Fake sleep: while the OLED power record's fake_sleep is 1, count minutes up to 10; at minute 10 the
 *      "10min led and offrs start" step asks the OLED power machine for a forced sensing run followed by power
 *      saving, and ends the fake sleep.
 *   5. "escape fake sleep when monitor don't enter sensing": fake sleep with channel 0 past code 5 and the
 *      OLED power machine idle: stop off sensing, switch the panel off and clear the fake-sleep fields.
 *   6. Every 20 s while the sleep state is 0: query the LED light bar.
 *   7. PIP/PBP is switched off ("diable pip mode") when channel 0 is past code 8 with a picture state other
 *      than 0, or channel 1 is past code 8 on a port with flag 6 or flag 9.
 *   8. CEC commands, when settings_page_flags bit 20 is set, PIP/PBP is off and the OLED machine is idle:
 *      power on, power off, change of input source, vendor ID and source name. Otherwise the command is read
 *      and dropped.
 *   9. Once a second: the save requests of app_flags_second.
 *  10. USB upstream port choice (UsbModeSelectRoutine).
 *  11. End of the CEC source hold; Optix Scope enables channel 1's source; the minute and hour count of the
 *      factory record while gpio_is_aux_bit0_high answers 1, which it never does (it reads GPIO port number
 *      0xFF, which gpio_read_pin does not serve); end of the USB hub power-on wait.
 *  12. One of three, by priority: the end of the logo hold; the DELAYED_ALL chain; the DELAYED_ALL_INACTIVE
 *      chain. In burn-in mode a chain steps the burn-in test colours. Otherwise, each time APP_TIMER_B runs
 *      out, the first step that applies: "No Signal" in place of the input quick menu (3 s); byte +7 bit 5
 *      of the state record: panel off (5 s); fake sleep (gaming flag bit 15 or "PHY CTS AUTO"); power saving.
 *  13. The colour cycle watch, the PC tool's command task on port 4 and the command receiver on port 2.
 *  14. In PBP with layout 0: every 200 ms check channel 1's input for a size change while it shows port code
 *      0xD.
 *
 * Both delayed-all chains clear APP_PORT_FLAG_DELAYED_ALL (bit 4) when they enter power saving; the
 * DELAYED_ALL_INACTIVE bit is not cleared here. Phase 1 can stop the main loop for good, and several steps
 * wait for the panel power sequencer (SYSAPI_PanelOnOffControl with WAIT_DONE).
 */
void sys_run_app_timer_task(void)
{
  unsigned char cec_command;
  unsigned char cec_source;
  unsigned short oled_error;

  /* 1. OLED panel signals. */
  if (gpio_is_port13_bit5_high() == 1)
  {
    if (!gpio_is_port13_bit7_low())
    {
      dbg_printf("IsOLED_ACPowerDet = true -> AC_DET low\r\n");
      SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
      /* Endless loop: nothing after this runs. */
      for (;;)
      {
        ;
      }

    }
    if ((gpio_is_port10_bit2_high() == 1) && (user_settings.factory_mode_marker != FACTORY_MODE_MARKER))
    {
      dbg_printf("IsOLED_ERRDetection = true -> DC off\r\n");
      oled_error = oled_read_reg_10();
      /* Only the first detection after start-up is counted and saved. */
      if (sys_oled_error_stored == 0)
      {
        sys_oled_error_stored = 1;
        factory_record.byte_0x15++;
        factory_record.half_0x16 = oled_error;
        SYSAPI_WriteEEPROM(EEPROM_AREA, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
      }
      if (oled_error != 0)
      {
        dbg_printf("err = %d\r\n", oled_error);
        panel_request_power(0);
        power_enter_app_state(APP_POWER_OFF);
      }
    }
    else
      if ((gpio_is_port10_bit2_high() == 1) && (user_settings.factory_mode_marker == FACTORY_MODE_MARKER))
    {
      /* Factory mode: the detection is stored the same way, but the monitor stays on. */
      dbg_printf("IsOLED_ERRDetection = true -> DC off (ProductMode)\r\n");
      oled_error = oled_read_reg_10();
      if (sys_oled_error_stored == 0)
      {
        factory_record.half_0x16 = oled_error;
        sys_oled_error_stored = 1;
        factory_record.byte_0x15++;
        SYSAPI_WriteEEPROM(EEPROM_AREA, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
      }
    }
  }
  /* 2. V-by-One check: a message only. */
  if ((((((sys_get_channel_state(MAIN_CHANNEL) == CHANNEL_STATE_LAST) && panel_is_power_on_done()) && (!panel_vx1_is_locked())) && (!oled_power_get_state())) && (!oled_power_get_step())) && (!oled_power_get_field_0c()))
  {
    dbg_printf("Vx1 is abnormal %d\r\n", 0);
  }
  /* 3. The OLED tasks. */
  oled_frc_task();
  oled_power_task();
  /* 4. Fake sleep minute count (OLED power record: fake_sleep = field +0x12, byte_0x11 = field +0x11). */
  if (oled_power_get_field_12() == 1)
  {
    if (oled_power_get_field_11() != RUN_END_POWER_SAVING_OR_OFF)
    {
      if (sys_fake_sleep_minutes == FAKE_SLEEP_NOT_COUNTING)
      {
        dbg_printf("fake sleep count start\r\n");
        sys_fake_sleep_minutes = 0;
        sys_app_timer_start(APP_TIMER_FAKE_SLEEP_MINUTE, MINUTE_MS);
      }
      else
      {
        if ((sys_app_timer_read(APP_TIMER_FAKE_SLEEP_MINUTE) == 0) && (sys_fake_sleep_minutes <= 9))
        {
          sys_fake_sleep_minutes = sys_fake_sleep_minutes + 1;
          dbg_printf("fake sleep count min = %d\r\n", sys_fake_sleep_minutes);
          sys_app_timer_start(APP_TIMER_FAKE_SLEEP_MINUTE, MINUTE_MS);
        }
        if ((sys_fake_sleep_minutes == FAKE_SLEEP_LAST_MINUTE) && (sys_fake_sleep_led_flag == FAKE_SLEEP_NOT_COUNTING))
        {
          /* Once, at minute 10: panel on, then a forced sensing run of the OLED power machine with power
             saving after it (after_sensing, sensing_requested, forced_sensing). */
          dbg_printf("10min led and offrs start\r\n");
          gpio_set_port4_bit4_low_if_allowed();
          sys_fake_sleep_led_flag = 0;
          oled_power_set_field_0f(AFTER_SENSING_POWER_SAVING);
          SYSAPI_PanelOnOffControl(PANEL_ON, WAIT_DONE);
          oled_power_set_field_09(1);
          oled_power_set_field_0a(1);
          oled_power_task();
          oled_power_set_field_11(1);
          oled_power_set_field_12(0);
          sys_api_set_all_channels_flag25();
        }
      }
    }
  }
  else
  {
    sys_fake_sleep_minutes = FAKE_SLEEP_NOT_COUNTING;
    sys_fake_sleep_led_flag = FAKE_SLEEP_NOT_COUNTING;
  }
  /* 5. Leave fake sleep when channel 0 comes up and no sensing run has started. */
  if ((((oled_power_get_field_12() == 1) && (sys_api_get_channel_state_code(MAIN_CHANNEL) > CHANNEL_CODE_5)) && (!oled_power_get_state())) && (!oled_power_get_step()))
  {
    dbg_printf("escape fake sleep when monitor don't enter sensing\r\n");
    oled_set_off_sensing(0);
    SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
    oled_power_set_field_12(0);
    oled_power_set_field_0d(0);
    oled_power_set_field_0c(0);
    gpio_set_port4_bit4_low_if_allowed();
    gpio_set_port4_bit7_high_if_allowed();
  }
  /* 6. LED light bar query. */
  if ((app_state_record.sleep.sleep_state == SLEEP_STATE_AWAKE) && (sys_app_timer_read(APP_TIMER_LED_BAR_QUERY) == 0))
  {
    sys_led_bar_send_query();
    sys_app_timer_start(APP_TIMER_LED_BAR_QUERY, LED_BAR_QUERY_MS);
  }
  /* 7. Switch PIP/PBP off when channel 0 is past code 8 with a picture state other than 0, or channel 1 is
        past code 8 on a port with flag 6 or flag 9. */
  if ((user_settings.pip_pbp_mode != 0) && (((sys_api_get_channel_state_code(MAIN_CHANNEL) > CHANNEL_CODE_8) && (sys_user_get_picture_state() != 0)) || ((sys_api_get_channel_state_code(SECOND_CHANNEL) > CHANNEL_CODE_8) && ((sys_api_get_channel_port_flag6(SECOND_CHANNEL) == 1) || (sys_api_get_channel_port_flag9(SECOND_CHANNEL) == 1)))))
  {
    user_settings.pip_pbp_mode = 0;
    panel_user_set_output_on(0);
    sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
    sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
    osd_close_menu();
    dbg_printf("diable pip mode\r\n");
    UserSetPIPMode();
  }
  /* 8. CEC commands. */
  if ((((user_settings.settings_page_flags & SETTINGS_PAGE_FLAG_BIT20) && (user_settings.pip_pbp_mode == 0)) && (!oled_power_get_state())) && (!oled_power_get_step()))
  {
    cec_command = hdmi_cec_api_get_command();
    if (cec_command != CEC_CMD_NONE)
    {
      dbg_printf("SYSAPI_CECGetCmd() = %d \r\n", cec_command);
    }
    switch (cec_command)
    {
      case CEC_CMD_FLAG0:
        if (!device_settings.power_status)
      {
        power_enter_app_state(APP_POWER_ON);
      }
        break;

      case CEC_CMD_MSG_36:
        /* Power off, unless the input of channel 0 translates to a source id other than 0. */
        if (device_settings.power_status && (!input_api_source_id_to_menu_index(input_api_get_channel_port_code(MAIN_CHANNEL))))
      {
        power_enter_app_state(APP_POWER_OFF);
      }
        break;

      case CEC_CMD_ACTIVATE_SOURCE:
        dbg_printf("_SYS_CECRequest_ActivateSC %02x %02x\r\n", hdmi_cec_api_get_sender(), user_settings.input_source);
        /* The sender byte chooses one of four input sources; any other value takes the first. */
        if (hdmi_cec_api_get_sender() == CEC_SENDER_1)
      {
        cec_source = CEC_SOURCE_1;
      }
      else
        if (hdmi_cec_api_get_sender() == CEC_SENDER_2)
      {
        cec_source = CEC_SOURCE_2;
      }
      else
        if (hdmi_cec_api_get_sender() == CEC_SENDER_3)
      {
        cec_source = CEC_SOURCE_3;
      }
      else
      {
        cec_source = (hdmi_cec_api_get_sender() == CEC_SENDER_4) ? (CEC_SOURCE_4) : (CEC_SOURCE_1);
      }
        if (!device_settings.power_status)
      {
        /* Powered off: power on, then switch to the requested source. */
        power_enter_app_state(APP_POWER_ON);
        if ((user_settings.input_source != cec_source) && ((user_settings.pip_pbp_mode == 0) || (user_settings.second_source != cec_source)))
        {
          user_settings.input_source = cec_source;
          sys_user_reset_display_path();
          app_state_record.half_0x0 |= APP_STATE_BIT10;
        }
      }
      else
      {
        /* Powered on: ignored while the hold is set (5 s, set by the screen size, DSC and Adaptive-Sync
           settings when they restart the channels). */
        if (app_state_record.half_0xa & APP_STATE_CEC_SOURCE_HOLD)
        {
          break;
        }
        if ((user_settings.input_source != cec_source) && ((user_settings.pip_pbp_mode == 0) || (user_settings.second_source != cec_source)))
        {
          user_settings.input_source = cec_source;
          sys_user_reset_display_path();
          app_state_record.half_0x0 |= APP_STATE_BIT10;
        }
      }
        break;

      case CEC_CMD_MSG_44_OP40:
        power_enter_app_state(APP_POWER_OFF);
        /* No break: the vendor ID bytes are taken as well. */

      case CEC_CMD_VENDOR_ID:
        dbg_printf("_SYS_CECRequest_VendorID!!\r\n");
        hdmi_cec_vendor_id_bytes[0] = hdmi_cec_api_get_message_word();
        hdmi_cec_vendor_id_bytes[1] = (hdmi_cec_api_get_message_word() & 0xffff) >> 8;
        hdmi_cec_vendor_id_bytes[2] = hdmi_cec_api_get_message_word() >> 16;
        hdmi_cec_vendor_id_bytes[3] = hdmi_cec_api_get_message_word() >> 24;
        break;

      case CEC_CMD_MSG_47:
        hdmi_cec_api_copy_message(hdmi_cec_source_name);
        break;

    }

  }
  else
  {
    /* The receive step still runs; its command is dropped. */
    hdmi_cec_api_get_command();
  }
  /* 9. Save requests, once a second. */
  if (sys_app_timer_read(APP_TIMER_SAVE_REQUESTS) == 0)
  {
    sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
    if (app_flags_second & APP_FLAG44_STORE_MODES_2)
    {
      nvram_api_store_by_selector(2);
    }
    if (app_flags_second & APP_FLAG44_SAVE_SETTINGS)
    {
      SYSAPI_WriteEEPROM(EEPROM_AREA, &user_settings, USER_SETTINGS_OFFSET, USER_SETTINGS_SIZE);
    }
    if (app_flags_second & APP_FLAG44_STORE_MODES_0)
    {
      nvram_api_store_by_selector(0);
    }
    if (app_flags_second & APP_FLAG44_STORE_MODES_1)
    {
      nvram_api_store_by_selector(1);
    }
    app_flags_second = 0;
  }
  /* 10. USB upstream port. */
  UsbModeSelectRoutine(0);
  /* 11. End of the CEC source hold. */
  if ((sys_app_timer_read(APP_TIMER_CEC_SOURCE_HOLD) == 0) && (app_state_record.half_0xa & APP_STATE_CEC_SOURCE_HOLD))
  {
    app_state_record.half_0xa &= ~APP_STATE_CEC_SOURCE_HOLD;
  }
  /* Optix Scope with one picture: once both channels are in their last state, enable channel 1's source. */
  if (((((user_settings.optix_scope != 0) && (sys_user_get_picture_state() == 0)) && (user_settings.pip_pbp_mode == 0)) && (sys_api_get_channel_state_code(MAIN_CHANNEL) == CHANNEL_CODE_LAST)) && (sys_api_get_channel_state_code(SECOND_CHANNEL) == CHANNEL_CODE_LAST))
  {
    sys_api_set_channel_source_enable(SECOND_CHANNEL, 1);
  }
  /* Minutes and hours while gpio_is_aux_bit0_high answers 1: three 20 s steps make a minute (factory record
     +0x11, 0..59), sixty minutes an hour (+0x12), and the record is saved once an hour. The read is of GPIO
     port number 0xFF and always gives 0, so this block does not run. */
  if ((sys_app_timer_read(APP_TIMER_AUX0_TIME) == 0) && gpio_is_aux_bit0_high())
  {
    sys_app_timer_start(APP_TIMER_AUX0_TIME, AUX0_TIME_STEP_MS);
    if (((unsigned char) (sys_aux0_time_step_count + 1)) > AUX0_TIME_STEPS_PER_MINUTE)
    {
      sys_aux0_time_step_count = 1;
      if (((unsigned char) (factory_record.panel_error_count + 1)) > (MINUTES_PER_HOUR - 1))
      {
        factory_record.panel_error_count = 0;
        if (factory_record.check_status != 0xffff)
        {
          factory_record.check_status++;
          SYSAPI_WriteEEPROM(EEPROM_AREA, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
        }
      }
      else
      {
        factory_record.panel_error_count = factory_record.panel_error_count + 1;
      }
    }
    else
    {
      sys_aux0_time_step_count = sys_aux0_time_step_count + 1;
    }
  }
  /* End of the USB hub power-on wait; the routine called then does nothing. */
  if ((sys_app_timer_read(APP_TIMER_USB_HUB_POWER_ON) == 0) && (app_state_record.sleep_word & SLEEP_WORD_USB_HUB_POWER_ON))
  {
    app_state_record.sleep_word &= ~SLEEP_WORD_USB_HUB_POWER_ON;
    sys_poll_events_stub_copy8(1);
  }
  /* 12. Logo hold first; else one of the two delayed-all chains. */
  if (app_flags & APP_FLAG_LOGO_HOLD)
  {
    /* 3 s after the logo: restore the picture and free the keys. */
    if (sys_app_timer_read(APP_TIMER_LOGO_HOLD) == 0)
    {
      sys_end_logo_restore_picture();
      sys_set_key_blocked(KEY_ID_ALL, 0);
      app_flags &= ~APP_FLAG_LOGO_HOLD;
      sys_api_clear_all_channels_flag25();
    }
  }
  else
    if (app_port_flags & APP_PORT_FLAG_DELAYED_ALL)
  {
    if (user_settings.burn_in_flag != 0)
    {
      /* Burn-in: one test colour per second. */
      if (sys_app_timer_read(APP_TIMER_B) == 0)
      {
        gpio_set_port4_bit7_low_if_allowed();
        gpio_set_port4_bit4_high_if_allowed();
        user_settings.gaming_flags |= GAMING_FLAG_BIT6;
        gpio_user_set_port2_bit2();
        panel_cycle_burnin_colour();
        sys_set_key_blocked(KEY_ID_ALL, 0);
        /* First step only: full brightness, and the pressed-key bit is cleared. */
        if (!(app_state_record.sleep_word & SLEEP_WORD_BURNIN_STARTED))
        {
          SetBrightness(LEVEL_MAX);
          app_state_record.sleep_word |= SLEEP_WORD_BURNIN_STARTED;
          *((unsigned char *) (&app_state_record.half_0x6)) = 0;
        }
        sys_app_timer_start(APP_TIMER_B, 1000);
      }
    }
    else
      if (sys_app_timer_read(APP_TIMER_B) == 0)
    {
      if (((sys_api_get_channel_state_code(MAIN_CHANNEL) != CHANNEL_CODE_LAST) && (!(user_settings.word_0x0 & SETTINGS_WORD0_BIT9))) && (osd_get_menu_state() == MENU_STATE_INPUT_QUICK_MENU))
      {
        /* No picture and the input quick menu open: replace it by the "No Signal" message for 3 s. */
        osd_draw_signal_message(SIGNAL_MESSAGE_NO_SIGNAL);
        osd_set_menu_state(MENU_STATE_CLOSED);
        sys_app_timer_start(APP_TIMER_B, 3000);
      }
      else
        if (app_state_record.half_0x6 & HALF6_BIT5)
      {
        app_state_record.half_0x6 = (app_state_record.half_0x6 & (~HALF6_BIT5)) | HALF6_BIT4;
        sys_app_timer_start(APP_TIMER_B, 5000);
        gpio_set_port4_bit7_low_if_allowed();
        gpio_set_port4_bit4_high_if_allowed();
        gpio_set_port2_bit2_low();
        SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
      }
      else
        if ((user_settings.gaming_flags & GAMING_FLAG_BIT15) || (nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO) == 1))
      {
        /* Fake sleep instead of power saving: panel off, and a power-down request with power saving after it
           to the OLED power machine when it is idle. */
        if (app_state_record.sleep.sleep_state == SLEEP_STATE_AWAKE)
        {
          app_state_record.sleep.sleep_state = SLEEP_STATE_FAKE_SLEEP;
          gpio_set_port4_bit7_low_if_allowed();
          gpio_set_port4_bit4_high_if_allowed();
          gpio_set_port2_bit2_low();
          osd_close_menu();
          SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
          if ((!oled_power_get_state()) && (!oled_power_get_step()))
          {
            oled_power_set_field_0d(1);
            oled_power_set_field_0f(AFTER_SENSING_POWER_SAVING);
          }
          oled_power_task();
          sys_app_timer_start(APP_TIMER_B, 1000);
        }
        else
          sys_app_timer_start(APP_TIMER_B, 1000);
      }
      else
      {
        dbg_printf("1.APPTimerRoutine->Enter Power Saving State\n\r");
        power_enter_app_state(APP_POWER_SAVING);
        app_port_flags &= ~APP_PORT_FLAG_DELAYED_ALL;
      }
    }
  }
  else
    if (app_port_flags & APP_PORT_FLAG_DELAYED_ALL_INACTIVE)
  {
    if (user_settings.burn_in_flag != 0)
    {
      /* Burn-in: one test colour per step while the OLED machine is idle and not in fake sleep; the step pace
         follows burn_in_flag (1: 1 s, 2: 1 s or 100 ms, 3: 1.5 s). */
      if (((((!oled_power_get_state()) && (!oled_power_get_step())) && (!((user_settings.gaming_flags & GAMING_FLAG_BIT15) && (app_state_record.sleep.sleep_state != SLEEP_STATE_AWAKE)))) && (sys_app_timer_read(APP_TIMER_B) == 0)) && (app_state_record.u014.bits.bit14 == 0))
      {
        gpio_set_port4_bit7_low_if_allowed();
        gpio_set_port4_bit4_high_if_allowed();
        user_settings.gaming_flags |= GAMING_FLAG_BIT6;
        gpio_user_set_port2_bit2();
        /* Factory mode: sound and three more pins on. */
        if (user_settings.factory_mode_marker == FACTORY_MODE_MARKER)
        {
          audio_user_apply_level();
          audio_unmute_outputs();
          gpio_set_port7_bit2_high();
          gpio_set_port5_bit7_high();
          gpio_set_aux_bit5_high();
        }
        sys_frc_set_channel_bit_triple(sys_get_channel_source_class(CHANNEL_3), 0);
        sys_frc_set_channel_enable(sys_get_channel_source_class(CHANNEL_3), 0);
        panel_cycle_burnin_colour();
        if (!(app_state_record.sleep_word & SLEEP_WORD_BURNIN_STARTED))
        {
          app_state_record.sleep_word |= SLEEP_WORD_BURNIN_STARTED;
        }
        if (user_settings.burn_in_flag == 1)
        {
          sys_app_timer_start(APP_TIMER_B, 1000);
        }
        else
          if (user_settings.burn_in_flag == 2)
        {
          if (DAT_a802af46 > 2)
          {
            sys_app_timer_start(APP_TIMER_B, 100);
          }
          else
          {
            sys_app_timer_start(APP_TIMER_B, 1000);
          }
        }
        else
          if (user_settings.burn_in_flag == 3)
        {
          sys_app_timer_start(APP_TIMER_B, 1500);
        }
      }
    }
    else
      if (sys_app_timer_read(APP_TIMER_B) == 0)
    {
      /* The same steps as the DELAYED_ALL chain; this one also closes the menu before the panel goes off. */
      if (((sys_api_get_channel_state_code(MAIN_CHANNEL) != CHANNEL_CODE_LAST) && (!(user_settings.word_0x0 & SETTINGS_WORD0_BIT9))) && (osd_get_menu_state() == MENU_STATE_INPUT_QUICK_MENU))
      {
        osd_draw_signal_message(SIGNAL_MESSAGE_NO_SIGNAL);
        osd_set_menu_state(MENU_STATE_CLOSED);
        sys_app_timer_start(APP_TIMER_B, 3000);
      }
      else
        if ((app_state_record.half_0x6 & HALF6_BIT5))
      {
        app_state_record.half_0x6 = (app_state_record.half_0x6 & (~HALF6_BIT5)) | HALF6_BIT4;
        sys_app_timer_start(APP_TIMER_B, 5000);
        gpio_set_port4_bit7_low_if_allowed();
        gpio_set_port4_bit4_high_if_allowed();
        gpio_set_port2_bit2_low();
        osd_close_menu();
        SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
      }
        else
      {
        if ((user_settings.gaming_flags & GAMING_FLAG_BIT15) || (nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO) == 1))
        {
          if (app_state_record.sleep.sleep_state == SLEEP_STATE_AWAKE)
          {
            app_state_record.sleep.sleep_state = SLEEP_STATE_FAKE_SLEEP;
            gpio_set_port4_bit7_low_if_allowed();
            gpio_set_port4_bit4_high_if_allowed();
            gpio_set_port2_bit2_low();
            osd_close_menu();
            SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
            if ((!oled_power_get_state()) && (!oled_power_get_step()))
            {
              oled_power_set_field_0d(1);
              oled_power_set_field_0f(AFTER_SENSING_POWER_SAVING);
            }
            oled_power_task();
          }
          sys_app_timer_start(APP_TIMER_B, 1000);
        }
        else
        {
          dbg_printf("2.APPTimerRoutine->Enter Power Saving State\n\r");
          power_enter_app_state(APP_POWER_SAVING);
          /* The firmware clears the DELAYED_ALL bit here too, not the DELAYED_ALL_INACTIVE bit. */
          app_port_flags &= ~APP_PORT_FLAG_DELAYED_ALL;
        }
      }
    }
  }
  /* 13. Colour cycle watch, PC tool commands (port 4), commands on port 2. */
  uart_cmd_poll_port2(uart_cmd_run_tool_task(input_resend_link_bytes_on_pin_change(0)));
  /* 14. PBP, layout 0: watch channel 1's input size. */
  if (((((user_settings.pip_pbp_mode == 2) && (user_settings.pbp_layout == 0)) && (sys_api_get_channel_state_code(SECOND_CHANNEL) > CHANNEL_CODE_7)) && (input_api_get_channel_port_code(SECOND_CHANNEL) == PBP_PORT_CODE_D)) && (sys_app_timer_read(APP_TIMER_PBP_INPUT_CHECK) == 0))
  {
    pq_detect_ch1_input_change(0);
    sys_app_timer_start(APP_TIMER_PBP_INPUT_CHECK, PBP_INPUT_CHECK_MS);
  }
}
