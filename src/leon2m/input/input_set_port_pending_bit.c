/* input_set_port_pending_bit  (FUN_a012b39c)
 *
 * Set a port's pending bit, or clear it and mark the port as changed.
 * Name basis: descriptive - bit mask at 0xA802CAF8, change bytes at 0xA802CB00; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b39c @ 0xa012b39c, flags -mcpu=v8 -O3 -g.
 * Source form: the clear mask is computed into its own local before the array store.
 */
extern unsigned char input_port_pending_bits;       /* one bit per port */
extern unsigned char input_port_changed_flags[];    /* one byte per port */

/*
 * Set or clear the pending bit of a port.
 *
 *   port  port number
 *   on    non-zero: set bit `port` of input_port_pending_bits
 *         zero: clear that bit and set input_port_changed_flags[port] to 1
 */
void input_set_port_pending_bit(unsigned int port, unsigned char on)
{
    if (on)
        input_port_pending_bits |= 1 << port;
    else {
        unsigned char index = port;
        unsigned int mask = 1 << index;

        input_port_changed_flags[index] = 1;
        input_port_pending_bits &= ~mask;
    }
}
