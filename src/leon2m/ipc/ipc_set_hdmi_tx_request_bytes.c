/* ipc_set_hdmi_tx_request_bytes  (FUN_a0137d98)
 *
 * Ask the input processor to store four HDMI output request bytes.
 * Name basis: derived - command 0x40 through the mailbox portal 1 sender; unused; mailbox command 0x40, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137d98 @ 0xa0137d98, flags -mcpu=v8 -O2 -g.
 * Source form: the five stores are in ascending message order; no other order gives the firmware's code. The
 * parameter port is an unsigned char stored without extension.
 */
#define IPC_CMD_SET_HDMI_TX_REQUEST_BYTES 0x40  /* mailbox command 0x40 */
#define IPC_SEND_NO_WAIT                  0     /* ipc_send_command: do not wait for the input processor */
extern void ipc_send_command(int, int, unsigned char *, int);

/*
 * Send four request bytes of one HDMI transmitter port to the input processor (mailbox command 0x40). The input
 * processor stores them as bytes +0x10..+0x13 of the port's request record and writes two of them to the
 * transmitter at once.
 *
 *   port   HDMI transmitter port
 *   bytes  the four request bytes
 *
 * No routine of the main program calls it.
 */
void ipc_set_hdmi_tx_request_bytes(unsigned char port, unsigned char *bytes)
{
  unsigned char msg[5];

  msg[0] = port;
  msg[1] = bytes[0];
  msg[2] = bytes[1];
  msg[3] = bytes[2];
  msg[4] = bytes[3];
  ipc_send_command(IPC_CMD_SET_HDMI_TX_REQUEST_BYTES, 5, msg, IPC_SEND_NO_WAIT);
}
