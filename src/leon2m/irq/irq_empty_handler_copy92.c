/* irq_empty_handler_copy92  (FUN_a0154574)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by sys_refresh_status_and_signal_alive.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0154574, flags -mcpu=v8 -g (unoptimised, like its caller sys_refresh_status_and_signal_alive), so
 * the empty body still gets its own register window (save, ret, restore).
 */
/*
 * Does nothing. Called by sys_refresh_status_and_signal_alive when the link status code is not 0 and the chip
 * revision belongs to class 0x8x.
 */
void irq_empty_handler_copy92(void)
{
}
