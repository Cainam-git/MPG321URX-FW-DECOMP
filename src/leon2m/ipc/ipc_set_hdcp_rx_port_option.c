/* ipc_set_hdcp_rx_port_option  (FUN_a0137de0)
 *
 * Ask the input processor to set a copy-protection option of an input.
 * Name basis: derived - command 0x14 through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); unused; mailbox command 0x14, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137de0 @ 0xa0137de0, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters.
 */
#define IPC_CMD_SET_HDCP_RX_PORT_OPTION 0x14    /* mailbox command 0x14 */
#define IPC_SEND_WAIT_TAKEN             1       /* ipc_send_command: wait until the input processor has taken the message */
extern int ipc_send_command();

/*
 * Set an option of the protection block of an input in the input processor (mailbox command 0x14).
 *
 *   port  input number (0 and 1 HDMI 2.0, 2 and 3 HDMI 2.1)
 *   mode  1 writes the value 4 to the option register; any other value writes 0
 *
 * No routine of the main program calls it.
 */
void ipc_set_hdcp_rx_port_option(unsigned char port, unsigned char mode)
{
    unsigned char msg[4] = {port, mode};

    ipc_send_command(IPC_CMD_SET_HDCP_RX_PORT_OPTION, 4, msg, IPC_SEND_WAIT_TAKEN);
}
