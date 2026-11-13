/* panel_blurfree_set_reference_delay  (FUN_a014f938)
 *
 * Store the reference delay.
 * Name basis: descriptive - byte 0xA802CC85, a converted delay from panel_blurfree_configure; setting id 13
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char panel_blurfree_reference_delay;

/* Store the delay that panel_blurfree_apply_channel_delays passes to panel_pwm_set_channel_delay for PWM
 * channel 0x18.
 * Called by panel_blurfree_set_parameter, id 13. */
void panel_blurfree_set_reference_delay(unsigned char delay)
{
    panel_blurfree_reference_delay = delay;
}
