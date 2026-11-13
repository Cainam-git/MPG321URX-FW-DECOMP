/* sys_user_apply_byte_2d_slot5  (FUN_a00d5b48)
 *
 * Pass settings byte +0x2D to a routine that is empty in this firmware.
 * Name basis: descriptive - tail call to an empty routine; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5b48 @ 0xa00d5b48-0xa00d5b64 (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a tail call. The caller's return address is handed on, so the callee returns straight to this
 * routine's caller; the last word is the nop the compiler places behind such a call sequence. The callee is
 * declared without a prototype.
 */
extern unsigned char user_settings_byte_0x2d;
extern void irq_empty_handler_copy77();

/* Pass channel number 5 and settings byte +0x2D to a routine that is empty in this firmware. Nothing calls it. */
void sys_user_apply_byte_2d_slot5(void)
{
    irq_empty_handler_copy77(5, user_settings_byte_0x2d);
}
