/* nvram_write_settings_record  (FUN_a0153970)
 *
 * Write the 0x50-byte settings record to EEPROM offset 0x470.
 * Note: Writes the EEPROM.
 * Name basis: derived - nvram_write(0, 0x470, 0x50, ...), the counterpart of the EEPROM read wrapper
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0153970, flags -mcpu=v8 -O2 -g.
 * Source form: nvram_write is declared without a prototype; the buffer is passed on as a 4-byte value.
 */
extern int nvram_write();

/*
 * Save the device settings record (0x50 bytes at EEPROM offset 0x470, device 0) from a buffer.
 *
 *   buffer  the record to write; the callers pass device_settings
 *   commit  last argument of nvram_write (0 or 1; the callers pass 0, one passes 1)
 */
void nvram_write_settings_record(unsigned int buffer, unsigned char commit)
{
  nvram_write(0, 0x470, 0x50, buffer, commit);
  return;
}
