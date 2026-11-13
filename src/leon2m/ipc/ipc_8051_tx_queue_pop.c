/* ipc_8051_tx_queue_pop  (FUN_a0135004)
 *
 * Take the next queued message out of the outgoing queue.
 * Returns: message in the caller's buffer
 * Name basis: derived - ring of 20-byte entries at 0xA802DA6C; unused
 *
 * Matching notes
 * --------------
 * FUN_a0135004, flags -mcpu=v8 -O3 -g. Source form: message is a plain word pointer, so every store through it may
 * alias the byte index and the compiler reloads ipc_8051_tx_queue_read_index for each word.
 */
/* One queued message: the header word and four data words, as in a mailbox slot. */
struct ipc_8051_tx_entry { unsigned int word[5]; };
extern struct ipc_8051_tx_entry ipc_8051_tx_queue[];
extern unsigned char ipc_8051_tx_queue_write_index, ipc_8051_tx_queue_read_index;

#define IPC_8051_TX_QUEUE_LAST  0x24    /* last index of the ring of 37 entries */

/*
 * Take the next message out of the ring of messages waiting for a free slot of the 8051 mailbox
 * (ipc_8051_tx_queue_flush sends them). Nothing in the firmware calls this routine.
 *   message: five words; words 0..3 are cleared first. When the ring is not empty (the write and read indexes
 *            differ) the entry at the read index is copied into all five words and the read index moves on,
 *            from the last entry back to 0.
 */
void ipc_8051_tx_queue_pop(unsigned int *message)
{
    unsigned char next;

    message[0] = 0;
    message[1] = 0;
    message[2] = 0;
    message[3] = 0;
    if (ipc_8051_tx_queue_write_index != ipc_8051_tx_queue_read_index) {
        message[0] = ipc_8051_tx_queue[ipc_8051_tx_queue_read_index].word[0];
        message[1] = ipc_8051_tx_queue[ipc_8051_tx_queue_read_index].word[1];
        message[2] = ipc_8051_tx_queue[ipc_8051_tx_queue_read_index].word[2];
        message[3] = ipc_8051_tx_queue[ipc_8051_tx_queue_read_index].word[3];
        message[4] = ipc_8051_tx_queue[ipc_8051_tx_queue_read_index].word[4];
        next = ipc_8051_tx_queue_read_index + 1;
        if (next > IPC_8051_TX_QUEUE_LAST)
            ipc_8051_tx_queue_read_index = 0;
        else
            ipc_8051_tx_queue_read_index = next;
    }
}
