/* ipc_8051_send_wake_port_table  (FUN_a0135dc0)
 *
 * Queue the table of wake-up ports for the 8051 (message type 9).
 * Name basis: derived - list built by input_port_list_build; called from SYSAPI_PowerSaving; message type 9;
 *   the handler in the 8051 program (ipc_store_wake_port_list, prints SetZPArry) shows the content
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0135dc0 @ 0xa0135dc0-0xa0136054 (660 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the ROM table is copied into the buffer by memcpy (memcpy) before the buffer is filled with 0xFF;
 *  - the packed words and the other locals are declared in a block after the copy call, so their zeroing follows
 *    the call; the packed words are unsigned long (the alias set of the queue stores), written through a pointer
 *    dest = words with the loop limit in a variable word_count = 4;
 *  - the short-piece test is the signed length - offset < 16;
 *  - both waits are a static copy of ipc_8051_wait_tx_queue with all three modes, which -O3 inlines.
 */

#define IPC_PORTAL_8051          0      /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_TX_SLOTS        0x10   /* first slot for messages to the 8051 (docs/MAILBOX.md) */
#define IPC_SLOT_BYTES           20     /* one slot: header word and four data words */
#define IPC_TX_QUEUE_LAST_INDEX  0x24   /* queue indices run 0..0x24 */
#define IPC_TX_QUEUE_ROOM        36     /* entries that can be filled at most; one always stays empty */
#define MSG_PIECE_BYTES          16     /* most bytes one message carries */
#define IPC_8051_MSG_WAKE_PORTS  9      /* message type 9: the wake-up port table (ipc_store_wake_port_list) */
#define WAKE_PORT_BUFFER_BYTES   0x30   /* the list buffer; the 8051 keeps the first 30 bytes (ten records) */

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
extern const unsigned char ipc_8051_wake_port_table[];
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern unsigned char input_port_list_build(unsigned int list);
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
 * Build the list of wake-up ports and send it to the 8051 as message type 9, which stores it in its wake-up port
 * table (ipc_store_wake_port_list: 30 bytes at XDATA 0xA62F, 'SetZPArry OOR' past the end).
 *
 * The 48-byte buffer is filled with 0xFF (the ROM table copied into it first is overwritten at once) and
 * input_port_list_build writes its 3-byte port records into it, ending with the end record; the size it returns
 * is the number of bytes sent. The routine first moves queued messages into the mailbox until the queue has room
 * for them, queues them in pieces of 16 bytes (piece n at table offset 16 * n), and returns only when the queue is
 * empty and the 8051 has cleared all four slots.
 *
 * Called from SYSAPI_PowerSaving.
 */
void ipc_8051_send_wake_port_table(void)
{
    unsigned char list[48];

    memcpy(list, ipc_8051_wake_port_table, WAKE_PORT_BUFFER_BYTES);
    {
        unsigned long words[4] = { 0, 0, 0, 0 };
        unsigned short i, offset;
        unsigned char length;
        unsigned char count = MSG_PIECE_BYTES, offset_16 = 0, j, word_count;
        unsigned char *piece;
        unsigned long *dest;

        for (i = 0; i < 48; i++)
            list[i] = 0xff;
        length = input_port_list_build((unsigned int)list);
        wait_queue_empty(WAIT_ROOM, length);
        for (offset = 0; offset < length; offset += MSG_PIECE_BYTES) {
            if (length - offset < MSG_PIECE_BYTES)
                count = length - offset;
            piece = list + offset;
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
            ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[0] = (offset_16 << 24) + (count << 16) + IPC_8051_MSG_WAKE_PORTS;
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
}
