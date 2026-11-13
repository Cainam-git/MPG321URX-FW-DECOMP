/* irq_empty_handler_copy76  (FUN_a014b970)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; called by sys_user_apply_byte_2b_slot5 and
 *   sys_user_apply_byte_2c_slot6 with arguments it ignores.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * leon2m irq_empty_handler_copy76 @ 0xa014b970, section default flags -mcpu=v8 -O2 -g (8 bytes, leaf).
 * Source form: an empty void function (the compiler emits retl; nop).
 */
/*
 * Empty routine: returns at once. Its code is identical to irq_empty_handler.
 * Called by sys_user_apply_byte_2b_slot5 and sys_user_apply_byte_2c_slot6.
 */
void irq_empty_handler_copy76(void)
{
}
