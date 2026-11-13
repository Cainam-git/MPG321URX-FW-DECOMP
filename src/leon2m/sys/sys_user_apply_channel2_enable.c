/* sys_user_apply_channel2_enable  (FUN_a00d5b80)
 *
 * Apply the enable setting of channel 2.
 * Name basis: descriptive - sys_api_set_secondary_channel_enable(0, settings byte +0x45); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5b80 @ 0xa00d5b80-0xa00d5b9c (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a tail call. The caller's return address is handed on, so the callee returns straight to this
 * routine's caller; the last word is the nop the compiler places behind such a call sequence.
 */
extern unsigned char user_settings_channel2_enable;
extern void sys_api_set_secondary_channel_enable(unsigned char which, unsigned char enable);

/*
 * Apply settings byte +0x45 as the enable value of channel 2 (which = 0 selects channel 2 in
 * sys_api_set_secondary_channel_enable). Nothing calls it.
 */
void sys_user_apply_channel2_enable(void)
{
    sys_api_set_secondary_channel_enable(0, user_settings_channel2_enable);
}
