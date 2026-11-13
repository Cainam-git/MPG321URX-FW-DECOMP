/* input_api_lookup_source_key  (FUN_a0144768)
 *
 * Return the key stored for a value in the five-entry table at 0x1A6DA3.
 * Returns: key or 0
 * Name basis: descriptive - reverse of input_api_lookup_source_value; unused
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: the for loop is written without braces, its if body is a single return, and the final return 0 is outside the loop; the struct is three unsigned char fields in the shown order.
 */
struct input_source_value_map_entry {
    unsigned char byte_0;   /* not used by this routine */
    unsigned char value;
    unsigned char key;
};
extern const struct input_source_value_map_entry input_source_value_map[];

#define INPUT_SOURCE_VALUE_MAP_ENTRIES 5  /* the table has five entries */

/*
 * Return the key byte of the first entry in input_source_value_map whose value byte
 * equals source_value, or 0 when no entry matches.
 *
 * The table has five three-byte entries. The first byte of each entry is not used by
 * this routine. The companion routine input_api_lookup_source_value returns the value
 * byte for a key in the same table.
 */
unsigned char input_api_lookup_source_key(unsigned char source_value)
{
    unsigned char i;

    for (i = 0; i < INPUT_SOURCE_VALUE_MAP_ENTRIES; i++)
        if (input_source_value_map[i].value == source_value)
            return input_source_value_map[i].key;
    return 0;
}
