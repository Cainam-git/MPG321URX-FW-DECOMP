/* panel_blurfree_set_duty_offset  (FUN_a014f95c)
 *
 * Store the duty offset.
 * Name basis: derived - halfword 0xA802A49E, the offset result of panel_blurfree_configure; setting id 16
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short panel_blurfree_duty_offset;

/* Store the value that panel_blurfree_set_mode (GEN2 on) and panel_blurfree_apply_mode_second_port pass to
 * panel_pwm_set_duty as the duty of the second port.
 * Called by panel_blurfree_set_parameter, id 16. */
void panel_blurfree_set_duty_offset(unsigned short offset)
{
    panel_blurfree_duty_offset = offset;
}
