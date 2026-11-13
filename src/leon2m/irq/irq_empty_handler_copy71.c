/* irq_empty_handler_copy71  (FUN_a0147a98)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by ddc_handle_request with arguments it ignores.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147a98 @ 0xa0147a98, flags -mcpu=v8 -O2 -g.
 * Source form: an empty void function.
 */

/*
 * Empty routine: it returns at once. ddc_handle_request (ddc_handle_request) calls it with five arguments
 * (the DDC/CI request's address, 0xa0, an offset, a length and a buffer); all are ignored.
 */
void irq_empty_handler_copy71(void)
{
}
