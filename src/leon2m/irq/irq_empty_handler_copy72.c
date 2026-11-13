/* irq_empty_handler_copy72  (FUN_a0148350)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by APPActionDispatcher with arguments it ignores.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148350 @ 0xa0148350, flags -mcpu=v8 -O2 -g.
 * Source form: an empty void function.
 */

/*
 * Empty routine: it returns at once. APPActionDispatcher (APPActionDispatcher) calls it with 0, 1 or 2 in the three
 * flag-29 actions (APP_ACTION_FLAG29_0..2); the argument is ignored.
 */
void irq_empty_handler_copy72(void)
{
}
