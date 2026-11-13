/* ddc_api_queue_reply  (FUN_a01486a8)
 *
 * Queue the bytes of a DDC/CI reply for the 8051 to send.
 * Name basis: derived - forwards to ddc_queue_reply
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01486a8 @ 0xa01486a8 (-mcpu=v8 -O2 -g)
 * Forwards its three arguments (cmd, len, buffer) to ddc_queue_reply(cmd, len, buffer) as a tail call; len is
 * passed on as an unsigned short. Callers: ddc_handle_request, ddc_send_vcp_e6_reply, ddc_tool_dispatch_command, ddc_tool_answer_read_request.
 */
extern void ddc_queue_reply(unsigned char cmd, unsigned short len, unsigned char *p);

/*
 * Queue a DDC/CI reply for the 8051: hands cmd, len and buf on to ddc_queue_reply unchanged.
 * Callers: ddc_handle_request, ddc_send_vcp_e6_reply, ddc_tool_dispatch_command, ddc_tool_answer_read_request.
 */
void ddc_api_queue_reply(unsigned char cmd, unsigned short len, unsigned char *buf)
{
    ddc_queue_reply(cmd, len, buf);
}
