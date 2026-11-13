/* nvram_read_settings_record  (FUN_a0153b00)
 *
 * Read the 0x50-byte settings record (EEPROM offset 0x470) into a buffer.
 * Name basis: derived - tail call to the EEPROM read wrapper with offset 0x470, length 0x50; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0153b00, flags -mcpu=v8 -O2 -g.
 * Source form: the call is a tail call; the last word of the routine is the nop the compiler places behind such a
 * call sequence.
 */
extern void nvram_read(unsigned char, unsigned short, unsigned short, unsigned char *);

/*
 * Read the device settings record (0x50 bytes at EEPROM offset 0x470, device 0) into a buffer.
 *
 *   buffer  destination, 0x50 bytes
 *
 * Nothing in the firmware calls it and no stored address points at it.
 */
void nvram_read_settings_record(unsigned char * buffer)
{
    nvram_read(0, 0x470, 0x50, buffer);
}
