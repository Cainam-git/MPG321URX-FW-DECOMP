/* App_Initialize  (FUN_a0086ae8)
 *
 * Switch the power pins on in the order for the power-on type and initialise the modules.
 *   type: power-on type
 * Note: Type 4 switches the EDID, services the ports and calls APPSetPowerOff(1) in place of the power-pin
 *   sequence; the stored settings are applied afterwards as for every type.
 * Name basis: proven - prints 'App_Initialize %02x' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0086ae8 @ 0xA0086AE8..0xA0087020 (334 words) "App_Initialize", flags -mcpu=v8 -O3 -g
 * (-msoft-float gives the same code).
 * Source forms the exact build depends on:
 *  - the CEC test near the end is written
 *      if (cec_on) { if (pip_pbp_mode == 0) send_action(4); set_port_signal(ALL_PORTS, 1); }
 *      else set_port_signal(ALL_PORTS, 1);
 *    The two input_api_set_port_signal calls are merged by cross-jumping after branch prediction. At prediction
 *    time the else arm ends in a block that holds a call, so the call heuristic predicts the bit set (70 %); the
 *    send_action(4) block then gets the frequency that makes block reordering place it right after the type-4
 *    head and before the APPSetPowerOff block, the type-4 pin block and the type-1 block, as in the firmware
 *    (0xA0086EE0 type-4 head, 0xA0086F0C APPSetPowerOff(1), 0xA0086F1C send_action(4), 0xA0086F2C pins,
 *    0xA0086F50 type 1). A plain 'if (cec_on && pip_pbp_mode == 0)' gives another block order;
 *  - the type-2 input source choice with the two gotos (common / tail), each path with its own copy of the
 *    display path restart;
 *  - the factory branches as two 'else if' tests, each comparing factory_marker again.
 */

/* Power-on types passed in by App_CoolInitialize (it maps the types of SYSAPI_GetPowerOnType onto these). */
enum {
    START_NORMAL     = 0,   /* every other power-on type */
    START_POWER_ON   = 1,   /* stores the power status 1 and sends two CEC messages */
    START_WAKE_UP    = 2,   /* the input source becomes the port that woke the monitor */
    START_TYPE_3     = 3,   /* as START_NORMAL, without pin 2.2 and the LED bar brightness */
    START_POWER_OFF  = 4    /* goes on to the power-off sequence (APPSetPowerOff) */
};

#define SOURCE_CODE_0C          0xc     /* the two source codes given to dp_api_set_dsc_support; it acts only */
#define SOURCE_CODE_0D          0xd     /*   when the code belongs to a DisplayPort-class port (0x71 / 0x81) */
#define PORT_NONE               0xff    /* power_api_get_wake_up_port: no wake-up port */
#define ALL_PORTS               0xfe    /* input_api_set_port_signal: every input slot */
#define KEY_ID_ALL              0xff    /* key routines: every key */
#define POWER_PIN_SETTLE_TICKS  0x32    /* wait between two power pins */

/* CEC actions of hdmi_cec_api_send_action. */
#define CEC_ACTION_MESSAGE_SECOND   2   /* hdmi_cec_send_message_second */
#define CEC_ACTION_MESSAGE_THIRD    3   /* hdmi_cec_send_message_third */
#define CEC_ACTION_4                4   /* no case in hdmi_cec_api_send_action: sends nothing */

#define GAMING_FLAG_BIT7              0x80        /* user settings +0xA8 bit 7 (Adaptive-Sync in the record notes) */
#define SETTINGS_POWER_BUTTON_STANDBY 0x8000      /* user settings +0xA8 bit 15: Power Button set to Standby */
#define SETTINGS_HDMI_CEC_ON          0x100000    /* user settings +0xAC bit 20: HDMI CEC switch */
#define SETTINGS_WORD0_BIT9           0x200       /* user settings word +0, bit 9 */
#define FACTORY_MODE_MARKER           0x55aa      /* user settings +0x1F6 while factory mode is on */
#define FACTORY_STATUS_0x55           0x55        /* values of settings byte +0x1D6 (factory tool status 2) */
#define FACTORY_STATUS_0xAA           0xaa
#define SCREEN_SIZE_FACTORY           2           /* Screen Size value set in factory mode */
#define APP_STATE_BIT10               0x400       /* app_state_record half_0x0 bit 10 */
#define NOTICE_ORIGIN_DONE            9           /* app_state_record +0xA */
#define APP_STATE_HALF_0xA_BIT7       0x80

struct user_settings_record
{
  unsigned int word_0x0;                    /* +0x000: SETTINGS_WORD0_* */
  unsigned char p004[0x1a];
  unsigned char input_source;               /* +0x01E Input Source (menu index) */
  unsigned char pip_pbp_mode;               /* +0x01F 0 off, 1 PIP, 2 PBP */
  unsigned char p020[0x88];
  unsigned int gaming_flags;                /* +0x0A8 */
  union
  {
    unsigned int settings_page_flags;       /* +0x0AC SETTINGS_HDMI_CEC_ON */
    unsigned char byte_0xac;                /* +0x0AC top byte: passed as the LED bar brightness */
  };
  unsigned char p0b0[0xf4];
  unsigned char screen_size;                /* +0x1A4 Screen Size */
  unsigned char p1a5[0x30];
  unsigned char burn_in_flag;               /* +0x1D5 burn-in mode on (1) or off (0) */
  unsigned char byte_0x1d6;                 /* +0x1D6 factory tool status 2 */
  unsigned char p1d7[0x1f];
  unsigned short factory_marker;            /* +0x1F6 FACTORY_MODE_MARKER while factory mode is on */
};
struct app_state_record
{
  unsigned short half_0x0;                  /* +0x00: APP_STATE_BIT10 */
  unsigned char p002[8];
  union
  {
    unsigned short half_0xa;                /* +0x0A */
    unsigned char notice_origin;            /* +0x0A high byte */
  };
  unsigned char p00c[0xe];
  unsigned short power_on_ticks;            /* +0x1A tick count when the type-1 power pins were on */
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern int dbg_printf(const char *, ...);
extern void pq_api_enable_color_matrix(int, int);
extern void pq_api_set_color_matrix_option(int);
extern void dp_api_set_dsc_support(int, int);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void gpio_set_port4_bit7_high_if_allowed(void);
extern void SYSAPI_SetPowerStatus(int);
extern void nvram_api_store_by_selector(unsigned char);
extern void hdmi_cec_api_send_action(int);
extern void gpio_set_port7_bit2_high(void);
extern void gpio_set_port6_bit2_high(void);
extern void gpio_user_set_port7_bit1(int);
extern void gpio_set_aux_bit6_low(void);
extern void gpio_set_aux_bit6_high(void);
extern void sys_poll_events_stub_copy11(void);
extern void gpio_set_port5_bit7_high(void);
extern void gpio_set_aux_bit5_high(void);
extern void gpio_set_port12_bit0_high(void);
extern void timer_sleep_ticks(int);
extern unsigned short timer_get_ticks16(void);
extern void UserSwitchEDID(int, int);
extern void sys_service_ports_by_mask(int);
extern void APPSetPowerOff(int);
extern void osd_user_apply_transparency(void);
extern void osd_user_apply_menu_timeout(void);
extern void pq_user_apply_mode_colors(void);
extern void pq_user_apply_custom_red(void);
extern void pq_user_apply_custom_green(void);
extern void pq_user_set_custom_blue(void);
extern unsigned char sys_is_logo_hold(void);
extern void sys_user_apply_brightness(void);
extern void pq_user_apply_color_gain(void);
extern void pq_user_apply_color_settings(void);
extern void pq_user_apply_gamma(void);
extern void sys_user_apply_channel0_scaling_mode(void);
extern void sys_user_apply_channel1_scaling_mode(void);
extern void audio_api_set_level_percent(int);
extern void gpio_user_set_port2_bit2(void);
extern void UserSetAuroraLEDBarBrightness(unsigned char);
extern void sys_api_set_config_bit31(int);
extern unsigned char input_api_menu_index_to_source_id(int);
extern void sys_user_reset_display_path(void);
extern void input_rearm_port_event(int, int);
extern void sys_user_apply_config_bit31(void);
extern void pq_user_reset_response_level(void);
extern void osd_user_apply_menu_position(void);
extern void osd_set_layout(int);
extern void sys_user_apply_pip_sources(int);
extern unsigned char power_api_get_wake_up_port(void);
extern void UserSetPIPMode(void);
extern void sys_set_key_repeat(int, int);
extern void sys_set_key_long_press(int, int);
extern void sys_set_key_long_press_alt(int, int);
extern void sys_set_key_repeat_delay(int);
extern void sys_set_key_repeat_interval(int);
extern void sys_set_key_long_press_time(int);
extern void input_api_set_port_signal(int, int);
extern void sys_user_apply_input_link_settings(int);
extern void sys_api_set_port0_value_and_stamp(int);
extern void sys_user_apply_config_bit25(void);
extern void input_resend_link_bytes_on_pin_change(int);
extern void sys_set_five_block_bits(void);

/*
 * Start the application part of the main program: power pins, stored settings, input source and keys.
 *
 *   type  START_*: how the monitor came up; App_CoolInitialize (start-up step 3) calls this once with it.
 *
 * Phases:
 *   1. Colour matrix off, print the type, pass settings +0xA8 bit 7 to dp_api_set_dsc_support for the
 *      sources 0x0C and 0x0D.
 *   2. Power pins, by type:
 *      START_POWER_ON  - pins 4.4 low and 4.7 high (when allowed), store power status 1 and the channel modes,
 *                        two CEC messages (CEC on and one picture), then the power pins with two waits of
 *                        POWER_PIN_SETTLE_TICKS, and note the tick count;
 *      START_POWER_OFF - load EDID variant 2, service the port groups 4 and 8, switch four power pins on when
 *                        Power Button is set to Standby, then run the power-off sequence;
 *      every other     - the same pins as START_POWER_ON, without the power status, the CEC messages and the
 *                        first wait.
 *   3. Apply the stored settings: menu, colours, brightness and gamma (not while the logo is held), scaling,
 *      audio level; for types 0 and 1 also pin 2.2 and the LED bar brightness.
 *   4. Factory mode (marker 0x55AA) with status byte 0x55 or 0xAA: configuration bit 31 off and, with 0xAA or
 *      in burn-in mode, the input source of channel 0 and a display path restart. Otherwise configuration
 *      bit 31 from the settings.
 *   5. Response level, menu position and layout, the sources of the other pictures. START_WAKE_UP takes the
 *      wake-up port as the input source when there is one and settings word 0 bit 9 is set. Then the display
 *      path restarts and the PIP/PBP mode is applied (not while the logo is held).
 *   6. Key timing: no auto-repeat and no long press for any key; repeat delay 500, repeat interval 50,
 *      long-press time 2000.
 *   7. Every input slot on; the per-input link settings (not for START_POWER_OFF); the closing settings, then
 *      print the size of the settings record (0x1FC).
 *
 * Its own code has no loop; the waits are the two fixed POWER_PIN_SETTLE_TICKS sleeps.
 */
void App_Initialize(unsigned char type)
{
  /* 1. */
  pq_api_enable_color_matrix(0, 0);
  pq_api_set_color_matrix_option(1);
  dbg_printf("App_Initialize %02x\r\n", type);
  dp_api_set_dsc_support(SOURCE_CODE_0C, (user_settings.gaming_flags >> 7) & 1);
  dp_api_set_dsc_support(SOURCE_CODE_0D, (user_settings.gaming_flags >> 7) & 1);
  /* 2. Power pins in the order for the type. */
  if (type == START_POWER_ON)
    {
      gpio_set_port4_bit4_low_if_allowed();
      gpio_set_port4_bit7_high_if_allowed();
      SYSAPI_SetPowerStatus(1);
      nvram_api_store_by_selector(1);
      if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && user_settings.pip_pbp_mode == 0)
        {
          hdmi_cec_api_send_action(CEC_ACTION_MESSAGE_SECOND);
          hdmi_cec_api_send_action(CEC_ACTION_MESSAGE_THIRD);
        }
      gpio_set_port7_bit2_high();
      timer_sleep_ticks(POWER_PIN_SETTLE_TICKS);
      gpio_set_port6_bit2_high();
      gpio_user_set_port7_bit1(0);
      gpio_set_aux_bit6_low();
      timer_sleep_ticks(POWER_PIN_SETTLE_TICKS);
      gpio_set_aux_bit6_high();
      sys_poll_events_stub_copy11();        /* empty */
      gpio_set_port5_bit7_high();
      gpio_set_aux_bit5_high();
      gpio_set_port12_bit0_high();
      app_state_record.power_on_ticks = timer_get_ticks16();
    }
  else if (type == START_POWER_OFF)
    {
      UserSwitchEDID(2, 0);
      sys_service_ports_by_mask(4);
      sys_service_ports_by_mask(8);
      if (user_settings.gaming_flags & SETTINGS_POWER_BUTTON_STANDBY)
        {
          gpio_set_port7_bit2_high();
          gpio_set_port5_bit7_high();
          gpio_set_aux_bit5_high();
          gpio_set_port6_bit2_high();
        }
      APPSetPowerOff(1);
    }
  else
    {
      gpio_set_port4_bit4_low_if_allowed();
      gpio_set_port4_bit7_high_if_allowed();
      gpio_set_port7_bit2_high();
      gpio_set_port6_bit2_high();
      gpio_user_set_port7_bit1(0);
      gpio_set_aux_bit6_low();
      timer_sleep_ticks(POWER_PIN_SETTLE_TICKS);
      gpio_set_aux_bit6_high();
      sys_poll_events_stub_copy11();        /* empty */
      gpio_set_port5_bit7_high();
      gpio_set_aux_bit5_high();
      gpio_set_port12_bit0_high();
    }
  /* 3. Apply the stored settings. */
  if (user_settings.factory_marker == FACTORY_MODE_MARKER)
    user_settings.screen_size = SCREEN_SIZE_FACTORY;
  osd_user_apply_transparency();
  osd_user_apply_menu_timeout();
  pq_user_apply_mode_colors();
  pq_user_apply_custom_red();
  pq_user_apply_custom_green();
  pq_user_set_custom_blue();
  if (sys_is_logo_hold() == 0)
    {
      sys_user_apply_brightness();
      pq_user_apply_color_gain();
      pq_user_apply_color_settings();
      pq_user_apply_gamma();
    }
  sys_user_apply_channel0_scaling_mode();
  sys_user_apply_channel1_scaling_mode();
  audio_api_set_level_percent(1);
  if (type <= START_POWER_ON)
    {
      gpio_user_set_port2_bit2();
      UserSetAuroraLEDBarBrightness(user_settings.byte_0xac);
    }
  /* 4. Factory mode: the factory tool's status byte decides. */
  if (user_settings.factory_marker == FACTORY_MODE_MARKER && user_settings.byte_0x1d6 == FACTORY_STATUS_0x55)
    {
      sys_api_set_config_bit31(0);
      if (user_settings.burn_in_flag != 0)
        {
          user_settings.input_source = input_api_menu_index_to_source_id(0);
          sys_user_reset_display_path();
          app_state_record.half_0x0 |= APP_STATE_BIT10;
          input_rearm_port_event(0, 0);
        }
    }
  else if (user_settings.factory_marker == FACTORY_MODE_MARKER && user_settings.byte_0x1d6 == FACTORY_STATUS_0xAA)
    {
      user_settings.input_source = input_api_menu_index_to_source_id(0);
      sys_user_reset_display_path();
      app_state_record.half_0x0 |= APP_STATE_BIT10;
      input_rearm_port_event(0, 0);
      sys_api_set_config_bit31(0);
    }
  else
    sys_user_apply_config_bit31();
  /* 5. Menu, other pictures, input source and display path. */
  pq_user_reset_response_level();
  if (sys_is_logo_hold() == 0)
    {
      osd_user_apply_menu_position();
      osd_set_layout(1);
    }
  sys_user_apply_pip_sources(1);
  if (type == START_WAKE_UP)
    {
      /* The port that woke the monitor becomes the input source. */
      if (power_api_get_wake_up_port() != PORT_NONE)
        if (user_settings.word_0x0 & SETTINGS_WORD0_BIT9)
          {
            user_settings.input_source = power_api_get_wake_up_port();
            goto common;
          }
      dbg_printf("\033[1;31mSYSAPI_GetWakeUpPortName return _SYS_InputSource_NULL\r\n\033[m");
      sys_user_reset_display_path();
      if (sys_is_logo_hold() == 0)
        UserSetPIPMode();
      goto tail;
    }
 common:
  sys_user_reset_display_path();
  if (sys_is_logo_hold() == 0)
    UserSetPIPMode();
 tail:
  /* 6. Key timing. */
  sys_set_key_repeat(KEY_ID_ALL, 0);
  sys_set_key_long_press(KEY_ID_ALL, 0);
  sys_set_key_long_press_alt(KEY_ID_ALL, 0);
  sys_set_key_repeat_delay(500);
  sys_set_key_repeat_interval(0x32);
  sys_set_key_long_press_time(2000);
  /* 7. Inputs on and the closing settings. */
  if (user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON)
    {
      if (user_settings.pip_pbp_mode == 0)
        hdmi_cec_api_send_action(CEC_ACTION_4);
      input_api_set_port_signal(ALL_PORTS, 1);
    }
  else
    input_api_set_port_signal(ALL_PORTS, 1);
  if (type != START_POWER_OFF)
    sys_user_apply_input_link_settings(2);
  sys_api_set_port0_value_and_stamp(0x1964);
  sys_user_apply_config_bit25();
  input_resend_link_bytes_on_pin_change(1);
  app_state_record.notice_origin = NOTICE_ORIGIN_DONE;
  app_state_record.half_0xa &= ~APP_STATE_HALF_0xA_BIT7;
  sys_set_five_block_bits();
  dbg_printf("usUsrEnd %X\r\n", 0x1fc);
}
