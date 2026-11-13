/* ipc_send_reply  (FUN_a006fd78)
 *
 * Send a reply message with id and up to 28 data bytes in mailbox slot 10.
 *   id: reply id
 *   len: data
 *   d: byte count
 * Name basis: derived - waits until slot 10 is free, header 0x55 | id | length, checksum; caller
 *   ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * FUN_a006fd78 (leon2s 0xa006fd78, 356 bytes), flags -mcpu=v8 -Os -g.
 * The byte count is split with / 4 and % 4 (the % gives the and on the masked length); the partial word is
 * addressed as buf[len / 4 + 1].
 */
extern void *lib_memset(void *, int, unsigned int);
extern void ipc_read_mailbox_slot(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void ipc_write_mailbox_slot(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void ipc_set_message_checksum(unsigned int *buf, unsigned char n);

#define IPC_SLOT_REPLY      10          /* mailbox slot the replies go to */
#define IPC_REPLY_WORDS     8           /* the message: header word + 7 data words */
#define IPC_REPLY_BYTES     0x1c        /* most data bytes of one reply */
#define IPC_MESSAGE_MARKER  0x55        /* byte 3 of every mailbox message */

/*
 * Send a reply message to the main processor in the reply slot (slot 10).
 *
 *   id   reply id; goes to byte 2 of the header
 *   len  number of data bytes, at most 0x1C (larger values are cut to 0x1C)
 *   d    the data bytes
 *
 * Waits until word 0 of the slot reads 0, then builds the message: header word = marker 0x55 in the low byte,
 * id << 8, total length (data bytes + 4) << 16, checksum in the top byte; the data follows from word 1, four
 * bytes per word with the first byte in the lowest position. The unused words are 0.
 */
void ipc_send_reply(int id, unsigned char len, unsigned char *d)
{
    unsigned int buf[IPC_REPLY_WORDS];
    unsigned char pos;
    unsigned char i;
    unsigned char full_words;
    unsigned char tail_bytes;

    lib_memset(buf, 0, 4 * IPC_REPLY_WORDS);
    pos = 0;
    do
        ipc_read_mailbox_slot(IPC_SLOT_REPLY, 0, buf, 1);
    while (buf[0] != 0);
    if (len > IPC_REPLY_BYTES)
        len = IPC_REPLY_BYTES;
    full_words = len / 4;
    tail_bytes = len % 4;
    for (i = 0; i < full_words; i++) {
        buf[i + 1] = d[pos] | d[pos + 1] << 8 | d[pos + 2] << 16 | d[pos + 3] << 24;
        pos += 4;
    }
    if (tail_bytes)
        for (i = 0; i < tail_bytes; i++)
            buf[len / 4 + 1] |= d[pos + i] << (i * 8);
    len += 4;
    buf[0] = id << 8 | len << 16 | IPC_MESSAGE_MARKER;
    ipc_set_message_checksum(buf, IPC_REPLY_WORDS);
    ipc_write_mailbox_slot(IPC_SLOT_REPLY, 0, buf, IPC_REPLY_WORDS);
}
