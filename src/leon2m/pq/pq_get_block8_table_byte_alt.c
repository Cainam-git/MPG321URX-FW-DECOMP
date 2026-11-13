/* pq_get_block8_table_byte_alt  (FUN_a01411f8)
 *
 * Return the second byte of the block-8 table entry for a preset.
 * Returns: byte
 * Name basis: descriptive - twin of pq_get_block8_table_byte
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01411f8 @ 0xa01411f8-0xa014122c (13 words), flags -mcpu=v8 -O3 -g.
 * Source form: as pq_get_block8_table_byte (separate 'row &= 0xff;', unsigned char callee, unsigned int entry),
 * with the + 1 inside the subscript.
 */
extern unsigned char pq_block8_value_tables[];
extern unsigned char pq_get_block8_variant(void);

#define VALUE_ROW_ENTRIES_SHIFT 4       /* 16 entries per row of pq_block8_value_tables */
#define VALUE_ENTRY_BYTES       2       /* each entry is a byte pair */

/*
 * Return the second byte of one entry of pq_block8_value_tables.
 *
 *   row  the table row (the low byte is used); the only caller, pq_get_preset_table_byte_alt, passes the
 *        stored preset index (sys_config byte +0x1D)
 *
 * The entry within the row is the 4-bit field that pq_get_block8_variant reads from register 0xCF012FDC.
 */
unsigned char pq_get_block8_table_byte_alt(unsigned int row)
{
    unsigned int entry;

    row &= 0xff;
    entry = pq_get_block8_variant();
    return pq_block8_value_tables[((row << VALUE_ROW_ENTRIES_SHIFT) + entry) * VALUE_ENTRY_BYTES + 1];
}
