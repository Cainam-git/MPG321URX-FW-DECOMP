/* panel_blurfree_set_on_time  (FUN_a014f888)
 *
 * Store the on-time of the first PWM signal.
 * Name basis: derived - halfword 0xA802A4B2, the 'on' result of panel_blurfree_configure; setting id 2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014f888 @ 0xa014f888, flags -mcpu=v8 -O2 -g. A direct store to the extern symbol.
 */

extern unsigned short panel_blurfree_on_time;

/* Store the on-time of the first PWM signal; called by panel_blurfree_set_parameter. */
void panel_blurfree_set_on_time(unsigned short on_time)
{
    panel_blurfree_on_time = on_time;
}
