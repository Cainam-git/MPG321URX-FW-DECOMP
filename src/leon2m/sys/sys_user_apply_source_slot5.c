/* sys_user_apply_source_slot5  (FUN_a00d59f0)
 *
 * Select the source of slot 5 from the settings.
 * Name basis: descriptive - sys_api_select_channel_source(5, settings byte +0x25); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d59f0 @ 0xa00d59f0-0xa00d5a0c (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a tail call. The caller's return address is handed on, so the callee returns straight to this
 * routine's caller; the last word is the nop the compiler places behind such a call sequence.
 */
extern unsigned char user_settings_source_slot5;
extern void sys_api_select_channel_source(unsigned char channel, unsigned char source);

/* Select the source of channel 5 from settings byte +0x25. Nothing in the firmware calls it. */
void sys_user_apply_source_slot5(void)
{
    sys_api_select_channel_source(5, user_settings_source_slot5);
}
