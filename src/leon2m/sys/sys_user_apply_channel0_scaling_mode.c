/* sys_user_apply_channel0_scaling_mode  (FUN_a00d58f8)
 *
 * Apply the scaling mode setting to channel 0.
 * Name basis: descriptive - sys_api_set_channel_scaling_mode(0, bits 16..19 of the settings word at +0x34)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d58f8 @ 0xa00d58f8, flags -mcpu=v8 -O2 -g (section default).
 * Tail call of sys_api_set_channel_scaling_mode(0, image_enhancement). The 4-bit value is a bit-field of the word (GCC
 * reads it with lduh); the range ends with the nop that -g leaves after the final call.
 */
/* Settings halfword +0x34 and the halfword before it, as one word (big-endian, fields from the top bit down). */
struct settings_word_0x34 {
    unsigned int bits_31_20 : 12;
    unsigned int image_enhancement : 4;         /* bits 19..16: the Image Enhancement level */
    unsigned int bits_15_12 : 4;
    unsigned int bits_11_0 : 12;
};
extern struct settings_word_0x34 user_settings_image_enhancement;
extern void sys_api_set_channel_scaling_mode(unsigned char, unsigned char);

/*
 * Pass the Image Enhancement level (bits 16..19 of the settings word at +0x34) to
 * sys_api_set_channel_scaling_mode for channel 0.
 */
void sys_user_apply_channel0_scaling_mode(void)
{
    sys_api_set_channel_scaling_mode(0, user_settings_image_enhancement.image_enhancement);
}
