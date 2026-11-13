/* hdmi_user_send_cec_action4  (FUN_a00d4888)
 *
 * Ask for CEC action 4 when HDMI CEC is on and PIP/PBP is off; action 4 has no case, nothing is sent.
 * Note: hdmi_cec_api_send_action has no case for action 4.
 * Name basis: derived - settings bit 20 of the word at +0xAC; hdmi_cec_api_send_action(4)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4888 @ 0xa00d4888, flags -mcpu=v8 -O3 -g.
 * Leaf frame, sibcall (mov %o7 form).
 * Source form: the record base user_settings as a struct, one record pointer for both reads; pip_pbp_mode is a
 * byte.
 */
/* The two fields of the user settings record read here. */
struct user_settings_record {
  unsigned char pad0[0x1f];
  unsigned char pip_pbp_mode;                   /* +0x1F: 0 = one picture */
  unsigned char pad20[0xac - 0x20];
  unsigned int settings_page_flags;             /* +0xAC */
};
extern struct user_settings_record user_settings;
extern void hdmi_cec_api_send_action(int);

#define SETTINGS_HDMI_CEC_ON 0x100000           /* settings_page_flags bit 20: the HDMI CEC switch */
#define CEC_ACTION_4         4                  /* hdmi_cec_api_send_action has no case for it: sends nothing */

/*
 * Ask for CEC action 4 when the HDMI CEC switch is on and the screen shows one picture.
 * Calls hdmi_cec_api_send_action(4); that routine does nothing for action 4.
 * Called from uart_cmd_set_language, uart_cmd_dispatch_set and ddc_handle_request.
 */
void hdmi_user_send_cec_action4(void)
{
  struct user_settings_record *settings = &user_settings;

  if ((settings->settings_page_flags & SETTINGS_HDMI_CEC_ON) != 0 && settings->pip_pbp_mode == 0)
    hdmi_cec_api_send_action(CEC_ACTION_4);
}
