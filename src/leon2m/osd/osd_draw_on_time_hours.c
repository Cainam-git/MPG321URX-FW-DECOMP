/* osd_draw_on_time_hours  (FUN_a008cdf0)
 *
 * Draw the five-digit hours part of the monitor on-time counter.
 *   column
 *   row
 * Note: Draws the word 0xA802E1A8 shifted right by 8, without a mask, so the minutes byte lands above the
 *   hours; nothing calls it (the info pages have their own copy).
 * Name basis: derived - drawn on the 'Monitor On Time' row (osd_draw_factory_info_page, osd_draw_factory_menu)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008cdf0, flags -mcpu=v8 -O3 -g.
 */

#define SPACE_CHAR       ' '
#define DIGIT_TO_FONT    47                     /* '0' - 1: digit d becomes font code d + 1; a space becomes 0 */
extern unsigned int device_settings_on_time;

extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned short);

/*
 * Draw device_settings_on_time shifted right by 8 (the hours) as 5 digits.
 * Each space becomes font code 0 and each digit character the font code DIGIT_TO_FONT less, then the 5
 * codes are written to the cells at (column, row).
 *   column, row: first cell
 */
void osd_draw_on_time_hours(unsigned char column, unsigned char row)
{
  unsigned char text[8];
  unsigned char i;

  sprintf(text, "%5ld", device_settings_on_time >> 8);
  for (i = 0; i < 5; i++) {
    if (text[i] == SPACE_CHAR)
      text[i] = 0;
    else
      text[i] -= DIGIT_TO_FONT;
  }
  osd_api_write_cell_bytes(0, column, row, 5, text, 0);
}
