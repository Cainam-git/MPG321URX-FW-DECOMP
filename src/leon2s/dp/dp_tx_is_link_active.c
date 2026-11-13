/* dp_tx_is_link_active  (FUN_a0088ea0)
 *
 * Return whether an output is connected and its link is in the running state.
 *   output
 * Name basis: descriptive - dp_tx_is_connected and link state 4; published as status bit 7
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0088ea0 @ 0xa0088ea0 (-mcpu=v8 -Os -g)
 * Source form: the results of both calls are kept as unsigned ints and tested through '& 0xff'.
 */
extern int dp_tx_is_connected();
extern int dp_tx_get_ctl_state_code();

/*
 * Tell whether an output has a sink connected and its link is in the running state: dp_tx_is_connected
 * returns non-zero and dp_tx_get_ctl_state_code returns 4. Returns 1 then, otherwise 0.
 *   output: DP output
 * Called by ipc_publish_status_flags (output 0 becomes bit 7 of the status flags), by mailbox command 0x5C
 * of ipc_dispatch_command (output taken from the command).
 */
unsigned int dp_tx_is_link_active(unsigned char output)
{
    unsigned int connected;
    unsigned int active;

    connected = dp_tx_is_connected(output);
    active = 0;
    if ((connected & 0xff) != 0) {
        active = dp_tx_get_ctl_state_code(output & 0xff);
        active = (unsigned int)((active & 0xff) == 4);
    }
    return active;
}
