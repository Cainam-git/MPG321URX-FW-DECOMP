/* sys_channel_apply_scaler_route_for  (FUN_a013bdb8)
 *
 * Choose the scaling route of the port given as second parameter from its own size fields.
 * Name basis: descriptive - same steps as sys_channel_apply_scaler_route_auto with the port as second
 *   argument; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013bdb8 @ 0xa013bdb8-0xa013beb0 (62 words), flags -mcpu=v8 -O3 -g.
 * Exact form: the body is written out (not as an inlined static function) with the unequal case as the first if arm.
 */
/* Channel record (0x78 bytes, table channel_records): only the halfwords used here are named. */
struct channel_record {
    unsigned char pad0[0xe];
    unsigned short half_0xe, half_0x10, half_0x12, half_0x14;
    unsigned short position_width, position_height;     /* +0x16, +0x18: position fields 9 and 10 */
    unsigned char pad1a[2];
    unsigned short half_0x1c, half_0x1e, half_0x20;
};
extern struct channel_record *sys_find_channel_by_port(unsigned char port);
extern unsigned char input_is_port_code_scalable(unsigned char);
extern void input_block_disable_scaler(unsigned char);
extern void input_block_set_reg6_bit6(unsigned char);
extern void input_block_enable_scaler_ratio(unsigned char, unsigned short);

#define LARGE_AREA 0x1fff                       /* limit of ((+0x10 - +0x14) * +0xe) / 2 above which the ratio is written */

/*
 * Same as sys_channel_apply_scaler_route_auto, but the port is the second parameter; the first is not used.
 * No routine calls it by name.
 */
void sys_channel_apply_scaler_route_for(unsigned char unused, unsigned char port)
{
    struct channel_record *record = sys_find_channel_by_port(port);
    unsigned char large = 0;

    if ((unsigned int)((record->half_0x10 - record->half_0x14) * record->half_0xe) >> 1 > LARGE_AREA)
        large = 1;
    input_block_disable_scaler(port);
    record = sys_find_channel_by_port(port);
    if (record->half_0x12 != record->position_width || record->half_0x14 != record->position_height) {
        if (large) {
            if (record->half_0x1c <= record->half_0x20)
                input_block_enable_scaler_ratio(port, record->half_0x20 - record->half_0x1c);
            else
                input_block_enable_scaler_ratio(port, record->half_0x20);
        }
        input_block_set_reg6_bit6(port);
    } else {
        if (input_is_port_code_scalable(port) == 1)
            input_block_disable_scaler(port);
        else if (large)
            input_block_enable_scaler_ratio(port, 0);
    }
}
