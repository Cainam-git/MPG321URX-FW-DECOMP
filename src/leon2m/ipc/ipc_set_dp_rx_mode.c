/* ipc_set_dp_rx_mode  (FUN_a0137a68)
 *
 * Ask the input processor to store the DisplayPort receiver mode bytes of a port.
 * Name basis: derived - command 0x21 through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); mailbox command 0x21, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137a68 @ 0xa0137a68, flags -mcpu=v8 -O3 -g.
 * Source form: the message is a zero-initialised 9-byte array; the byte stores come in the order below (byte 3
 * before bytes 1 and 2), which reproduces the firmware's schedule.
 */
#define IPC_CMD_SET_DP_RX_MODE 0x21     /* mailbox command 0x21 */
#define IPC_SEND_WAIT_TAKEN    1        /* ipc_send_command: wait until the input processor has taken the message */
extern void ipc_send_command(int, int, unsigned char *, int);

/*
 * Send the mode bytes of one DisplayPort receiver to the input processor (mailbox command 0x21). It stores them
 * as the first part of command 0x20 does (message bytes 0..3 and 8) and writes the receiver's registers again.
 *
 *   port  DP receiver (message byte 0)
 *   row   the port's link row; the bytes are taken from it as in ipc_set_dp_rx_config
 *
 * Called from input_set_port_link_field_first, _second, _third and input_set_port_link_flag_row7.
 */
void ipc_set_dp_rx_mode(unsigned char port, unsigned char *row)
{
    unsigned char msg[9] = {0};

    msg[0] = port;
    msg[3] = row[3] | row[4] << 1 | row[5] << 2 | row[6] << 3 | row[7] << 4;
    msg[1] = row[0];
    msg[2] = row[1];
    msg[8] = row[2];
    ipc_send_command(IPC_CMD_SET_DP_RX_MODE, 9, msg, IPC_SEND_WAIT_TAKEN);
}
