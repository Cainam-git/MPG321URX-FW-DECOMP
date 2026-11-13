/* ipc_load_dp_rx_clock_registers  (FUN_a0137c4c)
 *
 * Ask the input processor to clear a DisplayPort receiver bit and load its clock registers.
 * Name basis: derived - command 0x2B through the mailbox portal 1 sender; mailbox command 0x2B, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137c4c @ 0xa0137c4c, flags -mcpu=v8 -O3 -g.
 * Source form: a switch with a default (if/else forms give a different block layout); the message is a zeroed
 * 4-byte array (one word clear, not three byte clears); the port number is written into msg[0] and read back for
 * the test.
 */
#define IPC_CMD_CLEAR_DP_RX_REG3D0 0x2b         /* mailbox command 0x2B */
#define IPC_SEND_WAIT_TAKEN        1            /* ipc_send_command: wait until the input processor has taken the message */
#define DP_RX_NONE                 0xff         /* no DP receiver: nothing is sent */
extern void ipc_send_command(int, int, unsigned char *, int);

/*
 * Ask the input processor to clear bit 7 of register 0x223 of a DisplayPort receiver and to load its registers
 * 0x3D0..0x3D2 (mailbox command 0x2B).
 *
 *   mode  2 selects DP receiver 0, 3 selects DP receiver 1; any other value sends nothing
 *
 * Called from GlobalModeHandler.
 */
void ipc_load_dp_rx_clock_registers(int mode)
{
  unsigned char msg[4] = {0};

  switch (mode) {
  case 2: msg[0] = 0; break;
  case 3: msg[0] = 1; break;
  default: msg[0] = DP_RX_NONE; break;
  }
  if (msg[0] != DP_RX_NONE)
    ipc_send_command(IPC_CMD_CLEAR_DP_RX_REG3D0, 1, msg, IPC_SEND_WAIT_TAKEN);
}
