/* ipc_8051_send_wake_key_table  (FUN_a0136600)
 *
 * Queue the 60-byte table of standby keys and wake-up pins for the 8051 (message type 8).
 * Name basis: derived - ROM table chosen by mode plus two stored values; called from SYSAPI_PowerOff and
 *   SYSAPI_PowerSaving; message type 8; the handler in the 8051 program (FillKeyDetectList, original name)
 *   shows the content
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136600 @ 0xa0136600-0xa0136a10 (1040 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the message buffer is declared before the packed words (stack order);
 *  - the packed words and the packing pointer are unsigned long (the alias set of the queue stores); the packing
 *    loop compares with a limit variable word_count = 4;
 *  - the short-piece test is an unsigned compare, (unsigned int)(60 - offset) < 16;
 *  - the two prints have a debug class test each;
 *  - both waits are a static copy of ipc_8051_wait_tx_queue with all three modes, which -O3 inlines.
 */

#define IPC_PORTAL_8051          0      /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_TX_SLOTS        0x10   /* first slot for messages to the 8051 (docs/MAILBOX.md) */
#define IPC_SLOT_BYTES           20     /* one slot: header word and four data words */
#define IPC_TX_QUEUE_LAST_INDEX  0x24   /* queue indices run 0..0x24 */
#define IPC_TX_QUEUE_ROOM        36     /* entries that can be filled at most; one always stays empty */
#define MSG_PIECE_BYTES          16     /* most bytes one message carries */
#define IPC_8051_MSG_WAKE_KEYS   8      /* message type 8: the standby key and wake-up table (FillKeyDetectList) */
#define DBG_MAILBOX              0x20   /* debug class of the 8051 mailbox prints */

/* Layout of the 60-byte message (stored by the 8051 at XDATA 0xA5ED). */
#define WAKE_KEYS_BYTES          36     /* bytes 0..35: the ROM key list of the mode */
#define WAKE_TABLE_OFFSET        36     /* bytes 36..47: ipc_8051_wake_table */
#define WAKE_TABLE_SIZE          12
#define FIXED_WAKE_TABLE_OFFSET  48     /* bytes 48..59: ipc_8051_fixed_wake_table */
#define WAKE_KEY_MESSAGE_BYTES   60

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
extern const unsigned char ipc_8051_wake_keys_mode0[], ipc_8051_wake_keys_mode1[];
extern unsigned char ipc_8051_wake_table[], ipc_8051_fixed_wake_table[];
extern void ipc_8051_build_wake_table(void);
extern void ipc_8051_build_fixed_wake_table(void);
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf(const char *fmt, ...);
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
 * Build the 60-byte standby key and wake-up table and send it to the 8051 as message type 8, which stores it at
 * XDATA 0xA5ED (FillKeyDetectList, 'KeyDetArray OOR' past 60 bytes).
 *
 *   mode  0: bytes 0..35 are ipc_8051_wake_keys_mode0; 1: ipc_8051_wake_keys_mode1; any other value leaves
 *         them 0. Both callers pass byte 0x33 of the system configuration record.
 *
 * First the two pin tables are rebuilt (ipc_8051_build_wake_table, ipc_8051_build_fixed_wake_table); they become
 * bytes 36..47 and 48..59. The message goes out in four pieces (16, 16, 16 and 12 bytes; piece n at table offset
 * 16 * n). The room wait before queueing asks for 48 bytes (three entries), not for the 60 bytes (four entries)
 * that are then queued. With debug class DBG_MAILBOX on, each piece is printed as two lines of eight bytes;
 * for the last piece this includes buffer bytes 60..63, which stay 0. The routine returns only when the queue is empty and the 8051
 * has cleared all four slots.
 *
 * Called from SYSAPI_PowerOff and SYSAPI_PowerSaving, each time right before ipc_8051_send_power_cut_table.
 */
void ipc_8051_send_wake_key_table(unsigned char mode)
{
    unsigned char table[64] = { 0 };
    unsigned long words[4] = { 0, 0, 0, 0 };
    unsigned short i, offset;
    unsigned char count = MSG_PIECE_BYTES, offset_16 = 0, j, word_count;
    unsigned char *piece;
    unsigned long *dest;

    ipc_8051_build_wake_table();
    ipc_8051_build_fixed_wake_table();
    if (mode == 0) {
        for (i = 0; i < WAKE_KEYS_BYTES; i++)
            table[i] = ipc_8051_wake_keys_mode0[i];
    } else if (mode == 1) {
        for (i = 0; i < WAKE_KEYS_BYTES; i++)
            table[i] = ipc_8051_wake_keys_mode1[i];
    }
    for (i = 0; i < WAKE_TABLE_SIZE; i++)
        table[WAKE_TABLE_OFFSET + i] = ipc_8051_wake_table[i];
    for (i = 0; i < WAKE_TABLE_SIZE; i++)
        table[FIXED_WAKE_TABLE_OFFSET + i] = ipc_8051_fixed_wake_table[i];
    wait_queue_empty(WAIT_ROOM, 48);
    for (offset = 0; offset < WAKE_KEY_MESSAGE_BYTES; offset += MSG_PIECE_BYTES) {
        if ((unsigned int)(WAKE_KEY_MESSAGE_BYTES - offset) < MSG_PIECE_BYTES)
            count = WAKE_KEY_MESSAGE_BYTES - offset;
        if (dbg_is_print_enabled(DBG_MAILBOX))
            dbg_printf("data : %02X %02X %02X %02X %02X %02X %02X %02X\r\n", table[offset], table[offset + 1], table[offset + 2], table[offset + 3], table[offset + 4], table[offset + 5],
                         table[offset + 6], table[offset + 7]);
        if (dbg_is_print_enabled(DBG_MAILBOX))
            dbg_printf("data : %02X %02X %02X %02X %02X %02X %02X %02X\r\n", table[offset + 8], table[offset + 9], table[offset + 10], table[offset + 11], table[offset + 12],
                         table[offset + 13], table[offset + 14], table[offset + 15]);
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
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].words[0] = (offset_16 << 24) + (count << 16) + IPC_8051_MSG_WAKE_KEYS;
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
