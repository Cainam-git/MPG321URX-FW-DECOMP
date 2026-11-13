/* pq_get_preset_table_byte_alt  (FUN_a014bcc8)
 *
 * Return the table byte for the current preset (second table).
 * Returns: table byte
 * Name basis: descriptive - twin of pq_get_preset_table_byte on the neighbouring table; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014bcc8 @ 0xa014bcc8, flags -mcpu=v8 -O2 -g (section default).
 * Source form: as pq_get_preset_table_byte (callee without a prototype, returning int; an unsigned int local).
 */
extern unsigned char sys_config_preset_index;
extern int pq_get_block8_table_byte_alt();

/*
 * Return the second byte of the pq_block8_value_tables entry in the row of the stored preset index
 * (sys_config byte +0x1D), through pq_get_block8_table_byte_alt. Nothing in the firmware calls this routine.
 */
unsigned char pq_get_preset_table_byte_alt(void)
{
  unsigned int preset_index;

  preset_index = (unsigned int)sys_config_preset_index;
  return pq_get_block8_table_byte_alt(preset_index);
}
