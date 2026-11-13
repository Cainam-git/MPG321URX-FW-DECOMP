/* input_api_lookup_source_id_swapped  (FUN_a01446e0)
 *
 * Return the source id stored for a setting value in the five-entry table, swapping ids 4 and 6.
 * Returns: source id, or 0 when no entry holds the value
 * Note: Ids 4 and 6 are exchanged when device option bit 25 is 1.
 * Name basis: descriptive - input_source_value_map {source id, setting value, key}: matches byte 1, returns
 *   byte 0; option bit 25 of the device settings; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01446e0 @ 0xa01446e0-0xa0144768 (34 words), flags -mcpu=v8 -O3 -g.
 * Source form: the five-entry search is one for loop with a single if body; the 4/6 swap is two if statements, not a switch.
 */
/* One entry of input_source_value_map: {source id, setting value, key} (ROM 0x1A6DA3). */
struct input_source_value_map_entry { unsigned char source_id, value, key; };   /* key is not read here */
extern const struct input_source_value_map_entry input_source_value_map[5];
extern unsigned char nvram_get_device_option_bit25(void);

#define NO_MATCH 0 /* returned when no entry holds the setting value */

/*
 * Look up a setting value in the five-entry input_source_value_map and return the source id of the first
 * entry that holds it.
 *
 * value is the setting value to search for. The table entries are {source id, setting value, key} triples
 * (ROM 0x1A6DA3); entries 0..4 are searched in order. No direct call to it was found in the image.
 *
 * When nvram_get_device_option_bit25() returns 1, a matched source id of 4 is returned as 6 and 6 as 4.
 * If no entry holds the value, NO_MATCH is returned.
 */
unsigned char input_api_lookup_source_id_swapped(unsigned char value)
{
    unsigned char i;
    unsigned char source_id;

    for (i = 0; i <= 4; i++) {
        if (input_source_value_map[i].value == value) {
            source_id = input_source_value_map[i].source_id;
            /* The device option bit 25 selects the 4/6 exchange. */
            if (nvram_get_device_option_bit25() == 1) {
                if (source_id == 4)
                    source_id = 6;
                else if (source_id == 6)
                    source_id = 4;
            }
            return source_id;
        }
    }
    return NO_MATCH;
}
