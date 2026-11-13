/* osd_factory_activate_item  (FUN_a008e270)
 *
 * Run the selected factory menu item: Reset, Exit or start editing its value.
 * Note: Item 0x12 restores the default settings; item 0x1C closes the menu.
 * Name basis: derived - item 0x12 ('Reset') reloads defaults, 0x1C closes the menu; reached with menu state
 *   0x112
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008e270 @ 0xa008e270-0xa008e520 (172 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: an if-chain in the firmware's compare order with one call per arm; the
 * switch bit is a 1-bit bit-field, written before the byte copy; the item byte is read again after the first
 * fill call.
 */

/* Factory menu items used here (positions in osd_factory_menu_layout; see enum factory_item). */
#define FACTORY_ITEM_FIRST_COLOUR_VALUE 1       /* items 1..12: the R, G and B values of the four colour rows */
#define FACTORY_ITEM_COLOUR_VALUE_COUNT 12
#define FACTORY_ITEM_SSC_FREQ           0xf
#define FACTORY_ITEM_SSC_RATIO          0x10
#define FACTORY_ITEM_PRODUCT            0x11
#define FACTORY_ITEM_RESET              0x12
#define FACTORY_ITEM_BURN_IN            0x13
#define FACTORY_ITEM_CEC_PWM_ADJUST     0x14
#define FACTORY_ITEM_PHY_CTS_AUTO       0x18
#define FACTORY_ITEM_EXIT               0x1c    /* the item that closes the menu */

#define MENU_STATE_FACTORY_MENU         0x111

/* Device settings cleared by Reset (the OLED use-time and run counters and the Sensing Test switch). */
#define DEVICE_SETTING_EL_COUNT         0xa
#define DEVICE_SETTING_OFFS_COUNT       0xb
#define DEVICE_SETTING_EL_HOURS         0xc
#define DEVICE_SETTING_OFFS_HOURS       0xd
#define DEVICE_SETTING_EL_RUNS          0xe
#define DEVICE_SETTING_OFFS_RUNS        0xf
#define DEVICE_SETTING_SENSING_TEST     0x10

/* Bits of osd_request_bits: the event posted afterwards. */
#define OSD_REQUEST_EVENT_83            0x04
#define OSD_REQUEST_EVENT_81            0x08

/* Fill values written to the cells by osd_api_fill_cells: the selected item has 0x90 on its label and 0x790
   on its value field (osd_factory_select_item); while its value is edited it is the other way round. */
#define CELL_FILL_0X790                 0x790
#define CELL_FILL_0X90                  0x90

/* One entry of osd_factory_menu_layout: where the label of an item sits, in character cells. Its value field
   starts at col + len. */
struct factory_item_position { unsigned char col, row, len; };

/* The part of the user settings record used here. */
struct user_settings_record {           /* user_settings, 0xA802D290 */
  unsigned char pad000[9];
  unsigned char brightness;             /* +0x09 */
  unsigned char pad00a[0x1ca];
  union {                               /* +0x1D4 */
    unsigned int word;
    struct { unsigned int bits_31_7:25, cec_pwm_adjust:1, bits_5_0:6; } bits;   /* bit 6: "CEC PWM Adjust" on */
  } word_0x1d4;
  unsigned char cec_pwm_brightness;     /* +0x1D8: the brightness CEC PWM Adjust loads */
};

extern struct factory_item_position osd_factory_menu_layout[];
extern unsigned char osd_factory_drawn_flag, osd_factory_item, osd_factory_item20_switch, osd_request_bits;
extern struct user_settings_record user_settings;
extern int sys_user_apply_brightness(void);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_set_menu_state(int);
extern void osd_api_enable(int, int);
extern void sys_user_factory_reset(void);
extern void nvram_set_device_setting(int, int);
extern void nvram_api_store_by_selector(unsigned char);
extern void osd_draw_factory_menu(void);
extern void osd_close_menu(void);
extern void osd_set_layout(unsigned int);

/* The value field of item v: start cell (col + len, row), n cells wide, filled with CELL_FILL_0X90. */
#define FILL_VALUE_FIELD(v, n) \
    osd_api_fill_cells(osd_factory_menu_layout[v].col + osd_factory_menu_layout[v].len, \
                       osd_factory_menu_layout[v].row, n, CELL_FILL_0X90, 0)

/* Act on the selected factory menu item osd_factory_item (called by the factory menu key handler). No parameters, no result. Three cases:
 *  - Reset: go to the factory menu state, switch menu layer 0 off, reload all user settings from their
 *    defaults, clear the OLED counters and the Sensing Test switch in the device settings, store the channel
 *    modes, raise OSD_REQUEST_EVENT_83 and draw the factory menu again.
 *  - Exit: close the menu, set menu layout 0 and clear the "factory menu drawn" flag.
 *  - Any other item starts editing its value: for CEC PWM Adjust the current switch (settings word +0x1D4 bit 6)
 *    is kept in osd_factory_item20_switch, the bit is set, the brightness takes the value +0x1D8 and is applied
 *    (OSD_REQUEST_EVENT_81). Then the label cells get CELL_FILL_0X790 and the value field of the item gets
 *    CELL_FILL_0X90; the value field is 3 cells for the colour values, 5 for Product and CEC PWM Adjust, 10 for
 *    Burn In and PHY CTS AUTO, 6 for SSC Freq, 1 for SSC Ratio and 4 for all others.
 */
void osd_factory_activate_item(void)
{
  unsigned char v;

  if (osd_factory_item == FACTORY_ITEM_RESET) {
    osd_set_menu_state(MENU_STATE_FACTORY_MENU);
    osd_api_enable(0, 0);
    sys_user_factory_reset();
    nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
    nvram_set_device_setting(DEVICE_SETTING_EL_COUNT, 0);
    nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
    nvram_set_device_setting(DEVICE_SETTING_EL_HOURS, 0);
    nvram_set_device_setting(DEVICE_SETTING_SENSING_TEST, 0);
    nvram_set_device_setting(DEVICE_SETTING_EL_RUNS, 0);
    nvram_set_device_setting(DEVICE_SETTING_OFFS_RUNS, 0);
    nvram_api_store_by_selector(1);
    osd_request_bits |= OSD_REQUEST_EVENT_83;
    osd_draw_factory_menu();
  } else if (osd_factory_item == FACTORY_ITEM_EXIT) {
    osd_close_menu();
    osd_set_layout(0);
    osd_factory_drawn_flag = 0;
  } else {
    if (osd_factory_item == FACTORY_ITEM_CEC_PWM_ADJUST) {
      osd_factory_item20_switch = user_settings.word_0x1d4.bits.cec_pwm_adjust;
      user_settings.word_0x1d4.bits.cec_pwm_adjust = 1;
      user_settings.brightness = user_settings.cec_pwm_brightness;

      sys_user_apply_brightness();
      osd_request_bits |= OSD_REQUEST_EVENT_81;
    }
    osd_api_fill_cells(osd_factory_menu_layout[osd_factory_item].col, osd_factory_menu_layout[osd_factory_item].row, osd_factory_menu_layout[osd_factory_item].len, CELL_FILL_0X790, 0);
    v = osd_factory_item;
    if ((unsigned char)(v - FACTORY_ITEM_FIRST_COLOUR_VALUE) < FACTORY_ITEM_COLOUR_VALUE_COUNT)
      FILL_VALUE_FIELD(v, 3);
    else if (v == FACTORY_ITEM_PRODUCT)
      FILL_VALUE_FIELD(v, 5);
    else if (v == FACTORY_ITEM_BURN_IN)
      FILL_VALUE_FIELD(v, 0xa);
    else if (v == FACTORY_ITEM_PHY_CTS_AUTO)
      FILL_VALUE_FIELD(v, 0xa);
    else if (v == FACTORY_ITEM_SSC_RATIO)
      FILL_VALUE_FIELD(v, 1);
    else if (v == FACTORY_ITEM_SSC_FREQ)
      FILL_VALUE_FIELD(v, 6);
    else if (v == FACTORY_ITEM_CEC_PWM_ADJUST)
      FILL_VALUE_FIELD(v, 5);
    else
      FILL_VALUE_FIELD(v, 4);
  }
}
