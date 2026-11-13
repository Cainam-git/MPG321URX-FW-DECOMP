/* ipc_set_dp_rx_config  (FUN_a013797c)
 *
 * Send the full DisplayPort receiver configuration of a port to the input processor.
 * Name basis: derived - command 0x20 through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); mailbox command 0x20, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013797c @ 0xa013797c, flags -mcpu=v8 -O3 -g.
 * Source form: the byte statements are in the order below; it is the order that reproduces the firmware's
 * schedule. The message is a zero-initialised 9-byte array.
 */
#define IPC_CMD_SET_DP_RX_CONFIG 0x20   /* mailbox command 0x20 */
#define IPC_SEND_WAIT_TAKEN      1      /* ipc_send_command: wait until the input processor has taken the message */
extern void ipc_send_command(int, int, unsigned char *, int);

/*
 * Send the whole configuration of one DisplayPort receiver to the input processor (mailbox command 0x20). The
 * input processor stores it in the receiver's record and sets the receiver up again.
 *
 *   port  DP receiver (message byte 0)
 *   row   the port's link row; the message bytes are taken from it as listed in the code
 *
 * Called from dp_set_port_dsc_support and input_init_port_link_row.
 */
void ipc_set_dp_rx_config(unsigned char port, unsigned char *row)
{
    unsigned char msg[9] = {0};

    msg[0] = port;
    msg[1] = row[0];
    msg[2] = row[1];
    /* Byte 3: row[3..7], one bit each (bit 0..4). */
    msg[3] = row[3] | row[4] << 1 | row[5] << 2 | row[6] << 3 | row[7] << 4;
    /* Byte 5: row[9], then row[0xb..0x10] at bits 2..7 (bit 1 is not used). */
    msg[5] = row[9] | row[0xb] << 2 | row[0xc] << 3 | row[0xd] << 4 | row[0xe] << 5 | row[0xf] << 6 | row[0x10] << 7;
    msg[4] = row[8];
    /* Bytes 6 and 7: the halfword at row + 0x12, low byte first. */
    msg[6] = *(unsigned short *)(row + 0x12);
    msg[7] = *(unsigned short *)(row + 0x12) >> 8;
    msg[8] = row[2];
    ipc_send_command(IPC_CMD_SET_DP_RX_CONFIG, 9, msg, IPC_SEND_WAIT_TAKEN);
}
