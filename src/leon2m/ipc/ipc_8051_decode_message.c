/* ipc_8051_decode_message  (FUN_a013497c)
 *
 * Sort a message from the 8051 into the EDID, I2C, UART or infrared buffer.
 * Name basis: proven - portal 0 message decoder with one branch per message kind
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013497c @ 0xa013497c-0xa0134de0 (1124 bytes, 281 insns), flags -mcpu=v8 -O3 -g (the same bytes
 * also come out with -msoft-float).
 * Source forms the exact build depends on:
 *  (1) order of the header extractions: byte_count first, then flags, type, port, piece (piece last: its shift
 *      ends the life of header), and only THEN the block with 'bytes[16] = {0}'. With the initialiser before the
 *      extractions the scheduler keeps the second zero store early and the 64-bit zero pair takes %o4/%o5
 *      (firmware %o2/%o3);
 *  (2) TWO count variables: byte_count (unsigned char) is clamped in place and used by the loops and the type 1
 *      range check (firmware %l0); count = byte_count is an unsigned short used for the unpack call and the totals
 *      (firmware %l3, zero-extended; 'offset + count' keeps offset first);
 *  (3) type 2 computes the total into an unsigned char temporary BEFORE the debug print (firmware: the add sits in
 *      the bne delay slot after the call);
 *  (4) type 4 writes 'count + offset' and stores port, length, ready in that order;
 *  (5) type 1 is 'if (in range) { ... } else { error }'; the early-break form leaves the error text in %l0
 *      (firmware %l5);
 *  (6) offset = piece * 16 is unsigned short ('and 0xff0'); the unpack loop is an inlined static function with an
 *      unsigned short count; the ring's next index is unsigned int, masked with 0x1f at the compare with the read
 *      index (0xa0134c78) and at the store of the write index.
 * dbg_is_print_enabled returns unsigned char; dbg_printf is declared K&R style returning int.
 */
/* Message types from the 8051 (docs/MAILBOX.md, "Messages from the 8051"). */
enum {
    IPC_8051_MSG_NONE        = 0,
    IPC_8051_MSG_EDID_MEMORY = 1,           /* read-back of the EDID RAM, asked for with command 0x0D */
    IPC_8051_MSG_I2C         = 2,           /* result of an I2C read */
    IPC_8051_MSG_UART        = 3,           /* bytes received on a serial port */
    IPC_8051_MSG_DDCCI       = 4,           /* a DDC/CI request a computer sent */
    IPC_8051_MSG_IR          = 5            /* infrared pulse lengths */
};

#define MSG_FLAG_LAST_PIECE     1           /* flags = header bits 4..7; bit 4 marks the last piece */
#define MSG_PIECE_BYTES         16          /* data bytes per message: four words */
#define RX_BLOCK_LAST_OFFSET    0x7fe       /* offset + byte count above this is out of range */
#define UART_PORT_LAST          4           /* rings 0..4 */
#define UART_RING_MASK          0x1f        /* 32-byte rings */
#define IR_BUFFER_SIZE          0x40
#define DBG_MAILBOX            0x20        /* debug class of the 8051 mailbox prints */

/* Receive ring of one serial port. */
struct uart_rx_ring {
    unsigned char write_index;
    unsigned char read_index;
    unsigned char data[32];
    unsigned char overflow;                 /* set when a write catches up with the read index */
};

/* A DDC/CI request received from the 8051. */
struct ddc_request {
    unsigned char port;                     /* +0 */
    unsigned char pad;
    unsigned short length;                  /* +2 */
    unsigned char data[0x80];               /* +4 */
    unsigned char ready;                    /* +0x84: 1 = complete */
};

extern struct uart_rx_ring uart_rx_rings[];
extern struct ddc_request ddc_rx_request;
extern unsigned char ipc_8051_rx_block_buffer[];
extern unsigned char ipc_ir_rx_buffer[];
extern unsigned short ipc_ir_rx_buffer_count;
extern unsigned char ipc_8051_rx_block_length, ipc_8051_rx_block_ready_flag, ipc_8051_rx_block2_length, ipc_8051_rx_block2_ready_flag;
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf();

/* Unpack the data words big-endian (first byte = bits 24..31), whole words only. */
static void unpack(unsigned char *dst, unsigned int *src, unsigned short count)
{
    unsigned char i;
    unsigned char words = (count + 3) / 4;
    for (i = 0; i < words; i++) {
        dst[i * 4] = src[i] >> 24;
        dst[i * 4 + 1] = src[i] >> 16;
        dst[i * 4 + 2] = src[i] >> 8;
        dst[i * 4 + 3] = src[i];
    }
}

/*
 * Sort one message from the 8051 into its buffer. Called by ipc_8051_poll_messages for each filled slot of
 * mailbox portal 0; msg points to the slot's five words.
 *
 * Header word: type bits 0..3, flags bits 4..7 (bit 4 = last piece), port / channel bits 8..15, byte count bits
 * 16..23 (16 at most), piece number bits 24..31. A longer block comes in 16-byte pieces; piece n lands at offset
 * n * 16 of its buffer.
 *
 * Phases:
 *   1. Split the header, unpack the data words into 16 bytes, clamp the byte count to 16.
 *   2. By type:
 *      1 EDID memory: into ipc_8051_rx_block_buffer when it fits (offset + count <= 0x7FE, else a debug error);
 *        the last piece sets ipc_8051_rx_block_length to the total and the ready flag.
 *      2 I2C: into the same buffer without a range check; the last piece sets ipc_8051_rx_block2_length and its
 *        ready flag.
 *      3 serial port: append to the 32-byte ring of that port (0..4); the overflow flag is set when the write
 *        index reaches the read index.
 *      4 DDC/CI: into ddc_rx_request.data; the last piece stores port, length and ready = 1.
 *      5 infrared: append to the 64-byte buffer ipc_ir_rx_buffer (stops when it is full) and dump the bytes.
 *      Type 0 and types above 5 do nothing.
 */
void ipc_8051_decode_message(unsigned int *msg)
{
    unsigned int header;
    unsigned char type, flags, port, byte_count, piece, i;
    unsigned int next;
    unsigned short offset; unsigned short count;

    /* Phase 1. */
    header = msg[0];
    byte_count = header >> 16;
    flags = (header >> 4) & 0xf;
    type = header & 0xf;
    port = header >> 8;
    piece = header >> 24;
    {
    unsigned char bytes[MSG_PIECE_BYTES] = {0};
    if (byte_count > MSG_PIECE_BYTES) byte_count = MSG_PIECE_BYTES;
    count = byte_count;
    unpack(bytes, &msg[1], count);
    offset = piece * MSG_PIECE_BYTES;

    /* Phase 2. */
    switch (type) {
    case IPC_8051_MSG_NONE:
        break;
    case IPC_8051_MSG_EDID_MEMORY:
        if (offset + byte_count <= RX_BLOCK_LAST_OFFSET) {
            if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("EDID%d\r\n", 1);
            for (i = 0; i < byte_count; i++) {
                ipc_8051_rx_block_buffer[offset + i] = bytes[i];
                if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("%x ", bytes[i]);
            }
            if (flags & MSG_FLAG_LAST_PIECE) {
                ipc_8051_rx_block_length = offset + count;
                ipc_8051_rx_block_ready_flag = 1;
            }
        } else {
            if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("EDID address out of range! %d\r\n", 1);
        }
        break;
    case IPC_8051_MSG_I2C:
        for (i = 0; i < byte_count; i++)
            ipc_8051_rx_block_buffer[offset + i] = bytes[i];
        if (flags & MSG_FLAG_LAST_PIECE) {
            unsigned char total = offset + count;
            if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("I2C%x\r\n", port);
            ipc_8051_rx_block2_length = total;
            ipc_8051_rx_block2_ready_flag = 1;
        }
        break;
    case IPC_8051_MSG_UART:
        if (port > UART_PORT_LAST) {
            dbg_printf("UART buf index over!");
            break;
        }
        for (i = 0; i < byte_count; i++) {
            uart_rx_rings[port].data[uart_rx_rings[port].write_index] = bytes[i];
            next = uart_rx_rings[port].write_index + 1;
            /* The byte is stored even when the ring is full; only the flag records it. */
            if ((next & UART_RING_MASK) == uart_rx_rings[port].read_index) uart_rx_rings[port].overflow = 1;
            uart_rx_rings[port].write_index = next & UART_RING_MASK;
        }
        break;
    case IPC_8051_MSG_DDCCI:
        for (i = 0; i < byte_count; i++)
            ddc_rx_request.data[offset + i] = bytes[i];
        if (flags & MSG_FLAG_LAST_PIECE) {
            ddc_rx_request.port = port;
            ddc_rx_request.length = count + offset;
            ddc_rx_request.ready = 1;
        }
        break;
    case IPC_8051_MSG_IR:
        for (i = 0; i < byte_count; i++) {
            if (ipc_ir_rx_buffer_count > IR_BUFFER_SIZE - 1) break;
            ipc_ir_rx_buffer[ipc_ir_rx_buffer_count] = bytes[i];
            ipc_ir_rx_buffer_count++;
        }
        if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("IR%x ", 0);
        for (i = 0; i < byte_count; i++)
            if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("%x ", bytes[i]);
        if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("%x\r\n", 1);
        break;
    }
    }
}
