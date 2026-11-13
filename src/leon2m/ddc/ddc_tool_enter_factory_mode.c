/* ddc_tool_enter_factory_mode  (FUN_a00d28d4)
 *
 * Tool command: switch factory mode and burn-in on, save and verify.
 * Note: Writes the EEPROM.
 * Name basis: derived - marker 0x55AA in the factory record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d28d4 @ 0xa00d28d4, flags -mcpu=v8 -O3 -g.
 * Source form: the result is a local int preset to 0xE4 and set again in the final if/else.
 */
extern unsigned char user_settings[];
extern int SYSAPI_WriteEEPROM();

#define TOOL_RESULT_DONE            0xe0        /* the command was carried out */
#define TOOL_RESULT_BAD_VALUE       0xe4        /* a request value without an answer, or the check failed */
#define EEPROM_AREA_SETTINGS        0x30        /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define USER_SETTINGS_SIZE          0x1fc       /* the user settings record, at offset 0 of that area */
#define SETTINGS_WORD0_FACTORY_MODE 0x4000      /* user settings word +0, bit 14 */
#define SETTINGS_BURN_IN            0x1d5       /* user settings +0x1D5: the Burn In flag */
#define SETTINGS_BYTE_0x1D6         0x1d6
#define SETTINGS_FACTORY_MARKER     0x1f6       /* user settings +0x1F6: halfword */
#define FACTORY_MODE_MARKER         0x55aa      /* the marker while factory mode is on */
#define FACTORY_MODE_BYTE_0x1D6     0x55        /* stored in settings byte +0x1D6 */

/*
 * Factory tool command 0xAA (TOOL_CMD_ENTER_FACTORY_MODE): only request byte 7 = 1 does anything. It sets the
 * factory mode bit (bit 14 of settings word +0), the Burn In flag to 1, the factory marker to
 * FACTORY_MODE_MARKER and settings byte +0x1D6 to 0x55, then saves the user settings.
 *
 *   param_1  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE when the factory mode bit, the Burn In flag and the marker read back as set after the
 * save; TOOL_RESULT_BAD_VALUE when they do not, and for any other request value (nothing is written then).
 * ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls this one.
 */
int ddc_tool_enter_factory_mode(unsigned char *param_1)
{
    unsigned char v = param_1[7];
    int r = TOOL_RESULT_BAD_VALUE;
    if (v == 1) {
        *(unsigned int *)user_settings |= SETTINGS_WORD0_FACTORY_MODE;
        user_settings[SETTINGS_BURN_IN] = v;
        *(unsigned short *)(user_settings + SETTINGS_FACTORY_MARKER) = FACTORY_MODE_MARKER;
        user_settings[SETTINGS_BYTE_0x1D6] = FACTORY_MODE_BYTE_0x1D6;
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, user_settings, 0, USER_SETTINGS_SIZE);
        if ((*(unsigned int *)user_settings & SETTINGS_WORD0_FACTORY_MODE) && user_settings[SETTINGS_BURN_IN] == 1 && *(unsigned short *)(user_settings + SETTINGS_FACTORY_MARKER) == FACTORY_MODE_MARKER)
            r = TOOL_RESULT_DONE;
        else
            r = TOOL_RESULT_BAD_VALUE;
    }
    return r;
}
