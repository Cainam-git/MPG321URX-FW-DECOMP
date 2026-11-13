/* nvram_clear_mode_table  (FUN_a01539b8)
 *
 * Fill the saved-mode table (EEPROM 0x300..0x43F) with the 16-byte blank pattern.
 * Note: Writes the EEPROM.
 * Name basis: derived - 20 writes of the pattern at 0x1a75e6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01539b8, flags -mcpu=v8 -O3 -g.
 * Source form: the row address is computed in 16-bit arithmetic; the row count 20 is reloaded into 'remaining'
 * in each pass and the loop is written as for (;;) with the exit test at the end. The final write has length 0
 * and is skipped.
 */
extern unsigned char nvram_blank_pattern[];

extern int memcpy();
extern int nvram_write();

#define MODE_TABLE_ADDRESS 0x300        /* EEPROM offset of the saved-mode table */
#define MODE_TABLE_ROWS    20
#define MODE_ROW_SIZE      0x10

/*
 * Blank the saved-mode table (20 rows of 16 bytes at EEPROM offset 0x300, device 0) by writing the 16-byte
 * blank pattern into every row. Called by nvram_api_clear_mode_table for selector 2.
 */
void nvram_clear_mode_table()
{
  unsigned short row;
  unsigned short remaining;     /* the row count in the loop; the bytes left after it (0) at the end */
  unsigned char row_buffer[16];
  memcpy(row_buffer, nvram_blank_pattern, 0x10);
  row = 0;
  for (;;)
  {
    remaining = MODE_TABLE_ROWS;
    nvram_write(0, (unsigned short) ((row * 16) + MODE_TABLE_ADDRESS), MODE_ROW_SIZE, row_buffer, 0);
    row = (unsigned short) (row + 1);
    if (row >= remaining)
    {
      break;
    }
  }

  remaining = (unsigned short) (0x140 - (row * 16));
  if (remaining != 0)
  {
    nvram_write(0, (unsigned short) ((row * 16) + MODE_TABLE_ADDRESS), remaining, row_buffer, 0);
  }
}
