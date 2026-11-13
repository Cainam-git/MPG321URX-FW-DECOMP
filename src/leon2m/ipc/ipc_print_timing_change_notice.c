/* ipc_print_timing_change_notice  (FUN_a0138fb8)
 *
 * Ask the input processor to print a timing change notice (debug).
 * Name basis: derived - command 0xA6 through the mailbox portal 1 sender; mailbox command 0xA6, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138fb8 @ 0xa0138fb8-0xa0139040 (34 words), flags -mcpu=v8 -O2 -g. Caller: dbg_send_timing_change_notice.
 * The message is an initialised 12-byte array (std + st of zero first).
 */
extern void ipc_send_command(int, int, unsigned char *, int);

#define IPC_CMD_PRINT_TIMING_CHANGE 0xa6        /* mailbox command 0xA6 */
#define IPC_SEND_NO_WAIT            0           /* do not wait for the reply slot */

/*
 * Send mailbox command 0xA6 to the input processor, which prints 'AT Prepare Timing Change' with the three
 * values (debug only, see docs/MAILBOX.md). The message is the three words in order, each with its lowest byte
 * first. Called from dbg_send_timing_change_notice.
 */
void ipc_print_timing_change_notice(unsigned int value_0, unsigned int value_1, unsigned int value_2)
{
    unsigned char msg[12] = {0};

    msg[0] = value_0;
    msg[1] = value_0 >> 8;
    msg[2] = value_0 >> 16;
    msg[3] = value_0 >> 24;
    msg[4] = value_1;
    msg[5] = value_1 >> 8;
    msg[6] = value_1 >> 16;
    msg[7] = value_1 >> 24;
    msg[8] = value_2;
    msg[9] = value_2 >> 8;
    msg[10] = value_2 >> 16;
    msg[11] = value_2 >> 24;
    ipc_send_command(IPC_CMD_PRINT_TIMING_CHANGE, 12, msg, IPC_SEND_NO_WAIT);
}
