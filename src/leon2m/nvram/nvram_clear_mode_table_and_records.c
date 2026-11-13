/* nvram_clear_mode_table_and_records  (FUN_a0153a5c)
 *
 * Fill EEPROM 0x300..0x4BF (mode table and both records) with the blank pattern.
 * Note: Writes the EEPROM.
 * Name basis: derived - 28 writes of the pattern at 0x1a75e6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0153a5c, flags -mcpu=v8 -O3 -g.
 * Source form: the loop limit is kept in a local as '0x1b + 1' and the loop is a do-while; the buffer is passed
 * as an int. The final write has length 0 and is skipped.
 */
extern unsigned char nvram_blank_pattern[];

extern int memcpy();
extern int nvram_write();

/*
 * Blank the EEPROM from offset 0x300 up to 0x4BF (device 0): the saved-mode table (0x300..0x43F), the part
 * record (0x440..0x46F) and the device settings record (0x470..0x4BF). The 16-byte blank pattern is written
 * 28 times, 16 bytes at a time. Called by nvram_api_clear_mode_table for selectors above 3.
 */
void nvram_clear_mode_table_and_records(void)
{
  unsigned short row;
  unsigned short remaining;     /* the row count in the loop; the bytes left after it (0) at the end */
  unsigned char row_buffer[16];
  memcpy(row_buffer, nvram_blank_pattern, 0x10);
  remaining = 0x1b + 1;
  row = 0;
  do
  {
    nvram_write(0, (unsigned short) ((row * 0x10) + 0x300), 0x10, (int) row_buffer, 0);
    row = row + 1;
  }
  while (row < remaining);
  remaining = 0x1c0 - (row * 0x10);
  if (remaining != 0)
  {
    nvram_write(0, (unsigned short) ((row * 0x10) + 0x300), remaining, (int) row_buffer, 0);
  }
}
