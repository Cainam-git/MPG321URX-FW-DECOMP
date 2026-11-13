/* ipc_apply_port_enable_mask  (FUN_a01382b0)
 *
 * Ask the input processor to apply the port enable mask.
 * Name basis: derived - command 0x7F through the mailbox portal 1 sender; called from System_Initialize;
 *   mailbox command 0x7F, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01382b0 @ 0xa01382b0, flags -mcpu=v8 -O3 -g.
 * Source form: the message is zero-initialised and 0x3C is then ORed into byte 0.
 */
#define IPC_CMD_APPLY_PORT_ENABLE_MASK 0x7f     /* mailbox command 0x7F */
#define IPC_SEND_NO_WAIT               0        /* ipc_send_command: do not wait for the input processor */
#define PORT_ENABLE_MASK               0x3c     /* bit n = port record n: records 2..5 */
extern int ipc_send_command();

/*
 * Tell the input processor which ports to enable (mailbox command 0x7F). Bit n of the mask is port record n.
 * The mask 0x3C enables records 2..5 (the two HDMI 2.1 inputs and the two DisplayPort inputs); the input
 * processor puts every other record into the power-off state.
 *
 * Called from System_Initialize.
 */
void ipc_apply_port_enable_mask(void)
{
    unsigned char msg[4] = {0};
    msg[0] |= PORT_ENABLE_MASK;
    ipc_send_command(IPC_CMD_APPLY_PORT_ENABLE_MASK, 4, msg, IPC_SEND_NO_WAIT);
}
