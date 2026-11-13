/* hdmi_is_deep_color  (FUN_a008fe10)
 *
 * Return 1 when the colour depth code of an HDMI receiver (register 0x45 bits 0..2) is not 4.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: 1 when the code is not 4 (4 = 8 bits per colour), else 0
 * Note: Codes 0..3, which hdmi_get_color_depth also reports as 8 bits, give 1 here as codes 5..7 (10, 12, 16
 *   bits) do.
 * Name basis: derived - reg 0x45 bits 0..2 != 4; hdmi_get_color_depth maps the same field to 8 / 10 / 12 / 16
 *   bits
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fe10 @ 0xa008fe10 (-mcpu=v8 -Os -g)
 * Source form: the comparison result is returned as a value (the firmware makes it branch-free with addx).
 */

#define RX_REG_45   0x45

extern unsigned int hdmi_reg_read8(unsigned int param_1, unsigned short param_2);

/* Returns 1 when bits 0..2 of register 0x45 are not 4. The values 5, 6 and 7 of these bits are the 10, 12 and
   16 bit depths of hdmi_get_color_depth; the link state machine waits in STABLE for a while as long as this
   returns 1. */
unsigned int hdmi_is_deep_color(unsigned int port)
{
    unsigned int depth_code = hdmi_reg_read8(port & 0xff, RX_REG_45);
    return (depth_code & 7) != 4;
}
