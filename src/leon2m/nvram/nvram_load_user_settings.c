/* nvram_load_user_settings  (FUN_a00d3bb4)
 *
 * Read the user settings and the factory record from the EEPROM; write defaults if blank.
 * Name basis: proven - SYSAPI_ReadEEPROM for the 0x1FC-byte and the 0x1C-byte record; defaults when the marker
 *   is missing
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d3bb4 @ 0xa00d3bb4-0xa00d3d30 (95 words), flags -mcpu=v8 -O3 -g.
 * Source form: the first record's check is a block left by break: 'while (1) { p = ..; if (both halfwords are
 * equal) break; copy the defaults; write; break; }'. A loop statement at this place is what the firmware code
 * shows: the record address is formed again after the first read (0xa00d3bd0) and the arguments of the first
 * SYSAPI_ReadEEPROM call keep their source order (0xa00d3bbc-0xa00d3bcc); with a plain if GCC forms the address
 * once and moves the 0x1fc argument first. The second record's check is a plain if.
 */

#define EEPROM_DEVICE            0x30       /* first argument of every SYSAPI_ReadEEPROM / SYSAPI_WriteEEPROM call here */
#define USER_SETTINGS_SIZE       0x1fc      /* bytes of the user settings record, stored at EEPROM offset 0 */
#define FACTORY_RECORD_OFFSET    0x2e0      /* EEPROM offset of the factory record */
#define FACTORY_RECORD_SIZE      0x1c

/* The user settings record (docs/RECORDS.md); only the two halfwords that are compared are named. */
struct user_settings_record {
    unsigned short half_0x0;
    unsigned char pad[0x1f8 - 2];
    unsigned short half_0x1f8;
    unsigned short half_0x1fa;
};

/* The factory record: 14 halfwords (docs/DATA.md); half[0] and half[13] are compared. */
struct factory_record_halves { unsigned short half[14]; };

extern struct user_settings_record user_settings;
extern const struct user_settings_record user_settings_defaults;
extern struct factory_record_halves factory_record;
extern const struct factory_record_halves factory_record_defaults;
extern void *memcpy(void *dst, const void *src, int n);
extern int SYSAPI_ReadEEPROM(int, void *, int, int);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);

/*
 * Read both records from the EEPROM. A record whose halfwords at +0 and at its end (+0x1F8 for the user
 * settings, +0x1A for the factory record) differ from those of the default record is replaced by the default
 * record, and the default is written back to the EEPROM.
 *
 * Defaults: user settings in ROM at 0x198524, factory record in ROM at 0x198508.
 */
void nvram_load_user_settings(void)
{
    struct user_settings_record *settings;

    SYSAPI_ReadEEPROM(EEPROM_DEVICE, &user_settings, 0, USER_SETTINGS_SIZE);
    while (1) {
        settings = &user_settings;
        if (settings->half_0x1f8 == user_settings_defaults.half_0x1f8 && settings->half_0x0 == user_settings_defaults.half_0x0)
            break;
        memcpy(settings, &user_settings_defaults, USER_SETTINGS_SIZE);
        SYSAPI_WriteEEPROM(EEPROM_DEVICE, settings, 0, USER_SETTINGS_SIZE);
        break;
    }
    SYSAPI_ReadEEPROM(EEPROM_DEVICE, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    if (factory_record.half[13] != factory_record_defaults.half[13] || factory_record.half[0] != factory_record_defaults.half[0]) {
        factory_record = factory_record_defaults;
        SYSAPI_WriteEEPROM(EEPROM_DEVICE, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    }
}
