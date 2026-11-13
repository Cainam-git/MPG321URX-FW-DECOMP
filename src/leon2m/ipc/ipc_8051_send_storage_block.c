/* ipc_8051_send_storage_block  (FUN_a013588c)
 *
 * Queue a block for the 8051's flash data buffer (message type 7, 16-byte pieces) at a byte offset.
 * Note: Returns only when the queue is empty and the 8051 has cleared all four slots.
 * Name basis: derived - header word: offset / 16 in bits 24..31, offset & 0xF in bits 8..15; the 8051's
 *   ipc_run_message stores type 7 pieces with ipc_store_flash_data; used by nvram_write and
 *   nvram_flash_advance_row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013588c @ 0xa013588c-0xa0135ae4 (604 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the room test is a static helper (queue_room_bytes) called in the while condition; the final wait is a
 *    static copy of ipc_8051_wait_tx_queue with all three modes, called with mode 3, which -O3 inlines;
 *  - the packed words are unsigned long (the alias set of the queue stores) and are written through a pointer
 *    dest = words, with the loop limit in a variable word_count = 4;
 *  - offset_low is an int, cut to a byte where it is used;
 *  - -msoft-float decides which loop invariants are hoisted.
 */

#define IPC_PORTAL_8051          0      /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_TX_SLOTS        0x10   /* first slot for messages to the 8051 (docs/MAILBOX.md) */
#define IPC_SLOT_BYTES           20     /* one slot: header word and four data words */
#define IPC_TX_QUEUE_LAST_INDEX  0x24   /* queue indices run 0..0x24 */
#define IPC_TX_QUEUE_ROOM        36     /* entries that can be filled at most; one always stays empty */
#define MSG_PIECE_BYTES          16     /* most bytes one message carries */
#define IPC_8051_MSG_FLASH_DATA  7      /* message type 7: data for the 8051's 2 KB flash data buffer */

/* Modes of the queue wait (as ipc_8051_wait_tx_queue). */
enum {
    WAIT_ROOM  = 1,                     /* until the queue has room for a given number of bytes */
    WAIT_EMPTY = 2,                     /* until the queue is empty */
    WAIT_TAKEN = 3                      /* until the queue is empty and the 8051 has cleared all four slots */
};

/* One entry of the outgoing queue: the header word and four data words, as they go into a slot. */
struct ipc_8051_queue_entry { unsigned int words[5]; };

extern unsigned char ipc_8051_tx_queue_read_index, ipc_8051_tx_queue_write_index;
extern struct ipc_8051_queue_entry ipc_8051_tx_queue[];
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

/* Free room in the queue, in data bytes (16 per free entry). */
static unsigned short queue_room_bytes(void)
{
    unsigned short free_entries;

    if (ipc_8051_tx_queue_write_index > ipc_8051_tx_queue_read_index)
        free_entries = ipc_8051_tx_queue_read_index - ipc_8051_tx_queue_write_index + IPC_TX_QUEUE_ROOM;
    else if (ipc_8051_tx_queue_write_index >= ipc_8051_tx_queue_read_index)
        free_entries = IPC_TX_QUEUE_ROOM;
    else
        free_entries = ipc_8051_tx_queue_read_index - ipc_8051_tx_queue_write_index - 1;
    return free_entries << 4;
}

/*
 * Send length bytes to the 8051's 2 KB flash data buffer (XDATA 0xA800), starting at byte buffer_offset of that
 * buffer, as message type 7 in pieces of 16 bytes.
 *
 *   buffer_offset  where the first byte lands in the flash data buffer
 *   length         number of bytes
 *   data           the bytes
 *
 * First it moves queued messages into the mailbox until the queue has room for the whole block. Each piece is one
 * queue entry; its header word carries buffer_offset / 16 plus the piece number in bits 24..31 and buffer_offset
 * & 0xF in bits 8..15. The 8051 (ipc_run_message) adds the two back together, so piece n lands at
 * buffer_offset + 16 * n; after every piece it posts the buffer's checksum to portal word 0xB0. The routine
 * returns only when the queue is empty and the 8051 has cleared all four slots.
 *
 * Called by nvram_write (the block for a flash-backed storage area) and twice by nvram_flash_advance_row (one
 * byte at the last byte of the row, before each row program).
 */
void ipc_8051_send_storage_block(unsigned short buffer_offset, unsigned short length, unsigned char *data)
{
    unsigned long words[4] = { 0, 0, 0, 0 };
    unsigned short offset;
    unsigned char count = length > 15 ? 16 : length, j, word_count;
    unsigned char offset_16 = buffer_offset >> 4;
    int offset_low = buffer_offset & 0xf;
    unsigned char *piece;
    unsigned long *dest;

    while (length > queue_room_bytes())
        ipc_8051_tx_queue_flush();
    for (offset = 0; offset < length; offset += MSG_PIECE_BYTES) {
        if (length - offset < MSG_PIECE_BYTES)
            count = length - offset;
        piece = data + offset;
        /* Four big-endian words: the 8051 unpacks them high byte first. */
        word_count = 4;
        dest = words;
        for (j = 0; j < word_count; j++) {
            dest[j] = piece[j * 4];
            dest[j] = (dest[j] << 8) + piece[j * 4 + 1];
            dest[j] = (dest[j] << 8) + piece[j * 4 + 2];
            dest[j] = (dest[j] << 8) + piece[j * 4 + 3];
        }
        /* The flags nibble stays 0: no piece is marked as the last one. */
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[0] = (offset_16 << 24) + (count << 16) + ((unsigned char)offset_low << 8) + IPC_8051_MSG_FLASH_DATA;
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[1] = words[0];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[2] = words[1];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[3] = words[2];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[4] = words[3];
        if (++ipc_8051_tx_queue_write_index > IPC_TX_QUEUE_LAST_INDEX)
            ipc_8051_tx_queue_write_index = 0;
        offset_16++;
    }
    wait_queue_empty(WAIT_TAKEN, 0);
}
