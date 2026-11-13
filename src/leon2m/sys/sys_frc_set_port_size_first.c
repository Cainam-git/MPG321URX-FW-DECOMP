/* sys_frc_set_port_size_first  (FUN_a0109148)
 *
 * Write a size pair of a converter port (first register pair).
 * Name basis: descriptive - pairs at 0xCF011B00; used by the channel window size
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109148 @ 0xa0109148, flags -mcpu=v8 -O3 -g.
 * Source form: a switch over port (compare tree); register addresses as pointer constants, as in sys_frc_derive_output_sizes.
 */
#define REG(a) ((volatile unsigned int *)(a))
extern void reg_write16_bytes(volatile unsigned int *r, unsigned int v);

/*
 * Write two 16-bit values to the register pairs of converter port `port` (0 to 3; other values write nothing).
 * `value_a` goes to the first register of each pair, `value_b` to the second. Port 0 has one pair
 * (0xCF011B00, 0xCF011B10); ports 1 to 3 have two pairs, the second 0x60 above the first:
 *
 *   port 1   0xCF011B20, 0xCF011B30  and  0xCF011B80, 0xCF011B90
 *   port 2   0xCF011B40, 0xCF011B50  and  0xCF011BA0, 0xCF011BB0
 *   port 3   0xCF011B60, 0xCF011B70  and  0xCF011BC0, 0xCF011BD0
 *
 * reg_write16_bytes stores one 16-bit value in two byte registers.
 * Called by sys_set_channel_window_size (sys_set_channel_window_size); sys_frc_set_port_size_second does the same for the pairs
 * eight bytes above these.
 */
void sys_frc_set_port_size_first(unsigned char port, unsigned short value_a, unsigned short value_b)
{
    switch (port) {
    case 0:
        reg_write16_bytes(REG(0xcf011b00), value_a);
        reg_write16_bytes(REG(0xcf011b10), value_b);
        break;
    case 1:
        reg_write16_bytes(REG(0xcf011b20), value_a);
        reg_write16_bytes(REG(0xcf011b30), value_b);
        reg_write16_bytes(REG(0xcf011b80), value_a);
        reg_write16_bytes(REG(0xcf011b90), value_b);
        break;
    case 2:
        reg_write16_bytes(REG(0xcf011b40), value_a);
        reg_write16_bytes(REG(0xcf011b50), value_b);
        reg_write16_bytes(REG(0xcf011ba0), value_a);
        reg_write16_bytes(REG(0xcf011bb0), value_b);
        break;
    case 3:
        reg_write16_bytes(REG(0xcf011b60), value_a);
        reg_write16_bytes(REG(0xcf011b70), value_b);
        reg_write16_bytes(REG(0xcf011bc0), value_a);
        reg_write16_bytes(REG(0xcf011bd0), value_b);
        break;
    }
}
