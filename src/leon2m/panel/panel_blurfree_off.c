/* panel_blurfree_off  (FUN_a0150230)
 *
 * Switch blur reduction off.
 * Name basis: proven - tail call panel_blurfree_set_mode(0, 0); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150230 @ 0xa0150230, flags -mcpu=v8 -O2 -g. The call is a tail call.
 */

extern void panel_blurfree_set_mode(unsigned char, unsigned char);

/* Switch blur reduction off. Nothing calls it. */
void panel_blurfree_off(void)
{
    panel_blurfree_set_mode(0, 0);
}
