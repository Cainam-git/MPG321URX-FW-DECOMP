/* Disp_Init  (FUN_a0151db4)
 *
 * Set up the initial output configuration.
 * Name basis: proven - prints 'Disp_Init' (original name from the text); unused copy
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0151db4 @ 0xa0151db4, flags -mcpu=v8 -O3 -g (-mcpu=v8 -O3 gives the same code). Real size 0x25C
 * bytes. No direct call by address; System_Initialize (System_Initialize) has this function inlined.
 * Source form: DispModeTransform is called and inlined; it is defined here as a static copy
 * (DispModeTransform_inl) so that the compiler inlines it as the firmware did, without a second global
 * definition (its own source form applies: case order, the if-chain for 0x22 / 0x42). The device settings fields
 * are read as a packed record; the configuration is passed by value.
 */
/* Fields of the first word of a timing row, as printed by DispModeTransform. */
struct row_header { unsigned int hi:12; unsigned int format:3; unsigned int lo:9; unsigned char display_mode; unsigned char bpc; };
extern unsigned char *panel_get_active_row(void);
extern int dbg_printf();

#define ROW_DISPLAY_MODE      6         /* byte +6 of a panel timing row */
#define ROW_BPC               7         /* byte +7: bits per colour */
#define ROW_FORMAT_MASK       0xe0000   /* bits 17..19 of the first word (the middle number DispModeTransform prints) */
#define ROW_LINK_TYPE_MASK    0x700000  /* bits 20..22 of the first word: link type */
#define ROW_LINK_TYPE_2       0x200000

#define OUT_COLOUR_DEPTH_10BPC      2   /* colour_depth_code for a row of 10 bits per colour */
#define OUT_COLOUR_DEPTH_8BPC_LINK2 3   /* colour_depth_code for 8 bits per colour on link type 2 */
#define OUT_ED58_VALUE              0x80
#define OUT_EDE4_VALUE              0

/* The output configuration record (36 bytes), as panel_output_setup_path stores it. */
struct panel_output_config {
    unsigned char spread_on;            /* +0: 0 = clock modulation off */
    unsigned char spread_mode;          /* +1: not 0 = rate and depth values, 0 = control byte */
    unsigned char row_bit25;            /* +2 */
    unsigned char byte_0x03;
    int colour_depth_code;              /* +4 */
    int display_mode;                   /* +8 */
    unsigned char ed58_value;           /* +0xC: written to OUTPUT_SYNC_POLARITY (0xCF00ED58) */
    unsigned char ede4_value;           /* +0xD */
    unsigned short spread_ctrl_byte;    /* +0xE: control byte of the modulation */
    unsigned short spread_rate_value;   /* +0x10 */
    unsigned short spread_depth_value;  /* +0x12 */
    unsigned char byte_0x14;
    unsigned char rest[15];
};
/* The part of the device settings record (0xA802E1A0, packed) that holds the clock modulation values. */
struct device_settings_spread {
    unsigned char byte_0x0;
    unsigned short spread_ctrl_byte;    /* +1 */
    unsigned short spread_rate_value;   /* +3 */
    unsigned short spread_depth_value;  /* +5 */
    unsigned char pip_mode;             /* +7 */
} __attribute__((packed, aligned(4)));
extern struct device_settings_spread device_settings;
extern void panel_output_setup_path(struct panel_output_config);

/* Display mode number of the active row (the same table as DispModeTransform): from the row's display mode
   byte, together with its format field in the cases that look at it; 0 for a byte not listed. */
static int DispModeTransform_inl(void)
{
  unsigned char *row = panel_get_active_row();
  int mode = 0;
  switch (row[ROW_DISPLAY_MODE])
  {
    case 0x10: mode = 1; break;
    case 0x24: mode = 14; break;
    case 0x20: mode = 5; break;
    case 0x11: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0x20000) mode = 3; else mode = 4; break;
    case 0x21: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0) mode = 17; else mode = 8; break;
    case 0x40: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0) mode = 6; else mode = 5; break;
    case 0x41: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0x40000) mode = 10; else if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0) mode = 9; else mode = 8; break;
    case 0x22: case 0x42: if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0x40000) mode = 13; else if ((*(unsigned int *)row & ROW_FORMAT_MASK) == 0) mode = 12; else mode = 11; break;
  }
  dbg_printf("------>DispModeTransform %d,%d , %d\r\n", row[ROW_DISPLAY_MODE], ((struct row_header *)row)->format, mode);
  return mode;
}

/*
 * Build the initial output configuration and hand it to panel_output_setup_path. No parameters, no return
 * value. Prints "Disp_Init". This is the copy of System_Initialize's inlined code; nothing calls it.
 *
 * The configuration:
 *   - clock modulation values spread_ctrl_byte / rate / depth copied from the device settings record;
 *     spread_on = 1 and spread_mode = 1 when the rate is non-zero; else spread_on = 1 and spread_mode = 0 when
 *     the control byte is non-zero; else spread_on = 0 (spread_mode is not set in that case);
 *   - colour_depth_code from the active row's bits per colour: 8 gives 3 on link type 2 and 0 on other links,
 *     10 gives 2, any other value leaves the field unset;
 *   - display_mode from the display mode table (DispModeTransform);
 *   - ed58_value 0x80, ede4_value 0, byte_0x14 0, row_bit25 0.
 */
void Disp_Init(void)
{
    struct panel_output_config cfg;
    unsigned char *row = (unsigned char *)panel_get_active_row();
    cfg.row_bit25 = 0;
    dbg_printf("Disp_Init\r\n");
    cfg.spread_rate_value = device_settings.spread_rate_value;
    cfg.spread_depth_value = device_settings.spread_depth_value;
    cfg.spread_ctrl_byte = device_settings.spread_ctrl_byte;
    if (cfg.spread_rate_value != 0) { cfg.spread_on = 1; cfg.spread_mode = 1; }
    else if (cfg.spread_ctrl_byte != 0) { cfg.spread_on = 1; cfg.spread_mode = 0; }
    else cfg.spread_on = 0;
    if (row[ROW_BPC] == 8) { if ((*(unsigned int *)row & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2) cfg.colour_depth_code = OUT_COLOUR_DEPTH_8BPC_LINK2; else cfg.colour_depth_code = 0; }
    else if (row[ROW_BPC] == 10) cfg.colour_depth_code = OUT_COLOUR_DEPTH_10BPC;
    cfg.display_mode = DispModeTransform_inl();
    cfg.ed58_value = OUT_ED58_VALUE;
    cfg.ede4_value = OUT_EDE4_VALUE;
    cfg.byte_0x14 = 0;
    panel_output_setup_path(cfg);
}
