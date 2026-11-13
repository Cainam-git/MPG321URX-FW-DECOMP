/* ddc_tool_set_level_percent  (FUN_a00d2384)
 *
 * Store the level the factory tool sends in settings byte +0x10 and apply it.
 *   param_1: request
 * Returns: 0xE0
 * Name basis: derived - sys_user_apply_level_percent
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d2384 @ 0xa00d2384 (-mcpu=v8 -O3 -g)
 * Source form: the value is stored as sent (not limited); SYSAPI_WriteEEPROM is declared without a prototype.
 */
extern unsigned char user_settings[];
extern void audio_user_apply_level(void);
extern int SYSAPI_WriteEEPROM();

#define TOOL_RESULT_DONE     0xe0               /* the command was carried out */
#define EEPROM_AREA_SETTINGS 0x30               /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define USER_SETTINGS_SIZE   0x1fc              /* the user settings record, at offset 0 of that area */
#define SETTINGS_AUDIO_LEVEL 0x10               /* user settings +0x10: the audio level (at most 100) */

/*
 * Factory tool command 0x6C (TOOL_CMD_AUDIO_LEVEL): store request byte 7 as the audio level setting, apply it
 * (audio_user_apply_level, which limits it to 100) and save the user settings.
 *
 *   param_1  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_level_percent(unsigned char *param_1)
{
    user_settings[SETTINGS_AUDIO_LEVEL] = param_1[7];
    audio_user_apply_level();
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, user_settings, 0, USER_SETTINGS_SIZE);
    return TOOL_RESULT_DONE;
}
