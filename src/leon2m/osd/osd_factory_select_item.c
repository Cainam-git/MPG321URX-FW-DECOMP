/* osd_factory_select_item  (FUN_a008a95c)
 *
 * Move the factory menu highlight to the item's value and toggle item 0x14's switch.
 * Note: Item 0x14 copies its bit into settings word +0x1D4 bit 6.
 * Name basis: descriptive - code: highlight of the value cells; caller osd_factory_leave_item_edit (key
 *   handler)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a95c @ 0xa008a95c-0xa008abe0 (161 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: an if-chain in the firmware's compare order with one call per arm
 * (the arms for 0x13 and 0x18 and the arms for 0xf and 0x14 are separate, not merged); the switch bit is a
 * 1-bit bit-field of the settings word; v and the item byte are read again where the code reads them again.
 */

/* The factory menu item numbers used here (see enum factory_item in the factory menu files). */
#define FACTORY_ITEM_FIRST_COLOUR_VALUE 1       /* items 1..12: the R, G and B values of the four colour rows */
#define FACTORY_ITEM_COLOUR_VALUE_COUNT 12
#define FACTORY_ITEM_SSC_FREQ           0xf
#define FACTORY_ITEM_SSC_RATIO          0x10
#define FACTORY_ITEM_BURN_IN            0x13
#define FACTORY_ITEM_CEC_PWM_ADJUST     0x14
#define FACTORY_ITEM_PHY_CTS_AUTO       0x18

/* Fill values written to the cells by osd_api_fill_cells. */
#define CELL_FILL_0X790          0x790  /* written over the value field of the selected item */
#define CELL_FILL_0X90           0x90   /* written over the label cells of the selected item */

#define OSD_REQUEST_EVENT_81     0x08   /* bit of osd_request_bits: event 0x81 is posted afterwards */

/* One entry of osd_factory_menu_layout: where the label of an item sits, in character cells. Its value field
   starts at col + len. */
struct factory_item_position { unsigned char col, row, len; };

/* The part of the user settings record used here. */
struct user_settings_record {           /* user_settings, 0xA802D290 */
  unsigned char pad000[0x1d4];
  union {                               /* +0x1D4 */
    unsigned int word;
    struct { unsigned int bits_31_7:25, cec_pwm_adjust:1, bits_5_0:6; } bits;   /* bit 6: "CEC PWM Adjust" on */
  } word_0x1d4;
};

extern struct factory_item_position osd_factory_menu_layout[];
extern unsigned char osd_factory_item, osd_factory_item20_switch, osd_request_bits;
extern struct user_settings_record user_settings;
extern int sys_user_apply_brightness(void);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

/* The value field of item v: start cell (col + len, row), n cells wide, filled with CELL_FILL_0X790. */
#define FILL_VALUE_FIELD(v, n) \
    osd_api_fill_cells(osd_factory_menu_layout[v].col + osd_factory_menu_layout[v].len, \
                       osd_factory_menu_layout[v].row, n, CELL_FILL_0X790, 0)

/* Redraw the cells of the selected factory menu item osd_factory_item (called by the key handler). In order:
 *  1. When the item is "CEC PWM Adjust", its switch (bit 0 of osd_factory_item20_switch) is stored in
 *     settings word +0x1D4 bit 6; when that bit is then clear, the brightness is applied again and
 *     OSD_REQUEST_EVENT_81 is raised in osd_request_bits.
 *  2. The value field of the item is filled with CELL_FILL_0X790; its width depends on the item: 3 cells
 *     for the colour values, 10 for Burn In and PHY CTS AUTO, 6 for SSC Freq and CEC PWM Adjust, 1 for SSC Ratio,
 *     4 for all others.
 *  3. The label cells of the item (col, row, len) are filled with CELL_FILL_0X90.
 */
void osd_factory_select_item(void)
{
  unsigned char v;

  if (osd_factory_item == FACTORY_ITEM_CEC_PWM_ADJUST) {
    user_settings.word_0x1d4.bits.cec_pwm_adjust = osd_factory_item20_switch & 1;
    if (!(user_settings.word_0x1d4.word & 0x40)) {
      sys_user_apply_brightness();
      osd_request_bits |= OSD_REQUEST_EVENT_81;
    }
  }
  v = osd_factory_item;
  if ((unsigned char)(v - FACTORY_ITEM_FIRST_COLOUR_VALUE) < FACTORY_ITEM_COLOUR_VALUE_COUNT)
    FILL_VALUE_FIELD(v, 3);
  else if (v == FACTORY_ITEM_BURN_IN)
    FILL_VALUE_FIELD(v, 0xa);
  else if (v == FACTORY_ITEM_PHY_CTS_AUTO)
    FILL_VALUE_FIELD(v, 0xa);
  else if (v == FACTORY_ITEM_SSC_RATIO)
    FILL_VALUE_FIELD(v, 1);
  else if (v == FACTORY_ITEM_SSC_FREQ)
    FILL_VALUE_FIELD(v, 6);
  else if (v == FACTORY_ITEM_CEC_PWM_ADJUST)
    FILL_VALUE_FIELD(v, 6);
  else
    FILL_VALUE_FIELD(v, 4);
  osd_api_fill_cells(osd_factory_menu_layout[osd_factory_item].col, osd_factory_menu_layout[osd_factory_item].row, osd_factory_menu_layout[osd_factory_item].len, CELL_FILL_0X90, 0);
}
