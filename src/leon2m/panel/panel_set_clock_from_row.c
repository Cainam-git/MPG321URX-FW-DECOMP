/* panel_set_clock_from_row  (FUN_a0102f6c)
 *
 * Program the display clocks from the clock field of the working panel timing row.
 * Name basis: derived - value from row fields +0x34 and +0x22; used by the OLED refresh-rate handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0102f6c @ 0xa0102f6c, flags -mcpu=v8 -O3 -g.
 * Source form: panel_working_row_ptr is declared as an unsigned int and the two row fields are read through
 * casts of it plus the offset (the macros below); the callee is declared without a prototype.
 */
extern unsigned int panel_working_row_ptr;
extern void panel_set_pll_frequency();

/* Fields of the working copy of the active panel timing row. */
#define ROW_WORD_0X34 (*(unsigned int *)(panel_working_row_ptr + 0x34))     /* / 10 * htotal = clock in Hz */
#define ROW_HTOTAL    (*(unsigned short *)(panel_working_row_ptr + 0x22))   /* horizontal total */

/*
 * Program the four display clock generators for the active panel timing row.
 *
 * The output clock in Hz is row word +0x34 divided by 10, times the row's horizontal total. GPLL_DISPM gets the
 * full clock, GPLL_DISP1 and GPLL_DISP2 half of it, GPLL_DISP3 a quarter (panel_set_pll_frequency).
 *
 * The only caller is oled_frc_task, after it has applied the output timing again.
 */
void panel_set_clock_from_row(void)
{
  unsigned int output_clock;

  output_clock = (ROW_WORD_0X34 / 10) * (unsigned int)ROW_HTOTAL;
  panel_set_pll_frequency(0, output_clock);
  panel_set_pll_frequency(1, output_clock >> 1);
  panel_set_pll_frequency(2, output_clock >> 1);
  panel_set_pll_frequency(3, output_clock >> 2);
}
