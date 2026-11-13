/* hdmi_cec_send_reply  (FUN_CODE_bf7b)
 *
 * Send a reply message on the CEC bus and wait for the result.
 *   header: header (destination)
 *   count: byte count
 * Name basis: derived - CEC registers 0xD80D/0xD820/0xD810; waits up to 1000 ticks; caller
 *   hdmi_cec_receive_message (replies 0x84, 0x32, 0x90)
 *
 * Matching notes
 * --------------
 * FUN_CODE_bf7b, 8051_bank1. OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC) added).
 * No volatile on the CEC registers: the same bytes result without it (Keil re-reads XDATA in the loop).
 */
extern unsigned char xdata reg_hdmi_cec_status;
extern unsigned char xdata reg_hdmi_cec_tx_length;
extern unsigned char xdata reg_hdmi_cec_tx_dest;
extern unsigned char xdata DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_f0e0;
extern unsigned int xdata DAT_EXTMEM_a484;
unsigned int timer_get_ticks(void);
/*
 * hdmi_cec_send_reply - send one CEC message: write 0x2E to the status register 0xD80D, the destination header to
 * 0xD820 and the byte count to 0xD810, then wait until one of the bits 0x2E of 0xD80D is set, for at most 1000
 * ticks (test after each pass; every pass writes 0x55 to 0xF00A and 0xF0E0). The status is then read once and 0x2E is
 * written back. Returns 3 when a bit of 0x2C was set or the wait timed out, 0 when only bit 1 was set.
 *   header: value for 0xD820 (destination)
 *   count: value for 0xD810
 * Caller: hdmi_cec_receive_message (hdmi_cec_receive_message).
 */
unsigned char hdmi_cec_send_reply(unsigned char header, unsigned char count)
{
    unsigned char status;
    reg_hdmi_cec_status = 0x2e;
    reg_hdmi_cec_tx_dest = header;
    reg_hdmi_cec_tx_length = count;
    DAT_EXTMEM_a484 = timer_get_ticks();
    do {
        if (reg_hdmi_cec_status & 0x2e) break;
        DAT_EXTMEM_f00a = 0x55;
        DAT_EXTMEM_f0e0 = 0x55;
    } while (timer_get_ticks() - DAT_EXTMEM_a484 <= 1000);
    status = reg_hdmi_cec_status;
    reg_hdmi_cec_status = 0x2e;
    if (status & 0x2c) return 3;
    if (status & 0x02) return 0;
    return 3;
}
