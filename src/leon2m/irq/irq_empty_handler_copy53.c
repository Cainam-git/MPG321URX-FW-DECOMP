/* irq_empty_handler_copy53  (FUN_a0125ca4)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by oled_power_task.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a0125ca4 (leon2m 0xa0125ca4-0xa0125cac, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Called by oled_power_task. It lies between irq_empty_handler_copy52 and
 * irq_empty_handler_copy54. Source form: an empty void function.
 */
/* Empty routine: returns at once. Called by oled_power_task. */
void irq_empty_handler_copy53(void)
{
}
