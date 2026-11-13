/* nvram_api_write_fga_byte  (FUN_a0149254)
 *
 * Write one byte of the FGA block in the EEPROM.
 * Note: Writes the EEPROM.
 * Name basis: derived - forwards to the FGA block byte write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149254 @ 0xa0149254, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: the callee is declared with an empty parameter list returning int and
 * the argument is passed on as a byte.
 */
extern int nvram_write_fga_byte();

/*
 * Write one byte of the FGA block in the EEPROM: a plain forward to nvram_write_fga_byte.
 * Called by ddc_tool_run_factory_reset.
 */
void nvram_api_write_fga_byte(unsigned char value)

{
  nvram_write_fga_byte(value);
  return;
}
