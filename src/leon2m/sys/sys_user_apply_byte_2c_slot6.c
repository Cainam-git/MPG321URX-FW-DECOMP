/* sys_user_apply_byte_2c_slot6  (FUN_a00d5b2c)
 *
 * Pass settings byte +0x2C to a routine that is empty in this firmware.
 * Name basis: descriptive - tail call to an empty routine; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5b2c @ 0xa00d5b2c-0xa00d5b48 (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a tail call. The caller's return address is handed on, so the callee returns straight to this
 * routine's caller; the last word is the nop the compiler places behind such a call sequence. The callee is
 * declared without a prototype.
 */
extern unsigned char user_settings_byte_0x2c;
extern void irq_empty_handler_copy76();

/* Pass channel number 6 and settings byte +0x2C to a routine that is empty in this firmware. Nothing calls it. */
void sys_user_apply_byte_2c_slot6(void)
{
    irq_empty_handler_copy76(6, user_settings_byte_0x2c);
}
