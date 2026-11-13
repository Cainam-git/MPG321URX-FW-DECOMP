/* nvram_get_device_setting  (FUN_a0145af8)
 *
 * Return one of the eighteen fields of the device settings record.
 * Returns: field value
 * Name basis: proven - getter for the record saved at EEPROM offset 0x470
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145af8 @ 0xa0145af8, flags -mcpu=v8 -O3 -g (jump table included).
 * Source form: the record is a packed, 4-byte aligned struct (that is why the compiler reads the 16-bit fields with
 * a word load and a shift; the fields at +0x13 and +0x17 cross a word boundary and are read as two bytes); the
 * one-bit flags are read as bit-fields and cast to unsigned char.
 */
/* The device settings record at 0xA802E1A0 (0x50 bytes), saved at EEPROM offset 0x470 by nvram_write_settings_record.
 * Only the fields this getter returns are named. */
struct device_settings_record {
    unsigned int power_status:1,        /* +0x00 bit 31 */
                 flag_30:1,             /* bit 30: setting 0 */
                 flag_29:1,             /* bit 29: setting 1 */
                 bit_28:1,
                 phy_cts_auto:1,        /* bit 27: setting 2 */
                 flag_26:1,             /* bit 26: setting 3 */
                 bits_24_25:2,
                 rest0:24;
    unsigned char pad04[4];             /* +0x04 */
    unsigned char on_time_minutes;      /* +0x08: setting 6 */
    unsigned short on_time_hours;       /* +0x09: setting 7 */
    unsigned char pad0b;                /* +0x0b */
    unsigned char byte_0x0c;            /* +0x0c: setting 8 */
    unsigned short half_0x0d;           /* +0x0d: setting 9 */
    unsigned char el_count;             /* +0x0f: setting 10 */
    unsigned char offs_count;           /* +0x10: setting 11 */
    unsigned short el_hours;            /* +0x11: setting 12 */
    unsigned short offs_hours;          /* +0x13: setting 13 */
    unsigned short el_runs;             /* +0x15: setting 14 */
    unsigned short offs_runs;           /* +0x17: setting 15 */
    unsigned int sensing_test:1,        /* +0x19 bit 7: setting 16 */
                 usage_record:1,        /* bit 6: setting 17 */
                 rest1:6;
} __attribute__((packed, aligned(4)));
extern struct device_settings_record device_settings;

/* Setting numbers (the names the callers use). */
enum {
    DEVICE_SETTING_PHY_CTS_AUTO = 2,    /* factory menu switch "PHY CTS AUTO" */
    DEVICE_SETTING_ON_TIME_MINUTES = 6,
    DEVICE_SETTING_ON_TIME_HOURS = 7,
    DEVICE_SETTING_8 = 8,
    DEVICE_SETTING_9 = 9,
    DEVICE_SETTING_EL_COUNT = 0xa,
    DEVICE_SETTING_OFFS_COUNT = 0xb,
    DEVICE_SETTING_EL_HOURS = 0xc,
    DEVICE_SETTING_OFFS_HOURS = 0xd,
    DEVICE_SETTING_EL_RUNS = 0xe,
    DEVICE_SETTING_OFFS_RUNS = 0xf,
    DEVICE_SETTING_SENSING_TEST = 0x10, /* factory menu switch "Sensing Test" */
    DEVICE_SETTING_USAGE_RECORD = 0x11
};

/*
 * Return setting id (0..17) of the device settings record: one-bit flags as 0 or 1, bytes and 16-bit values
 * as they are. The ids 4 and 5 and everything above 17 return 0xFFFF. Setting 2 is the factory switch
 * "PHY CTS AUTO"; SYSAPI_GetPanelParamStruct reads it to narrow its refresh-rate margin from 2.0 Hz to 0.5 Hz.
 *
 *   id 0..3    flag bits 30, 29, 27, 26 of the record's first word
 *   id 6, 8    bytes at +0x08, +0x0C;  id 10, 11  bytes at +0x0F, +0x10
 *   id 7, 9    16-bit values at +0x09, +0x0D;  id 12, 13, 14, 15  16-bit values at +0x11, +0x13, +0x15, +0x17
 *   id 16, 17  flag bits 7 and 6 of the byte at +0x19
 */
unsigned short nvram_get_device_setting(unsigned int id)
{
    unsigned short result = 0xffff;
    switch (id) {
    case 0: result = (unsigned char)device_settings.flag_30; break;
    case 1: result = (unsigned char)device_settings.flag_29; break;
    case DEVICE_SETTING_PHY_CTS_AUTO: result = (unsigned char)device_settings.phy_cts_auto; break;
    case 3: result = (unsigned char)device_settings.flag_26; break;
    case DEVICE_SETTING_ON_TIME_MINUTES: result = device_settings.on_time_minutes; break;
    case DEVICE_SETTING_ON_TIME_HOURS: result = device_settings.on_time_hours; break;
    case DEVICE_SETTING_8: result = device_settings.byte_0x0c; break;
    case DEVICE_SETTING_9: result = device_settings.half_0x0d; break;
    case DEVICE_SETTING_EL_COUNT: result = device_settings.el_count; break;
    case DEVICE_SETTING_OFFS_COUNT: result = device_settings.offs_count; break;
    case DEVICE_SETTING_EL_HOURS: result = device_settings.el_hours; break;
    case DEVICE_SETTING_OFFS_HOURS: result = device_settings.offs_hours; break;
    case DEVICE_SETTING_EL_RUNS: result = device_settings.el_runs; break;
    case DEVICE_SETTING_OFFS_RUNS: result = device_settings.offs_runs; break;
    case DEVICE_SETTING_SENSING_TEST: result = (unsigned char)device_settings.sensing_test; break;
    case DEVICE_SETTING_USAGE_RECORD: result = (unsigned char)device_settings.usage_record; break;
    }
    return result;
}
