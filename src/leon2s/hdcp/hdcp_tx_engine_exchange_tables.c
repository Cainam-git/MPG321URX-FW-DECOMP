/* hdcp_tx_engine_exchange_tables  (FUN_a00c77dc)
 *
 * Run the two-round table exchange with the engine and combine the result with ROM tables.
 * Name basis: descriptive - registers 0x0C / 0x0D / 0x0A with bounded waits; XOR with ROM tables
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c77dc @ 0xa00c77dc, flags -mcpu=v8 -Os -g (the section default).
 * Required forms: the buffer pointer is a local (kept in a register for the whole routine); the counter i is
 * initialised at its declaration (the firmware's 'clr' of it comes before the first call; an 'i = 0' just
 * before the first loop gives a different order). The first loop is a do/while, the later ones are for loops.
 */
extern unsigned char hdcp_tx_exchange_buffer[];
extern const unsigned char hdcp_tx_exchange_byte_table[];
extern const unsigned char hdcp_tx_engine_fixed_block[];
extern void hdcp_tx_engine_reg_write8(unsigned int, unsigned int, unsigned int);
extern unsigned int hdcp_tx_engine_reg_read8(unsigned int, unsigned int);

#define FIRST_LENGTH    0x20    /* bytes of hdcp_tx_exchange_byte_table, and of the second read */
#define SECOND_LENGTH   0x5f    /* bytes of the first read, and of the second write */
#define SECOND_OFFSET   0x21    /* the 95 bytes lie at buffer[0x21..0x7F], the 32 bytes at buffer[1..0x20] */
#define POLL_LIMIT      0xff    /* polls of register 0xa before a wait gives up */

/*
 * Run the two-round table exchange with the engine of one output and leave 127 bytes in
 * hdcp_tx_exchange_buffer.
 *
 *   port  the engine unit (byte +9 of the output's protection record)
 *
 * Called by the key-block states of the HDMI and DisplayPort output handshakes
 * (hdcp_tx_hdmi_state_send_key_block, hdcp_tx_dp_state_send_key_block); the result is then sent to the engine
 * with hdcp_tx_engine_load_key_blocks. Byte 0 of the buffer is set to 0.
 *
 * Round 1: the 32 bytes of hdcp_tx_exchange_byte_table (0, 1, 2, ...) are written to engine register 0xd
 * (after 0x18, 0x10 to register 0xc), 0x42 is written to register 0xa and the routine waits for bit 1 of
 * register 0xa to clear (at most 255 polls, then it goes on). With 0x28, 0x20 in register 0xc, 95 bytes are
 * read from register 0xd; each is XORed with the byte of hdcp_tx_engine_fixed_block at the same index and
 * stored at buffer[0x21 + index].
 * Round 2: those 95 bytes are written back the same way, register 0xa gets 0x44 and the routine waits for
 * bit 2 to clear (same limit). 32 bytes are then read, XORed with hdcp_tx_exchange_byte_table and stored at
 * buffer[1..0x20].
 */
void hdcp_tx_engine_exchange_tables(unsigned char port)
{
    unsigned char i = 0;
    unsigned char tries;
    unsigned char *buffer;

    buffer = hdcp_tx_exchange_buffer;
    hdcp_tx_exchange_buffer[0] = 0;
    hdcp_tx_engine_reg_write8(port, 0xc, 0x18);
    hdcp_tx_engine_reg_write8(port, 0xc, 0x10);
    do {
        hdcp_tx_engine_reg_write8(port, 0xd, hdcp_tx_exchange_byte_table[i]);
        i++;
    } while (i < FIRST_LENGTH);
    hdcp_tx_engine_reg_write8(port, 0xa, 0x42);
    tries = POLL_LIMIT;
    while (hdcp_tx_engine_reg_read8(port, 0xa) & 2) {
        if (--tries == 0)
            break;
    }
    hdcp_tx_engine_reg_write8(port, 0xc, 0x28);
    hdcp_tx_engine_reg_write8(port, 0xc, 0x20);
    for (i = 0; i < SECOND_LENGTH; i++)
        buffer[SECOND_OFFSET + i] = hdcp_tx_engine_reg_read8(port, 0xd) ^ hdcp_tx_engine_fixed_block[i];

    hdcp_tx_engine_reg_write8(port, 0xc, 0x18);
    hdcp_tx_engine_reg_write8(port, 0xc, 0x10);
    for (i = 0; i < SECOND_LENGTH; i++)
        hdcp_tx_engine_reg_write8(port, 0xd, buffer[SECOND_OFFSET + i]);
    hdcp_tx_engine_reg_write8(port, 0xa, 0x44);
    tries = POLL_LIMIT;
    while (hdcp_tx_engine_reg_read8(port, 0xa) & 4) {
        if (--tries == 0)
            break;
    }
    hdcp_tx_engine_reg_write8(port, 0xc, 0x28);
    hdcp_tx_engine_reg_write8(port, 0xc, 0x20);
    for (i = 0; i < FIRST_LENGTH; i++)
        buffer[1 + i] = hdcp_tx_engine_reg_read8(port, 0xd) ^ hdcp_tx_exchange_byte_table[i];
}
