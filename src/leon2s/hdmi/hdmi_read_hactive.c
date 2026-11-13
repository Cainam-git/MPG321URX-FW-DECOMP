/* hdmi_read_hactive  (FUN_a0090010)
 *
 * Return the active width of an HDMI receiver, doubled for 4:2:0.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: pixels
 * Name basis: derived - reg 0x4E; stored as the HDE field of the link timing record
 *
 * Matching notes
 * --------------
 * FUN_a0090010 (leon2s, 0xa0090010-0xa0090078, 104 bytes, 26 words), flags -mcpu=v8 -Os -g.
 * Source form: the doubled result is written out twice (the firmware shares one call site: the test of the
 * colour space field branches to the shift block).
 */

#define RX_AVI_DATA_0     0x144         /* first data byte of the AVI packet area; bits 5..7 = colour space */
#define RX_HACTIVE        0x4e
#define AVI_COLOR_SPACE_3_MASKED  0x60  /* colour space field 3, still in bit position 5..7 */

extern unsigned int hdmi_reg_read8(unsigned int param_1, unsigned short param_2);
extern unsigned char hdmi_get_port1_double_flag(unsigned char param_1);
extern unsigned int hdmi_reg_read16_stable(unsigned int param_1, unsigned short param_2);

/* Reads the active width from register 0x4E (read until two reads agree) and doubles it when the AVI colour
   space field (bits 5..7 of register 0x144) is 3 or when hdmi_get_port1_double_flag is not 0. Both doubling
   paths read register 0x4E again. hdmi_save_link_timing stores the result in the record as hactive. */
unsigned short hdmi_read_hactive(unsigned int port)
{
    port = port & 0xff;
    if ((hdmi_reg_read8(port, RX_AVI_DATA_0) & 0xe0) == AVI_COLOR_SPACE_3_MASKED)
        return hdmi_reg_read16_stable(port, RX_HACTIVE) << 1;
    if (hdmi_get_port1_double_flag(port) != 0)
        return hdmi_reg_read16_stable(port, RX_HACTIVE) << 1;
    return hdmi_reg_read16_stable(port, RX_HACTIVE);
}
