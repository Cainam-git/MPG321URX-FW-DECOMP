/* sys_user_apply_channel3_enable  (FUN_a00d5b9c)
 *
 * Apply the enable setting of channel 3.
 * Name basis: descriptive - sys_api_set_secondary_channel_enable(1, settings byte +0x47); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5b9c @ 0xa00d5b9c-0xa00d5bb8 (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a tail call. The caller's return address is handed on, so the callee returns straight to this
 * routine's caller; the last word is the nop the compiler places behind such a call sequence.
 */
extern unsigned char user_settings_channel3_enable;
extern void sys_api_set_secondary_channel_enable(unsigned char which, unsigned char enable);

/*
 * Apply settings byte +0x47 as the enable value of channel 3 (which = 1 selects channel 3 in
 * sys_api_set_secondary_channel_enable). Nothing calls it.
 */
void sys_user_apply_channel3_enable(void)
{
    sys_api_set_secondary_channel_enable(1, user_settings_channel3_enable);
}
