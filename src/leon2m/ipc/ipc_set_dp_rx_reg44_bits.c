/* ipc_set_dp_rx_reg44_bits  (FUN_a0137cac)
 *
 * Ask the input processor to write DisplayPort receiver register bits from a value.
 * Name basis: derived - command 0x2C through the mailbox portal 1 sender; mailbox command 0x2C, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137cac @ 0xa0137cac, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters.
 */
#define IPC_CMD_SET_DP_RX_REG44_BITS 0x2c       /* mailbox command 0x2C */
#define IPC_SEND_NO_WAIT             0          /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Ask the input processor to write bits 4..7 of register 0x44 of a DisplayPort receiver from a value
 * (mailbox command 0x2C). The input processor then also sets or clears bit 4 of register 0x40.
 *
 *   port   DP receiver
 *   value  only bits 4..7 are used
 *
 * Called from ipc_api_set_dp_rx_reg44_bits.
 */
void ipc_set_dp_rx_reg44_bits(unsigned char port, unsigned char value)
{
    unsigned char msg[4] = {port, value};

    ipc_send_command(IPC_CMD_SET_DP_RX_REG44_BITS, 4, msg, IPC_SEND_NO_WAIT);
}
