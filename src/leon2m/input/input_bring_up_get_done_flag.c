/* input_bring_up_get_done_flag  (FUN_a00f1100)
 *
 * Return the bring-up done flag of ports 2 / 6 or ports 3 / 7; 0 for any other port.
 * Returns: flag byte
 * Note: Nothing calls it.
 * Name basis: derived - bytes 0xA802B746 (ports 2 and 6) and 0xA802B742 (ports 3 and 7), the done flags of
 *   input_bring_up_lock_port
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1100 @ 0xa00f1100, flags -mcpu=v8 -O3 -g.
 * Source form: one if / else-if chain with the four port numbers as separate arms.
 */

extern unsigned char input_bring_up_done_ports_2_6, input_bring_up_done_ports_3_7;

/*
 * Return the done flag of the port bring-up (input_bring_up_lock_port) for port 2, 3, 6 or 7; 0 for any
 * other port. Ports 2 and 6 share input_bring_up_done_ports_2_6 (0xA802B746), ports 3 and 7 share
 * input_bring_up_done_ports_3_7 (0xA802B742). No code calls this routine.
 */
unsigned char input_bring_up_get_done_flag(unsigned char port)
{
    unsigned char done = 0;
    if (port == 2)
        done = input_bring_up_done_ports_2_6;
    else if (port == 3)
        done = input_bring_up_done_ports_3_7;
    else if (port == 6)
        done = input_bring_up_done_ports_2_6;
    else if (port == 7)
        done = input_bring_up_done_ports_3_7;
    return done;
}
