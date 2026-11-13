/* osd_draw_factory_aux0_minutes  (FUN_a008e5b8)
 *
 * Draw factory record byte +0x11 (the minutes count) as two digits.
 *   column
 *   row
 * Note: Nothing calls it.
 * Name basis: descriptive - sprintf "%2ld" of factory record +0x11, which sys_run_app_timer_task counts as
 *   minutes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008e5b8, flags -mcpu=v8 -O3 -g.
 */

#define SPACE_CHAR       ' '
#define DIGIT_TO_FONT    47                     /* '0' - 1: digit d becomes font code d + 1; a space becomes 0 */
extern unsigned char factory_record_aux0_minutes;

extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned short);

/*
 * Draw factory_record_aux0_minutes (the panel error count) as 2 digits.
 * Each space becomes font code 0 and each digit character the font code DIGIT_TO_FONT less, then the 2
 * codes are written to the cells at (column, row).
 *   column, row: first cell
 */
void osd_draw_factory_aux0_minutes(unsigned char column, unsigned char row)
{
  unsigned char text[8];
  unsigned char i;

  sprintf(text, "%2ld", factory_record_aux0_minutes);
  for (i = 0; i < 2; i++) {
    if (text[i] == SPACE_CHAR)
      text[i] = 0;
    else
      text[i] -= DIGIT_TO_FONT;
  }
  osd_api_write_cell_bytes(0, column, row, 2, text, 0);
}
