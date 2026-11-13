/* ipc_8051_write_port_memory  (FUN_a0136a10)
 *
 * Queue a block for the 8051's 2 KB EDID RAM in 16-byte pieces (message type 1), from a RAM offset.
 * Note: No port number is sent; piece n goes to offset (offset / 16 + n) * 16, and the routine waits after
 *   every piece until the 8051 took it.
 * Name basis: derived - message type 1 with offset / 16 in header bits 24..31; the 8051's ipc_run_message
 *   copies type 1 pieces into its EDID RAM (XDATA 0xF800); used by startup_load_port_edids and
 *   edid_write_port_edid
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136a10 @ 0xa0136a10, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - data is a byte pointer, but the address of a piece is kept as an unsigned int (piece_address = (unsigned
 *    int)data + offset) and cast at each byte read, so every partial word of the packing is stored to words[j];
 *    the packed words are unsigned long; the packing loop compares with a limit variable word_count = 4;
 *  - the three prints have a debug class test each;
 *  - both waits are a static copy of ipc_8051_wait_tx_queue with all three modes, which -O3 inlines; the
 *    mode 3 wait sits inside the piece loop.
 */

#define IPC_PORTAL_8051             0       /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_TX_SLOTS           0x10    /* first slot for messages to the 8051 (docs/MAILBOX.md) */
#define IPC_SLOT_BYTES              20      /* one slot: header word and four data words */
#define IPC_TX_QUEUE_LAST_INDEX     0x24    /* queue indices run 0..0x24 */
#define IPC_TX_QUEUE_ROOM           36      /* entries that can be filled at most; one always stays empty */
#define MSG_PIECE_BYTES             16      /* most bytes one message carries */
#define IPC_8051_MSG_EDID_MEMORY    1       /* message type 1: bytes for the 8051's 2 KB EDID RAM (XDATA 0xF800) */
#define DBG_MAILBOX                 0x20    /* debug class of the 8051 mailbox prints */

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
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf(const char *fmt, ...);
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
 * Write length bytes into the 8051's EDID RAM (XDATA 0xF800, 2 KB) at ram_offset, as message type 1 in pieces of
 * 16 bytes.
 *
 *   ram_offset  where the block starts in the EDID RAM; only ram_offset / 16 is sent, so the block lands at the
 *               16-byte boundary at or below it
 *   length      number of bytes
 *   data        the bytes
 *
 * First queued messages are moved into the mailbox until the queue has room for the whole block. Piece n goes to
 * EDID RAM offset (ram_offset / 16 + n) * 16; the 8051 writes nothing for a piece that would pass the end of the
 * RAM ('EDID address out of range!'). After every piece the routine waits, without a time limit, until the queue
 * is empty and the 8051 has cleared all four slots. With debug class DBG_MAILBOX on, the offset / 16, the byte
 * count and the first eight bytes of each piece are printed.
 *
 * Called by startup_load_port_edids and edid_write_port_edid.
 */
void ipc_8051_write_port_memory(unsigned short ram_offset, unsigned short length, unsigned char * data)
{
    unsigned long words[4] = { 0, 0, 0, 0 };
    unsigned short offset;
    unsigned char count, offset_16, j, word_count;
    unsigned int piece_address;
    unsigned long *dest;

    wait_queue_empty(WAIT_ROOM, length);
    offset_16 = ram_offset >> 4;
    count = MSG_PIECE_BYTES;
    for (offset = 0; offset < length; offset += MSG_PIECE_BYTES) {
        if (length - offset < MSG_PIECE_BYTES)
            count = length - offset;
        if (dbg_is_print_enabled(DBG_MAILBOX))
            dbg_printf("ofst_u %x\r\n", offset_16);
        if (dbg_is_print_enabled(DBG_MAILBOX))
            dbg_printf("len_u %x ", count);
        piece_address = (unsigned int)data + offset;
        if (dbg_is_print_enabled(DBG_MAILBOX))
            dbg_printf("data : %02X %02X %02X %02X %02X %02X %02X %02X\r\n", ((unsigned char *)piece_address)[0], ((unsigned char *)piece_address)[1], ((unsigned char *)piece_address)[2], ((unsigned char *)piece_address)[3], ((unsigned char *)piece_address)[4], ((unsigned char *)piece_address)[5], ((unsigned char *)piece_address)[6], ((unsigned char *)piece_address)[7]);
        /* Four big-endian words: the 8051 unpacks them high byte first. */
        word_count = 4;
        dest = words;
        for (j = 0; j < word_count; j++) {
            dest[j] = ((unsigned char *)piece_address)[j * 4 + 0];
            dest[j] = (dest[j] << 8) + ((unsigned char *)piece_address)[j * 4 + 1];
            dest[j] = (dest[j] << 8) + ((unsigned char *)piece_address)[j * 4 + 2];
            dest[j] = (dest[j] << 8) + ((unsigned char *)piece_address)[j * 4 + 3];
        }
        /* Header: offset / 16 in bits 24..31, byte count in bits 16..23; no flags, no channel. */
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[0] = (offset_16 << 24) + (count << 16) + IPC_8051_MSG_EDID_MEMORY;
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[1] = words[0];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[2] = words[1];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[3] = words[2];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[4] = words[3];
        if (++ipc_8051_tx_queue_write_index > IPC_TX_QUEUE_LAST_INDEX)
            ipc_8051_tx_queue_write_index = 0;
        offset_16++;
        wait_queue_empty(WAIT_TAKEN, 0);
    }
}
