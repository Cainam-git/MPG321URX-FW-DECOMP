/* irq_empty_handler_copy38  (FUN_a010983c)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a010983c (leon2m), flags -mcpu=v8 -O2 -g.
 * Source form: an empty void function.
 */

/* Empty routine: returns at once. No call, branch or address word in the image refers to it. */
void irq_empty_handler_copy38(void)
{
}
