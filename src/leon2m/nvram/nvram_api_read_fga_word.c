/* nvram_api_read_fga_word  (FUN_a0149280)
 *
 * Read one 16-bit value of the FGA block in the EEPROM.
 * Returns: value
 * Name basis: derived - forwards to the FGA block read at offset 0x70 + 2 * index; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149280 @ 0xa0149280, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: the index is masked with 0xff in the (unsigned int) parameter itself
 * before the call; the callee is declared with an empty parameter list returning int; the second parameter is
 * declared and unused.
 */
extern int nvram_read_fga_word();

/*
 * Read one 16-bit value of the FGA block in the EEPROM. The value is number "index" of the block
 * (nvram_read_fga_word reads it at block offset 0x70 + 2 * index). Nothing calls it.
 */
unsigned short nvram_api_read_fga_word(unsigned int index, unsigned int unused)
{
  index = index & 0xff;
  return nvram_read_fga_word(index);
}
