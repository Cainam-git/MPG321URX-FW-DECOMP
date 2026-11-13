/* panel_api_get_active_size  (FUN_a014837c)
 *
 * Return the first or second 16-bit size field of the active panel timing row.
 * Returns: size, 0 for another selector
 * Name basis: derived - halfwords +8 and +0xA of the active row at 0xA802E378
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014837c @ 0xa014837c-0xa01483b8 (15 words), flags -mcpu=v8 -O3 -g. A leaf.
 * Source form: a switch with case 0 first and a preset result of 0 (if/else chains in either order, or a switch
 * with case 1 first, give other code); the result is zero-extended on the shared exit.
 */
extern unsigned short panel_active_row_active_width;
extern unsigned short panel_active_row_active_lines;

/*
 * Return one of the two size fields of the active panel timing row: halfword +8 for selector 0, halfword +0xA
 * for selector 1, 0 for any other selector. The first is the width and the second the number of lines of the
 * row (see the timing row fields set in panel_api_set_active_row).
 *
 *   which  0: halfword +8, 1: halfword +0xA
 */
unsigned short panel_api_get_active_size(unsigned char which)
{
  unsigned short size = 0;

  switch (which) {
  case 0:
    size = panel_active_row_active_width;
    break;
  case 1:
    size = panel_active_row_active_lines;
    break;
  }
  return size;
}
