/* ldc_user_apply_grid_enable  (FUN_a00db690)
 *
 * Switch the grid block for the current state and re-apply the dimming mode.
 * Name basis: descriptive - ldc_hw_api_set_enable_mode per state
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00db690 @ 0xa00db690-0xa00db738 (42 words), flags -mcpu=v8 -O3 -g.
 * Source form: each path calls ldc_hw_api_set_enable_mode with its own constant and the shared calls are
 * cross-jumped: the firmware keeps the constant in %o0 per path. Case 3 shares the mode-0 block ('goto zero').
 * A variable holding the mode gives an extra mov / and 1 and if-conversion of the bit test.
 */

#define SETTINGS_AI_VISION  0x8000      /* bit 15 of settings word +0x174: the AI Vision switch */

extern unsigned int user_settings_word_0x174;
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);
extern void ldc_hw_api_set_enable_mode(unsigned char);
extern void sys_user_apply_dimming_mode(void);

/*
 * Set the enable mode of the grid block of the dimming hardware, then apply the dimming mode again.
 *
 * The mode is 1 only when the AI Vision switch (bit 15 of settings word +0x174) is on and neither of these holds:
 *  - flag bit 9 of the port record of channel 0 is 1;
 *  - flag bit 6 of the port record of channel 0 is 1 and the status field from the mailbox
 *    (ipc_api_get_status_field) is 1, 2, 3 or 4.
 * In every other case the mode is 0.
 * Called after the AI Vision switch changes (osd_toggle_ai_vision, uart_cmd_set_ai_vision) and from
 * uart_cmd_dispatch_set.
 */
void ldc_user_apply_grid_enable(void)
{
  if (sys_api_get_channel_port_flag9(0) == 1)
    goto zero;
  if (sys_api_get_channel_port_flag6(0) == 1) {
    switch (ipc_api_get_status_field()) {
    case 1: ldc_hw_api_set_enable_mode(0); sys_user_apply_dimming_mode(); return;
    case 2: ldc_hw_api_set_enable_mode(0); sys_user_apply_dimming_mode(); return;
    case 3: goto zero;
    case 4: ldc_hw_api_set_enable_mode(0); sys_user_apply_dimming_mode(); return;
    }
  }
  if (user_settings_word_0x174 & SETTINGS_AI_VISION) {
    ldc_hw_api_set_enable_mode(1);
    sys_user_apply_dimming_mode();
    return;
  }
zero:
  ldc_hw_api_set_enable_mode(0);
  sys_user_apply_dimming_mode();
}
