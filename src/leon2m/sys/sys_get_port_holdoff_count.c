/* sys_get_port_holdoff_count  (FUN_a014e7bc)
 *
 * Return the hold-off counter of a port.
 * Returns: counter
 * Name basis: descriptive - getter for the per-port counter kept by sys_poll_port_flag5_holdoff; unused
 *
 * Matching notes
 * --------------
 * FUN_a014e7bc (leon2m 0xa014e7bc-0xa014e7d0, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: an unsigned char index (and 0xff) into an extern byte array.
 */
extern unsigned char sys_port_holdoff_counts[];

/*
 * Return the hold-off counter of a port (the counters are kept per port by sys_poll_port_flag5_holdoff).
 *
 * Nothing in the firmware calls it.
 */
unsigned char sys_get_port_holdoff_count(unsigned char port)
{
    return sys_port_holdoff_counts[port];
}
