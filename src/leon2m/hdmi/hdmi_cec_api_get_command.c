/* hdmi_cec_api_get_command  (FUN_a0147790)
 *
 * Run the CEC receive step and return the received command 0..7.
 * Returns: command code
 * Name basis: derived - result of the CEC receive and reply dispatch; command 5 only counts with operand 0x40
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147790 @ 0xa0147790, flags -mcpu=v8 -O3 -g.
 * Source form: the switch has one case per command (jump table); case 5 sets the result and breaks on operand 0x40,
 * otherwise it falls through into the default arm.
 */
extern int hdmi_cec_receive_and_reply(void);
extern unsigned char hdmi_cec_get_operand(void);

/* Commands that hdmi_cec_receive_and_reply returns (see there). */
enum {
    CEC_CMD_NONE            = 0,
    CEC_CMD_FLAG0           = 1,
    CEC_CMD_MSG_36          = 2,
    CEC_CMD_ACTIVATE_SOURCE = 3,
    CEC_CMD_MSG_9D          = 4,
    CEC_CMD_MSG_44_OP40     = 5,
    CEC_CMD_VENDOR_ID       = 6,
    CEC_CMD_MSG_47          = 7
};

#define CEC_OPERAND_40 0x40     /* the operand with which command 5 is passed on */

/*
 * Run the receive step of the CEC link and return its command, 0 to 7. Command 5 (message 0x44) is returned only
 * when the stored operand is 0x40; with another operand the result is 0, as it is for any value above 7.
 * Called by sys_run_app_timer_task.
 */
int hdmi_cec_api_get_command(void)
{
    int command;

    switch (hdmi_cec_receive_and_reply()) {
    case CEC_CMD_NONE:
        command = CEC_CMD_NONE;
        break;
    case CEC_CMD_FLAG0:
        command = CEC_CMD_FLAG0;
        break;
    case CEC_CMD_MSG_36:
        command = CEC_CMD_MSG_36;
        break;
    case CEC_CMD_ACTIVATE_SOURCE:
        command = CEC_CMD_ACTIVATE_SOURCE;
        break;
    case CEC_CMD_MSG_9D:
        command = CEC_CMD_MSG_9D;
        break;
    case CEC_CMD_MSG_44_OP40:
        command = CEC_CMD_MSG_44_OP40;
        if (hdmi_cec_get_operand() == CEC_OPERAND_40)
            break;
    default:
        command = CEC_CMD_NONE;
        break;
    case CEC_CMD_VENDOR_ID:
        command = CEC_CMD_VENDOR_ID;
        break;
    case CEC_CMD_MSG_47:
        command = CEC_CMD_MSG_47;
        break;
    }
    return command;
}
