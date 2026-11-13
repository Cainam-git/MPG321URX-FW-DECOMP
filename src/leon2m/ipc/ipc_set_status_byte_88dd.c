/* ipc_set_status_byte_88dd  (FUN_a013777c)
 *
 * Ask the input processor to store a status byte.
 * Name basis: derived - through ipc_send_command; sent by the main-loop task; mailbox command 0x70, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013777c, flags -mcpu=v8 -O2 -g. ipc_send_command is declared without a prototype, as the firmware's own
 * calls need; the 'return 0' in a void routine is part of the original form.
 */
extern int ipc_send_command();

#define IPC_CMD_SET_EVENT_CLEAR_MASK  0x70  /* command number in the input program's dispatcher */
#define IPC_SEND_NO_WAIT              0     /* send and return at once */

/*
 * Send command 0x70 (IPC_CMD_SET_EVENT_CLEAR_MASK) with one data byte. The input program stores the byte as the event
 * bits that ipc_publish_port_status clears after it has published them (the byte is kept at 0xA80788DD).
 * Caller: sys_main_loop_periodic_task, which sends the low byte of the input processor's state word whenever it changes.
 *   status_byte: the data byte
 */
void ipc_set_status_byte_88dd(unsigned char status_byte)
{
    ipc_send_command(IPC_CMD_SET_EVENT_CLEAR_MASK, 1, &status_byte, IPC_SEND_NO_WAIT);
    return 0;
}
