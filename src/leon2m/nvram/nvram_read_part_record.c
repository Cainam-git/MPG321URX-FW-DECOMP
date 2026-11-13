/* nvram_read_part_record  (FUN_a0153c54)
 *
 * Read the 0x30-byte settings part record (EEPROM offset 0x440) into a buffer.
 *   buffer: destination buffer
 * Name basis: derived - tail call to the EEPROM read wrapper with offset 0x440, length 0x30
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0153c54, flags -mcpu=v8 -O2 -g.
 * Source form: the call is a tail call; the last word of the routine is the nop the compiler places behind such a
 * call sequence.
 */
extern void nvram_read(unsigned char, unsigned short, unsigned short, unsigned char *);

/*
 * Read the part record (0x30 bytes at EEPROM offset 0x440, device 0) into a buffer.
 *
 *   buffer  destination, 0x30 bytes
 *
 * Nothing in the firmware calls it and no stored address points at it.
 */
void nvram_read_part_record(unsigned char * buffer)
{
    nvram_read(0, 0x440, 0x30, buffer);
}
