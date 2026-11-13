/* ldc_api_set_direct_pwm  (FUN_a014dbf4)
 *
 * Switch direct PWM of the dimming processor on for argument 1, off for every other value.
 *   enable: 1 switches direct PWM on; every other value off
 * Name basis: derived - ldc_set_direct_pwm_off(0) for the argument 1, else ldc_set_direct_pwm_off(1); command
 *   0x60 through mailbox portal 2, slot 0x20
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014dbf4, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: an if/else of two calls (GCC merges them into one call with the
 * argument chosen by a branch, as in the firmware).
 */
extern void ldc_set_direct_pwm_off(unsigned int on);

/*
 * Switch direct PWM of the dimming processor on when the argument is 1 and off for every other value:
 * ldc_set_direct_pwm_off gets 0 or 1 and sends command 0x60 with the opposite (1 = direct PWM on).
 * Called by APPBlurFree_AfterMute and panel_blurfree_apply_user_mode.
 */
void ldc_api_set_direct_pwm(unsigned char enable)
{
    if (enable == 1)
        ldc_set_direct_pwm_off(0);
    else
        ldc_set_direct_pwm_off(1);
}
