/* sys_api_set_channel_scaling_mode  (FUN_a0149064)
 *
 * Store the mode 0..4 of channel 0 or 1 and apply it.
 * Name basis: descriptive - 4-bit fields in stSysConfig word +4, then the per-channel mode routine; same as
 *   command 14 of sys_api_config
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149064 @ 0xa0149064 (-mcpu=v8 -O3 -g).
 * Source form: the switch on the mode assigns each value back to itself (needed for the compare chain); switch (ch)
 * has case 0 only storing and breaking to the shared final call, and case 1 storing, calling
 * sys_set_channel_path_mode(1, mode) itself and returning. The block-reorder pass copies the shared call into case 0.
 */
/* Word +4 of the system configuration record: three 4-bit fields. */
struct sys_config_words {
    unsigned int word_0;
    struct {
        unsigned int converter_mode : 4;        /* bits 28..31 */
        unsigned int path_mode_ch0 : 4;         /* bits 24..27 */
        unsigned int path_mode_ch1 : 4;         /* bits 20..23 */
        unsigned int rest : 20;
    } w4;
};
extern struct sys_config_words sys_config;
extern void sys_set_channel_path_mode(unsigned char, unsigned char);

/*
 * Store the signal path mode of channel 0 or 1 and apply it.
 *
 *   channel  0 or 1; the mode is stored for these two only
 *   mode     0 to 4; any other value is passed on unchanged
 *
 * Callers include sys_user_apply_channel1_scaling_mode, sys_user_apply_channel0_scaling_mode, UserSetProMode and UserSetGameMode (and command 14 of sys_api_config).
 */
void sys_api_set_channel_scaling_mode(unsigned char channel, unsigned char mode)
{
    switch (mode) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    case 3: mode = 3; break;
    case 4: mode = 4; break;
    }
    switch (channel) {
    case 0:
        sys_config.w4.path_mode_ch0 = mode;
        break;
    case 1:
        sys_config.w4.path_mode_ch1 = mode;
        sys_set_channel_path_mode(1, mode);
        return;
    }
    sys_set_channel_path_mode(channel, mode);
}
