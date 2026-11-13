/* ipc_8051_queue_buffer_chunks  (FUN_a013358c)
 *
 * Queue two bytes and a buffer for the 8051 in 16-byte chunks without waiting.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013358c @ 0xa013358c, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on: the queue is an array of 5-word entries, ipc_8051_tx_queue[][5]; the
 * packed words are unsigned long; the packing helper is a static routine that takes the word count as an
 * argument (pack_words(words, bytes, 4)) and is inlined twice. ipc_8051_send_buffer_chunks is the same body
 * followed by a wait for the queue.
 */
#define IPC_8051_MSG_I2C        2       /* message type 2: an I2C transfer for the 8051 (ipc_run_message) */
#define IPC_TX_QUEUE_LAST_INDEX 0x24    /* queue indices run 0..0x24 */
#define MSG_PIECE_BYTES         16      /* most bytes one message carries */
#define IPC_FLAGS_LAST_PIECE    1       /* flags nibble (bits 4..7 of word 0) of the final piece */
#define IPC_FLAGS_MORE_PIECES   2       /* flags nibble of every piece before it */
#define I2C_WRITE_READ          0x80    /* channel byte bit 7: write-then-read instead of a page write (8051 side) */

extern unsigned char ipc_8051_tx_queue_write_index;
extern unsigned int ipc_8051_tx_queue[][5];

/* Pack word_count groups of four bytes into big-endian words. */
static void pack_words(unsigned long *words, unsigned char *bytes, unsigned char word_count)
{
    unsigned char j;

    for (j = 0; j < word_count; j++) {
        words[j] = bytes[j * 4];
        words[j] = (words[j] << 8) + bytes[j * 4 + 1];
        words[j] = (words[j] << 8) + bytes[j * 4 + 2];
        words[j] = (words[j] << 8) + bytes[j * 4 + 3];
    }
}

/*
 * Queue an I2C message (type 2) for the 8051: the two bytes first and second, then length bytes of data, cut into
 * pieces of 16 bytes. Each piece is one entry of ipc_8051_tx_queue (ipc_8051_tx_queue_flush moves the entries
 * into the mailbox). The routine does not look at the free room in the queue and does not wait.
 *
 *   channel  goes into bits 8..15 of each header word (the 8051 takes it as the I2C channel)
 *   first    first byte of the first piece
 *   second   second byte of the first piece
 *   data     the data bytes
 *   length   number of data bytes
 *
 * Header word of a piece: piece number << 24, byte count << 16, channel << 8, flags << 4, type 2. All pieces but
 * the last carry IPC_FLAGS_MORE_PIECES, a last piece shorter than 16 bytes IPC_FLAGS_LAST_PIECE; when
 * length + 2 is a multiple of 16 no piece carries the last-piece flag.
 *
 * With bit 7 of channel set, only first and second are sent, and bits 24..31 carry the low byte of length
 * instead of the piece number. The 8051 handles this case as a write-then-read (ipc_run_message): first = device
 * address, second = write count, the offset field times 16 = read count. Without bit 7 it collects the pieces
 * and on the last one calls i2c_write_eeprom_pages with first = device address and second = start address.
 *
 * No direct call to this routine was found in FW.021.
 */
void ipc_8051_queue_buffer_chunks(unsigned char channel, unsigned char first, unsigned char second, unsigned char *data, unsigned short length)
{
    unsigned long words[4] = { 0, 0, 0, 0 };
    unsigned char first_piece[MSG_PIECE_BYTES] = { 0 };
    unsigned short offset;
    unsigned char type = IPC_8051_MSG_I2C, flags = IPC_FLAGS_MORE_PIECES, count = MSG_PIECE_BYTES, piece = 0, k;

    if (channel & I2C_WRITE_READ) {
        piece = length;
        length = 0;
    }
    /* offset counts the bytes of the whole message: the two leading bytes, then the data. */
    for (offset = 0; offset < length + 2; offset += MSG_PIECE_BYTES) {
        if (length - offset + 2 < MSG_PIECE_BYTES) {
            count = length - offset + 2;
            flags = IPC_FLAGS_LAST_PIECE;
        }
        if (offset == 0) {
            /* The first piece is built in a local buffer: the two bytes, then the first data bytes. */
            first_piece[0] = first;
            first_piece[1] = second;
            for (k = 0; k < count - 2; k++)
                first_piece[k + 2] = data[k];
            pack_words(words, first_piece, 4);
        } else
            pack_words(words, data + offset - 2, 4);
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][0] = (piece << 24) + (count << 16) + (channel << 8) + type + (flags << 4);
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][1] = words[0];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][2] = words[1];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][3] = words[2];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][4] = words[3];
        if (++ipc_8051_tx_queue_write_index > IPC_TX_QUEUE_LAST_INDEX)
            ipc_8051_tx_queue_write_index = 0;
        piece++;
    }
}
