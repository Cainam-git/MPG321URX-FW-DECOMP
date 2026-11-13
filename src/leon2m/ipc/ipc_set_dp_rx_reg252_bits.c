/* ipc_set_dp_rx_reg252_bits  (FUN_a0138bc8)
 *
 * Ask the input processor to write bits 5-7 of DisplayPort receiver register 0x252.
 * Name basis: derived - command 0x86 through the mailbox portal 1 sender; mailbox command 0x86, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138bc8 @ 0xa0138bc8, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters.
 */
#define IPC_CMD_SET_DP_RX_REG252_BITS 0x86      /* mailbox command 0x86 */
#define IPC_SEND_NO_WAIT              0         /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Ask the input processor to write bits 5..7 of register 0x252 of a DisplayPort receiver (mailbox command 0x86).
 *
 *   port   DP receiver
 *   value  bits 0..2 become bits 5..7 of the register
 *
 * Called from ipc_api_set_dp_rx_reg252_bits.
 */
void ipc_set_dp_rx_reg252_bits(unsigned char port, unsigned char value)
{
    unsigned char msg[4] = {port, value};
    ipc_send_command(IPC_CMD_SET_DP_RX_REG252_BITS, 4, msg, IPC_SEND_NO_WAIT);
}
