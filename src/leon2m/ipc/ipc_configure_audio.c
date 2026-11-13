/* ipc_configure_audio  (FUN_a0138564)
 *
 * Ask the input processor to store the 3-byte audio configuration and initialise the audio block.
 * Name basis: derived - command 0x90 through the mailbox portal 1 sender; called from audio_init_config;
 *   mailbox command 0x90, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138564 @ 0xa0138564, flags -mcpu=v8 -O3 -g.
 * Source form: the message is a zero-initialised 4-byte array; p[0] is read into an unsigned char and copied into
 * an unsigned int for the shifts (an 'and 0xff' follows the load); bit 0 is taken from the byte.
 */
#define IPC_CMD_CONFIGURE_AUDIO 0x90            /* mailbox command 0x90 */
#define IPC_SEND_NO_WAIT        0               /* ipc_send_command: do not wait for the input processor */
extern void ipc_send_command(int, int, unsigned char *, int);

/*
 * Send the 3-byte audio configuration to the input processor (mailbox command 0x90). The input processor
 * unpacks it again and initialises its audio block.
 *
 *   config  three bytes. Message byte 0 is config[0] with its bit order reversed (bit 0 becomes bit 7), byte 1
 *           is config[2], byte 2 is bits 6..7 of config[1] and byte 3 is bits 4..5 of config[1].
 *
 * Called from audio_init_config.
 */
void ipc_configure_audio(unsigned char *config)
{
    unsigned char msg[4] = {0};
    unsigned char first = config[0];
    unsigned int bits = first;

    msg[0] = (bits >> 7) | ((bits >> 5) & 2) | ((bits >> 3) & 4) | ((bits >> 1) & 8) | ((bits << 1) & 0x10) | ((bits << 3) & 0x20) |
             ((bits << 5) & 0x40) | ((first & 1) << 7);
    msg[1] = config[2];
    msg[2] = config[1] >> 6;
    msg[3] = (config[1] >> 4) & 3;
    ipc_send_command(IPC_CMD_CONFIGURE_AUDIO, 4, msg, IPC_SEND_NO_WAIT);
}
