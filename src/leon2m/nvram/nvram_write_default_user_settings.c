/* nvram_write_default_user_settings  (FUN_a00d57e8)
 *
 * Write the default user settings and the default factory record to the EEPROM.
 * Note: Writes the EEPROM.
 * Name basis: proven - 0x1FC bytes from 0x198524 and 28 bytes from 0x198508, each with SYSAPI_WriteEEPROM;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d57e8 @ 0xa00d57e8-0xa00d58b0 (50 words).
 * Source form: user_settings is passed through one pointer local (the whole address stays in a register); the
 * 28-byte record is a structure of 14 halfwords (2-byte alignment: copied halfword by halfword). The last
 * SYSAPI_WriteEEPROM is a tail call.
 */

#define EEPROM_DEVICE            0x30       /* first argument of every SYSAPI_WriteEEPROM call here */
#define USER_SETTINGS_SIZE       0x1fc      /* bytes of the user settings record, stored at EEPROM offset 0 */
#define FACTORY_RECORD_OFFSET    0x2e0      /* EEPROM offset of the factory record */
#define FACTORY_RECORD_SIZE      0x1c

/* The factory record: 14 halfwords (docs/DATA.md). */
struct factory_record_halves { unsigned short half[14]; };

extern unsigned char user_settings[];
extern const unsigned char user_settings_defaults[];
extern struct factory_record_halves factory_record;
extern const struct factory_record_halves factory_record_defaults;
extern void *memcpy(void *dst, const void *src, int n);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);

/*
 * Reset both records to their defaults (user settings from ROM at 0x198524, factory record from ROM at
 * 0x198508) and write them to the EEPROM. Unlike nvram_load_user_settings it does not look at what the EEPROM
 * holds.
 */
void nvram_write_default_user_settings(void)
{
    unsigned char *settings = user_settings;

    memcpy(settings, user_settings_defaults, USER_SETTINGS_SIZE);
    SYSAPI_WriteEEPROM(EEPROM_DEVICE, settings, 0, USER_SETTINGS_SIZE);
    factory_record = factory_record_defaults;
    SYSAPI_WriteEEPROM(EEPROM_DEVICE, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
}
