/* hdmi_tx_read_edid  (FUN_a0091db4)
 *
 * Read EDID bytes of the display connected to an HDMI TX port.
 *   port: HDMI TX port
 *   dst: where the bytes go
 *   len: byte count, a multiple of 16
 *   base: first EDID offset
 * Note: Reads len / 16 blocks of 16 bytes; a remainder of len below 16 is not read.
 * Name basis: proven - 16-byte DDC reads from I2C address 0xA0 (EDID) through the TX DDC master
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091db4 @ 0xa0091db4-0xa0091e70 (188 bytes), flags -mcpu=v8 -Os -g.
 * hdmi_tx_ddc_start returns int (its result is ignored; a void prototype moves the port 'mov' out of the call
 * delay slot); the offset i * 16 is an unsigned int.
 */
extern void hdmi_tx_ddc_reset_step_first(unsigned char);
extern void hdmi_tx_ddc_reset_step_second(unsigned char);
extern int hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_ddc_read(unsigned char, unsigned char *, unsigned char);

#define EDID_I2C_ADDRESS 0xa0           /* I2C address of the sink's EDID */
#define EDID_BLOCK_SIZE 16              /* bytes read per DDC transfer */

/*
 * Read 'len' bytes of the sink's EDID on HDMI TX 'port', starting at EDID offset 'base', into 'dst'.
 *
 * Works in blocks of 16 bytes: len / 16 blocks are read and a length that is not a multiple of 16 loses its
 * remainder. Before each block the two DDC reset steps run.
 */
void hdmi_tx_read_edid(unsigned char port, unsigned char *dst, unsigned short len, unsigned short base)
{
    unsigned char block[EDID_BLOCK_SIZE];
    unsigned short i, j;
    unsigned int offset;

    for (i = 0; i < (len >> 4); i++) {
        hdmi_tx_ddc_reset_step_first(port);
        hdmi_tx_ddc_reset_step_second(port);
        offset = i << 4;
        hdmi_tx_ddc_start(port, EDID_I2C_ADDRESS, offset + base, EDID_BLOCK_SIZE);
        hdmi_tx_ddc_read(port, block, EDID_BLOCK_SIZE);
        for (j = 0; j < 16; j++)
            dst[offset + j] = block[j];
    }
}
