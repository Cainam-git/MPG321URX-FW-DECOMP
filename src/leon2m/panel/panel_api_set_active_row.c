/* panel_api_set_active_row  (FUN_a01483f4)
 *
 * Make a panel timing row the active one and optionally apply it to the output.
 * Name basis: proven - prints 'clk', 'Htoal' and 'Vtoal'; builds the transformed row and programs the output
 *   timing
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01483f4 @ 0xa01483f4, flags -mcpu=v8 -O3 -g.
 * Source form: the copy is a byte loop with an unsigned short counter, and the source byte is read through a
 * second pointer local (new_var) assigned inside the store; the two derived fields are one chained assignment
 * (hblank_part2 = (hblank_part = ...)).
 */
/* One panel timing row (0x58 bytes, big-endian), as far as it is used here; the field names are those of the
   other panel routines. */
struct panel_timing_row
{
  unsigned int flags;                   /* +0: bits 20..22 link type */
  unsigned short half_0x04;
  unsigned char display_mode;           /* +6: filled in by panel_transform_row */
  unsigned char bpc;                    /* +7: bits per colour */
  unsigned short active_size0;          /* +8: active width in pixels */
  unsigned short active_size1;          /* +0xA: active lines */
  unsigned char pad0c[4];
  unsigned long long clk_min;           /* +0x10: the two clock values printed as 'clk' */
  unsigned long long clk_max;           /* +0x18 */
  unsigned short htotal_min;            /* +0x20: the three horizontal totals printed as 'Htoal' */
  unsigned short half_0x22;             /* +0x22: the middle one of them */
  unsigned short htotal_max;            /* +0x24 */
  unsigned short hblank_part;           /* +0x26: derived here from htotal_min and the active width */
  unsigned short hblank_part2;          /* +0x28: the same value */
  unsigned short vtotal_min;            /* +0x2A: the three vertical totals printed as 'Vtoal' */
  unsigned short vtotal;                /* +0x2C */
  unsigned short vtotal_max;            /* +0x2E */
  unsigned char pad30[0x18];
  unsigned short vfreq_at_min_clock;    /* +0x48: derived here from clk_min and the minimum totals */
  unsigned short hfreq_min;             /* +0x4A: line rate limits, 100 Hz units */
  unsigned short hfreq_max;             /* +0x4C */
  unsigned short vfreq_min;             /* +0x4E: refresh rate limits, tenths of a hertz */
  unsigned short vfreq_max;             /* +0x50 */
  unsigned char pad52[6];
};
extern struct panel_timing_row panel_active_row;
extern int dbg_printf();
extern void panel_transform_row(void);
extern void panel_output_apply_timing(int);

#define ROW_SIZE            0x58        /* bytes in a timing row */
#define HBLANK_STEP         48
#define HBLANK_PART_FACTOR  16
#define FREQ_FACTOR         10

/*
 * Copy a timing row into the active-row record (panel_active_row, 0x58 bytes), print its clock limits and
 * totals, derive three fields of it, build the working copy (panel_transform_row, which also sets up the output
 * path) and, when asked, program the output timing.
 *
 *   row        the 0x58-byte timing row to make active (one of the three panel mode rows, or a copy of one)
 *   apply_now  non-zero: also program the output timing registers from the new row (panel_output_apply_timing(0))
 *
 * Prints "clk <min>, <max>", "Htoal <min> <middle> <max>" and "Vtoal <min> <middle> <max>".
 * Derived fields of the active row, overwriting what the copied row held:
 *   hblank_part = hblank_part2 = (htotal_min - active_size0) / 48 * 16   (signed division)
 *   vfreq_at_min_clock         = clk_min / htotal_min / vtotal_min * 10   (64-bit divisions)
 *
 * Callers: SYSAPI_GetPanelParamStruct (apply_now 1 when it switches the mode by the measured input or by force;
 * apply_now 0 in the picture-in-picture modes that always use the 120 Hz mode, where it calls FRCConfigPostFRC
 * itself afterwards) and oled_frc_apply_default_row (apply_now 1).
 */
void panel_api_set_active_row(unsigned char *row, unsigned char apply_now)
{
  unsigned short i;
  unsigned char *new_var;
  for (i = 0; i < ROW_SIZE; i++)
  {
    ((unsigned char *) (&panel_active_row))[i] = (new_var = row)[i];
  }

  dbg_printf("clk %ld, %ld\r\n", panel_active_row.clk_min, panel_active_row.clk_max);
  dbg_printf("Htoal %d %d %d\r\n", panel_active_row.htotal_min, panel_active_row.half_0x22, panel_active_row.htotal_max);
  dbg_printf("Vtoal %d %d %d\r\n", panel_active_row.vtotal_min, panel_active_row.vtotal, panel_active_row.vtotal_max);
  panel_active_row.hblank_part2 = (panel_active_row.hblank_part = ((panel_active_row.htotal_min - panel_active_row.active_size0) / HBLANK_STEP) * HBLANK_PART_FACTOR);
  panel_active_row.vfreq_at_min_clock = ((panel_active_row.clk_min / panel_active_row.htotal_min) / panel_active_row.vtotal_min) * FREQ_FACTOR;
  panel_transform_row();
  if (apply_now)
  {
    panel_output_apply_timing(0);
  }
}
