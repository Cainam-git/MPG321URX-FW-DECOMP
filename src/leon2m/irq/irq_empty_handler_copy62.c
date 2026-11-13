/* irq_empty_handler_copy62  (FUN_a0132a28)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a0132a28 (leon2m 0xa0132a28-0xa0132a30, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between sys_call_empty_hook and uart_cmd_return_zero_copy31. Source form: an empty void function.
 */
/* Empty routine: returns at once. Nothing in the image calls it or stores its address. */
void irq_empty_handler_copy62(void)
{
}
