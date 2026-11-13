/* hdmi_get_avi_color_space  (FUN_a008fb5c)
 *
 * Return the colour space field of the received AVI InfoFrame.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: colour space code
 * Name basis: proven - bits 5..7 of reg 0x144 = AVI byte 1 (Y field; 0x60 = 4:2:0 doubles horizontal values)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fb5c @ 0xa008fb5c (-mcpu=v8 -Os -g)
 */

#define RX_AVI_DATA_0   0x144           /* first data byte of the AVI packet area (area starts at 0x140) */

extern unsigned int hdmi_reg_read8(unsigned int param_1, unsigned short param_2);

/* Bits 5..7 of register 0x144, as 0..7. hdmi_is_ycbcr_input tests it for non-zero and hdmi_set_ycbcr422_bit
   for 1; hdmi_read_hactive, hdmi_read_htotal and hdmi_calc_pixel_clock read the same bits themselves and act
   on the value 3. */
unsigned int hdmi_get_avi_color_space(unsigned int port)
{
    return (hdmi_reg_read8(port & 0xff, RX_AVI_DATA_0) & 0xe0) >> 5;
}
