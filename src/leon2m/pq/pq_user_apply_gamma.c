/* pq_user_apply_gamma  (FUN_a00d7bc0)
 *
 * Apply the gamma setting, or the gamma that the current picture state requires.
 * Name basis: derived - settings byte +0x44 mapped to a code for pq_api_set_gamma_and_reapply
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d7bc0 @ 0xa00d7bc0-0xa00d7d48 (98 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - settings byte +0x181 is read once into an unsigned int for the 5..6 range test;
 *  - 'code = 0;' stands as a statement right before the switch (no default case).
 */

#define GAMMA_MAX               7      /* the gamma choice is limited to 7 before the translation */
#define GAMMA_STATE_BITS        0xc0000 /* settings_page_flags bits 18..19 */
#define GAMING_FLAG_PRO_MODE    0x800  /* gaming_flags bit 11: Pro (1) / Game (0) */

struct user_settings_record {
    unsigned char pad0[0x11];
    unsigned char color_temperature;    /* +0x11: the Color Temperature choice */
    unsigned char pad12[0x44 - 0x12];
    unsigned char gamma;                /* +0x44: the gamma choice */
    unsigned char pad45[0xa8 - 0x45];
    unsigned int gaming_flags;          /* +0xA8 */
    unsigned int settings_page_flags;   /* +0xAC */
    unsigned char padb0[0x181 - 0xb0];
    unsigned char pro_mode;             /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;
extern unsigned char ipc_api_get_status_field(void);
extern unsigned char sys_api_get_channel_port_flag9(unsigned char ch);
extern void pq_api_set_gamma_and_reapply(unsigned char);

/* True when the port of channel 0 has flag bit 9 set, or the mailbox status field reads 2. */
static int port_flag9_or_status2(void)
{
    unsigned char result = 0;

    if (ipc_api_get_status_field() == 2)
        result = 1;
    if (sys_api_get_channel_port_flag9(0) == 1)
        result = 1;
    return result & 1;
}

/*
 * Apply the gamma setting, or the gamma that the current picture state requires.
 *
 * The stored choice (+0x44) is overruled first: when either of settings-page flag bits 18..19
 * is set and port_flag9_or_status2() is true, the choice becomes 1; otherwise, with the Color
 * Temperature at 1 (Normal), the Pro mode at 5 or 6 and the Pro flag set, it becomes 3. The
 * choice is limited to 7 (the stored byte is not changed) and translated to a gamma number for
 * pq_load_gamma: 1 -> 0x1A (when the first test above holds), else 0x18 (Pro flag set and Pro
 * mode 4), else 0x13; 2 -> 0x11; 3 -> 0x13; 4 -> 0x19; 5 -> 0x18; 0, 6 and 7 -> 0, which
 * pq_load_gamma treats as "every gamma table off". pq_api_set_gamma_and_reapply stores the
 * number, loads it and applies the picture mode again.
 *
 * Callers: App_Initialize, ddc_handle_request, sys_end_logo_restore_picture, UserSetProMode,
 * UserSetGameMode, sys_user_factory_reset.
 */
void pq_user_apply_gamma(void)
{
    unsigned char gamma = user_settings.gamma;
    unsigned char code;
    unsigned int pro_mode;

    if ((user_settings.settings_page_flags & GAMMA_STATE_BITS) && port_flag9_or_status2())
        gamma = 1;
    else if (user_settings.color_temperature == 1 && (pro_mode = user_settings.pro_mode) >= 5 && pro_mode <= 6) {
        if (user_settings.gaming_flags & GAMING_FLAG_PRO_MODE)
            gamma = 3;
    }
    if (gamma > GAMMA_MAX)
        gamma = GAMMA_MAX;
    code = 0;
    switch (gamma) {
    case 1:
        if ((user_settings.settings_page_flags & GAMMA_STATE_BITS) && port_flag9_or_status2())
            code = 0x1a;
        else if ((user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) && user_settings.pro_mode == 4)
            code = 0x18;
        else
            code = 0x13;
        break;
    case 2:
        code = 0x11;
        break;
    case 3:
        code = 0x13;
        break;
    case 4:
        code = 0x19;
        break;
    case 5:
        code = 0x18;
        break;
    }
    pq_api_set_gamma_and_reapply(code);
}
