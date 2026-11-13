/* panel_blurfree_set_mode  (FUN_a0150120)
 *
 * Switch blur reduction off, or on in GEN1 or GEN2 mode, and program the PWM port.
 * Name basis: proven - prints '##BFree_Mode_GEN2_ON', '##BFree_Mode_GEN1_ON', '##BFree_Mode_OFF'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150120, flags -mcpu=v8 -O3 -g.
 * panel_pwm_clear_control takes one argument. One common tail after the if / else; writing it in both arms
 * gives other code. The last call is a tail call.
 */

extern unsigned char panel_blurfree_second_port;
extern unsigned short panel_blurfree_duty_offset;
extern unsigned short panel_blurfree_second_pwm_freq;
extern int dbg_printf();
extern void ConfigScalerPWM(unsigned char, unsigned char, unsigned short, int);
extern void panel_pwm_set_duty(unsigned char, unsigned short);
extern void panel_pwm_enable(unsigned char, int);
extern void panel_pwm_clear_control(unsigned char);
extern void panel_pwm_set_mode_field(unsigned char, int);
extern void panel_pwm_set_control_bit6(unsigned char, int);
extern void panel_blurfree_apply_channel_delays(void);
extern void SetPSMMixMode(int);

/*
 * Switch blur reduction off (on = 0) or on (on = 1) in GEN1 (mode = 0) or GEN2 (mode = 1).
 *
 * GEN2 enables the second PWM port, sets its mode field, duty and frequency. GEN1 and off both clear that
 * port's control. SetPSMMixMode gets 1 for on and 0 for off. In every case the channel delays are written and
 * PWM channel 0x1f is set up last. Called from panel_api_set_blurfree_mode.
 */
void panel_blurfree_set_mode(unsigned char on, unsigned char mode)
{
  if (on == 1) {
    if (mode == 1) {
      dbg_printf("##BFree_Mode_GEN2_ON\r\n");
      panel_pwm_enable(panel_blurfree_second_port, 1);
      panel_pwm_set_mode_field(panel_blurfree_second_port, 1);
      panel_pwm_set_duty(panel_blurfree_second_port, panel_blurfree_duty_offset);
      ConfigScalerPWM(panel_blurfree_second_port, 0xff, panel_blurfree_second_pwm_freq, 0);
    } else {
      dbg_printf("##BFree_Mode_GEN1_ON\r\n");
      panel_pwm_clear_control(panel_blurfree_second_port);
    }
    SetPSMMixMode(1);
  } else {
    dbg_printf("##BFree_Mode_OFF\r\n");
    panel_pwm_clear_control(panel_blurfree_second_port);
    SetPSMMixMode(0);
  }
  panel_blurfree_apply_channel_delays();
  panel_pwm_set_mode_field(0x1f, 1);
  panel_pwm_set_control_bit6(0x1f, 1);
  panel_pwm_enable(0x1f, 1);
}
