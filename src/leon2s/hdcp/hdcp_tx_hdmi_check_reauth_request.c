/* hdcp_tx_hdmi_check_reauth_request  (FUN_a00cc9f8)
 *
 * Return whether the receiver asks for a new handshake, and note it.
 * Returns: 0 or 1
 * Name basis: derived - bit 3 of the second status byte (re-authentication request)
 *
 * Matching notes
 * --------------
 * FUN_a00cc9f8 (leon2s, 0xa00cc9f8-0xa00cca38, 64 bytes, 16 words).
 * Flags: -mcpu=v8 -Os -g.
 * Source form: u8 return type and one return of the result variable (two int returns give a different exit).
 */
extern int hdcp_tx_hdmi_read_rx_status(unsigned int, unsigned char *);
extern int hdcp_tx_init_port_record(unsigned int, int);

#define RXSTATUS_BIT3           0x08    /* bit 3 of the second status byte */

/*
 * Read the receiver's two status bytes and test bit 3 of the second one. When it is set the output's record is
 * initialised again (hdcp_tx_init_port_record(port, 0)) and 1 is returned, otherwise 0. Called by
 * hdcp_tx_service_port, which prints "InitHDCPMSG(Txlinkidx, FALSE)" when the result is 1.
 */
unsigned char hdcp_tx_hdmi_check_reauth_request(unsigned int port_arg)
{
    unsigned char status[2];
    unsigned char found;
    unsigned int port;

    port = port_arg & 0xff;
    hdcp_tx_hdmi_read_rx_status(port, status);
    found = 0;
    if (status[1] & RXSTATUS_BIT3) {
        hdcp_tx_init_port_record(port, 0);
        found = 1;
    }
    return found;
}
