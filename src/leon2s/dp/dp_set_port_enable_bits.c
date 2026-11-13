/* dp_set_port_enable_bits  (FUN_a0083f04)
 *
 * Set or clear the four enable bits of a DP receiver.
 *   port
 *   enable: 1 = enable
 * Name basis: descriptive - registers 0x490 (bits 0/1), 0x434, 0x433 of the DP block; callers receiver power-
 *   off and port start
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083f04 (0xa0083f04-0xa0083fb8, 180 bytes), flags -mcpu=v8 -Os -g.
 * Source form: each arm of the enable test makes all four calls; the last call is a tail call.
 */
extern unsigned char dp_map_port(unsigned char a);
extern void dp_paged_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Set (enable) or clear (disable) four bits of a DP receiver: bit 0 of register 0x490, bit 0 of 0x434,
 * bit 4 of 0x433 and bit 1 of 0x490. Enabling sets the first and clears the other three; disabling does the
 * opposite.
 *   port:   DP port, mapped to its receiver by dp_map_port
 *   enable: 1 = enable
 */
void dp_set_port_enable_bits(unsigned char port, unsigned char enable)
{
    unsigned char block = dp_map_port(port);

    if (enable) {
        dp_paged_reg_update_bits(block, 0x490, 1, 1);
        dp_paged_reg_update_bits(block, 0x434, 1, 0);
        dp_paged_reg_update_bits(block, 0x433, 0x10, 0);
        dp_paged_reg_update_bits(block, 0x490, 2, 0);
    } else {
        dp_paged_reg_update_bits(block, 0x490, 1, 0);
        dp_paged_reg_update_bits(block, 0x434, 1, 1);
        dp_paged_reg_update_bits(block, 0x433, 0x10, 1);
        dp_paged_reg_update_bits(block, 0x490, 2, 1);
    }
}
