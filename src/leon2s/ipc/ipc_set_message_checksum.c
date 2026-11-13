/* ipc_set_message_checksum  (FUN_a006fb3c)
 *
 * Store the XOR checksum of a mailbox message in its top byte.
 *   message
 *   word_count
 * Name basis: proven - XOR of all bytes of the first n words into byte 3 of word 0; checked by
 *   ipc_verify_message
 *
 * Matching notes
 * --------------
 * FUN_a006fb3c (leon2s 0xa006fb3c), flags -mcpu=v8 -Os -g.
 * The operand order 'word ^ checksum' gives the target's xor %o5, %o4, %o4.
 */
/*
 * Store the checksum of a mailbox message in its first byte (the top byte of word 0).
 *
 *   message     the words of the message
 *   word_count  number of words (only the low 8 bits count)
 *
 * The first byte is cleared, then the checksum is the XOR of all bytes of the first word_count words; with the
 * checksum stored the XOR of all bytes of the message is 0 (see ipc_verify_message).
 */
void ipc_set_message_checksum(unsigned int *message, unsigned int word_count)
{
    unsigned int checksum = 0;
    unsigned int i = 0;
    *message &= 0xffffff;
    if ((word_count & 0xff) != 0) {
        do {
            unsigned int word = message[i & 0xff];
            checksum = word ^ checksum ^ (word >> 8) ^ (word >> 16) ^ (word >> 24);
            i++;
        } while ((i & 0xff) < (word_count & 0xff));
    }
    *message |= checksum << 24;
}
