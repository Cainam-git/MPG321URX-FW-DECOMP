/* ipc_get_hdmi21_status_byte  (FUN_a01391a8)
 *
 * Ask the input processor to read a status byte of an HDMI 2.1 input.
 * Returns: reply byte
 * Name basis: derived - command 0xA4 through the mailbox portal 1 sender; unused; mailbox command 0xA4, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01391a8 @ 0xa01391a8 (-mcpu=v8 -O2 -g).
 */
extern unsigned char ipc_reply_result_byte;
extern void ipc_send_command(int, int, unsigned char *, int);
extern void ipc_wait_reply(int);

#define IPC_CMD_GET_HDMI21_FRL_RATE 0xa4        /* mailbox command 0xA4 */
#define IPC_SEND_NO_WAIT            0           /* do not wait for the reply slot */

/*
 * Read a status byte of an HDMI 2.1 input from the input processor with mailbox command 0xA4.
 *   mode  input number 0 to 3; it is sent as port number 2 to 5 (any other value sends port number 0)
 * Returns the first data byte of the reply: a status byte the input processor keeps for port 2 (mode 0) or
 * port 3 (mode 1). Every other port number is answered with 0.
 * The routine sends the command, waits for the reply and returns the reply byte (ipc_reply_result_byte).
 */
unsigned char ipc_get_hdmi21_status_byte(unsigned char mode)
{
  unsigned char msg[4] = {0};

  switch (mode) {
  case 1: msg[0] = 3; break;
  case 2: msg[0] = 4; break;
  case 3: msg[0] = 5; break;
  case 0: msg[0] = 2; break;
  }
  ipc_send_command(IPC_CMD_GET_HDMI21_FRL_RATE, 4, msg, IPC_SEND_NO_WAIT);
  ipc_wait_reply(1);
  return ipc_reply_result_byte;
}
