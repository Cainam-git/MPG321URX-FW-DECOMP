/* irq_empty_handler_copy13  (FUN_a00bb520)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a00bb520 (leon2m 0xa00bb520-0xa00bb528, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between uart_cmd_build_ok_reply_port2 and uart_cmd_flush_rx_port2. Source form: an empty void function.
 */

/* Does nothing and returns at once. Nothing in the image calls it or stores its address. */
void irq_empty_handler_copy13(void)
{
}
