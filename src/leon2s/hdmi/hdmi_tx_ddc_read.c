/* hdmi_tx_ddc_read  (FUN_a00c81f8)
 *
 * Read a block of bytes from a device on the HDMI output's DDC channel.
 * Name basis: proven - blocks of 16 after polling the status register 0xF5
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c81f8, flags -mcpu=v8 -Os -g.
 * Source forms: raw unsigned int port (the callees mask it to a byte); a for loop over the block number with
 * the `length != 0` test; the poll is a while loop with an inner 'if (--tries == 0) break;'.
 */
extern void timer_delay_long_units(unsigned int);
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, unsigned short);
extern void hdmi_tx_ddc_read_fifo(unsigned char port, unsigned char *buf, unsigned char n, unsigned short reg);

#define HDMI_TX_BANK_CORE 0             /* bank 0 of an HDMI transmitter's registers */
#define DDC_DATA_REG 0xf4               /* DDC master: data */
#define DDC_FIFO_LEVEL_REG 0xf5         /* DDC master: bits 0..4 = number of bytes waiting */
#define DDC_FIFO_LEVEL_MASK 0x1f
#define DDC_BLOCK_BYTES 0x10            /* bytes read per block */
#define DDC_POLL_TRIES 100              /* polls of the level register, shared by all blocks */

/*
 * Read `length` bytes from the data register of the DDC master of an HDMI output into `buffer`. After a
 * timer_delay_long_units(2) it reads the data register once into buffer[0]. The bytes are then fetched in
 * blocks of up to 16 with hdmi_tx_ddc_read_fifo; before each block the routine polls register 0xF5 until its
 * bits 0..4 equal 0x10 (when more than 16 bytes remain) or the block size minus 1. A counter that starts at
 * 100 and is shared by all blocks drops by one for every poll that does not match; when it reaches 0 the
 * poll stops and the block is read anyway. Always returns 0.
 *   port:   HDMI TX port
 *   buffer: where the bytes go
 *   length: number of bytes
 */
int hdmi_tx_ddc_read(unsigned int port, unsigned char *buffer, unsigned short length)
{
    unsigned char tries = DDC_POLL_TRIES;
    unsigned short block;

    timer_delay_long_units(2);
    buffer[0] = hdmi_tx_reg_read8(port, HDMI_TX_BANK_CORE, DDC_DATA_REG);
    for (block = 0; length != 0; block++) {
        while ((hdmi_tx_reg_read8(port, HDMI_TX_BANK_CORE, DDC_FIFO_LEVEL_REG) & DDC_FIFO_LEVEL_MASK) != (length > DDC_BLOCK_BYTES ? DDC_BLOCK_BYTES : length - 1)) {
            if (--tries == 0)
                break;
        }
        hdmi_tx_ddc_read_fifo(port, buffer + block * DDC_BLOCK_BYTES, length > DDC_BLOCK_BYTES ? DDC_BLOCK_BYTES : length, DDC_DATA_REG);
        length = length > DDC_BLOCK_BYTES ? length - DDC_BLOCK_BYTES : 0;
    }
    return 0;
}
