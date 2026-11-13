/* osd_draw_number_2digits  (FUN_a008cc28)
 *
 * Draw a number as two digits at a menu text position.
 *   column
 *   row
 *   value
 * Note: Unused copy; the menus inline this code.
 * Name basis: derived - format '%2ld', digit font codes c - 47
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008cc28, flags -mcpu=v8 -O2 -g.
 * Source form: the firmware ends with a real nop after the last call (asm nop here, not a delay slot).
 */

#define SPACE_CHAR       ' '
#define DIGIT_TO_FONT    47                     /* '0' - 1: digit d becomes font code d + 1; a space becomes 0 */

extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned short);

/*
 * Draw a number as 2 digits (blank-padded on the left).
 * Each space becomes font code 0 and each digit character the font code DIGIT_TO_FONT less, then the 2
 * codes are written to the cells at (column, row).
 *   column, row: first cell
 */
void osd_draw_number_2digits(unsigned char column, unsigned char row, unsigned short value)
{
  unsigned char text[8];
  unsigned char i;

  sprintf(text, "%2ld", value);
  for (i = 0; i < 2; i++) {
    if (text[i] == SPACE_CHAR)
      text[i] = 0;
    else
      text[i] -= DIGIT_TO_FONT;
  }
  osd_api_write_cell_bytes(0, column, row, 2, text, 0);
  __asm__ volatile ("nop");
}
