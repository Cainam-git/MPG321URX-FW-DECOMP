/* irq_empty_handler_copy84  (FUN_a014dd50)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * leon2m irq_empty_handler_copy84 @ 0xa014dd50, section default flags -mcpu=v8 -O2 -g (8 bytes, leaf).
 * Source form: an empty void function (the compiler emits retl; nop).
 */
/*
 * Empty routine: returns at once. Its code is identical to irq_empty_handler.
 * Nothing in the image refers to it: no call, branch or address word.
 */
void irq_empty_handler_copy84(void)
{
}
