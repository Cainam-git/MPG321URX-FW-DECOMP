/* hdmi_get_bt2020_colorimetry  (FUN_a008ff08)
 *
 * Return 1 or 2 when the AVI InfoFrame reports a BT.2020 colorimetry, else 0.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: 1 for extended colorimetry code 5, 2 for code 6, else 0
 * Name basis: derived - extended colorimetry bits 4..6 of reg 0x146: 5 -> 1, 6 -> 2 (the two BT.2020 codes of
 *   the InfoFrame standard)
 *
 * Matching notes
 * --------------
 * FUN_a008ff08 (leon2s 0xa008ff08-0xa008ff58, 80 bytes), flags -mcpu=v8 -Os -g.
 * Source form: register 0x146 is read a second time for the second comparison.
 */

#define RX_AVI_DATA_2   0x146           /* AVI packet area starts at 0x140 */

extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);

/* Bits 4..6 of register 0x146 are 5 (0x50): returns 1; they are 6 (0x60): returns 2; any other value: 0.
   hdmi_get_color_format_code adds the result to the format code it builds. */
unsigned int hdmi_get_bt2020_colorimetry(unsigned char port)
{
    if ((hdmi_reg_read8(port, RX_AVI_DATA_2) & 0x70) == 0x50)
        return 1;
    return ((hdmi_reg_read8(port, RX_AVI_DATA_2) & 0x70) == 0x60) * 2;
}
