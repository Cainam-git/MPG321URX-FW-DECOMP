/* sys_user_apply_config_bit31  (FUN_a00d5918)
 *
 * Apply settings bit 9 to configuration bit 31.
 * Name basis: descriptive - sys_api_set_config_bit31
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5918 @ 0xa00d5918, flags -mcpu=v8 -O2 -g (section default).
 * Tail call of sys_api_set_config_bit31(bit 9 of the first word of user_settings). Bit 9 is a 1-bit bit-field of the word;
 * the range ends with the nop that -g leaves after the final call.
 */
/* The first word of the user settings record, split around bit 9 (big-endian, fields from the top bit down). */
struct settings_word_0 {
    unsigned int bits_31_10 : 22;
    unsigned int bit_9 : 1;
    unsigned int bits_8_0 : 9;
};
extern struct settings_word_0 user_settings;
extern void sys_api_set_config_bit31(unsigned char);

/* Pass bit 9 of the first word of the user settings to sys_api_set_config_bit31. */
void sys_user_apply_config_bit31(void)
{
    sys_api_set_config_bit31(user_settings.bit_9);
}
