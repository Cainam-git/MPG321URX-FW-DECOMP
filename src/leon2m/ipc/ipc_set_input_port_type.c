/* ipc_set_input_port_type  (FUN_a0137864)
 *
 * Ask the input processor to set the type of one input port.
 * Name basis: derived - first byte 2 + item; through ipc_send_command; mailbox command 0x02, whose handler in
 *   the input program shows the meaning
 *
 * Matching notes
 * --------------
 * FUN_a0137864, flags -mcpu=v8 -O2 -g. Source form: an initialised local array {0} filled by a switch.
 */
extern void ipc_send_command(unsigned int cmd, unsigned char len, unsigned char *p, unsigned char wait);

#define IPC_CMD_SET_PORT_TYPE  0x02 /* command number in the input program's dispatcher */
#define IPC_SEND_NO_WAIT       0    /* send and return at once */

/* Input numbers of the input program (the port argument of command 0x02). */
#define INPUT_HDMI21_0  2
#define INPUT_HDMI21_1  3
#define INPUT_DP_0      4
#define INPUT_DP_1      5

/*
 * Send command 0x02 (IPC_CMD_SET_PORT_TYPE): the input program sets the type of one input port. Data byte 0 is the
 * input number, data byte 1 the type. Caller: input_resend_link_bytes_on_pin_change.
 *   input_index: 0..3 for INPUT_HDMI21_0, INPUT_HDMI21_1, INPUT_DP_0, INPUT_DP_1; any other value sends input
 *                number 0
 *   type:        the port type, data byte 1
 */
void ipc_set_input_port_type(unsigned char input_index, unsigned char type)
{
    unsigned char data[4] = { 0 };

    switch (input_index) {
    case 0:
        data[0] = INPUT_HDMI21_0;
        break;
    case 1:
        data[0] = INPUT_HDMI21_1;
        break;
    case 2:
        data[0] = INPUT_DP_0;
        break;
    case 3:
        data[0] = INPUT_DP_1;
        break;
    }
    data[1] = type;
    ipc_send_command(IPC_CMD_SET_PORT_TYPE, 2, data, IPC_SEND_NO_WAIT);
}
