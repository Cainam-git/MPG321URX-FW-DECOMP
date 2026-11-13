/* hdmi_set_reg08_from_avi  (FUN_a008facc)
 *
 * Set the high nibble of HDMI receiver register 8 from the AVI field of reg 0x148.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - 0x50 / 0xF0 for reg 0x148 nibble 1 / 3 when reg 0x134 bit 1 is set
 *
 * Matching notes
 * --------------
 * FUN_a008facc (leon2s, 0xa008facc-0xa008fb5c, 144 bytes, 36 words).
 * Flags: -mcpu=v8 -Os -g.
 * Source form: the nibble of register 0x148 is an unsigned char (the firmware re-extends it with 'and 0xff'),
 * the 0xF0 case is written as an or with 0xfffffff0 and the write back as value & 0xff.
 */

#define RX_REG_08       8
#define RX_REG_134      0x134
#define RX_AVI_DATA_4   0x148           /* AVI packet area starts at 0x140 */

extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);
extern void hdmi_reg_write8(unsigned int, int, unsigned int);
extern void hdmi_reg_update_bits(unsigned int, int, unsigned int, int);

/* Called by the link state machine in STABLE. When bit 1 of register 0x134 is set, the high nibble of register
   8 becomes 5 if the low nibble of register 0x148 is 1, 0xF if it is 3, and 0 for any other value (the low
   nibble of register 8 is kept). When the bit is clear, the high nibble of register 8 is cleared. */
void hdmi_set_reg08_from_avi(unsigned int port)
{
    unsigned char avi_nibble;
    unsigned int value;
    unsigned char low_nibble;

    port &= 0xff;

    if (hdmi_reg_read8(port, RX_REG_134) & 2) {
        avi_nibble = (unsigned char)(hdmi_reg_read8(port, RX_AVI_DATA_4) & 0xf);
        low_nibble = hdmi_reg_read8(port, RX_REG_08) & 0xf;

        value = low_nibble;
        if (avi_nibble == 1) {
            value = low_nibble | 0x50;
        } else if (avi_nibble == 3) {
            value = low_nibble | 0xfffffff0;
        }

        hdmi_reg_write8(port, RX_REG_08, value & 0xff);
    } else {
        hdmi_reg_update_bits(port, RX_REG_08, 0xf0, 0);
    }
}
