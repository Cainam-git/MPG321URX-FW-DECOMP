/* hdmi_set_ycbcr422_bit  (FUN_a008fdc8)
 *
 * Set bit 1 of receiver register 0x48 when the AVI colour space field is 1, else clear it.
 *   port: HDMI 2.0 receiver 0/1
 * Note: Colour space field 1 is YCbCr 4:2:2 in the InfoFrame standard; the code only compares with 1.
 * Name basis: descriptive - hdmi_get_avi_color_space (bits 5..7 of AVI data byte 0x144) == 1 -> reg 0x48 bit 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fdc8 @ 0xa008fdc8 (-mcpu=v8 -Os -g)
 * Source form: the call of hdmi_reg_update_bits is in both arms of the if/else (this gives the firmware's two
 * separate call sequences after the comparison). The second parameter is not used.
 */

#define RX_REG_48       0x48
#define AVI_COLOR_SPACE_1   1

extern unsigned int hdmi_get_avi_color_space(unsigned int param_1);
extern void hdmi_reg_update_bits(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4);

/* Called by the link state machine when a port goes to READY. Bit 1 of register 0x48 is set when the AVI colour
   space field is 1, and cleared otherwise. */
void hdmi_set_ycbcr422_bit(unsigned int port, unsigned int param_2)
{
    unsigned int rx;
    unsigned int color_space;

    rx = port & 0xff;
    color_space = hdmi_get_avi_color_space(rx);
    if ((color_space & 0xff) == AVI_COLOR_SPACE_1) {
        hdmi_reg_update_bits(rx, RX_REG_48, 2, 1);
    } else {
        hdmi_reg_update_bits(rx, RX_REG_48, 2, 0);
    }
}
