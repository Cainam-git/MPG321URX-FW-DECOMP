/* ddc_queue_reply  (FUN_a0133b54)
 *
 * Queue the bytes of a DDC/CI reply for the 8051 to send.
 * Name basis: derived - message type 4 to the 8051; used by the DDC/CI request handler and the factory tool
 *   replies
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133b54 @ 0xa0133b54-0xa0133cbc (360 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form the exact build depends on: the same as the ring senders ipc_8051_send_power_cut_table / ipc_8051_send_storage_block (the packed
 * words are unsigned long, the packing loop limit is the variable word_count); the message type is a variable so
 * that the constant stays ahead of (flags << 4) in the sum.
 */

#define IPC_8051_MSG_DDCCI      4       /* message type 4: DDC/CI reply bytes for the 8051 */
#define IPC_TX_QUEUE_LAST_INDEX 0x24    /* the queue has 36 entries */
#define MSG_PIECE_BYTES         16      /* most bytes one message carries */
#define IPC_FLAGS_LAST_PIECE    1       /* flags nibble (bits 4..7 of word 0) of the final piece */
#define IPC_FLAGS_MORE_PIECES   2       /* flags nibble of every piece before it */

/* One 8051 message: header word and four data words. */
struct Msg { unsigned int w[5]; };
extern unsigned char ipc_8051_tx_queue_write_index;
extern struct Msg ipc_8051_tx_queue[];

/*
 * Queue len bytes of a DDC/CI reply for the 8051 (type 4 messages). The caller is ddc_api_queue_reply.
 * Nothing is sent here and nothing is waited for: the entries are written to ipc_8051_tx_queue and
 * ipc_8051_tx_queue_flush hands them to the mailbox later.
 *
 *   cmd   goes into bits 8..15 of every header (the port / channel byte of a message to the 8051)
 *   len   number of bytes; 0 queues nothing
 *   p     the reply bytes
 *
 * The layout of the pieces is the same as in uart_send_bytes: 16 bytes per message, header word 0 =
 * piece number << 24 | bytes in the piece << 16 | cmd << 8 | flags << 4 | type, flags 2 before the last piece
 * and 1 on it. Words 1..4 hold the bytes four to a word, first byte in the high bits; four words are always read
 * from the buffer, also in a short final piece.
 */
void ddc_queue_reply(unsigned char cmd, unsigned short len, unsigned char *p)
{
    unsigned long w[4] = { 0, 0, 0, 0 };        /* the four data words of the piece */
    unsigned short off;                         /* offset of the piece in p */
    unsigned char type = IPC_8051_MSG_DDCCI, last = IPC_FLAGS_MORE_PIECES, cnt = MSG_PIECE_BYTES;
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
