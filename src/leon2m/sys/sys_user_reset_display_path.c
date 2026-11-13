/* sys_user_reset_display_path  (FUN_a00d9238)
 *
 * Mute, switch the panel off when showing, select the input source and restart channels 0 and 1.
 * Note: Panel off only with PIP/PBP off and channel 0 at state code 10; channel 1 only with PIP/PBP off.
 * Name basis: derived - audio mute, SYSAPI_PanelOnOffControl(0, 0), source select and restart of channels 0
 *   and 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d9238 @ 0xa00d9238-0xa00d934c (69 words), flags -mcpu=v8 -O3 -g.
 * Source form: step 2 is ONE call guarded by '||', with the common pair after it (GCC's block reordering copies
 * the pair and the pip_pbp_mode test into both paths, as in the firmware). The record is read again from memory
 * after each call. sys_api_set_port0_value_and_stamp is the final tail call and gets one argument (only %o0 is
 * set; its source lists a second). sys_api_get_channel_state_code returns an unsigned char.
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
  unsigned char pad0[0x1e];
  unsigned char input_source;       /* +0x1E: the selected input source */
  unsigned char pip_pbp_mode;       /* +0x1F: 0 = off */
  unsigned char pad20[0xa8 - 0x20];
  unsigned int gaming_flags;        /* +0xA8 */
};
extern struct user_settings_record user_settings;
extern unsigned char sys_api_get_channel_state_code(unsigned char channel);
extern void gpio_set_aux_bit0_low(void);
extern void oled_controller_disable(void);
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);
extern void timer_sleep_ticks(int ticks);
extern void audio_api_set_mute(unsigned char);
extern void sys_api_select_channel_source(int channel, unsigned char source);
extern void sys_api_restart_channel_at_level(int channel, int level);
extern void sys_api_set_port0_value_and_stamp(unsigned short value);

#define GAMING_FLAG_BIT14 0x4000

/*
 * Set the display path up again from the settings. Called by the four per-port handlers osd_run_navi_key_right,
 * osd_run_navi_key_left, osd_run_navi_key_down and osd_run_navi_key_up and by several other routines, and by sys_user_swap_pip_sources.
 *  1. With the PIP/PBP mode off and channel 0 in state code 10: gpio_set_aux_bit0_low, oled_controller_disable,
 *     SYSAPI_PanelOnOffControl(0, 0), then wait 0x32 ticks.
 *  2. When the PIP/PBP mode is off, or bit 14 of gaming_flags is clear: audio_api_set_mute(1).
 *  3. Select the input source for channel 0 and restart it at level 1; with the PIP/PBP mode off do the same for
 *     channel 1.
 *  4. sys_api_set_port0_value_and_stamp(0x1964).
 */
void sys_user_reset_display_path(void)
{
  if (user_settings.pip_pbp_mode == 0 && sys_api_get_channel_state_code(0) == 10) {
    gpio_set_aux_bit0_low();
    oled_controller_disable();
    SYSAPI_PanelOnOffControl(0, 0);
    timer_sleep_ticks(0x32);
  }
  if (user_settings.pip_pbp_mode == 0 || !(user_settings.gaming_flags & GAMING_FLAG_BIT14))
    audio_api_set_mute(1);
  sys_api_select_channel_source(0, user_settings.input_source);
  sys_api_restart_channel_at_level(0, 1);
  if (user_settings.pip_pbp_mode == 0) {
    sys_api_select_channel_source(1, user_settings.input_source);
    sys_api_restart_channel_at_level(1, 1);
  }
  sys_api_set_port0_value_and_stamp(0x1964);
}
