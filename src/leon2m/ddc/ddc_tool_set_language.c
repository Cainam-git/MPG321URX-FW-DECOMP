/* ddc_tool_set_language  (FUN_a00d20a4)
 *
 * Set the menu language the factory tool names and save it.
 *   request
 * Returns: 0xE0
 * Note: Request byte 7 (0..0x1F) mapped through a table to the language byte +0x8.
 * Name basis: derived - settings byte +0x8 = language index of the menu texts
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d20a4 @ 0xa00d20a4-0xa00d2334 (164 words), flags -mcpu=v8 -O3 -g. Language switch: jump table
 * 0x6ecb0 (32 entries).
 */

/* The one field of the user settings record (docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad0[8];
    unsigned char language;                     /* +0x08: the menu language, 1 = English */
};
extern struct user_settings_record user_settings;
extern int SYSAPI_WriteEEPROM(int, void *, int, int);
extern void nvram_api_store_by_selector(unsigned char);

#define EEPROM_AREA               0x30          /* first argument of SYSAPI_WriteEEPROM */
#define USER_SETTINGS_OFFSET      0
#define USER_SETTINGS_SIZE        0x1fc
#define TOOL_RESULT_DONE          0xe0          /* the factory tool's "carried out" code */

/*
 * Factory tool command 'c' 0x6A: set the menu language and save the settings.
 *
 *   request  the tool request; byte 7 = the tool's language number
 *
 * ddc_tool_dispatch_command carries out this command with an inlined copy of this body.
 *
 * Phases:
 *   1. Tool language number -> menu language (settings byte +8). Numbers 0x0A, 0x0B and 0x0F and every number
 *      above 0x1F leave the language unchanged. ddc_tool_build_reply answers TOOL_ANSWER_LANGUAGE with the
 *      inverse of this table.
 *   2. Write the settings record to the EEPROM and call nvram_api_store_by_selector(1), whether the language
 *      changed or not.
 *
 * Returns TOOL_RESULT_DONE (0xE0) in every case.
 */
unsigned char ddc_tool_set_language(unsigned char *request)
{
    /* Phase 1: the language. */
    switch (request[7]) {
    case 0x0:
        user_settings.language = 0x1;
        break;
    case 0x1:
        user_settings.language = 0x3;
        break;
    case 0x2:
        user_settings.language = 0x2;
        break;
    case 0x3:
        user_settings.language = 0x5;
        break;
    case 0x4:
        user_settings.language = 0x4;
        break;
    case 0x5:
        user_settings.language = 0x19;
        break;
    case 0x6:
        user_settings.language = 0x16;
        break;
    case 0x7:
        user_settings.language = 0x9;
        break;
    case 0x8:
        user_settings.language = 0x18;
        break;
    case 0x9:
        user_settings.language = 0x8;
        break;
    case 0xc:
        user_settings.language = 0x0;
        break;
    case 0xd:
        user_settings.language = 0x7;
        break;
    case 0xe:
        user_settings.language = 0x6;
        break;
    case 0x10:
        user_settings.language = 0xd;
        break;
    case 0x11:
        user_settings.language = 0xa;
        break;
    case 0x12:
        user_settings.language = 0xb;
        break;
    case 0x13:
        user_settings.language = 0xc;
        break;
    case 0x14:
        user_settings.language = 0xe;
        break;
    case 0x15:
        user_settings.language = 0xf;
        break;
    case 0x16:
        user_settings.language = 0x10;
        break;
    case 0x17:
        user_settings.language = 0x11;
        break;
    case 0x18:
        user_settings.language = 0x12;
        break;
    case 0x19:
        user_settings.language = 0x13;
        break;
    case 0x1a:
        user_settings.language = 0x14;
        break;
    case 0x1b:
        user_settings.language = 0x15;
        break;
    case 0x1c:
        user_settings.language = 0x17;
        break;
    case 0x1d:
        user_settings.language = 0x1a;
        break;
    case 0x1e:
        user_settings.language = 0x1b;
        break;
    case 0x1f:
        user_settings.language = 0x1c;
        break;
    }

    /* Phase 2: save. */
    SYSAPI_WriteEEPROM(EEPROM_AREA, &user_settings, USER_SETTINGS_OFFSET, USER_SETTINGS_SIZE);
    nvram_api_store_by_selector(1);
    return TOOL_RESULT_DONE;
}
