/* ipc_8051_request_and_wait  (FUN_a0135344)
 *
 * Queue a request with two bytes for the 8051 and service the mailbox until the answer is in.
 * Name basis: derived - queue entry with command | 0x80, then flush and poll in a loop; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0135344 @ 0xa0135344, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the sender (the body of ipc_8051_queue_buffer_chunks, here
 * queue_i2c_message with its packing helper pack_words(words, bytes, word_count)) and ipc_8051_take_rx_block2
 * are static copies inlined at -O3; the sender is called with 'channel | 0x80'; the count field is formed in an
 * unsigned int before the header sum ('count_field = count << 16'); the packed words are unsigned long; the queue
 * is a 2-D word array ipc_8051_tx_queue[][5] (as ipc_8051_send_buffer_chunks).
 */
#define IPC_8051_MSG_I2C        2       /* message type 2: an I2C transfer for the 8051 (ipc_run_message) */
#define IPC_TX_QUEUE_LAST_INDEX 0x24    /* queue indices run 0..0x24 */
#define MSG_PIECE_BYTES         16      /* most bytes one message carries */
#define IPC_FLAGS_LAST_PIECE    1       /* flags nibble (bits 4..7 of word 0) of the final piece */
#define IPC_FLAGS_MORE_PIECES   2       /* flags nibble of every piece before it */
#define I2C_WRITE_READ          0x80    /* channel byte bit 7: write-then-read instead of a page write (8051 side) */

extern unsigned char ipc_8051_tx_queue_write_index;
extern unsigned int ipc_8051_tx_queue[][5];
extern void ipc_8051_tx_queue_flush(void);
extern void ipc_8051_poll_messages(void);
extern unsigned char ipc_8051_rx_block2_length, ipc_8051_rx_block2_ready_flag;
extern unsigned char ipc_8051_rx_block_buffer[];

/* When the I2C result is in (ipc_8051_decode_message, type 2): copy it to dst, clear the ready flag, return 1. */
static unsigned char ipc_8051_take_rx_block2(unsigned char *dst)
{
    unsigned char taken = 0;
    unsigned char i;

    if (ipc_8051_rx_block2_ready_flag == 1) {
        for (i = 0; i < ipc_8051_rx_block2_length; i++)
            dst[i] = ipc_8051_rx_block_buffer[i];
        ipc_8051_rx_block2_ready_flag = 0;
        taken = 1;
    }
    return taken & 1;
}

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

/* Queue an I2C message in 16-byte pieces; see ipc_8051_queue_buffer_chunks, of which this is a copy. */
static void queue_i2c_message(unsigned char channel, unsigned char first, unsigned char second, unsigned char *data, unsigned short length)
{
    unsigned long words[4] = { 0, 0, 0, 0 };
    unsigned char first_piece[MSG_PIECE_BYTES] = { 0 };
    unsigned short offset;
    unsigned int count_field;
    unsigned char type = IPC_8051_MSG_I2C, flags = IPC_FLAGS_MORE_PIECES, count = MSG_PIECE_BYTES, piece = 0, k;

    if (channel & I2C_WRITE_READ) {
        piece = length;
        length = 0;
    }
    for (offset = 0; offset < length + 2; offset += MSG_PIECE_BYTES) {
        if (length - offset + 2 < MSG_PIECE_BYTES) {
            count = length - offset + 2;
            flags = IPC_FLAGS_LAST_PIECE;
        }
        if (offset == 0) {
            first_piece[0] = first;
            first_piece[1] = second;
            for (k = 0; k < count - 2; k++)
                first_piece[k + 2] = data[k];
            pack_words(words, first_piece, 4);
        } else
            pack_words(words, data + offset - 2, 4);
        count_field = count << 16;
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][0] = (piece << 24) + count_field + (channel << 8) + type + (flags << 4);
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][1] = words[0];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][2] = words[1];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][3] = words[2];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index][4] = words[3];
        if (++ipc_8051_tx_queue_write_index > IPC_TX_QUEUE_LAST_INDEX)
            ipc_8051_tx_queue_write_index = 0;
        piece++;
    }
}

/*
 * Ask the 8051 for an I2C write-then-read and wait for the bytes read.
 *
 *   channel     I2C channel; bit 7 is set here, which makes the 8051 do a write-then-read (ipc_run_message)
 *   first       first byte of the message (device address on the 8051 side)
 *   second      second byte (write count on the 8051 side)
 *   buffer      receives the result
 *   read_field  its low byte goes into header bits 24..31; the 8051 takes that field times 16 as the read count
 *
 * One message of type 2 with only the two bytes is queued (bit 7 set makes the sender drop the data). Then the
 * routine flushes the queue and polls the incoming slots until ipc_8051_decode_message reports the I2C result in
 * (ipc_8051_rx_block2_ready_flag), and copies ipc_8051_rx_block2_length bytes of it into buffer. There is no time
 * limit.
 *
 * No direct call to this routine was found in FW.021.
 */
void ipc_8051_request_and_wait(unsigned char channel, unsigned char first, unsigned char second, unsigned char *buffer, unsigned short read_field)
{
    queue_i2c_message(channel | I2C_WRITE_READ, first, second, buffer, read_field);
    while (!ipc_8051_take_rx_block2(buffer)) {
        ipc_8051_tx_queue_flush();
        ipc_8051_poll_messages();
    }
}
