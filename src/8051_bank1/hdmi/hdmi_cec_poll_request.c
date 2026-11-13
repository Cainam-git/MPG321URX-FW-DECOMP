/* hdmi_cec_poll_request  (FUN_CODE_c4ee)
 *
 * Return the next pending CEC power request after reading the CEC bus.
 * Returns: request 1..5, or 0
 * Name basis: derived - lowest set bit of 0xA758 (set by hdmi_cec_receive_message) as 1..5, cleared on return
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c4ee, OPTIMIZE(8,SPEED) LARGE. The result lives in XDATA and is read back for the return.
 */
extern unsigned char xdata hdmi_cec_request_flags;
extern unsigned char hdmi_cec_receive_message(void);

/*
 * hdmi_cec_poll_request - call hdmi_cec_receive_message; when it returns 1, return the lowest set bit of
 * hdmi_cec_request_flags as a number (bit 0 -> 1 ... bit 4 -> 5, none -> 0) and clear the flags. Returns 0 when
 * nothing was received.
 * Only caller: hdmi_cec_report_request, which prints the request for the codes 1, 2, 3 and 5.
 */
unsigned char hdmi_cec_poll_request(void)
{
    unsigned char request, flags;

    request = 0;
    if (hdmi_cec_receive_message() == 1) {
        flags = hdmi_cec_request_flags;
        if (flags & 0x01) request = 1;
        else if (flags & 0x02) request = 2;
        else if (flags & 0x04) request = 3;
        else if (flags & 0x08) request = 4;
        else if (flags & 0x10) request = 5;
        hdmi_cec_request_flags = 0;
    }
    return request;
}
