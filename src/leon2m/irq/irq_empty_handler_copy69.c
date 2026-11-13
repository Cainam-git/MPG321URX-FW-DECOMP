/* irq_empty_handler_copy69  (FUN_a01478a8)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by APPActionDispatcher.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01478a8 @ 0xa01478a8, flags -mcpu=v8 -O2 -g.
 * Source form: an empty void function.
 */

/* Empty routine: it returns at once. Called without arguments by APPActionDispatcher (APPActionDispatcher). */
void irq_empty_handler_copy69(void)
{
}
