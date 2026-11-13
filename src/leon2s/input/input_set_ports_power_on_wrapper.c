/* input_set_ports_power_on_wrapper  (FUN_a006d3c8)
 *
 * Set ports 0..6 to the power-on link state.
 * Name basis: derived - forwards to input_set_ports_power_on; called by main init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d3c8 @ 0xa006d3c8, flags -mcpu=v8 -Os -g.
 */

extern int input_set_ports_power_on();

/* Set the port records 0..6 to power on (input_set_ports_power_on); called from the main initialisation. */
void input_set_ports_power_on_wrapper(void)
{
  input_set_ports_power_on();
}
