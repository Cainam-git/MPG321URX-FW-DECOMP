/* hdcp_tx_hdmi_read_rx_status  (FUN_a00c9798)
 *
 * Read the receiver's two status bytes over the HDMI output's control channel.
 * Returns: error code or 0
 * Name basis: derived - device 0x74, offset 0x70, two bytes; logs the first non-zero error
 *
 * Matching notes
 * --------------
 * FUN_a00c9798 (leon2s 0xa00c9798-0xa00c9810, 30 words), flags -mcpu=v8 -Os -g.
 * Source form: two early-return checks; the buffer pointer is passed through to the read.
 */
extern unsigned int hdmi_tx_ddc_start(unsigned char, int, int, int);
extern unsigned int hdmi_tx_ddc_read(unsigned char, unsigned char *, unsigned char);
extern int dbg_printf(const char *, ...);

#define HDCP_DDC_DEVICE    0x74                 /* device address used for all handshake reads */
#define HDCP_DDC_RXSTATUS  0x70                 /* offset of the 2-byte status */
#define RXSTATUS_LENGTH    2

/*
 * Read the 2 status bytes of the screen on HDMI output `port` (DDC device 0x74, offset 0x70) into buf. Returns 0, or
 * the error of the DDC start or of the read, which the firmware prints as "Read RXSTATUS Error 1 = %02X" (start)
 * or "Read RXSTATUS Error 2 = %02X" (read).
 *
 * Called by the state handlers of hdcp_tx_hdmi_run_state, which pass hdcp_tx_status_bytes as buf.
 */
unsigned char hdcp_tx_hdmi_read_rx_status(unsigned char port, unsigned char *buf)
{
    unsigned char result;

    result = hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, HDCP_DDC_RXSTATUS, RXSTATUS_LENGTH);
    if (result != 0) {
        dbg_printf("\nRead RXSTATUS Error 1 = %02X", result);
        return result;
    }
    result = hdmi_tx_ddc_read(port, buf, RXSTATUS_LENGTH);
    if (result != 0) {
        dbg_printf("\nRead RXSTATUS Error 2 = %02X", result);
        return result;
    }
    return 0;
}
