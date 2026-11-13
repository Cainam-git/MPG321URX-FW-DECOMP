/* dp_tx_init_ctl_banks  (FUN_a00aa3a4)
 *
 * Write the start-up values of a DP / eDP transmitter control bank.
 *   port: output 0..4
 * Name basis: derived - output 0: registers 9 / 0xA; eDP: one-time bank set-up then registers 0xC / 0xD;
 *   caller dp_tx_init_ports
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. The call to dp_tx_phy_write_dptx_option for output 0 is a tail call.
 */
extern unsigned char dp_tx_ctl_init_byte;
extern unsigned char dp_tx_ctl_reg_read8(unsigned char, unsigned short);
extern void dp_tx_ctl_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_tx_phy_write_dptx_option(void);
extern void dp_tx_phy_write_edp_options(void);

/*
 * Write the start-up values of the control bank of a DP output and the PHY options that go with it.
 *
 *   port: output 0 (DPTX) or 1..4 (eDP)
 *
 * Output 0: control register 9 = (old value & 0x08) | 0x91, control register 0x0A = 0x11, then
 * dp_tx_phy_write_dptx_option.
 * Outputs 1..4: the first time (while dp_tx_ctl_init_byte is 0) control registers 0x64 of bank 1 = 7 and 0x63
 * of bank 1 = 0x94 are written, dp_tx_phy_write_edp_options is called and the flag is set; every time then
 * control register 0x0C = 0x10 and 0x0D = 8 of the output.
 * Called by dp_tx_init_ports.
 */
void dp_tx_init_ctl_banks(unsigned char port)
{
    if (port == 0) {
        dp_tx_ctl_reg_write8(0, 9, (dp_tx_ctl_reg_read8(0, 9) & 0x08) | 0x91);
        dp_tx_ctl_reg_write8(0, 10, 0x11);
        dp_tx_phy_write_dptx_option();
        return;
    }
    if (dp_tx_ctl_init_byte == 0) {
        dp_tx_ctl_reg_write8(1, 100, 7);
        dp_tx_ctl_reg_write8(1, 99, 0x94);
        dp_tx_phy_write_edp_options();
        dp_tx_ctl_init_byte = 1;
    }
    dp_tx_ctl_reg_write8(port, 0xc, 0x10);
    dp_tx_ctl_reg_write8(port, 0xd, 8);
}
