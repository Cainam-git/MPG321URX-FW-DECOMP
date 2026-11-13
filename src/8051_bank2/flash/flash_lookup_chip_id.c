/* flash_lookup_chip_id  (FUN_CODE_b044)
 *
 * Return the chip-table index whose three id bytes match, 0xFF if none.
 *   chip_id: chip table
 *   table: three id bytes
 * Returns: index or 0xFF
 * Name basis: derived - 8-byte records, bytes 5..7; used with the id read through scaler regs 0xF064..0xF066
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameters chip_id (generic pointer, 0x0902) and table (generic
 * pointer, 0x0905, passed in the parameter block); locals row 0x0908, j 0x0909, found 0x090A.
 * Source forms the bytes depend on: 'row = 0;' in front of the loop as well (two stores to 0x0908); 'break' at the
 * table end (CPL A / JNZ to the shared 'return 0xFF'); 'continue' after a set bit; the inner loop 'j != 3'.
 */
#define ID_BYTES        3
#define TABLE_END       0xff    /* id0 of the row after the last chip */
#define NO_THIRD_BYTE   0xff    /* id2 of a row whose id has only two bytes to match */
#define CHIP_NOT_FOUND  0xff
#define MATCHED_ID0     0x01
#define MATCHED_ID1     0x02
#define MATCHED_ID2     0x04
#define MATCHED_ALL     0x07

/* A row of flash_chip_table (8 bytes); only the three id bytes are read here. */
struct flash_chip_ids { unsigned char other[5]; unsigned char id0; unsigned char id1; unsigned char id2; };

/* flash_lookup_chip_id: find the row of table whose three id bytes are the three bytes of chip_id, in any order.
 *
 * chip_id: three bytes (flash_identify_chip reads them from service registers 0xF064..0xF066).
 * table:   flash_chip_table (CODE 0xCB8C).
 * Returns the row number, or CHIP_NOT_FOUND (0xFF) at the table end or after 255 rows.
 *
 * Each byte of chip_id marks the first of id0, id1, id2 that equals it and is not marked yet. A row with
 * id2 = NO_THIRD_BYTE counts id2 as matched. Caller: flash_identify_chip, when the direct lookup
 * (flash_lookup_jedec_id) found nothing. */
unsigned char flash_lookup_chip_id(unsigned char *chip_id, struct flash_chip_ids *table)
{
    unsigned char row;
    unsigned char j;
    unsigned char found;
    row = 0;
    for (row = 0; row < 0xff; row++) {
        found = 0;
        if (table[row].id0 == TABLE_END) break;
        for (j = 0; j != ID_BYTES; j++) {
            if (chip_id[j] == table[row].id0 && !(found & MATCHED_ID0)) {
                found |= MATCHED_ID0;
                continue;
            }
            if (chip_id[j] == table[row].id1 && !(found & MATCHED_ID1)) {
                found |= MATCHED_ID1;
                continue;
            }
            if (chip_id[j] == table[row].id2 && !(found & MATCHED_ID2)) found |= MATCHED_ID2;
        }
        if (table[row].id2 == NO_THIRD_BYTE) found |= MATCHED_ID2;
        if ((found & MATCHED_ALL) == MATCHED_ALL) return row;
    }
    return CHIP_NOT_FOUND;
}
