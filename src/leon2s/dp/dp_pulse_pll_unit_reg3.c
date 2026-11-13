/* dp_pulse_pll_unit_reg3  (FUN_a008b914)
 *
 * Pulse bit 2 of register 3 of PLL unit 4 (DP receiver 0) or unit 6 (any other receiver).
 *   port: DP receiver 0/1
 * Name basis: descriptive - hdmi_unit_pulse_reg3(4) for port 0, else hdmi_unit_pulse_reg3(6); caller
 *   dp_run_link_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b914 @ 0xa008b914-0xa008b930 (28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: one crossjumped leaf tail call (mov %o7,%g1 / call / mov %g1,%o7). It is written as two calls with
 * the == 0 arm first; a value variable or a ternary becomes branch-free arithmetic, and the != 0 arm first
 * does not give the firmware's code.
 */
extern void hdmi_unit_pulse_reg3(unsigned int);

/*
 * Call hdmi_unit_pulse_reg3 with unit 4 for DP receiver 0 and unit 6 for any other receiver number.
 *   port: DP receiver 0 or 1
 */
void dp_pulse_pll_unit_reg3(unsigned char port)
{
    if (port == 0)
        hdmi_unit_pulse_reg3(4);
    else
        hdmi_unit_pulse_reg3(6);
}
