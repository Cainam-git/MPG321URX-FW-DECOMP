/* osd_draw_three_digit_number  (FUN_a00b6ec8)
 *
 * Draw a number as three digits at a menu position.
 *   column
 *   row
 *   value
 * Returns: the column
 * Note: Formats with sprintf 'n%3d'; the first byte becomes the length.
 * Name basis: derived - callers are the red/green/blue gain drawers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6ec8 @ 0xa00b6ec8 (-mcpu=v8 -O3 -g)
 * Source form: the result is CONCAT44(row, column) returned as int, so only the column comes back; the
 * parameters are unsigned int and masked to a byte at the call.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define TEXT_MODE_NUMBER 2                      /* text drawing mode used for the numbers */
#define NUMBER_WIDTH     3                      /* characters drawn */
extern int osd_draw_text();
extern void osd_api_set_text_mode();
extern int sprintf();

/*
 * Draw value as a right-aligned number of three characters at (column, row) of the main menu layer.
 * The text is built as a length-prefixed string: sprintf writes "n%3d" and the first byte is then replaced by
 * the length 3. Called by the red, green and blue gain drawers.
 */
int osd_draw_three_digit_number(unsigned int column,unsigned int row,unsigned char value)

{
  unsigned char text [8];
  
  sprintf(text,"n%3d",value);
  text[0] = NUMBER_WIDTH;
  osd_api_set_text_mode(TEXT_MODE_NUMBER,0);
  osd_draw_text(0,column & 0xff,row & 0xff,2,text,0);
  return CONCAT44(row,column);
}
