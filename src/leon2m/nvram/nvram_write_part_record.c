/* nvram_write_part_record  (FUN_a0153994)
 *
 * Write the 0x30-byte part record to EEPROM offset 0x440.
 * Note: Writes the EEPROM.
 * Name basis: derived - nvram_write(0, 0x440, 0x30, ...)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0153994, flags -mcpu=v8 -O2 -g.
 * Source form: nvram_write is declared without a prototype; the buffer is passed on as a 4-byte value.
 */
extern int nvram_write();

/*
 * Save the part record (0x30 bytes at EEPROM offset 0x440, device 0) from a buffer.
 *
 *   buffer  the record to write; the caller passes part_record
 *   commit  last argument of nvram_write (the caller passes 0)
 */
void nvram_write_part_record(unsigned int buffer, unsigned char commit)
{
  nvram_write(0,0x440,0x30,buffer,commit);
  return;
}
