/* osd_get_text  (FUN_a00a3844)
 *
 * Return the text pointer at an index of a menu text table.
 *   table: text table
 *   index
 * Returns: text pointer
 * Note: Index = item * 29 + language for the translated tables.
 * Name basis: derived - callers pass a text table and settings byte +8 (language)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a3844, flags -mcpu=v8 -O3 -g.
 * Source form: the table address is passed as an int and the index is masked to 16 bits in the expression.
 */

/*
 * Return entry 'index' of a table of 4-byte text pointers.
 *
 *   table  address of the text table
 *   index  entry number, taken as 16 bits
 *
 * Callers pass a menu text table and an index; for the translated tables the index is built from the item and
 * the language (settings byte +8).
 */
unsigned int osd_get_text(int table, unsigned short index)

{
  return *(unsigned int *)(table + (index & 0xffff) * 4);
}
