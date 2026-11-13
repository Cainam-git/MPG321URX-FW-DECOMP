/* ipc_set_port_option_mask  (FUN_a01382e4)
 *
 * Ask the input processor to set the port option mask.
 * Name basis: derived - command 0x7E through the mailbox portal 1 sender; stSysConfig bytes +0x30..+0x32;
 *   called from start-up; mailbox command 0x7E, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01382e4 @ 0xa01382e4, flags -mcpu=v8 -O3 -g.
 * Source form: the three-element initialiser of the 4-byte array gives the firmware's clear of the word before
 * the byte stores.
 */
#define IPC_CMD_SET_PORT_OPTION_MASK 0x7e       /* mailbox command 0x7E */
#define IPC_SEND_NO_WAIT             0          /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();
extern unsigned char sys_config[];

/*
 * Send the three bytes +0x30..+0x32 of the system configuration record to the input processor (mailbox command
 * 0x7E). The input processor builds its port option mask from bits 0..2 of each of them.
 *
 * Called from startup_bring_up_system.
 */
void ipc_set_port_option_mask(void)
{
    unsigned char msg[4] = {sys_config[0x30], sys_config[0x31], sys_config[0x32]};
    ipc_send_command(IPC_CMD_SET_PORT_OPTION_MASK, 4, msg, IPC_SEND_NO_WAIT);
}
