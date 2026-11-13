/* sys_user_apply_startup_settings  (FUN_a00db054)
 *
 * Run the set-up calls that apply the stored settings after power-on.
 * Name basis: derived - panel off, EDID, channel restart, zone grid and one command to the input processor
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00db054 @ 0xa00db054-0xa00db12c (54 words), flags -mcpu=v8 -O3 -g.
 * Source form: both globals are named directly in every arm of the if/else-if chain (no pointer local), so each
 * arm computes the address of part_record itself, as the firmware does. The last call is a tail call.
 */
/* The word at +0xAC of the user settings record. */
struct user_settings_record {
    unsigned char pad[0xac];
    unsigned int word_0xac;
};
/* The halfword at +0x24 of the part record. */
struct part_record_fields {
    unsigned char pad[0x24];
    unsigned short hdr_peak_luminance;
};
extern struct user_settings_record user_settings;
extern struct part_record_fields part_record;
extern void gpio_set_aux_bit0_low(void);
extern void oled_controller_disable(void);
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);
extern void UserSwitchEDID(unsigned char how, unsigned char select);
extern void sys_api_restart_channel_at_level(unsigned char channel, unsigned char level);
extern void sys_api_set_channel_timeout(unsigned char channel, unsigned int on, unsigned short value);
extern void ldc_api_set_zone_grid(unsigned char grid);
extern void ipc_api_set_hdr_peak_luminance(unsigned short);

#define ZONE_GRID_MASK 0xc0000          /* bits 18..19 of the settings word at +0xAC */
#define ZONE_GRID_0x40000 0x40000
#define ZONE_GRID_0x80000 0x80000

/*
 * Apply the stored settings after power-on: the panel is switched off (gpio_set_aux_bit0_low,
 * oled_controller_disable, SYSAPI_PanelOnOffControl(0, 0)), the EDID is loaded (UserSwitchEDID(2, 0)),
 * channels 0 and 1 are restarted at level 1 and channel 4 gets the value 1000 (sys_api_set_channel_timeout).
 * Bits 18..19 of the settings word at +0xAC then choose the zone grid and the peak luminance of the part record:
 * 0x40000 gives luminance 0x3F7 and grid 0; 0x80000 gives 0x3F7 and grid 1; any other value gives 0x1C2 and
 * grid 0. The luminance is then sent with ipc_api_set_hdr_peak_luminance. Called from App_CoolInitialize,
 * osd_accept_display_hdr, uart_cmd_set_display_hdr, osd_apply_choice_on_timeout and sys_user_factory_reset.
 */
void sys_user_apply_startup_settings(void)
{
    gpio_set_aux_bit0_low();
    oled_controller_disable();
    SYSAPI_PanelOnOffControl(0, 0);
    UserSwitchEDID(2, 0);
    sys_api_restart_channel_at_level(0, 1);
    sys_api_restart_channel_at_level(1, 1);
    sys_api_set_channel_timeout(4, 1, 1000);
    if ((user_settings.word_0xac & ZONE_GRID_MASK) == ZONE_GRID_0x40000) {
        part_record.hdr_peak_luminance = 0x3f7;
        ldc_api_set_zone_grid(0);
    } else if ((user_settings.word_0xac & ZONE_GRID_MASK) == ZONE_GRID_0x80000) {
        part_record.hdr_peak_luminance = 0x3f7;
        ldc_api_set_zone_grid(1);
    } else {
        part_record.hdr_peak_luminance = 0x1c2;
        ldc_api_set_zone_grid(0);
    }
    ipc_api_set_hdr_peak_luminance(part_record.hdr_peak_luminance);
}
