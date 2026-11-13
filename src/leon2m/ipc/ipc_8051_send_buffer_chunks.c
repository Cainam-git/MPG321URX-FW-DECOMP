/* ipc_8051_send_buffer_chunks  (FUN_a0135ae8)
 *
 * Queue two bytes and a buffer for the 8051 in 16-byte chunks.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0135ae8 @ 0xa0135ae8, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the queue is an array of 5-word entries, ipc_8051_tx_queue[][5]; the packed words are unsigned long;
 *  - the packing helper is a static routine that takes the word count as an argument (pack_words(words, bytes,
 *    4)) and is inlined twice; passing 4 through the parameter keeps the constant from being folded;
 *  - the final wait is a static copy of ipc_8051_wait_tx_queue with all three modes, called with mode 3, which
 *    -O3 inlines.
 * The body up to the wait is the same as ipc_8051_queue_buffer_chunks.
 */

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_TX_SLOTS       0x10    /* first slot for messages to the 8051 (docs/MAILBOX.md) */
#define IPC_SLOT_BYTES          20      /* one slot: header word and four data words */
#define IPC_TX_QUEUE_LAST_INDEX 0x24    /* queue indices run 0..0x24 */
#define IPC_TX_QUEUE_ROOM       36      /* entries that can be filled at most; one always stays empty */
#define IPC_8051_MSG_I2C        2       /* message type 2: an I2C transfer for the 8051 (ipc_run_message) */
#define MSG_PIECE_BYTES         16      /* most bytes one message carries */
#define IPC_FLAGS_LAST_PIECE    1       /* flags nibble (bits 4..7 of word 0) of the final piece */
#define IPC_FLAGS_MORE_PIECES   2       /* flags nibble of every piece before it */
#define I2C_WRITE_READ          0x80    /* channel byte bit 7: write-then-read instead of a page write (8051 side) */

/* Modes of the queue wait (as ipc_8051_wait_tx_queue). */
enum {
    WAIT_ROOM  = 1,                     /* until the queue has room for a given number of bytes */
    WAIT_EMPTY = 2,                     /* until the queue is empty */
    WAIT_TAKEN = 3                      /* until the queue is empty and the 8051 has cleared all four slots */
};

extern unsigned char ipc_8051_tx_queue_read_index, ipc_8051_tx_queue_write_index;
extern unsigned int ipc_8051_tx_queue[][5];
extern void ipc_8051_tx_queue_flush(void);
extern void ipc_mailbox_read(unsigned char, unsigned char, unsigned int *, unsigned char);

/* The body of ipc_8051_wait_tx_queue. Every mode waits without a time limit. */
static void wait_queue_empty(unsigned char mode, unsigned short bytes)
{
    unsigned int header = 0;
    unsigned int any_busy;
    unsigned char slot;
    unsigned short free_entries;

    switch (mode) {
    case WAIT_ROOM:
        for (;;) {
            if (ipc_8051_tx_queue_write_index > ipc_8051_tx_queue_read_index)
                free_entries = ipc_8051_tx_queue_read_index - ipc_8051_tx_queue_write_index + IPC_TX_QUEUE_ROOM;
            else if (ipc_8051_tx_queue_write_index >= ipc_8051_tx_queue_read_index)
                free_entries = IPC_TX_QUEUE_ROOM;
            else
                free_entries = ipc_8051_tx_queue_read_index - ipc_8051_tx_queue_write_index - 1;
            if (bytes <= (unsigned short)(free_entries << 4))
                break;
            ipc_8051_tx_queue_flush();
        }
        break;
    case WAIT_EMPTY:
        while (ipc_8051_tx_queue_write_index != ipc_8051_tx_queue_read_index)
            ipc_8051_tx_queue_flush();
        break;
    case WAIT_TAKEN:
        while (ipc_8051_tx_queue_write_index != ipc_8051_tx_queue_read_index)
            ipc_8051_tx_queue_flush();
        /* The 8051 clears a slot's header word after it has carried out the message. */
        do {
            any_busy = 0;
            for (slot = 0; slot * IPC_SLOT_BYTES + IPC_8051_TX_SLOTS <= 0x50; slot++) {
                ipc_mailbox_read(IPC_PORTAL_8051, slot * IPC_SLOT_BYTES + IPC_8051_TX_SLOTS, &header, 1);
                any_busy |= header;
            }
        } while (any_busy != 0);
        break;
    }
}

/* Pack word_count groups of four bytes into big-endian words (the 8051 unpacks them high byte first). */
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
 * pieces of 16 bytes, and wait until the 8051 has carried it out. Each piece is one entry of ipc_8051_tx_queue.
 * The routine does not look at the free room in the queue before it fills it.
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
 * Afterwards it moves the whole queue into the mailbox and waits, without a time limit, until the 8051 has
 * cleared all four slots. No direct call to this routine was found in FW.021.
 */
void ipc_8051_send_buffer_chunks(unsigned char channel, unsigned char first, unsigned char second, unsigned char *data, unsigned short length)
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
    wait_queue_empty(WAIT_TAKEN, 0);
}
