/* ddc_tool_run_factory_reset  (FUN_a00d1b48)
 *
 * Reset the user settings to their defaults and save the user settings and the factory record.
 * Returns: 0xE0
 * Note: Adds 1 to device settings halfword +0x3A when Brightness / Contrast are 1 / 2 or 1 / 4; zeroes the
 *   seven panel usage counters when the marker at settings +0x1F6 is 0x55AA; calls sys_user_factory_reset.
 * Name basis: derived - caller ddc_tool_dispatch_command; SYSAPI_WriteEEPROM of both records
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1b48 @ 0xa00d1b48-0xa00d1ce4 (103 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the word at settings +8 is read once per test, masked with 0xffff00;
 *  - the seven counter clears stand in the firmware's order (0xB, 0xA, 0xD, 0xC, 0x10, 0xE, 0xF).
 */

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[8];
    unsigned int word_0x8;                  /* +8: language, Brightness (+9), Contrast (+0xA), byte +0xB */
    unsigned char pad0c[0x1f6 - 0xc];
    unsigned short factory_mode_marker;     /* +0x1F6 */
};
/* The field of the factory record used here. */
struct factory_record_fields {
    unsigned char pad[0x10];
    unsigned char key_test_bits;            /* +0x10: one bit per front key passed in the key test */
};
/* The field of the device settings record used here. */
struct device_settings_record {
    unsigned char pad[0x3a];
    unsigned short half_0x3a;               /* +0x3A */
};
extern struct user_settings_record user_settings;
extern struct factory_record_fields factory_record;
extern struct device_settings_record device_settings;
extern void nvram_api_store_by_selector(unsigned char);
extern void nvram_api_write_fga_byte(unsigned char);
extern void nvram_set_device_setting(int, int);
extern void sys_user_factory_reset(void);
extern void sys_clear_factory_mode_flag(void);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);

#define TOOL_RESULT_DONE              0xe0      /* answer of the factory tool command */

/* Settings bytes +9 and +0xA (Brightness, Contrast) inside word_0x8. */
#define BRIGHTNESS_CONTRAST_MASK      0xffff00
#define BRIGHTNESS_1_CONTRAST_2       0x10200
#define BRIGHTNESS_1_CONTRAST_4       0x10400

#define FACTORY_MODE_MARKER           0x55aa    /* settings +0x1F6 */
#define FACTORY_MODE_MARKER_CLEARED   0xbb99
#define KEY_TEST_BITS_DURING_RESET    0xf6

/* Fields of the device settings record (nvram_set_device_setting): the panel usage counters. */
#define DEVICE_SETTING_EL_COUNT       0xa
#define DEVICE_SETTING_OFFS_COUNT     0xb
#define DEVICE_SETTING_EL_HOURS       0xc
#define DEVICE_SETTING_OFFS_HOURS     0xd
#define DEVICE_SETTING_EL_RUNS        0xe
#define DEVICE_SETTING_OFFS_RUNS      0xf
#define DEVICE_SETTING_SENSING_TEST   0x10

/* SYSAPI_WriteEEPROM: the area code and where the two records lie in that area. */
#define EEPROM_AREA                   0x30
#define USER_SETTINGS_OFFSET          0
#define USER_SETTINGS_SIZE            0x1fc
#define FACTORY_RECORD_OFFSET         0x2e0
#define FACTORY_RECORD_SIZE           0x1c

/*
 * Factory tool command TOOL_CMD_FACTORY_RESET (3) of ddc_tool_dispatch_command: reset the user settings and
 * save them and the factory record.
 *
 * Returns TOOL_RESULT_DONE (0xE0) in every case.
 *
 * Steps, in this order:
 *   1. With Brightness 1 and Contrast 2: add 1 to device settings halfword +0x3A and call
 *      nvram_api_store_by_selector(1). With Brightness 1 and Contrast 4: the same, then
 *      nvram_api_write_fga_byte(0).
 *   2. Set the factory record's key-test bits to 0xF6.
 *   3. When the factory mode marker (settings +0x1F6) is 0x55AA: set the seven panel usage counters of the
 *      device settings (EL / OFFS count, hours and runs, sensing test) to 0 and call
 *      nvram_api_store_by_selector(1).
 *   4. Reload and apply the default user settings (sys_user_factory_reset) and save the user settings record.
 *   5. Clear the key-test bits, clear the factory mode flag (sys_clear_factory_mode_flag, which also switches all
 *      input signals off), set the marker to 0xBB99 and save the factory record.
 * The flag and the marker of step 5 change after the user settings were saved in step 4; this routine does not
 * save them.
 */
unsigned char ddc_tool_run_factory_reset(void)
{
    /* Step 1. */
    if ((user_settings.word_0x8 & BRIGHTNESS_CONTRAST_MASK) == BRIGHTNESS_1_CONTRAST_2) {
        device_settings.half_0x3a++;
        nvram_api_store_by_selector(1);
    }
    if ((user_settings.word_0x8 & BRIGHTNESS_CONTRAST_MASK) == BRIGHTNESS_1_CONTRAST_4) {
        device_settings.half_0x3a++;
        nvram_api_store_by_selector(1);
        nvram_api_write_fga_byte(0);
    }

    /* Step 2. */
    factory_record.key_test_bits = KEY_TEST_BITS_DURING_RESET;

    /* Step 3: only while the marker is set. */
    if (user_settings.factory_mode_marker == FACTORY_MODE_MARKER) {
        nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
        nvram_set_device_setting(DEVICE_SETTING_EL_COUNT, 0);
        nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
        nvram_set_device_setting(DEVICE_SETTING_EL_HOURS, 0);
        nvram_set_device_setting(DEVICE_SETTING_SENSING_TEST, 0);
        nvram_set_device_setting(DEVICE_SETTING_EL_RUNS, 0);
        nvram_set_device_setting(DEVICE_SETTING_OFFS_RUNS, 0);
        nvram_api_store_by_selector(1);
    }

    /* Step 4. */
    sys_user_factory_reset();
    SYSAPI_WriteEEPROM(EEPROM_AREA, &user_settings, USER_SETTINGS_OFFSET, USER_SETTINGS_SIZE);

    /* Step 5. */
    factory_record.key_test_bits = 0;
    sys_clear_factory_mode_flag();
    user_settings.factory_mode_marker = FACTORY_MODE_MARKER_CLEARED;
    SYSAPI_WriteEEPROM(EEPROM_AREA, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    return TOOL_RESULT_DONE;
}
