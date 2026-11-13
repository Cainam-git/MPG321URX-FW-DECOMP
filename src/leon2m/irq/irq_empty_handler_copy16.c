/* irq_empty_handler_copy16  (FUN_a00d5f9c)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a00d5f9c (leon2m 0xa00d5f9c-0xa00d5fa4, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between sys_user_clear_second_picture_request and input_user_apply_port0_option. Source form: an empty void function.
 */

/* Does nothing and returns at once. Nothing in the image calls it or stores its address. */
void irq_empty_handler_copy16(void)
{
}
