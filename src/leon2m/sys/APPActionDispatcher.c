/* APPActionDispatcher  (FUN_a008454c)
 *
 * Map an application, key, menu or DDC/CI event to its action and run it.
 *   event: event code: type in bits 6-7, index in bits 0-5
 * Note: Type 0 = APP, 0x40 = key, 0x80 = OSD, 0xC0 = DDC/CI.
 * Name basis: proven - prints 'APPActionDispatcher->...Event(%d) Action(%d)' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008454c @ 0xa008454c..0xa0085984 (1294 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the callees declared with an empty parameter list take char arguments in their own sources; this file calls
 *    them without prototypes, so the values are passed and used without char masking (as in the firmware);
 *  - APP_ACTION_TIMING_GET_MAIN: the three timing tests jump to one shared 'sys_api_enable_channel_port(0, 1)'
 *    (label port_on), which falls through into the end of APP_ACTION_TIMING_GET_P1; with Adaptive-Sync off the
 *    case jumps to port_off after the switch, which holds 'sys_api_enable_channel_port(0, 0)' and its own copy of
 *    that end (firmware: the branch at 0xa00849c0 to the call at 0xa00849d0 with %o1 = 0);
 *  - actions 0, 11 and 13 go to the end of the switch in the firmware's jump table, like the actions without a
 *    case, but the firmware's block layout needs two separate case blocks for them (case 0, and cases 11 / 13);
 *    each holds 'action = 0', which the compiler removes;
 *  - the two delayed-all actions test bit 15 of half_0x3e as '(short)(half_0x3e & 0x8000)';
 *  - the cases stand in the order of this file (1, 60, 62, 2, 3, ...).
 */

/* Event codes (sys_post_app_event): the type in bits 6..7, the index in bits 0..5. */
#define EVENT_TYPE_MASK         0xc0
#define EVENT_TYPE_APP          0x00    /* application events, made by sys_app_generate_events (APP_EV_*) */
#define EVENT_TYPE_KEY          0x40    /* front keys, posted by sys_scan_keys_post_event */
#define EVENT_TYPE_OSD          0x80    /* menu events */
#define EVENT_TYPE_DDCCI        0xc0    /* DDC/CI events, posted by ddc_post_pending_event */
#define EVENT_INDEX_MASK        0x3f

/* The row of each index table that stands for "no action". */
#define APP_EVENT_ROW_NONE      0x30
#define KEY_EVENT_ROW_NONE      10
#define OSD_EVENT_ROW_NONE      4
#define DDCCI_EVENT_ROW_NONE    7

#define DBG_APP_ACTIONS         0x80    /* debug class of the four event prints; no other routine tests it */

/*
 * The actions, numbered as in the action tables. A name in quotes is the text the action prints; APP_EV_* are
 * the application events of sys_app_generate_events. "Channel n" events are the event of that channel
 * (the generator's port n): channel 0 is the main picture ("_Main"), channel 1 the second picture ("_P1").
 * The actions 14, 15, 23, 24, 27, 28, 41, 52 and 55 have no case: they do nothing. No row of the four action
 * tables holds action 6.
 */
enum app_action {
    APP_ACTION_NONE                   = 0,
    APP_ACTION_PWR_ON_INIT            = 1,  /* "APPATN_PWR_ON_INIT": APP_EV_POWER_ON_INIT */
    APP_ACTION_POWER_ONOFF            = 2,  /* key 0x40 */
    APP_ACTION_POWER_ON               = 3,  /* DDC/CI event 0xC4 */
    APP_ACTION_POWER_OFF              = 4,  /* DDC/CI event 0xC5 */
    APP_ACTION_POWER_SAVING           = 5,  /* DDC/CI event 0xC6 */
    APP_ACTION_POWER_STATE_4          = 6,
    APP_ACTION_AFTER_MUTE_MAIN        = 7,  /* "APPTasksAfterMute_Main": APP_EV_AFTER_MUTE of channel 0 */
    APP_ACTION_AFTER_MUTE_P1          = 8,  /* "APPTasksAfterMute_P1": APP_EV_AFTER_MUTE of channel 1 */
    APP_ACTION_AFTER_MUTE_2           = 9,  /* APP_EV_AFTER_MUTE of channel 2 */
    APP_ACTION_AFTER_MUTE_3           = 10, /* APP_EV_AFTER_MUTE of channel 3 */
    APP_ACTION_AFTER_MUTE_ANY         = 11, /* APP_EV_AFTER_MUTE_ANY: nothing */
    APP_ACTION_MUTE_ALL               = 12, /* "APPATN_MUTE_ALL": APP_EV_MUTE_ALL */
    APP_ACTION_13                     = 13, /* application event 0x15: nothing */
    APP_ACTION_MUTE_WAIT2SHOW         = 16, /* "APPATN_MUTE_WAIT2SHOW": APP_EV_MUTE_WAIT2SHOW */
    APP_ACTION_SYNC_DET_MAIN          = 17, /* "APPATN_SYNC_DET_MAIN": APP_EV_SYNC_DET of channel 0 */
    APP_ACTION_SYNC_DET_P1            = 18, /* APP_EV_SYNC_DET of channel 1 */
    APP_ACTION_SYNC_DET_2             = 19, /* APP_EV_SYNC_DET of channel 2 */
    APP_ACTION_SYNC_DET_3             = 20, /* APP_EV_SYNC_DET of channel 3 */
    APP_ACTION_TIMING_GET_MAIN        = 21, /* "APPATN_TIMING_GET_MAIN": APP_EV_TIMING_GET of channel 0 */
    APP_ACTION_TIMING_GET_P1          = 22, /* APP_EV_TIMING_GET of channel 1 */
    APP_ACTION_BEFOREDISPLAY_MAIN     = 25, /* "APPATN_BEFOREDISPLAY_MAIN": APP_EV_BEFORE_DISPLAY of channel 0 */
    APP_ACTION_BEFOREDISPLAY_P1       = 26, /* "APPATN_BEFOREDISPLAY_P1": APP_EV_BEFORE_DISPLAY of channel 1 */
    APP_ACTION_BEFORE_DISPLAY_ALL     = 29, /* "APPTasksBeforeDisplay": APP_EV_BEFORE_DISPLAY_ALL */
    APP_ACTION_BEFOREDISPLAY_APP_ONLY = 30, /* "APPATN_BEFOREDISPLAY_APP_ONLY": APP_EV_BEFORE_DISPLAY_APP_ONLY */
    APP_ACTION_AFTERDISPLAY_MAIN      = 31, /* "APPATN_AFTERDISPLAY_MAIN": APP_EV_AFTER_DISPLAY of channel 0 */
    APP_ACTION_AFTER_DISPLAY_P1       = 32, /* "APPTasksAfterDisplay_P1": APP_EV_AFTER_DISPLAY of channel 1 */
    APP_ACTION_AFTER_DISPLAY_2        = 33, /* APP_EV_AFTER_DISPLAY of channel 2 */
    APP_ACTION_AFTER_DISPLAY_3        = 34, /* APP_EV_AFTER_DISPLAY of channel 3 */
    APP_ACTION_AFTER_DISPLAY_ALL      = 35, /* "APPTasksAfterDisplay": APP_EV_AFTER_DISPLAY_ALL */
    APP_ACTION_DELAYED_ACTIVE_0       = 36, /* APP_EV_DELAYED_ACTIVE of channels 0..3 */
    APP_ACTION_DELAYED_ACTIVE_1       = 37,
    APP_ACTION_DELAYED_ACTIVE_2       = 38,
    APP_ACTION_DELAYED_ACTIVE_3       = 39,
    APP_ACTION_DELAYED_ALL            = 40, /* APP_EV_DELAYED_ALL */
    APP_ACTION_DELAYED_INACTIVE_0     = 42, /* APP_EV_DELAYED_INACTIVE of channels 0..3 */
    APP_ACTION_DELAYED_INACTIVE_1     = 43,
    APP_ACTION_DELAYED_INACTIVE_2     = 44,
    APP_ACTION_DELAYED_INACTIVE_3     = 45,
    APP_ACTION_DELAYED_ALL_INACTIVE   = 46, /* APP_EV_DELAYED_ALL_INACTIVE */
    APP_ACTION_FLAG29_0               = 47, /* APP_EV_STATE_10_FLAG29 of channels 0..3 */
    APP_ACTION_FLAG29_1               = 48,
    APP_ACTION_FLAG29_2               = 49,
    APP_ACTION_FLAG29_3               = 50,
    APP_ACTION_FLAG29_ALL             = 51, /* APP_EV_STATE_10_FLAG29_ALL */
    APP_ACTION_POWER_STATE_5          = 53, /* keys 0x41 and 0x45..0x48 */
    APP_ACTION_NEXT_SOURCE            = 54, /* key 0x43 */
    APP_ACTION_SAVE_SETTINGS          = 56, /* menu event 0x80, DDC/CI event 0xC0 */
    APP_ACTION_STORE_MODES_1          = 57, /* menu event 0x81, DDC/CI event 0xC1 */
    APP_ACTION_STORE_MODES_2          = 58, /* menu event 0x82, DDC/CI event 0xC2 */
    APP_ACTION_STORE_MODES_0          = 59, /* menu event 0x83, DDC/CI event 0xC3 */
    APP_ACTION_TOGGLE_WORD0_BIT14     = 60, /* key 0x49 */
    APP_ACTION_KEY_4C                 = 61, /* key 0x4C */
    APP_ACTION_TOGGLE_WORD0_BIT13     = 62  /* key 0x4D */
};

/* power_enter_app_state: the states, by the texts of that routine. */
#define APP_POWER_ONOFF             0       /* "APPSTATE_PWR_ONOFF" */
#define APP_POWER_OFF               1       /* APPSetPowerOff */
#define APP_POWER_ON                2       /* "APPSTATE_PWR_ON" */
#define APP_POWER_SAVING            3       /* "APPSetPowersaving" */
#define APP_POWER_STATE_4           4
#define APP_POWER_STATE_5           5

/* Application timers (sys_app_timer_start: timer number, time in ms). */
#define APP_TIMER_SAVE_REQUESTS     1       /* paces the save requests of app_flags_second */
#define APP_TIMER_PORT0             4       /* timers 4..7: one per channel, started by the after-mute actions */
#define APP_TIMER_B                 0xb     /* steps of the two delayed-all chains in sys_run_app_timer_task */

/* app_flags_second: requests to save, served once a second by sys_run_app_timer_task. */
#define APP_FLAG44_STORE_MODES_2    0x01    /* nvram_api_store_by_selector(2): the mode row of the shown channel */
#define APP_FLAG44_SAVE_SETTINGS    0x02    /* the user settings record */
#define APP_FLAG44_STORE_MODES_0    0x04    /* nvram_api_store_by_selector(0): the part record */
#define APP_FLAG44_STORE_MODES_1    0x08    /* nvram_api_store_by_selector(1): the device settings record */

/* app_port_flags: three bits per channel n (n, 5 + n, 10 + n) and three bits for all channels (4, 9, 14).
   sys_app_generate_events clears them; the actions below set them. */
#define APP_PORT_FLAG_DELAYED_ACTIVE(n)     (0x1 << (n))
#define APP_PORT_FLAG_DELAYED_ALL           0x10    /* bit 4 */
#define APP_PORT_FLAG_FLAG29(n)             (0x20 << (n))
#define APP_PORT_FLAG_FLAG29_ALL            0x200   /* bit 9 */
#define APP_PORT_FLAG_DELAYED_INACTIVE(n)   (0x400 << (n))
#define APP_PORT_FLAG_DELAYED_ALL_INACTIVE  0x4000  /* bit 14 */

/* Bits of the user settings record (docs/RECORDS.md) tested here. */
#define SETTINGS_WORD0_BIT9         0x200       /* word +0 bit 9 */
#define SETTINGS_WORD0_BIT13        0x2000      /* word +0 bit 13, switched by APP_ACTION_TOGGLE_WORD0_BIT13 */
#define SETTINGS_WORD0_BIT14        0x4000      /* word +0 bit 14, also set at start-up when the key read is 2 */
#define GAMING_FLAG_ADAPTIVE_SYNC   0x80        /* gaming_flags (+0xA8) bit 7 */
#define GAMING_FLAG_PRO_MODE        0x800       /* gaming_flags bit 11: Pro (1) / Game (0) */
#define GAMING_FLAG_BIT14           0x4000      /* gaming_flags bit 14: which channel's steps handle the sound */
#define SETTINGS_PAGE_FLAG_BIT17    0x20000     /* settings_page_flags (+0xAC) bit 17 */
#define SETTINGS_HDMI_CEC_ON        0x100000    /* settings_page_flags bit 20: the HDMI CEC menu switch */
#define TYPE_C_PD_CHARGE            0x80        /* word +0x1EC bit 7: Type C PD Charge */
#define FACTORY_MODE_MARKER         0x55aa      /* halfword +0x1F6 while the factory tool's factory mode is on */
#define SCREEN_SIZE_4               4           /* screen_size value set back to 0 by APP_ACTION_TIMING_GET_MAIN */

/* Bits of the application state record tested here. */
#define APP_STATE_HALF_A_BIT7       0x80        /* half_0xa bit 7: blocks the Pro/Game copy before display */
#define PORT_FLAG_CHANNEL0          1           /* port_flag_bits: bit n = channel n (see the struct) */
#define PORT_FLAG_CHANNEL1          2
#define PORT_FLAG_CHANNEL2          4
#define PORT_FLAG_CHANNEL3          8

/* OLED power state machine (oled_power_state), the values used here. */
#define OLED_POWER_EL_SENSING       1       /* "ELSENSING" */
#define OLED_POWER_OFF_SENSING      2       /* "OFFSENSING" */
#define OLED_POWER_QSM              3       /* "QSM": stop a sensing run at once */
#define AFTER_SENSING_DISPLAY       0       /* after_sensing (+0x0F): "Goto Display" */
#define AFTER_SENSING_POWER_SAVING  1       /* "Goto PowerSaving" */
#define AFTER_SENSING_POWER_OFF     2       /* "Goto PowerOff" */

/* Fields of the measured input timing (input_api_get_timing_field). */
#define TIMING_REFRESH_RATE         1       /* tenths of a hertz */
#define TIMING_FIELD_7              7       /* compared below with 1920, 3840, 2560 and panel size field 0 */
#define TIMING_FIELD_8              8       /* compared below with 1080, 2160, 1600 and panel size field 1 */

#define MAIN_CHANNEL                0
#define SECOND_CHANNEL              1
#define CHANNEL_2                   2
#define CHANNEL_3                   3

#define PANEL_OFF                   0       /* SYSAPI_PanelOnOffControl: first argument */
#define NO_WAIT                     0       /* SYSAPI_PanelOnOffControl: second argument */
#define WAIT_DONE                   1
#define ALL_INPUT_PORTS             0xfe    /* input_api_set_port_signal: every port */
#define MENU_STATE_NO_SIGNAL        0x10d   /* the no-signal message (OSDCloseWhenSyncDet) */
#define LAST_SOURCE_MENU_INDEX      20      /* the next source wraps to source 0 above this menu index */

/* The bits of a halfword or word that this file names, in big-endian bit-field order (top bit first). */
struct app_state_record
{
  union
  {
    unsigned short half_0x0;                    /* +0x00 */
    struct
    {
      unsigned short bits_15_9 : 7;
      unsigned short after_display : 1;         /* bit 8: set by APP_ACTION_AFTER_DISPLAY_ALL, cleared by
                                                   APP_ACTION_MUTE_ALL */
      unsigned short bits_7_0 : 8;
    } flags_0x0;
  };
  unsigned short half_0x2;                      /* +0x02 */
  union
  {
    unsigned short sleep_word;                  /* +0x04 */
    struct
    {
      unsigned short bits_15_10 : 6;
      unsigned short burnin_started : 1;        /* bit 9: set by the first burn-in step */
      unsigned short bits_8_0 : 9;
    } sleep;
  };
  union
  {
    unsigned short half_0x6;                    /* +0x06 */
    struct
    {
      unsigned short bits_15_7 : 9;
      unsigned short dpms_suspended : 1;        /* bit 6: set by power_enter_app_state(APP_POWER_SAVING) when
                                                   bit 7 is set; it then switches the panel off without
                                                   SYSAPI_PowerSaving */
      unsigned short bits_5_0 : 6;
    } flags_0x6;
  };
  unsigned short half_0x8;                      /* +0x08 */
  unsigned short half_0xa;                      /* +0x0A */
  unsigned char p00c[0x18 - 0x0c];
  unsigned short half_0x18;                     /* +0x18: bit 13 is printed by APP_ACTION_TIMING_GET_MAIN */
  unsigned short half_0x1a;                     /* +0x1A */
  unsigned char port_flag_bits;                 /* +0x1C: bit n set by sys_app_generate_events in the pass of a
                                                   state change of channel n when its flags 14..15 are set; the
                                                   after-display action prints "_ModeTriggerByApp" then */
  unsigned char p01d[0x3e - 0x1d];
  unsigned short half_0x3e;                     /* +0x3E: bit 15 keeps APP_TIMER_B from being started here */
};

/* The user settings record (docs/RECORDS.md), up to the fields used here. */
struct user_settings_record
{
  unsigned int word_0x0;                        /* +0x000: SETTINGS_WORD0_* */
  unsigned char p004[0x1e - 0x04];
  unsigned char input_source;                   /* +0x01E Input Source (menu index) */
  unsigned char pip_pbp_mode;                   /* +0x01F 0 = one picture */
  unsigned char second_source;                  /* +0x020 source of the second picture */
  unsigned char byte_0x21;                      /* +0x021: receives channel 2's port code after display */
  unsigned char byte_0x22;                      /* +0x022: receives channel 3's port code after display */
  unsigned char p023[0x4a - 0x23];
  unsigned char optix_scope;                    /* +0x04A Optix Scope switch */
  unsigned char p04b[0xa8 - 0x4b];
  union
  {
    unsigned int gaming_flags;                  /* +0x0A8: GAMING_FLAG_* */
    struct
    {
      unsigned int bits_31_12 : 20;
      unsigned int pro_selected : 1;            /* bit 11 = GAMING_FLAG_PRO_MODE */
      unsigned int bits_10_9 : 2;
      unsigned int pro_selected_copy_3 : 1;     /* bit 8: kept with mode copy 3 by UserSetProMode / UserSetGameMode */
      unsigned int bits_7_0 : 8;
    } gaming;
  };
  union
  {
    unsigned int settings_page_flags;           /* +0x0AC: SETTINGS_PAGE_FLAG_*, SETTINGS_HDMI_CEC_ON */
    unsigned char settings_page_bytes[4];       /* byte 0 (+0x0AC) is the LED light bar brightness argument */
  };
  unsigned int blur_free_mode;                  /* +0x0B0 */
  unsigned char p0b4[0x181 - 0xb4];
  unsigned char pro_mode;                       /* +0x181 */
  unsigned char game_mode;                      /* +0x182 */
  unsigned char p183[0x187 - 0x183];
  unsigned char pro_mode_copy_3;                /* +0x187: copy of pro_mode kept by UserSetProMode / UserSetGameMode */
  unsigned char game_mode_copy_3;               /* +0x188: copy of game_mode, kept the same way */
  unsigned char p189[0x1a4 - 0x189];
  unsigned char screen_size;                    /* +0x1A4 Screen Size */
  unsigned char p1a5[0x1b4 - 0x1a5];
  unsigned char byte_0x1b4;                     /* +0x1B4: copied to app_settings_1b4_copy */
  unsigned char p1b5[0x1d5 - 0x1b5];
  unsigned char burn_in_flag;                   /* +0x1D5 factory menu "Burn In" */
  unsigned char p1d6[0x1ec - 0x1d6];
  unsigned int word_0x1ec;                      /* +0x1EC: TYPE_C_PD_CHARGE */
  unsigned char p1f0[0x1f6 - 0x1f0];
  unsigned short factory_mode_marker;           /* +0x1F6: FACTORY_MODE_MARKER in factory mode */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned char app_settings_1b4_copy;
extern unsigned char app_flags_second;
extern unsigned char device_settings_pip_mode;
extern unsigned char app_main_link_state;
extern unsigned short app_port_flags;
extern unsigned char hdmi_cec_vendor_id_bytes[4];
extern unsigned char hdmi_cec_source_name[5];
extern const unsigned char app_event_indexes[];
extern const unsigned char app_event_actions[];
extern const unsigned char app_key_event_indexes[];
extern const unsigned char app_osd_event_indexes[];
extern const unsigned char app_ddcci_event_indexes[];
extern const unsigned char app_ddcci_event_actions[];
extern const unsigned int app_key_event_actions[];
extern const unsigned int app_osd_event_actions[];
extern unsigned char dbg_is_print_enabled(unsigned int);
extern int dbg_printf();
extern void sys_api_set_channel_timeout();
extern void power_escape_fake_sleep(void);
extern void power_enter_app_state();
extern void sys_app_timer_start();
extern void input_api_set_port_signal();
extern unsigned char panel_is_power_on_done(void);
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern int input_api_get_channel_port_byte5();
extern int input_api_get_channel_port_code();
extern void sys_api_enable_channel_port();
extern void SYSAPI_GetPanelParamStruct(unsigned int, int, unsigned char);
extern void oled_frc_request_send(void);
extern void pq_detect_ch1_input_change();
extern unsigned char oled_power_get_state(void);
extern unsigned char oled_power_get_step(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void gpio_set_port4_bit7_high_if_allowed(void);
extern void gpio_set_aux_bit0_low(void);
extern void audio_user_apply_level(void);
extern void audio_user_apply_mute(void);
extern void oled_user_apply_pixel_shift(void);
extern void oled_user_apply_pixel_shift_speed(void);
extern void oled_user_apply_screen_saver_range(void);
extern void oled_user_apply_pillar_box(void);
extern void oled_user_apply_task_bar(void);
extern void oled_user_apply_multi_logo(void);
extern void sys_api_set_port0_value_and_stamp();
extern void osd_close_factory_info_page(void);
extern void gpio_user_set_port2_bit2(void);
extern void gpio_user_set_led_by_state(void);
extern void UserSetAuroraLEDBarBrightness(unsigned char);
extern void gpio_user_set_port7_bit1(unsigned char);
extern void UserSetGameMode(void);
extern void UserSetProMode(void);
extern void audio_user_update_routing(void);
extern unsigned short osd_get_menu_state(void);
extern void osd_close_menu(void);
extern unsigned short panel_api_get_active_size();
extern void pq_api_set_window_rect(int, int, int, unsigned short, unsigned short);
extern unsigned char input_api_query_channel_link_state();
extern void UserGetCECSourceMode(void);
extern void pq_load_fga_color_entries(void);
extern int sys_user_get_picture_state(void);
extern void SYSAPI_SetPowerStatus(unsigned char);
extern void App_Initialize();
extern void irq_empty_handler_copy69(void);
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);
extern void audio_api_set_mute(unsigned char);
extern void sys_api_set_event_code();
extern void oled_power_set_state(unsigned char);
extern void oled_power_set_step(unsigned char);
extern void oled_power_set_field_09(unsigned char);
extern void oled_power_set_field_0f(unsigned char);
extern void hdmi_cec_api_send_action();
extern void panel_api_set_blurfree_mode(unsigned int);
extern void sys_api_set_channel_source_enable(unsigned char, unsigned char);
extern void irq_empty_handler_copy72();
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void sys_user_reset_display_path(void);
extern void sys_user_apply_auto_level(void);
extern void gpio_set_aux_bit1_high(void);
extern unsigned char oled_power_get_field_0f(void);
extern void sys_led_bar_send_query(void);
extern unsigned char panel_api_check_limitation(void);
extern void UserSetPIPMode(void);

/* Whether channel 0..3 takes part in the PIP/PBP layout: channel 0 always, channel 1 in every mode but 0,
   channel 2 in modes 4 to 7, channel 3 in mode 7 (the rule of input_is_port_used). */
static unsigned char port_is_used(unsigned char port)
{
  unsigned char used = 0;
  if (port == 0)
    used = 1;
  else
    if (port == 1)
  {
    if (user_settings.pip_pbp_mode != 0)
      used = 1;
  }
  else
    if (port == 2)
  {
    if (((unsigned char) (user_settings.pip_pbp_mode - 4)) <= 3)
      used = 1;
  }
  else
    if (port == 3)
  {
    if (user_settings.pip_pbp_mode == 7)
      used = 1;
  }
  return used;
}

/*
 * Turn one event into its action and carry the action out.
 *
 *   event   event code: the type in bits 6..7 (EVENT_TYPE_*), the index in bits 0..5
 *
 * Called by sys_pump_app_events for every event it takes from the queue.
 *
 * Phase 1, decode: the index of the event selects a row in the index table of its type (app_event_indexes,
 *   app_key_event_indexes, app_osd_event_indexes, app_ddcci_event_indexes); the row selects the action in the
 *   action table of the type. The "no action" row of a type ends the routine at once. With debug class
 *   DBG_APP_ACTIONS on, the row and the action are printed.
 * Phase 2, run the action (enum app_action). The actions fall into these groups, in the order of the cases:
 *   power: power-on init, the two settings-bit toggles, power on/off, the power states of power_enter_app_state;
 *   after mute (one per channel), mute all, mute wait to show;
 *   sync detect (one per channel) and the timing check of channel 0;
 *   before display (channel 0, channel 1, all, app only);
 *   after display (one per channel, then all);
 *   the delayed-event bits of app_port_flags and the two "all channels" checks;
 *   the next input source and the four save requests.
 *
 * Several actions ask for the settings to be saved: they start APP_TIMER_SAVE_REQUESTS with 1000 ms and set a
 * bit of app_flags_second, which sys_run_app_timer_task serves when the timer runs out.
 */
void APPActionDispatcher(unsigned int event)
{
  unsigned char row;
  unsigned int action;

  /* Phase 1: event -> table row -> action. */
  if ((event & EVENT_TYPE_MASK) == EVENT_TYPE_KEY)
  {
    row = app_key_event_indexes[event & EVENT_INDEX_MASK];
    if (row == KEY_EVENT_ROW_NONE)
    {
      return;
    }
    action = app_key_event_actions[row];
    if (dbg_is_print_enabled(DBG_APP_ACTIONS))
    {
      dbg_printf("\nAPPActionDispatcher->KeyEvent(%d) Action(%d)\n\r", row, action);
    }
  }
  else
    if ((event & EVENT_TYPE_MASK) == EVENT_TYPE_OSD)
  {
    row = app_osd_event_indexes[event & EVENT_INDEX_MASK];
    if (row == OSD_EVENT_ROW_NONE)
    {
      return;
    }
    action = app_osd_event_actions[row];
    if (dbg_is_print_enabled(DBG_APP_ACTIONS))
    {
      dbg_printf("\nAPPActionDispatcher->OSDEvent(%d) Action(%d)\n\r", row, action);
    }
  }
  else
    if ((event & EVENT_TYPE_MASK) == EVENT_TYPE_DDCCI)
  {
    row = app_ddcci_event_indexes[event & EVENT_INDEX_MASK];
    if (row == DDCCI_EVENT_ROW_NONE)
    {
      return;
    }
    action = app_ddcci_event_actions[row];
    if (dbg_is_print_enabled(DBG_APP_ACTIONS))
    {
      dbg_printf("\nAPPActionDispatcher->DDCCiEvent(%d) Action(%d)\n\r", row, action);
    }
  }
  else
    if ((event & EVENT_TYPE_MASK) == EVENT_TYPE_APP)
  {
    row = app_event_indexes[event & EVENT_INDEX_MASK];
    if (row == APP_EVENT_ROW_NONE)
    {
      return;
    }
    action = app_event_actions[row];
    if (dbg_is_print_enabled(DBG_APP_ACTIONS))
    {
      dbg_printf("\nAPPActionDispatcher->APPEvent(%d) Action(%d)\n\r", row, action);
    }
  }
  else
  {
    return;
  }

  /* Phase 2: run the action. */
  switch (action)
  {
    /* --- Power --- */

    case APP_ACTION_PWR_ON_INIT:
      dbg_printf("APPATN_PWR_ON_INIT\r\n");
      /* After that power saving: clear the bit, power status on, then the power-on of type 2. */
      if (app_state_record.flags_0x6.dpms_suspended)
    {
      app_state_record.flags_0x6.dpms_suspended = 0;
      dbg_printf("wakeup from susped DPMS\r\n");
      gpio_set_port4_bit4_low_if_allowed();
      gpio_set_port4_bit7_high_if_allowed();
      SYSAPI_SetPowerStatus(1);
      App_Initialize(2);
    }
      break;

    case APP_ACTION_TOGGLE_WORD0_BIT14:
      /* Either way the on/off command goes to every input port. */
      if (user_settings.word_0x0 & SETTINGS_WORD0_BIT14)
    {
      user_settings.word_0x0 &= ~SETTINGS_WORD0_BIT14;
      input_api_set_port_signal(ALL_INPUT_PORTS, 1);
    }
    else
    {
      user_settings.word_0x0 |= SETTINGS_WORD0_BIT14;
      input_api_set_port_signal(ALL_INPUT_PORTS, 1);
    }
      power_enter_app_state(APP_POWER_ON);
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_STORE_MODES_1;
      break;

    case APP_ACTION_TOGGLE_WORD0_BIT13:
      if (user_settings.word_0x0 & SETTINGS_WORD0_BIT13)
    {
      user_settings.word_0x0 &= ~SETTINGS_WORD0_BIT13;
    }
    else
    {
      user_settings.word_0x0 |= SETTINGS_WORD0_BIT13;
    }
      power_enter_app_state(APP_POWER_ON);
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_STORE_MODES_1;
      break;

    case APP_ACTION_POWER_ONOFF:
      /* With HDMI CEC on, one picture and port code 5 on channel 0: CEC action 1 first. */
      if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON)
          && (unsigned char)input_api_get_channel_port_code(MAIN_CHANNEL) == 5 && user_settings.pip_pbp_mode == 0)
        hdmi_cec_api_send_action(1);
      /* A running panel care run is stopped (QSM) and is to end in power off. */
      if ((oled_power_get_state() == OLED_POWER_OFF_SENSING) || (oled_power_get_state() == OLED_POWER_EL_SENSING))
    {
      oled_power_set_state(OLED_POWER_QSM);
      oled_power_set_step(0);
      oled_power_set_field_09(0);
      oled_power_set_field_0f(AFTER_SENSING_POWER_OFF);
    }
      power_enter_app_state(APP_POWER_ONOFF);
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
      break;

    case APP_ACTION_POWER_ON:
      power_enter_app_state(APP_POWER_ON);
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
      break;

    case APP_ACTION_POWER_OFF:
      power_enter_app_state(APP_POWER_OFF);
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
      break;

    case APP_ACTION_POWER_SAVING:
      power_enter_app_state(APP_POWER_SAVING);
      break;

    case APP_ACTION_POWER_STATE_4:
      power_enter_app_state(APP_POWER_STATE_4);
      break;

    /* --- After mute: start the channel's timer (APP_TIMER_PORT0 + channel) --- */

    case APP_ACTION_AFTER_MUTE_MAIN:
      /* With settings word +0 bit 9 the timer is 3000 ms in factory mode, else 12000 ms, and a value is stored
         for port 0 (into halfword +0x10 of its port record); without the bit, 5000 ms. */
      if (user_settings.word_0x0 & SETTINGS_WORD0_BIT9)
    {
      if (user_settings.factory_mode_marker == FACTORY_MODE_MARKER)
      {
        sys_app_timer_start(APP_TIMER_PORT0, 3000);
      }
      else
      {
        sys_app_timer_start(APP_TIMER_PORT0, 12000);
      }
      if (((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && (user_settings.pip_pbp_mode == 0)) && (!input_api_source_id_to_menu_index(input_api_get_channel_port_code(MAIN_CHANNEL))))
        sys_api_set_port0_value_and_stamp(8000);
      else if ((user_settings.factory_mode_marker == FACTORY_MODE_MARKER) && (user_settings.burn_in_flag != 0))
        sys_api_set_port0_value_and_stamp(100);
      else
        sys_api_set_port0_value_and_stamp(6500);
    }
    else
    {
      sys_app_timer_start(APP_TIMER_PORT0, 5000);
    }
      dbg_printf("APPTasksAfterMute_Main \r\n");
      if (user_settings.pip_pbp_mode != 0)
    {
      osd_close_menu();
    }
      /* Blur reduction off. */
      if (user_settings.blur_free_mode != 0)
    {
      panel_api_set_blurfree_mode(0);
    }
      if ((user_settings.pip_pbp_mode == 0) && (user_settings.optix_scope != 0))
    {
      sys_api_set_channel_source_enable(SECOND_CHANNEL, 0);
    }
      /* The sound is muted here when the main channel's steps handle it (gaming_flags bit 14 clear) in PIP/PBP. */
      if (((!(user_settings.gaming_flags & GAMING_FLAG_BIT14)) && (user_settings.pip_pbp_mode != 0)) && (user_settings.settings_page_flags & SETTINGS_PAGE_FLAG_BIT17))
    {
      audio_api_set_mute(1);
    }
      break;

    case APP_ACTION_AFTER_MUTE_P1:
      sys_app_timer_start(APP_TIMER_PORT0 + 1, 5000);
      dbg_printf("APPTasksAfterMute_P1 \r\n");
      /* The sound is muted here when the second channel's steps handle it (gaming_flags bit 14 set). */
      if (((user_settings.gaming_flags & GAMING_FLAG_BIT14) && (user_settings.pip_pbp_mode != 0)) && (user_settings.settings_page_flags & SETTINGS_PAGE_FLAG_BIT17))
    {
      audio_api_set_mute(1);
    }
      break;

    case APP_ACTION_AFTER_MUTE_2:
      sys_app_timer_start(APP_TIMER_PORT0 + 2, 5000);
      break;

    case APP_ACTION_AFTER_MUTE_3:
      sys_app_timer_start(APP_TIMER_PORT0 + 3, 5000);
      break;

    /* --- Mute --- */

    case APP_ACTION_MUTE_ALL:
      dbg_printf("APPATN_MUTE_ALL\r\n");
      app_state_record.flags_0x0.after_display = 0;
      gpio_set_aux_bit0_low();
      SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
      dbg_printf("APPTasksAfterMute\r\n");
      audio_api_set_mute(1);
      sys_api_set_event_code(1);
      break;

    case APP_ACTION_MUTE_WAIT2SHOW:
      dbg_printf("APPATN_MUTE_WAIT2SHOW\r\n");
      gpio_set_aux_bit0_low();
      SYSAPI_PanelOnOffControl(PANEL_OFF, NO_WAIT);
      break;

    /* --- Sync detected --- */

    case APP_ACTION_SYNC_DET_MAIN:
      dbg_printf("APPATN_SYNC_DET_MAIN\r\n");
      if ((!(app_state_record.port_flag_bits & PORT_FLAG_CHANNEL0)) && app_state_record.flags_0x6.dpms_suspended)
    {
      /* The same wake-up as in APP_ACTION_PWR_ON_INIT. */
      app_state_record.flags_0x6.dpms_suspended = 0;
      dbg_printf("wakeup from susped DPMS\r\n");
      gpio_set_port4_bit4_low_if_allowed();
      gpio_set_port4_bit7_high_if_allowed();
      SYSAPI_SetPowerStatus(1);
      App_Initialize(2);
    }
    else
    {
      /* HDMI CEC on, one picture and channel 0 on source 0: forget the received CEC vendor ID and source
         name (0xFF) and send CEC actions 5 and 7. */
      if (!(app_state_record.port_flag_bits & PORT_FLAG_CHANNEL0) && (user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && user_settings.pip_pbp_mode == 0
          && !input_api_source_id_to_menu_index(input_api_get_channel_port_code(MAIN_CHANNEL)))
      {
          hdmi_cec_vendor_id_bytes[3] = 0xff;
          hdmi_cec_vendor_id_bytes[2] = 0xff;
          hdmi_cec_source_name[4] = 0xff;
          hdmi_cec_source_name[3] = 0xff;
          hdmi_cec_source_name[2] = 0xff;
          hdmi_cec_vendor_id_bytes[1] = 0xff;
          hdmi_cec_vendor_id_bytes[0] = 0xff;
          hdmi_cec_source_name[1] = 0xff;
          hdmi_cec_source_name[0] = 0xff;
          hdmi_cec_api_send_action(5);
          hdmi_cec_api_send_action(7);
      }
      if (user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON)
        sys_api_set_channel_timeout(MAIN_CHANNEL, 1, 1000);
    }
      if ((device_settings_pip_mode == 0) || (device_settings_pip_mode == 2))
    {
      gpio_set_aux_bit0_low();
    }
      power_escape_fake_sleep();
      break;

    case APP_ACTION_SYNC_DET_P1:
      pq_detect_ch1_input_change(1);
      power_escape_fake_sleep();
      if ((((user_settings.pip_pbp_mode != 0) && (!(user_settings.word_0x0 & SETTINGS_WORD0_BIT9))) && (!oled_power_get_state())) && (!oled_power_get_step()))
    {
      gpio_set_port4_bit4_low_if_allowed();
      gpio_set_port4_bit7_high_if_allowed();
    }
      break;

    case APP_ACTION_SYNC_DET_2:
      power_escape_fake_sleep();
      break;

    case APP_ACTION_SYNC_DET_3:
      power_escape_fake_sleep();
      break;

    /* --- Timing of channel 0 known --- */

    case APP_ACTION_TIMING_GET_MAIN:
    {
      unsigned short field_7;
      unsigned short field_8;
      unsigned short refresh_rate;
      unsigned char port_byte5;
      unsigned char port_code;
      dbg_printf("-------------->>>>>>APPATN_TIMING_GET_MAIN %d,%d,%d\r\n", user_settings.pip_pbp_mode, (app_state_record.half_0x18 >> 13) & 1, panel_is_power_on_done());
      /* Screen Size 4 is set back to 0 (and applied) when the input's fields 7 / 8 equal the panel's size. */
      if (!(app_state_record.port_flag_bits & PORT_FLAG_CHANNEL0))
      {
        if (((((unsigned short) input_api_get_timing_field(MAIN_CHANNEL, TIMING_FIELD_7)) == panel_api_get_active_size(0))
             && (((unsigned short) input_api_get_timing_field(MAIN_CHANNEL, TIMING_FIELD_8)) == panel_api_get_active_size(1)))
            && (user_settings.screen_size == SCREEN_SIZE_4))
        {
          user_settings.screen_size = 0;
          UserSetPIPMode();
          app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
        }
      }
      /* Channel 0's port is switched on for three timings, refresh rates in tenths of a hertz with both limits
         excluded, and otherwise only with Adaptive-Sync on. */
      field_7 = input_api_get_timing_field(MAIN_CHANNEL, TIMING_FIELD_7);
      field_8 = input_api_get_timing_field(MAIN_CHANNEL, TIMING_FIELD_8);
      refresh_rate = input_api_get_timing_field(MAIN_CHANNEL, TIMING_REFRESH_RATE);
      port_byte5 = input_api_get_channel_port_byte5(MAIN_CHANNEL);
      port_code = input_api_get_channel_port_code(MAIN_CHANNEL);
      if ((((field_7 == 1920) && (field_8 == 1080)) && (refresh_rate < 2450)) && (refresh_rate > 2350))
        goto port_on;
      if ((((field_7 == 3840) && (field_8 == 2160)) && (refresh_rate < 1250)) && (refresh_rate > 1150))
        goto port_on;
      if ((((((field_7 == 2560) && (field_8 == 1600)) && (refresh_rate < 1490)) && (refresh_rate > 1390)) && (port_byte5 == 6)) && ((port_code == 12) || (port_code == 13)))
        goto port_on;
      if (!(user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC))
        goto port_off;
    port_on:
      sys_api_enable_channel_port(MAIN_CHANNEL, 1);
      /* fall through: same end as APP_ACTION_TIMING_GET_P1 */
    }

    case APP_ACTION_TIMING_GET_P1:
      /* Choose the panel timing row for the input and have the chosen row sent to the panel. */
      SYSAPI_GetPanelParamStruct(1, 1, 0);
      oled_frc_request_send();
      break;

    /* --- Before display --- */

    case APP_ACTION_BEFOREDISPLAY_MAIN:
    {
      int panel_size_0;
      int panel_size_1;
      struct user_settings_record *settings;
      dbg_printf("APPATN_BEFOREDISPLAY_MAIN\n");
      /* The window of channel 0 covers the active panel size. */
      panel_size_0 = panel_api_get_active_size(0);
      panel_size_1 = panel_api_get_active_size(1);
      pq_api_set_window_rect(MAIN_CHANNEL, 0, 0, panel_size_0, panel_size_1);
      settings = &user_settings;
      if (app_state_record.port_flag_bits & PORT_FLAG_CHANNEL0)
      {
        break;
      }
      dbg_printf("APPTasksBeforeDisplay_Main\n");
      app_main_link_state = input_api_query_channel_link_state(MAIN_CHANNEL);
      dbg_printf("UserGetCECSourceMode\r\n");
      UserGetCECSourceMode();
      app_settings_1b4_copy = settings->byte_0x1b4;
      pq_load_fga_color_entries();
      /* The same restore as in APPBeforeDisplay_TriggerBySystem: the Pro/Game bit, game_mode and pro_mode take
         back their copies 3. */
      if ((sys_user_get_picture_state() != 0) && (!(app_state_record.half_0xa & APP_STATE_HALF_A_BIT7)))
      {
        settings->gaming.pro_selected = settings->gaming.pro_selected_copy_3;
        settings->game_mode = settings->game_mode_copy_3;
        settings->pro_mode = settings->pro_mode_copy_3;
      }
      if (!(user_settings.gaming_flags & GAMING_FLAG_PRO_MODE))
      {
        UserSetGameMode();
      }
      else
      {
        UserSetProMode();
      }
      if ((!(user_settings.gaming_flags & GAMING_FLAG_BIT14)) || (user_settings.pip_pbp_mode == 0))
      {
        audio_user_update_routing();
      }
      gpio_user_set_port7_bit1(0);
      break;
    }

    case APP_ACTION_BEFOREDISPLAY_P1:
      dbg_printf("APPATN_BEFOREDISPLAY_P1\n");
      if (app_state_record.port_flag_bits & PORT_FLAG_CHANNEL1)
    {
      break;
    }
      if (user_settings.pip_pbp_mode == 0)
    {
      break;
    }
      if (!(user_settings.word_0x0 & SETTINGS_WORD0_BIT9))
    {
      if (!(user_settings.gaming_flags & GAMING_FLAG_PRO_MODE))
      {
        UserSetGameMode();
      }
      else
      {
        UserSetProMode();
      }
    }
      if (user_settings.gaming_flags & GAMING_FLAG_BIT14)
    {
      audio_user_update_routing();
    }
      if (osd_get_menu_state() == MENU_STATE_NO_SIGNAL)
    {
      osd_close_menu();
    }
      break;

    case APP_ACTION_BEFORE_DISPLAY_ALL:
      if (app_state_record.port_flag_bits != 0)
    {
      break;
    }
      dbg_printf("APPTasksBeforeDisplay \r\n");
      osd_close_factory_info_page();
      app_state_record.sleep.burnin_started = 0;
      /* With the burn-in flag set, settings_page_flags bit 17 is set here. */
      if (user_settings.burn_in_flag != 0)
    {
      gpio_set_port4_bit4_low_if_allowed();
      gpio_set_port4_bit7_high_if_allowed();
      user_settings.settings_page_flags |= SETTINGS_PAGE_FLAG_BIT17;
    }
      gpio_user_set_port2_bit2();
      gpio_user_set_led_by_state();
      UserSetAuroraLEDBarBrightness(user_settings.settings_page_bytes[0]);
      /* Factory mode switches Type C PD Charge on. */
      if (user_settings.factory_mode_marker == FACTORY_MODE_MARKER)
    {
      user_settings.word_0x1ec |= TYPE_C_PD_CHARGE;
    }
      gpio_user_set_port7_bit1(0);
      break;

    case APP_ACTION_BEFOREDISPLAY_APP_ONLY:
      dbg_printf("APPATN_BEFOREDISPLAY_APP_ONLY\r\n");
      break;

    /* --- After display: keep the channel's port code as its source, save, clear the channel timeout --- */

    case APP_ACTION_AFTERDISPLAY_MAIN:
      dbg_printf("APPATN_AFTERDISPLAY_MAIN\r\n");
      if (!(app_state_record.port_flag_bits & PORT_FLAG_CHANNEL0))
    {
      user_settings.input_source = input_api_get_channel_port_code(MAIN_CHANNEL);
      dbg_printf("APPTasksAfterDisplay_Main\r\n");
      if ((!(user_settings.gaming_flags & GAMING_FLAG_BIT14)) || (user_settings.pip_pbp_mode == 0))
      {
        audio_user_apply_mute();
      }
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
    }
      sys_api_set_channel_timeout(MAIN_CHANNEL, 0, 0);
      /* The port 0 value: 8000 with HDMI CEC on, one picture and channel 0 on source 0, else 6500. */
      sys_api_set_port0_value_and_stamp((((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && (user_settings.pip_pbp_mode == 0))
                                         && (!input_api_source_id_to_menu_index(input_api_get_channel_port_code(MAIN_CHANNEL))))
                                        ? 8000 : 6500);
      break;

    case APP_ACTION_AFTER_DISPLAY_P1:
      if ((!(app_state_record.port_flag_bits & PORT_FLAG_CHANNEL1)) && (user_settings.pip_pbp_mode != 0))
    {
      user_settings.second_source = input_api_get_channel_port_code(SECOND_CHANNEL);
      dbg_printf("APPTasksAfterDisplay_P1\r\n");
      if ((user_settings.gaming_flags & GAMING_FLAG_BIT14) && (user_settings.pip_pbp_mode != 0))
      {
        audio_user_apply_mute();
      }
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
    }
      sys_api_set_channel_timeout(SECOND_CHANNEL, 0, 0);
      break;

    case APP_ACTION_AFTER_DISPLAY_2:
      if (!(app_state_record.port_flag_bits & PORT_FLAG_CHANNEL2))
    {
      user_settings.byte_0x21 = input_api_get_channel_port_code(CHANNEL_2);
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
    }
      sys_api_set_channel_timeout(CHANNEL_2, 0, 0);
      break;

    case APP_ACTION_AFTER_DISPLAY_3:
      if (!(app_state_record.port_flag_bits & PORT_FLAG_CHANNEL3))
    {
      user_settings.byte_0x22 = input_api_get_channel_port_code(CHANNEL_3);
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
    }
      sys_api_set_channel_timeout(CHANNEL_3, 0, 0);
      break;

    case APP_ACTION_AFTER_DISPLAY_ALL:
      app_state_record.flags_0x0.after_display = 1;
      /* No channel flagged in port_flag_bits: the full set of steps; otherwise the shorter set. */
      if (app_state_record.port_flag_bits == 0)
    {
      dbg_printf("APPTasksAfterDisplay\r\n");
      audio_user_apply_level();
      sys_user_apply_auto_level();
      gpio_set_aux_bit1_high();
      /* A panel care run that was to end in power saving now ends in the picture. */
      if (oled_power_get_field_0f() == AFTER_SENSING_POWER_SAVING)
      {
        if ((oled_power_get_state() == OLED_POWER_OFF_SENSING) || (oled_power_get_state() == OLED_POWER_EL_SENSING))
        {
          oled_power_set_field_0f(AFTER_SENSING_DISPLAY);
        }
      }
      oled_user_apply_pixel_shift();
      oled_user_apply_pixel_shift_speed();
      oled_user_apply_screen_saver_range();
      oled_user_apply_pillar_box();
      oled_user_apply_task_bar();
      oled_user_apply_multi_logo();
      sys_led_bar_send_query();
      /* panel_api_check_limitation always returns 0, so these prints do not run. */
      if (panel_api_check_limitation() == 1)
      {
        dbg_printf("\033[1;31m!!!!!!!Panel over limitation\r\n\033[m");
        dbg_printf("\033[1;31m!!!!!!!Panel over limitation\r\n\033[m");
        dbg_printf("\033[1;31m!!!!!!!Panel over limitation\r\n\033[m");
      }
    }
    else
    {
      dbg_printf("APPTasksAfterDisplay_ModeTriggerByApp\r\n");
      audio_user_apply_level();
      audio_user_apply_mute();
      oled_user_apply_pixel_shift();
      oled_user_apply_pixel_shift_speed();
      oled_user_apply_screen_saver_range();
      oled_user_apply_pillar_box();
      oled_user_apply_task_bar();
      oled_user_apply_multi_logo();
    }
      break;

    /* --- Delayed events: note them in app_port_flags --- */

    case APP_ACTION_DELAYED_ACTIVE_0:
      app_port_flags |= APP_PORT_FLAG_DELAYED_ACTIVE(0);
      break;

    case APP_ACTION_DELAYED_ACTIVE_1:
      app_port_flags |= APP_PORT_FLAG_DELAYED_ACTIVE(1);
      break;

    case APP_ACTION_DELAYED_ACTIVE_2:
      app_port_flags |= APP_PORT_FLAG_DELAYED_ACTIVE(2);
      break;

    case APP_ACTION_DELAYED_ACTIVE_3:
      app_port_flags |= APP_PORT_FLAG_DELAYED_ACTIVE(3);
      break;

    case APP_ACTION_DELAYED_ALL:
      /* Every used channel must have its delayed-active bit (n) or its delayed-inactive bit (10 + n). */
      if (!((app_port_flags & 1) | ((app_port_flags >> 10) & 1)))
    {
      break;
    }
      if ((port_is_used(1) == 1) && (!(((app_port_flags >> 1) & 1) | ((app_port_flags >> 11) & 1))))
    {
      break;
    }
      if ((port_is_used(2) == 1) && (!(((app_port_flags >> 2) & 1) | ((app_port_flags >> 12) & 1))))
    {
      break;
    }
      if ((port_is_used(3) == 1) && (!(((app_port_flags >> 3) & 1) | ((app_port_flags >> 13) & 1))))
    {
      break;
    }
      app_port_flags |= APP_PORT_FLAG_DELAYED_ALL;
      if ((short)(app_state_record.half_0x3e & 0x8000))
        break;
      sys_app_timer_start(APP_TIMER_B, 5000);
      break;

    case APP_ACTION_DELAYED_INACTIVE_0:
      app_port_flags |= APP_PORT_FLAG_DELAYED_INACTIVE(0);
      break;

    case APP_ACTION_DELAYED_INACTIVE_1:
      app_port_flags |= APP_PORT_FLAG_DELAYED_INACTIVE(1);
      break;

    case APP_ACTION_DELAYED_INACTIVE_2:
      app_port_flags |= APP_PORT_FLAG_DELAYED_INACTIVE(2);
      break;

    case APP_ACTION_DELAYED_INACTIVE_3:
      app_port_flags |= APP_PORT_FLAG_DELAYED_INACTIVE(3);
      break;

    case APP_ACTION_DELAYED_ALL_INACTIVE:
      /* Every used channel must have its delayed-inactive bit. */
      if (!(app_port_flags & APP_PORT_FLAG_DELAYED_INACTIVE(0)))
    {
      break;
    }
      if ((port_is_used(1) == 1) && (!(app_port_flags & APP_PORT_FLAG_DELAYED_INACTIVE(1))))
    {
      break;
    }
      if ((port_is_used(2) == 1) && (!(app_port_flags & APP_PORT_FLAG_DELAYED_INACTIVE(2))))
    {
      break;
    }
      if ((port_is_used(3) == 1) && (!(app_port_flags & APP_PORT_FLAG_DELAYED_INACTIVE(3))))
    {
      break;
    }
      app_port_flags |= APP_PORT_FLAG_DELAYED_ALL_INACTIVE;
      if ((short)(app_state_record.half_0x3e & 0x8000))
        break;
      sys_app_timer_start(APP_TIMER_B, 5000);
      break;

    /* --- Channel state 10 with flag 29 --- */

    case APP_ACTION_FLAG29_0:
      irq_empty_handler_copy72(0);
      app_port_flags |= APP_PORT_FLAG_FLAG29(0);
      break;

    case APP_ACTION_FLAG29_1:
      irq_empty_handler_copy72(1);
      app_port_flags |= APP_PORT_FLAG_FLAG29(1);
      break;

    case APP_ACTION_FLAG29_2:
      irq_empty_handler_copy72(2);
      app_port_flags |= APP_PORT_FLAG_FLAG29(2);
      break;

    case APP_ACTION_FLAG29_3:
      irq_empty_handler_copy72(3);
      app_port_flags |= APP_PORT_FLAG_FLAG29(3);
      break;

    case APP_ACTION_FLAG29_ALL:
      app_port_flags |= APP_PORT_FLAG_FLAG29_ALL;
      sys_app_timer_start(APP_TIMER_B, 60000);
      break;

    /* --- Keys, menu and DDC/CI requests --- */

    case APP_ACTION_POWER_STATE_5:
      power_enter_app_state(APP_POWER_STATE_5);
      break;

    case APP_ACTION_NEXT_SOURCE:
      /* The menu index of the next source id; past the last menu index back to source 0. */
      if (input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source) + 1) > LAST_SOURCE_MENU_INDEX)
    {
      user_settings.input_source = input_api_menu_index_to_source_id(0);
    }
    else
    {
      user_settings.input_source = input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source) + 1);
    }
      sys_user_reset_display_path();
      break;

    case APP_ACTION_SAVE_SETTINGS:
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_SAVE_SETTINGS;
      break;

    case APP_ACTION_STORE_MODES_1:
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_STORE_MODES_1;
      break;

    case APP_ACTION_STORE_MODES_2:
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_STORE_MODES_2;
      break;

    case APP_ACTION_STORE_MODES_0:
      sys_app_timer_start(APP_TIMER_SAVE_REQUESTS, 1000);
      app_flags_second |= APP_FLAG44_STORE_MODES_0;
      break;

    case APP_ACTION_KEY_4C:
      irq_empty_handler_copy69();
      break;

    /* --- No action --- */

    case APP_ACTION_NONE:
      action = 0;
      break;

    case APP_ACTION_AFTER_MUTE_ANY:
    case APP_ACTION_13:
      action = 0;
      break;

  }
  return;

 port_off:
  /* APP_ACTION_TIMING_GET_MAIN with channel 0's port off. */
  sys_api_enable_channel_port(MAIN_CHANNEL, 0);
  SYSAPI_GetPanelParamStruct(1, 1, 0);
  oled_frc_request_send();
}
