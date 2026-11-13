/* ipc_set_dp_rx_option  (FUN_a0137c1c)
 *
 * Ask the input processor to store a DisplayPort receiver option byte and reprogram the port.
 * Name basis: derived - command 0x26 through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); unused; mailbox command 0x26, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137c1c @ 0xa0137c1c, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters.
 */
#define IPC_CMD_SET_DP_RX_SETTING_115 0x26      /* mailbox command 0x26 */
#define IPC_SEND_WAIT_TAKEN           1         /* ipc_send_command: wait until the input processor has taken the message */
extern int ipc_send_command();

/*
 * Store a byte in the record of one DisplayPort receiver (byte +0x115) in the input processor and have it
 * program the receiver again (mailbox command 0x26).
 *
 *   port   DP receiver (0 or 1)
 *   value  the byte to store
 *
 * No routine of the main program calls it.
 */
void ipc_set_dp_rx_option(unsigned char port, unsigned char value)
{
    unsigned char msg[4] = {port, value};

    ipc_send_command(IPC_CMD_SET_DP_RX_SETTING_115, 4, msg, IPC_SEND_WAIT_TAKEN);
}
