/* irq_empty_handler_copy21  (FUN_a00da868)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by oled_power_task with arguments it ignores.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a00da868 (leon2m 0xa00da868-0xa00da870, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Empty routine: returns at once (retl; nop). Called by oled_power_task (2 calls). It lies between irq_empty_handler_copy20 and
 * sys_led_bar_get_status_code. Source form: an empty void function.
 */

/* Does nothing and returns at once. oled_power_task calls it with three arguments, which it ignores. */
void irq_empty_handler_copy21(void)
{
}
