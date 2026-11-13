/* sys_channel_derive_default_window  (FUN_a013bbb8)
 *
 * Derive the default window fields of a channel from its measured sizes.
 * Name basis: descriptive - halfwords +0x2E..+0x38 from +0x28, +0x2A, +0x10 and +0x18; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013bbb8 @ 0xa013bbb8-0xa013bc5c (41 words), flags -mcpu=v8 -O3 -g.
 * Exact form: the half_0x38 store is written out in both arms (GCC merges the tails).
 */
/* Channel record (0x78 bytes, table channel_records): only the halfwords used here are named. */
struct channel_record {
    unsigned char pad0[0x10];
    unsigned short half_0x10;
    unsigned char pad12[6];
    unsigned short position_height;             /* +0x18: position field 10 */
    unsigned char pad1a[0xe];
    unsigned short half_0x28, half_0x2a, half_0x2c, half_0x2e, half_0x30, half_0x32, half_0x34, half_0x36, half_0x38;
};
extern struct channel_record *sys_find_channel_by_port(unsigned char port);
extern unsigned char input_block_get_status_bit2(unsigned char port);

#define MARGIN_LIMIT 0x32                       /* largest distance used on either side of +0x28 and +0x2a */

/*
 * Set halfwords +0x2e..+0x38 of the channel record of port from halfwords +0x28, +0x2a, +0x10 and +0x18.
 *
 *   +0x2e = +0x28 - m and +0x30 = +0x28 + m, with m = +0x28 limited to 0x32
 *   +0x32 = +0x2a - n and +0x34 = +0x2a + n, with n = +0x2a limited to 0x32
 *   +0x36 = 0
 *   +0x38 = +0x10 - height - 3, using twice +0x10 when input_block_get_status_bit2(port) is not 0
 *
 * No routine calls it by name.
 */
void sys_channel_derive_default_window(unsigned char port)
{
    struct channel_record *record = sys_find_channel_by_port(port);
    unsigned short margin;

    margin = record->half_0x28;
    if (margin > MARGIN_LIMIT)
        margin = MARGIN_LIMIT;
    record->half_0x2e = record->half_0x28 - margin;
    record->half_0x30 = record->half_0x28 + margin;
    margin = record->half_0x2a;
    if (margin > MARGIN_LIMIT)
        margin = MARGIN_LIMIT;
    record->half_0x32 = record->half_0x2a - margin;
    record->half_0x34 = record->half_0x2a + margin;
    record->half_0x36 = 0;
    if (input_block_get_status_bit2(port))
        record->half_0x38 = record->half_0x10 * 2 - record->position_height - 3;
    else
        record->half_0x38 = record->half_0x10 - record->position_height - 3;
}
