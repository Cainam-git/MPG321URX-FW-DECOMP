/* irq_empty_handler_copy28  (FUN_a00e0d08)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0d08 @ 0xa00e0d08, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: an empty function body.
 */

/* Return at once; takes no arguments and does nothing. */
void irq_empty_handler_copy28(void)
{
}
