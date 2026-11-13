/* panel_blurfree_set_pwm_freq_ch16  (FUN_a014fa84)
 *
 * Set the PWM frequency of channel 0x10.
 * Name basis: derived - tail call ConfigScalerPWM(0x10, 0xff, freq, 0); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014fa84 @ 0xa014fa84, flags -mcpu=v8 -O2 -g.
 * ConfigScalerPWM is a tail call; freq is an unsigned short parameter (shifted left and right by 16).
 */

extern void ConfigScalerPWM(unsigned char, unsigned char, unsigned int, unsigned int);

/* Set the PWM frequency of channel 0x10. Nothing calls it. */
void panel_blurfree_set_pwm_freq_ch16(unsigned short freq)
{
    ConfigScalerPWM(0x10, 0xff, freq, 0);
}
