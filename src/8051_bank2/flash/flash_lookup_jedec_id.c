/* flash_lookup_jedec_id  (FUN_CODE_c44e)
 *
 * Return the chip-table index that matches the JEDEC ID, 0xFF if none.
 * Returns: index or 0xFF
 * Name basis: proven - 8-byte records at CODE 0xCB8C, bytes 5..7 = JEDEC manufacturer / type / capacity
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameters reply (generic pointer, 0x0902..0x0904, from R3/R2/R1) and
 * table (generic pointer, memory parameter 0x0905..0x0907), local row at 0x0908. All reads are ?C?CLDOPTR with a
 * field offset in DPTR; Keil keeps row * 8 in R6:R7 for the first two fields and recomputes it with B for the third
 * and for the end test. The caller declares table as void *.
 */
#define TABLE_END       0xff    /* id0 of the row after the last chip */
#define CHIP_NOT_FOUND  0xff

/* A row of flash_chip_table (8 bytes); only the three id bytes are read here. */
struct flash_chip_ids { unsigned char other[5]; unsigned char id0; unsigned char id1; unsigned char id2; };

/* flash_lookup_jedec_id: find the row of table whose id bytes equal reply[3], reply[4], reply[5], in this order.
 *
 * reply:  the reply buffer of the Read ID command (FLASH_CMD_READ_ID 0x9F) in flash_identify_chip; the id is at
 *         bytes 3..5.
 * table:  flash_chip_table (CODE 0xCB8C).
 * Returns the row number, or CHIP_NOT_FOUND (0xFF) at the table end or after 255 rows. A row is compared before the
 * end test, so the TABLE_END row itself can match.
 * Caller: flash_identify_chip, only when reply bytes 3 and 4 are EF 40. */
unsigned char flash_lookup_jedec_id(unsigned char *reply, struct flash_chip_ids *table)
{
    unsigned char row;
    for (row = 0; row < 0xff; row++) {
        if (table[row].id0 == reply[3] && table[row].id1 == reply[4] && table[row].id2 == reply[5]) return row;
        if (table[row].id0 == TABLE_END) break;
    }
    return CHIP_NOT_FOUND;
}
