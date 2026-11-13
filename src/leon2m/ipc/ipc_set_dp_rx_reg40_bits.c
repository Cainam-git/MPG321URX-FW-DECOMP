/* ipc_set_dp_rx_reg40_bits  (FUN_a0137cdc)
 *
 * Ask the input processor to set bits 6-7 of DisplayPort receiver register 0x40 and run the follow-up.
 * Name basis: derived - command 0x28 through the mailbox portal 1 sender; mailbox command 0x28, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137cdc @ 0xa0137cdc, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the one parameter.
 */
#define IPC_CMD_SET_DP_RX_REG40_BITS 0x28       /* mailbox command 0x28 */
#define IPC_SEND_NO_WAIT             0          /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Ask the input processor to set bits 6 and 7 of register 0x40 of a DisplayPort receiver and then set bits 0
 * and 1 of register 0x44 (mailbox command 0x28).
 *
 *   port  DP receiver
 *
 * Called from ipc_api_set_dp_rx_reg40_bits.
 */
void ipc_set_dp_rx_reg40_bits(unsigned char port)
{
    unsigned char msg[4] = {port};

    ipc_send_command(IPC_CMD_SET_DP_RX_REG40_BITS, 4, msg, IPC_SEND_NO_WAIT);
}
