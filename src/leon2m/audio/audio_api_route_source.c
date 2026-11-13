/* audio_api_route_source  (FUN_a01478b0)
 *
 * Translate a setting through a table and route that sound source.
 * Name basis: derived - 3-byte table at 0x1A6DA3, then audio_unit_request_unit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01478b0 @ 0xa01478b0, flags -mcpu=v8 -O3 -g.
 * Source form: the lookup is a static helper inlined here. Cases 4..7 and the default all set the second argument to
 * 9 and give one jump-table target; the case blocks are laid out 3, 2, 1, 0 when case 7 has its own body and cases
 * 4, 5, 6 share theirs with the default.
 */
/* Entry of input_source_value_map (ROM, 3 bytes; FW.021: 01 00 04 / 0c 04 01 / 0e 03 00 / 06 09 03 / 04 08 02). */
struct source_value_entry { unsigned char id, value, key; };
extern const struct source_value_entry input_source_value_map[];
extern unsigned char nvram_get_device_option_bit25(void);
extern void audio_unit_request_unit(unsigned char, unsigned char);

#define SOURCE_VALUE_COUNT 5        /* entries in input_source_value_map */
#define ROUTE_ALL_UNITS 9           /* value of request_arg that stands for the six requests below */

/*
 * Find the entry of input_source_value_map whose value byte equals source_value and return its id byte; 0 when no
 * entry matches. With option bit 25 of the device settings set, the ids 4 and 6 swap places in the result.
 */
static unsigned char lookup_id(unsigned char source_value)
{
    unsigned char k, id;

    for (k = 0; k < SOURCE_VALUE_COUNT; k++) {
        if (input_source_value_map[k].value == source_value) {
            id = input_source_value_map[k].id;
            if (nvram_get_device_option_bit25() == 1) {
                if (id == 4)
                    id = 6;
                else if (id == 6)
                    id = 4;
            }
            return id;
        }
    }
    return 0;
}

/*
 * Route the sound source that belongs to a source setting: translate the setting to an id through the ROM table
 * and ask the audio unit code (audio_unit_request_unit) to give that id a unit.
 *
 *   source_value  the source setting to translate (lookup_id)
 *   select        picks the second argument of the request: 0 -> 0, 1 -> 6, 2 -> 7, 3 -> 8; any other value
 *                 (4..7 and above) makes the routine send the six requests 0, 6, 7, 4, 5, 8 in that order.
 *
 * The only caller passes the source setting of the user settings and select = 7, so it always sends the six requests.
 */
void audio_api_route_source(unsigned char source_value, unsigned char select)
{
    unsigned char id, request_arg;

    id = lookup_id(source_value);
    switch (select) {
    case 0: request_arg = 0; break;
    case 1: request_arg = 6; break;
    case 2: request_arg = 7; break;
    case 3: request_arg = 8; break;
    case 7: request_arg = ROUTE_ALL_UNITS; break;
    case 4: case 5: case 6: default: request_arg = ROUTE_ALL_UNITS; break;
    }
    if (request_arg == ROUTE_ALL_UNITS) {
        audio_unit_request_unit(id, 0);
        audio_unit_request_unit(id, 6);
        audio_unit_request_unit(id, 7);
        audio_unit_request_unit(id, 4);
        audio_unit_request_unit(id, 5);
        audio_unit_request_unit(id, 8);
    } else
        audio_unit_request_unit(id, request_arg);
}
