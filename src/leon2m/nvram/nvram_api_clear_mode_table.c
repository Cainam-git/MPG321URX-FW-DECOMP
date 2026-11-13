/* nvram_api_clear_mode_table  (FUN_a01454c4)
 *
 * Clear the saved-mode table, or the table and both records.
 * Note: Writes the EEPROM.
 * Name basis: derived - selector 2 = nvram_clear_mode_table, above 3 = nvram_clear_mode_table_and_records;
 *   unused
 *
 * Matching notes
 * --------------
 * FUN_a01454c4 (leon2m 0xa01454c4, 68 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a switch with explicit empty cases 0, 1 and 3; the two calls are tail calls.
 */
extern void nvram_clear_mode_table_and_records(void);
extern void nvram_clear_mode_table(void);

/*
 * Clear stored data in the EEPROM by selector:
 *   2         the saved-mode table (nvram_clear_mode_table)
 *   above 3   the mode table and both records (nvram_clear_mode_table_and_records)
 *   0, 1, 3   nothing
 * Nothing in the image calls this routine or refers to its address.
 */
void nvram_api_clear_mode_table(unsigned char selector)
{
    switch (selector) {
    case 0:
    case 1:
    case 3:
        break;
    case 2:
        nvram_clear_mode_table();
        break;
    default:
        nvram_clear_mode_table_and_records();
        break;
    }
}
