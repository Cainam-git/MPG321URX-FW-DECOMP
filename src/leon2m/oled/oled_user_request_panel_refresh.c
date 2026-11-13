/* oled_user_request_panel_refresh  (FUN_a00dab4c)
 *
 * Request the panel protect run when the chosen button of its prompt is Execute (0).
 * Note: Any other choice (Cancel, Later, More Info) changes nothing.
 * Name basis: derived - for choice 0 sets fields +9, +0xA, +0x13 and clears +0xF of the OLED power state
 *   record and sets channel flag 25
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dab4c @ 0xa00dab4c, flags -mcpu=v8 -O2 -g (section default; -O3 -g and -Os -g give the same
 * bytes).
 * Source form: the early return comes first; the channel flag call is the last statement (a tail call).
 */
extern void oled_power_set_field_09(unsigned char value);
extern void oled_power_set_field_0a(unsigned char value);
extern void oled_power_set_field_0f(unsigned char value);
extern void oled_power_set_field_13(unsigned char value);
extern void sys_api_set_all_channels_flag25(void);

#define PROTECT_BUTTON_EXECUTE 0            /* first button of the panel protect prompt */

/*
 * Start the OLED panel protect run when the user chose "Execute".
 *
 *   choice  the chosen button of the panel protect prompt (0 Execute, 1 Cancel, 2 Later, 3 More Info); the PC
 *           tool's start command passes 0, its request command 1, the prompt the chosen button row
 *
 * For Execute it sets fields +0x09, +0x0A and +0x13 of the OLED power state record (the state of
 * oled_power_task) to 1 and field +0x0F to 0, then sets flag bit 25 in all four channel records. Any other
 * choice returns without a change.
 */
void oled_user_request_panel_refresh(unsigned int choice)
{
  if ((choice & 0xff) != PROTECT_BUTTON_EXECUTE) {
    return;
  }
  oled_power_set_field_09(1);
  oled_power_set_field_0f(0);
  oled_power_set_field_0a(1);
  oled_power_set_field_13(1);
  sys_api_set_all_channels_flag25();
}
