/* nvram_restore_factory_records  (FUN_a0153b20)
 *
 * Write the ROM default records to the EEPROM, fully or only five fields of the settings record.
 * Note: Writes the EEPROM.
 * Name basis: derived - mode 1 writes both ROM records to 0x440/0x470; else rewrites the settings record with
 *   five ROM fields
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0153b20, flags -mcpu=v8 -O3 -g.
 * Source form: the record types and the ROM block at 0x20000 are those of nvram_validate_settings_at_startup
 * (8-byte aligned structures, copied inline with ldd/std); the field stores run in the order marker_0x38,
 * ring_index, word_0x3e, word_0x40, blank_check.
 */
/*
 * Layout of the records handled here: the device settings record (0x50 bytes; EEPROM 0x470, RAM device_settings)
 * and the part record (0x30 bytes; EEPROM 0x440, RAM part_record). Their ROM defaults sit side by side in
 * nvram_default_records at 0x140, part record first. Only the fields used here have names.
 */
struct settings_record {
    unsigned char before_ring_index[0x1a];
    unsigned char ring_index;               /* +0x1A: next row of the saved-mode table */
    unsigned char before_marker[0x1d];
    unsigned short marker_0x38;             /* +0x38 */
    unsigned short version;                 /* +0x3A */
    unsigned short blank_check;             /* +0x3C: holds nvram_get_blank_value() once set */
    unsigned short word_0x3e;               /* +0x3E */
    unsigned short word_0x40;               /* +0x40 */
    unsigned short end_marker;              /* +0x42 */
    unsigned char after_end_marker[0xc];
} __attribute__((aligned(8)));
struct part_block { unsigned char before_marker[0x28]; unsigned short marker; unsigned char after_marker[6]; } __attribute__((aligned(8)));
struct default_pair { struct part_block part; struct settings_record settings; };
struct default_records { unsigned char other[0x140]; struct default_pair pair; };   /* 0x000..0x13F: not read here */
extern const struct default_records nvram_default_records;
extern void nvram_read(unsigned char, unsigned short, unsigned short, void *);
extern void nvram_write(unsigned char, unsigned short, unsigned short, void *, unsigned char);
extern unsigned short nvram_get_blank_value(void);

/*
 * Put the ROM defaults back into the EEPROM (device 0).
 *
 *   mode  1: write both default records, the part record to 0x440 and the settings record to 0x470.
 *         any other value: read the settings record from 0x470, replace its fields marker_0x38, ring_index,
 *         word_0x3e and word_0x40 with the ROM values and blank_check with nvram_get_blank_value(), and
 *         write it back. The part record is not touched.
 *
 * Called by nvram_api_restore_factory_records, which passes 1.
 */
void nvram_restore_factory_records(unsigned char mode)
{
    struct settings_record record;
    struct part_block part;

    if (mode == 1) {
        part = nvram_default_records.pair.part;
        record = nvram_default_records.pair.settings;
        nvram_write(0, 0x440, 0x30, &part, 0);
        nvram_write(0, 0x470, 0x50, &record, 1);
    } else {
        nvram_read(0, 0x470, 0x50, &record);
        record.marker_0x38 = nvram_default_records.pair.settings.marker_0x38;
        record.ring_index = nvram_default_records.pair.settings.ring_index;
        record.word_0x3e = nvram_default_records.pair.settings.word_0x3e;
        record.word_0x40 = nvram_default_records.pair.settings.word_0x40;
        record.blank_check = nvram_get_blank_value();
        nvram_write(0, 0x470, 0x50, &record, 1);
    }
}
