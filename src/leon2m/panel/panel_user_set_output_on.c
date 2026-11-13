/* panel_user_set_output_on  (FUN_a00d91fc)
 *
 * Switch the picture output on, or switch the panel off in the proper order.
 * Name basis: derived - on: one pin high; off: pin low, OLED controller off, SYSAPI_PanelOnOffControl(0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d91fc @ 0xa00d91fc, flags -mcpu=v8 -O2 -g.
 * Source form: the routine takes six parameters and hands the last four on unchanged in both calls that end it
 * (the firmware leaves %o2..%o5 untouched before those calls); the callees are declared without a parameter
 * list so that the extra arguments are accepted.
 */
extern void oled_controller_disable(void);
extern void gpio_set_aux_bit0_high();
extern void gpio_set_aux_bit0_low(void);
extern int SYSAPI_PanelOnOffControl();

/*
 * Switch the picture output on, or switch the panel off in the proper order.
 *
 *   on        1: gpio_set_aux_bit0_high and stop there (GPIO port number 0xFF, so no pin changes);
 *             anything else: gpio_set_aux_bit0_low (no pin change either), switch the OLED panel controller's
 *             enable pin off and ask the power sequencer to switch the panel off (SYSAPI_PanelOnOffControl(0, 0): no wait for the end)
 *   unused    not used
 *   pass2..5  not used here; passed on unchanged (see the matching notes)
 *
 * Every call in the image passes 0: menu handlers that apply a setting with the panel off (screen size, PIP/PBP
 * layout, DSC and others) and the application timer task.
 */
void panel_user_set_output_on(unsigned char on, unsigned int unused, unsigned int pass2, unsigned int pass3,
                              unsigned int pass4, unsigned int pass5)
{
  if (on == '\x01') {
    gpio_set_aux_bit0_high(0, 0, pass2, pass3, pass4, pass5);
    return;
  }
  gpio_set_aux_bit0_low();
  oled_controller_disable();
  SYSAPI_PanelOnOffControl(0, 0, pass2, pass3, pass4, pass5);
  return;
}
