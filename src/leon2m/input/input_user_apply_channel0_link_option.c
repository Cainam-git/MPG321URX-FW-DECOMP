/* input_user_apply_channel0_link_option  (FUN_a00d5fe4)
 *
 * Apply the link option setting of channel 0.
 * Name basis: descriptive - input_api_set_channel_link_option(0, settings byte +0x4F); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5fe4 @ 0xa00d5fe4, flags -mcpu=v8 -O2 -g (section default).
 */

extern unsigned char user_settings_channel0_link_option;
extern void input_api_set_channel_link_option(unsigned char, unsigned char);

/*
 * Pass the link option of channel 0 (settings byte +0x4f, user_settings_channel0_link_option) to
 * input_api_set_channel_link_option, which stores it per channel and forwards it for channels whose
 * port record has 0x71 in its byte +0xA. No code calls this routine.
 */
void input_user_apply_channel0_link_option(void)
{
    input_api_set_channel_link_option(0, user_settings_channel0_link_option);
}
