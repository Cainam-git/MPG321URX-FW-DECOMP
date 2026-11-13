/* hdmi_tx_ddc_read_at  (FUN_a00c82dc)
 *
 * Start a DDC read at an address and fetch the bytes.
 * Name basis: derived - hdmi_tx_ddc_start, then hdmi_tx_ddc_read
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c82dc, flags -mcpu=v8 -Os -g.
 * Source form: the port is masked to a byte first; the result of each call is masked to a byte and kept in a
 * local that the compiler holds in %g1; a non-zero result from the first call is returned as it is.
 */
extern int hdmi_tx_ddc_start();
extern int hdmi_tx_ddc_read();

#define READ_AT_DEVICE 0x74     /* device address given to hdmi_tx_ddc_start */
#define READ_AT_OFFSET 0x41     /* offset given to hdmi_tx_ddc_start */
#define READ_AT_LENGTH 2        /* number of bytes started and read */

/*
 * Read two bytes from device 0x74, offset 0x41 on the DDC channel of an HDMI output: hdmi_tx_ddc_start
 * programs the master, then hdmi_tx_ddc_read fetches the bytes into `buffer`.
 *   port:   HDMI TX port
 *   buffer: receives the two bytes
 * Returns the result of hdmi_tx_ddc_start when it is not 0 (the read is then not done), else the result of
 * hdmi_tx_ddc_read (always 0).
 */
unsigned char hdmi_tx_ddc_read_at(unsigned char port, unsigned int buffer)
{
    unsigned char result;
    
    port = port & 0xff;
    result = (unsigned char)(hdmi_tx_ddc_start(port, READ_AT_DEVICE, READ_AT_OFFSET, READ_AT_LENGTH) & 0xff);
    if (result != 0) {
        return result;
    }
    return (unsigned char)(hdmi_tx_ddc_read(port, buffer, READ_AT_LENGTH) & 0xff);
}
