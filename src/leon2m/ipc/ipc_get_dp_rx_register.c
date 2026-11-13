/* ipc_get_dp_rx_register  (FUN_a01384e4)
 *
 * Ask the input processor to read one DisplayPort receiver register.
 *   port: DP receiver
 *   reg: register number, one byte
 * Note: The register number is sent as one byte, and the input processor answers 0 for registers outside
 *   0x200..0x3FF, so every answer is 0.
 * Name basis: derived - command 0x22 through the mailbox portal 1 sender, then ipc_wait_reply; unused; mailbox
 *   command 0x22, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01384e4 @ 0xa01384e4, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters; the function returns void.
 */
#define IPC_CMD_GET_DP_RX_REGISTER 0x22         /* mailbox command 0x22 */
#define IPC_SEND_NO_WAIT           0            /* ipc_send_command: do not wait for the input processor */
extern void ipc_send_command();
extern int ipc_wait_reply();

/*
 * Ask the input processor to read a register of a DisplayPort receiver (mailbox command 0x22) and wait for the
 * reply. The routine returns nothing; the answer stays in the reply words (ipc_reply_words).
 *
 *   port  DP receiver
 *   reg   low byte of the register number; the input processor takes message bytes 1..2 as the register
 *         number, so here the high byte is 0, and it answers 0 for a register outside 0x200..0x3FF
 *
 * No routine of the main program calls it.
 */
void ipc_get_dp_rx_register(unsigned char port, unsigned char reg)
{
    unsigned char msg[4] = {port, reg};
    ipc_send_command(IPC_CMD_GET_DP_RX_REGISTER, 4, msg, IPC_SEND_NO_WAIT);
    ipc_wait_reply(1);
}
