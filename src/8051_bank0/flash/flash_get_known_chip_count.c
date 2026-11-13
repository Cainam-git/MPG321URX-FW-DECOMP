/* flash_get_known_chip_count  (FUN_CODE_18e8)
 *
 * Return 57, the number of chips in the built-in table.
 * Returns: 57
 * Name basis: proven - constant
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 */

#define FLASH_KNOWN_CHIP_COUNT  57      /* records in flash_chip_table (CODE 0x4000, 6 bytes each) */

/* flash_get_known_chip_count
 *
 * Returns the number of records in flash_chip_table.  Only caller: flash_identify, as the bound of its search.
 */
unsigned char flash_get_known_chip_count(void)
{
    return FLASH_KNOWN_CHIP_COUNT;
}
