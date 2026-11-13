/* sys_channel_apply_scaler_route  (FUN_a013bd00)
 *
 * Choose the scaling route of a channel from its size fields.
 * Name basis: descriptive - three routines chosen by halfword compares and a flag; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013bd00 @ 0xa013bd00-0xa013bdb8 (46 words), flags -mcpu=v8 -O3 -g.
 * Exact form: the unequal case is the first if arm (it fixes the register choice in the equal case).
 */
/* Channel record (0x78 bytes, table channel_records): only the halfwords used here are named. */
struct channel_record {
    unsigned char pad0[0x12];
    unsigned short half_0x12, half_0x14;
    unsigned short position_width, position_height;     /* +0x16, +0x18: position fields 9 and 10 */
    unsigned char pad1a[2];
    unsigned short half_0x1c, half_0x1e, half_0x20;
};
extern struct channel_record *sys_find_channel_by_port(unsigned char port);
extern unsigned char input_is_port_code_scalable(unsigned char);
extern void input_block_disable_scaler(unsigned char);
extern void input_block_set_reg6_bit6(unsigned char);
extern void input_block_enable_scaler_ratio(unsigned char, unsigned short);

/*
 * Set up the scaler of the input block of port, depending on the channel record of port.
 *
 *   flag  non-zero: the scaler ratio is written as well
 *
 * When halfwords +0x12 and +0x14 differ from the position width and height (+0x16, +0x18): with flag set,
 * input_block_enable_scaler_ratio gets +0x20 - +0x1c (or +0x20 when +0x1c is the larger); then
 * input_block_set_reg6_bit6. When they are equal: input_block_disable_scaler if the port's signal code is
 * scalable (input_is_port_code_scalable returns 1), else the ratio 0 with flag set.
 * The second and third parameters are not used. No routine calls it by name.
 */
void sys_channel_apply_scaler_route(unsigned char port, int unused_a, int unused_b, unsigned char flag)
{
    struct channel_record *record = sys_find_channel_by_port(port);

    if (record->half_0x12 != record->position_width || record->half_0x14 != record->position_height) {
        if (flag) {
            if (record->half_0x1c <= record->half_0x20)
                input_block_enable_scaler_ratio(port, record->half_0x20 - record->half_0x1c);
            else
                input_block_enable_scaler_ratio(port, record->half_0x20);
        }
        input_block_set_reg6_bit6(port);
    } else {
        if (input_is_port_code_scalable(port) == 1)
            input_block_disable_scaler(port);
        else if (flag)
            input_block_enable_scaler_ratio(port, 0);
    }
}
