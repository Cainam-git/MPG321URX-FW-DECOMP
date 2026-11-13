/* hdmi_is_ycbcr_input  (FUN_a008fea8)
 *
 * Return whether an HDMI source sends a YCbCr picture with an AVI InfoFrame.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: 1 when YCbCr
 * Name basis: derived - reg 0x134 bit 1, AVI type 0x82 at reg 0x140, colour space != 0
 *
 * Matching notes
 * --------------
 * FUN_a008fea8 (leon2s 0xa008fea8-0xa008ff08, 96 bytes), flags -mcpu=v8 -Os -g.
 * Source form: a result byte set to 1 or 0 in an if/else and returned as result & 1.
 */

#define RX_REG_134          0x134
#define RX_AVI_TYPE         0x140       /* first byte of the AVI packet area */
#define PACKET_TYPE_AVI     0x82

extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned char hdmi_get_avi_color_space(unsigned char);

/* Returns 1 when bit 1 of register 0x134 is set, the AVI packet area holds a packet of type 0x82 and its colour
   space field (hdmi_get_avi_color_space) is not 0. */
unsigned char hdmi_is_ycbcr_input(unsigned char port)
{
    unsigned char result;

    if ((hdmi_reg_read8(port, RX_REG_134) & 2) && (unsigned char)hdmi_reg_read8(port, RX_AVI_TYPE) == PACKET_TYPE_AVI &&
        hdmi_get_avi_color_space(port) != 0)
        result = 1;
    else
        result = 0;
    return result & 1;
}
