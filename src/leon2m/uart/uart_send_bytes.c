/* uart_send_bytes  (FUN_a01337e8)
 *
 * Queue bytes for sending on one of the 8051's serial ports.
 *   cmd: serial port of the 8051 (1..4)
 *   len: number of bytes
 *   p: the bytes
 * Name basis: derived - message type 3 to the 8051 with the port number in the command byte; reached through
 *   uart_api_send_bytes by the PC tool reply frames and the LED bar frames
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01337e8 @ 0xa01337e8-0xa0133950 (360 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form the exact build depends on: the same as the ring senders ipc_8051_send_power_cut_table / ipc_8051_send_storage_block (the packed
 * words are unsigned long, the packing loop limit is the variable word_count); the message type is a variable so
 * that the constant stays ahead of (flags << 4) in the sum.
 */

#define IPC_8051_MSG_UART       3       /* message type 3: bytes to send on a serial port of the 8051 */
#define IPC_TX_QUEUE_LAST_INDEX 0x24    /* the queue has 36 entries */
#define MSG_PIECE_BYTES         16      /* most bytes one message carries */
#define IPC_FLAGS_LAST_PIECE    1       /* flags nibble (bits 4..7 of word 0) of the final piece */
#define IPC_FLAGS_MORE_PIECES   2       /* flags nibble of every piece before it */

/* One 8051 message: header word and four data words. */
struct Msg { unsigned int w[5]; };
extern unsigned char ipc_8051_tx_queue_write_index;
extern struct Msg ipc_8051_tx_queue[];

/*
 * Queue len bytes for serial port `port` of the 8051 (type 3 messages). The caller is uart_api_send_bytes.
 * Nothing is sent here and nothing is waited for: the entries are written to ipc_8051_tx_queue and
 * ipc_8051_tx_queue_flush hands them to the mailbox later.
 *
 *   port   serial port number; goes into bits 8..15 of the header (the parameter is called cmd in the code
 *          that builds the header)
 *   len    number of bytes; 0 queues nothing
 *   p      the bytes
 *
 * The bytes go out in pieces of 16. Header word 0 of a piece:
 *   bits 24..31  piece number from 0 (the byte offset / 16)
 *   bits 16..23  bytes in this piece (16, or what is left in the final piece)
 *   bits  8..15  port
 *   bits  4..7   2 for every piece but the last, 1 for the last
 *   bits  0..3   message type 3
 * Words 1..4 hold the 16 bytes of the piece, four per word, first byte in the high bits. Four words are always
 * read from the buffer, so a final piece shorter than 16 bytes also copies the bytes behind it; the byte count in
 * the header tells the receiver how many are valid.
 */
void uart_send_bytes(unsigned char cmd, unsigned short len, unsigned char *p)
{
    unsigned long w[4] = { 0, 0, 0, 0 };        /* the four data words of the piece */
    unsigned short off;                         /* offset of the piece in p */
    unsigned char type = IPC_8051_MSG_UART, last = IPC_FLAGS_MORE_PIECES, cnt = MSG_PIECE_BYTES;
    unsigned char hi = 0;                       /* piece number */
    unsigned char j, nw;
    unsigned char *q;
    unsigned long *d;

    for (off = 0; off < len; off += MSG_PIECE_BYTES) {
        if (len - off <= MSG_PIECE_BYTES) {
            cnt = len - off;
            last = IPC_FLAGS_LAST_PIECE;
        }
        q = p + off;
        nw = 4;
        d = w;
        /* Pack the 16 bytes big-endian into four words. */
        for (j = 0; j < nw; j++) {
            d[j] = q[j * 4];
            d[j] = (d[j] << 8) + q[j * 4 + 1];
            d[j] = (d[j] << 8) + q[j * 4 + 2];
            d[j] = (d[j] << 8) + q[j * 4 + 3];
        }
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].w[0] = (hi << 24) + (cnt << 16) + (cmd << 8) + type + (last << 4);
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].w[1] = w[0];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].w[2] = w[1];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].w[3] = w[2];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].w[4] = w[3];
        if (++ipc_8051_tx_queue_write_index > IPC_TX_QUEUE_LAST_INDEX)
            ipc_8051_tx_queue_write_index = 0;
        hi++;
    }
}
