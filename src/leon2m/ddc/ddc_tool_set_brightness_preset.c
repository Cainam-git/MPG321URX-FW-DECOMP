/* ddc_tool_set_brightness_preset  (FUN_a00d27ac)
 *
 * Tool command: set brightness preset 0..2, switch to Game Mode 1, apply and save.
 * Note: Brightness and its mode-1 copy get the preset's value (25, 70, 70), device settings byte +0xB the
 *   preset number; Game Mode 1 / Pro mode 0 chosen and applied; user settings and device settings saved.
 *   Another preset number changes nothing.
 * Name basis: derived - frame byte 7 = 0/1/2; settings bytes 9 and 0x59; UserSetGameMode; saved with
 *   SYSAPI_WriteEEPROM and the device settings store
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d27ac @ 0xa00d27ac-0xa00d2884 (216 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: each preset has its own full arm (GCC merges the common tails); pro_selected (bit 11 of word
 * +0xA8) is a 1-bit bit-field; the stores keep the order brightness, preset, brightness_tab1[1], pro_selected,
 * game_mode, pro_mode, so pro_mode is cleared just before the sys_user_apply_brightness call.
 */

/* The fields of the user settings record (docs/RECORDS.md) used here; the record is saved whole. */
struct user_settings_record {
    unsigned char pad000[9];
    unsigned char brightness;                   /* +0x09: Brightness */
    unsigned char pad00a[0x58 - 0xa];
    unsigned char brightness_tab1[13];          /* +0x58: Brightness kept per mode number, first table */
    unsigned char pad065[0xa8 - 0x65];
    /* gaming_flags, word +0xA8 */
    unsigned int gaming_flags_bits31_12 : 20,
                 pro_selected : 1,              /* bit 11: Pro (1) / Game (0) mode */
                 gaming_flags_bits10_0 : 11;
    unsigned char pad0ac[0x181 - 0xac];
    unsigned char pro_mode;                     /* +0x181: the Professional mode */
    unsigned char game_mode;                    /* +0x182: the Game Mode */
    unsigned char pad183[0x1fc - 0x183];
};
extern struct user_settings_record user_settings;
extern unsigned char device_settings_brightness_preset;
extern void sys_user_apply_brightness(void);
extern void UserSetGameMode(void);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);
extern void nvram_api_store_by_selector(unsigned char);

#define TOOL_RESULT_DONE      0xe0              /* the command was carried out */
#define TOOL_RESULT_BAD_VALUE 0xe4
#define EEPROM_AREA_SETTINGS  0x30              /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define STORE_DEVICE_SETTINGS 1                 /* nvram_api_store_by_selector: save the device settings */

/* Request byte 7: the preset, and the Brightness (0..100) each one sets. */
#define BRIGHTNESS_PRESET_0   0
#define BRIGHTNESS_PRESET_1   1
#define BRIGHTNESS_PRESET_2   2
#define PRESET_0_BRIGHTNESS   0x19              /* 25 */
#define PRESET_1_2_BRIGHTNESS 0x46              /* 70, presets 1 and 2 */

#define GAME_MODE_1           1                 /* with the Game Mode chosen, mode number 1 */
#define MODE_NUMBER_1         1                 /* brightness_tab1 slot of mode number 1 */
#define PRO_MODE_0            0

/*
 * Factory tool command 0x73 (TOOL_CMD_BRIGHTNESS_PRESET): choose brightness preset 0, 1 or 2, switch to
 * Game Mode 1 and save.
 *
 *   request  the tool request; byte 7 = the preset
 *
 * The steps, the same for each preset except the Brightness value (PRESET_0_BRIGHTNESS for preset 0,
 * PRESET_1_2_BRIGHTNESS for presets 1 and 2):
 *   1. Brightness takes the value, and so does brightness_tab1[1], the Brightness kept for mode number 1 in
 *      the first per-mode table (the mode number of Game Mode 1, see sys_user_save_mode_slot). The second table
 *      is not written.
 *   2. The preset number goes to device settings byte +0xB; ddc_tool_dispatch_command answers it to
 *      TOOL_GET_BRIGHTNESS_PRESET.
 *   3. Game Mode is chosen over Pro mode (pro_selected = 0), Game Mode = 1, Pro mode = 0.
 *   4. Brightness and the Game Mode are applied (sys_user_apply_brightness, UserSetGameMode), the user
 *      settings record is written to the EEPROM and the device settings are saved.
 *
 * Returns TOOL_RESULT_DONE, or TOOL_RESULT_BAD_VALUE for any other preset (nothing is changed then).
 * Called by ddc_tool_dispatch_command.
 */
int ddc_tool_set_brightness_preset(unsigned char *request)
{
    if (request[7] == BRIGHTNESS_PRESET_0) {
        user_settings.brightness = PRESET_0_BRIGHTNESS;
        device_settings_brightness_preset = BRIGHTNESS_PRESET_0;
        user_settings.brightness_tab1[MODE_NUMBER_1] = PRESET_0_BRIGHTNESS;
        user_settings.pro_selected = 0;
        user_settings.game_mode = GAME_MODE_1;
        user_settings.pro_mode = PRO_MODE_0;
        sys_user_apply_brightness();
        UserSetGameMode();
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, sizeof user_settings);
        nvram_api_store_by_selector(STORE_DEVICE_SETTINGS);
        return TOOL_RESULT_DONE;
    } else if (request[7] == BRIGHTNESS_PRESET_1) {
        user_settings.brightness = PRESET_1_2_BRIGHTNESS;
        device_settings_brightness_preset = BRIGHTNESS_PRESET_1;
        user_settings.brightness_tab1[MODE_NUMBER_1] = PRESET_1_2_BRIGHTNESS;
        user_settings.pro_selected = 0;
        user_settings.game_mode = GAME_MODE_1;
        user_settings.pro_mode = PRO_MODE_0;
        sys_user_apply_brightness();
        UserSetGameMode();
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, sizeof user_settings);
        nvram_api_store_by_selector(STORE_DEVICE_SETTINGS);
        return TOOL_RESULT_DONE;
    } else if (request[7] == BRIGHTNESS_PRESET_2) {
        user_settings.brightness = PRESET_1_2_BRIGHTNESS;
        device_settings_brightness_preset = BRIGHTNESS_PRESET_2;
        user_settings.brightness_tab1[MODE_NUMBER_1] = PRESET_1_2_BRIGHTNESS;
        user_settings.pro_selected = 0;
        user_settings.game_mode = GAME_MODE_1;
        user_settings.pro_mode = PRO_MODE_0;
        sys_user_apply_brightness();
        UserSetGameMode();
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, sizeof user_settings);
        nvram_api_store_by_selector(STORE_DEVICE_SETTINGS);
        return TOOL_RESULT_DONE;
    }
    return TOOL_RESULT_BAD_VALUE;
}
