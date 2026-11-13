/* ipc_set_dp_tx_timing  (FUN_a013832c)
 *
 * Ask the input processor to store the video timing for the DisplayPort outputs and program it.
 * Name basis: derived - command 0x50 through the mailbox portal 1 sender; mailbox command 0x50, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013832c @ 0xa013832c, flags -mcpu=v8 -O3 -g.
 * Source form: the single flag bits of word 0 are bit-fields of an unsigned int (they give the firmware's one word
 * load with shifts); the message bytes are stored in ascending order.
 */
#define IPC_CMD_SET_DP_TX_TIMING 0x50           /* mailbox command 0x50 */
#define IPC_SEND_NO_WAIT         0              /* ipc_send_command: do not wait for the input processor */
#define TIMING_MSG_BYTES         0x18

/* The output record (0x24 bytes per output, sys_output_records), as far as this routine reads it. */
struct output_record {
    unsigned int flag_31 : 1, flag_30 : 1, flag_29 : 1, flag_28 : 1, flag_27 : 1, flag_26 : 1, flag_25 : 1,
                 flag_24 : 1, rest : 24;                /* rest = signal_code_1 (+1), signal_code_2 (+2), byte_0x3 */
    unsigned short line_length, frame_length, active_width, active_height;      /* +4..+0xA: size values 0..3 */
    unsigned short size_4, size_5, size_6, size_7;      /* +0xC..+0x12: size values 4..7 */
    int word_0x14;
    unsigned char byte_0x18, bits_per_colour;           /* the size block's byte 0x14 and bits per colour */
};
extern void ipc_send_command(int, int, unsigned char *, int);

/*
 * Send the video timing of one output record to the input processor (mailbox command 0x50). The input processor
 * stores it in the path record of the DisplayPort output and programs the output.
 *
 *   output  DP output (message byte 0)
 *   rec     the output record
 *
 * Message: byte 1 = flags 31, 30, 29, 28, 27 and 25 of word 0 at bits 0..5; bytes 2 and 3 = bytes +1 and +2 of
 * the record; bytes 4..5 = the low half of word_0x14; bytes 6 and 7 = byte_0x18 and bits_per_colour; bytes
 * 8..23 = the eight size values, low byte first.
 *
 * Called from sys_report_output_timing.
 */
void ipc_set_dp_tx_timing(unsigned char output, struct output_record *rec)
{
    unsigned char msg[24];

    msg[0] = output;
    msg[1] = (rec->flag_25 << 5) | (rec->flag_27 << 4) | (rec->flag_28 << 3) | (rec->flag_29 << 2) | (rec->flag_30 << 1) | rec->flag_31;
    msg[2] = ((unsigned char *)rec)[1];
    msg[3] = ((unsigned char *)rec)[2];
    msg[4] = rec->word_0x14;
    msg[5] = rec->word_0x14 >> 8;
    msg[6] = rec->byte_0x18;
    msg[7] = rec->bits_per_colour;
    msg[8] = rec->line_length;
    msg[9] = rec->line_length >> 8;
    msg[10] = rec->frame_length;
    msg[11] = rec->frame_length >> 8;
    msg[12] = rec->active_width;
    msg[13] = rec->active_width >> 8;
    msg[14] = rec->active_height;
    msg[15] = rec->active_height >> 8;
    msg[16] = rec->size_4;
    msg[17] = rec->size_4 >> 8;
    msg[18] = rec->size_5;
    msg[19] = rec->size_5 >> 8;
    msg[20] = rec->size_6;
    msg[21] = rec->size_6 >> 8;
    msg[22] = rec->size_7;
    msg[23] = rec->size_7 >> 8;
    ipc_send_command(IPC_CMD_SET_DP_TX_TIMING, TIMING_MSG_BYTES, msg, IPC_SEND_NO_WAIT);
}
