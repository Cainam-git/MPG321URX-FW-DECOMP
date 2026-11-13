/* ldc_set_direct_pwm_off  (FUN_a0132a40)
 *
 * Switch direct PWM of the dimming processor off for argument 1 and on for argument 0 (command 0x60).
 * Name basis: derived - ldc_send_direct_pwm(0) for argument 1, ldc_send_direct_pwm(1) for argument 0, nothing
 *   for any other value
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0132a40 @ 0xa0132a40 (-mcpu=v8 -O2 -g)
 * The call is a normal call inside a register window, not a tail call; the sender is declared without a
 * parameter list.
 */
extern int ldc_send_direct_pwm();

/*
 * Send dimming command 0x60 with the opposite of the argument: 1 for 0, 0 for 1. Any other argument sends
 * nothing. Called by ldc_api_set_direct_pwm.
 */
void ldc_set_direct_pwm_off(unsigned int value)
{
    if (value == 0) {
        ldc_send_direct_pwm(1);
    } else if (value == 1) {
        ldc_send_direct_pwm(0);
    }
}
