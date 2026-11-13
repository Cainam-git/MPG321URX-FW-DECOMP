/* nvram_load_default_part_record  (FUN_a015440c)
 *
 * Copy the 0x30-byte ROM default part record to its RAM copy at 0xA802E1F0.
 * Name basis: proven - struct copy from the ROM defaults (0x20140) to RAM
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015440c, flags -mcpu=v8 -O3 -g.
 * Source form: the record types and the ROM block at 0x20000 are those of nvram_validate_settings_at_startup. The
 * structures are 8-byte aligned (no-code type attribute), so the copy is done inline with ldd/std pairs; the ROM
 * base 0x20000 is set with sethi alone and the field offset 0x140 is added in each load.
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
extern struct part_block part_record;

/*
 * Copy the 0x30-byte ROM default part record (ROM 0x20140) to part_record in RAM.
 * Called by startup_load_default_records, which calls nvram_load_default_settings_record next.
 */
void nvram_load_default_part_record(void)
{
    part_record = nvram_default_records.pair.part;
}
