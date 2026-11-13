/* ipc_8051_send_power_cut_table  (FUN_a0136384)
 *
 * Queue the 18-byte power-cut table for the 8051 (message type 10).
 * Name basis: derived - record at 0xA802D9A0; called from SYSAPI_PowerOff and SYSAPI_PowerSaving; message type
 *   10; the handler in the 8051 program (ipc_store_power_cut_list, prints CutPwArray) shows the content
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136384 @ 0xa0136384-0xa0136600 (636 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the message buffer is declared before the packed words (stack order);
 *  - the packed words and the packing pointer are unsigned long (the alias set of the queue stores decides the
 *    store schedule); the packing loop compares with a limit variable word_count = 4 (cmp 4; bcs);
 *  - the short-piece test is an unsigned compare, (unsigned int)(18 - offset) < 16;
 *  - both waits are a static copy of ipc_8051_wait_tx_queue with all three modes, which -O3 inlines.
 */

#define IPC_PORTAL_8051          0      /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_TX_SLOTS        0x10   /* first slot for messages to the 8051 (docs/MAILBOX.md) */
#define IPC_SLOT_BYTES           20     /* one slot: header word and four data words */
#define IPC_TX_QUEUE_LAST_INDEX  0x24   /* queue indices run 0..0x24 */
#define IPC_TX_QUEUE_ROOM        36     /* entries that can be filled at most; one always stays empty */
#define MSG_PIECE_BYTES          16     /* most bytes one message carries */
#define IPC_8051_MSG_POWER_CUT   10     /* message type 10: the power-cut table (ipc_store_power_cut_list) */
#define POWER_CUT_TABLE_SIZE     18     /* six 3-byte records (code, entry, delay) */

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
extern unsigned char ipc_8051_power_cut_table[];
extern void ipc_8051_build_power_cut_table(void);
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

/*
 * Build the power-cut table (ipc_8051_build_power_cut_table) and send its 18 bytes to the 8051 as message
 * type 10, which stores them in its power-cut table (ipc_store_power_cut_list: 18 bytes at XDATA 0xA6AF,
 * 'CutPwArray OOR' past the end).
 *
 * The table is copied into a zeroed local buffer and sent in two pieces: bytes 0..15 and bytes 16..17. Before
 * queueing, queued messages are moved into the mailbox until the queue has room for 18 bytes; afterwards the
 * routine returns only when the queue is empty and the 8051 has cleared all four slots.
 *
 * Called from SYSAPI_PowerOff and SYSAPI_PowerSaving, each time right after ipc_8051_send_wake_key_table.
 */
void ipc_8051_send_power_cut_table(void)
{
    unsigned char table[22] = { 0 };
    unsigned long words[4] = { 0, 0, 0, 0 };
    unsigned short i, offset;
    unsigned char count = MSG_PIECE_BYTES, offset_16 = 0, j, word_count;
    unsigned char *piece;
    unsigned long *dest;

    ipc_8051_build_power_cut_table();
    for (i = 0; i < POWER_CUT_TABLE_SIZE; i++)
        table[i] = ipc_8051_power_cut_table[i];
    wait_queue_empty(WAIT_ROOM, POWER_CUT_TABLE_SIZE);
    for (offset = 0; offset < POWER_CUT_TABLE_SIZE; offset += MSG_PIECE_BYTES) {
        if ((unsigned int)(POWER_CUT_TABLE_SIZE - offset) < MSG_PIECE_BYTES)
            count = POWER_CUT_TABLE_SIZE - offset;
        piece = table + offset;
        /* Four big-endian words: the 8051 unpacks them high byte first. */
        word_count = 4;
        dest = words;
        for (j = 0; j < word_count; j++) {
            dest[j] = piece[j * 4];
            dest[j] = (dest[j] << 8) + piece[j * 4 + 1];
            dest[j] = (dest[j] << 8) + piece[j * 4 + 2];
            dest[j] = (dest[j] << 8) + piece[j * 4 + 3];
        }
        /* Header: offset / 16 in bits 24..31, byte count in bits 16..23; no flags, no channel. */
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[0] = (offset_16 << 24) + (count << 16) + IPC_8051_MSG_POWER_CUT;
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
