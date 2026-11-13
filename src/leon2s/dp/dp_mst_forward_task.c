/* dp_mst_forward_task  (FUN_a00dbed4)
 *
 * Forward a waiting down request while the notify flag is set; otherwise discard the queued requests.
 * Name basis: derived - row indexes differ: dp_mst_forward_down_request when dp_mst_message_state_notify_flag
 *   is non-zero, else write index = read index
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dbed4 @ 0xa00dbed4 (-mcpu=v8 -Os -g)
 * Source form: the goto form gives the firmware's branch layout: be to the end on equality, bne to the call,
 * and the store in the delay slot of the branch to the end.
 */
extern unsigned char dp_mst_message_state_fwd_read_index;
extern unsigned char dp_mst_message_state_fwd_write_index;
extern unsigned char dp_mst_message_state_notify_flag;
extern int dp_mst_forward_down_request();
/*
 * Forward-ring part of the MST service, run for port 0 by dp_mst_task. Nothing happens when the forward ring
 * is empty (write index = read index). Otherwise, when dp_mst_message_state_notify_flag is non-zero, one entry
 * is sent on with dp_mst_forward_down_request; when it is zero, the write index is set to the read index.
 */
void dp_mst_forward_task(void)
{
  if (dp_mst_message_state_fwd_write_index == dp_mst_message_state_fwd_read_index) goto end;
  if (dp_mst_message_state_notify_flag != 0) goto call;
  dp_mst_message_state_fwd_write_index = dp_mst_message_state_fwd_read_index;
  goto end;
call:
  dp_mst_forward_down_request();
end:
  return;
}
