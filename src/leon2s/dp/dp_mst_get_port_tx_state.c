/* dp_mst_get_port_tx_state  (FUN_a00d9e44)
 *
 * Return the transmit state of the current port.
 * Returns: state
 * Name basis: descriptive - byte table at 0xA8078838
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d9e44 @ 0xa00d9e44 (-mcpu=v8 -Os -g)
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_tx_states[];

/*
 * Return the transmit state of the current port: 0 when idle, 2 while the chunks of a down reply are being sent,
 * 4 while the chunks of an up request are being sent (as set by dp_mst_send_down_reply_step and
 * dp_mst_send_up_message_step). Called by dp_mst_transmit_task.
 */
unsigned char dp_mst_get_port_tx_state(void)
{
  return dp_mst_message_state_tx_states[dp_mst_message_state_port];
}
