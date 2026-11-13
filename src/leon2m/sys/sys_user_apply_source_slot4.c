/* sys_user_apply_source_slot4  (FUN_a00d59d4)
 *
 * Select the source of slot 4 from the settings.
 * Name basis: descriptive - sys_api_select_channel_source(4, settings byte +0x23); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d59d4 @ 0xa00d59d4-0xa00d59f0 (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a tail call. The caller's return address is handed on, so the callee returns straight to this
 * routine's caller; the last word is the nop the compiler places behind such a call sequence.
 */
extern unsigned char user_settings_source_slot4;
extern void sys_api_select_channel_source(unsigned char channel, unsigned char source);

/* Select the source of channel 4 from settings byte +0x23. Nothing in the firmware calls it. */
void sys_user_apply_source_slot4(void)
{
    sys_api_select_channel_source(4, user_settings_source_slot4);
}
