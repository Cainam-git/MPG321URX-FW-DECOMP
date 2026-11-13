/* pq_get_preset_table_byte  (FUN_a014bcac)
 *
 * Return the table byte for the current preset (first table).
 * Returns: table byte
 * Name basis: descriptive - ROM table look-up by stSysConfig byte +0x1D; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014bcac @ 0xa014bcac, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the callee is declared without a prototype and returning int; the stored byte is widened into
 * an unsigned int local before the call.
 */
extern unsigned char sys_config_preset_index;
extern int pq_get_block8_table_byte();

/*
 * Return the first byte of the pq_block8_value_tables entry in the row of the stored preset index
 * (sys_config byte +0x1D), through pq_get_block8_table_byte. Nothing in the firmware calls this routine.
 */
unsigned char pq_get_preset_table_byte(void)
{
  unsigned int preset_index;

  preset_index = (unsigned int)sys_config_preset_index;
  return pq_get_block8_table_byte(preset_index);
}
