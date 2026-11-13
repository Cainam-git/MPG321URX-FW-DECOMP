/* startup_init_converter_sources  (FUN_a00fd558)
 *
 * Reset the converter's source fields, switch the V-by-One receiver off and print a message.
 * Name basis: derived - called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fd558, flags -mcpu=v8 -O3 -g.
 * The print is a tail call with one argument (only %o0 is set).
 */
extern void dbg_printf(const char *, ...);
extern void sys_frc_init_control_number_fields(void);
extern void panel_pwm_enable(int, int);
extern void Vx1RxPowerOff(void);

/*
 * Start-up step: reset the converter's source fields, write 0xB to the register 0xCF00ED84, switch the V-by-One
 * receiver off, call panel_pwm_enable(0, 1) and print "ScalerInitialize".
 */
void startup_init_converter_sources(void)
{
  sys_frc_init_control_number_fields();
  *(volatile unsigned int *)0xcf00ed84 = 0xb;
  Vx1RxPowerOff();
  panel_pwm_enable(0, 1);
  dbg_printf("\rScalerInitialize\r\n");
}
