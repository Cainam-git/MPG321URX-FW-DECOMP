/* ddc_tool_set_factory_mode  (FUN_a00d1ad4)
 *
 * Switch factory mode on or off as the factory tool asks and save it.
 *   param_1: request
 * Returns: 0xE0
 * Note: 1: flag + marker 0x55AA at settings +0x1F6; 0: flag cleared, marker 0xBB99.
 * Name basis: derived - sys_set_factory_mode_flag / sys_clear_factory_mode_flag
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1ad4 @ 0xa00d1ad4-0xa00d1b48 (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: in arm 1 the marker is addressed through a local base pointer (the halfword store shares the base
 * register of the call argument; a plain symbol + 0x1f6 gives an add of -502); arm 0 keeps the symbol + 0x1f6
 * form. SYSAPI_WriteEEPROM returns int (a void declaration puts 'mov 0x30, %o0' first).
 */
extern unsigned char user_settings[];
extern void sys_set_factory_mode_flag(void);
extern void sys_clear_factory_mode_flag(void);
extern void nvram_api_store_by_selector(unsigned char);
extern int SYSAPI_WriteEEPROM(unsigned char, void *, unsigned short, unsigned short);

#define TOOL_RESULT_DONE            0xe0        /* the command was carried out */
#define EEPROM_AREA_SETTINGS        0x30        /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define USER_SETTINGS_SIZE          0x1fc       /* the user settings record, at offset 0 of that area */
#define SETTINGS_FACTORY_MARKER     0x1f6       /* user settings +0x1F6: halfword, FACTORY_MODE_MARKER while on */
#define FACTORY_MODE_MARKER         0x55aa
#define FACTORY_MODE_MARKER_CLEARED 0xbb99      /* written there when factory mode ends */
#define STORE_DEVICE_SETTINGS       1           /* nvram_api_store_by_selector: save the device settings record */

/*
 * Factory tool command 2 (TOOL_CMD_FACTORY_MODE): request byte 7 = 1 sets the factory mode flag, writes
 * FACTORY_MODE_MARKER into the user settings and saves them; 0 clears the flag and writes
 * FACTORY_MODE_MARKER_CLEARED but does not save the user settings. Any other value changes nothing. In every
 * case the device settings record is saved at the end.
 *
 *   param_1  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_factory_mode(unsigned char *param_1)
{
  if (param_1[7] == 1) {
    sys_set_factory_mode_flag();
    unsigned char *p = user_settings;
    *(unsigned short *)(p + SETTINGS_FACTORY_MARKER) = FACTORY_MODE_MARKER;
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, p, 0, USER_SETTINGS_SIZE);
  } else if (param_1[7] == 0) {
    sys_clear_factory_mode_flag();
    *(unsigned short *)(user_settings + SETTINGS_FACTORY_MARKER) = FACTORY_MODE_MARKER_CLEARED;
  }
  nvram_api_store_by_selector(STORE_DEVICE_SETTINGS);
  return TOOL_RESULT_DONE;
}
