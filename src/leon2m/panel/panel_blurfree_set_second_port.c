/* panel_blurfree_set_second_port  (FUN_a014f968)
 *
 * Store the port of the second PWM signal.
 * Name basis: derived - byte 0xA802A49A (ucSecondPort); setting id 18
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char panel_blurfree_second_port;

/* Store the PWM port that panel_blurfree_set_mode programs in GEN2 mode and clears in GEN1 and off mode.
 * SetPSMMixMode also passes it to panel_pwm_init_group.
 * Called by panel_blurfree_set_parameter, id 18. */
void panel_blurfree_set_second_port(unsigned char port)
{
    panel_blurfree_second_port = port;
}
