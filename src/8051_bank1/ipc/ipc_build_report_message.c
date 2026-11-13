/* ipc_build_report_message  (FUN_CODE_5c06)
 *
 * Build the next five-word message for the main processor from the report record.
 *   msg: five-word message buffer
 * Name basis: proven - header word = type, channel, byte count, number of the four-word piece; payload four
 *   words of 0xA3EC; caller ipc_service_mailbox (8051 -> main slots)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_5c06 @ 0x5C06..0x5DCB (453 bytes), OPTIMIZE(8,SPEED) LARGE.
 * msg is a generic pointer to 5 unsigned long words (LARGE parameter at XDATA 0xA48E..0xA490); locals i 0xA491,
 * count 0xA492, piece_index 0xA493. The five clears use ?C?LSTKPTR / ?C?LSTKOPTR with the inline constant 0.
 * 0xF00A is a hardware register (volatile).
 * Source form: the last term is cast to unsigned int, '(unsigned int)((report_area.flags * 16) & 0xF0)', which
 * gives the firmware's zero extension to long (CLR A); without the cast Keil sign-extends the int.
 */
/* The report area at XDATA 0xA3E3..0xA46E (the same structure as in ipc_fill_report_record); its first byte has the
 * name uart_rx_reported_mask. */
#define report_area uart_rx_reported_mask
struct ipc_report_area {
    unsigned char reported_mask;    /* 0xA3E3: serial ports whose data sits in a mailbox slot */
    unsigned char i2c_channel;      /* 0xA3E4: channel of the I2C read result */
    unsigned char word_count;       /* 0xA3E5: data words of the report */
    unsigned char position;         /* 0xA3E6: next data word to send */
    unsigned char type;             /* 0xA3E7: message type, bits 0..3 of each piece's header */
    unsigned char channel;          /* 0xA3E8: header bits 8..15 */
    unsigned char flags;            /* 0xA3E9: header bits 4..7; bit 0 = last piece */
    unsigned int length;            /* 0xA3EA: bytes still to send; 0 = the area is free */
    unsigned long data_words[32];   /* 0xA3EC: the bytes, four per word, first byte most significant */
};
extern struct ipc_report_area xdata report_area;
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
bit ipc_test_report_slot_free(void);
void ipc_fill_report_record(void);

#define MSG_PIECE_BYTES     16      /* data bytes in one message at most */
#define MSG_PIECE_WORDS     4
#define MSG_FLAG_LAST_PIECE 1       /* bit 0 of the flags field (header bit 4) */

/*
 * ipc_build_report_message - fill one message for the main processor (a header word and four data words) with the
 * next piece of the report area. Called by ipc_service_mailbox for a free 8051 -> main slot.
 *   msg  the five words; all zero when there is nothing to send
 * When the report area is free, ipc_fill_report_record is asked first to load the next pending report. A piece
 * carries up to 16 bytes; the flags field gets MSG_FLAG_LAST_PIECE on the piece that empties the area and loses it
 * on any other. Header word (docs/MAILBOX.md): bits 0..3 type, bits 4..7 flags, bits 8..15 channel, bits 16..23
 * byte count of this piece, bits 24..31 position / 4. position counts data words, so this is the number of pieces
 * sent before (docs/MAILBOX.md calls it the word offset). The four data words that follow are always copied, also
 * past the byte count. After the piece, a free area is filled again for the next call.
 */
void ipc_build_report_message(unsigned long *msg)
{
    unsigned char i, count, piece_index;

    msg[0] = 0;
    msg[1] = 0;
    msg[2] = 0;
    msg[3] = 0;
    msg[4] = 0;
    if (ipc_test_report_slot_free()) ipc_fill_report_record();
    DAT_EXTMEM_f00a = 0x55;
    if (!ipc_test_report_slot_free()) {
        if (report_area.length > MSG_PIECE_BYTES) {
            count = MSG_PIECE_BYTES;
            report_area.length -= MSG_PIECE_BYTES;
            report_area.flags &= ~MSG_FLAG_LAST_PIECE;
        } else {
            count = report_area.length;
            report_area.flags |= MSG_FLAG_LAST_PIECE;
            report_area.length = 0;
        }
        piece_index = report_area.position / 4;
        msg[0] = ((unsigned long)piece_index << 24) + ((unsigned long)count << 16) + ((unsigned long)report_area.channel << 8)
               + (report_area.type & 0x0f) + (unsigned int)((report_area.flags * 16) & 0xf0);
        for (i = 0; i < MSG_PIECE_WORDS; i++)
            msg[i + 1] = report_area.data_words[report_area.position++];
    }
    if (ipc_test_report_slot_free()) ipc_fill_report_record();
}
