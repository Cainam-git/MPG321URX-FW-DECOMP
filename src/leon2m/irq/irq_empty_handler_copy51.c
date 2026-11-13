/* irq_empty_handler_copy51  (FUN_a0125c94)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by panel_power_sequencer_task.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a0125c94 (leon2m 0xa0125c94-0xa0125c9c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Called by panel_power_sequencer_task. It lies between sys_poll_events_stub_copy13 and
 * irq_empty_handler_copy52. Source form: an empty void function.
 */
/* Empty routine: returns at once. Called by panel_power_sequencer_task. */
void irq_empty_handler_copy51(void)
{
}
