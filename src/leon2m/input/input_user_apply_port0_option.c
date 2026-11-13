/* input_user_apply_port0_option  (FUN_a00d5fa4)
 *
 * Apply settings bit 29 to the option of input port 0.
 * Name basis: descriptive - input_api_set_port0_option_bit24; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5fa4 @ 0xa00d5fa4, flags -mcpu=v8 -O2 -g (section default). A leaf that tail-calls the setter.
 */

extern unsigned int user_settings_option_bits;
extern void input_api_set_port0_option_bit24(unsigned int);

/*
 * Pass bit 29 of the option word at settings +4 (user_settings_option_bits) to
 * input_api_set_port0_option_bit24, which keeps it as configuration bit 24 and sends the option of port 0.
 * No code calls this routine.
 */
void input_user_apply_port0_option(void)
{
    input_api_set_port0_option_bit24((user_settings_option_bits >> 29) & 1);
}
