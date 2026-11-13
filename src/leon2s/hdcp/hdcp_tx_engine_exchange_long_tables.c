/* hdcp_tx_engine_exchange_long_tables  (FUN_a00c255c)
 *
 * Run the engine's two-pass exchange on the result tables and keep the last 17 bytes read back.
 * Note: Writes the 95-byte table b, reads 32 bytes XOR table a, writes them back, reads 95 bytes and keeps the
 *   last 17 XOR table b.
 * Name basis: descriptive - XOR combination; prints '17th = %02X'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c255c @ 0xa00c255c, flags -mcpu=v8 -Os -g (the section default).
 * Source form: the two table pointers are locals declared with the counters (the pointer a first, then the
 * counters, then b = a + 0x20); the counter i is initialised at its declaration, so the first loop has no init
 * of its own.
 */
extern unsigned char hdcp_rx_engine_result_tables[];
extern unsigned char hdcp_rx_key_buffer[];
extern int dbg_printf(const char *, ...);
extern void hdcp_tx_engine_reg_write8(unsigned char, unsigned int, unsigned char);
extern unsigned char hdcp_tx_engine_reg_read8(unsigned char, unsigned int);

#define FIRST_LENGTH   0x20     /* bytes of the first table */
#define SECOND_LENGTH  0x5f     /* bytes of the second table */
#define RESULT_SKIP    0x4e     /* the last 17 bytes of the second read-back are kept */
#define POLL_LIMIT     0xff     /* polls of register 0xa before a wait gives up */

/*
 * Run the second exchange with the protection engine and leave 17 result bytes in hdcp_rx_key_buffer.
 *
 *   port  the engine unit (0 HDMI 2.0, 1 HDMI 2.1, 2 DisplayPort inputs)
 *
 * Called by hdcp_rx_key_load_step in step 2. The input data is the 127 bytes that follow the first byte of the
 * 128-byte result in the buffer that hdcp_rx_engine_result_buffer starts (stored there in step 1 by
 * hdcp_tx_engine_read_result): the first 32 bytes are table a, the next 95 table b.
 *
 * Round 1: table b is written to engine register 0xd (after 0x18, 0x10 to register 0xc), 0x44 is written to
 * register 0xa and the routine waits for bit 2 of register 0xa to clear (at most 255 polls, then it goes on).
 * With 0x28, 0x20 in register 0xc, 32 bytes are read from register 0xd; each is XORed with the byte of table
 * a at the same index and stored in hdcp_rx_key_buffer[0..31].
 * Round 2: those 32 bytes are written back the same way, register 0xa gets 0x42 and the routine waits for
 * bit 1 to clear (same limit). 95 bytes are then read; the bytes with index 0x4E..0x5E are XORed with the
 * table b bytes at the same index and stored in hdcp_rx_key_buffer[0..16], overwriting the first 17 of the 32. The
 * first of the 17 is printed ("17th = %02X").
 */
void hdcp_tx_engine_exchange_long_tables(unsigned char port)
{
    unsigned char *table_a = hdcp_rx_engine_result_tables;
    unsigned char i = 0, tries, value;
    unsigned char *table_b = table_a + FIRST_LENGTH;

    hdcp_tx_engine_reg_write8(port, 0xc, 0x18);
    hdcp_tx_engine_reg_write8(port, 0xc, 0x10);
    for (; i <= SECOND_LENGTH - 1; i++)
        hdcp_tx_engine_reg_write8(port, 0xd, table_b[i]);
    hdcp_tx_engine_reg_write8(port, 0xa, 0x44);
    tries = POLL_LIMIT;
    while (hdcp_tx_engine_reg_read8(port, 0xa) & 4) {
        tries--;
        if (tries == 0)
            break;
    }
    hdcp_tx_engine_reg_write8(port, 0xc, 0x28);
    hdcp_tx_engine_reg_write8(port, 0xc, 0x20);
    for (i = 0; i <= FIRST_LENGTH - 1; i++)
        hdcp_rx_key_buffer[i] = hdcp_tx_engine_reg_read8(port, 0xd) ^ table_a[i];
    hdcp_tx_engine_reg_write8(port, 0xc, 0x18);
    hdcp_tx_engine_reg_write8(port, 0xc, 0x10);
    for (i = 0; i <= FIRST_LENGTH - 1; i++)
        hdcp_tx_engine_reg_write8(port, 0xd, hdcp_rx_key_buffer[i]);
    hdcp_tx_engine_reg_write8(port, 0xa, 0x42);
    tries = POLL_LIMIT;
    while (hdcp_tx_engine_reg_read8(port, 0xa) & 2) {
        tries--;
        if (tries == 0)
            break;
    }
    hdcp_tx_engine_reg_write8(port, 0xc, 0x28);
    hdcp_tx_engine_reg_write8(port, 0xc, 0x20);
    for (i = 0; i <= SECOND_LENGTH - 1; i++) {
        value = hdcp_tx_engine_reg_read8(port, 0xd);
        if (i > RESULT_SKIP - 1)
            hdcp_rx_key_buffer[i - RESULT_SKIP] = table_b[i] ^ value;
    }
    dbg_printf("\n17th = %02X", hdcp_rx_key_buffer[0]);
}
