/* ipc_api_set_dp_rx_reg40_bits  (FUN_a012b404)
 *
 * Ask the input processor to set bits 6-7 of DisplayPort receiver register 0x40 and run the follow-up.
 * Name basis: derived - tail call; used by the bring-up state machine; mailbox command 0x28, whose handler in
 *   the input program shows the meaning
 *
 * Matching notes
 * --------------
 * FUN_a012b404 (leon2m 0xa012b404-0xa012b418, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: an unsigned char parameter passed on as a tail call; the nop after the call is the -g line nop.
 */
extern void ipc_set_dp_rx_reg40_bits(unsigned char);

/*
 * Forward to ipc_set_dp_rx_reg40_bits, which sends mailbox command 0x28 to the input processor.
 *   receiver: DisplayPort receiver number, as passed by input_channel_bring_up_task
 * Caller: input_channel_bring_up_task.
 */
void ipc_api_set_dp_rx_reg40_bits(unsigned char receiver)
{
    ipc_set_dp_rx_reg40_bits(receiver);
}
