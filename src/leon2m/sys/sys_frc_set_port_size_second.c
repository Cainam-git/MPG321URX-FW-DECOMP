/* sys_frc_set_port_size_second  (FUN_a0109278)
 *
 * Write a size pair of a converter port (second register pair).
 * Name basis: descriptive - pairs at 0xCF011B08; used by the channel window size
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109278 @ 0xa0109278, flags -mcpu=v8 -O3 -g.
 * Source form: a switch over port (compare tree); register addresses as pointer constants, as in sys_frc_derive_output_sizes.
 */
#define REG(a) ((volatile unsigned int *)(a))
extern void reg_write16_bytes(volatile unsigned int *r, unsigned int v);

/*
 * Write two 16-bit values to the second register pairs of converter port `port` (0 to 3; other values write
 * nothing). `value_a` goes to the first register of each pair, `value_b` to the second. Port 0 has one pair
 * (0xCF011B08, 0xCF011B18); ports 1 to 3 have two pairs, the second 0x60 above the first:
 *
 *   port 1   0xCF011B28, 0xCF011B38  and  0xCF011B88, 0xCF011B98
 *   port 2   0xCF011B48, 0xCF011B58  and  0xCF011BA8, 0xCF011BB8
 *   port 3   0xCF011B68, 0xCF011B78  and  0xCF011BC8, 0xCF011BD8
 *
 * Each address is 8 above the one sys_frc_set_port_size_first writes. Called by sys_set_channel_window_size
 * (sys_set_channel_window_size).
 */
void sys_frc_set_port_size_second(unsigned char port, unsigned short value_a, unsigned short value_b)
{
    switch (port) {
    case 0:
        reg_write16_bytes(REG(0xcf011b08), value_a);
        reg_write16_bytes(REG(0xcf011b18), value_b);
        break;
    case 1:
        reg_write16_bytes(REG(0xcf011b28), value_a);
        reg_write16_bytes(REG(0xcf011b38), value_b);
        reg_write16_bytes(REG(0xcf011b88), value_a);
        reg_write16_bytes(REG(0xcf011b98), value_b);
        break;
    case 2:
        reg_write16_bytes(REG(0xcf011b48), value_a);
        reg_write16_bytes(REG(0xcf011b58), value_b);
        reg_write16_bytes(REG(0xcf011ba8), value_a);
        reg_write16_bytes(REG(0xcf011bb8), value_b);
        break;
    case 3:
        reg_write16_bytes(REG(0xcf011b68), value_a);
        reg_write16_bytes(REG(0xcf011b78), value_b);
        reg_write16_bytes(REG(0xcf011bc8), value_a);
        reg_write16_bytes(REG(0xcf011bd8), value_b);
        break;
    }
}
