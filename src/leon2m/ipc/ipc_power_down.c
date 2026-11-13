/* ipc_power_down  (FUN_a01386e4)
 *
 * Ask the input processor to power the receivers down (mode 0) and stop the input processor.
 * Name basis: derived - command 0x73 through the mailbox portal 1 sender; called from SYSAPI_PowerOff; mailbox
 *   command 0x73, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01386e4 @ 0xa01386e4, flags -mcpu=v8 -O2 -g.
 * Source form: the message is 12 zero bytes (a 64-bit store for the first 8 bytes and a word store for the last
 * 4); the routine takes no arguments.
 */
#define IPC_CMD_POWER_DOWN 0x73                 /* mailbox command 0x73 */
#define IPC_SEND_NO_WAIT   0                    /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Tell the input processor to power its receivers down (receiver power-off mode 0) and stop (mailbox command
 * 0x73). The input processor sets its DisplayPort output 0 sink to power save, reports its status flags and then
 * stops in an endless loop. The message is 12 zero bytes.
 *
 * Called from SYSAPI_PowerOff.
 */
void ipc_power_down(void)
{
    unsigned int msg[3] = {0, 0, 0};
    ipc_send_command(IPC_CMD_POWER_DOWN, 0xc, msg, IPC_SEND_NO_WAIT);
}
