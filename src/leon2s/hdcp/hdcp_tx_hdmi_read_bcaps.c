/* hdcp_tx_hdmi_read_bcaps  (FUN_a00c8360)
 *
 * Read the receiver's capability byte.
 * Name basis: proven - DDC device 0x74, offset 0x40, one byte (Bcaps); bit 6 = repeater
 *
 * Matching notes
 * --------------
 * FUN_a00c8360 (leon2s 0xa00c8360-0xa00c83e4), flags -mcpu=v8 -Os -g.
 * Source form: the record array is declared as unsigned int and indexed port * 6 (24-byte records).
 */
extern unsigned int hdcp_tx_records[];
extern int hdmi_tx_ddc_start();
extern int hdmi_tx_ddc_read();

#define HDCP_DDC_DEVICE   0x74                  /* device address used for all handshake reads */
#define HDCP_DDC_BCAPS    0x40                  /* offset of the Bcaps byte */
#define BCAPS_REPEATER    0x40                  /* bit 6 of that byte */
#define RECORD_REPEATER   0x10000000            /* bit 28 of word 0 of the output record */
#define RECORD_WORDS      6                     /* words in one 24-byte output record */

/*
 * Read the Bcaps byte of the screen on HDMI output `port` into *bcaps. When bit 6 of it is set, bit 28 of word 0
 * of the output's record in hdcp_tx_records is set (hdcp_tx_hdmi_set_repeater_bits reads it). Returns 0, or the
 * non-zero result of the DDC start or read when one of them fails (then the record is not touched).
 */
int hdcp_tx_hdmi_read_bcaps(unsigned int port, unsigned char *bcaps)
{
    unsigned int start_result;
    unsigned int read_result;
    
    port = port & 0xff;
    start_result = hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, HDCP_DDC_BCAPS, 1) & 0xff;
    if (start_result == 0) {
        read_result = hdmi_tx_ddc_read(port, bcaps, 1) & 0xff;
        if (read_result == 0) {
            if ((*bcaps & BCAPS_REPEATER) != 0) {
                hdcp_tx_records[port * RECORD_WORDS] |= RECORD_REPEATER;
            }
            return 0;
        }
        return read_result;
    }
    return start_result;
}
