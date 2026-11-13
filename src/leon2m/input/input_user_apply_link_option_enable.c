/* input_user_apply_link_option_enable  (FUN_a00d5fc4)
 *
 * Apply settings bit 28 to the link option enable.
 * Name basis: descriptive - input_api_set_link_option_enable; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5fc4 @ 0xa00d5fc4, flags -mcpu=v8 -O2 -g (section default).
 */

extern unsigned int user_settings_option_bits;
extern void input_api_set_link_option_enable(unsigned char);

/*
 * Pass bit 28 of the option word at settings +4 (user_settings_option_bits) to
 * input_api_set_link_option_enable, which keeps it as configuration bit 23 and sends each channel's link
 * option (or 0 when off). No code calls this routine.
 */
void input_user_apply_link_option_enable(void)
{
    input_api_set_link_option_enable((user_settings_option_bits >> 28) & 1);
}
