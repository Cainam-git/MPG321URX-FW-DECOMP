/* irq_empty_vector_handler_copy7  (FUN_a00abb20)
 *
 * Return at once: an empty routine, identical in code to irq_empty_vector_handler.
 * Note: Called by dp_run_link_state with an argument it ignores; its address is stored in no table.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_vector_handler, not as a
 *   vector entry
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00abb20 @ 0xa00abb20 (-mcpu=v8 -Os -g).
 * Empty routine: it returns at once. Each empty routine of this kind is its own function in the firmware.
 */

/*
 * Empty routine; it does nothing. Called once, by dp_run_link_state.
 */
void irq_empty_vector_handler_copy7(void)

{
  return;
}
