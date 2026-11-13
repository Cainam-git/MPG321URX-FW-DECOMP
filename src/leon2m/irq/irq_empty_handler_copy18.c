/* irq_empty_handler_copy18  (FUN_a00da850)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by oled_power_task with arguments it ignores.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a00da850 (leon2m 0xa00da850-0xa00da858, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Called by oled_power_task. It lies between irq_empty_handler_copy17 and
 * irq_empty_handler_copy19. Source form: an empty void function.
 */

/* Does nothing and returns at once. oled_power_task calls it with three zero arguments, which it ignores. */
void irq_empty_handler_copy18(void)
{
}
