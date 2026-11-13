/* irq_empty_vector_handler_copy4  (FUN_a0096300)
 *
 * Return at once: an empty routine, identical in code to irq_empty_vector_handler.
 * Note: Called by hdmi_rx21_service_sync_events with an argument it ignores; its address is stored in no
 *   table.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_vector_handler, not as a
 *   vector entry
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0096300 @ 0xa0096300 (-mcpu=v8 -Os -g).
 * Empty routine: it returns at once. Each empty routine of this kind is its own function in the firmware.
 */

/*
 * Empty routine; it does nothing. Called once, by hdmi_rx21_service_sync_events.
 */
void irq_empty_vector_handler_copy4(void)

{
  return;
}
