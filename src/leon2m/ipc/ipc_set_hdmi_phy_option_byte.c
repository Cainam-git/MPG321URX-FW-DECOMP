/* ipc_set_hdmi_phy_option_byte  (FUN_a0137b1c)
 *
 * Ask the input processor to store an option byte of one HDMI receiver.
 * Name basis: derived - command 0x15 through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); unused; mailbox command 0x15, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137b1c @ 0xa0137b1c, flags -mcpu=v8 -O2 -g.
 * Source form: the message starts cleared; the test phy != 0xff is computed into a flag before the two byte
 * stores.
 */
#define IPC_CMD_SET_HDMI_PHY_OPTION_BYTE 0x15   /* mailbox command 0x15 */
#define IPC_SEND_WAIT_TAKEN              1      /* ipc_send_command: wait until the input processor has taken the message */
#define PHY_NONE                         0xff   /* no PHY: nothing is sent */
extern int ipc_send_command();

/*
 * Store an option byte in the record of one HDMI PHY in the input processor (mailbox command 0x15).
 *
 *   phy    PHY number; 0xff sends nothing
 *   value  the option byte
 *
 * No routine of the main program calls it.
 */
void ipc_set_hdmi_phy_option_byte(unsigned char phy, unsigned char value)
{
    unsigned char msg[4] = { 0 };
    int valid = phy != PHY_NONE;

    msg[0] = phy;
    msg[1] = value;
    if (valid)
        ipc_send_command(IPC_CMD_SET_HDMI_PHY_OPTION_BYTE, 4, msg, IPC_SEND_WAIT_TAKEN);
}
