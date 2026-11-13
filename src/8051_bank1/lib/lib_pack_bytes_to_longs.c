/* lib_pack_bytes_to_longs  (FUN_CODE_5868)
 *
 * Pack a byte buffer into 32-bit words, first byte most significant.
 *   bytes
 *   words
 *   count: byte count
 * Name basis: proven - code: q[i] = p[4i..4i+3] big-endian for (n + 3) / 4 words
 *
 * Matching notes
 * --------------
 * 8051_bank1 module FUN_CODE_5868: ipc_fill_report_record @ 0x38A7..0x3C4D and lib_pack_bytes_to_longs @
 * 0x5868..0x5A39 with the common-entry block lib_pack_bytes_to_longs_entry @ 0x5864..0x5868; one compile with OPTIMIZE(8,SPEED)
 * LARGE (c51opts). Source forms the exact build depends on:
 * - Both routines stay in this file: the block 0x5864 'MOV R2,#0A4H / MOV R1,#97H' loads the low two bytes of the
 *   generic pointer to collected[] (XDATA 0xA497) and falls into lib_pack_bytes_to_longs; its only users are the
 *   three calls at 0x3A67, 0x3BBC and 0x3C49, and Keil builds such a block only from calls inside the module.
 * - LARGE locals of ipc_fill_report_record: i 0xA494, j 0xA495, channel 0xA496, collected[128] 0xA497..0xA516.
 *   lib_pack_bytes_to_longs: bytes (generic pointer) 0xA517..0xA519, words (generic pointer) 0xA51A..0xA51C,
 *   count 0xA51D..0xA51E, i 0xA51F, word_count 0xA520; the packing goes through ?C?LLDOPTR / ?C?LSHL / ?C?LSTOPTR.
 * - XDATA 0xA3E3..0xA46E is one structure (struct ipc_report_area): Keil reaches 0xA3E5/0xA3E6, 0xA3E8/0xA3E9
 *   and 0xA46C/0xA46D with INC DPTR, as for members of one object.
 * - 'reported_mask |= 1 << channel' is written through the copies reported and port.
 * - The array 'collected' must not share its name with the parameter 'bytes' of lib_pack_bytes_to_longs: with
 *   the same name for both LARGE slots of the module the exact check of ipc_fill_report_record fails.
 */
/* The report area at 0xA3E3; it begins with the byte named uart_rx_reported_mask. */
#define report_area uart_rx_reported_mask
struct ipc_report_area {
    unsigned char reported_mask;    /* 0xA3E3: serial ports whose data sits in a mailbox slot */
    unsigned char i2c_channel;      /* 0xA3E4: channel of the I2C read result */
    unsigned char word_count;       /* 0xA3E5: data words of the report */
    unsigned char position;         /* 0xA3E6: next data word to send (ipc_build_report_message) */
    unsigned char type;             /* 0xA3E7: message type, bits 0..3 of each piece's header */
    unsigned char channel;          /* 0xA3E8: header bits 8..15 */
    unsigned char flags;            /* 0xA3E9: header bits 4..7; bit 0 = last piece */
    unsigned int length;            /* 0xA3EA: bytes still to send; 0 = the area is free */
    unsigned long data_words[32];   /* 0xA3EC: the bytes, four per word, first byte most significant */
    unsigned char edid_count;       /* 0xA46C: EDID read-back byte count (command 0x0D) */
    unsigned char edid_offset;      /* 0xA46D: EDID read-back start in 16-byte units */
    unsigned char i2c_length;       /* 0xA46E: bytes of the I2C read result */
};
extern struct ipc_report_area xdata report_area;
extern unsigned char xdata ddc_request_buffers[4][0x3c];
extern unsigned char xdata edid_ram[];
extern unsigned char xdata i2c_transfer_data[];
extern unsigned char xdata i2c_result_ready_flag;
extern unsigned char idata ddc_request_index_port0[];
extern void lib_printf517(void *fmt, ...) large;
bit ipc_test_report_slot_free(void);
bit ddc_test_none_pending(void);
unsigned char ddc_get_first_pending_channel(void);
bit uart_test_no_rx_data(void);
unsigned char uart_find_port_with_rx_data(void);
bit uart_test_rx_reported(unsigned char n);
bit edid_test_readback_requested(void);
bit i2c_test_no_result_ready(void);
bit sys_ir_ring_test_empty(void);
unsigned char sys_ir_ring_is_empty(void);
unsigned char sys_ir_ring_read_byte(void);
unsigned char uart_read_rx_ring(unsigned char ch, unsigned char *buf);
void ddc_clear_pending_channel(unsigned char n);
void lib_pack_bytes_to_longs(unsigned char *bytes, unsigned long *words, unsigned int count);

/* Message types from the 8051 to the main processor (docs/MAILBOX.md). */
#define IPC_8051_MSG_EDID_MEMORY  1
#define IPC_8051_MSG_I2C          2
#define IPC_8051_MSG_UART         3
#define IPC_8051_MSG_DDCCI        4
#define IPC_8051_MSG_IR           5
#define REPORT_FLAG_2             2     /* set for DDC/CI and I2C reports (header bit 5) */
#define CHANNEL_NONE              0xFF
#define DDC_ROW_LAST              0x3B  /* odd DDC/CI ports fill their row from here downwards */
#define IR_MAX_BYTES              0x80

/* ipc_fill_report_record - when the report area is free, fill it with the next thing to report to the main
 * processor. ipc_build_report_message calls it before and after it sends a piece and cuts the area into
 * 16-byte pieces.
 *
 * Sources, in order of priority (the first that applies is taken):
 *   1. DDC/CI (type 4): a port with a pending request. Its bytes come from the port's row of
 *      ddc_request_buffers: an even port from index 0 up to its write index, an odd port from index 0x3B down to
 *      just above its write index, so the report holds them in arrival order. The pending mark is cleared. When
 *      a request is pending, nothing else is reported in this call, even when that port has no bytes.
 *   2. Serial ports (type 3): a port with received data that is not reported yet. The port's bit is set in
 *      reported_mask.
 *   3. EDID read-back (type 1): edid_count bytes of edid_ram from 16 * edid_offset; then both are cleared.
 *   4. I2C read result (type 2): i2c_length bytes of i2c_transfer_data; i2c_result_ready_flag is cleared.
 *   5. Infrared (type 5): up to 128 bytes from the IR ring; prints "Reload IR".
 * Each source sets the type, the length and the word count, resets the send position and packs the bytes into
 * data_words with lib_pack_bytes_to_longs.
 */
void ipc_fill_report_record(void)
{
    unsigned char i, j, channel;
    unsigned char collected[128];
    unsigned int edid_row;
    unsigned char reported, port;

    channel = CHANNEL_NONE;
    if (!ipc_test_report_slot_free()) return;
    if (!ddc_test_none_pending()) {
        /* 1. DDC/CI request; an even port's index counts up from 0, an odd port's down from 0x3B. */
        channel = ddc_get_first_pending_channel();
        if (channel != CHANNEL_NONE && ((!(channel & 1) && ddc_request_index_port0[channel] != 0) || ((channel & 1) && ddc_request_index_port0[channel] != DDC_ROW_LAST))) {
            report_area.type = IPC_8051_MSG_DDCCI;
            if (channel & 1) {
                for (i = DDC_ROW_LAST, j = 0; i > ddc_request_index_port0[channel]; i--, j++)
                    collected[j] = ddc_request_buffers[channel >> 1][i];
            } else {
                for (i = 0, j = 0; i < ddc_request_index_port0[channel]; i++, j++)
                    collected[i] = ddc_request_buffers[channel >> 1][i];
            }
            report_area.length = j;
            report_area.word_count = (report_area.length + 3) >> 2;
            report_area.position = 0;
            report_area.channel = channel;
            report_area.flags = REPORT_FLAG_2;
            ddc_clear_pending_channel(channel);
            lib_pack_bytes_to_longs(collected, report_area.data_words, report_area.length);
        }
    } else if (!uart_test_no_rx_data() && (channel = uart_find_port_with_rx_data()) != CHANNEL_NONE && !uart_test_rx_reported(channel)) {
        /* 2. Received serial bytes. */
        report_area.type = IPC_8051_MSG_UART;
        report_area.length = uart_read_rx_ring(channel, collected);
        report_area.word_count = (report_area.length + 3) >> 2;
        report_area.position = 0;
        report_area.channel = channel;
        lib_pack_bytes_to_longs(collected, report_area.data_words, report_area.length);
        reported = report_area.reported_mask;
        port = channel;
        report_area.reported_mask = reported | (1 << port);
    } else if (edid_test_readback_requested()) {
        /* 3. EDID RAM read-back. */
        report_area.type = IPC_8051_MSG_EDID_MEMORY;
        edid_row = report_area.edid_offset;
        for (i = 0; i < report_area.edid_count; i++)
            collected[i] = edid_ram[i + (edid_row << 4)];
        report_area.length = report_area.edid_count;
        report_area.word_count = (report_area.length + 3) >> 2;
        report_area.position = 0;
        report_area.edid_count = 0;
        report_area.edid_offset = 0;
        lib_pack_bytes_to_longs(collected, report_area.data_words, report_area.length);
    } else if (!i2c_test_no_result_ready()) {
        /* 4. I2C read result. */
        report_area.type = IPC_8051_MSG_I2C;
        for (i = 0; i < report_area.i2c_length; i++)
            collected[i] = i2c_transfer_data[i];
        report_area.length = report_area.i2c_length;
        report_area.word_count = (report_area.length + 3) >> 2;
        report_area.position = 0;
        report_area.channel = report_area.i2c_channel;
        report_area.flags = REPORT_FLAG_2;
        lib_pack_bytes_to_longs(collected, report_area.data_words, report_area.length);
        i2c_result_ready_flag = 0;
    } else if (!sys_ir_ring_test_empty()) {
        /* 5. Infrared pulse lengths, until the ring is empty or 128 bytes are taken. */
        lib_printf517((void code *)0x55e9);   /* "Reload IR\r\n" */
        report_area.type = IPC_8051_MSG_IR;
        for (i = 0; i < IR_MAX_BYTES; i++) {
            if (sys_ir_ring_is_empty() != 0) break;
            collected[i] = sys_ir_ring_read_byte();
        }
        report_area.length = i;
        report_area.word_count = (report_area.length + 3) >> 2;
        report_area.position = 0;
        lib_pack_bytes_to_longs(collected, report_area.data_words, report_area.length);
    }
}

/* lib_pack_bytes_to_longs - pack 'count' bytes into (count + 3) / 4 words, four bytes per word with the first
 * byte in bits 24..31. The last word reads up to three bytes past the end of 'bytes'.
 */
void lib_pack_bytes_to_longs(unsigned char *bytes, unsigned long *words, unsigned int count)
{
    unsigned char i, word_count;

    word_count = (count + 3) >> 2;
    for (i = 0; i < word_count; i++) {
        words[i] = bytes[i * 4];
        words[i] = (words[i] << 8) + bytes[i * 4 + 1];
        words[i] = (words[i] << 8) + bytes[i * 4 + 2];
        words[i] = (words[i] << 8) + bytes[i * 4 + 3];
    }
}
