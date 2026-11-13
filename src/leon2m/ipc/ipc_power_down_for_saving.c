/* ipc_power_down_for_saving  (FUN_a0138718)
 *
 * Ask the input processor to power the receivers down (mode 1) and stop the input processor.
 * Name basis: derived - command 0x72 through the mailbox portal 1 sender; called from SYSAPI_PowerSaving;
 *   mailbox command 0x72, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138718 @ 0xa0138718, flags -mcpu=v8 -O2 -g.
 * Source form: as ipc_power_down, with another command number.
 */
#define IPC_CMD_POWER_DOWN_FOR_SAVING 0x72      /* mailbox command 0x72 */
#define IPC_SEND_NO_WAIT              0         /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Tell the input processor to power its receivers down (receiver power-off mode 1) and stop (mailbox command
 * 0x72). Otherwise it does the same as command 0x73 (ipc_power_down), except for the print
 * '_SetLeonSPowerDown' that only 0x73 makes. The message is 12 zero bytes.
 *
 * Called from SYSAPI_PowerSaving.
 */
void ipc_power_down_for_saving(void)
{
    unsigned int msg[3] = {0, 0, 0};
    ipc_send_command(IPC_CMD_POWER_DOWN_FOR_SAVING, 0xc, msg, IPC_SEND_NO_WAIT);
}
