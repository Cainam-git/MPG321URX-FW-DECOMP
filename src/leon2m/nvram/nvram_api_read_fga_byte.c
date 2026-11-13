/* nvram_api_read_fga_byte  (FUN_a0149268)
 *
 * Read one byte of the FGA block in the EEPROM.
 * Returns: byte
 * Name basis: derived - forwards to the FGA block byte read; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149268 @ 0xa0149268, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: the callee is declared with an empty parameter list returning int;
 * the two parameters are declared and unused.
 */
extern int nvram_read_fga_byte();

/*
 * Read one byte of the FGA block in the EEPROM: a plain forward to nvram_read_fga_byte, which takes no
 * argument. Nothing calls it.
 */
unsigned char nvram_api_read_fga_byte(unsigned int unused1, unsigned int unused2)
{
  return nvram_read_fga_byte();
}
