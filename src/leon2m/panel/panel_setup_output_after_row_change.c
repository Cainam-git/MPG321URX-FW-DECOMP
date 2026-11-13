/* panel_setup_output_after_row_change  (FUN_a015373c)
 *
 * Set up the output path again after the panel mode row changed.
 * Name basis: proven - docs/MAP.md panel modes: re-runs the output set-up; prints DispModeTransform
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015373c @ 0xa015373c, flags -mcpu=v8 -O3 -g (-mcpu=v8 -O3 gives the same code). Real size 564 bytes.
 * Source forms the exact build depends on:
 *  - DispModeTransform is called and inlined; it is defined here as a static copy (DispModeTransform_inl) so that
 *    the compiler inlines it as the firmware did, without a second global definition (its own source form
 *    applies: case order, the if-chain for 0x22 / 0x42);
 *  - the device settings record is read as a packed record (the rate as a halfword at +3 gives the firmware's
 *    byte and word loads);
 *  - the two bytes made from the row word at +0x54 are written as single-bit extracts shifted into place
 *    (pre-shifted masks make the compiler narrow 0x80 / 0xC0 to -128 / -64).
 */

/* Fields of the first word of a timing row, as printed by DispModeTransform. */
struct row_header { unsigned int hi:12; unsigned int format:3; unsigned int lo:9; unsigned char display_mode; unsigned char bpc; };

/* The output configuration record (36 bytes) that panel_output_setup_clock takes by value. Fields that are not
   set here are left as they are on the stack. */
struct panel_output_config
{
  unsigned char spread_on;              /* +0: 1 when the device settings hold a modulation rate, else 0 */
  unsigned char spread_mode;            /* +1: not set here */
  unsigned char row_bit25;              /* +2: bit 25 of the row's first word */
  unsigned char byte_0x03;
  int colour_depth_code;                /* +4 */
  int display_mode;                     /* +8 */
  unsigned char ed58_value;             /* +0xC: written to OUTPUT_SYNC_POLARITY (0xCF00ED58) */
  unsigned char ede4_value;             /* +0xD: written to 0xCF00EDE4 for display modes above 2 */
  unsigned short spread_ctrl_byte;      /* +0xE: not set here */
  unsigned short spread_rate_value;     /* +0x10 */
  unsigned short spread_depth_value;    /* +0x12 */
  unsigned char byte_0x14;              /* +0x14: written to 0xCF00EDA8 */
  unsigned char rest[15];
};
/* The part of the device settings record (0xA802E1A0, packed) that holds the clock modulation values. */
struct device_settings_spread
{
  unsigned char byte_0x0;
  unsigned char byte_0x1;
  unsigned char byte_0x2;
  unsigned short spread_rate_value;     /* +3 */
  unsigned short spread_depth_value;    /* +5 */
  unsigned char pip_mode;               /* +7 */
} __attribute__((packed, aligned(4)));
extern struct device_settings_spread device_settings;
extern unsigned char *panel_get_active_row(void);
extern int dbg_printf();
extern void panel_output_setup_clock(struct panel_output_config);
extern void ldc_send_panel_size_and_start(void);

#define ROW_DISPLAY_MODE   6            /* byte +6 of a panel timing row */
#define ROW_BPC            7            /* byte +7: bits per colour */
#define ROW_FORMAT_MASK    0xe0000      /* bits 17..19 of the first word (the middle number DispModeTransform prints) */
#define ROW_WORD_54        0x54         /* offset of the word whose top bits make ed58_value and ede4_value */
#define ROW_BYTE_55        0x55         /* offset of the byte that becomes byte_0x14 */
#define COLOUR_DEPTH_10BPC 2            /* colour_depth_code for a row of 10 bits per colour */

/* Display mode number of the active row (the same table as DispModeTransform): from the row's display mode
   byte, together with its format field in the cases that look at it; 0 for a byte not listed. */
static int DispModeTransform_inl(void)
{
  unsigned char *row = panel_get_active_row();
  int m = 0;
  switch (row[ROW_DISPLAY_MODE])
  {
    case 0x10: m = 1; break;
    case 0x24: m = 14; break;
    case 0x20: m = 5; break;
    case 0x11: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0x20000) m = 3; else m = 4; break;
    case 0x21: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0) m = 17; else m = 8; break;
    case 0x40: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0) m = 6; else m = 5; break;
    case 0x41: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0x40000) m = 10; else if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0) m = 9; else m = 8; break;
    case 0x22: case 0x42: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0x40000) m = 13; else if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0) m = 12; else m = 11; break;
  }
  dbg_printf("------>DispModeTransform %d,%d , %d\r\n", row[ROW_DISPLAY_MODE], ((struct row_header *)row)->format, m);
  return m;
}

/*
 * Build the output configuration from the active panel timing row and the device settings, program the output
 * for it (panel_output_setup_clock) and send the panel size to the dimming processor
 * (ldc_send_panel_size_and_start). No parameters, no return value.
 *
 * Called at the end of panel_transform_row, so after every change of the panel mode row, and by
 * startup_init_display_output at power-on: it is on the start-up path of the monitor.
 *
 * The configuration:
 *   row_bit25            bit 25 of the row's first word;
 *   spread_on            1 when the device settings hold a modulation rate (settings +3), with that rate and the
 *                        depth (settings +5) copied; else 0 and rate and depth are not set;
 *   colour_depth_code    2 when the row has 10 bits per colour, else 0;
 *   display_mode         the display mode of the row (DispModeTransform);
 *   ed58_value           from the top bits of the row word at +0x54: bit 29 -> bit 7, bit 31 -> bit 5,
 *                        bit 30 -> bit 4;
 *   ede4_value           bits 27..28 of that word, as bits 6..7;
 *   byte_0x14            the row byte at +0x55.
 * spread_mode and spread_ctrl_byte are not set: panel_output_setup_clock does not read them.
 */
void panel_setup_output_after_row_change(void)
{
  struct panel_output_config cfg;
  unsigned char *row = panel_get_active_row();
  unsigned int spread_rate;
  unsigned char *r;
  int display_mode;
  cfg.row_bit25 = ((*((unsigned int *) row)) >> 25) & 1;
  spread_rate = device_settings.spread_rate_value;
  if (spread_rate != 0)
  {
    cfg.spread_on = 1;
    cfg.spread_rate_value = spread_rate;
    cfg.spread_depth_value = device_settings.spread_depth_value;
  }
  else
  {
    cfg.spread_on = 0;
  }
  if (row[ROW_BPC] == 10)
  {
    cfg.colour_depth_code = COLOUR_DEPTH_10BPC;
  }
  else
  {
    cfg.colour_depth_code = 0;
  }
  display_mode = DispModeTransform_inl();
  cfg.display_mode = display_mode;
  cfg.ed58_value = (((*((unsigned int *) (row + ROW_WORD_54))) >> 29 & 1) << 7) | (((*((unsigned int *) (row + ROW_WORD_54))) >> 31) << 5) | (((*((unsigned int *) (row + ROW_WORD_54))) >> 30 & 1) << 4);
  cfg.ede4_value = ((*((unsigned int *) (row + ROW_WORD_54))) >> 27 & 3) << 6;
  cfg.byte_0x14 = row[ROW_BYTE_55];
  panel_output_setup_clock(cfg);
  ldc_send_panel_size_and_start();
}
