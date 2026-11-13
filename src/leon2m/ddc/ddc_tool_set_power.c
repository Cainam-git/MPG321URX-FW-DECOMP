/* ddc_tool_set_power  (FUN_a00d1a34)
 *
 * Switch the monitor on or off as the factory tool asks.
 *   msg: request
 * Returns: 0xE0
 * Note: Request byte 7: 0 off, 1 on, 2 power saving (power_enter_app_state 1 / 2 / 3); saves the settings.
 * Name basis: derived - power_enter_app_state; tool reply code 0xE0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1a34 @ 0xa00d1a34-0xa00d1ad4 (40 words), flags -mcpu=v8 -O2 -g.
 * Source form: the request byte is read once into an unsigned char local; the message pointer is unsigned char,
 * no volatile. The 0 argument of the three state tests is set once in the delay slot of the first branch.
 */
extern unsigned char user_settings[];
extern void power_enter_app_state(int);
extern unsigned char sys_get_channel_state(unsigned char);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern int SYSAPI_WriteEEPROM(unsigned char, void *, unsigned short, unsigned short);

#define TOOL_RESULT_DONE       0xe0             /* the command was carried out */
#define EEPROM_AREA_SETTINGS   0x30             /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define USER_SETTINGS_SIZE     0x1fc            /* the user settings record, at offset 0 of that area */

#define APP_POWER_OFF          1                /* argument values of power_enter_app_state */
#define APP_POWER_ON           2
#define APP_POWER_SAVING       3
#define MAIN_CHANNEL           0                /* channel 0: the main picture */
#define CHANNEL_STATE_CODE_OFF 0                /* sys_api_get_channel_state_code: channel off */

/*
 * Factory tool command 1 (TOOL_CMD_POWER): request byte 7 = 1 powers on when the main channel is off, 0 powers
 * off when it is not, 2 enters power saving unless the raw state of the main channel is 1. Any other value
 * changes nothing. The user settings are saved in every case.
 *
 *   msg  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_power(unsigned char *msg)
{
  unsigned char value = msg[7];

  if (value == 1) {
    if (sys_api_get_channel_state_code(MAIN_CHANNEL) == CHANNEL_STATE_CODE_OFF)
      power_enter_app_state(APP_POWER_ON);
  } else if (value == 0) {
    if (sys_api_get_channel_state_code(MAIN_CHANNEL) != CHANNEL_STATE_CODE_OFF)
      power_enter_app_state(APP_POWER_OFF);
  } else if (value == 2) {
    if (sys_get_channel_state(MAIN_CHANNEL) != 1)
      power_enter_app_state(APP_POWER_SAVING);
  }
  SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, user_settings, 0, USER_SETTINGS_SIZE);
  return TOOL_RESULT_DONE;
}
