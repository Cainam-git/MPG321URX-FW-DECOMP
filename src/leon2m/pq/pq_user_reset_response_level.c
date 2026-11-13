/* pq_user_reset_response_level  (FUN_a00d8c1c)
 *
 * Switch the response level off and back to the stored value.
 * Name basis: descriptive - saves the level, pq_api_set_response_level(5), restores; skipped under two
 *   conditions
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8c1c @ 0xa00d8c1c-0xa00d8cd4 (46 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - input_user_has_rate_mode is a static copy of the routine of that name (input_user_has_rate_mode), inlined here;
 *  - the test is a static helper that returns 'blur_free_mode == 0 || !input_user_has_rate_mode(0, 1)', used
 *    as 'if (!reset_allowed()) return;';
 *  - every record access is written through the record's name. With this form the firmware's copy of the
 *    record address for the +0x8F / +0x19 stores (0xa00d8c4c 'mov %l1,%o5') and its second address for the
 *    level == 0 store (%l1 at 0xa00d8c90) come out as in the firmware.
 */

#define TIMING_REFRESH_RATE  1          /* measured refresh rate in tenths of a hertz */
#define RESPONSE_TIME_MAX    3
#define RESPONSE_LEVEL_OFF   5          /* pq_api_set_response_level: only stops picture block 8 */

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x19];
    unsigned char response_time;                /* +0x19: the response time level */
    unsigned char pad1a[0x8f - 0x1a];
    unsigned char byte_0x8f;                    /* +0x8F: holds the limited response time while it is switched off */
    unsigned char pad90[0xb0 - 0x90];
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
};
extern struct user_settings_record user_settings;
extern int pq_select_rate_mode();
extern int input_api_get_timing_field();
extern void pq_api_set_response_level(int);

/* 1 when pq_select_rate_mode gives a result other than 0 for channel 0's refresh rate in whole hertz. */
static unsigned int input_user_has_rate_mode(unsigned int unused_1, unsigned int unused_2)
{
    unsigned int refresh_rate;

    refresh_rate = input_api_get_timing_field(0, TIMING_REFRESH_RATE);
    return (pq_select_rate_mode((unsigned short)refresh_rate / 10) != 0);
}

/* The reset is skipped while a blur reduction mode is on and the input passes the rate test. */
static int reset_allowed(void)
{
    return user_settings.blur_free_mode == 0 || !input_user_has_rate_mode(0, 1);
}

/*
 * Switch the response level off (pq_api_set_response_level(RESPONSE_LEVEL_OFF), which stops picture block 8)
 * and put the response time setting back afterwards.
 *
 * The response time is limited to 3 and kept in byte +0x8F. During the call the setting reads 0 (both
 * branches below store 0); afterwards it is set from +0x8F, so a value above 3 comes back as 3.
 * Nothing happens while a blur reduction mode is on and input_user_has_rate_mode() is 1.
 *
 * Callers: App_Initialize, osd_accept_pbp_custom_split, osd_commit_pip_pbp_layout, the serial commands
 * uart_cmd_set_response_time, _set_pip_pbp_settings, _set_pip_pbp_mode and _set_picture_settings,
 * ddc_tool_set_pip_test_mode, UserSetGameMode and UserSetProMode. sys_user_factory_reset has its own copy.
 */
void pq_user_reset_response_level(void)
{
    unsigned char level = user_settings.response_time;

    if (!reset_allowed())
        return;
    if (level > RESPONSE_TIME_MAX)
        level = RESPONSE_TIME_MAX;
    user_settings.byte_0x8f = level;
    if (level != 0)
        user_settings.response_time = 0;
    else
        user_settings.response_time = level;
    pq_api_set_response_level(RESPONSE_LEVEL_OFF);
    user_settings.response_time = user_settings.byte_0x8f;
}
