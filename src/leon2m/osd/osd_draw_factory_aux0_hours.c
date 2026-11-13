/* osd_draw_factory_aux0_hours  (FUN_a008e520)
 *
 * Draw factory record halfword +0x12 (the hours count) as five digits.
 *   column
 *   row
 * Note: Nothing calls it.
 * Name basis: derived - factory record +0x12, which sys_run_app_timer_task counts as hours
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008e520, flags -mcpu=v8 -O3 -g.
 */

#define SPACE_CHAR       ' '
#define DIGIT_TO_FONT    47                     /* '0' - 1: digit d becomes font code d + 1; a space becomes 0 */
extern unsigned short factory_record_aux0_hours;

extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned short);

/*
 * Draw factory_record_aux0_hours (the panel check status) as 5 digits.
 * Each space becomes font code 0 and each digit character the font code DIGIT_TO_FONT less, then the 5
 * codes are written to the cells at (column, row).
 *   column, row: first cell
 */
void osd_draw_factory_aux0_hours(unsigned char column, unsigned char row)
{
  unsigned char text[8];
  unsigned char i;

  sprintf(text, "%5ld", factory_record_aux0_hours);
  for (i = 0; i < 5; i++) {
    if (text[i] == SPACE_CHAR)
      text[i] = 0;
    else
      text[i] -= DIGIT_TO_FONT;
  }
  osd_api_write_cell_bytes(0, column, row, 5, text, 0);
}
