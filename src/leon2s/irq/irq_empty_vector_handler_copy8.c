/* irq_empty_vector_handler_copy8  (FUN_a00abb28)
 *
 * Return at once: an empty routine, identical in code to irq_empty_vector_handler.
 * Note: Called by dp_flag_port_stream_reset with an argument it ignores; its address is stored in no table.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_vector_handler, not as a
 *   vector entry
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00abb28 @ 0xa00abb28 (-mcpu=v8 -Os -g).
 * Empty routine: it returns at once. Each empty routine of this kind is its own function in the firmware.
 */

/*
 * Empty routine; it does nothing. Called once, by dp_flag_port_stream_reset.
 */
void irq_empty_vector_handler_copy8(void)

{
  return;
}
