/* irq_empty_handler_copy7  (FUN_a009108c)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; startup_register_app_callbacks registers it as callback slot 2.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: an empty void function.
 */
/* Empty routine: returns at once. Registered as callback slot 2 by startup_register_app_callbacks. */
void irq_empty_handler_copy7(void)
{
}
