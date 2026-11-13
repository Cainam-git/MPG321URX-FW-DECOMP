/* ipc_run_message  (FUN_CODE_1c3c)
 *
 * Carry out one message from the main processor according to its type.
 *   msg: five-word message
 * Note: Types: 1 EDID RAM, 2 I2C, 3 serial ports, 4 DDC/CI reply, 6 command list, 7 flash data, 8/9/10 power
 *   tables, 11 Type-C info.
 * Name basis: proven - prints 'EDID address out of range!', 'DATA_I2C OOR', 'DATA_DDCCI OOR', 'DataTest';
 *   types match the main side's senders
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE over 0x1C3C..0x224F (1555 bytes). The parameter msg sits in the LARGE block at
 * XDATA 0xA48E..0xA490; the locals follow in declaration order: msg_type 0xA491, flags 0xA492, channel 0xA493,
 * count 0xA494, offset_16 0xA495, i 0xA496, offset 0xA497..0xA498, payload[16] 0xA499..0xA4A8.
 * Source forms the exact build depends on:
 * - ddc_reply_rows_from_end and ddc_reply_buffers are declared with a fixed size ([4][0x3C]), which makes Keil
 *   compute the row offset in 8 bits (MUL AB, CLR A / ADDC).
 * - The DDC/CI case ends with 'if (!(flags & MSG_FLAG_LAST_PIECE)) return;', the firmware's second test of that
 *   bit (JNB to a RET, else LJMP to the shared RET).
 * - 0xF00A is a chip register (volatile).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata edid_ram[];
extern unsigned char xdata i2c_transfer_buffer[];
extern unsigned char xdata ddc_reply_rows_from_end[4][0x3c];
extern unsigned char xdata ddc_reply_buffers[4][0x3c];
extern unsigned char xdata i2c_result_channel, i2c_result_ready_flag, i2c_result_length;
extern unsigned long xdata DAT_EXTMEM_a51a, DAT_EXTMEM_a51e, DAT_EXTMEM_a522, DAT_EXTMEM_a526, DAT_EXTMEM_a52a;
extern unsigned char idata ddc_reply_end_indexes[];
extern void lib_printf517(void *fmt, ...) large;
extern void lib_unpack_longs_to_bytes(unsigned char *dst, unsigned char *src, unsigned int n);
extern void i2c_write_eeprom_pages(unsigned char a, unsigned char b, unsigned char c, unsigned char *p, unsigned int n);
extern void i2c_master_write_read(unsigned char a, unsigned char b, unsigned int c, unsigned char *p, unsigned int n);
extern unsigned char uart_putchar(unsigned char c);
extern void uart_queue_tx_byte_port2(unsigned char v);
extern void uart_queue_tx_byte_port3(unsigned char v);
extern void uart_queue_tx_byte_port4(unsigned char v);
extern void uart_flush_tx_queue_port2(void);
extern void uart_flush_tx_queue_port3(void);
extern void uart_flush_tx_queue_port4(void);
extern void ipc_run_command(unsigned long p);
extern void ipc_store_flash_data(unsigned int off, unsigned int n, unsigned char *p);
extern unsigned long ipc_sum_flash_data(void);
extern void ipc_post_result_word(unsigned long v);
extern void FillKeyDetectList(unsigned int off, unsigned char n, unsigned char *p);
extern void ipc_store_wake_port_list(unsigned int off, unsigned char n, unsigned char *p);
extern void ipc_store_power_cut_list(unsigned int off, unsigned char n, unsigned char *p);
extern void FillTypeCInfo(unsigned char *p);

/* Message types from the main processor (docs/MAILBOX.md, "Messages to the 8051"); 5, 12, 13 and 14 are ignored. */
#define IPC_8051_TX_MSG_EDID_MEMORY 1
#define IPC_8051_TX_MSG_I2C         2
#define IPC_8051_TX_MSG_UART        3
#define IPC_8051_TX_MSG_DDCCI       4
#define IPC_8051_TX_MSG_COMMANDS    6
#define IPC_8051_TX_MSG_FLASH_DATA  7
#define IPC_8051_TX_MSG_WAKE_KEYS   8
#define IPC_8051_TX_MSG_WAKE_PORTS  9
#define IPC_8051_TX_MSG_POWER_CUT   10
#define IPC_8051_TX_MSG_USB_C_INFO  11
#define IPC_8051_TX_MSG_TEST        15

#define MSG_FLAG_LAST_PIECE 1       /* bit 0 of the flags field (header bit 4) */
#define MSG_PIECE_BYTES     16      /* data bytes in one message at most */
#define I2C_PAGE_WRITE_READ 0x80    /* channel byte bit 7: write-then-read instead of a page write */
#define EDID_RAM_SIZE       0x800   /* edid_ram at XDATA 0xF800 */
#define I2C_BUFFER_SIZE     0x80
#define DDC_ROW_SIZE        0x3c    /* one row of ddc_reply_buffers, shared by an even and an odd port */

/*
 * ipc_run_message - carry out one message that the main processor left in a mailbox slot.
 *   msg  the slot: header word, then four data words
 * Header word (docs/MAILBOX.md): type bits 0..3, flags bits 4..7 (bit 4 = last piece), port / channel bits 8..15,
 * byte count bits 16..23 (16 at most), offset / 16 bits 24..31. The data words are unpacked into payload[] high byte
 * first.
 * Called by ipc_service_mailbox for each filled slot; the caller clears the header afterwards.
 *
 * Phases:
 *   1. Split the header, write 0x55 to 0xF00A, cap the count at 16 and unpack the data bytes.
 *   2. Carry out the message by type:
 *      EDID_MEMORY  data into edid_ram at the offset; nothing is written when it would pass the 2 KB end.
 *      I2C          data into i2c_transfer_buffer (cut at 0x80 bytes). Page write: on the last piece the buffer
 *                   (device address, start address, data) goes to i2c_write_eeprom_pages and is cleared.
 *                   Channel bit 7 (write-then-read): payload bytes 0 / 1 are the device address and write count, the
 *                   offset field gives the read count (1 when 0); on the last piece i2c_master_write_read runs and
 *                   i2c_result_* record channel, length and ready for the report back.
 *      UART         bytes to serial port 1 (sent at once) or queued for ports 2..4 (the last piece starts the
 *                   queue).
 *      DDCCI        reply bytes into the port's DDC/CI reply row: an even port fills its row from the front, an
 *                   odd port from the back of the same row; the last piece stores the reply end index.
 *      COMMANDS     count / 4 command words, each carried out by ipc_run_command.
 *      FLASH_DATA   data into the 2 KB flash data buffer at channel + offset, then post the buffer's checksum.
 *      WAKE_KEYS / WAKE_PORTS / POWER_CUT / USB_C_INFO   handed to the routine that stores that table.
 *      TEST         print the header word and data words 1..3 ('DataTest'; word 3 is printed twice).
 */
void ipc_run_message(unsigned long *msg)
{
    unsigned char msg_type, flags, channel, count, offset_16, i;
    unsigned int offset;
    unsigned char payload[16];

    /* Phase 1: header. */
    msg_type = *msg & 0x0f;
    flags = (*msg & 0xf0) >> 4;
    channel = *msg >> 8;
    count = *msg >> 16;
    offset_16 = *msg >> 24;
    DAT_EXTMEM_f00a = 0x55;
    if (count > MSG_PIECE_BYTES) count = MSG_PIECE_BYTES;
    lib_unpack_longs_to_bytes(payload, (unsigned char *)(msg + 1), count);
    offset = offset_16;
    offset <<= 4;

    /* Phase 2: by type. */
    switch (msg_type) {
    case IPC_8051_TX_MSG_EDID_MEMORY:
        if (count + offset <= EDID_RAM_SIZE) {
            for (i = 0; i < count; i++) edid_ram[offset + i] = payload[i];
        } else {
            /* 'EDID address out of range!' */
            lib_printf517((void code *)0x5582);
        }
        break;
    case IPC_8051_TX_MSG_I2C:
        if (count + offset > I2C_BUFFER_SIZE) {
            /* 'DATA_I2C OOR': keep what still fits, drop the message when nothing does. */
            lib_printf517((void code *)0x559f);
            if (offset >= I2C_BUFFER_SIZE) return;
            count = I2C_BUFFER_SIZE - offset;
        }
        if (!(channel & I2C_PAGE_WRITE_READ)) {
            for (i = 0; i < count; i++) i2c_transfer_buffer[offset + i] = payload[i];
        } else {
            i2c_transfer_buffer[0] = payload[0];
            i2c_transfer_buffer[1] = payload[1];
        }
        if (flags & MSG_FLAG_LAST_PIECE) {
            if (!(channel & I2C_PAGE_WRITE_READ)) {
                /* Bytes after the two leading ones = all pieces so far. */
                offset = offset + count - 2;
                i2c_write_eeprom_pages(channel, i2c_transfer_buffer[0], i2c_transfer_buffer[1], &i2c_transfer_buffer[2], offset);
                for (i = 0; i < 0x10; i++) i2c_transfer_buffer[i] = 0;
            } else {
                channel &= 0x7f;
                if (offset == 0) offset = 1;
                i2c_master_write_read(channel, i2c_transfer_buffer[0], i2c_transfer_buffer[1], &i2c_transfer_buffer[2], offset);
                /* Picked up for report type 2 to the main processor. */
                i2c_result_channel = channel;
                i2c_result_ready_flag = 1;
                i2c_result_length = offset;
            }
        }
        break;
    case IPC_8051_TX_MSG_UART:
        if (channel == 1) {
            for (i = 0; i < count; i++) uart_putchar(payload[i]);
        } else if (channel == 2) {
            for (i = 0; i < count; i++) uart_queue_tx_byte_port2(payload[i]);
            if (flags & MSG_FLAG_LAST_PIECE) uart_flush_tx_queue_port2();
        } else if (channel == 3) {
            for (i = 0; i < count; i++) uart_queue_tx_byte_port3(payload[i]);
            if (flags & MSG_FLAG_LAST_PIECE) uart_flush_tx_queue_port3();
        } else if (channel == 4) {
            for (i = 0; i < count; i++) uart_queue_tx_byte_port4(payload[i]);
            if (flags & MSG_FLAG_LAST_PIECE) uart_flush_tx_queue_port4();
        }
        break;
    case IPC_8051_TX_MSG_DDCCI:
        if (count + offset > DDC_ROW_SIZE) {
            /* 'DATA_DDCCI OOR'; the count is cut to 2 - offset (not to the row size). */
            lib_printf517((void code *)0x55ae);
            if (offset >= 2) return;
            count = 2 - offset;
        }
        if (channel & 1) {
            /* Odd port: from the back of the row (ddc_reply_rows_from_end starts one byte before the rows). */
            for (i = 0; i < count; i++) ddc_reply_rows_from_end[channel >> 1][0x3c - (offset + i)] = payload[i];
        } else {
            for (i = 0; i < count; i++) ddc_reply_buffers[channel >> 1][offset + i] = payload[i];
        }
        if (flags & MSG_FLAG_LAST_PIECE) {
            if (channel & 1) ddc_reply_end_indexes[channel] = 0x3b - (offset + count);
            else ddc_reply_end_indexes[channel] = offset + count;
        }
        if (!(flags & MSG_FLAG_LAST_PIECE)) return;
        break;
    case IPC_8051_TX_MSG_COMMANDS:
        for (i = 0; i < count / 4; i++) ipc_run_command(msg[i + 1]);
        break;
    case IPC_8051_TX_MSG_FLASH_DATA:
        ipc_store_flash_data(channel + offset, count, payload);
        ipc_post_result_word(ipc_sum_flash_data());
        break;
    case IPC_8051_TX_MSG_WAKE_KEYS:
        FillKeyDetectList(offset, count, payload);
        break;
    case IPC_8051_TX_MSG_WAKE_PORTS:
        ipc_store_wake_port_list(offset, count, payload);
        break;
    case IPC_8051_TX_MSG_POWER_CUT:
        ipc_store_power_cut_list(offset, count, payload);
        break;
    case IPC_8051_TX_MSG_USB_C_INFO:
        FillTypeCInfo(payload);
        break;
    case IPC_8051_TX_MSG_TEST:
        /* 'DataTest %08lx, %08lx, %08lx, %08lx %08lx' */
        lib_printf517((void code *)0x55bf, msg[0], msg[1], msg[2], msg[3], msg[3]);
        break;
    }
}
