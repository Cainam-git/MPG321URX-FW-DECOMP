/* osd_draw_on_time_minutes  (FUN_a008ccc0)
 *
 * Draw the two-digit minutes part of the monitor on-time counter.
 *   column
 *   row
 * Note: Top byte of the word 0xA802E1A8 in the saved settings; inlined in the info pages.
 * Name basis: derived - drawn next to 'Monitor On Time' with the 5-digit field (osd_draw_factory_info_page)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ccc0, flags -mcpu=v8 -O3 -g.
 */

#define SPACE_CHAR       ' '
#define DIGIT_TO_FONT    47                     /* '0' - 1: digit d becomes font code d + 1; a space becomes 0 */
extern unsigned char device_settings_on_time;

extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned short);

/*
 * Draw the first byte of device_settings_on_time (the minutes) as 2 digits.
 * Each space becomes font code 0 and each digit character the font code DIGIT_TO_FONT less, then the 2
 * codes are written to the cells at (column, row).
 *   column, row: first cell
 */
void osd_draw_on_time_minutes(unsigned char column, unsigned char row)
{
  unsigned char text[8];
  unsigned char i;

  sprintf(text, "%2ld", device_settings_on_time);
  for (i = 0; i < 2; i++) {
    if (text[i] == SPACE_CHAR)
      text[i] = 0;
    else
      text[i] -= DIGIT_TO_FONT;
  }
  osd_api_write_cell_bytes(0, column, row, 2, text, 0);
}
