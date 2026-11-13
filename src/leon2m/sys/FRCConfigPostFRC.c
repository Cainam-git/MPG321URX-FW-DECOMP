/* FRCConfigPostFRC  (FUN_a0107e44)
 *
 * Configure the output clock and timing behind the frame-rate converter.
 * Name basis: proven - prints 'FRCConfigPostFRC' texts (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107e44 @ 0xa0107e44, flags -mcpu=v8 -O3 -g -msoft-float (the image has no FPU instructions; the
 * float maths goes through the libgcc soft-float routines __floatsisf, __mulsf3, __divsf3, __fixunssfsi; 10.0 is
 * the float constant at 0x198760).
 * Source forms the exact build depends on:
 *  - h_active is unsigned short, not 8-bit, and the first clock product has no 8-bit cast;
 *  - each branch of the scale choice updates FRC_V_SCALE_REG with TWO separate read-modify-writes (clear bits,
 *    then set one), not one combined write; timing_form is unsigned char;
 *  - the opening field reads go through the local copy `row`; the search loop re-reads panel_working_row_ptr for
 *    its start, its limit and clk_min ('for (line_length = ptr->htotal_min; line_length < ptr->htotal_max;
 *    line_length += 8)'), after a first clock estimate before the loop;
 *  - both timing_form arms load htotal_min, h_active, hblank_part2, hblank_part in that order (the compiler emits
 *    the hblank_part load first, since `row` dies there); the two identical hblank_part2 tails are merged into
 *    the join;
 *  - the locals are declared frame_length active_lines v_part_0x30 v_part_0x32 hblank_part h_active hblank_part2
 *    vtotal_max line_length (declaration order breaks a register tie: h_active must win over hblank_part2), and
 *    active_lines, v_part_0x30, v_part_0x32, vtotal_max are loaded in that order;
 *  - the three scale arms are written alike: a range test of max_v_remainder, then 'if (sys_get_chip_revision() <
 *    code)' with the no-scale write in its then-arm and the arm's own write in its else-arm; the compiler merges
 *    the three no-scale writes and the final else into one block at 0xa0107ff8 and moves the revision tests out
 *    of line (0xa0108308 / 0xa0108358 / 0xa01083b4). The 0x2000 and 0x1000 ranges are written 's >= lo && s <= hi'.
 */

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row
{
  unsigned int flags;                   /* +0: bits 20..22 link type */
  unsigned short half_0x04;
  unsigned char display_mode;           /* +6 */
  unsigned char bpc;                    /* +7 */
  unsigned short active_size0;          /* +8: active width */
  unsigned short active_size1;          /* +0xA: active lines */
  unsigned char byte_0x0c[4];
  unsigned long long clk_min;           /* +0x10: the two clock values printed as 'clk', in Hz */
  unsigned long long clk_max;           /* +0x18 */
  unsigned short htotal_min;            /* +0x20: the three horizontal totals printed as 'Htoal' */
  unsigned short half_0x22;
  unsigned short htotal_max;            /* +0x24 */
  unsigned short hblank_part;           /* +0x26 */
  unsigned short hblank_part2;          /* +0x28 */
  unsigned short vtotal_min;            /* +0x2A */
  unsigned short vtotal;                /* +0x2C */
  unsigned short vtotal_max;            /* +0x2E */
  unsigned short half_0x30;             /* +0x30 */
  unsigned short half_0x32;             /* +0x32 */
};

#define REG(a) (*((volatile unsigned int *) (a)))

/* Frame-rate converter output registers. */
#define FRC_REG_1A80        REG(0xcf011a80)
#define FRC_1A80_PARTS      0x80        /* bit 7: the read-back routines take the output line and frame length as
                                           the sum of the four parts below (else 0xCF011C20 / 0xCF011C38) */
#define FRC_1A80_BIT1       0x02
#define FRC_ACTIVE_CTRL     REG(0xcf011aa0)
#define FRC_ACTIVE          0x80        /* bit 7: tested by sys_frc_is_active */

/* The output line in four parts (16-bit register pairs, written with reg_write16_bytes); they add up to the
   line length (sys_frc_get_output_line_length). */
#define FRC_H_PART0         0xcf011ac0
#define FRC_H_PART1         0xcf011ac8
#define FRC_H_PART2         0xcf011ad0
#define FRC_H_PART3         0xcf011ad8
/* The output frame in four parts; they add up to the frame length divided by the scale below
   (sys_frc_get_output_frame_length). FRC_V_PART1 is also the register sys_frc_setup_lock writes. */
#define FRC_V_PART0         0xcf011ae0
#define FRC_V_PART1         0xcf011ae8
#define FRC_V_PART2         0xcf011af0
#define FRC_V_PART3         0xcf011af8

/* The second register set: line length and frame length as single values, as the read-back routines take
   them when FRC_1A80_PARTS is clear. */
#define FRC_REG_1C00        REG(0xcf011c00)
#define FRC_MODE_REG        REG(0xcf011c04)
#define FRC_MODE_FREE_RUN   0x60        /* the value sys_frc_setup_lock writes for free run ('FRC freerun mode') */
#define FRC_REG_1C10        0xcf011c10
#define FRC_REG_1C18        0xcf011c18
#define FRC_LINE_LENGTH     0xcf011c20
#define FRC_REG_1C28        0xcf011c28
#define FRC_REG_1C30        0xcf011c30
#define FRC_FRAME_LENGTH    0xcf011c38
#define FRC_REG_1C40        0xcf011c40
#define FRC_REG_1C48        0xcf011c48  /* sys_frc_setup_lock writes the lock offset here */
#define FRC_REG_1C50        0xcf011c50
#define FRC_REG_1C58        0xcf011c58

/* Bits 1..3: scale of the four frame parts. The read-back multiplies their sum by 8, 4 or 2. */
#define FRC_V_SCALE_REG     REG(0xcf011e40)
#define FRC_V_SCALE_8       0x2         /* bit 1: parts are stored divided by 8 */
#define FRC_V_SCALE_4       0x4         /* bit 2: divided by 4 */
#define FRC_V_SCALE_2       0x8         /* bit 3: divided by 2 */
#define FRC_V_SCALE_MASK    0xe
#define REG_CF01340C        REG(0xcf01340c)

/* Lowest chip revision codes (sys_get_chip_revision, 0x80..0x84) that take a scale. */
#define CHIP_REV_SCALE_4_8  0x84
#define CHIP_REV_SCALE_2    0x83

#define GPLL_FRC            4           /* clock generator of the frame-rate converter (panel_set_pll_frequency) */
#define HTOTAL_STEP         8           /* the line length is searched in steps of 8 pixels */
#define OSD_REG_44          0x44
#define OSD_REG_A5          0xa5

extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned short sys_frc_post_last_rate;
extern unsigned short sys_frc_post_frame_remainder;
extern int dbg_printf();
extern void panel_set_pll_frequency(int, unsigned int);
extern unsigned char sys_get_chip_revision(void);
extern void reg_write16_bytes(unsigned int, unsigned int);
extern void osd_write_reg16(int, int, unsigned int);
extern void osd_update_reg_bits(int, int, int, int);

/*
 * Program the clock and the timing of the frame-rate converter's output for a refresh rate, from the working
 * panel timing row.
 *
 *   timing_form  1: the active part of the line is the row's active lines (+0xA); otherwise its active width
 *                (+8). The callers pass sys_config_byte_3 != 0, or 0.
 *   rate         refresh rate in tenths of a hertz (2400 = 240.0 Hz)
 *   force        1: program even when rate equals the last rate; every caller passes 1
 *
 * Called from SYSAPI_GetPanelParamStruct, input_channel_bring_up_task, panel_api_reapply_nominal_rate,
 * sys_api_set_output_mode and sys_api_config (both with 240.0 Hz), SYSAPI_ConfigSystemPIPMode and
 * System_Initialize.
 *
 * Phases:
 *  1. Skip when rate equals sys_frc_post_last_rate and force is 0; else remember rate.
 *  2. Read the row: frame length = vtotal_min + 1; the active part and the two blanking parts of a line.
 *  3. Clock search: from htotal_min in steps of 8 below htotal_max, the first line length whose clock
 *     (line length * frame length * rate / 10, in Hz) is above the row's clk_min. Program the converter's clock
 *     generator with it.
 *  4. Split line and frame into four parts each; the remainder parts make the sums come out at the line length
 *     and the frame length.
 *  5. Choose the frame-part scale from the remainder computed with vtotal_max (0x1000 and more: 2, 0x2000: 4,
 *     0x4000: 8), on chips whose revision code allows it, and scale the four frame parts down.
 *  6. Write both register sets, mark the converter active, and set the menu layers' registers 0x44 and 0xA5.
 */
void FRCConfigPostFRC(unsigned char timing_form, unsigned short rate, unsigned char force)
{
  struct panel_timing_row *row;
  unsigned short frame_length;
  unsigned short active_lines;
  unsigned short v_part_0x30;
  unsigned short v_part_0x32;
  unsigned short hblank_part;
  unsigned short h_active;
  unsigned short hblank_part2;
  unsigned short vtotal_max;
  unsigned short line_length;
  unsigned short max_v_remainder;
  unsigned short h_remainder;
  unsigned short v_remainder;
  unsigned short scaled_0x30;
  unsigned short scaled_0x32;
  unsigned short scaled_remainder;
  unsigned short scaled_active;
  unsigned int clock;
  unsigned char v_shift;

  /* 1. Nothing to do for the same rate unless forced. */
  if (sys_frc_post_last_rate == rate && force == 0)
  {
    return;
  }
  sys_frc_post_last_rate = rate;
  dbg_printf("\033[0;33mFRCConfigPostFRC %d\r\n\033[m", rate);

  /* 2. The row's values. */
  row = panel_working_row_ptr;
  active_lines = row->active_size1;
  v_part_0x30 = row->half_0x30;
  v_part_0x32 = row->half_0x32;
  vtotal_max = row->vtotal_max;
  frame_length = row->vtotal_min + 1;
  if (timing_form == 1)
  {
    line_length = row->htotal_min; h_active = active_lines; hblank_part2 = row->hblank_part2; hblank_part = row->hblank_part;
  }
  else { line_length = row->htotal_min; h_active = row->active_size0; hblank_part2 = row->hblank_part2; hblank_part = row->hblank_part; }

  /* 3. The clock at htotal_min; it stays in use when the search below does not run (htotal_min not below
     htotal_max). When no line length reaches clk_min, the search ends at or above htotal_max with the clock of
     the last length tried. */
  clock = (float) line_length * frame_length * rate / 10.0f;
  for (line_length = panel_working_row_ptr->htotal_min; line_length < panel_working_row_ptr->htotal_max; line_length += HTOTAL_STEP)
  {
    clock = (float) line_length * frame_length * rate / 10.0f;
    if (clock > panel_working_row_ptr->clk_min)
    {
      break;
    }
  }
  panel_set_pll_frequency(GPLL_FRC, clock);

  /* 4. What is left of the line and of the frame after the other parts (12 bits each). */
  h_remainder = (line_length - h_active - hblank_part2 - hblank_part) & 0xfff;
  v_remainder = (frame_length - active_lines - v_part_0x32 - v_part_0x30) & 0xfff;
  max_v_remainder = vtotal_max - active_lines - v_part_0x32 - v_part_0x30;
  if (v_remainder == 0)
  {
    v_remainder = 1;
  }

  /* 5. The scale of the frame parts: the larger the remainder can get, the larger the divisor. Older chip
     revisions keep the parts unscaled. */
  if (max_v_remainder > 0x3fff)
  {
    if (sys_get_chip_revision() < CHIP_REV_SCALE_4_8)
    {
      FRC_V_SCALE_REG = FRC_V_SCALE_REG & (~FRC_V_SCALE_MASK);
      v_shift = 0;
    }
    else
    {
      FRC_V_SCALE_REG = FRC_V_SCALE_REG & (~(FRC_V_SCALE_4 | FRC_V_SCALE_2));
      FRC_V_SCALE_REG = FRC_V_SCALE_REG | FRC_V_SCALE_8;
      v_shift = 3;
    }
  }
  else if (max_v_remainder >= 0x2000 && max_v_remainder <= 0x3fff)
  {
    if (sys_get_chip_revision() < CHIP_REV_SCALE_4_8)
    {
      FRC_V_SCALE_REG = FRC_V_SCALE_REG & (~FRC_V_SCALE_MASK);
      v_shift = 0;
    }
    else
    {
      FRC_V_SCALE_REG = FRC_V_SCALE_REG & (~(FRC_V_SCALE_8 | FRC_V_SCALE_2));
      FRC_V_SCALE_REG = FRC_V_SCALE_REG | FRC_V_SCALE_4;
      v_shift = 2;
    }
  }
  else if (max_v_remainder >= 0x1000 && max_v_remainder <= 0x1fff)
  {
    if (sys_get_chip_revision() < CHIP_REV_SCALE_2)
    {
      FRC_V_SCALE_REG = FRC_V_SCALE_REG & (~FRC_V_SCALE_MASK);
      v_shift = 0;
    }
    else
    {
      FRC_V_SCALE_REG = FRC_V_SCALE_REG & (~(FRC_V_SCALE_8 | FRC_V_SCALE_4));
      FRC_V_SCALE_REG = FRC_V_SCALE_REG | FRC_V_SCALE_2;
      v_shift = 1;
    }
  }
  else
  {
    FRC_V_SCALE_REG = FRC_V_SCALE_REG & (~FRC_V_SCALE_MASK);
    v_shift = 0;
  }

  /* The unscaled remainder is kept for sys_frc_setup_lock, which writes it back on free run. */
  sys_frc_post_frame_remainder = v_remainder;
  /* Each scaled part is at least 1. */
  scaled_0x30 = v_part_0x30 >> (v_shift & 3);
  if (scaled_0x30 == 0)
  {
    scaled_0x30 = 1;
  }
  scaled_0x32 = v_part_0x32 >> (v_shift & 3);
  if (scaled_0x32 == 0)
  {
    scaled_0x32 = 1;
  }
  scaled_remainder = (v_remainder & 0xfff) >> (v_shift & 3);
  if (scaled_remainder == 0)
  {
    scaled_remainder = 1;
  }
  scaled_active = active_lines >> (v_shift & 3);
  if (scaled_active == 0)
  {
    scaled_active = 1;
  }

  /* 6. The four-part register set: line, then frame. */
  reg_write16_bytes(FRC_H_PART0, hblank_part);
  reg_write16_bytes(FRC_H_PART1, h_remainder & 0xfff);
  reg_write16_bytes(FRC_H_PART2, hblank_part2);
  reg_write16_bytes(FRC_H_PART3, h_active);
  reg_write16_bytes(FRC_V_PART0, scaled_0x30);
  reg_write16_bytes(FRC_V_PART1, scaled_remainder);
  reg_write16_bytes(FRC_V_PART2, scaled_0x32);
  reg_write16_bytes(FRC_V_PART3, scaled_active);
  FRC_ACTIVE_CTRL = FRC_ACTIVE_CTRL | FRC_ACTIVE;
  /* The single-value register set. */
  reg_write16_bytes(FRC_REG_1C10, h_remainder & 0xfff);
  reg_write16_bytes(FRC_REG_1C18, h_active);
  reg_write16_bytes(FRC_LINE_LENGTH, line_length);
  reg_write16_bytes(FRC_REG_1C28, scaled_remainder);
  reg_write16_bytes(FRC_REG_1C30, scaled_active);
  reg_write16_bytes(FRC_FRAME_LENGTH, frame_length);
  reg_write16_bytes(FRC_REG_1C40, 0);
  reg_write16_bytes(FRC_REG_1C48, frame_length >> 1);
  reg_write16_bytes(FRC_REG_1C50, 0);
  reg_write16_bytes(FRC_REG_1C58, 0);
  /* The four-part set is selected only when the active lines fit in 12 bits. */
  if (panel_working_row_ptr->active_size1 <= 0xfff)
  {
    FRC_REG_1A80 = FRC_REG_1A80 | FRC_1A80_PARTS;
  }
  FRC_REG_1A80 = FRC_REG_1A80 | FRC_1A80_BIT1;
  FRC_REG_1C00 = 0;
  FRC_MODE_REG = FRC_MODE_FREE_RUN;
  /* Both menu layers: register 0x44 gets the scaled frame remainder, bit 3 of register 0xA5 is set. */
  osd_write_reg16(0, OSD_REG_44, scaled_remainder);
  osd_write_reg16(1, OSD_REG_44, scaled_remainder);
  osd_update_reg_bits(0, OSD_REG_A5, 8, 1);
  osd_update_reg_bits(1, OSD_REG_A5, 8, 1);
  REG_CF01340C = 0;
}
