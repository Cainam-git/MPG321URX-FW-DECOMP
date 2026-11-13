/* APPBeforeDisplay_TriggerBySystem  (FUN_a0080af0)
 *
 * Refresh the game/pro mode state before the picture is shown.
 *   mode: 0 = full refresh
 * Note: Calls UserSetProMode / UserSetGameMode when the stored mode changed.
 * Name basis: proven - prints 'APPBeforeDisplay_TriggerBySystem' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0080af0 @ 0xa0080af0-0xa0080bc0 (52 words).
 * Prints the string at 0xfeda0 with dbg_printf. For mode 0: UserGetCECSourceMode(); when sys_user_get_picture_state() returns nonzero
 * and bit 7 of halfword 0xa802cffe is clear, bit 11 of word 0xa802d338 takes the value of its bit 8 and bytes
 * 0xa802d411/0xa802d412 take bytes 0xa802d417/0xa802d418. Then, when byte 0xa802d444 differs from byte 0xa802af40,
 * UserSetProMode (bit 11 of 0xa802d338 set) or UserSetGameMode (clear) is called. Always ends with a tail call of
 * sys_user_apply_auto_level.
 */
/* The fields of the user settings record that this routine uses. */
struct user_settings_record {
    unsigned char pad0[0xa8];
    unsigned int gaming_flags;                  /* +0xA8; bit 11 = Pro (1) / Game (0) */
    unsigned char pad_ac[0xd5];
    unsigned char pro_mode;                     /* +0x181 */
    unsigned char game_mode;                    /* +0x182 */
    unsigned char pad_183[4];
    unsigned char byte_0x187;                   /* +0x187: copied to pro_mode */
    unsigned char byte_0x188;                   /* +0x188: copied to game_mode */
    unsigned char pad_189[0x2b];
    unsigned char byte_0x1b4;                   /* +0x1B4: copy kept in app_settings_1b4_copy */
};
extern struct user_settings_record user_settings;
extern unsigned char app_settings_1b4_copy;
extern unsigned short app_state_record_half_0xa;
extern int dbg_printf(const char *fmt, ...);
extern void UserGetCECSourceMode(void);
extern int sys_user_get_picture_state(void);
extern void UserSetProMode(void);
extern void UserSetGameMode(void);
extern void sys_user_apply_auto_level(void);

#define GAMING_FLAG_PRO_MODE 0x800              /* user_settings_gaming_flags bit 11: Pro (1) / Game (0) */

/*
 * Bring the Pro/Game mode state up to date before the picture is shown, then call sys_user_apply_auto_level.
 *
 *   mode   0: do the whole refresh below; any other value: only the last call
 *
 * The refresh calls UserGetCECSourceMode. When sys_user_get_picture_state() is not zero and bit 7 of the halfword
 * at 0xA802CFFE is clear, the Pro/Game bit of the gaming flags takes the value of the flags' bit 8, and pro_mode
 * and game_mode take settings bytes +0x187 and +0x188. Then, when settings byte +0x1B4 differs from its copy in
 * app_settings_1b4_copy, UserSetProMode (Pro/Game bit set) or UserSetGameMode (clear) is called.
 */
void APPBeforeDisplay_TriggerBySystem(unsigned char mode)
{
    dbg_printf("APPBeforeDisplay_TriggerBySystem \r\n");
    if (mode == 0) {
        UserGetCECSourceMode();
        if (sys_user_get_picture_state() && !(app_state_record_half_0xa & 0x80)) {
            /* bit 8 moved up to bit 11 */
            user_settings.gaming_flags = (user_settings.gaming_flags & ~GAMING_FLAG_PRO_MODE) | ((user_settings.gaming_flags << 3) & GAMING_FLAG_PRO_MODE);
            user_settings.game_mode = user_settings.byte_0x188;
            user_settings.pro_mode = user_settings.byte_0x187;
        }
        if (user_settings.byte_0x1b4 != app_settings_1b4_copy) {
            if (!(user_settings.gaming_flags & GAMING_FLAG_PRO_MODE))
                UserSetGameMode();
            else
                UserSetProMode();
        }
    }
    sys_user_apply_auto_level();
}
