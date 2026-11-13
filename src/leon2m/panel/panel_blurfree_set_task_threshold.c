/* panel_blurfree_set_task_threshold  (FUN_a014f944)
 *
 * Store the threshold the periodic blur-reduction task compares against.
 * Name basis: derived - halfword 0xA802A4A2, read only by panel_blurfree_periodic_task; setting id 14
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short panel_blurfree_task_threshold;

/* Store the limit that panel_blurfree_periodic_task compares its argument against. It is the only reader.
 * Called by panel_blurfree_set_parameter, id 14. */
void panel_blurfree_set_task_threshold(unsigned short threshold)
{
    panel_blurfree_task_threshold = threshold;
}
