/* irq_empty_handler_copy9  (FUN_a00ba9d0)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: an empty void function.
 */
/* Empty routine: returns at once. No other routine in the source calls it or takes its address. */
void irq_empty_handler_copy9(void)
{
}
