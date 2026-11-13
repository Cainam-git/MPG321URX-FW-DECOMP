/* irq_empty_vector_handler_copy5  (FUN_a00a0558)
 *
 * Return at once: an empty routine, identical in code to irq_empty_vector_handler.
 * Note: Called by hdmi_rx21_set_port_enable with an argument it ignores; its address is stored in no table.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_vector_handler, not as a
 *   vector entry
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0558 @ 0xa00a0558 (-mcpu=v8 -Os -g).
 * Empty routine: it returns at once. Each empty routine of this kind is its own function in the firmware.
 */

/*
 * Empty routine; it does nothing. Called once, by hdmi_rx21_set_port_enable.
 */
void irq_empty_vector_handler_copy5(void)

{
  return;
}
