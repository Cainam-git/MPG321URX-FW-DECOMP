/* panel_blurfree_apply_user_mode  (FUN_a008767c)
 *
 * Choose the blur reduction mode (off, 1 or 2) from the settings and set up its PWM parameters.
 *   force_off: non-zero forces mode 0
 * Note: From the blur reduction setting +0xB0; allowed only when pq_select_rate_mode gives 2 or 3 (84..279 Hz,
 *   or Adaptive-Sync).
 * Name basis: derived - panel_api_set_blurfree_mode 0 / 1 / 2; every write goes to
 *   panel_blurfree_set_parameter / panel_blurfree_configure
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008767c @ 0xa008767c-0xa008796c, flags -mcpu=v8 -O3 -g.
 * Source form: 'mode' is an int that is set to SELECT_OFF by the sys_user_get_picture_state test and then
 * copied into 'allowed', which is copied into 'selection'; the same variable 'mode' later holds the setting
 * word +0xB0, and the value-1 case is an if/else that assigns 'selection' in both arms.
 */
/* The fields of the user settings record read here (docs/RECORDS.md). */
struct user_settings_record {
  unsigned char pad000[0x19];
  unsigned char response_time;          /* +0x19: the response time level */
  unsigned char pad01a[0x8e];
  unsigned int gaming_flags;            /* +0xA8: bit 7 Adaptive-Sync */
  unsigned int settings_page_flags;     /* +0xAC */
  unsigned int blur_free_mode;          /* +0xB0: the blur reduction setting, 0..3 */
};

/* The blur reduction parameters (as in panel_blurfree_configure; the field names are the firmware's own). */
struct blurfree_params {
  unsigned char ucFirstPort, ucFirstPWMDuty, ucFirstPWMFreq, ucFirstPWMDelay, ucSecondPort, pad5;
  unsigned short usSecondPWMFreq;
  unsigned char ucSecondPWMNum, pad9;
  unsigned short ucFrameRate;
  unsigned char trim;
};

#define GAMING_FLAG_ADAPTIVE_SYNC 0x80

/* Parameter numbers of panel_blurfree_set_parameter (as in that routine). */
enum {
  BLURFREE_PARAM_SECOND_CHANNEL_MASK = 0,
  BLURFREE_PARAM_CHANNEL_MASK        = 1,
  BLURFREE_PARAM_ON_TIME             = 2,
  BLURFREE_PARAM_FIRST_PWM_FREQ      = 3,
  BLURFREE_PARAM_CYCLE_LENGTH        = 12,
  BLURFREE_PARAM_TASK_THRESHOLD      = 14,
  BLURFREE_PARAM_REVERSED_MODE       = 15,
  BLURFREE_PARAM_DUTY_OFFSET         = 16,
  BLURFREE_PARAM_SECOND_PWM_FREQ     = 17,
  BLURFREE_PARAM_SECOND_PORT         = 18
};

/* Blur reduction modes of panel_api_set_blurfree_mode. */
enum { BLURFREE_MODE_OFF = 0, BLURFREE_MODE_GEN1 = 1, BLURFREE_MODE_GEN2 = 2 };

/* The selection made here, named by the mode each one switches on. */
enum { SELECT_OFF = 0, SELECT_GEN1 = 2, SELECT_GEN2 = 3 };

#define MAIN_CHANNEL         0
#define STATE_CODE_8         8          /* only channel state codes above 8 allow blur reduction */
#define RATE_MIN_HZ          84         /* refresh rates 84..279 Hz allow it ((rate - 84) <= 195) */
#define RATE_SPAN_HZ         0xc3
#define BLURFREE_SETTING_MAX 3
#define RESPONSE_LEVEL_OFF   5          /* sys_user_map_mode_1_2(5) gives 5: pq_api_set_response_level switches off */
#define MASK_BIT4            0x10

extern struct user_settings_record user_settings;
extern unsigned short panel_output_rate;
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern int sys_user_get_picture_state(void);
extern int gpio_is_aux_bit0_high(void);
extern void panel_blurfree_set_parameter(unsigned int, unsigned short);
extern void gpio_set_aux_bit0_low_copy2(void);
extern void panel_api_store_blurfree_mode(unsigned int);
extern void sys_user_apply_brightness(void);
extern void timer_sleep_ticks(int ms);
extern void ldc_api_set_mode_byte(unsigned char);
extern void panel_blurfree_set_pin_functions(unsigned char, unsigned char);
extern unsigned char sys_user_map_mode_1_2(unsigned char);
extern void pq_api_set_response_level(unsigned char);
extern void panel_api_set_blurfree_mode(unsigned int);
extern void ldc_api_set_direct_pwm(unsigned char);
extern unsigned char sys_api_is_frc_active_unlocked(void);
extern void pq_apply_settings_by_mask(unsigned char, unsigned char);
extern void gpio_set_aux_bit0_high_copy(void);
extern void panel_blurfree_configure(struct blurfree_params *);

/*
 * Decide whether blur reduction runs, in which mode, and set it up.
 *
 *   force_off  non-zero: switch blur reduction off whatever the settings say. APPSetPowerOff and
 *              power_enter_app_state pass 1; App_CoolInitialize passes 0.
 *
 * Phases, in order:
 *   1. Allowed? Only when the main channel's state code is above 8 and the refresh rate is 84..279 Hz or
 *      Adaptive-Sync is on (settings word +0xA8 bit 7), and sys_user_get_picture_state returns 0.
 *   2. Mode: a blur reduction setting (+0xB0) above 3 is cleared to 0. When allowed and not forced off, the
 *      setting picks the mode: 1 = GEN2 with Adaptive-Sync, else GEN1; 2 = GEN1; 3 = GEN2; 0 = off.
 *   3. Common parameters, written for every mode (panel_blurfree_set_parameter).
 *   4. GEN1: one PWM signal at the frame rate minus 2, set up parameter by parameter.
 *      GEN2: the complete set handed to panel_blurfree_configure, with the frame rate.
 *      Both: gpio_set_aux_bit0_high_copy (port number 0xFF, no pin changes), the mode stored and applied,
 *      the response level switched off, the pins of the PWM channels in the two masks set up
 *      (panel_blurfree_set_pin_functions), and the dimming processor told (direct PWM on:
 *      ldc_api_set_direct_pwm(1), ldc_api_set_mode_byte(1)).
 *      Off: gpio_set_aux_bit0_low_copy2 (no pin changes either), the mode stored as off, the response level
 *      of the user's setting, the mode applied.
 *   5. The brightness applied again (sys_user_apply_brightness).
 */
void panel_blurfree_apply_user_mode(unsigned char force_off)
{
  unsigned short rate_hz;
  int mode;
  unsigned int selection, allowed;
  unsigned char state_code;
  struct blurfree_params params;

  /* 1. Allowed? */
  rate_hz = input_api_get_timing_field(MAIN_CHANNEL, 1) / 10;   /* field 1: refresh rate in tenths of Hz */
  state_code = sys_api_get_channel_state_code(MAIN_CHANNEL);
  mode = 0;
  allowed = 0;
  if (state_code > STATE_CODE_8) {
    if ((unsigned short)(rate_hz - RATE_MIN_HZ) <= RATE_SPAN_HZ)
      mode = SELECT_GEN1;
    if (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC)
      mode = SELECT_GEN2;
    if (sys_user_get_picture_state())
      mode = SELECT_OFF;
    allowed = mode;
  }
  selection = allowed;
  gpio_is_aux_bit0_high();              /* read; the result is not used */

  /* 2. Mode from the user's setting. */
  if (user_settings.blur_free_mode > BLURFREE_SETTING_MAX) {
    user_settings.blur_free_mode = 0;
    selection = SELECT_OFF;
  }
  if (force_off) {
    selection = SELECT_OFF;
  } else if (selection != SELECT_OFF) {
    mode = user_settings.blur_free_mode;
    if (mode == 1) {
      if (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC)
        selection = SELECT_GEN2;
      else
        selection = SELECT_GEN1;
    } else
      selection = mode;
  }

  /* 3. Common parameters. */
  panel_blurfree_set_parameter(BLURFREE_PARAM_CYCLE_LENGTH, 0x134);
  panel_blurfree_set_parameter(BLURFREE_PARAM_SECOND_PWM_FREQ, 0x61a8);
  panel_blurfree_set_parameter(BLURFREE_PARAM_DUTY_OFFSET, 0xe1);
  panel_blurfree_set_parameter(BLURFREE_PARAM_TASK_THRESHOLD, 0x55);
  panel_blurfree_set_parameter(BLURFREE_PARAM_SECOND_CHANNEL_MASK, 0x10);
  panel_blurfree_set_parameter(BLURFREE_PARAM_CHANNEL_MASK, 0x10);
  panel_blurfree_set_parameter(BLURFREE_PARAM_SECOND_PORT, 0x19);
  panel_blurfree_set_parameter(BLURFREE_PARAM_REVERSED_MODE, 0);

  if (selection == SELECT_GEN1) {
    /* 4. GEN1. With frame-rate conversion running (not bypassed or locked) the panel's output rate counts. */
    panel_blurfree_set_parameter(BLURFREE_PARAM_CHANNEL_MASK, 0);
    if (sys_api_is_frc_active_unlocked())
      rate_hz = panel_output_rate / 10;
    panel_blurfree_set_parameter(BLURFREE_PARAM_FIRST_PWM_FREQ, rate_hz - 2);
    panel_blurfree_set_parameter(BLURFREE_PARAM_CYCLE_LENGTH, 0x3ff);
    panel_blurfree_set_parameter(BLURFREE_PARAM_ON_TIME, 0xb2);
    pq_apply_settings_by_mask(MASK_BIT4, 0x10);     /* bit 4: parameter 8, the delay of PWM channel 4 */
    gpio_set_aux_bit0_high_copy();
    panel_api_set_blurfree_mode(BLURFREE_MODE_GEN1);
    pq_api_set_response_level(sys_user_map_mode_1_2(RESPONSE_LEVEL_OFF));
    panel_blurfree_set_pin_functions(1, 0xff);
    ldc_api_set_direct_pwm(1);
    ldc_api_set_mode_byte(1);
  } else if (selection == SELECT_GEN2) {
    /* 4. GEN2: the whole parameter set at once. */
    params.ucFirstPort = 0x10;
    params.ucFirstPWMDuty = 0x14;
    params.ucFirstPWMFreq = 0x2d;
    params.ucFirstPWMDelay = 0x10;
    params.ucSecondPort = 0x19;
    params.usSecondPWMFreq = 0xfa;
    params.ucSecondPWMNum = 0xa;
    params.ucFrameRate = rate_hz;
    params.trim = 0x80;                 /* 128 = no change of the duty offset */
    panel_blurfree_configure(&params);
    gpio_set_aux_bit0_high_copy();
    panel_api_set_blurfree_mode(BLURFREE_MODE_GEN2);
    pq_api_set_response_level(sys_user_map_mode_1_2(RESPONSE_LEVEL_OFF));
    panel_blurfree_set_pin_functions(1, 0xff);
    ldc_api_set_direct_pwm(1);
    ldc_api_set_mode_byte(1);
  } else {
    /* 4. Off. */
    gpio_set_aux_bit0_low_copy2();
    panel_api_store_blurfree_mode(BLURFREE_MODE_OFF);
    sys_user_apply_brightness();
    timer_sleep_ticks(50);
    ldc_api_set_mode_byte(0);
    panel_blurfree_set_pin_functions(1, 0xff);
    panel_blurfree_set_parameter(BLURFREE_PARAM_ON_TIME, 0x3ff);
    pq_api_set_response_level(sys_user_map_mode_1_2(user_settings.response_time));
    panel_api_set_blurfree_mode(BLURFREE_MODE_OFF);
    ldc_api_set_direct_pwm(0);
  }

  /* 5. */
  sys_user_apply_brightness();
}
