/* sys_api_set_pwm7_duty  (FUN_a0148d34)
 *
 * Write a duty value to PWM channel 7 for selector 0..2.
 * Name basis: descriptive - tail call to the PWM value write with channel 7; unused
 *
 * Matching notes
 * --------------
 * FUN_a0148d34 (leon2m 0xa0148d34-0xa0148d98, 100 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Nothing in the image refers to this routine. Source form: a switch with a separate call per case
 * (GCC merges them).
 */
#define PWM_CHANNEL_7 7

extern void panel_pwm_set_duty(unsigned char channel, unsigned short duty);

/* For selector 0, 1 or 2 call panel_pwm_set_duty(7, duty) (the same call in all three cases); any other
 * selector does nothing. Nothing calls this routine. */
void sys_api_set_pwm7_duty(unsigned char selector, unsigned short duty)
{
    switch (selector) {
    case 0:
        panel_pwm_set_duty(PWM_CHANNEL_7, duty);
        break;
    case 1:
        panel_pwm_set_duty(PWM_CHANNEL_7, duty);
        break;
    case 2:
        panel_pwm_set_duty(PWM_CHANNEL_7, duty);
        break;
    }
}
