/* hdmi_tx_set_vtem_enable_state  (FUN_a00927a0)
 *
 * Set the VTEM packet enable bits of an HDMI TX port, or clear them when idle.
 *   port: HDMI TX port
 *   on: 1 = on
 *   force: 1 = force off
 * Name basis: descriptive - EMP page 3 reg 0 bits 0..1; regs 0xBE/0xBF both 0xFF mean nothing to send
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00927a0 @ 0xa00927a0-0xa0092890 (60 words), flags -mcpu=v8 -Os -g.
 * hdmi_tx_reg_read8 takes 3 arguments (u8 (u8, u8, u16)), hdmi_tx_reg_update_bits 5.
 */
extern unsigned char hdmi_tx_reg_read8(unsigned char, unsigned char, unsigned short);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);

#define HDMI_TX_BANK_VTEM 3             /* bank holding the VTEM packet (see hdmi_tx_write_vtem_payload) */

/*
 * Set the enable state of the VTEM packet of HDMI TX 'port' (bank 3, register 0 bits 1..0).
 *
 * on != 0: set the bits. Otherwise, with 'force' set, write 0xFF to registers 0xBE and 0xBF and clear the bits.
 * With 'force' clear: read registers 0xBE and 0xBF; when both are 0xFF clear the bits, otherwise write register
 * 0 back with the value it has.
 */
void hdmi_tx_set_vtem_enable_state(unsigned char port, unsigned char on, unsigned char force)
{
    unsigned char reg_be, reg_bf;

    if (on) {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_VTEM, 0, 3, 1);
        return;
    }
    if (force) {
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_VTEM, 0xbe, 0xff);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_VTEM, 0xbf, 0xff);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_VTEM, 0, 3, 0);
        return;
    }
    reg_be = hdmi_tx_reg_read8(port, HDMI_TX_BANK_VTEM, 0xbe);
    reg_bf = hdmi_tx_reg_read8(port, HDMI_TX_BANK_VTEM, 0xbf);
    if (reg_be == 0xff && reg_bf == 0xff) {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_VTEM, 0, 3, 0);
        return;
    }
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_VTEM, 0, hdmi_tx_reg_read8(port, HDMI_TX_BANK_VTEM, 0));
}
