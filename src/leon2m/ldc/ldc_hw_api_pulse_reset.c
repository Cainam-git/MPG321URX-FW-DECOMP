/* ldc_hw_api_pulse_reset  (FUN_a014e7d0)
 *
 * Pulse the reset bit of the grid block for five ticks.
 * Name basis: descriptive - forwards to ldc_hw_pulse_reset
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e7d0 @ 0xa014e7d0, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: the callee is declared with an empty parameter list returning int.
 */
extern int ldc_hw_pulse_reset();

/*
 * Pulse the reset bit of the grid block (a plain forward to ldc_hw_pulse_reset).
 * Called by GMDHEnableFRC and sys_mode_apply_converter_setup.
 */
void ldc_hw_api_pulse_reset(void)

{
  ldc_hw_pulse_reset();
  return;
}
