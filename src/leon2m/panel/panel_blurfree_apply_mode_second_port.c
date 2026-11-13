/* panel_blurfree_apply_mode_second_port  (FUN_a014fb84)
 *
 * Program the second PWM port for blur-reduction mode 1, otherwise clear its control.
 * Name basis: derived - same calls as the GEN arms of panel_blurfree_set_mode without the prints; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014fb84 @ 0xa014fb84, flags -mcpu=v8 -O3 -g.
 * panel_pwm_clear_control takes one argument; it is a tail call.
 */

extern unsigned char panel_blurfree_second_port;
extern unsigned short panel_blurfree_duty_offset;
extern unsigned short panel_blurfree_second_pwm_freq;
extern void ConfigScalerPWM(unsigned char, unsigned char, unsigned short, int);
extern void panel_pwm_set_duty(unsigned char, unsigned short);
extern void panel_pwm_enable(unsigned char, int);
extern void panel_pwm_clear_control(unsigned char);
extern void panel_pwm_set_mode_field(unsigned char, int);

/*
 * Program the second PWM port when mode is 1; for any other mode clear its control. This is the GEN2 / GEN1
 * part of panel_blurfree_set_mode without the debug prints. Nothing calls it.
 */
void panel_blurfree_apply_mode_second_port(unsigned char mode)
{
    if (mode == 1) {
        panel_pwm_enable(panel_blurfree_second_port, 1);
        panel_pwm_set_mode_field(panel_blurfree_second_port, 1);
        panel_pwm_set_duty(panel_blurfree_second_port, panel_blurfree_duty_offset);
        ConfigScalerPWM(panel_blurfree_second_port, 0xff, panel_blurfree_second_pwm_freq, 0);
        return;
    }
    panel_pwm_clear_control(panel_blurfree_second_port);
}
