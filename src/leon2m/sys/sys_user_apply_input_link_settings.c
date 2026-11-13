/* sys_user_apply_input_link_settings  (FUN_a00d9fdc)
 *
 * Apply the per-input link settings and the EDID for a selector.
 * Name basis: derived - UserSwitchEDID, channel time-out, restart, port switch-on, DSC flags
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d9fdc @ 0xa00d9fdc-0xa00da184 (106 words), flags -mcpu=v8 -O3 -g.
 * Source form: apply_dsc_switch is a static helper, inlined twice. The sign of the word at 0xa802d484 is read as
 * a signed 1-bit bit-field: a plain int compared with 0 gives the same test but the opposite block placement.
 */
/* The settings word +0x1F4: bit 31 is the DSC switch (a signed 1-bit field, see the matching notes). */
struct dsc_switch_word {
    int dsc_on : 1;
    unsigned int rest : 31;
};
extern struct dsc_switch_word user_settings_word_0x1f4;
extern void UserSwitchEDID(int, int);
extern void sys_api_set_channel_timeout(int, int, int);
extern void sys_api_restart_channel_at_level(int, int);
extern void input_power_on_ports_by_mask(unsigned int, unsigned int);
extern unsigned char SYSAPI_GetSystemDPDSCSupport(unsigned char source);
extern void input_api_set_port_flag_row7(unsigned char source, unsigned char on);

/*
 * Bring the per-port setting of the sources 12 and 13 in line with the DSC switch. With the switch on, both are
 * set to 1 as soon as either source reports no DSC support; with the switch off, both are set to 0 as soon as
 * either one reports support. Nothing is written when they already agree.
 */
static void apply_dsc_switch(void)
{
    if (user_settings_word_0x1f4.dsc_on) {
        if (!SYSAPI_GetSystemDPDSCSupport(0xc) || !SYSAPI_GetSystemDPDSCSupport(0xd)) {
            input_api_set_port_flag_row7(0xc, 1);
            input_api_set_port_flag_row7(0xd, 1);
        }
    } else {
        if (SYSAPI_GetSystemDPDSCSupport(0xc) == 1 || SYSAPI_GetSystemDPDSCSupport(0xd) == 1) {
            input_api_set_port_flag_row7(0xc, 0);
            input_api_set_port_flag_row7(0xd, 0);
        }
    }
}

/*
 * Apply the settings that belong to the input links: the EDID, the channel time-out, the channel restart, the
 * port power and the DSC switch.
 *
 *   sel   0: reload the EDID with UserSwitchEDID(0, 1), set the channel time-out (4, 1, 1000), restart channels
 *         0 and 1 at level 1 and switch on ports by mask 0xf; no DSC step.
 *         1: only the DSC step (apply_dsc_switch).
 *         anything else: the same as 0 but with UserSwitchEDID(2, 1), followed by the DSC step.
 *
 * Callers: App_Initialize, osd_toggle_dsc and uart_cmd_set_dsc pass 2; UserSetPIPMode passes 1.
 */
void sys_user_apply_input_link_settings(unsigned char sel)
{
    if (sel == 0) {
        UserSwitchEDID(0, 1);
        sys_api_set_channel_timeout(4, 1, 1000);
        sys_api_restart_channel_at_level(0, 1);
        sys_api_restart_channel_at_level(1, 1);
        input_power_on_ports_by_mask(0xf, 1);
    } else if (sel == 1) {
        apply_dsc_switch();
    } else {
        UserSwitchEDID(2, 1);
        sys_api_set_channel_timeout(4, 1, 1000);
        sys_api_restart_channel_at_level(0, 1);
        sys_api_restart_channel_at_level(1, 1);
        input_power_on_ports_by_mask(0xf, 1);
        apply_dsc_switch();
    }
}
