/* ipc_get_dp_rx_clock_value  (FUN_a01381f0)
 *
 * Ask the input processor to read the 24-bit clock value of a DisplayPort input.
 * Returns: reply value
 * Name basis: derived - command 0x7C through the mailbox portal 1 sender; unused; mailbox command 0x7C, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01381f0 @ 0xa01381f0, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a zero-initialised 4-byte array (the word is cleared, then one byte is stored); the
 * cases are a switch without a jump table; the result is a full word load.
 */
#define IPC_CMD_GET_DP_RX_REG3D0_VALUE 0x7c     /* mailbox command 0x7C */
#define IPC_SEND_NO_WAIT               0        /* ipc_send_command: do not wait for the input processor */
extern unsigned int ipc_reply_word1;
extern void ipc_send_command(int, int, unsigned char *, int);
extern void ipc_wait_reply(int);

/*
 * Ask the input processor for the 24-bit value of the registers 0x3D0..0x3D2 of a DisplayPort receiver (mailbox
 * command 0x7C) and return reply word 1 (reply bytes 0..2 hold the value, byte 3 is 0).
 *
 *   mode  0..3 selects input 2..5 (4 and 5 are the two DP inputs; the input processor answers 0 for 2 and 3);
 *         any other value leaves the input number 0
 *
 * No routine of the main program calls it.
 */
unsigned int ipc_get_dp_rx_clock_value(unsigned char mode)
{
  unsigned char msg[4] = {0};

  switch (mode) {
  case 1: msg[0] = 3; break;
  case 2: msg[0] = 4; break;
  case 3: msg[0] = 5; break;
  case 0: msg[0] = 2; break;
  }
  ipc_send_command(IPC_CMD_GET_DP_RX_REG3D0_VALUE, 4, msg, IPC_SEND_NO_WAIT);
  ipc_wait_reply(1);
  return ipc_reply_word1;
}
