/* input_find_source_code_index  (FUN_a012f2dc)
 *
 * Return the index of a code in the four-entry source code table.
 * Returns: index or 0xFF
 * Name basis: descriptive - ROM table at 0x1A5238; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012f2dc @ 0xa012f2dc, flags -mcpu=v8 -O2 -g.
 * Source form: the table byte is read into a local before the compare.
 */
extern const unsigned char input_source_code_table[];   /* four source codes: 0x61, 0x51, 0x81, 0x71 */

/*
 * Return the index (0..3) of `code` in input_source_code_table, or 0xFF when it is not in the table.
 */
unsigned char input_find_source_code_index(unsigned char code)
{
    unsigned char i;
    for (i = 0; i < 4; i++) {
        unsigned char entry = input_source_code_table[i];
        if (code == entry)
            return i;
    }
    return 0xff;
}
