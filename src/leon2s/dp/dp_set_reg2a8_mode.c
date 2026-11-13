/* dp_set_reg2a8_mode  (FUN_a00c6760)
 *
 * Write the mode registers at 0x2A8 of a DisplayPort block by an on/off flag.
 * Name basis: descriptive - revision-dependent extra write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c6760 @ 0xa00c6760..0xa00c68f8 (408 bytes), flags -mcpu=v8 -Os -g.
 * The register routines are declared without parameter lists and are called at 0xa0fb6c98 (dp_reg_update_bits)
 * and 0xa0fb6c00 (dp_reg_write8), addresses outside the leon2s image; the labels are func_0x<address>.
 * The firmware takes the mode != 0 arm first (btst 0xff, %i1; be -> the other arm).
 */
extern int sys_get_chip_revision();
extern void dp_reg_write8();
extern void dp_reg_update_bits();
extern unsigned char hdcp_rx_dp_hdcp2_bytes[];

/* Writes the 0x2a8 mode register of a DP block and the registers around it, by an on/off choice.
 *
 * Both choices follow the same frame: set bit 7 of register 0x30, write 0x2a8, [on chip revision up to 0x81:
 * write 0x45d], clear bit 7 of 0x30, 0x400 = 3, set bit 7 of 0x402, then eleven bytes to register 0x401.
 * mode != 0: 0x2a8 = 1; the 0x45d write is 0; register 0x403 = 0 is written before the bytes; the eleven bytes
 * are the table hdcp_rx_dp_hdcp2_bytes.
 * mode == 0: 0x2a8 = 0; 0x45d = 0xbf is written only when extra_flag is non-zero; register 0x403 is not
 * written; the eleven bytes are all 0.
 *
 * port: DP block (receiver number). mode: choice. extra_flag: used in the mode == 0 case only.
 * No direct call to this routine exists in the image.
 */
void dp_set_reg2a8_mode(unsigned int port_arg, unsigned int mode, unsigned char extra_flag)
{
    unsigned int port = port_arg & 0xff;
    unsigned char i;
    unsigned char chip_revision;

    if ((mode & 0xff) != 0) {
        dp_reg_update_bits(port, 0x30, 0x80, 1);
        dp_reg_write8(port, 0x2a8, 1);
        chip_revision = sys_get_chip_revision() & 0xff;
        if (chip_revision <= 0x81) {
            dp_reg_write8(port, 0x45d, 0);
        }
        dp_reg_update_bits(port, 0x30, 0x80, 0);
        dp_reg_write8(port, 0x400, 3);
        dp_reg_update_bits(port, 0x402, 0x80, 1);
        dp_reg_write8(port, 0x403, 0);
        for (i = 0; i <= 10; i++) {
            dp_reg_write8(port, 0x401, hdcp_rx_dp_hdcp2_bytes[i]);
        }
    } else {
        dp_reg_update_bits(port, 0x30, 0x80, 1);
        dp_reg_write8(port, 0x2a8, 0);
        chip_revision = sys_get_chip_revision() & 0xff;
        if (chip_revision <= 0x81) {
            if (extra_flag != 0) {
                dp_reg_write8(port, 0x45d, 0xbf);
            }
        }
        dp_reg_update_bits(port, 0x30, 0x80, 0);
        dp_reg_write8(port, 0x400, 3);
        dp_reg_update_bits(port, 0x402, 0x80, 1);
        for (i = 0; i <= 10; i++) {
            dp_reg_write8(port, 0x401, 0);
        }
    }
    return;
}
