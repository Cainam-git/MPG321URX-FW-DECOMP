/* pq_get_block8_table_byte  (FUN_a01411c8)
 *
 * Return the first byte of the block-8 table entry for a preset.
 * Returns: byte
 * Name basis: descriptive - index from the preset and the block variant
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01411c8 @ 0xa01411c8-0xa01411f8 (12 words), flags -mcpu=v8 -O3 -g.
 * Source form: the mask is a separate first statement 'row &= 0xff;' on the unsigned int parameter (the firmware
 * masks in place before the call; an unsigned char parameter or the mask inside the index expression masks into a
 * fresh register after the call); pq_get_block8_variant is declared returning unsigned char.
 */
extern unsigned char pq_block8_value_tables[];
extern unsigned char pq_get_block8_variant(void);

#define VALUE_ROW_ENTRIES_SHIFT 4       /* 16 entries per row of pq_block8_value_tables */
#define VALUE_ENTRY_BYTES       2       /* each entry is a byte pair */

/*
 * Return the first byte of one entry of pq_block8_value_tables.
 *
 *   row  the table row (the low byte is used); the only caller, pq_get_preset_table_byte, passes the stored
 *        preset index (sys_config byte +0x1D)
 *
 * The entry within the row is the 4-bit field that pq_get_block8_variant reads from register 0xCF012FDC.
 * pq_get_block8_table_byte_alt returns the second byte of the same entry.
 */
unsigned char pq_get_block8_table_byte(unsigned int row)
{
    unsigned int entry;
    row &= 0xff;
    entry = pq_get_block8_variant();
    return pq_block8_value_tables[((row << VALUE_ROW_ENTRIES_SHIFT) + entry) * VALUE_ENTRY_BYTES];
}
