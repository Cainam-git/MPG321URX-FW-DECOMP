/* sys_touch_row_and_return  (FUN_a012c118)
 *
 * Call the active-row routine and return the argument.
 * Returns: its argument
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012c118 @ 0xa012c118 (-mcpu=v8 -O2 -g)
 * The extern is declared without a parameter list, as in the decompiler output.
 */
extern int panel_get_active_row();

/* Call panel_get_active_row (its result is not used) and return the first argument. The second is not used. */
int sys_touch_row_and_return(int value, int unused)
{
  panel_get_active_row();
  return value;
}
