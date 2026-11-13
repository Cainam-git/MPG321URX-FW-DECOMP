/* irq_empty_handler_copy14  (FUN_a00bf2c8)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a00bf2c8 (leon2m 0xa00bf2c8-0xa00bf2d0, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between UartSetI2CEnable and uart_cmd_get_byte_0x18. Source form: an empty void function.
 */

/* Does nothing and returns at once. Nothing in the image calls it or stores its address. */
void irq_empty_handler_copy14(void)
{
}
