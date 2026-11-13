/* ddc_tool_set_color_temperature  (FUN_a00d1e3c)
 *
 * Select the colour temperature the factory tool names and save it.
 *   p: request
 * Returns: 0xE0, or 0xE3
 * Note: Codes 1..4 map to 2, 0, 1, 3; other codes return 0xE3.
 * Name basis: derived - settings byte +0x11, pq_user_apply_color_settings
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1e3c @ 0xa00d1e3c-0xa00d1ed8 (39 words), flags -mcpu=v8 -O3 -g.
 * Source form: a switch on request byte 7 that sets a local and returns at once for an unknown byte.
 */

/* The user settings record: only the colour temperature byte is named here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned char pad000[0x11];
    unsigned char color_temperature;            /* +0x11: Color Temperature (COLOR_TEMP_*) */
    unsigned char pad012[0x1fc - 0x12];
};
extern struct user_settings_record user_settings;
extern void pq_user_apply_color_settings(void);
extern void ddc_raise_event0(void);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);

#define TOOL_RESULT_DONE     0xe0               /* the command was carried out */
#define TOOL_RESULT_UNKNOWN  0xe3               /* a value the routine does not know */
#define EEPROM_AREA_SETTINGS 0x30               /* first argument of SYSAPI_WriteEEPROM: the settings area */

/* Colour temperature values (settings +0x11). */
#define COLOR_TEMP_COOL      0
#define COLOR_TEMP_NORMAL    1
#define COLOR_TEMP_WARM      2
#define COLOR_TEMP_CUSTOM    3

/*
 * Factory tool command 0x0D (TOOL_CMD_COLOR_TEMPERATURE): request byte 7 = 1, 2, 3, 4 selects Warm, Cool,
 * Normal, Custom. When that differs from the Color Temperature setting, the setting is changed, applied
 * (pq_user_apply_color_settings), DDC/CI event 0 is raised and the user settings are saved.
 *
 *   p  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE, or TOOL_RESULT_UNKNOWN for any other value (nothing is changed then).
 * ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls this one.
 */
int ddc_tool_set_color_temperature(unsigned char *p)
{
    unsigned char color_temperature;

    switch (p[7]) {
    case 1:
        color_temperature = COLOR_TEMP_WARM;
        break;
    case 2:
        color_temperature = COLOR_TEMP_COOL;
        break;
    case 3:
        color_temperature = COLOR_TEMP_NORMAL;
        break;
    case 4:
        color_temperature = COLOR_TEMP_CUSTOM;
        break;
    default:
        return TOOL_RESULT_UNKNOWN;
    }
    if (user_settings.color_temperature != color_temperature) {
        user_settings.color_temperature = color_temperature;
        pq_user_apply_color_settings();
        ddc_raise_event0();
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, sizeof user_settings);
    }
    return TOOL_RESULT_DONE;
}
