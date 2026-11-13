/* APPSetPowerOff  (FUN_a0080490)
 *
 * Run the power-off sequence: off sensing, pin sequence and panel off.
 *   from_startup: 1 when called at start-up for power-on type 4
 * Name basis: proven - prints 'APPSetPowerOff' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0080490 @ 0xA0080490..0xA00808AC (263 words) "APPSetPowerOff", flags -mcpu=v8 -O3 -g
 * (-msoft-float gives the same code).
 * Source forms the exact build depends on:
 *  - the two printed OLED bytes are int locals (the firmware masks them at the call);
 *  - the 'blur_free_mode != 0' and 'from_startup == 0' tests are nested ifs (an '&&' becomes set-flag code);
 *  - the store to dialog_button_index (+0x3F) comes before the store to half_0xc;
 *  - the four 0xFF stores to hdmi_cec_vendor_id_bytes are written 3, 2, 1, 0.
 */

/* The fields of the user settings record (user_settings, docs/RECORDS.md) read here. */
struct user_settings_record
{
  unsigned int word_0x0;                        /* +0x00 */
  unsigned char p004[0x1b];
  unsigned char pip_pbp_mode;                   /* +0x1F 0 = PIP/PBP off */
  unsigned char p020[0x88];
  unsigned int gaming_flags;                    /* +0xA8 SETTINGS_POWER_BUTTON_STANDBY */
  unsigned int settings_page_flags;             /* +0xAC SETTINGS_HDMI_CEC_ON */
  unsigned int blur_free_mode;                  /* +0xB0 the blur reduction mode */
  unsigned char p0b4[0x142];
  unsigned short factory_marker;                /* +0x1F6 FACTORY_MODE_MARKER while factory mode is on */
};
/* The factory record (factory_record, 0x1C bytes, kept in the EEPROM at 0x2E0), up to the byte used here. */
struct factory_record_fields
{
  unsigned char p00[0x14];
  unsigned char byte_0x14;                      /* +0x14 */
};
/* The fields of the application state record (app_state_record) written here. */
struct app_state_record
{
  unsigned short half_0x0;
  unsigned short half_0x2;
  struct
  {
    unsigned short bit15 : 1;
    unsigned short sleep_state : 2;             /* bits 13..14: SLEEP_STATE_* */
    unsigned short low_bits : 13;
  } sleep_word;                                 /* +0x04 */
  unsigned char p006[6];
  unsigned short half_0xc;                      /* +0x0C */
  unsigned char p00e[0x30];
  union
  {
    unsigned short half_0x3e;                   /* +0x3E */
    struct
    {
      unsigned char byte_0x3e;
      unsigned char dialog_button_index;        /* +0x3F the selected button of a dialog or prompt */
    } bytes_0x3e;
  };
};
extern struct user_settings_record user_settings;
extern struct factory_record_fields factory_record;
extern struct app_state_record app_state_record;
extern unsigned char hdmi_cec_vendor_id_bytes[4];
extern int dbg_printf(const char *, ...);
extern void timer_api_get_ticks16(void);
extern unsigned char SYSAPI_GetPowerOnType(void);
extern unsigned char oled_power_get_field_12(void);
extern unsigned char oled_power_get_field_11(void);
extern unsigned char oled_power_get_field_10(void);
extern unsigned char oled_power_get_state(void);
extern unsigned char oled_power_get_step(void);
extern void osd_close_menu(void);
extern void sys_set_mode_byte_c9f8(int);
extern void gpio_set_port4_bit7_low_if_allowed(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void sys_user_apply_mode_byte(void);
extern void oled_power_set_field_12(int);
extern void oled_power_set_field_09(int);
extern void oled_power_set_field_0d(int);
extern void oled_power_set_field_0f(int);
extern void oled_power_task(void);
extern void SYSAPI_PanelOnOffControl(int, int);
extern void sys_api_set_all_channels_flag25(void);
extern void sys_restart_channel(int, int);
extern void gpio_set_aux_bit0_low(void);
extern void hdmi_cec_api_reset(void);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);
extern void ldc_api_set_dimming_mode(int);
extern void gpio_set_port7_bit2_low(void);
extern void gpio_set_port7_bit7_inverted(unsigned char);
extern void gpio_set_port5_bit7_low(void);
extern void gpio_set_aux_bit5_low(void);
extern void gpio_set_port2_bit2_low(void);
extern void gpio_set_aux_bit1_low(void);
extern void sys_set_key_blocked(int, int);
extern void SYSAPI_SetPowerStatus(int);
extern void sys_api_set_flag_e403(int);
extern void audio_api_set_mute(int);
extern void panel_api_set_blurfree_mode(int);
extern unsigned int oled_flag_registers_read(void);
extern void oled_flag_registers_write(unsigned int);
extern void input_api_select_ports(int, int);
extern void timer_sleep_ticks(int);
extern void gpio_set_aux_bit3_pattern(int);
extern void gpio_set_port6_bit2_low(void);
extern void gpio_set_port7_bit1_low(void);
extern void gpio_set_aux_bit6_low(void);
extern void sys_poll_events_stub_copy7(void);
extern void gpio_set_port12_bit0_low(void);
extern void panel_blurfree_apply_user_mode(int);
extern void SYSAPI_PowerOff(void);

#define POWER_ON_TYPE_4                4        /* SYSAPI_GetPowerOnType: the type for which App_Initialize calls
                                                   this routine with from_startup = 1 */
#define FACTORY_MODE_MARKER            0x55aa   /* user settings halfword +0x1F6 while factory mode is on */
#define SETTINGS_HDMI_CEC_ON           0x100000 /* settings word +0xAC bit 20: the HDMI CEC menu switch */
#define SETTINGS_POWER_BUTTON_STANDBY  0x8000   /* settings word +0xA8 bit 15: the Power Button menu choice,
                                                   0 = OFF, 1 = Standby */

/* OLED power state machine (oled_power_task): the state value and the after_sensing value used here. */
#define OLED_POWER_POWER_OFF           4        /* "start panel power off sequence" */
#define AFTER_SENSING_POWER_OFF        2        /* "Goto PowerOff" after a sensing run */

#define PANEL_OFF                      0        /* SYSAPI_PanelOnOffControl: first argument */
#define NO_WAIT                        0        /* SYSAPI_PanelOnOffControl: second argument */
#define WAIT_DONE                      1

#define SLEEP_STATE_DC_ON              1        /* the value power_enter_app_state takes as "dc on" */

#define EEPROM_AREA_CODE               0x30     /* first argument of SYSAPI_WriteEEPROM */
#define FACTORY_RECORD_EEPROM_OFFSET   0x2e0
#define FACTORY_RECORD_SIZE            0x1c

#define RETAINED_RUN_BITS_CLEAR        0xfedf   /* clears bits 5 and 8 (0x120) of the retention registers, the
                                                   bits oled_power_task sets while off sensing runs */

/*
 * Switch the monitor off, or first let the OLED panel care run an off sensing pass.
 *
 *   from_startup  1 when App_Initialize calls it at start-up for power-on type 4; 0 from power_enter_app_state
 *                 (state 0 "dc off" and state 1)
 *
 * Phases, in order:
 *   1. Common start: read the tick count (the value is dropped) and the power-on type; clear the selected dialog
 *      button and app state halfword +0xC.
 *   2. Off sensing (power-on type not 4, factory mode off, OLED fields +0x10 and +0x11/+0x12 as tested below):
 *      when the OLED power state machine is already busy, return at once. Otherwise close the menu, set the pin
 *      mode byte and drive pins 7 and 4 of port 4 low where allowed, ask the state machine for a sensing run followed by power off, and run it once. When it
 *      has started something, either switch the panel off without waiting ("POWEROFF", state 4) or restart
 *      channels 0, 1 and 3 ("OFFSENSING"), and return: the OLED state machine continues from there.
 *   3. Power off, common part: CEC, the factory record, the pins and the saved power status.
 *   4a. Power Button = Standby: mute the sound, switch the panel off and wait, store sleep state "dc on" and
 *      return with the system still running.
 *   4b. Power Button = OFF: switch the panel off and wait, switch the input ports, set the remaining pins and
 *      end in SYSAPI_PowerOff.
 *
 * The gpio_set_aux_* routines pass GPIO port 0xFF to gpio_write_pin, which writes nothing for ports above 17.
 */
void APPSetPowerOff(unsigned char from_startup)
{
  unsigned char power_on_type;

  /* Phase 1: common start. */
  timer_api_get_ticks16();
  power_on_type = SYSAPI_GetPowerOnType();
  app_state_record.bytes_0x3e.dialog_button_index = 0;
  app_state_record.half_0xc = 0;

  /* Phase 2: let the OLED power state machine run an off sensing pass first. */
  if (power_on_type != POWER_ON_TYPE_4 && user_settings.factory_marker != FACTORY_MODE_MARKER
      && (oled_power_get_field_12() == 0 || oled_power_get_field_11() == 0) && oled_power_get_field_10() == 0)
    {
      int state, step;
      /* The state machine is already busy: leave it alone. */
      if (oled_power_get_state() != 0 || oled_power_get_step() != 0)
        return;
      osd_close_menu();
      sys_set_mode_byte_c9f8(1);
      gpio_set_port4_bit7_low_if_allowed();
      gpio_set_port4_bit4_low_if_allowed();
      sys_user_apply_mode_byte();
      /* fake_sleep = 0, sensing_requested = 1, power-down request = 1, then power off after the run. */
      oled_power_set_field_12(0);
      oled_power_set_field_09(1);
      oled_power_set_field_0d(1);
      oled_power_set_field_0f(AFTER_SENSING_POWER_OFF);
      oled_power_task();
      state = oled_power_get_state();
      step = oled_power_get_step();
      dbg_printf("----> %d(%d)\r\n", state, step);
      /* Still state 0 step 0: no run and no power-down started, go on with the power off below. */
      if (oled_power_get_state() != 0 || oled_power_get_step() != 0)
        {
          if (oled_power_get_state() == OLED_POWER_POWER_OFF)
            {
              dbg_printf("POWEROFF\r\n");
              SYSAPI_PanelOnOffControl(PANEL_OFF, NO_WAIT);
            }
          else
            {
              dbg_printf("OFFSENSING\r\n");
              sys_api_set_all_channels_flag25();
              sys_restart_channel(0, 0);
              sys_restart_channel(1, 0);
              sys_restart_channel(3, 0);
            }
          dbg_printf("---> return\r\n");
          return;
        }
    }

  /* Phase 3: power off, common part. */
  app_state_record.half_0x3e &= 0x7fff;
  dbg_printf("APPSetPowerOff\r\n");
  gpio_set_aux_bit0_low();
  /* HDMI CEC on and PIP/PBP off: fill the received CEC vendor bytes with 0xFF; otherwise, with Power Button
     OFF, clear the CEC control register. */
  if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && user_settings.pip_pbp_mode == 0)
    {
      hdmi_cec_vendor_id_bytes[3] = 0xff;
      hdmi_cec_vendor_id_bytes[2] = 0xff;
      hdmi_cec_vendor_id_bytes[1] = 0xff;
      hdmi_cec_vendor_id_bytes[0] = 0xff;
    }
  else if (!(user_settings.gaming_flags & SETTINGS_POWER_BUTTON_STANDBY))
    hdmi_cec_api_reset();
  /* Clear factory record byte +0x14 and save the record. */
  if (factory_record.byte_0x14 != 0)
    {
      factory_record.byte_0x14 = 0;
      SYSAPI_WriteEEPROM(EEPROM_AREA_CODE, &factory_record, FACTORY_RECORD_EEPROM_OFFSET, FACTORY_RECORD_SIZE);
    }
  sys_set_mode_byte_c9f8(1);
  gpio_set_port4_bit7_low_if_allowed();
  gpio_set_port4_bit4_low_if_allowed();
  sys_user_apply_mode_byte();
  ldc_api_set_dimming_mode(0);
  /* These pins keep their level when Power Button is Standby. */
  if (!(user_settings.gaming_flags & SETTINGS_POWER_BUTTON_STANDBY))
    {
      gpio_set_port7_bit2_low();
      gpio_set_port7_bit7_inverted(0);
      gpio_set_port5_bit7_low();
      gpio_set_aux_bit5_low();
    }
  gpio_set_port2_bit2_low();
  gpio_set_aux_bit1_low();
  sys_set_key_blocked(0x40, 0);                 /* unblock key 0x40 */
  SYSAPI_SetPowerStatus(0);                     /* store power status 0 and save the settings */
  sys_api_set_flag_e403(1);

  /* Phase 4a: Power Button = Standby. */
  if (user_settings.gaming_flags & SETTINGS_POWER_BUTTON_STANDBY)
    {
      audio_api_set_mute(1);
      SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
      app_state_record.sleep_word.sleep_state = SLEEP_STATE_DC_ON;
      /* Blur reduction off, except at start-up. */
      if (user_settings.blur_free_mode != 0)
        if (from_startup == 0)
          panel_api_set_blurfree_mode(0);
      sys_api_set_all_channels_flag25();
      oled_flag_registers_write(oled_flag_registers_read() & RETAINED_RUN_BITS_CLEAR);
      return;
    }

  /* Phase 4b: Power Button = OFF. */
  SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
  input_api_select_ports(2, 0);
  timer_sleep_ticks(10);
  gpio_set_aux_bit3_pattern(3);
  gpio_set_port6_bit2_low();
  gpio_set_port7_bit1_low();
  gpio_set_aux_bit6_low();
  sys_poll_events_stub_copy7();
  gpio_set_port12_bit0_low();
  if (from_startup == 0)
    panel_blurfree_apply_user_mode(1);
  SYSAPI_PowerOff();
}
