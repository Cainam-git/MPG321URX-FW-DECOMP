/* pq_select_rate_mode  (FUN_a0087458)
 *
 * Return 2 (refresh rate 84..279 Hz) or 3 (Adaptive-Sync on) for a settled input, else 0.
 *   refresh_rate_hz: input rate
 * Returns: 0, 2 or 3
 * Note: The argument is the refresh rate in Hz. A nonzero picture state (sys_user_get_picture_state) gives 0.
 * Name basis: derived - range test 0x54 <= rate < 0x118, Adaptive-Sync bit of the gaming flags; callers pass
 *   timing field 1 / 10
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0087458 @ 0xa0087458-0xa00874c8 (28 words), flags -mcpu=v8 -O3 -g.
 * Source form: two separate ifs for the mode (the fw returns to the bit test after mode=2); mode and the result are
 * separate unsigned int variables, the result set to mode after the picture-state test (fw 'and %l0,%o2,%i0').
 */
extern unsigned char sys_api_get_channel_state_code(unsigned char ch);
extern int sys_user_get_picture_state(void);
extern unsigned int user_settings_gaming_flags;

#define CHANNEL_STATE_SETTLED 8   /* the rate mode is chosen only for channel 0 state codes above this */
#define RATE_MIN 0x54             /* 84 Hz: lower bound of the rate range */
#define RATE_MAX_EXCLUSIVE 0x118  /* 280 Hz: upper bound (exclusive) */
#define ADAPTIVE_SYNC_BIT 0x80    /* bit 7 of user_settings_gaming_flags: Adaptive-Sync */

/*
 * Return the rate mode of channel 0's input.
 *
 *   refresh_rate_hz  the input refresh rate in Hz (callers pass timing field 1, tenths of Hz, / 10)
 *
 * 0 unless the state code of channel 0 is above 8. Then 2 when the rate is in [84, 280) Hz, 3 when the
 * Adaptive-Sync bit is set (whatever the rate), and 0 when sys_user_get_picture_state() is not 0.
 *
 * Callers: ddc_apply_maker_vcp_set, input_user_has_rate_mode, pq_user_reset_response_level,
 * sys_user_apply_brightness, UserSetProMode, UserSetGameMode, sys_user_factory_reset.
 */
int pq_select_rate_mode(unsigned short refresh_rate_hz)
{
    unsigned int mode = 0;
    unsigned int result = 0;

    if (sys_api_get_channel_state_code(0) > CHANNEL_STATE_SETTLED) {
        if (refresh_rate_hz >= RATE_MIN && refresh_rate_hz < RATE_MAX_EXCLUSIVE)
            mode = 2;
        if (user_settings_gaming_flags & ADAPTIVE_SYNC_BIT)
            mode = 3;
        if (sys_user_get_picture_state())
            mode = 0;
        result = mode;
    }
    return result;
}
