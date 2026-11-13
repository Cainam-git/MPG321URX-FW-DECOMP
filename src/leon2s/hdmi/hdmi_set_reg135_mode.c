/* hdmi_set_reg135_mode  (FUN_a008fe38)
 *
 * Write 6 or 9 to HDMI receiver register 0x135.
 *   port: HDMI 2.0 receiver
 *   on: 1 = 6
 * Name basis: descriptive - 6 when on (also the start value), 9 when off
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fe38 @ 0xa008fe38 (-mcpu=v8 -Os -g)
 * Source form: the register number is loaded in both arms of the if/else.
 */

#define RX_REG_135   0x135

extern void hdmi_reg_write8(unsigned int param_1, unsigned short param_2, unsigned int param_3);

/* Register 0x135 gets 6 when "on" is not 0 and 9 when it is 0. The link state machine calls it with 1 when a
   port goes to STANDBY; what the two values do is not shown. */
void hdmi_set_reg135_mode(unsigned char port, unsigned char on)
{
    if (on != 0)
        hdmi_reg_write8(port, RX_REG_135, 6);
    else
        hdmi_reg_write8(port, RX_REG_135, 9);
}
