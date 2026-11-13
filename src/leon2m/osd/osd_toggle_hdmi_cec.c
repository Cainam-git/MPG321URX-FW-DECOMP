/* osd_toggle_hdmi_cec  (FUN_a0099244)
 *
 * Switch HDMI CEC on or off and restart the input channels.
 * Note: Toggles bit 20 of settings word +0xAC.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x30 = 'HDMI CEC' (Settings texts 0x1874F8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099244 @ 0xa0099244-0xa009934c (66 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Source form: bit 20 of word +0xAC is a 1-bit bit-field, toggled as 'f = 1 - f' ('~f', '!f' and '^= 1' give
 * other instructions). The record base is user_settings. panel_user_set_output_on(0) runs before the two
 * sys_api_restart_channel_at_level calls in the pip_pbp_mode arm.
 */
/* The fields of the settings record used here. */
struct user_settings_record {
  unsigned char pad[0x1e];
  unsigned char input_source;                   /* +0x1E: the selected input source (menu index) */
  unsigned char pip_pbp_mode;                   /* +0x1F: 0 = PIP/PBP off */
  unsigned char pad2[0xac - 0x20];
  unsigned int hi : 11, hdmi_cec_on : 1, lo : 20; /* +0xAC: bit 20 = HDMI CEC */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_draw_toggle_switch_selected(int, unsigned char);
extern void panel_user_set_output_on(int);
extern void UserSetPIPMode(void);
extern void input_api_select_ports(int, int);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void sys_api_restart_channel_at_level(int, int);

#define TOGGLE_ITEM_HDMI_CEC     6      /* item index of osd_draw_toggle_switch_selected for HDMI CEC */
#define INPUT_SOURCE_MENU_5      5      /* input source menu index 5: the ports 0x10 are selected for it */
#define PORT_SELECTION_0X10      0x10   /* first argument of input_api_select_ports */
#define LEVEL_1                  1      /* level argument of sys_api_restart_channel_at_level */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on the HDMI CEC item of the Settings page: flip the switch (bit 20 of settings word +0xAC), draw the new
 * OFF or ON state, then restart the pictures.
 *
 * When PIP/PBP is on (settings byte +0x1F is not 0) it is set to 0: the picture output is switched off, channels
 * 0 and 1 are restarted at level 1 and UserSetPIPMode applies the mode. Then, when
 * input_api_source_id_to_menu_index returns 0 for the selected input (settings byte +0x1E), the output is switched
 * off again, input 5 selects the ports 0x10 first, and channels 0 and 1 are restarted at level 1.
 * The routine ends by reporting a settings change.
 */
void osd_toggle_hdmi_cec(void)
{
  struct user_settings_record *p = &user_settings;

  p->hdmi_cec_on = 1 - p->hdmi_cec_on;
  osd_draw_toggle_switch_selected(TOGGLE_ITEM_HDMI_CEC, p->hdmi_cec_on);
  if (p->pip_pbp_mode != 0) {
    p->pip_pbp_mode = 0;
    panel_user_set_output_on(0);
    sys_api_restart_channel_at_level(0, LEVEL_1);
    sys_api_restart_channel_at_level(1, LEVEL_1);
    UserSetPIPMode();
  }
  if (input_api_source_id_to_menu_index(p->input_source) == 0) {
    panel_user_set_output_on(0);
    if (p->input_source == INPUT_SOURCE_MENU_5)
      input_api_select_ports(PORT_SELECTION_0X10, 1);
    sys_api_restart_channel_at_level(0, LEVEL_1);
    sys_api_restart_channel_at_level(1, LEVEL_1);
  }
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
