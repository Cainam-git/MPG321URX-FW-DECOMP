/* ipc_set_hdmi_tx_reg0d_bit2  (FUN_a013805c)
 *
 * Ask the input processor to set or clear a control bit of an HDMI output.
 * Name basis: derived - command 0x47 through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); unused; mailbox command 0x47, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013805c @ 0xa013805c, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters.
 */
#define IPC_CMD_SET_HDMI_TX_REG0D_BIT2 0x47     /* mailbox command 0x47 */
#define IPC_SEND_WAIT_TAKEN            1        /* ipc_send_command: wait until the input processor has taken the message */
extern int ipc_send_command();

/*
 * Ask the input processor to set or clear bit 2 of register 0x0D (bank 0) of one HDMI transmitter port
 * (mailbox command 0x47). A port above 1 is ignored there.
 *
 *   port  HDMI transmitter port
 *   on    non-zero sets the bit, 0 clears it
 *
 * No routine of the main program calls it.
 */
void ipc_set_hdmi_tx_reg0d_bit2(unsigned char port, unsigned char on)
{
    unsigned char msg[4] = {port, on};

    ipc_send_command(IPC_CMD_SET_HDMI_TX_REG0D_BIT2, 4, msg, IPC_SEND_WAIT_TAKEN);
}
