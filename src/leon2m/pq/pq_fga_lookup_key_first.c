/* pq_fga_lookup_key_first  (FUN_a012cf1c)
 *
 * Return the value for a key from the first FGA key table.
 * Returns: the value of the matching pair; 0 when no key matches
 * Note: With no match it reads entry 11, the zero pair that follows the eleven pairs. Nothing calls it.
 * Name basis: descriptive - eleven halfword pairs at 0x1A5198 followed by a zero pair; no reference in the
 *   image
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012cf1c @ 0xa012cf1c-0xa012cf64 (72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the loop breaks on a match and the value is read with the loop counter afterwards.
 */
struct fga_key_entry { unsigned short key, value; };
extern const struct fga_key_entry pq_fga_key_table_first[];

#define FIRST_TABLE_ENTRIES 11      /* entries 0..10 are searched (FGA_FIRST_KEY_LAST_ROW 10 in pq_fga_handle_command) */

/*
 * Return the value of the entry of pq_fga_key_table_first whose key equals 'key'. When none of entries
 * 0..10 matches, the value of entry 11 is returned.
 *
 * Nothing in the firmware refers to this routine (no call and no stored address).
 */
unsigned short pq_fga_lookup_key_first(unsigned char key)
{
    unsigned char i;

    for (i = 0; i < FIRST_TABLE_ENTRIES; i++)
        if (key == pq_fga_key_table_first[i].key)
            break;
    return pq_fga_key_table_first[i].value;
}
