/* nvram_set_device_setting  (FUN_a0145c5c)
 *
 * Store one of the eighteen fields of the device settings record.
 * Name basis: proven - setter for the packed record saved at EEPROM offset 0x470
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145c5c @ 0xa0145c5c, flags -mcpu=v8 -O3 -g. The jump table of the switch is at 0xe3280 in the
 * firmware file.
 * Source form: the record is a packed, 4-byte aligned struct (16-bit fields at odd offsets are accessed with word
 * read-modify-writes; the fields at +0x13 and +0x17 straddle two words, so both words are written). The 16-bit
 * fields are 'unsigned short x:16' bit-fields (the firmware's value conversion is 'sll 16 / srl 8'; an
 * 'unsigned int x:16' field would mask with 'and 0xffff' instead); the byte fields are plain unsigned char
 * members (stb; byte bit-fields would be word read-modify-writes on SPARC). No volatile.
 */

/* The device settings record (0x50 bytes at 0xA802E1A0, docs/RECORDS.md); only the fields this setter stores are named. */
struct __attribute__((packed, aligned(4))) device_settings_record {
    unsigned int power_status:1, flag_30:1, flag_29:1, bit_28:1, phy_cts_auto:1, flag_26:1, rest0:26;   /* +0x00 */
    unsigned int word_0x04;                                                                            /* +0x04 */
    unsigned char on_time_minutes;                                                                      /* +0x08 */
    unsigned short on_time_hours:16;                                                                    /* +0x09 */
    unsigned char byte_0x0b, byte_0x0c;                                                                 /* +0x0b, +0x0c */
    unsigned short half_0x0d:16;                                                                        /* +0x0d */
    unsigned char el_count, offs_count;                                                                 /* +0x0f, +0x10 */
    unsigned short el_hours:16, offs_hours:16, el_runs:16, offs_runs:16;                                /* +0x11, +0x13, +0x15, +0x17 */
    unsigned int sensing_test:1, usage_record:1, rest1:6;                                               /* +0x19 */
};
extern struct device_settings_record device_settings;

/* Setting numbers, as in nvram_get_device_setting. */
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
 * Store value in setting id (0..17) of the device settings record in RAM. The ids 4 and 5 and everything above
 * 17 do nothing. The fields are those that nvram_get_device_setting reads:
 *   id 0, 1, 2, 3  flag bits 30, 29, 27 (phy_cts_auto), 26 of the record's first word
 *   id 6, 8        bytes at +0x08 (on_time_minutes) and +0x0C;  id 10, 11  bytes at +0x0F, +0x10 (el_count, offs_count)
 *   id 7, 9        16-bit values at +0x09 (on_time_hours) and +0x0D
 *   id 12, 13, 14, 15  16-bit values at +0x11, +0x13, +0x15, +0x17 (el_hours, offs_hours, el_runs, offs_runs)
 *   id 16, 17      flag bits 7 and 6 of the byte at +0x19 (sensing_test, usage_record)
 * The value is cut to the width of the field. Called by power_enter_app_state, App_CoolInitialize, osd_factory_activate_item and others.
 */
void nvram_set_device_setting(unsigned int id, unsigned int value)
{
    switch (id) {
    case 0: device_settings.flag_30 = value; break;
    case 1: device_settings.flag_29 = value; break;
    case DEVICE_SETTING_PHY_CTS_AUTO: device_settings.phy_cts_auto = value; break;
    case 3: device_settings.flag_26 = value; break;
    case DEVICE_SETTING_ON_TIME_MINUTES: device_settings.on_time_minutes = value; break;
    case DEVICE_SETTING_ON_TIME_HOURS: device_settings.on_time_hours = value; break;
    case DEVICE_SETTING_8: device_settings.byte_0x0c = value; break;
    case DEVICE_SETTING_9: device_settings.half_0x0d = value; break;
    case DEVICE_SETTING_EL_COUNT: device_settings.el_count = value; break;
    case DEVICE_SETTING_OFFS_COUNT: device_settings.offs_count = value; break;
    case DEVICE_SETTING_EL_HOURS: device_settings.el_hours = value; break;
    case DEVICE_SETTING_OFFS_HOURS: device_settings.offs_hours = value; break;
    case DEVICE_SETTING_EL_RUNS: device_settings.el_runs = value; break;
    case DEVICE_SETTING_OFFS_RUNS: device_settings.offs_runs = value; break;
    case DEVICE_SETTING_SENSING_TEST: device_settings.sensing_test = value; break;
    case DEVICE_SETTING_USAGE_RECORD: device_settings.usage_record = value; break;
    }
}
