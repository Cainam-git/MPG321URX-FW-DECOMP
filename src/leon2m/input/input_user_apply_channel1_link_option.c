/* input_user_apply_channel1_link_option  (FUN_a00d6000)
 *
 * Apply the link option setting of channel 1.
 * Name basis: descriptive - input_api_set_channel_link_option(1, settings byte +0x50); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d6000 @ 0xa00d6000, flags -mcpu=v8 -O2 -g (section default).
 */

extern unsigned char user_settings_channel1_link_option;
extern void input_api_set_channel_link_option(unsigned char, unsigned char);

/*
 * Pass the link option of channel 1 (settings byte +0x50, user_settings_channel1_link_option) to
 * input_api_set_channel_link_option, which stores it per channel and forwards it for channels whose
 * port record has 0x71 in its byte +0xA. No code calls this routine.
 */
void input_user_apply_channel1_link_option(void)
{
    input_api_set_channel_link_option(1, user_settings_channel1_link_option);
}
