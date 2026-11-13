/* hdmi_tx_set_pixel_format  (FUN_a0092064)
 *
 * Set the pixel format bits and matching clock mode of an HDMI TX port.
 *   port: HDMI TX port
 *   mode: pixel format code
 * Name basis: derived - reg 0x82 bits 5..6 = 1/2/3 like the AVI Y field (1 -> clock mode 1, 3 = 4:2:0 -> 2)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0092064 @ 0xa0092064-0xa00920ec (34 words), flags -mcpu=v8 -Os -g.
 * gcc crossjumps the 1 and 3 arms into one hdmi_tx_reg_write8 call (the clock-mode argument lands in %i1 in
 * the delay slots). hdmi_tx_reg_read8 returns u8; hdmi_tx_reg_write8 takes a u8 value (the 3-case 'and 0xff'
 * is that conversion).
 * Source form: a switch on mode & 0xf (an if/else-if chain gives another layout and keeps the masked mode in
 * %l0); sibcall tails.
 */
extern unsigned char hdmi_tx_reg_read8(unsigned char, unsigned char, unsigned short);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_set_clock_mode_reg5(unsigned char, unsigned char);

#define PIXEL_FORMAT_REG 0x82           /* bits 6..5 are changed here */

/*
 * Set register 0x82 (bank 0) of HDMI TX 'port' and the clock mode (hdmi_tx_set_clock_mode_reg5) for pixel
 * format 'mode' (only the low 4 bits count):
 *   1: bit 6 set, bit 5 cleared; clock mode 1
 *   3: bits 6 and 5 set; clock mode 2
 *   any other value: bit 5 set, bit 6 cleared; clock mode 0
 * The other bits of the register are kept.
 */
void hdmi_tx_set_pixel_format(unsigned char port, unsigned int mode)
{
    unsigned char reg_value;

    reg_value = hdmi_tx_reg_read8(port, 0, PIXEL_FORMAT_REG);
    switch (mode & 0xf) {
    case 1:
        hdmi_tx_reg_write8(port, 0, PIXEL_FORMAT_REG, (reg_value | 0x40) & 0xdf);
        hdmi_tx_set_clock_mode_reg5(port, 1);
        break;
    case 3:
        hdmi_tx_reg_write8(port, 0, PIXEL_FORMAT_REG, reg_value | 0x60);
        hdmi_tx_set_clock_mode_reg5(port, 2);
        break;
    default:
        hdmi_tx_reg_write8(port, 0, PIXEL_FORMAT_REG, (reg_value | 0x20) & 0xbf);
        hdmi_tx_set_clock_mode_reg5(port, 0);
        break;
    }
}
