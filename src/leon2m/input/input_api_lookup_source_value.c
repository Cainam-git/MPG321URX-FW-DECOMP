/* input_api_lookup_source_value  (FUN_a014468c)
 *
 * Return the value stored for a key in the five-entry table at 0x1A6DA3.
 * Returns: value or 0xFF
 * Name basis: descriptive - 3-byte entries {a, value, key}
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014468c @ 0xa014468c-0xa01446e0 (21 words), flags -mcpu=v8 -O3 -g.
 * Source form: keep the three-byte struct order (byte_0, value, key), the u8 loop counter with <= 4, and the array indexing of input_source_value_map; the named constants expand to 4 and 0xff.
 */
/* One entry of the input source table. The value field is returned when the key field matches. */
struct input_source_entry {
    unsigned char byte_0;           /* not read here */
    unsigned char value;
    unsigned char key;
};
extern const struct input_source_entry input_source_value_map[];

#define INPUT_SOURCE_MAP_LAST_INDEX 4  /* last index of the five-entry table */
#define INPUT_SOURCE_NOT_FOUND 0xff    /* returned when no key matches */

/*
 * Return the value stored for lookup_key in the five-entry input_source_value_map table.
 *
 * lookup_key is the key to search for. The entries are scanned in order; the first entry whose key field
 * equals lookup_key supplies the returned value field. If no entry matches, return INPUT_SOURCE_NOT_FOUND.
 *
 * Callers: audio_user_update_routing, audio_user_toggle_source. Other routines read the same table with other
 * byte roles (input_api_lookup_source_key, input_api_lookup_source_id_swapped).
 */
unsigned char input_api_lookup_source_value(unsigned char lookup_key)
{
    unsigned char i;

    for (i = 0; i <= INPUT_SOURCE_MAP_LAST_INDEX; i++)
        if (input_source_value_map[i].key == lookup_key)
            return input_source_value_map[i].value;
    return INPUT_SOURCE_NOT_FOUND;
}
