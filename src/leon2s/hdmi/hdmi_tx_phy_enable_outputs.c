/* hdmi_tx_phy_enable_outputs  (FUN_a008e654)
 *
 * Enable the HDMI TX output stages and load the calibration value.
 *   port: HDMI TX port
 *   mode: TX record bit 4
 * Name basis: descriptive - regs 7 bit 7, 0x0A enables, 9, 5 then hdmi_tx_load_reg0c_trim; TX command 8
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e654 @ 0xa008e654-0xa008e6b8, flags -mcpu=v8 -Os -g.
 * Source form: the first step is an if/else with two hdmi_tx_set_reg07_bit7 calls (gcc crossjumps them into one
 * call with %o1 = 0/1; this keeps the firmware's separate 'and %i0,0xff,%g1' copy and the second
 * 'and %i0,0xff,%i0'). A computed 0/1 argument gives an extra 'and %o1,1'. The four unused words are passed
 * through to the last call, which is a tail call.
 */
extern void hdmi_tx_set_reg0a_enables(unsigned char, unsigned char);
extern void hdmi_tx_set_reg09_mode(unsigned char, unsigned char);
extern void hdmi_tx_set_reg05_enable(unsigned char, unsigned char);
extern void hdmi_tx_load_reg0c_trim(unsigned char, unsigned char, unsigned int, unsigned int, unsigned int, unsigned int);
extern void hdmi_tx_set_reg07_bit7(unsigned char, unsigned char);
extern void timer_delay_long_units(unsigned char);

/*
 * Switch on the output stages of the HDMI TX PHY, in this order: bit 7 of register 7 (clear when frl_mode is 1,
 * set otherwise), the four enable bits of register 0x0A, register 9 = 0x43, a wait of one long delay unit,
 * register 5 (hdmi_tx_set_reg05_enable), and the register 0x0C value (hdmi_tx_load_reg0c_trim).
 *   port: HDMI TX port.  frl_mode: the channel record's frl_mode bit.  unused_3 to unused_6: not used here;
 *   passed on to hdmi_tx_load_reg0c_trim.
 * Called by hdmi_tx_run_step.
 */
void hdmi_tx_phy_enable_outputs(unsigned char port, unsigned char frl_mode, unsigned int unused_3, unsigned int unused_4,
                  unsigned int unused_5, unsigned int unused_6)
{
    if (frl_mode == 1)
        hdmi_tx_set_reg07_bit7(port, 0);
    else
        hdmi_tx_set_reg07_bit7(port, 1);
    hdmi_tx_set_reg0a_enables(port, 1);
    hdmi_tx_set_reg09_mode(port, 1);
    timer_delay_long_units(1);
    hdmi_tx_set_reg05_enable(port, 1);
    hdmi_tx_load_reg0c_trim(port, frl_mode, unused_3, unused_4, unused_5, unused_6);
}
