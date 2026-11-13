/* irq_empty_handler_copy59  (FUN_a012c130)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a012c130 (leon2m 0xa012c130-0xa012c138, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between sys_touch_row_and_return and edid_set_port_size_code. Source form: an empty void function.
 */
/* Empty routine: returns at once. Nothing in the image calls it or stores its address. */
void irq_empty_handler_copy59(void)
{
}
