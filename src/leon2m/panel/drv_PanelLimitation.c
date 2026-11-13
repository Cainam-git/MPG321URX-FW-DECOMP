/* drv_PanelLimitation  (FUN_a01070b4)
 *
 * Compare the current timing with the panel's limits and warn when it is outside.
 * Returns: bit mask of violated limits
 * Name basis: proven - prints the PANEL_MIN / PANEL_MAX warnings (original name from the firmware's text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01070b4 @ 0xa01070b4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on (the types follow where the firmware narrows to 16 bits):
 *  - the callees return unsigned short, except sys_frc_get_output_line_length and _frame_length, declared
 *    int-returning (on the converter path the firmware takes the result with no narrowing);
 *  - clock_mhz is an unsigned int (the firmware zero-extends panel_get_pll_frequency_mhz's result right after the call,
 *    so it is not a signed short); htotal and vtotal are unsigned int;
 *  - htotal is narrowed again at the division: the inline helper calc_hfreq(unsigned int, unsigned short) gives
 *    the same code as a cast; vtotal is narrowed at its compares and prints ((unsigned short)vtotal);
 *  - on the path without the converter the block register goes into the inner local htotal_read, and
 *    'htotal = htotal_read' comes after the "FRC OFF" print (gives the firmware's register assignment);
 *  - sys_frc_get_output_frame_length is called once, on the converter path only.
 */

/* The working copy of the active panel timing row (field names as in panel_output_apply_timing). */
struct panel_timing_row
{
  unsigned char pad00[0x10];
  unsigned long long clk_min;           /* +0x10: pixel clock limits in Hz */
  unsigned long long clk_max;           /* +0x18 */
  unsigned short htotal_min;            /* +0x20: horizontal total limits */
  unsigned short half_0x22;
  unsigned short htotal_max;            /* +0x24 */
  unsigned short hblank_part;
  unsigned short hblank_part2;
  unsigned short vtotal_min;            /* +0x2A: vertical total limits */
  unsigned short vtotal;
  unsigned short vtotal_max;            /* +0x2E */
  unsigned char pad30[0x18];
  unsigned short half_0x48;
  unsigned short hfreq_min;             /* +0x4A: line rate limits, in units of 100 Hz */
  unsigned short hfreq_max;             /* +0x4C */
  unsigned short vfreq_min;             /* +0x4E: refresh rate limits, in tenths of a hertz */
  unsigned short vfreq_max;             /* +0x50 */
  unsigned char pad52[6];
};
extern struct panel_timing_row *panel_working_row_ptr;
extern int input_block_measure_vfreq(int);
extern unsigned char sys_frc_is_running(void);
extern unsigned short panel_get_pll_frequency_mhz(int);
extern unsigned short pq_block_read16(int, int);
extern int sys_frc_get_output_line_length(void);
extern int sys_frc_get_output_frame_length(void);
extern int dbg_printf();
extern unsigned long long __udivdi3(unsigned long long, unsigned long long);

/* Bits of the result: which limit of the panel row is broken. */
#define LIMIT_HFREQ_LOW   0x01
#define LIMIT_HFREQ_HIGH  0x02
#define LIMIT_CLOCK_LOW   0x04
#define LIMIT_CLOCK_HIGH  0x08
#define LIMIT_VFREQ_LOW   0x10
#define LIMIT_VFREQ_HIGH  0x20
#define LIMIT_HTOTAL_LOW  0x40
#define LIMIT_HTOTAL_HIGH 0x80

#define MAIN_CHANNEL      0
#define GPLL_DISPM        0             /* clock generators (panel_get_pll_frequency_mhz) */
#define GPLL_FRC          4
#define BLK_VTOTAL        0x5b          /* picture block registers */
#define BLK_HTOTAL        0x5e
#define FRC_REG_1EC0      (*((volatile unsigned int *) 0xcf011ec0))
#define FRC_VTOTAL_FROM_CLOCK 0x40      /* bit 6 of FRC_REG_1EC0: the vertical total is computed, not read */

/* Line rate in units of 100 Hz from a clock in MHz and a horizontal total. */
static unsigned int calc_hfreq(unsigned int clock_mhz, unsigned short htotal)
{
  return (clock_mhz * 10000) / htotal;
}

/*
 * Compare the input refresh rate and the output timing with the limits of the active panel row, print a
 * warning for each limit that is broken, and return the bits of the broken limits (vertical total: warning
 * only, no bit).
 *
 * Without the frame-rate converter the output values are the main display clock and picture block 0's
 * totals; with it, the converter's clock and its output line and frame lengths (the frame length is computed
 * from the clock and the input refresh rate when bit 6 of FRC_REG_1EC0 is set).
 *
 * Its caller panel_api_check_limitation (from APPActionDispatcher) drops the result: the check only reports.
 */
unsigned char drv_PanelLimitation(void)
{
  unsigned short input_vfreq;
  unsigned short hfreq;
  unsigned int clock_mhz;
  unsigned int htotal;
  unsigned int vtotal;
  unsigned int limit_mhz;
  unsigned short htotal16;
  unsigned char violations = 0;
  input_vfreq = input_block_measure_vfreq(MAIN_CHANNEL);
  if (input_vfreq < panel_working_row_ptr->vfreq_min)
  {
    dbg_printf("\033[1;33mwarning: input vfreq(%d) < PANEL_MIN_VFREQ(%d)\r\n", input_vfreq, panel_working_row_ptr->vfreq_min);
    violations = LIMIT_VFREQ_LOW;
  }
  if (panel_working_row_ptr->vfreq_max < input_vfreq)
  {
    violations |= LIMIT_VFREQ_HIGH;
    dbg_printf("\033[1;33mwarning: input vfreq(%d) > PANEL_MAX_VFREQ(%d)\r\n", input_vfreq, panel_working_row_ptr->vfreq_max);
  }
  if (sys_frc_is_running() == 0)
  {
    unsigned int htotal_read;

    clock_mhz = panel_get_pll_frequency_mhz(GPLL_DISPM);
    htotal_read = pq_block_read16(MAIN_CHANNEL, BLK_HTOTAL);
    vtotal = pq_block_read16(MAIN_CHANNEL, BLK_VTOTAL);
    dbg_printf("[drv_PanelLimitation] FRC OFF\r\n");
    htotal = htotal_read;
  }
  else
  {
    clock_mhz = panel_get_pll_frequency_mhz(GPLL_FRC);
    htotal = sys_frc_get_output_line_length();
    vtotal = sys_frc_get_output_frame_length();
    /* Lines per frame = line rate / refresh rate (100 Hz units over tenths of a hertz, hence * 1000). */
    if (FRC_REG_1EC0 & FRC_VTOTAL_FROM_CLOCK)
    {
      vtotal = (calc_hfreq(clock_mhz, htotal) * 1000) / input_vfreq;
    }
    dbg_printf("[drv_PanelLimitation] FRC ON\r\n");
  }
  htotal16 = htotal;
  hfreq = calc_hfreq(clock_mhz, htotal16);
  if (hfreq < panel_working_row_ptr->hfreq_min)
  {
    dbg_printf("\033[1;33mwarning: display hfreq(%d) < PANEL_MIN_HFREQ(%d)\r\n", hfreq, panel_working_row_ptr->hfreq_min);
    violations |= LIMIT_HFREQ_LOW;
  }
  if (panel_working_row_ptr->hfreq_max < hfreq)
  {
    dbg_printf("\033[1;33mwarning: display hfreq(%d) > PANEL_MAX_HFREQ(%d)\r\n", hfreq, panel_working_row_ptr->hfreq_max);
    violations |= LIMIT_HFREQ_HIGH;
  }
  /* The row's clock limits are in Hz, the measured clock in MHz. */
  limit_mhz = panel_working_row_ptr->clk_min / 1000000;
  if (clock_mhz < limit_mhz)
  {
    dbg_printf("\033[1;31mwarning: display out of range (%d) < (%d)\r\n", clock_mhz, limit_mhz);
    violations |= LIMIT_CLOCK_LOW;
  }
  limit_mhz = panel_working_row_ptr->clk_max / 1000000;
  if (limit_mhz < clock_mhz)
  {
    dbg_printf("\033[1;31mwarning: display out of range (%d) > (%d)\r\n", clock_mhz, limit_mhz);
    violations |= LIMIT_CLOCK_HIGH;
  }
  if (htotal16 < panel_working_row_ptr->htotal_min)
  {
    dbg_printf("\033[1;33mwarning: display htotal(%d) < PANEL_MIN_HTOTAL(%d)\r\n", htotal16, panel_working_row_ptr->htotal_min);
    violations |= LIMIT_HTOTAL_LOW;
  }
  if (panel_working_row_ptr->htotal_max < htotal16)
  {
    dbg_printf("\033[1;33mwarning: display htotal(%d) > PANEL_MAX_HTOTAL(%d)\r\n", htotal16, panel_working_row_ptr->htotal_max);
    violations |= LIMIT_HTOTAL_HIGH;
  }
  if (((unsigned short) vtotal) < panel_working_row_ptr->vtotal_min)
  {
    dbg_printf("\033[1;33mwarning: display vtotal(%d) < PANEL_MIN_VTOTAL(%d)\r\n", (unsigned short) vtotal, panel_working_row_ptr->vtotal_min);
  }
  if (panel_working_row_ptr->vtotal_max < ((unsigned short) vtotal))
  {
    dbg_printf("\033[1;33mwarning: display vtotal(%d) > PANEL_MAX_VTOTAL(%d)\r\n", (unsigned short) vtotal, panel_working_row_ptr->vtotal_max);
  }
  return violations;
}
