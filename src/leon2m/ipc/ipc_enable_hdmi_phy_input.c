/* ipc_enable_hdmi_phy_input  (FUN_a01378f0)
 *
 * Ask the input processor to enable or disable the input of one HDMI receiver.
 * Name basis: derived - through ipc_send_command; unused; mailbox command 0x11, whose handler in the input
 *   program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01378f0 @ 0xa01378f0, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters; only 2 bytes are sent.
 */
#define IPC_CMD_ENABLE_HDMI_PHY_INPUT 0x11      /* mailbox command 0x11 */
#define IPC_SEND_NO_WAIT              0         /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Enable or disable the input of one HDMI PHY in the input processor (mailbox command 0x11).
 *
 *   phy     PHY number
 *   enable  1 enables the input; any other value disables it
 *
 * No routine of the main program calls it.
 */
void ipc_enable_hdmi_phy_input(unsigned char phy, unsigned char enable)
{
    unsigned char msg[4] = {phy, enable};

    ipc_send_command(IPC_CMD_ENABLE_HDMI_PHY_INPUT, 2, msg, IPC_SEND_NO_WAIT);
}
