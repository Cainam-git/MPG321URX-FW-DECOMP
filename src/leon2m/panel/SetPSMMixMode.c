/* SetPSMMixMode  (FUN_a014fe78)
 *
 * Switch the PSM mix mode on or off and program the PWM channels for it.
 * Name basis: proven - prints '##SetPSMMixMode_ON' / '##SetPSMMixMode_OFF' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014fe78 @ 0xa014fe78, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the signature has six parameters: the firmware forwards the incoming argument registers 2..6 unchanged to
 *    panel_blurfree_enable_channels, which is declared without a prototype; callers pass one argument;
 *  - the on-time is read once into a local (on_time) after the print and used for the seven duty writes of the
 *    channel mask; the first write in each arm reads the variable again;
 *  - the seven mask tests are separate ifs in each arm (no loop), and the on arm and the off arm each have their
 *    own copy;
 *  - panel_pwm_init_group is called with an argument although it takes none.
 */

#define PWM_GROUP_FIRST         0x10    /* first PWM channel of the group the blur reduction uses (mask bit 0) */
#define PWM_CHANNEL_REFERENCE   0x18    /* PWM channel 24, which gets the cycle length */
#define PWM_NO_PIN              0xff    /* ConfigScalerPWM: leave the output pins alone */
#define PWM_CLOCK_REFCLK_12MHZ  0       /* ConfigScalerPWM: clock source 0, the 12 MHz clock */

extern unsigned char panel_blurfree_second_port;
extern unsigned char panel_blurfree_reversed_mode;
extern unsigned char panel_blurfree_second_channel_mask;
extern unsigned short panel_blurfree_first_pwm_freq;
extern unsigned short panel_blurfree_cycle_length;
extern unsigned short panel_blurfree_on_time;
extern int dbg_printf();
extern int ConfigScalerPWM();
extern int panel_pwm_set_duty();
extern int panel_pwm_init_group();
extern int panel_blurfree_set_channel_output_mode();
extern int panel_blurfree_enable_channels();

/*
 * Set up the PWM channels of the blur reduction for the switched-on or switched-off state. Called by
 * panel_blurfree_set_mode with one argument (1 for GEN1 and GEN2 on, 0 for off).
 *
 *   on         1: switch on; any other value: switch off
 *   forwarded_arg2 .. forwarded_arg6
 *              not used here; handed on unchanged to panel_blurfree_enable_channels (see the matching notes)
 *
 * Always: panel_pwm_init_group (fixed start values of the grouped PWM channels).
 * On:  print "##SetPSMMixMode_ON"; set up PWM channel 0x10 for the first PWM frequency (no pin change, 12 MHz
 *      clock); give each channel 0x10 + n whose bit n (0..6) is set in the second channel mask the duty
 *      panel_blurfree_on_time; give channel 0x18 the cycle length; set the output mode of the channels of the
 *      main channel mask to 1; enable them with the "reversed mode" value.
 * Off: print "##SetPSMMixMode_OFF"; the same duty writes for the channels of the second channel mask; output
 *      mode 0 and enable value 0 for the channels of the main channel mask.
 */
void SetPSMMixMode(unsigned char on, unsigned int forwarded_arg2, unsigned int forwarded_arg3, unsigned int forwarded_arg4,
                 unsigned int forwarded_arg5, unsigned int forwarded_arg6)

{
  unsigned short on_time;

  panel_pwm_init_group(panel_blurfree_second_port);
  if (on == 1) {
    dbg_printf("##SetPSMMixMode_ON\r\n");
    ConfigScalerPWM(PWM_GROUP_FIRST, PWM_NO_PIN, panel_blurfree_first_pwm_freq, PWM_CLOCK_REFCLK_12MHZ);
    on_time = panel_blurfree_on_time;
    if ((panel_blurfree_second_channel_mask & 1) != 0) {
      panel_pwm_set_duty(PWM_GROUP_FIRST + 0, panel_blurfree_on_time);
    }
    if ((panel_blurfree_second_channel_mask & 2) != 0) {
      panel_pwm_set_duty(PWM_GROUP_FIRST + 1, on_time);
    }
    if ((panel_blurfree_second_channel_mask & 4) != 0) {
      panel_pwm_set_duty(PWM_GROUP_FIRST + 2, on_time);
    }
    if ((panel_blurfree_second_channel_mask & 8) != 0) {
      panel_pwm_set_duty(PWM_GROUP_FIRST + 3, on_time);
    }
    if ((panel_blurfree_second_channel_mask & 0x10) != 0) {
      panel_pwm_set_duty(PWM_GROUP_FIRST + 4, on_time);
    }
    if ((panel_blurfree_second_channel_mask & 0x20) != 0) {
      panel_pwm_set_duty(PWM_GROUP_FIRST + 5, on_time);
    }
    if ((panel_blurfree_second_channel_mask & 0x40) != 0) {
      panel_pwm_set_duty(PWM_GROUP_FIRST + 6, on_time);
    }
    panel_pwm_set_duty(PWM_CHANNEL_REFERENCE, panel_blurfree_cycle_length);
    panel_blurfree_set_channel_output_mode(1);
    panel_blurfree_enable_channels(panel_blurfree_reversed_mode, forwarded_arg2, forwarded_arg3, forwarded_arg4, forwarded_arg5, forwarded_arg6);
    return;
  }
  dbg_printf("##SetPSMMixMode_OFF\r\n");
  on_time = panel_blurfree_on_time;
  if ((panel_blurfree_second_channel_mask & 1) != 0) {
    panel_pwm_set_duty(PWM_GROUP_FIRST + 0, panel_blurfree_on_time);
  }
  if ((panel_blurfree_second_channel_mask & 2) != 0) {
    panel_pwm_set_duty(PWM_GROUP_FIRST + 1, on_time);
  }
  if ((panel_blurfree_second_channel_mask & 4) != 0) {
    panel_pwm_set_duty(PWM_GROUP_FIRST + 2, on_time);
  }
  if ((panel_blurfree_second_channel_mask & 8) != 0) {
    panel_pwm_set_duty(PWM_GROUP_FIRST + 3, on_time);
  }
  if ((panel_blurfree_second_channel_mask & 0x10) != 0) {
    panel_pwm_set_duty(PWM_GROUP_FIRST + 4, on_time);
  }
  if ((panel_blurfree_second_channel_mask & 0x20) != 0) {
    panel_pwm_set_duty(PWM_GROUP_FIRST + 5, on_time);
  }
  if ((panel_blurfree_second_channel_mask & 0x40) != 0) {
    panel_pwm_set_duty(PWM_GROUP_FIRST + 6, on_time);
  }
  panel_blurfree_set_channel_output_mode(0);
  panel_blurfree_enable_channels(0, forwarded_arg2, forwarded_arg3, forwarded_arg4, forwarded_arg5, forwarded_arg6);
  return;
}
