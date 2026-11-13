/* dp_mst_task  (FUN_a00dc214)
 *
 * Run the MST message service once: receive, transmit and, for port 0, forwarding.
 * Name basis: descriptive - sequence of five calls; called from input_poll_port_services
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dc214 @ 0xa00dc214 (-mcpu=v8 -Os -g)
 * The result is the pending-chunk byte, widened to int. The two parameters of the decompiled form are unused.
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_pending_chunks;
extern int dp_mst_receive_task();
extern int dp_mst_transmit_task();
extern int dp_mst_downstream_task();
extern int dp_mst_forward_task();
extern int dp_mst_count_pending_chunks();
/*
 * One round of the MST message service for the current port: receive (dp_mst_receive_task), transmit
 * (dp_mst_transmit_task) and, for port 0 only, the forward ring (dp_mst_forward_task) and the downstream part
 * (dp_mst_downstream_task). Then the waiting entries are counted (dp_mst_count_pending_chunks) and the sum is
 * returned. Called by input_poll_port_services, once for port 0 and once for port 1 (after dp_mst_select_port).
 */
int dp_mst_task(void)
{
  dp_mst_receive_task();
  dp_mst_transmit_task();
  if (dp_mst_message_state_port == '\0') {
    dp_mst_forward_task();
    dp_mst_downstream_task();
  }
  dp_mst_count_pending_chunks();
  return dp_mst_message_state_pending_chunks;
}
