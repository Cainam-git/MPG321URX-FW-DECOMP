/* input_get_port_changed_flag  (FUN_a012b3f0)
 *
 * Return the changed flag of a port.
 * Returns: byte
 * Name basis: descriptive - byte table at 0xA802CB00; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b3f0 @ 0xa012b3f0, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char input_port_changed_flags[];    /* one byte per port */

/*
 * Return the changed flag of a port (set by input_set_port_pending_bit).
 */
unsigned char input_get_port_changed_flag(unsigned char port)
{
    return input_port_changed_flags[port];
}
