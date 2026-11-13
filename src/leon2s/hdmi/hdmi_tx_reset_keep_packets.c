/* hdmi_tx_reset_keep_packets  (FUN_a00943d0)
 *
 * Pulse the HDMI TX reset bit while keeping the packet settings.
 *   port: HDMI TX port 0/1
 * Name basis: derived - saves packet enables and EMP regs, pulses reg 5 bit 0, restores them
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00943d0 @ 0xa00943d0-0xa00944e0 (68 words), flags -mcpu=v8 -Os -g.
 * The values written back are the read results, held in a byte array on the stack.
 */
extern unsigned char hdmi_tx_reg_read8(unsigned char, unsigned char, unsigned short);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_tx_sys_reg_write_masked(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char hdmi_tx_sys_reg_read8(unsigned char, unsigned short);
extern void timer_delay_long_units(unsigned int);

/*
 * Pulse bit 0 of register 5 (bank 0) of HDMI TX 'port' high and low, keeping five other register values.
 *
 * Before the pulse it reads system register 0x80, bank 0 registers 0x13E and 0x13F and bank 2 registers 0xBD
 * and 0; after the pulse (one timer_delay_long_units(1) wait between the two writes) it writes the same values
 * back.
 */
void hdmi_tx_reset_keep_packets(unsigned char port)
{
    unsigned char saved[5];

    saved[0] = hdmi_tx_sys_reg_read8(port, 0x80);
    saved[1] = hdmi_tx_reg_read8(port, 0, 0x13e);
    saved[2] = hdmi_tx_reg_read8(port, 0, 0x13f);
    saved[3] = hdmi_tx_reg_read8(port, 2, 0xbd);
    saved[4] = hdmi_tx_reg_read8(port, 2, 0);
    hdmi_tx_reg_update_bits(port, 0, 5, 1, 1);
    timer_delay_long_units(1);
    hdmi_tx_reg_update_bits(port, 0, 5, 1, 0);
    hdmi_tx_sys_reg_write_masked(port, 0x80, 0, saved[0]);
    hdmi_tx_reg_write8(port, 0, 0x13e, saved[1]);
    hdmi_tx_reg_write8(port, 0, 0x13f, saved[2]);
    hdmi_tx_reg_write8(port, 2, 0xbd, saved[3]);
    hdmi_tx_reg_write8(port, 2, 0, saved[4]);
}
