/* ipc_8051_send_usb_c_info  (FUN_a0136054)
 *
 * Queue the ten-byte description of the USB-C port for the 8051 (message type 0x0B).
 * Name basis: derived - built from the port tables; called from SYSAPI_PowerSaving; message type 11; the
 *   handler in the 8051 program (FillTypeCInfo, original name) shows the content
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136054 @ 0xa0136054-0xa0136384 (816 bytes), flags -mcpu=v8 -O3 -g.
 * wait_queue is ipc_8051_wait_tx_queue of another file, written here as a static copy that GCC inlines at -O3
 * (its mode 1 and mode 3 bodies remain).
 * Source forms the exact build depends on: as ipc_8051_send_power_cut_table (message buffer declared before words,
 * words unsigned long); byte0_bit2 = 1 at its declaration and 'if (port_index != 5) byte0_bit2 = port_index != 6;';
 * order is a two-word array (8-byte stack slot); declaration order port_index, byte0_bit2, chunk_bytes, chunk.
 */
/* One entry of the queue of messages to the 8051: header word and four data words, as in a mailbox slot. */
struct ipc_8051_tx_entry { unsigned int word[5]; };

#define IPC_8051_TX_MSG_USB_C_INFO  0x0b    /* message type 11: the 8051 stores it with FillTypeCInfo */
#define IPC_8051_TX_QUEUE_LAST      0x24    /* queue indices run 0..0x24 */
#define IPC_8051_TX_QUEUE_ROOM      36      /* entries that can wait at once (one stays empty) */
#define MSG_PIECE_BYTES             16      /* data bytes per message: four words */
#define USB_C_INFO_BYTES            10
#define PORT_INDEX_NONE             0xff

/* Mailbox portal 0: the four slots of messages to the 8051 start at +0x10, 20 bytes apart. */
#define IPC_8051_PORTAL             0
#define IPC_8051_RX_SLOT_FIRST      16
#define IPC_8051_RX_SLOT_SIZE       20
#define IPC_8051_RX_SLOT_LAST       0x50    /* a slot offset above this is past the fourth slot */

enum { WAIT_QUEUE_ROOM = 1, WAIT_QUEUE_EMPTY = 2, WAIT_QUEUE_TAKEN = 3 };

extern unsigned char ipc_8051_tx_queue_read_index, ipc_8051_tx_queue_write_index;
extern struct ipc_8051_tx_entry ipc_8051_tx_queue[];
extern unsigned char input_port_table_find_flagged_type2(void);
extern unsigned char input_find_port_entry_by_bus_id(unsigned char);
extern unsigned char input_entry_index_to_port_code(unsigned char);
extern unsigned char input_port_code_to_receiver_index(unsigned char);
extern void input_port_table_get_link_bytes(unsigned char, unsigned int *);
extern int dbg_printf(const char *fmt, ...);
extern const char s_001a5540[], s_001a5550[];   /* "port_idx %d\r\n", "data : %02X %02X ... (8 bytes)\r\n" */
extern void ipc_8051_tx_queue_flush(void);
extern void ipc_mailbox_read(unsigned char, unsigned char, unsigned int *, unsigned char);

/*
 * WAIT_QUEUE_ROOM: flush the queue until it has room for bytes data bytes (16 per free entry).
 * WAIT_QUEUE_EMPTY: flush until the queue is empty.
 * WAIT_QUEUE_TAKEN: flush until the queue is empty, then wait until the header words of the four mailbox slots
 * read 0 (the 8051 clears a slot's header once it has carried the message out).
 */
static void wait_queue(unsigned char mode, unsigned short bytes)
{
    unsigned int header = 0;
    unsigned int any_header;
    unsigned char i;
    unsigned short free_entries;

    switch (mode) {
    case WAIT_QUEUE_ROOM:
        for (;;) {
            if (ipc_8051_tx_queue_write_index > ipc_8051_tx_queue_read_index)
                free_entries = ipc_8051_tx_queue_read_index - ipc_8051_tx_queue_write_index + IPC_8051_TX_QUEUE_ROOM;
            else if (ipc_8051_tx_queue_write_index >= ipc_8051_tx_queue_read_index)
                free_entries = IPC_8051_TX_QUEUE_ROOM;
            else
                free_entries = ipc_8051_tx_queue_read_index - ipc_8051_tx_queue_write_index - 1;
            if (bytes <= (unsigned short)(free_entries << 4))
                break;
            ipc_8051_tx_queue_flush();
        }
        break;
    case WAIT_QUEUE_EMPTY:
        while (ipc_8051_tx_queue_write_index != ipc_8051_tx_queue_read_index)
            ipc_8051_tx_queue_flush();
        break;
    case WAIT_QUEUE_TAKEN:
        while (ipc_8051_tx_queue_write_index != ipc_8051_tx_queue_read_index)
            ipc_8051_tx_queue_flush();
        do {
            any_header = 0;
            for (i = 0; i * IPC_8051_RX_SLOT_SIZE + IPC_8051_RX_SLOT_FIRST <= IPC_8051_RX_SLOT_LAST; i++) {
                ipc_mailbox_read(IPC_8051_PORTAL, i * IPC_8051_RX_SLOT_SIZE + IPC_8051_RX_SLOT_FIRST, &header, 1);
                any_header |= header;
            }
        } while (any_header != 0);
        break;
    }
}

/*
 * Send the 8051 the ten-byte USB-C port description (message type 11, docs/MAILBOX.md); the 8051 stores it at
 * XDATA 0xA69C (FillTypeCInfo). Called by SYSAPI_PowerSaving.
 *
 * Phases:
 *   1. Find the input: the first type 2 entry of the port table with flag 0x400 (input_port_table_find_flagged_type2).
 *      Its index is printed; with none (0xFF) nothing is sent. A chain of port look-ups follows whose result is
 *      not used.
 *   2. Build the ten bytes:
 *        0  0xF6, or 0xF2 for port table index 6
 *        1  0x60 | bit 11 of the entry's halfword +0x14
 *        2..8  0xFF, 1, 2, 1, 0xFF, 1, 1
 *        9  bits 8..9 of the entry's halfword +0x14
 *      (the 8051 side keeps bytes 0, 1 and 9 as bit groups; the meaning of the fields is not shown).
 *   3. Wait for room in the queue, then queue the bytes in 16-byte pieces (here one piece), each printed first.
 *      Header of a piece: piece number << 24, byte count << 16, message type.
 *   4. Wait until the queue is empty and the 8051 has taken every message.
 */
void ipc_8051_send_usb_c_info(void)
{
    unsigned char message[14] = { 0 };
    unsigned long words[4] = { 0, 0, 0, 0 };
    unsigned short offset;
    unsigned char port_index, byte0_bit2 = 1, chunk_bytes = MSG_PIECE_BYTES, chunk = 0, j, word_count;
    unsigned int order[2];                  /* bytes +0x12..+0x15 of the port table entry */
    unsigned char *src;
    unsigned long *dst;

    /* Phase 1. */
    port_index = input_port_table_find_flagged_type2();
    dbg_printf(s_001a5540, port_index);
    if (port_index == PORT_INDEX_NONE)
        return;
    input_port_code_to_receiver_index(input_entry_index_to_port_code(input_find_port_entry_by_bus_id(port_index)));
    input_port_table_get_link_bytes(port_index, order);

    /* Phase 2. */
    if (port_index != 5)
        byte0_bit2 = port_index != 6;
    message[0] = (byte0_bit2 << 2) | 0xf2;
    message[1] = ((order[0] >> 11) & 1) | 0x60;
    message[2] = 0xff;
    message[3] = 1;
    message[4] = 2;
    message[5] = 1;
    message[6] = 0xff;
    message[7] = 1;
    message[8] = 1;
    message[9] = (order[0] >> 8) & 3;

    /* Phase 3. */
    wait_queue(WAIT_QUEUE_ROOM, USB_C_INFO_BYTES);
    for (offset = 0; offset < USB_C_INFO_BYTES; offset += MSG_PIECE_BYTES) {
        if (USB_C_INFO_BYTES - offset < MSG_PIECE_BYTES)
            chunk_bytes = USB_C_INFO_BYTES - offset;
        dbg_printf(s_001a5550, message[offset], message[offset + 1], message[offset + 2], message[offset + 3], message[offset + 4], message[offset + 5],
                     message[offset + 6], message[offset + 7]);
        /* Pack the piece big-endian into four words. */
        src = message + offset;
        word_count = 4;
        dst = words;
        for (j = 0; j < word_count; j++) {
            dst[j] = src[j * 4];
            dst[j] = (dst[j] << 8) + src[j * 4 + 1];
            dst[j] = (dst[j] << 8) + src[j * 4 + 2];
            dst[j] = (dst[j] << 8) + src[j * 4 + 3];
        }
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].word[0] = (chunk << 24) + (chunk_bytes << 16) + IPC_8051_TX_MSG_USB_C_INFO;
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].word[1] = words[0];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].word[2] = words[1];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].word[3] = words[2];
        ipc_8051_tx_queue[ipc_8051_tx_queue_write_index].word[4] = words[3];
        if (++ipc_8051_tx_queue_write_index > IPC_8051_TX_QUEUE_LAST)
            ipc_8051_tx_queue_write_index = 0;
        chunk++;
    }

    /* Phase 4. */
    wait_queue(WAIT_QUEUE_TAKEN, 0);
}
