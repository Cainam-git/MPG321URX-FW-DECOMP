/* nvram_validate_settings_at_startup  (FUN_a0153c74)
 *
 * Check the saved settings at start-up; write the ROM defaults or blank the saved-mode table if bad.
 * Note: A wrong version word (or an unusable EEPROM) writes both ROM default records; a wrong marker only
 *   blanks EEPROM 0x300..0x43F and resets five fields.
 * Name basis: proven - prints 'DG_SYSSETTING OPR is invalid' and 'SysNvram_IsEmpty 1 / 2'; reads EEPROM 0x470
 *   / 0x440 and compares the header words with the ROM defaults; called from the start-up routine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0153c74 @ 0xa0153c74..0xa01541ec (350 words), flags -mcpu=v8 -O3 -g.
 * The shape comparison in tools/diff.py reports a difference for this function: the firmware's ROM base
 * 'sethi %hi(nvram_default_records); or %r, %lo(nvram_default_records)' prints as 'mov', so the later field loads are labelled
 * differently. The byte-exact link check (tools/exact.py) finds the bytes equal to the firmware.
 * Source form: (1) the 'not usable' arm FIRST ('if (!nvram_is_device_usable(0)) ... else if (check_stored_header()
 * == 1) ... else if (check_stored_header() == 2)'): gives the firmware's register renaming AND its stack-slot
 * sharing (the defaults copy reuses the first check's buffer slot fp-88 / the second's fp-216); (2) both record
 * structs 8-byte aligned (no-code type attribute: the firmware copies the ROM records with ldd/std, which gcc only
 * does inline for 8-aligned structs; with 2-byte alignment it calls memcpy); (3) the defaults as 'declare record,
 * part; part = ROM.part; record = ROM.record;' (load order of the copy); (4) a u16 total 'total = 0x140;
 * i < total / 16' (gives 'cmp 0x14; bcs' instead of 'cmp 0x13; bleu'); (5) the field order of the blank case
 * marker_0x38, ring_index, word_0x3e, word_0x40 (gives the firmware's load / store order).
 */
/*
 * Layout of the two records read here. The settings record is the device settings (0x50 bytes at EEPROM 0x470),
 * the part record is 0x30 bytes at EEPROM 0x440; their defaults sit side by side in ROM (nvram_default_records,
 * part record first). Only the fields this routine tests or sets have names.
 */
struct settings_record {
    unsigned char before_ring_index[0x1a];
    unsigned char ring_index;               /* +0x1A: next row of the saved-mode table (see nvram_store_mode_row) */
    unsigned char before_marker[0x1d];
    unsigned short marker_0x38;             /* +0x38: compared with the ROM default */
    unsigned short version;                 /* +0x3A: compared with the ROM default */
    unsigned short blank_check;             /* +0x3C: expected to equal nvram_get_blank_value() */
    unsigned short word_0x3e;               /* +0x3E: compared with the ROM default */
    unsigned short word_0x40;               /* +0x40: compared with the ROM default */
    unsigned short end_marker;              /* +0x42: ROM copy compared with the part record's marker */
    unsigned char after_end_marker[0xc];
} __attribute__((aligned(8)));
struct part_block { unsigned char before_marker[0x28]; unsigned short marker; unsigned char after_marker[6]; } __attribute__((aligned(8)));
struct default_pair { struct part_block part; struct settings_record settings; };
struct default_records { unsigned char other[0x140]; struct default_pair pair; };   /* 0x000..0x13F: not read here */
extern const struct default_records nvram_default_records;
extern struct settings_record device_settings;
extern struct part_block part_record;
extern void (*sys_callback_table_slot12)(void);
extern unsigned char nvram_is_device_usable(unsigned char);
extern void nvram_read(unsigned char, unsigned short, unsigned short, void *);
extern void nvram_write(unsigned char, unsigned short, unsigned short, void *, unsigned char);
extern unsigned short nvram_get_blank_value(void);
extern void *memcpy(void *, const void *, unsigned int);
extern int dbg_printf(const char *, ...);

/*
 * Read the settings record from the EEPROM and compare its header words with the ROM defaults.
 * The record is read twice per round until both reads give the same version word.
 * Returns 1 when the version, word_0x40 or word_0x3e differ from the ROM (the record is not ours),
 * 2 when marker_0x38 differs or blank_check is not the blank value, 0 when the header is good.
 * The stored and the ROM version are printed.
 */
static unsigned char check_stored_header(void)
{
    struct settings_record record = {{0}};
    unsigned short first_version, stored_version;

    do {
        nvram_read(0, 0x470, 0x50, &record);
        first_version = record.version;
        nvram_read(0, 0x470, 0x50, &record);
        stored_version = record.version;
    } while (stored_version != first_version);
    dbg_printf("%04x,%04x\r\n", stored_version, nvram_default_records.pair.settings.version);
    if (nvram_default_records.pair.settings.version != stored_version)
        return 1;
    if (record.word_0x40 != nvram_default_records.pair.settings.word_0x40)
        return 1;
    if (record.word_0x3e != nvram_default_records.pair.settings.word_0x3e)
        return 1;
    if (record.marker_0x38 != nvram_default_records.pair.settings.marker_0x38)
        return 2;
    return record.blank_check != nvram_get_blank_value() ? 2 : 0;
}

/*
 * Start-up check of the saved settings (called once by startup_bring_up_system). Three cases, tried in order:
 *  1. The settings EEPROM is not usable: print "DG_SYSSETTING OPR is invalid" and write both ROM default
 *     records (part record, then settings record).
 *  2. The header of the stored settings record is wrong (check_stored_header returns 1): print
 *     "SysNvram_IsEmpty 1" and write both ROM default records the same way.
 *  3. Otherwise check_stored_header runs a second time (a full read again); when it returns 2: print
 *     "SysNvram_IsEmpty 2", fill the 0x140 bytes at EEPROM 0x300 (the saved-mode table) with 0xFF in 20 chunks
 *     of 16, read the settings record, set its marker_0x38, ring_index, word_0x3e and word_0x40 from the ROM
 *     defaults and blank_check to the blank value, and write it back. The rest of the record stays.
 * Then, always: load the part record into RAM (part_record) and the settings record into RAM
 * (device_settings). Two ROM constants are tested last: the part record's marker must be 0xA5A5 and the
 * settings record's end_marker must equal it; if not, "While : 3" or "While : 4" is printed and the routine
 * never returns. Finally the routine in sys_callback_table_slot12 is called when one is set.
 *
 * Every EEPROM write waits for the chip without a time limit (nvram_write).
 */
void nvram_validate_settings_at_startup(void)
{
    if (!nvram_is_device_usable(0)) {
        dbg_printf("\nDG_SYSSETTING OPR is invalid %d\r\n", 1);
        {
            struct settings_record record;
            struct part_block part;
            part = nvram_default_records.pair.part;
            record = nvram_default_records.pair.settings;
            nvram_write(0, 0x440, 0x30, &part, 0);
            nvram_write(0, 0x470, 0x50, &record, 1);
        }
    } else if (check_stored_header() == 1) {
        dbg_printf("\nSysNvram_IsEmpty %d\r\n", 1);
        {
            struct settings_record record;
            struct part_block part;
            part = nvram_default_records.pair.part;
            record = nvram_default_records.pair.settings;
            nvram_write(0, 0x440, 0x30, &part, 0);
            nvram_write(0, 0x470, 0x50, &record, 1);
        }
    } else if (check_stored_header() == 2) {
        {
            unsigned char blank_pattern[16];
            struct settings_record record;
            unsigned short i, total;
            dbg_printf("\nSysNvram_IsEmpty %d\r\n", 2);
            memcpy(blank_pattern, "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377", 16);
            total = 0x140;
            for (i = 0; i < total / 16; i++)
                nvram_write(0, 0x300 + (i << 4), 16, blank_pattern, 0);
            total = total - (i << 4);
            if (total != 0)
                nvram_write(0, 0x300 + (i << 4), total, blank_pattern, 0);
            nvram_read(0, 0x470, 0x50, &record);
            record.marker_0x38 = nvram_default_records.pair.settings.marker_0x38;
            record.ring_index = nvram_default_records.pair.settings.ring_index;
            record.word_0x3e = nvram_default_records.pair.settings.word_0x3e;
            record.word_0x40 = nvram_default_records.pair.settings.word_0x40;
            record.blank_check = nvram_get_blank_value();
            nvram_write(0, 0x470, 0x50, &record, 1);
        }
    }
    nvram_read(0, 0x440, 0x30, &part_record);
    nvram_read(0, 0x470, 0x50, &device_settings);
    /* The two ROM markers are constants; a mismatch stops the monitor here. */
    if (nvram_default_records.pair.part.marker != 0xa5a5) {
        dbg_printf("\nWhile : %d\r\n", 3);
        for (;;)
            ;
    }
    if (nvram_default_records.pair.settings.end_marker != nvram_default_records.pair.part.marker) {
        dbg_printf("\nWhile : %d\r\n", 4);
        for (;;)
            ;
    }
    if (sys_callback_table_slot12 != 0)
        sys_callback_table_slot12();
}
