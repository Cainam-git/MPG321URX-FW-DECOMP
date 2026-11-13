/* ipc_set_dsc_encoder_parameters  (FUN_a01392f8)
 *
 * Ask the input processor to store the picture compression parameters.
 * Name basis: derived - command 0xFE through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); unused; mailbox command 0xFE, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01392f8 @ 0xa01392f8-0xa01393bc (49 words), flags -mcpu=v8 -O2 -g. No direct callers (reached
 * through a table).
 * The message is an initialised 18-byte array.
 */
/* The record whose compression parameters are sent: eight halfwords at +8 to +0x16 and a source byte at +5. */
struct dsc_params_record {
    unsigned char pad0[5];
    unsigned char source;                       /* +5: sent as byte 17 */
    unsigned char pad6[2];
    unsigned short param[8];                    /* +8 .. +0x16 */
};
extern void ipc_send_command(int, int, unsigned char *, int);

#define IPC_CMD_SET_DSC_ENCODER_PARAMETERS 0xfe /* mailbox command 0xFE */
#define IPC_SEND_WAIT_TAKEN                1    /* wait until the input processor has taken the message */

/*
 * Send the compression (DSC) encoder parameters to the input processor with mailbox command 0xFE.
 *
 *   id      byte 16 of the message; the input processor stores it at +0x18 of its encoder record
 *   record  source of the eight parameter halfwords and of the source byte
 *
 * The 18-byte message is: bytes 0 to 15 = the eight halfwords at +8 to +0x16 of the record, each with its low
 * byte first; byte 16 = id; byte 17 = the source byte (+5) of the record, which the input processor stores at +5
 * of its encoder record. The routine waits until the input processor has taken the message.
 * The routine has no direct caller; it is reached through a table.
 */
void ipc_set_dsc_encoder_parameters(unsigned char id, struct dsc_params_record *record)
{
    unsigned char msg[18] = {0};

    msg[0] = record->param[0];
    msg[1] = record->param[0] >> 8;
    msg[2] = record->param[1];
    msg[3] = record->param[1] >> 8;
    msg[4] = record->param[2];
    msg[5] = record->param[2] >> 8;
    msg[6] = record->param[3];
    msg[7] = record->param[3] >> 8;
    msg[8] = record->param[4];
    msg[9] = record->param[4] >> 8;
    msg[10] = record->param[5];
    msg[11] = record->param[5] >> 8;
    msg[12] = record->param[6];
    msg[13] = record->param[6] >> 8;
    msg[14] = record->param[7];
    msg[15] = record->param[7] >> 8;
    msg[16] = id;
    msg[17] = record->source;
    ipc_send_command(IPC_CMD_SET_DSC_ENCODER_PARAMETERS, 0x12, msg, IPC_SEND_WAIT_TAKEN);
}
