/* sys_user_apply_auto_level  (FUN_a00d8ffc)
 *
 * Switch the automatic level control as the setting says; re-apply the brightness when it is off.
 * Name basis: descriptive - bit 31 of the settings word at +0x11C; pq_api_set_auto_level_mode;
 *   sys_user_apply_brightness only when that bit is clear
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8ffc @ 0xa00d8ffc-0xa00d9120 (73 words), flags -mcpu=v8 -O3 -g.
 * Source form: the bit is read into an unsigned char mode, copied to sel, written back, and the case labels 0..2
 * of sel set mode again (a no-op the compiler keeps in this form); each case of the status switch in
 * auto_level_blocked has its own body (shared labels give a range test). The top bit of the settings word is a
 * bit-field member.
 */
/* The settings word +0x11C: bit 31 is the automatic level switch, the other 31 bits are not used here. */
struct professional_flags_word {
    unsigned int auto_level : 1;
    unsigned int rest : 31;
};
struct user_settings_record {
    unsigned char pad0[0x11c];
    struct professional_flags_word professional_flags;      /* +0x11C */
};
extern struct user_settings_record user_settings;
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);
extern void pq_api_set_auto_level_mode(unsigned char);
extern void sys_user_apply_brightness(void);

/*
 * 1 when channel 0 has port flag 9 set, or has port flag 6 set and the mailbox status field is 1, 2, 3 or 4;
 * else 0. This is the same condition that makes the picture state of sys_user_apply_brightness non-zero.
 */
static int auto_level_blocked(void)
{
    if (sys_api_get_channel_port_flag9(0) == 1)
        return 1;
    if (sys_api_get_channel_port_flag6(0) == 1) {
        switch (ipc_api_get_status_field()) {
        case 1: return 1;
        case 2: return 1;
        case 3: return 1;
        case 4: return 1;
        }
    }
    return 0;
}

/*
 * Pass the user's automatic level switch (bit 31 of settings word +0x11C) on to the picture-quality code, then
 * apply the brightness.
 *
 * The mode handed to pq_api_set_auto_level_mode is the switch (0 or 1), but 0 whenever auto_level_blocked()
 * is true. When the switch is off, sys_user_apply_brightness runs afterwards (as a tail call); when it is on, the
 * brightness is not touched here.
 */
void sys_user_apply_auto_level(void)
{
    unsigned char mode = user_settings.professional_flags.auto_level;
    unsigned char sel = mode;

    user_settings.professional_flags.auto_level = sel;
    switch (sel) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    }
    if (auto_level_blocked())
        mode = 0;
    pq_api_set_auto_level_mode(mode & 3);
    if (!user_settings.professional_flags.auto_level)
        sys_user_apply_brightness();
}
