/* hdcp_tx_hdmi_read_ri  (FUN_a00c8760)
 *
 * Read the receiver's two link-check bytes.
 * Name basis: proven - DDC device 0x74, offset 8, two bytes (Ri'); prints an error
 *
 * Matching notes
 * --------------
 * FUN_a00c8760 (leon2s 0xa00c8760-0xa00c87c0, 96 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the result of hdmi_tx_ddc_read is dropped (hdcp_tx_hdmi_read_ri's twin hdcp_tx_hdmi_read_rx_status checks it).
 */
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned char, unsigned short);
extern int hdmi_tx_ddc_read(unsigned int, unsigned char *, unsigned short);

#define HDCP_DDC_DEVICE 0x74                    /* device address used for all handshake reads */
#define HDCP_DDC_RI     0x08                    /* offset of the 2-byte Ri */
#define RI_LENGTH       2

/*
 * Read the 2-byte Ri of the screen on HDMI output `port` (DDC device 0x74, offset 8) into buf. When the DDC
 * start fails the firmware prints "Read R0 Error = %02X" with the result and the routine returns that result
 * without reading; otherwise it returns 0 (the result of the read itself is not looked at).
 *
 * Called from hdcp_tx_hdmi_state_check_ri.
 */
unsigned char hdcp_tx_hdmi_read_ri(unsigned char port, unsigned char *buf)
{
    unsigned char result;

    result = hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, HDCP_DDC_RI, RI_LENGTH);
    if (result != 0) {
        dbg_printf("\nRead R0 Error = %02X", result);
        return result;
    }
    hdmi_tx_ddc_read(port, buf, RI_LENGTH);
    return 0;
}
