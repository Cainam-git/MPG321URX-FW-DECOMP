/* ipc_send_dsc_dec_command  (FUN_a0137d6c)
 *
 * Send a command byte for the DSC decoder state machine of the input processor (command 0x74).
 * Name basis: derived - command 0x74 through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); mailbox command 0x74, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137d6c @ 0xa0137d6c, flags -mcpu=v8 -O2 -g.
 * Source form: the initialiser {command} gives the firmware's clear of the whole word followed by a single byte
 * store. Only 1 byte is sent.
 */
#define IPC_CMD_SET_DSC_DEC_COMMAND 0x74        /* mailbox command 0x74 */
#define IPC_SEND_WAIT_TAKEN         1           /* ipc_send_command: wait until the input processor has taken the message */
extern int ipc_send_command();

/*
 * Send a command byte for the DSC decoder state machine of the input processor (mailbox command 0x74). The
 * input processor stores the byte and sets the decoder's restart flag.
 *
 * Called from GlobalModeHandler.
 */
void ipc_send_dsc_dec_command(unsigned char decoder_command)
{
    unsigned char msg[4] = {decoder_command};

    ipc_send_command(IPC_CMD_SET_DSC_DEC_COMMAND, 1, msg, IPC_SEND_WAIT_TAKEN);
}
