/* nvram_api_restore_factory_records  (FUN_a014564c)
 *
 * Write the ROM default records to the EEPROM.
 * Note: Writes the EEPROM.
 * Name basis: derived - tail call nvram_restore_factory_records(1); unused
 *
 * Matching notes
 * --------------
 * FUN_a014564c (leon2m 0xa014564c, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a void wrapper with a constant argument; the call is a tail call and the nop after it is the one
 * the debug-line information puts behind it.
 */
extern void nvram_restore_factory_records(int);

#define RESTORE_ALL_FIELDS 1    /* argument of nvram_restore_factory_records (the other mode writes only five fields of the settings record) */

/* Call nvram_restore_factory_records(1). Nothing in the image calls this routine or refers to its address. */
void nvram_api_restore_factory_records(void)
{
    nvram_restore_factory_records(RESTORE_ALL_FIELDS);
}
