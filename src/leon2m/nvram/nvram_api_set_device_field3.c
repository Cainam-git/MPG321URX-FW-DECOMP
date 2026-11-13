/* nvram_api_set_device_field3  (FUN_a01452d0)
 *
 * Store two values in the 16-bit field at +3 of the device settings and save them.
 * Note: Writes the EEPROM.
 * Name basis: descriptive - nvram_write_settings_record, then a block set-up call; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01452d0 @ 0xa01452d0, flags -mcpu=v8 -O3 -g.
 * Source form: the field is a 16-bit bit-field at bytes +0x03..+0x04 of a packed, 4-byte aligned record, so it
 * straddles the words +0x00 and +0x04 and each store is two word read-modify-writes. The two field stores are
 * separate statements; GCC merges them into one read-modify-write per word, and the dead 'a << 24' term of the
 * first store stays in the +0x04 word update as in the firmware.
 */

/* The device settings record (0x50 bytes at 0xA802E1A0, docs/RECORDS.md); only the field used here is named. */
struct __attribute__((packed, aligned(4))) device_settings_record {
    unsigned char byte_0x00, byte_0x01, byte_0x02;
    unsigned short half_0x03:16;                /* bytes +0x03..+0x04 */
    unsigned char rest[0x50 - 5];
};
extern struct device_settings_record device_settings;
extern void nvram_write_settings_record(void *, unsigned char);
extern void panel_spread_configure(unsigned char, unsigned short, unsigned short);

/*
 * Store a, then value, in the 16-bit field at bytes +0x03..+0x04 of the device settings record (the second store
 * replaces the first), write the record to the EEPROM with nvram_write_settings_record, then call
 * panel_spread_configure(1, field, field) with the field read back from the record. Nothing calls this routine
 * directly.
 */
void nvram_api_set_device_field3(unsigned char a, unsigned short value)
{
    device_settings.half_0x03 = a;
    device_settings.half_0x03 = value;
    nvram_write_settings_record(&device_settings, 0);
    panel_spread_configure(1, device_settings.half_0x03, device_settings.half_0x03);
}
