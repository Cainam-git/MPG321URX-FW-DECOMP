/* ipc_set_dp_rx_capabilities  (FUN_a0137be8)
 *
 * Ask the input processor to store two mode bytes and rewrite the port's capability registers.
 * Name basis: derived - command 0x25 through the mailbox portal 1 sender; unused; mailbox command 0x25, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137be8 @ 0xa0137be8, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the three parameters.
 */
#define IPC_CMD_SET_DP_RX_CAPABILITIES 0x25     /* mailbox command 0x25 */
#define IPC_SEND_WAIT_TAKEN            1        /* ipc_send_command: wait until the input processor has taken the message */
extern int ipc_send_command();

/*
 * Send two mode bytes of one DisplayPort receiver to the input processor (mailbox command 0x25). It stores them
 * in the receiver's record (byte +0x117 and byte +0x110) and writes the receiver's capability registers
 * 0x200..0x203 and 0x266 again.
 *
 *   port       DP receiver
 *   byte_0x117 stored as byte +0x117 of the receiver's record
 *   byte_0x110 stored as byte +0x110
 *
 * No routine of the main program calls it.
 */
void ipc_set_dp_rx_capabilities(unsigned char port, unsigned char byte_0x117, unsigned char byte_0x110)
{
    unsigned char msg[4] = {port, byte_0x117, byte_0x110};

    ipc_send_command(IPC_CMD_SET_DP_RX_CAPABILITIES, 4, msg, IPC_SEND_WAIT_TAKEN);
}
