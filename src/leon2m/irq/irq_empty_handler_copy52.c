/* irq_empty_handler_copy52  (FUN_a0125c9c)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by panel_power_sequencer_task.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a0125c9c (leon2m 0xa0125c9c-0xa0125ca4, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Called by panel_power_sequencer_task. It lies between irq_empty_handler_copy51 and
 * irq_empty_handler_copy53. Source form: an empty void function.
 */
/* Empty routine: returns at once. Called by panel_power_sequencer_task. */
void irq_empty_handler_copy52(void)
{
}
