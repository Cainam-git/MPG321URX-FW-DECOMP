/* irq_empty_handler_copy55  (FUN_a0126310)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a0126310 (leon2m 0xa0126310-0xa0126318, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between input_get_key_table_entry and switchdataD_a0126318. Source form: an empty void function.
 */
/* Empty routine: returns at once. Nothing in the image calls it or stores its address. */
void irq_empty_handler_copy55(void)
{
}
