/* panel_blurfree_set_cycle_length  (FUN_a014f92c)
 *
 * Store the cycle length of the first PWM signal.
 * Name basis: derived - halfword 0xA802A4B0, the cycle result of panel_blurfree_configure; setting id 12
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short panel_blurfree_cycle_length;

/* Store the value that panel_blurfree_periodic_task and SetPSMMixMode write as the duty of PWM channel 0x18.
 * Called by panel_blurfree_set_parameter, id 12. */
void panel_blurfree_set_cycle_length(unsigned short cycle_length)
{
    panel_blurfree_cycle_length = cycle_length;
}
