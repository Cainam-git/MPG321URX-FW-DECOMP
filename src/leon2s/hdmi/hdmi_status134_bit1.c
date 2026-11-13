/* hdmi_status134_bit1  (FUN_a008f9c0)
 *
 * Return bit 1 of HDMI receiver status register 0x134.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: 0 or 1
 * Name basis: descriptive - single bit; also required by hdmi_is_ycbcr_input together with an AVI InfoFrame
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f9c0 @ 0xa008f9c0 (-mcpu=v8 -Os -g)
 * Source form: the masked bit is held in a local and compared with 0 on return.
 */

#define RX_REG_134  0x134

extern unsigned int hdmi_reg_read8(unsigned int param_1, unsigned short param_2);

/* Callers: hdmi_update_port_status_flags (copies it into bit 15 of the port record's halfword 0xE),
   hdmi_poll_rx_status (AVI time-out test), hdmi_is_ycbcr_input and the link state machine. */
unsigned int hdmi_status134_bit1(unsigned int port)
{
    unsigned int bit1 = hdmi_reg_read8(port & 0xff, RX_REG_134) & 2;
    return bit1 != 0;
}
