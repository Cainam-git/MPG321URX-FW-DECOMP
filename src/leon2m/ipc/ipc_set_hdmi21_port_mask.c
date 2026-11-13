/* ipc_set_hdmi21_port_mask  (FUN_a0137b5c)
 *
 * Ask the input processor to apply a mask to the HDMI 2.1 port records.
 * Name basis: derived - command 0x16 through the mailbox portal 1 sender; mailbox command 0x16, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137b5c @ 0xa0137b5c, flags -mcpu=v8 -O3 -g.
 * Source form: as ipc_restart_hdmi_port, the switch writes the port number straight into msg[0]; no scheduling aid
 * is needed.
 */
#define IPC_CMD_SET_HDMI21_PORT_MASK 0x16       /* mailbox command 0x16 */
#define IPC_SEND_WAIT_TAKEN          1          /* ipc_send_command: wait until the input processor has taken the message */
#define PORT_HDMI21_0                2          /* input numbers inside commands: 2 and 3 are the HDMI 2.1 inputs */
#define PORT_HDMI21_1                3
#define PORT_NONE                    0xff       /* not an HDMI 2.1 input */
extern void ipc_send_command(int cmd, int len, unsigned char *buf, int flag);

/*
 * Ask the input processor to apply a mask to the records of the HDMI 2.1 receivers (mailbox command 0x16).
 *
 *   ch    0 = input 2, 1 = input 3; any other value is sent as PORT_NONE
 *   set   1 = set the mask bits of the receiver; with any other value, or with PORT_NONE, the input processor
 *         clears the mask bits on both receivers
 *   mask  the mask bits
 *
 * Called from input_channel_bring_up_task and sys_set_channel_port.
 */
void ipc_set_hdmi21_port_mask(unsigned char ch, unsigned char set, unsigned char mask)
{
    unsigned char msg[4] = { 0, 0, 0, 0 };

    switch (ch) {
    case 0: msg[0] = PORT_HDMI21_0; break;
    case 1: msg[0] = PORT_HDMI21_1; break;
    default: msg[0] = PORT_NONE; break;
    }
    msg[1] = set;
    msg[2] = mask;
    ipc_send_command(IPC_CMD_SET_HDMI21_PORT_MASK, 4, msg, IPC_SEND_WAIT_TAKEN);
}
