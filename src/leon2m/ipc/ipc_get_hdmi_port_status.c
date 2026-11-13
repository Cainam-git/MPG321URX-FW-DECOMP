/* ipc_get_hdmi_port_status  (FUN_a01384ac)
 *
 * Ask the input processor to read a status bit of an HDMI port.
 * Name basis: derived - command 0x83 through the mailbox portal 1 sender; unused; mailbox command 0x83, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01384ac @ 0xa01384ac, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters; the function returns void.
 */
#define IPC_CMD_GET_HDMI_PORT_STATUS 0x83       /* mailbox command 0x83 */
#define IPC_SEND_NO_WAIT             0          /* ipc_send_command: do not wait for the input processor */
extern void ipc_send_command();
extern int ipc_wait_reply();

/*
 * Ask the input processor for a status of an HDMI input (mailbox command 0x83) and wait for the reply. The
 * routine returns nothing; the answer stays in the reply words (ipc_reply_words). With what = 0 the first reply
 * byte is a status bit of the input (0 or 1); with what = 1 the reply is all zeros.
 *
 *   input  HDMI input 0..3
 *   what   0 or 1
 *
 * No routine of the main program calls it.
 */
void ipc_get_hdmi_port_status(unsigned char input, unsigned char what)
{
    unsigned char msg[4] = {input, what};
    ipc_send_command(IPC_CMD_GET_HDMI_PORT_STATUS, 4, msg, IPC_SEND_NO_WAIT);
    ipc_wait_reply(1);
}
