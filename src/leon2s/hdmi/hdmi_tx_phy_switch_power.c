/* hdmi_tx_phy_switch_power  (FUN_a008e5ac)
 *
 * Order the HDMI TX PHY power call and two control bits by FRL mode and rate, then wait.
 *   port: HDMI TX port
 *   frl_mode: FRL mode bit of the output record
 *   rate_4_up: 1 = FRL rate above 3
 *   rate_5_up: 1 = FRL rate at or above the upper limit; third argument of hdmi_tx_phy_set_power
 * Note: The PHY power is switched on only in FRL mode at a rate above 3; otherwise it is switched off.
 * Name basis: descriptive - orders hdmi_tx_phy_set_power with regs 8 bit 3 and 0x7F bit 0, then waits
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e5ac @ 0xa008e5ac-0xa008e654, flags -mcpu=v8 -Os -g.
 * The third argument of hdmi_tx_phy_set_power is rate_5_up in all arms (the firmware computes
 * 'and %i3,0xff,%o2' once at entry and keeps it for both 0-arm calls). The wait is a tail call (declared void).
 */
extern void hdmi_tx_set_reg08_bit3(unsigned char, unsigned char); /* 0xa008db4c */
extern void hdmi_tx_set_reg7f_bit0(unsigned char, unsigned char); /* 0xa008db90 */
extern void hdmi_tx_phy_set_power(unsigned char, unsigned char, unsigned char); /* 0xa008dbd4 */
extern void timer_delay_long_units(int); /* 0xa00b1794 */

/*
 * Run the power sequence of the HDMI TX PHY, then wait 10 long delay units. The three steps are
 * hdmi_tx_phy_set_power(port, on, rate_5_up), bit 3 of register 8 and bit 0 of register 0x7F:
 *   frl_mode == 0:  power off, register 8 bit 3 set, register 0x7F bit 0 clear;
 *   rate_4_up == 1: register 8 bit 3 clear, power on, register 0x7F bit 0 set;
 *   otherwise:      power off, register 8 bit 3 set, register 0x7F bit 0 set.
 *   port: HDMI TX port.  frl_mode: the channel record's frl_mode bit.  rate_4_up: 1 when the FRL rate is
 *   above 3.  rate_5_up: 1 when the FRL rate is 5 or more.
 * Called by hdmi_tx_run_step, which passes the three flags.
 */
void hdmi_tx_phy_switch_power(unsigned char port, unsigned char frl_mode, unsigned char rate_4_up, unsigned char rate_5_up)
{
    if (frl_mode == 0) {
        hdmi_tx_phy_set_power(port, 0, rate_5_up);
        hdmi_tx_set_reg08_bit3(port, 1);
        hdmi_tx_set_reg7f_bit0(port, 0);
    } else if (rate_4_up == 1) {
        hdmi_tx_set_reg08_bit3(port, 0);
        hdmi_tx_phy_set_power(port, 1, rate_5_up);
        hdmi_tx_set_reg7f_bit0(port, 1);
    } else {
        hdmi_tx_phy_set_power(port, 0, rate_5_up);
        hdmi_tx_set_reg08_bit3(port, 1);
        hdmi_tx_set_reg7f_bit0(port, 1);
    }

    timer_delay_long_units(10);
}
