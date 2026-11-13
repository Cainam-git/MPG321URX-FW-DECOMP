/* ipc_set_dp_rx_lane_options  (FUN_a0137d08)
 *
 * Send three DisplayPort receiver option bytes and the lane and enable bits of a port.
 * Name basis: derived - command 0x2E through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); mailbox command 0x2E, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137d08 @ 0xa0137d08, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 5-byte array initialised with the five parameters.
 */
#define IPC_CMD_SET_DP_RX_LANE_OPTIONS 0x2e     /* mailbox command 0x2E */
#define IPC_SEND_WAIT_TAKEN            1        /* ipc_send_command: wait until the input processor has taken the message */
extern int ipc_send_command();

/*
 * Send three option bytes and the lane option of one DisplayPort receiver to the input processor (mailbox
 * command 0x2E). The input processor stores the three bytes in the receiver's record (bytes +0x118, +0x11A,
 * +0x11B), sets or clears the lane option bit and applies the bytes.
 *
 *   port         DP receiver
 *   byte_0x118   stored as byte +0x118
 *   byte_0x11a   stored as byte +0x11A
 *   byte_0x11b   stored as byte +0x11B
 *   lane_option  0 clears the lane option bit; any other value sets it
 *
 * Called from input_set_port_link_tail_bytes and input_init_port_link_row.
 */
void ipc_set_dp_rx_lane_options(unsigned char port, unsigned char byte_0x118, unsigned char byte_0x11a,
                  unsigned char byte_0x11b, unsigned char lane_option)
{
    unsigned char msg[5] = {port, byte_0x118, byte_0x11a, byte_0x11b, lane_option};

    ipc_send_command(IPC_CMD_SET_DP_RX_LANE_OPTIONS, 5, msg, IPC_SEND_WAIT_TAKEN);
}
