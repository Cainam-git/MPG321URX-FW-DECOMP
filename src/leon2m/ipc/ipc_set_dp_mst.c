/* ipc_set_dp_mst  (FUN_a0137aec)
 *
 * Ask the input processor to switch DisplayPort multi-stream on or off for a port.
 * Name basis: derived - command 0x24 through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); mailbox command 0x24, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137aec @ 0xa0137aec, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters.
 */
#define IPC_CMD_SET_DP_MST  0x24        /* mailbox command 0x24 */
#define IPC_SEND_WAIT_TAKEN 1           /* ipc_send_command: wait until the input processor has taken the message */
extern int ipc_send_command();

/*
 * Switch DisplayPort multi-stream (MST) on or off for one receiver in the input processor (mailbox command 0x24).
 *
 *   port  DP receiver
 *   on    1 = MST on, 0 = off
 *
 * Called from input_set_port_link_byte3.
 */
void ipc_set_dp_mst(unsigned char port, unsigned char on)
{
    unsigned char msg[4] = {port, on};

    ipc_send_command(IPC_CMD_SET_DP_MST, 4, msg, IPC_SEND_WAIT_TAKEN);
}
