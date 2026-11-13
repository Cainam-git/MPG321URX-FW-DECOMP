/* hdmi_cec_select_port  (FUN_CODE_bf18)
 *
 * Set up the CEC controller for one port and reset its state.
 *   port: port 0..3
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - CEC registers 0xD807/0xD800/0xD811/0xD80D, 2-bit port field in 0xD533, logical
 *   address 0x0F
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_bf18, no caller in the image. Keil compiles the switch as a DEC A / JZ chain with the case 0 body first.
 */
extern unsigned char xdata DAT_EXTMEM_d800, DAT_EXTMEM_d807, reg_hdmi_cec_status, DAT_EXTMEM_d811, reg_hdmi_cec_port_select;
extern unsigned char xdata hdmi_cec_active_source, hdmi_cec_operand, hdmi_cec_initiator;
extern void hdmi_cec_set_clock_divider(void);
/*
 * hdmi_cec_select_port - set up the CEC controller for port 0..3 and reset the receive state.
 * Writes 0xD807 = 0x28, 0xD800 = 1, 0xD811 = 0x53; sets a 2-bit field of the port select register 0xD533 to 01
 * (port 0: bits 7..6, port 1: bits 5..4, port 2: bits 3..2, port 3: bits 1..0; other numbers: no field); then
 * writes 0xFF to the status register, 0x0F to hdmi_cec_initiator and hdmi_cec_active_source, 0xFF to
 * hdmi_cec_operand, and ends by jumping into hdmi_cec_set_clock_divider. No caller in the bank-1 image.
 */
void hdmi_cec_select_port(unsigned char port)
{
    DAT_EXTMEM_d807 = 0x28;
    DAT_EXTMEM_d800 = 1;
    DAT_EXTMEM_d811 = 0x53;
    switch (port) {
    case 0: reg_hdmi_cec_port_select = reg_hdmi_cec_port_select & 0x3f | 0x40; break;
    case 1: reg_hdmi_cec_port_select = reg_hdmi_cec_port_select & 0xcf | 0x10; break;
    case 2: reg_hdmi_cec_port_select = reg_hdmi_cec_port_select & 0xf3 | 0x04; break;
    case 3: reg_hdmi_cec_port_select = reg_hdmi_cec_port_select & 0xfc | 0x01; break;
    }
    reg_hdmi_cec_status = 0xff;
    hdmi_cec_initiator = 0x0f;
    hdmi_cec_active_source = 0x0f;
    hdmi_cec_operand = 0xff;
    hdmi_cec_set_clock_divider();
}
