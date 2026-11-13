/* hdcp_tx_engine_read_result  (FUN_a00c2488)
 *
 * Read 64 byte pairs from the engine when its done bit is set.
 * Name basis: descriptive - bit 5 of register 2; bytes stored in reverse
 *
 * Matching notes
 * --------------
 * FUN_a00c2488 (leon2s 0xa00c2488-0xa00c255c, 212 bytes), flags -mcpu=v8 -Os -g.
 * Source form: result and loop counter are unsigned char locals both initialised to 0 at their declarations (the
 * firmware copies the result register's 0 into the counter); the result is returned as 'done & 1'.
 */
extern unsigned int hdcp_tx_engine_reg_read8(unsigned char, unsigned char);
extern void hdcp_tx_engine_reg_write8(unsigned char, unsigned char, unsigned char);

#define ENGINE_STATUS_REG   2                   /* bit 5 = a result is ready */
#define ENGINE_RESULT_PAIRS 64                  /* byte pairs in the result */

/*
 * Fetch the result of copy-protection engine unit `port` when it is ready. Returns 0 and leaves buf alone when
 * bit 5 of register 2 is not set. Otherwise it writes the register sequence 2 = 0x40, 3 = 0, 4 = 0x66,
 * 5 = 0x80, 5 = 0, reads register 7 once and drops the value, then reads 64 pairs (register 6, register 7) and
 * returns 1. Pair i is stored at buf[2 * (63 - i) + 1] (register 6) and buf[2 * (63 - i)] (register 7), so
 * the first pair read ends up at the end of the 128-byte buffer.
 *
 * Callers: the copy-protection key step of the inputs (result goes to hdcp_rx_engine_result_buffer) and the output
 * handshake code (hdcp_tx_message_buffer).
 */
unsigned char hdcp_tx_engine_read_result(unsigned char port, unsigned char *buf)
{
    unsigned char done = 0;
    unsigned char i = 0;
    unsigned char value;

    if (hdcp_tx_engine_reg_read8(port, ENGINE_STATUS_REG) & 0x20) {
        hdcp_tx_engine_reg_write8(port, 2, 0x40);
        hdcp_tx_engine_reg_write8(port, 3, 0);
        hdcp_tx_engine_reg_write8(port, 4, 0x66);
        hdcp_tx_engine_reg_write8(port, 5, 0x80);
        hdcp_tx_engine_reg_write8(port, 5, 0);
        hdcp_tx_engine_reg_read8(port, 7);
        for (i = 0; i < ENGINE_RESULT_PAIRS; i++) {
            value = hdcp_tx_engine_reg_read8(port, 6);
            buf[((ENGINE_RESULT_PAIRS - 1 - i) * 2) + 1] = value;
            buf[(ENGINE_RESULT_PAIRS - 1 - i) * 2] = hdcp_tx_engine_reg_read8(port, 7);
        }
        done = 1;
    }
    return done & 1;
}
