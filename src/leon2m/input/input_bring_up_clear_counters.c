/* input_bring_up_clear_counters  (FUN_a00f1150)
 *
 * Clear the bring-up counters of port pair 2/6 or 3/7.
 * Name basis: descriptive - halfwords at 0xA802B740..0xA802B746
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1150 @ 0xa00f1150, flags -mcpu=v8 -O3 -g.
 * Source form: one if / else-if chain with the four port numbers as separate arms.
 */

extern unsigned char input_bring_up_done_ports_2_6, input_bring_up_done_ports_3_7;
extern unsigned short input_bring_up_retry_count_ports_2_6, input_bring_up_retry_count_ports_3_7;

/*
 * Clear the done flag and the retry count that input_bring_up_lock_port keeps for port 2, 3, 6 or 7.
 * Ports 2 and 6 use the pair3 variables (0xA802B746 / 0xA802B744), ports 3 and 7 the pair2 variables
 * (0xA802B742 / 0xA802B740). Other ports are ignored. Called by input_channel_bring_up_task when it
 * selects a port.
 */
void input_bring_up_clear_counters(unsigned char port)
{
    if (port == 2) {
        input_bring_up_done_ports_2_6 = 0;
        input_bring_up_retry_count_ports_2_6 = 0;
    } else if (port == 3) {
        input_bring_up_done_ports_3_7 = 0;
        input_bring_up_retry_count_ports_3_7 = 0;
    } else if (port == 6) {
        input_bring_up_done_ports_2_6 = 0;
        input_bring_up_retry_count_ports_2_6 = 0;
    } else if (port == 7) {
        input_bring_up_done_ports_3_7 = 0;
        input_bring_up_retry_count_ports_3_7 = 0;
    }
}
