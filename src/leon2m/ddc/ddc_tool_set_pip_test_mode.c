/* ddc_tool_set_pip_test_mode  (FUN_a00d253c)
 *
 * Tool command: switch a picture-in-picture test layout on or off.
 * Name basis: descriptive - frame byte 6 = 0/1; reset sequence, UserSetPIPMode and source selection
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d253c @ 0xa00d253c-0xa00d25f4 (46 words), flags -mcpu=v8 -O3 (no -g).
 * Source form: the same four-call sequence is written out in both arms.
 */

/* The user settings record up to the two bytes used here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned char pad000[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP) */
    unsigned char second_source;                /* +0x20: the source of the second picture */
};
extern struct user_settings_record user_settings;
extern void panel_user_set_output_on(int);
extern void sys_api_restart_channel_at_level(int, int);
extern void UserSetPIPMode(void);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void sys_user_apply_pip_sources(int);
extern void pq_user_reset_response_level(void);
extern void audio_user_update_routing(void);

#define TOOL_RESULT_DONE 0xe0                   /* the command was carried out */
#define PIP_PBP_PIP      1                      /* values of the PIP/PBP mode setting */
#define PIP_PBP_PBP      2
#define RESTART_LEVEL    1                      /* level argument of sys_api_restart_channel_at_level */

/*
 * Factory tool command 0x6F (TOOL_CMD_PIP_TEST): request byte 6 chooses the layout.
 *   0  PIP/PBP mode setting = PIP.
 *   1  PIP/PBP mode setting = PBP, and the source of the second picture = the menu index of the input that
 *      request byte 7 names (input_api_menu_index_to_source_id); the second picture's source is then applied
 *      (sys_user_apply_pip_sources).
 *   other  the PIP/PBP mode setting stays; only the closing steps below run.
 * In both layouts the same sequence runs between the settings and the source step: the panel output is switched
 * off (panel_user_set_output_on(0)), channels 0 and 1 are restarted at level 1 and the mode is applied
 * (UserSetPIPMode). In every case the response level is reset (pq_user_reset_response_level) and the audio
 * routing is updated. The settings are not saved here.
 *
 *   p  the request
 *
 * Returns TOOL_RESULT_DONE. Called by ddc_tool_dispatch_command.
 */
int ddc_tool_set_pip_test_mode(unsigned char *p)
{
    if (p[6] == 0) {
        user_settings.pip_pbp_mode = PIP_PBP_PIP;
        panel_user_set_output_on(0);
        sys_api_restart_channel_at_level(0, RESTART_LEVEL);
        sys_api_restart_channel_at_level(1, RESTART_LEVEL);
        UserSetPIPMode();
    } else if (p[6] == 1) {
        user_settings.pip_pbp_mode = PIP_PBP_PBP;
        panel_user_set_output_on(0);
        sys_api_restart_channel_at_level(0, RESTART_LEVEL);
        sys_api_restart_channel_at_level(1, RESTART_LEVEL);
        UserSetPIPMode();
        user_settings.second_source = input_api_menu_index_to_source_id(p[7]);
        sys_user_apply_pip_sources(1);
    }
    pq_user_reset_response_level();
    audio_user_update_routing();
    return TOOL_RESULT_DONE;
}
