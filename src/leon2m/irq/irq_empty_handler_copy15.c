/* irq_empty_handler_copy15  (FUN_a00d5ea4)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5ea4 @ 0xa00d5ea4-0xa00d5eac (2 words).
 * Empty function without parameters: returns at once (retl with a nop in the delay slot).
 * It directly follows sys_user_apply_config_bit25 in the image; no direct calls to it were found in the code.
 * Data used: none.
 */

/* Does nothing and returns at once. No direct call to it was found. */
void irq_empty_handler_copy15(void)
{
}
