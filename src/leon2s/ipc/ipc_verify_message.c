/* ipc_verify_message  (FUN_a006fd04)
 *
 * Check the 0x55 marker and the XOR checksum of a received mailbox message.
 * Returns: 1 when valid
 * Name basis: proven - inverse of ipc_set_message_checksum; ipc_poll_command reads slot 8 and runs
 *   ipc_dispatch_command on success
 *
 * Matching notes
 * --------------
 * FUN_a006fd04 (leon2s 0xa006fd04), flags -mcpu=v8 -Os -g.
 * One raw index is masked at each use ('index & 0xff'); a separate pre-masked index gives 'clr %g1' instead of the
 * 'and %o3, 0xff, %g1' at the loop head.
 */
#define IPC_MESSAGE_MARKER 0x55         /* byte 3 of every mailbox message */

/*
 * Check a received mailbox message: byte 3 must be the marker 0x55, and the XOR of all bytes of the first
 * word_count words must be 0 (the checksum byte, byte 0, was set by ipc_set_message_checksum on the sender's side).
 *
 *   message     the received words
 *   word_count  number of words
 *
 * Returns 1 when the message is valid, else 0. Called by ipc_poll_command.
 */
int ipc_verify_message(unsigned char *message, unsigned char word_count)
{
    unsigned int checksum = 0;

    if (message[3] == IPC_MESSAGE_MARKER) {
        unsigned int count = word_count & 0xff;
        unsigned int index = 0;

        if (count != 0) {
            do {
                unsigned int word = *(unsigned int *)(message + (index & 0xff) * 4);
                index++;
                checksum = word ^ checksum ^ (word >> 8) ^ (word >> 16) ^ (word >> 24);
            } while ((index & 0xff) < count);
        }

        return (checksum & 0xff) == 0;
    }

    return 0;
}
