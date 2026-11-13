/* dp_mst_downstream_task  (FUN_a00dbe74)
 *
 * Fetch messages from the output and run the notification sequence when idle.
 * Name basis: derived - dp_mst_fetch_downstream_message by option bits, then dp_mst_notify_task
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dbe74 @ 0xa00dbe74-0xa00dbed4 (24 words, incl. the merged unreachable tail), flags -mcpu=v8 -Os -g.
 * dp_mst_message_state_rx_write_indexes is a second byte array indexed by the same port (firmware 'or 0x30' +
 * [base + port]). dp_mst_notify_task is a tail call.
 */
extern unsigned char dp_mst_message_state_rx_read_indexes[];
extern unsigned char dp_mst_message_state_rx_write_indexes[];
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_option_byte;
extern void dp_mst_fetch_downstream_message(void);
extern void dp_mst_notify_task(void);
#define OPTION_FETCH_BITS  0x30     /* bits of the option byte that switch the fetch on */

/*
 * Downstream part of the MST service, run for port 0 by dp_mst_task. When bit 4 or bit 5 of the option byte
 * (dp_mst_message_state_option_byte) is set, a message is fetched from the output with
 * dp_mst_fetch_downstream_message. When the receive ring of the current port is empty (read index = write
 * index), the notification sequence is stepped with dp_mst_notify_task.
 */
void dp_mst_downstream_task(void)
{
    if (dp_mst_message_state_option_byte & OPTION_FETCH_BITS)
        dp_mst_fetch_downstream_message();
    if (dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port] == dp_mst_message_state_rx_write_indexes[dp_mst_message_state_port])
        dp_mst_notify_task();
}
