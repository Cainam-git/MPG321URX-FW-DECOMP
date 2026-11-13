/* input_api_set_device_option_bit25  (FUN_a0149018)
 *
 * Wake the input ports, store device option bit 25 and save the settings record.
 * Note: Writes the EEPROM.
 * Name basis: descriptive - input_power_on_ports_by_mask twice, bit 25 of the device record,
 *   nvram_write_settings_record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149018, flags -mcpu=v8 -O3 -g.
 * Source form: keep the bit-field declaration as one 32-bit unsigned int with a 1-bit field at bit 25; the store is to that 1-bit field.
 * Source form: keep the two input_power_on_ports_by_mask calls, the bit-field store, and the nvram_write_settings_record call in this order; the last call is in tail position.
 */
/* The 32-bit word of the device settings record accessed here; bit 25 is the device option bit. */
struct device_settings_word {
    unsigned int bits_0x1a_0x1f : 6, device_option_bit25 : 1, bits_0x00_0x18 : 25;
};
extern struct device_settings_word device_settings;
extern void input_power_on_ports_by_mask(unsigned int, unsigned int);
extern void nvram_write_settings_record(void *, unsigned int);

/*
 * Wake the input ports selected by masks 0x10 and 0x20, store the bit 25 device option in the device settings record, and save that record.
 *
 * bit25_value: value to store in the 1-bit field at bit 25; only its bit 0 is kept.
 *
 * No direct call to it was found in the image. nvram_get_device_option_bit25 reads the bit back.
 */
void input_api_set_device_option_bit25(unsigned int bit25_value)
{
    /* Wake the input ports before the device option is stored. */
    input_power_on_ports_by_mask(0x10, 1);
    input_power_on_ports_by_mask(0x20, 1);
    /* The 1-bit field keeps only the low bit of the value. */
    device_settings.device_option_bit25 = bit25_value;
    /* Save the 0x50-byte device settings record. */
    nvram_write_settings_record(&device_settings, 0);
}
