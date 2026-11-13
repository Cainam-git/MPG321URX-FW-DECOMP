/* hdmi_get_color_format_code  (FUN_a00901a0)
 *
 * Return a code for the colour format and colorimetry an HDMI source sends.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: format code
 * Name basis: derived - built from AVI fields (regs 0x144..0x148); a change restarts the link state ('colour
 *   space' in the record)
 *
 * Matching notes
 * --------------
 * FUN_a00901a0 (leon2s 0xa00901a0-0xa0090374, 468 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the code starts at 1 and is set to 2 before the register 0x145 test; the increment condition is
 * one || / && expression; the BT.2020 sum goes through an unsigned int local.
 */

/* The AVI packet area starts at register 0x140 (see hdmi_capture_avi_infoframe); 0x144..0x148 are its data bytes
   1 to 5. */
#define RX_REG_134      0x134
#define RX_AVI_DATA_1   0x144
#define RX_AVI_DATA_2   0x145
#define RX_AVI_DATA_3   0x146
#define RX_AVI_DATA_4   0x147
#define RX_AVI_DATA_5   0x148

extern unsigned char hdmi_is_ycbcr_input(unsigned char);
extern unsigned char hdmi_get_bt2020_colorimetry(unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);

/* Builds one number from the AVI fields that describe the picture format. The link state machine stores it as
   the port's colour_space; a change of it in READY sends the port back to STABLE.
   - hdmi_is_ycbcr_input true: start at 2. Register 0x145 bits 6..7 = 3 give 0xE, and then 0x14 when register
     0x146 bits 4..6 = 1, or 0x1C / 0x22 when hdmi_get_bt2020_colorimetry returns 1 / 2; bits 6..7 = 2 give 8.
     Then add 1 when register 0x148 bits 6..7 are not 0, or when register 0x146 bits 2..3 are not 1 and are
     either not 0 or register 0x147 bits 0..6 equal 1. Add 2 when register 0x144 bits 5..7 equal 1, and 4 when
     they equal 3.
   - otherwise: 1, unless bit 1 of register 0x134 is set; then it is 0x1A plus (register 0x146 bits 2..3 not 1)
     when hdmi_get_bt2020_colorimetry is not 0, else just that comparison (0 or 1). */
unsigned char hdmi_get_color_format_code(unsigned char port)
{
    unsigned char code = 1;
    unsigned int not_one;

    if (hdmi_is_ycbcr_input(port)) {
        code = 2;
        if ((hdmi_reg_read8(port, RX_AVI_DATA_2) & 0xc0) == 0xc0) {
            code = 0xe;
            if ((hdmi_reg_read8(port, RX_AVI_DATA_3) & 0x70) == 0x10)
                code = 0x14;
            else if (hdmi_get_bt2020_colorimetry(port) == 1)
                code = 0x1c;
            else if (hdmi_get_bt2020_colorimetry(port) == 2)
                code = 0x22;
        } else if ((hdmi_reg_read8(port, RX_AVI_DATA_2) & 0xc0) == 0x80)
            code = 8;
        if ((hdmi_reg_read8(port, RX_AVI_DATA_5) & 0xc0)
            || ((hdmi_reg_read8(port, RX_AVI_DATA_3) & 0xc) != 4
                && ((hdmi_reg_read8(port, RX_AVI_DATA_3) & 0xc) || (hdmi_reg_read8(port, RX_AVI_DATA_4) & 0x7f) == 1)))
            code++;
        if ((hdmi_reg_read8(port, RX_AVI_DATA_1) & 0xe0) == 0x20)
            code += 2;
        if ((hdmi_reg_read8(port, RX_AVI_DATA_1) & 0xe0) == 0x60)
            code += 4;
    } else if (hdmi_reg_read8(port, RX_REG_134) & 2) {
        if (hdmi_get_bt2020_colorimetry(port)) {
            not_one = (hdmi_reg_read8(port, RX_AVI_DATA_3) & 0xc) != 4;
            code = not_one + 0x1a;
        } else
            code = (hdmi_reg_read8(port, RX_AVI_DATA_3) & 0xc) != 4;
    }
    return code;
}
