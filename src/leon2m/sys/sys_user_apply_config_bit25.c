/* sys_user_apply_config_bit25  (FUN_a00d5e84)
 *
 * Apply settings bit 30 to configuration bit 25 and restart all channels.
 * Name basis: descriptive - sys_api_set_config_bit25_restart_all
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5e84 @ 0xa00d5e84-0xa00d5ea4 (8 words), flags -mcpu=v8 -O2 -g.
 * Source form: bit 30 is a 1-bit bit-field; the call is a tail call and the range ends with the nop that -g
 * leaves after the final call.
 */
/* The settings word user_settings_option_bits (bit 30 is the one used here). */
struct option_bits_word {
    unsigned int bit31 : 1;
    unsigned int bit30 : 1;
    unsigned int rest : 30;
};
extern struct option_bits_word user_settings_option_bits;
extern void sys_api_set_config_bit25_restart_all(unsigned char bit);

/*
 * Pass bit 30 of the settings word user_settings_option_bits to sys_api_set_config_bit25_restart_all, which
 * stores it as bit 25 of the first system configuration word and restarts channels 0 to 3. Called from
 * App_Initialize.
 */
void sys_user_apply_config_bit25(void)
{
    sys_api_set_config_bit25_restart_all(user_settings_option_bits.bit30);
}
