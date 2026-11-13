/* input_used_ports_settled  (FUN_a00803a4)
 *
 * Return 1 when no used port reports a state code above 4.
 * Returns: 1 = all used ports settled
 * Note: The OLED frame-rate handler oled_frc_task re-picks the panel mode only when this returns 1.
 * Name basis: derived - header: callee of oled_frc_task before SYSAPI_GetPanelParamStruct
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00803a4 @ 0xa00803a4, flags -mcpu=v8 -O3 -g.
 * Source form: the "port is used" test is an if / else-if chain on i (not a switch, not a call of
 * input_is_port_used) with sel = 0 at the top of each round.
 */

/* The start of the user settings record; only the PIP/PBP mode byte is used here. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = one picture; see input_is_port_used */
};
extern struct user_settings_record user_settings;
extern unsigned char sys_api_get_channel_state_code(unsigned char);

/*
 * Return 1 when no port that takes part in the present layout has a state code above 4, else 0.
 * The ports are the same as in input_is_port_used (the test is written out here).
 * The OLED frame-rate handler (oled_frc_task) calls this and only goes on when it returns 1.
 */
unsigned char input_used_ports_settled(void)
{
    unsigned char settled = 1;
    unsigned char i;

    for (i = 0; i <= 3; i++) {
        unsigned char used = 0;
        if (i == 0) used = 1;
        else if (i == 1) { if (user_settings.pip_pbp_mode != 0) used = 1; }
        else if (i == 2) { if ((unsigned char)(user_settings.pip_pbp_mode - 4) <= 3) used = 1; }
        else if (i == 3) { if (user_settings.pip_pbp_mode == 7) used = 1; }
        if (used && sys_api_get_channel_state_code(i) > 4) { settled = 0; break; }
    }
    return settled & 1;
}
