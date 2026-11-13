/* sys_user_reset_settings_keep_source  (FUN_a00dc2dc)
 *
 * Put the whole user settings record back to its defaults, keeping the input source, and re-apply.
 * Note: Also keeps the byte pairs +0x1E2/+0x1E3 and +0x1E6/+0x1E7; then applies the RGB gains, colour
 *   temperature and Game or Pro mode. Called for DDC/CI SetVCP code 0x08.
 * Name basis: derived - 0x1FC-byte defaults table at 0x198524 copied over the record; three items saved and
 *   put back; caller is the DDC/CI handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dc2dc @ 0xa00dc2dc-0xa00dc3dc (64 words), flags -mcpu=v8 -O3 -g.
 * Source form: the byte pairs are kept in 2-byte local structures and copied member by member (a structure
 * assignment copies them as halfwords); the limited gain is an unsigned short, as in pq_user_set_custom_blue.
 */
/* Two neighbouring settings bytes that are kept together. */
struct settings_byte_pair {
    unsigned char first;
    unsigned char second;
};
struct user_settings_record {
    unsigned char pad0[0x12];
    unsigned char red_gain;                 /* +0x12: the custom red gain, 0..100 */
    unsigned char green_gain;               /* +0x13 */
    unsigned char blue_gain;                /* +0x14 */
    unsigned char pad15[0x1e - 0x15];
    unsigned char input_source;             /* +0x1E: the selected Input Source */
    unsigned char pad1f[0xa8 - 0x1f];
    unsigned int gaming_flags;              /* +0xA8: bit 11 = Pro (1) / Game (0) */
    unsigned char padac[0x1e2 - 0xac];
    struct settings_byte_pair pair_0x1e2;   /* +0x1E2, +0x1E3 */
    unsigned char pad1e4[2];
    struct settings_byte_pair pair_0x1e6;   /* +0x1E6, +0x1E7 */
};
extern struct user_settings_record user_settings;
extern const unsigned char user_settings_defaults[];
extern void *memcpy(void *, const void *, unsigned int);
extern void pq_api_set_rgb_gain(int, unsigned char);
extern void pq_user_apply_color_temperature(void);
extern void UserSetProMode(void);
extern void UserSetGameMode(void);

#define USER_SETTINGS_SIZE   0x1fc          /* size of the settings record, and of its defaults */
#define GAMING_FLAG_PRO_MODE 0x800          /* bit 11 of settings word +0xA8: 1 = Professional modes, 0 = Game modes */

/*
 * Put the whole user settings record back to the defaults and apply the picture settings that depend on it.
 *
 * The record (0x1FC bytes) is overwritten with the table of defaults, except for the selected input source
 * (+0x1E) and the byte pairs +0x1E2/+0x1E3 and +0x1E6/+0x1E7, which are saved before and put back after the
 * copy. Then the custom red, green and blue gains (+0x12, +0x13, +0x14) are limited to 100, written back and
 * handed to pq_api_set_rgb_gain as colours 0, 1 and 2; the colour temperature is applied; and finally the
 * Game mode is applied (UserSetGameMode), or the Professional mode (UserSetProMode) when bit 11 of the settings
 * word +0xA8 is set in the restored record.
 *
 * Called from the DDC/CI request handler, in the branch for the SetVCP code 0x08.
 */
void sys_user_reset_settings_keep_source(void)
{
    struct settings_byte_pair saved_pair_0x1e2, saved_pair_0x1e6;
    unsigned char saved_input_source;

    saved_pair_0x1e2.first = user_settings.pair_0x1e2.first;
    saved_pair_0x1e2.second = user_settings.pair_0x1e2.second;
    saved_pair_0x1e6.first = user_settings.pair_0x1e6.first;
    saved_pair_0x1e6.second = user_settings.pair_0x1e6.second;
    saved_input_source = user_settings.input_source;
    unsigned short gain;

    memcpy(&user_settings, user_settings_defaults, USER_SETTINGS_SIZE);
    user_settings.input_source = saved_input_source;
    user_settings.pair_0x1e2.first = saved_pair_0x1e2.first;
    user_settings.pair_0x1e2.second = saved_pair_0x1e2.second;
    user_settings.pair_0x1e6.first = saved_pair_0x1e6.first;
    user_settings.pair_0x1e6.second = saved_pair_0x1e6.second;
    gain = user_settings.red_gain;
    if (gain > 100)
        gain = 100;
    user_settings.red_gain = gain;
    pq_api_set_rgb_gain(0, gain);
    gain = user_settings.green_gain;
    if (gain > 100)
        gain = 100;
    user_settings.green_gain = gain;
    pq_api_set_rgb_gain(1, gain);
    gain = user_settings.blue_gain;
    if (gain > 100)
        gain = 100;
    user_settings.blue_gain = gain;
    pq_api_set_rgb_gain(2, gain);
    pq_user_apply_color_temperature();
    if (!(user_settings.gaming_flags & GAMING_FLAG_PRO_MODE))
        UserSetGameMode();
    else
        UserSetProMode();
}
