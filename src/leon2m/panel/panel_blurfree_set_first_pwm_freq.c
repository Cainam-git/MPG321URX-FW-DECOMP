/* panel_blurfree_set_first_pwm_freq  (FUN_a014f894)
 *
 * Store the frequency of the first PWM signal.
 * Name basis: derived - halfword 0xA802A49C (ucFirstPWMFreq); setting id 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014f894 @ 0xa014f894, flags -mcpu=v8 -O2 -g. A direct store to the extern symbol.
 */

extern unsigned short panel_blurfree_first_pwm_freq;

/* Store the frequency of the first PWM signal (ucFirstPWMFreq); called by panel_blurfree_set_parameter. */
void panel_blurfree_set_first_pwm_freq(unsigned short freq)
{
    panel_blurfree_first_pwm_freq = freq;
}
