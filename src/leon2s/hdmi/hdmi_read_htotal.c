/* hdmi_read_htotal  (FUN_a0090098)
 *
 * Return the total line length of an HDMI receiver, doubled for 4:2:0.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: pixels
 * Name basis: derived - reg 0x3A; stored as the HTOTAL field and printed as 'usLINKHtotal'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090098 @ 0xa0090098 (-mcpu=v8 -Os -g)
 * Source form: the same as hdmi_read_hactive (the doubled result is written out twice).
 */

#define RX_AVI_DATA_0     0x144         /* first data byte of the AVI packet area; bits 5..7 = colour space */
#define RX_HTOTAL         0x3a
#define AVI_COLOR_SPACE_3_MASKED  0x60  /* colour space field 3, still in bit position 5..7 */

extern unsigned int hdmi_reg_read8(unsigned int param_1, unsigned short param_2);
extern unsigned char hdmi_get_port1_double_flag(unsigned char param_1);
extern unsigned int hdmi_reg_read16_stable(unsigned int param_1, unsigned short param_2);

/* Same as hdmi_read_hactive, for register 0x3A: the total line length, doubled when the AVI colour space field
   is 3 or hdmi_get_port1_double_flag is not 0. The link state machine prints it as 'usLINKHtotal'. */
unsigned short hdmi_read_htotal(unsigned int port)
{
    port = port & 0xff;
    if ((hdmi_reg_read8(port, RX_AVI_DATA_0) & 0xe0) == AVI_COLOR_SPACE_3_MASKED)
        return hdmi_reg_read16_stable(port, RX_HTOTAL) << 1;
    if (hdmi_get_port1_double_flag(port) != 0)
        return hdmi_reg_read16_stable(port, RX_HTOTAL) << 1;
    return hdmi_reg_read16_stable(port, RX_HTOTAL);
}
