/* sys_channel_clamp_position  (FUN_a013bc5c)
 *
 * Limit the position fields of a channel to half and double of its sizes.
 * Name basis: descriptive - halfwords +0x0E, +0x1E and +0x20; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013bc5c @ 0xa013bc5c-0xa013bd00 (41 words), flags -mcpu=v8 -O3 -g.
 * Exact form: the unsigned doublings and halvings are written as shifts (<< 1, >> 1); written as * 2 and / 2 GCC
 * orders the operations differently.
 */
/* Channel record (0x78 bytes, table channel_records): only the halfwords used here are named. */
struct channel_record {
    unsigned char pad0[0xe];
    unsigned short half_0xe, half_0x10;
    unsigned char pad12[4];
    unsigned short position_width, position_height;     /* +0x16, +0x18: position fields 9 and 10 */
    unsigned char pad1a[4];
    unsigned short start_x, start_y;                    /* +0x1e, +0x20: position fields 12 and 16 */
};
extern struct channel_record *sys_find_channel_by_port(unsigned char port);

/*
 * Limit three halfwords of the channel record of port, with w = the position width (+0x16):
 *   +0xe above 2 * w         becomes w / 2 + w
 *   start_x above +0xe / 2   becomes (+0xe - w) / 2
 *   start_y above +0x10 / 2  becomes (+0x10 - position height) / 2
 * The differences are halved as signed ints. No routine calls it by name.
 */
void sys_channel_clamp_position(unsigned char port)
{
    struct channel_record *record = sys_find_channel_by_port(port);
    unsigned short w = record->position_width;

    if (record->half_0xe > (unsigned short)(w << 1))
        record->half_0xe = (w >> 1) + w;
    if (record->start_x > record->half_0xe >> 1)
        record->start_x = (record->half_0xe - w) / 2;
    if (record->start_y > record->half_0x10 >> 1)
        record->start_y = (record->half_0x10 - record->position_height) / 2;
}
