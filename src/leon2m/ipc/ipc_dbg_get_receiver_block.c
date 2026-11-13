/* ipc_dbg_get_receiver_block  (FUN_a013782c)
 *
 * Ask the input processor to read 28 bytes of a receiver block (debug).
 * Name basis: derived - through ipc_send_command; unused; mailbox command 0xF3, whose handler in the input
 *   program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013782c, flags -mcpu=v8 -O2 -g. Both callees are declared without a full prototype, as the firmware's
 * own calls need; their results are dropped. The data bytes are an initialised 4-byte array {receiver, type}.
 */
extern void ipc_send_command();
extern int ipc_wait_reply();

#define IPC_CMD_READ_INFOFRAME  0xf3    /* command number in the input program's dispatcher */
#define IPC_SEND_NO_WAIT        0       /* send and return at once */

/*
 * Send command 0xF3 (IPC_CMD_READ_INFOFRAME) and wait for the reply. The input program reads an InfoFrame of the
 * given type from an HDMI 2.0 receiver and answers with the 28 bytes. Nothing in the firmware calls this routine,
 * and it does not return the reply.
 *   receiver:       data byte 0, the HDMI 2.0 receiver
 *   infoframe_type: data byte 1, the InfoFrame type
 */
void ipc_dbg_get_receiver_block(unsigned char receiver, unsigned char infoframe_type)
{
    unsigned char data[4] = {receiver, infoframe_type};
    ipc_send_command(IPC_CMD_READ_INFOFRAME, 2, data, IPC_SEND_NO_WAIT);
    ipc_wait_reply(1);
}
