/* panel_output_setup_clock  (FUN_a0106d64)
 *
 * Set up the output path's configuration and clock modulation registers.
 * Name basis: derived - output path set-up B; called when the panel row changes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106d64 @ 0xa0106d64, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on (the rate / depth clamp; panel_output_setup_path has the same forms):
 *  - spread_depth_value is read into its own unsigned short (depth_raw), together with spread_rate_value into an
 *    unsigned int (rate_check), BETWEEN the spread_on test and the 'rate_check != 0' test: that puts the depth
 *    load in the delay slot of that branch and keeps depth_raw and depth_value in separate registers;
 *  - rate_value is read from the record AGAIN (not 'rate_value = rate_check'): the second load keeps the record
 *    pointer live past the depth load;
 *  - 'depth_value = depth_raw;' comes BEFORE the range check of rate_value (written as 'rate_value < 25 ||
 *    rate_value > 500'); placed after it, the 'rate_value = 100' arm stays inline instead of out of line;
 *  - the three 'modulation off' arms (spread_on 0, rate 0, row bit 26 clear) are separate source copies; the
 *    compiler merges two of them;
 *  - the link type / display mode test is written out twice, as in the firmware;
 *  - the division by 15,000,000 is plain C: the compiler turns it into a shift right by 6 and a multiplication
 *    by the reciprocal of 234375.
 */

#define R(a) (*(volatile unsigned int *)(a))

/* The output configuration record (0xA802D680, 36 bytes); field names as in panel_output_setup_path. */
struct panel_output_config
{
  unsigned char spread_on;              /* +0: 0 = clock modulation off */
  unsigned char spread_mode;            /* +1: not read here (rate and depth are always used) */
  unsigned char row_bit25;              /* +2 */
  unsigned char byte_0x03;
  unsigned int colour_depth_code;       /* +4 */
  unsigned int display_mode;            /* +8 */
  unsigned char ed58_value;             /* +0xC: written to OUTPUT_SYNC_POLARITY */
  unsigned char ede4_value;             /* +0xD: not read here */
  unsigned char spread_ctrl[2];         /* +0xE: the 16-bit field spread_ctrl_byte; not read here */
  unsigned short spread_rate_value;     /* +0x10: 25..500, else 100 is used */
  unsigned short spread_depth_value;    /* +0x12: 5..5000, else 150 is used */
  unsigned char byte_0x14;              /* +0x14: written to OUTPUT_REG_EDA8 */
  unsigned char byte_0x15;
  unsigned char byte_0x16;
  unsigned char byte_0x17;
  unsigned int word_0x18;
  unsigned int word_0x1c;
  unsigned int word_0x20;
};

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row
{
  unsigned int flags;                   /* +0: bits 20..22 link type, bit 26 clock modulation */
  unsigned short half_0x04;
  unsigned char display_mode;           /* +6 */
  unsigned char bpc;                    /* +7 */
  unsigned short active_size0, active_size1;    /* +8 / +0xA: active width and lines */
  unsigned char pad0c[0x16];
  unsigned short half_0x22;             /* +0x22: the middle horizontal total of the row */
  unsigned char pad24[2];
  unsigned short hblank_part;           /* +0x26 */
  unsigned short hblank_part2;          /* +0x28 */
  unsigned char pad2a[6];
  unsigned short half_0x30;
  unsigned short half_0x32;
  unsigned int line_rate_x10;           /* +0x34: line rate in tenths of a hertz (564480.0 Hz in the 240 Hz row) */
};
extern struct panel_output_config panel_output_config_record;
extern struct panel_timing_row *panel_working_row_ptr;
extern void pq_block_write8(int, int, int);
extern void panel_output_apply_timing(int);
extern void panel_set_pll_frequency(int, unsigned int);
extern void reg_write16_bytes(unsigned int, unsigned int);

/* Clock generators (the firmware's print names). */
enum { GPLL_DISPM = 0, GPLL_DISP1 = 1, GPLL_DISP2 = 2, GPLL_DISP3 = 3 };

/* Bits 20..22 of the row's first word: link type. */
#define ROW_LINK_TYPE_MASK   0x700000
#define ROW_LINK_TYPE_2      0x200000
#define PANEL_ROW_SPREAD_BIT 0x4000000      /* bit 26: clock modulation on for this row */

#define OUTPUT_SYNC_POLARITY R(0xcf00ed58)
#define OUTPUT_REG_ED5C      R(0xcf00ed5c)  /* 0x20 for link type 2 with display modes 8..10, else 0x40 */
#define OUTPUT_REG_EDA8      R(0xcf00eda8)

/* Clock modulation, two register blocks (see panel_spread_configure). Each block lies in the register set of one
   clock generator: block 0 beside GPLL_DISPM (value 0xCF012884), block 1 beside GPLL_FRC (value 0xCF012984).
   Control register: bit 0 on; rate register: bit 7 set after the value. */
#define SPREAD_CTRL_BLOCK0   R(0xcf012890)
#define SPREAD_RATE_BLOCK0   R(0xcf012898)
#define SPREAD_DEPTH_BLOCK0  R(0xcf01289c)
#define SPREAD_CTRL_BLOCK1   R(0xcf012990)
#define SPREAD_RATE_BLOCK1   R(0xcf012998)
#define SPREAD_DEPTH_BLOCK1  R(0xcf01299c)

/* Accepted ranges of the modulation values, and the values that replace anything outside them. */
#define SPREAD_RATE_MIN      25
#define SPREAD_RATE_MAX      500
#define SPREAD_RATE_DEFAULT  100
#define SPREAD_DEPTH_MIN     5
#define SPREAD_DEPTH_MAX     5000
#define SPREAD_DEPTH_DEFAULT 150

/* Register pairs written with reg_write16_bytes (low byte at the address, bits 8..15 one word above). */
#define CLOCK_REG_B81C       0xcf00b81c
#define CLOCK_REG_B824       0xcf00b824
#define CLOCK_REG_B82C       0xcf00b82c
#define CLOCK_REG_B834       0xcf00b834

#define BLK_REG_8D           0x8d          /* register 0x8D of a picture block */

/*
 * Store a new output configuration and program the output for the working panel timing row: the output
 * registers, the output timing of picture block 0, the four display clock generators and the clock modulation.
 *
 *   cfg   the 36-byte output configuration; it is copied to panel_output_config_record first, and everything
 *         below reads the copy
 *
 * The only caller is panel_setup_output_after_row_change, which builds the configuration from the active row and
 * the device settings record. That caller runs at every power-on (startup_bring_up_system ->
 * startup_init_display_output) and after every panel row change (panel_transform_row), so this routine is on the
 * start-up path of the monitor.
 *
 * Steps, in order:
 *  1. copy the configuration; OUTPUT_SYNC_POLARITY = ed58_value; OUTPUT_REG_ED5C = 0x20 or 0x40;
 *     OUTPUT_REG_EDA8 = byte_0x14; for link type 2 with display modes 8..10, picture block 0 register 0x8D = 8;
 *  2. panel_output_apply_timing for picture block 0;
 *  3. clock generators: GPLL_DISPM = the row's line rate (line_rate_x10 / 10) times its middle horizontal total
 *     (half_0x22); GPLL_DISP1 and GPLL_DISP2 get half of that, GPLL_DISP3 a quarter;
 *  4. clock modulation, in both blocks: when spread_on and spread_rate_value are both non-zero, the rate register
 *     gets 1500 / rate and the depth register (depth * rate * 32768) / 15,000,000 (each cut to 8 bits, rate and
 *     depth clamped as below), and bit 0 (on) of the control registers follows bit 26 of the row; otherwise bit 0
 *     is cleared;
 *  5. two value pairs of the row into the CLOCK_REG_B8xx registers.
 *
 * Unlike panel_output_setup_path (called from Disp_Init and System_Initialize), it leaves the other picture block registers, the
 * size registers and the position offset alone, writes the timing of block 0 only, and never reads spread_mode
 * or spread_ctrl_byte: the modulation is always set from rate and depth. In step 1, display modes 5 and 11 take
 * the 0x40 path (neither lies in 8..10).
 */
void panel_output_setup_clock(struct panel_output_config *cfg)
{
  unsigned int pixel_clock;
  unsigned short rate_value;
  unsigned short depth_value;
  unsigned int rate_check;
  unsigned short depth_raw;
  panel_output_config_record = *cfg;

  /* Step 1: output registers. */
  OUTPUT_SYNC_POLARITY = panel_output_config_record.ed58_value;
  if (((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2) && (((unsigned char) (panel_working_row_ptr->display_mode - 8)) <= 2))
  {
    OUTPUT_REG_ED5C = 0x20;
  }
  else
  {
    OUTPUT_REG_ED5C = 0x40;
  }
  OUTPUT_REG_EDA8 = panel_output_config_record.byte_0x14;
  /* Link type 2 with display modes 8..10: block 0 gets 8 in register 0x8D. */
  if (((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2) && (((unsigned char) (panel_working_row_ptr->display_mode - 8)) <= 2))
  {
    pq_block_write8(0, BLK_REG_8D, 8);
  }

  /* Step 2: output timing of picture block 0 from the row. */
  panel_output_apply_timing(0);

  /* Step 3: the four display clock generators. */
  pixel_clock = (panel_working_row_ptr->line_rate_x10 / 10) * panel_working_row_ptr->half_0x22;
  panel_set_pll_frequency(GPLL_DISPM, pixel_clock);
  panel_set_pll_frequency(GPLL_DISP1, pixel_clock >> 1);
  panel_set_pll_frequency(GPLL_DISP2, pixel_clock >> 1);
  panel_set_pll_frequency(GPLL_DISP3, pixel_clock >> 2);

  /* Step 4: clock modulation. */
  if (panel_output_config_record.spread_on != 0)
  {
    rate_check = panel_output_config_record.spread_rate_value;
    depth_raw = panel_output_config_record.spread_depth_value;
    if (rate_check != 0)
    {
    rate_value = panel_output_config_record.spread_rate_value;
    depth_value = depth_raw;
    if ((rate_value < SPREAD_RATE_MIN) || (rate_value > SPREAD_RATE_MAX)) rate_value = SPREAD_RATE_DEFAULT;
    if ((depth_value < SPREAD_DEPTH_MIN) || (depth_value > SPREAD_DEPTH_MAX)) depth_value = SPREAD_DEPTH_DEFAULT;
    SPREAD_RATE_BLOCK0 = (unsigned char) (1500 / rate_value);
    SPREAD_DEPTH_BLOCK0 = (unsigned char) (((((unsigned int) depth_value) * rate_value) << 15) / 15000000);
    SPREAD_RATE_BLOCK0 = (SPREAD_RATE_BLOCK0) | 0x80;
    SPREAD_RATE_BLOCK1 = (unsigned char) (1500 / rate_value);
    SPREAD_DEPTH_BLOCK1 = (unsigned char) (((((unsigned int) depth_value) * rate_value) << 15) / 15000000);
    SPREAD_RATE_BLOCK1 = (SPREAD_RATE_BLOCK1) | 0x80;
    /* The row decides whether the modulation runs. */
    if (panel_working_row_ptr->flags & PANEL_ROW_SPREAD_BIT)
    {
      SPREAD_CTRL_BLOCK0 = (SPREAD_CTRL_BLOCK0) | 1;
      SPREAD_CTRL_BLOCK1 = (SPREAD_CTRL_BLOCK1) | 1;
    }
    else
    {
      SPREAD_CTRL_BLOCK0 = (SPREAD_CTRL_BLOCK0) & (~1);
      SPREAD_CTRL_BLOCK1 = (SPREAD_CTRL_BLOCK1) & (~1);
    }
    }
    else
    {
    /* No rate value: modulation off. */
    SPREAD_CTRL_BLOCK0 = (SPREAD_CTRL_BLOCK0) & (~1);
    SPREAD_CTRL_BLOCK1 = (SPREAD_CTRL_BLOCK1) & (~1);
    }
  }
  else
  {
    SPREAD_CTRL_BLOCK0 = (SPREAD_CTRL_BLOCK0) & (~1);
    SPREAD_CTRL_BLOCK1 = (SPREAD_CTRL_BLOCK1) & (~1);
  }

  /* Step 5: two ranges of the row, each as a start and an end value. */
  reg_write16_bytes(CLOCK_REG_B81C, panel_working_row_ptr->half_0x30);
  reg_write16_bytes(CLOCK_REG_B824, panel_working_row_ptr->hblank_part);
  reg_write16_bytes(CLOCK_REG_B82C, panel_working_row_ptr->hblank_part + panel_working_row_ptr->hblank_part2);
  reg_write16_bytes(CLOCK_REG_B834, panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32);
}
