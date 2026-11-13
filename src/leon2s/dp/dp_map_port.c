/* dp_map_port  (FUN_a0083ed0)
 *
 * Map a DP port number to its receiver block, honouring the port swap.
 *   port
 * Returns: receiver block 0/1
 * Name basis: derived - returns a != 0 or a == 0 by the swap flag; used before every DP receiver register
 *   access
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083ed0 (0xa0083ed0-0xa0083f04, 13 words), flags -mcpu=v8 -Os -g.
 * Source form: u8 types. dp_get_port_swap takes no argument (the 'and %i0,0xff' in the call delay slot is
 * for the port). The comparison is written as two arms, which gives the cmp %g0 + addx / subx pair.
 */
extern unsigned char dp_get_port_swap(void);

/*
 * Map a DP port number to the number (0 or 1) of the receiver register set it uses.
 * Without the swap flag port 0 gives 1 and any other port gives 0; when dp_get_port_swap() is 1 it is the
 * other way round. Every DP receiver register access in this program goes through it.
 *   port: port number
 */
unsigned char dp_map_port(unsigned char port)
{
    unsigned char result;

    if (dp_get_port_swap() == 1)
        result = (port != 0);
    else
        result = (port == 0);
    return result & 1;
}
