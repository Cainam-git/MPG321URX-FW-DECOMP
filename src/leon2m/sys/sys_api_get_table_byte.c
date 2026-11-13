/* sys_api_get_table_byte  (FUN_a014883c)
 *
 * Return the first byte of an entry of the two-byte table at 0x1A6DB2.
 * Returns: byte
 * Name basis: descriptive - plain table look-up; unused
 *
 * Matching notes
 * --------------
 * FUN_a014883c (leon2m 0xa014883c-0xa0148854, 24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to this routine. Source form: an unsigned char parameter indexing an extern
 * byte array with index * 2 (add %o0, %o0).
 */
extern unsigned char input_menu_source_pairs[];

/* Return the first byte of entry index of input_menu_source_pairs (two bytes per entry). Nothing calls
 * this routine. */
unsigned char sys_api_get_table_byte(unsigned char index)
{
    return input_menu_source_pairs[index * 2];
}
