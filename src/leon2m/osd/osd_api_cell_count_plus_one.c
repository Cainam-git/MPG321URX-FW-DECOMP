/* osd_api_cell_count_plus_one  (FUN_a0146194)
 *
 * Return columns times rows plus one.
 * Returns: product + 1
 * Name basis: descriptive - p1 * p2 + 1; used by the menu drawing code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146194, flags -mcpu=v8 -O3 -g.
 */
/* Return columns * rows + 1.
 * Called by ShowLogo (ShowLogo).
 */
unsigned short osd_api_cell_count_plus_one(short columns, short rows)
{
  return columns * rows + 1;
}
