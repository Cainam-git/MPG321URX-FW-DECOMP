/* dp_set_port_flag_bit  (FUN_a00ab884)
 *
 * Set or clear one bit of the DP port flag byte.
 *   port: bit
 *   set: 1 = set
 * Name basis: descriptive - flag byte 0xA8079314; caller dp_reset_port
 *
 * Matching notes
 * --------------
 * FUN_a00ab884 (leon2s), flags -mcpu=v8 -Os -g. Leaf.
 * Source form: both parameters are unsigned char; the bit expression 1 << bit is written in each arm (a shared mask
 * local is computed in another order).
 */
extern unsigned char dp_port_flag_bits;         /* one bit per DP port */

/*
 * Set or clear the bit of one port in dp_port_flag_bits.
 * dp_reset_port clears the bit; dp_unit_restart tests it.
 *   port: bit number (the DP port)
 *   set: non-zero sets the bit, 0 clears it
 */
void dp_set_port_flag_bit(unsigned char port, unsigned char set)
{
    if (set)
        dp_port_flag_bits |= 1 << port;
    else
        dp_port_flag_bits &= ~(1 << port);
}
