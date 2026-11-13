/* panel_user_set_pwm7_percent  (FUN_a00da714)
 *
 * Set PWM channel 7 to a percentage.
 * Name basis: descriptive - duty = percent * 10, 0x3FF at 100; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00da714 @ 0xa00da714, flags -mcpu=v8 -O3 -g.
 * Source form: the second duty write is the routine's last statement, a tail call that hands the incoming
 * %o2..%o5 on unchanged; the callee is declared without a parameter list.
 */
extern int panel_pwm_set_duty();

#define PWM_CHANNEL_7  7
#define PWM_DUTY_FULL  0x3ff                /* the largest 10-bit duty value */

/*
 * Set the duty of PWM channel 7 to a percentage.
 *
 *   percent   0..100 (low byte used); the duty value is percent * 10, and 100 gives the full 0x3FF instead of
 *             1000 (written after the 1000)
 *   unused    not used
 *   pass2..5  not used here; passed on unchanged to the last write
 *
 * Nothing in the image calls this routine.
 */
void panel_user_set_pwm7_percent(unsigned int percent, unsigned int unused, unsigned int pass2, unsigned int pass3,
                                 unsigned int pass4, unsigned int pass5)
{
  panel_pwm_set_duty(PWM_CHANNEL_7, (percent & 0xff) * 10);
  if ((percent & 0xff) != 100) {
    return;
  }
  panel_pwm_set_duty(PWM_CHANNEL_7, PWM_DUTY_FULL, pass2, pass3, pass4, pass5);
}
