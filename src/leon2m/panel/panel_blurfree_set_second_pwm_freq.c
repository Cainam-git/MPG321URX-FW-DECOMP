/* panel_blurfree_set_second_pwm_freq  (FUN_a014f950)
 *
 * Store the frequency of the second PWM signal as given to ConfigScalerPWM.
 * Note: panel_blurfree_configure stores its usSecondPWMFreq parameter times 100 in the same halfword.
 * Name basis: derived - halfword 0xA802A4A0 (usSecondPWMFreq x 100), passed to ConfigScalerPWM as the
 *   frequency; setting id 17
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short panel_blurfree_second_pwm_freq;

/* Store the frequency that panel_blurfree_set_mode (GEN2 on) and panel_blurfree_apply_mode_second_port pass
 * to ConfigScalerPWM for the second port.
 * Called by panel_blurfree_set_parameter, id 17. */
void panel_blurfree_set_second_pwm_freq(unsigned short freq)
{
    panel_blurfree_second_pwm_freq = freq;
}
