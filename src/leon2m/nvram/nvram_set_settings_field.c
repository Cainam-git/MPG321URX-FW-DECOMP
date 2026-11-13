/* nvram_set_settings_field  (FUN_a014b3fc)
 *
 * Copy one field into the settings record and save the record.
 * Note: Writes the EEPROM.
 * Name basis: derived - field 1 to 4 bytes long copied to the record at 0xA802E1C2, then
 *   nvram_write_settings_record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b3fc, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: byte counters, the length and the offset as unsigned chars preset to 0,
 * set by a switch on the selector; the copy is a loop over the bytes with the record address as the base; the
 * record write is the last call.
 */
extern unsigned char device_settings[];
extern void nvram_write_settings_record(void *, unsigned int);

#define SETTINGS_FIELDS_OFFSET 0x22     /* the five fields start at byte 0x22 of the device settings record */

/*
 * Copy one field into the device settings record and write the record.
 *
 *   field   which field: 0 = 2 bytes at offset 0, 1 = 2 bytes at offset 2, 2 = 4 bytes at offset 4,
 *           3 = 1 byte at offset 8, 4 = 1 byte at offset 9 (offsets counted from byte 0x22 of the record);
 *           any other value copies nothing
 *   src     the bytes to copy
 *
 * Nothing calls it.
 *
 * Note: Writes the EEPROM.
 */
void nvram_set_settings_field(unsigned char field, const unsigned char *src)
{
    unsigned char length = 0, offset = 0, i;

    switch (field) {
    case 0: length = 2; offset = 0; break;
    case 1: length = 2; offset = 2; break;
    case 2: length = 4; offset = 4; break;
    case 3: length = 1; offset = 8; break;
    case 4: length = 1; offset = 9; break;
    }
    for (i = 0; i < length; i++)
        device_settings[SETTINGS_FIELDS_OFFSET + offset + i] = src[i];
    nvram_write_settings_record(device_settings, 0);
}
