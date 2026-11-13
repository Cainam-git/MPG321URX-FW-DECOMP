/* ipc_get_input_timing  (FUN_a0139040)
 *
 * Ask the input processor to read the measured timing of one input port.
 * Name basis: derived - command 0x71 through the mailbox portal 1 sender; waits for the reply, copies four
 *   words out as halfwords; mailbox command 0x71, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139040 @ 0xa0139040-0xa0139114 (53 words), flags -mcpu=v8 -O3 -g. Caller: input_query_port_timing.
 * The four reply words are stored in the order +4, +8, +0xc, +0x10 of the record (out[0..1], out[6..7],
 * out[2..3], out[4..5]). Same switch as ipc_get_dp_rx_clock_value.
 */
/* The reply of the input processor: word 0 is the reply header, words 1 to 4 are the first 16 data bytes. */
struct reply_words { unsigned int header, data_0, data_1, data_2, data_3; };
extern struct reply_words ipc_reply_words;
extern void ipc_send_command(int, int, unsigned char *, int);
extern void ipc_wait_reply(int);

#define IPC_CMD_GET_INPUT_TIMING 0x71           /* mailbox command 0x71 */
#define IPC_SEND_NO_WAIT         0              /* do not wait for the reply slot */

/*
 * Read the timing of input 0 to 3 from the input processor and copy it into out[0..7].
 *
 *   mode  input number 0 to 3; it is sent as port number 2 to 5 (any other value sends port number 0)
 *   out   receives eight 16-bit values
 *
 * Mailbox command 0x71 answers with eight 16-bit timing values (input_read_port_timing in the input program).
 * The routine waits for the reply and splits its first four data words into halves: the first word goes to
 * out[0] and out[1], the second to out[6] and out[7], the third to out[2] and out[3], the fourth to out[4] and
 * out[5]; in each word the low half comes first.
 * Called from input_query_port_timing (input_query_port_timing).
 */
void ipc_get_input_timing(unsigned char mode, unsigned short *out)
{
    unsigned char msg[4] = {0};

    switch (mode) {
    case 1: msg[0] = 3; break;
    case 2: msg[0] = 4; break;
    case 3: msg[0] = 5; break;
    case 0: msg[0] = 2; break;
    }
    ipc_send_command(IPC_CMD_GET_INPUT_TIMING, 4, msg, IPC_SEND_NO_WAIT);
    ipc_wait_reply(1);
    out[0] = ipc_reply_words.data_0;
    out[1] = ipc_reply_words.data_0 >> 16;
    out[6] = ipc_reply_words.data_1;
    out[7] = ipc_reply_words.data_1 >> 16;
    out[2] = ipc_reply_words.data_2;
    out[3] = ipc_reply_words.data_2 >> 16;
    out[4] = ipc_reply_words.data_3;
    out[5] = ipc_reply_words.data_3 >> 16;
}
