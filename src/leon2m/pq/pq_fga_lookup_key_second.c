/* pq_fga_lookup_key_second  (FUN_a012cf64)
 *
 * Return the value for a key from the second FGA key table.
 * Returns: the value of the matching pair; 1 when no key matches
 * Note: With no match it reads entry 12, which is the first pair of pq_fga_key_table_first (value 1). Nothing
 *   calls it.
 * Name basis: descriptive - twelve halfword pairs at 0x1A5168, directly followed by pq_fga_key_table_first; no
 *   reference in the image
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012cf64 @ 0xa012cf64-0xa012cfac (72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the loop breaks on a match and the value is read with the loop counter afterwards.
 */
struct fga_key_entry { unsigned short key, value; };
extern const struct fga_key_entry pq_fga_key_table_second[];

#define SECOND_TABLE_ENTRIES 12     /* entries 0..11 are searched (FGA_SECOND_KEY_LAST_ROW 11 in pq_fga_handle_command) */

/*
 * Return the value of the entry of pq_fga_key_table_second whose key equals 'key'. When none of entries
 * 0..11 matches, the value of entry 12 is returned.
 *
 * Nothing in the firmware refers to this routine (no call and no stored address).
 */
unsigned short pq_fga_lookup_key_second(unsigned char key)
{
    unsigned char i;

    for (i = 0; i < SECOND_TABLE_ENTRIES; i++)
        if (key == pq_fga_key_table_second[i].key)
            break;
    return pq_fga_key_table_second[i].value;
}
