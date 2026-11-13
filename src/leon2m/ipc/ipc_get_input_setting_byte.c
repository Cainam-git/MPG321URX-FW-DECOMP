/* ipc_get_input_setting_byte  (FUN_a013923c)
 *
 * Ask the input processor to read a setting byte of an input.
 * Returns: reply byte
 * Name basis: derived - command 0xA1 through the mailbox portal 1 sender; mailbox command 0xA1, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013923c @ 0xa013923c-0xa01392d0 (37 words), flags -mcpu=v8 -O2 -g.
 * Source form: a switch, not an if-chain (the compiler builds a case tree rooted at 1).
 */
extern unsigned char ipc_reply_result_byte;
extern void ipc_send_command(int, int, unsigned char *, int);
extern void ipc_wait_reply(int);

#define IPC_CMD_GET_INPUT_SETTING_BYTE 0xa1        /* mailbox command 0xA1 */
#define IPC_SEND_NO_WAIT            0           /* do not wait for the reply slot */

/*
 * Read a setting byte of input 0 to 3 from the input processor with mailbox command 0xA1.
 *   mode  input number 0 to 3; it is sent as port number 2 to 5 (any other value sends port number 0)
 * Returns the first data byte of the reply: for an HDMI 2.1 input (ports 2 and 3) the first CVTEM field, 8 for a
 * DisplayPort input (ports 4 and 5).
 * The routine sends the command, waits for the reply and returns the reply byte (ipc_reply_result_byte).
 */
unsigned char ipc_get_input_setting_byte(unsigned char mode)
{
  unsigned char msg[4] = {0};

  switch (mode) {
  case 1: msg[0] = 3; break;
  case 2: msg[0] = 4; break;
  case 3: msg[0] = 5; break;
  case 0: msg[0] = 2; break;
  }
  ipc_send_command(IPC_CMD_GET_INPUT_SETTING_BYTE, 4, msg, IPC_SEND_NO_WAIT);
  ipc_wait_reply(1);
  return ipc_reply_result_byte;
}
