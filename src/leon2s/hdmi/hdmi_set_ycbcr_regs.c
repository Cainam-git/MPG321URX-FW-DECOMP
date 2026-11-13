/* hdmi_set_ycbcr_regs  (FUN_a00912ec)
 *
 * Set the YCbCr handling registers 0x4B..0x4D of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - 0x80 values when hdmi_is_ycbcr_input; 0x4D also needs the colour space not to be
 *   4:4:4 code 3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00912ec @ 0xa00912ec-0xa0091388 (39 words), flags -mcpu=v8 -Os -g.
 * Source form: each outcome writes all three registers in its own arm (nested ifs, the 0x144 test inside the
 * hdmi_is_ycbcr_input arm); the compiler shares the common call tails.
 */
extern unsigned char hdmi_is_ycbcr_input(unsigned char);
extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);
extern void hdmi_reg_write8(unsigned int, unsigned short, unsigned int);

/*
 * Write receiver registers 0x4B, 0x4C and 0x4D of HDMI receiver 'port'.
 *
 * When hdmi_is_ycbcr_input(port) is false all three are written 0. Otherwise 0x4B gets 0x80 and 0x4C gets 0;
 * 0x4D gets 0 when bits 7..5 of register 0x144 read 011, else 0x80.
 */
void hdmi_set_ycbcr_regs(unsigned char port)
{
    if (hdmi_is_ycbcr_input(port)) {
        if ((hdmi_reg_read8(port, 0x144) & 0xe0) == 0x60) {
            hdmi_reg_write8(port, 0x4b, 0x80);
            hdmi_reg_write8(port, 0x4c, 0);
            hdmi_reg_write8(port, 0x4d, 0);
        } else {
            hdmi_reg_write8(port, 0x4b, 0x80);
            hdmi_reg_write8(port, 0x4c, 0);
            hdmi_reg_write8(port, 0x4d, 0x80);
        }
    } else {
        hdmi_reg_write8(port, 0x4b, 0);
        hdmi_reg_write8(port, 0x4c, 0);
        hdmi_reg_write8(port, 0x4d, 0);
    }
}
