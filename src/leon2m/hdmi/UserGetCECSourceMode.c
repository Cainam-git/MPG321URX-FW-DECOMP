/* UserGetCECSourceMode  (FUN_a00da4b8)
 *
 * Store the CEC source kind and load Pro and Game mode from saved copy 1 (CEC mode on) or copy 2.
 * Note: With CEC mode on and the channel 0 port flag set, a Pro mode in a range of three values is replaced
 *   and the settings are marked changed.
 * Name basis: proven - prints 'UserGetCECSourceMode %x(%x)%x,%x' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00da4b8 @ 0xa00da4b8-0xa00da65c (105 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the record at 0xa802cff4 is reached through a constant address (#define), so the compiler does not separate
 *    its halfword store from the loads of the settings bytes; that keeps those loads ahead of the bit merge;
 *  - in the "CEC source mode on" arm the bytes are loaded first (y, then x), the bit copy follows, then the
 *    stores in the order shown; in the block after it the stores are written pro_mode, pro_mode_copy_1, then
 *    the osd_request_bits update;
 *  - cec_source_mode_on() and channel0_port_flag_set() are static helpers that the compiler inlines.
 */
/* Settings record, only the fields this routine uses. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = one picture */
    unsigned char pad20[0xa8 - 0x20];
    struct {                                    /* word +0xA8 (gaming_flags), bits 11 down to 8 */
        unsigned int bits_31_12 : 20;
        unsigned int pro_mode_flag : 1;         /* bit 11: Pro (1) / Game (0), the live value */
        unsigned int copy_1_pro_mode_flag : 1;  /* bit 10: saved value for CEC source mode on */
        unsigned int copy_2_pro_mode_flag : 1;  /* bit 9: saved value for CEC source mode off */
        unsigned int bit_8 : 1;
        unsigned int bits_7_0 : 8;
    } gaming_flags;
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned char padb0[0x181 - 0xb0];
    unsigned char pro_mode;                     /* +0x181: live Pro mode */
    unsigned char game_mode;                    /* +0x182: live Game mode */
    unsigned char pro_mode_copy_1;              /* +0x183 */
    unsigned char game_mode_copy_1;             /* +0x184 */
    unsigned char pro_mode_copy_2;              /* +0x185 */
    unsigned char game_mode_copy_2;             /* +0x186 */
    unsigned char pad187[0x1b4 - 0x187];
    unsigned char cec_source_type;              /* +0x1B4: console kind from APPCECGetSourceType */
};
struct app_state_record_head {
    unsigned char pad[0xa];
    unsigned short notice_origin;               /* +0xA: bit 7 is set here while CEC source mode is on */
};

#define SETTINGS_HDMI_CEC_ON   0x100000         /* settings_page_flags bit 20: HDMI CEC switched on */
#define APP_STATE_CEC_MODE_ON  0x80             /* notice_origin bit 7 */
#define PRO_MODE_FIRST_CEC     4                /* pro_mode 4..6 is replaced by 7 on a flagged port */
#define PRO_MODE_CEC_REPLACED  7
#define CEC_SOURCE_TYPE_MAX    2                /* console kinds 0..2 (Play, Nint, XBOX) */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits */

extern struct user_settings_record user_settings;
#define app_state_record (*(struct app_state_record_head *)0xa802cff4)
extern unsigned char osd_request_bits;
extern int dbg_printf(const char *fmt, ...);
extern unsigned char APPCECGetSourceType(void);
extern unsigned char input_api_get_channel_port_code(int);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);

/* True when channel 0 has port flag 9 set, or port flag 6 set together with a mailbox status field of 1 to 4. */
static int channel0_port_flag_set(void)
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
 * True when CEC source mode applies: the HDMI CEC switch is on, one picture is shown (pip_pbp_mode 0), the
 * console kind is 0..2 and the menu index of channel 0's port maps to source 0.
 */
static int cec_source_mode_on(unsigned char console)
{
    if (!(user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON))
        return 0;
    if (user_settings.pip_pbp_mode != 0)
        return 0;
    if (console > CEC_SOURCE_TYPE_MAX)
        return 0;
    if (input_api_source_id_to_menu_index(input_api_get_channel_port_code(0)))
        return 0;
    return 1;
}

/*
 * Store the console kind (APPCECGetSourceType) in the settings and load the Pro/Game mode that goes with it.
 *
 * With CEC source mode on, the live Pro/Game mode bit and the two live mode bytes (+0x181 / +0x182) are loaded
 * from the saved set 1 (bit 10, bytes +0x183 / +0x184) and app_state_record's bit 7 is set. If channel 0's port
 * flag is set and the loaded Pro mode is 4 to 6, Pro mode and its set-1 copy become 7 and a settings-changed
 * request is posted to the OSD. Otherwise bit 7 is cleared and the same values are loaded from set 2 (bit 9,
 * bytes +0x185 / +0x186). Ends with a trace print of console kind, mode bit, Game mode and Pro mode.
 *
 * Called from APPActionDispatcher and APPBeforeDisplay_TriggerBySystem; no parameters, no result.
 */
void UserGetCECSourceMode(void)
{
    unsigned char console = APPCECGetSourceType();

    user_settings.cec_source_type = console;
    if (cec_source_mode_on(console)) {
        unsigned char game, pro;

        game = user_settings.game_mode_copy_1;
        pro = user_settings.pro_mode_copy_1;
        user_settings.gaming_flags.pro_mode_flag = user_settings.gaming_flags.copy_1_pro_mode_flag;
        user_settings.game_mode = game;
        app_state_record.notice_origin |= APP_STATE_CEC_MODE_ON;
        user_settings.pro_mode = pro;
        if (channel0_port_flag_set() && (unsigned char)(user_settings.pro_mode - PRO_MODE_FIRST_CEC) <= 2) {
            user_settings.pro_mode = PRO_MODE_CEC_REPLACED;
            user_settings.pro_mode_copy_1 = PRO_MODE_CEC_REPLACED;
            osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        }
    } else {
        unsigned char game, pro;

        game = user_settings.game_mode_copy_2;
        pro = user_settings.pro_mode_copy_2;
        user_settings.gaming_flags.pro_mode_flag = user_settings.gaming_flags.copy_2_pro_mode_flag;
        user_settings.game_mode = game;
        app_state_record.notice_origin &= ~APP_STATE_CEC_MODE_ON;
        user_settings.pro_mode = pro;
    }
    dbg_printf("\x1b[1;35mUserGetCECSourceMode %x(%x)%x,%x\r\n\x1b[m", user_settings.cec_source_type,
                 user_settings.gaming_flags.pro_mode_flag, user_settings.game_mode, user_settings.pro_mode);
}
