/* dp_mst_select_port  (FUN_a00dc264)
 *
 * Store the port that the MST service works on.
 * Name basis: descriptive - byte at 0xA8078832
 *
 * Matching notes
 * --------------
 * FUN_a00dc264 (leon2s 0xa00dc264-0xa00dc270, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_mst_message_state_port;
/*
 * Choose the DP port that the MST service works on: stores the port number in dp_mst_message_state_port, the
 * index of all per-port MST arrays. Called by input_poll_port_services (ports 0 and 1, before each
 * dp_mst_task), by dp_run_link_state, by ipc_dispatch_command and by ipc_publish_port_status.
 */
void dp_mst_select_port(unsigned char port)
{
    dp_mst_message_state_port = port;
}
