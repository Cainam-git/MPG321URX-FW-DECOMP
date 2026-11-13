/* ipc_route_audio_source  (FUN_a013863c)
 *
 * Ask the input processor to route an audio source to an output through an audio unit.
 * Name basis: derived - command 0x92 through the mailbox portal 1 sender; used by the ACR unit bookkeeping;
 *   mailbox command 0x92, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013863c @ 0xa013863c, flags -mcpu=v8 -O2 -g.
 * Source form: the message is initialised with {0, 0, 0, 0} (that gives the clear of the whole word) and the four
 * bytes are then stored one by one.
 */
#define IPC_CMD_ROUTE_AUDIO_SOURCE 0x92         /* mailbox command 0x92 */
#define IPC_SEND_NO_WAIT           0            /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Ask the input processor to route an audio source to an output through an audio unit (mailbox command 0x92).
 *
 *   source  the source
 *   output  the output
 *   unit    the audio unit
 *   enable  the enable value
 *
 * Called from audio_unit_send_owner_slots, audio_unit_assign_unit and audio_unit_request_unit.
 */
void ipc_route_audio_source(unsigned char source, unsigned char output, unsigned char unit, unsigned char enable)
{
    unsigned char msg[4] = {0, 0, 0, 0};
    msg[0] = source;
    msg[1] = output;
    msg[2] = unit;
    msg[3] = enable;
    ipc_send_command(IPC_CMD_ROUTE_AUDIO_SOURCE, 4, msg, IPC_SEND_NO_WAIT);
}
