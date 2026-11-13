/* dp_tx_aux_read_reply  (FUN_a0086154)
 *
 * Collect the AUX reply bytes and check the reply code.
 *   port: output
 *   type: AUX command
 *   length
 *   out: data
 * Returns: 0 on ACK
 * Name basis: derived - reads the reply FIFO 0x37 while 0x34 bit 3 is set; reply byte 0 = 0 means ACK
 *
 * Matching notes
 * --------------
 * FUN_a0086154 (leon2s 0xa0086154-0xa00862e4, 400 bytes), flags -mcpu=v8 -Os -g.
 * Called by dp_tx_aux_transfer (its fifth parameter is out).
 * Source form: out is 'volatile unsigned char *', the type of the buffer the caller chain passes in:
 * dp_tx_handle_test_request (volatile dp_tx_aux_data_byte) -> dp_tx_aux_request_copy -> dp_tx_aux_transfer -> out. The
 * volatile store keeps the copy-loop stb before the loop cmp; the bl slot is filled from the loop head.
 */
#define AUX_REG_REPLY_STATUS 0x34    /* bit 3 is set while reply bytes are waiting; set to 1 after each read */
#define AUX_REG_REPLY_DATA   0x37    /* the next reply byte */

extern unsigned char dp_tx_aux_reply_bytes[];
extern unsigned char dp_tx_aux_reply_count;
extern unsigned char dp_tx_reg_read8(unsigned char, unsigned char);
extern void dp_tx_reg_update_bits(unsigned char, unsigned char, unsigned char, unsigned char);

/*
 * Read the reply of an AUX request from a link output into dp_tx_aux_reply_bytes. Bytes are read while bit 3
 * of the reply status register is set; bytes beyond the expected count are read and dropped. The expected
 * count is 1 for the commands 0x80, 0x40 and 0, else length + 2.
 * Result: 0 when reply byte 0 is 0 and the expected number of bytes arrived (for the other commands
 * reply bytes 1.. are then copied to out[0..]); 0x20 when reply byte 0 is 0x20; otherwise 0xff.
 *   port:   link output
 *   type:   AUX command of the request
 *   length: length given to the request
 *   out:    receives the reply data
 */
unsigned char dp_tx_aux_read_reply(unsigned char port, unsigned char type, unsigned char length, volatile unsigned char *out)
{
    signed char expected;
    unsigned char i;
    if (type == 0x80 || type == 0x40 || type == 0)
        expected = 1;
    else
        expected = length + 2;
    dp_tx_aux_reply_count = 0;
    dp_tx_aux_reply_bytes[0] = 0xff;
    while (dp_tx_reg_read8(port, AUX_REG_REPLY_STATUS) & 8) {
        if (dp_tx_aux_reply_count < expected)
            dp_tx_aux_reply_bytes[dp_tx_aux_reply_count++] = dp_tx_reg_read8(port, AUX_REG_REPLY_DATA);
        else
            dp_tx_reg_read8(port, AUX_REG_REPLY_DATA);
        dp_tx_reg_update_bits(port, AUX_REG_REPLY_STATUS, 8, 1);
    }
    if (dp_tx_aux_reply_bytes[0] == 0) {
        if (type == 0x80 || type == 0x40 || type == 0) {
            if (dp_tx_aux_reply_count == 1)
                return 0;
            return 0xff;
        }
        if (dp_tx_aux_reply_count == expected) {
            for (i = 1; i < expected; i++)
                out[i - 1] = dp_tx_aux_reply_bytes[i];
            return 0;
        }
        return 0xff;
    }
    if (dp_tx_aux_reply_bytes[0] == 0x20)
        return 0x20;
    return 0xff;
}
