/* sys_user_apply_adaptive_sync_setting  (FUN_a00da184)
 *
 * Apply the Adaptive-Sync switch: reload the EDID, restart both channels, set DSC support from it.
 * Note: The value passed to dp_api_set_dsc_support for sources 0xC and 0xD is bit 7 of settings word +0xA8,
 *   the Adaptive-Sync switch.
 * Name basis: derived - UserSwitchEDID(2, 1) and dp_api_set_dsc_support with bit 7 of settings word +0xA8;
 *   called by the Adaptive-Sync switch routines of the menu and the PC tool and by the routines that switch
 *   Adaptive-Sync off (PIP/PBP, screen size, Optix Scope)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00da184 @ 0xa00da184-0xa00da254 (52 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record bases user_settings and app_state_record are declared with the fields used here. The
 * port code is fetched first and its result is the argument of input_api_source_id_to_menu_index, whose return
 * is the tested value. The last dp_api_set_dsc_support call is a tail call with two arguments and re-reads the
 * settings word.
 */
/* The halfword at +0x0A of the application state record. */
struct app_state_record_fields { unsigned char pad[0xa]; unsigned short halfword_0x0a; };
extern struct app_state_record_fields app_state_record;
/* The words at +0xA8 and +0xAC of the user settings record. */
struct user_settings_record { unsigned char pad[0xa8]; unsigned int gaming_flags; unsigned int word_0xac; };
extern struct user_settings_record user_settings;
extern void UserSwitchEDID(int how, int select);
extern void sys_api_set_channel_timeout(int channel, int on, int value);
extern unsigned char input_api_get_channel_port_code(int channel);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void sys_app_timer_start(int id, int ms);
extern void ddc_send_vcp_e6_reply(void);
extern void sys_api_restart_channel_at_level(int channel, int level);
extern void input_power_on_ports_by_mask(unsigned int mask, unsigned int on);
extern void dp_api_set_dsc_support(int source, unsigned int enable);

#define SETTINGS_WORD_0xAC_BIT20 0x100000
#define GAMING_FLAG_ADAPTIVE_SYNC_BIT 7 /* the Adaptive-Sync switch, passed on as the DSC enable value */

/*
 * Apply the Adaptive-Sync setting. The EDID is loaded again (UserSwitchEDID(2, 1)), channel 4 gets the value 1000 in
 * sys_api_set_channel_timeout, and, when the port code of channel 0 maps to a non-zero source and bit 20 of the
 * settings word at +0xAC is set, bit 6 of the application state halfword +0x0A is set and application timer
 * 0x14 is started for 5000 ms. Then ddc_send_vcp_e6_reply runs, channels 0 and 1 are restarted at level 1,
 * input_power_on_ports_by_mask(0xF, 1) is called and bit 7 of gaming_flags (the Adaptive-Sync
 * switch) is stored through dp_api_set_dsc_support for the sources 0xC and 0xD.
 */
void sys_user_apply_adaptive_sync_setting(void)
{
  UserSwitchEDID(2, 1);
  sys_api_set_channel_timeout(4, 1, 1000);
  if (input_api_source_id_to_menu_index(input_api_get_channel_port_code(0)) && (user_settings.word_0xac & SETTINGS_WORD_0xAC_BIT20)) {
    app_state_record.halfword_0x0a |= 0x40;
    sys_app_timer_start(0x14, 5000);
  }
  ddc_send_vcp_e6_reply();
  sys_api_restart_channel_at_level(0, 1);
  sys_api_restart_channel_at_level(1, 1);
  input_power_on_ports_by_mask(0xf, 1);
  dp_api_set_dsc_support(0xc, user_settings.gaming_flags >> GAMING_FLAG_ADAPTIVE_SYNC_BIT & 1);
  dp_api_set_dsc_support(0xd, user_settings.gaming_flags >> GAMING_FLAG_ADAPTIVE_SYNC_BIT & 1);
}
