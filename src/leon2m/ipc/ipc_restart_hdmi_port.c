/* ipc_restart_hdmi_port  (FUN_a0137920)
 *
 * Ask the input processor to restart one of the two HDMI 2.1 inputs (channel 0 or 1).
 *   ch: 0 or 1 = HDMI 2.1 input 0 / 1; other values send nothing
 * Note: Channels 0 and 1 are sent as input numbers 2 and 3; any other channel sends nothing.
 * Name basis: derived - command 0x12 through the mailbox portal 1 sender with input number 2 or 3; its handler
 *   in the input program restarts the HDMI 2.1 receiver for those numbers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137920 @ 0xa0137920, flags -mcpu=v8 -O3 -g.
 * Source form: the switch writes the port number straight into msg[0] and the test reads msg[0] back; a separate
 * local for the port number does not give the firmware's order of instructions. The message is a zeroed 4-byte
 * array (one word clear). ch is an int.
 */
#define IPC_CMD_RESTART_HDMI_PORT 0x12  /* mailbox command 0x12 */
#define IPC_SEND_NO_WAIT          0     /* ipc_send_command: do not wait for the input processor */
#define PORT_HDMI21_0             2     /* input numbers inside commands: 2 and 3 are the HDMI 2.1 inputs */
#define PORT_HDMI21_1             3
#define PORT_NONE                 0xff  /* not an HDMI 2.1 input: nothing is sent */
extern void ipc_send_command(int cmd, int len, unsigned char *buf, int flag);

/*
 * Ask the input processor to restart one HDMI 2.1 input (mailbox command 0x12).
 *
 *   ch  0 restarts input 2, 1 restarts input 3; any other value sends nothing
 *
 * Called from input_power_on_ports_by_mask and GlobalModeHandler.
 */
void ipc_restart_hdmi_port(int ch)
{
    unsigned char msg[4] = { 0, 0, 0, 0 };

    switch (ch) {
    case 0: msg[0] = PORT_HDMI21_0; break;
    case 1: msg[0] = PORT_HDMI21_1; break;
    default: msg[0] = PORT_NONE; break;
    }
    if (msg[0] != PORT_NONE)
        ipc_send_command(IPC_CMD_RESTART_HDMI_PORT, 1, msg, IPC_SEND_NO_WAIT);
}
