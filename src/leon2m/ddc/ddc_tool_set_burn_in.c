/* ddc_tool_set_burn_in  (FUN_a00d1ce4)
 *
 * Switch the burn-in test on or off as the factory tool asks and save it.
 *   param_1: request
 * Returns: 0xE0
 * Name basis: proven - glossary: factory item 19 'Burn In' = byte 0xA802D465
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1ce4 @ 0xa00d1ce4, flags -mcpu=v8 -O3 -g (also exact at -O2 -g).
 * Source form: SYSAPI_WriteEEPROM is declared without a prototype.
 */
extern unsigned char user_settings[];
extern int SYSAPI_WriteEEPROM();

#define TOOL_RESULT_DONE     0xe0               /* the command was carried out */
#define EEPROM_AREA_SETTINGS 0x30               /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define USER_SETTINGS_SIZE   0x1fc              /* the user settings record, at offset 0 of that area */
#define SETTINGS_BURN_IN     0x1d5              /* user settings +0x1D5: the Burn In flag, 1 on, 0 off */

/*
 * Factory tool command 8 (TOOL_CMD_BURN_IN): request byte 7 = 1 sets the Burn In flag, 0 clears it, any other
 * value leaves it. The user settings are saved in every case.
 *
 *   param_1  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_burn_in(unsigned char *param_1)
{
    if (param_1[7] == 1)
        user_settings[SETTINGS_BURN_IN] = 1;
    else if (param_1[7] == 0)
        user_settings[SETTINGS_BURN_IN] = 0;
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, user_settings, 0, USER_SETTINGS_SIZE);
    return TOOL_RESULT_DONE;
}
