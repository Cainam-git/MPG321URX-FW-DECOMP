/* ipc_set_dp_tx_reg11_mode  (FUN_a0138110)
 *
 * Ask the input processor to set the mode register 0x11 of a DisplayPort output.
 * Name basis: derived - command 0x5F through the mailbox portal 1 sender; unused; mailbox command 0x5F, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138110 @ 0xa0138110, flags -mcpu=v8 -O2 -g.
 * Source form: the zero initialiser comes first and the byte stores are inside the branch (an initialiser
 * {output, mode} puts the store of mode before the test).
 */
#define IPC_CMD_SET_DP_TX_REG11_MODE 0x5f       /* mailbox command 0x5F */
#define IPC_SEND_NO_WAIT             0          /* ipc_send_command: do not wait for the input processor */
extern void ipc_send_command(int, int, void *, int);

/*
 * Ask the input processor to set the mode of register 0x11 of a DisplayPort output (mailbox command 0x5F). Only
 * output 0 is sent; for any other output nothing is sent.
 *
 *   output  DP output; only 0 is sent
 *   mode    non-zero writes 0x1B to register 0x11 (and 0x28 to register 0x66), 0 writes 0 to register 0x11
 *
 * No routine of the main program calls it.
 */
void ipc_set_dp_tx_reg11_mode(unsigned char output, unsigned char mode)
{
  unsigned char msg[4] = { 0 };

  if (output == 0) {
    msg[0] = output;
    msg[1] = mode;
    ipc_send_command(IPC_CMD_SET_DP_TX_REG11_MODE, 4, msg, IPC_SEND_NO_WAIT);
  }
}
