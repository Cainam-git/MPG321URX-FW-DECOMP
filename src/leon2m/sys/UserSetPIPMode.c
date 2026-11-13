/* UserSetPIPMode  (FUN_a00da254)
 *
 * Apply the picture-in-picture / picture-by-picture mode the user chose.
 * Name basis: proven - prints 'UserSetPIPMode' texts (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00da254 @ 0xa00da254-0xa00da4b8 (516 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: bit 13 of the halfword at 0xa802d032 is a bit-field; cases 5 and 6 are written as two separate
 * identical bodies (GCC merges them into one block, which then comes first among the out-of-line case blocks);
 * the capture window is copied through two local 16-byte buffers (ldd/std pairs).
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1e];
    unsigned char input_source;         /* +0x1E: the selected Input Source */
    unsigned char pip_pbp_mode;         /* +0x1F: PIP/PBP mode, 0 = one picture */
    unsigned char second_source;        /* +0x20: the source of the second picture */
};
extern struct user_settings_record user_settings;
extern struct { unsigned short low : 2; unsigned short bit13 : 1; unsigned short high : 13; } DAT_a802d032;
extern int dbg_printf(const char *fmt, ...);
extern void UserSwitchEDID(int, int);
extern void sys_api_set_channel_timeout(int, int, int);
extern unsigned char sys_is_mode_4_to_6(void);
extern void APP_ConfigDispSize(int, void *);
extern void input_api_set_capture_window(int, void *);
extern void SYSAPI_ConfigSystemPIPMode(unsigned int mode);
extern void sys_api_set_config_bit21(unsigned int);
extern void sys_user_apply_input_link_settings(unsigned char sel);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern unsigned char input_api_get_channel_port_code(int);
extern void sys_api_select_channel_source(int, unsigned char);
extern void sys_api_set_panel_power_all_channels(unsigned char);
extern void sys_api_set_entry_actions_all_channels(unsigned char);
extern unsigned char SYSAPI_GetSystemDPDSCSupport(unsigned char source);
extern void input_api_set_port_flag_row7(unsigned char source, unsigned char on);

/*
 * Apply the picture-in-picture / picture-by-picture mode that the user settings hold.
 *
 * The settings byte +0x1F (0..7) gives the system mode handed to SYSAPI_ConfigSystemPIPMode and the number of
 * channels that take part:
 *
 *   setting   0        1    2    4    5    6    7
 *   mode      0 or 2   1    5    3    6    6    7      (setting 3 and above 7: mode 0)
 *   channels  1        2    2    3    3    3    4      (setting 3 and above 7: none)
 *
 * With setting 0 the mode is 2 unless sys_is_mode_4_to_6() returns 1, and then 0.
 *
 * Order of work: UserSwitchEDID(2, 0); the channel time-out (4, 1, 1500) unless bit 13 of the halfword at
 * 0xa802d032 is set; the mode and channel count as above; the mode is printed; for each taking-part channel the
 * display window computed by APP_ConfigDispSize is handed to the channel as its capture window; the system mode
 * is configured; configuration bit 21 is cleared for the modes 3, 4, 6 and 7 and set for every other mode.
 *
 * Then the source of the second channel (channel 1) is chosen:
 *   - one picture (setting 0): the DSC step of sys_user_apply_input_link_settings(1) runs; channel 1 gets the
 *     input source of the settings (+0x1E) when channel 0 reports the state code 10, else the port code that
 *     channel 0 shows; configuration bytes 0x2E and 0x2F are set to 0;
 *   - any other setting: when source 12 or source 13 reports DSC support, the per-port setting of both is set
 *     to 0; channel 1 gets the second source of the settings (+0x20); configuration bytes 0x2E and 0x2F are set
 *     to 1.
 *
 * Callers: App_Initialize, APPActionDispatcher, the PIP/PBP menu routines (osd_*), the PC-tool commands
 * (uart_cmd_*) and sys_user_factory_reset.
 */
void UserSetPIPMode(void)
{
    unsigned long long window[2];
    unsigned long long window_copy[2];
    unsigned char channel_count = 0;
    unsigned int mode = 0;
    unsigned char i;

    UserSwitchEDID(2, 0);
    if (!DAT_a802d032.bit13)
        sys_api_set_channel_timeout(4, 1, 1500);
    switch (user_settings.pip_pbp_mode) {
    case 0:
        mode = (sys_is_mode_4_to_6() != 1) * 2;
        channel_count = 1;
        break;
    case 1:
        mode = 1;
        channel_count = 2;
        break;
    case 2:
        mode = 5;
        channel_count = 2;
        break;
    case 4:
        mode = 3;
        channel_count = 3;
        break;
    case 5:
        mode = 6;
        channel_count = 3;
        break;
    case 6:
        mode = 6;
        channel_count = 3;
        break;
    case 7:
        mode = 7;
        channel_count = 4;
        break;
    }
    dbg_printf("\x1b[1;33mUserSetPIPMode %x\r\n\x1b[m", mode);
    for (i = 0; i < channel_count; i++) {
        APP_ConfigDispSize(i, window);
        window_copy[0] = window[0];
        window_copy[1] = window[1];
        input_api_set_capture_window(i, window_copy);
    }
    SYSAPI_ConfigSystemPIPMode(mode);
    if (mode == 3 || mode == 4 || mode == 6 || mode == 7)
        sys_api_set_config_bit21(0);
    else
        sys_api_set_config_bit21(1);
    if (user_settings.pip_pbp_mode == 0) {
        sys_user_apply_input_link_settings(1);
        if (sys_api_get_channel_state_code(0) == 10)
            sys_api_select_channel_source(1, user_settings.input_source);
        else
            sys_api_select_channel_source(1, input_api_get_channel_port_code(0));
        sys_api_set_panel_power_all_channels(0);
        sys_api_set_entry_actions_all_channels(0);
    } else {
        if (SYSAPI_GetSystemDPDSCSupport(0xc) == 1 || SYSAPI_GetSystemDPDSCSupport(0xd) == 1) {
            input_api_set_port_flag_row7(0xc, 0);
            input_api_set_port_flag_row7(0xd, 0);
        }
        sys_api_select_channel_source(1, user_settings.second_source);
        sys_api_set_panel_power_all_channels(1);
        sys_api_set_entry_actions_all_channels(1);
    }
}
