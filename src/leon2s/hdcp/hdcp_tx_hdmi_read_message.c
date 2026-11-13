/* hdcp_tx_hdmi_read_message  (FUN_a00c9810)
 *
 * Read a message from the receiver in 16-byte blocks, waiting for each block to fill the DDC fifo.
 * Name basis: derived - split between the caller's buffer and the work buffer; prints
 *
 * Matching notes
 * --------------
 * FUN_a00c9810 (leon2s 0xa00c9810-0xa00c9968), flags -mcpu=v8 -Os -g.
 * Source form: the destination-buffer arm is written first (index - 0x8b > 0x17f); the index is incremented
 * before the length is decremented; the wait loop is a do-while inside a do-while on the unsigned char tries.
 */
extern void timer_delay_long_units(int);
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, unsigned short);
extern int dbg_printf(const char *, ...);
extern unsigned char hdcp_tx_engine_buffer[];

#define DDC_DATA_REG       0xf4                 /* registers of the output's DDC master: data ... */
#define DDC_FIFO_LEVEL_REG 0xf5                 /* ... and the number of bytes waiting (bits 0..4) */
#define BLOCK_BYTES        16
#define BUFFER_FIRST       0x8b                 /* bytes 0x8B..0x20A of the message go to hdcp_tx_engine_buffer */
#define BUFFER_COUNT       0x180

/*
 * Read a message of len bytes from the DDC master of HDMI output `port` (the transfer was started by
 * hdmi_tx_ddc_start) in blocks of 16 bytes. Before each block it waits until register 0xF5 (bits 0..4) shows
 * the block's byte count minus 1 (0x10 when more than 16 bytes are left), repeating the wait while the counter
 * `tries` (0x14 at the start, counted down over the whole read) is non-zero.
 *
 * The message bytes numbered 0x8B..0x20A go to hdcp_tx_engine_buffer, all others to message in order.
 * Before the first block register 0xF4 is read once into message[0] (the first message byte overwrites it)
 * and the firmware prints len and the block count.
 *
 * Called from hdcp_tx_hdmi_state_read_message with hdcp_tx_message_buffer.
 */
void hdcp_tx_hdmi_read_message(unsigned char port, unsigned char *message, unsigned short len)
{
    unsigned short blocks, block, index, engine_index;
    unsigned char tries, message_index, i, value;

    timer_delay_long_units(2);
    message[0] = hdmi_tx_reg_read8(port, 0, DDC_DATA_REG);
    blocks = (len >> 4) + 1;
    dbg_printf((const char *)0x9f1c20f8, len, blocks);
    tries = 0x14;
    message_index = 0;
    engine_index = 0;
    index = 0;
    for (block = 0; block < blocks; block++) {
        do {
            do {
                value = hdmi_tx_reg_read8(port, 0, DDC_FIFO_LEVEL_REG) & 0x1f;
            } while (len <= 0x10 ? value != len - 1 : value != 0x10);
        } while (tries-- != 0);
        for (i = 0; i < BLOCK_BYTES; i++) {
            value = hdmi_tx_reg_read8(port, 0, DDC_DATA_REG);
            if ((unsigned short)(index - BUFFER_FIRST) > BUFFER_COUNT - 1)
                message[message_index++] = value;
            else
                hdcp_tx_engine_buffer[engine_index++] = value;
            index++;
            len--;
            if (len == 0)
                return;
        }
    }
}
