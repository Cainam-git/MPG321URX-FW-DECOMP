/* input_is_mode_id_listed  (FUN_a013b92c)
 *
 * Return whether a port's mode id is one of fourteen listed values.
 * Returns: 0 or 1
 * Name basis: descriptive - halfword +0x3C of the channel record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b92c @ 0xa013b92c, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the first two values are one || test that returns 1 directly; the other
 * twelve are separate ifs that jump to one shared "return 1" (an || chain becomes flag arithmetic, a final ==
 * test becomes a set-on-equal). The values are tested in the order written.
 */

/* The record of a channel, up to the field used here. */
struct channel_record_mode {
    unsigned char pad[0x3c];
    unsigned short mode_id;         /* +0x3C */
};
extern struct channel_record_mode *sys_find_channel_by_port(unsigned char port);

/*
 * Return 1 when the mode id (halfword +0x3C) of the channel record of a port is one of these fourteen values
 * (input_match_port_mode stores there the id, halfword +0x22, of the mode-table row it matched):
 * 0x5b01, 0x5c01, 0x5d01, 0x800, 0x5f01, 0x6001, 0x6101, 0x5800, 0x5900, 0x2200, 0x5700, 0x5a00, 0x6301, 0x6201.
 * Otherwise return 0.
 *
 * No routine calls this one directly; the image reaches it through a table.
 */
unsigned char input_is_mode_id_listed(unsigned char port)
{
    unsigned short mode_id = sys_find_channel_by_port(port)->mode_id;

    if (mode_id == 0x5b01 || mode_id == 0x5c01)
        return 1;
    if (mode_id == 0x5d01)
        goto yes;
    if (mode_id == 0x800)
        goto yes;
    if (mode_id == 0x5f01)
        goto yes;
    if (mode_id == 0x6001)
        goto yes;
    if (mode_id == 0x6101)
        goto yes;
    if (mode_id == 0x5800)
        goto yes;
    if (mode_id == 0x5900)
        goto yes;
    if (mode_id == 0x2200)
        goto yes;
    if (mode_id == 0x5700)
        goto yes;
    if (mode_id == 0x5a00)
        goto yes;
    if (mode_id == 0x6301)
        goto yes;
    if (mode_id == 0x6201)
        goto yes;
    return 0;
yes:
    return 1;
}
