/* sys_step_clock_switch  (FUN_CODE_d214)
 *
 * Advance the switch-over from the crystal clock to the PLL clock by one step.
 * Note: Step counter = dp_power_up_request (1: PLL registers; 2; 3: switch, then 4). Runs from an interrupt in
 *   register bank 3; not used on chip id 0x20.
 * Name basis: derived - step 1 programs the clock unit (regs 0xD904..), step 3 switches the clock and timer
 *   rates; the counter is the byte dp_power_up_request
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d214 @ 0xd214 (54 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Source form: runs in register bank 3 ('using 3': PUSH PSW, PSW = 0x18) like its callees. The second read of the
 * state byte is kept in R7 for the '== 3' test; 'state == 1' and 'state++' share the increment tail.
 */
extern unsigned char xdata dp_power_up_request;
void sys_setup_pll_regs(void);
void sys_switch_to_pll_clock(void);
void sys_scale_timing_to_clock(void);

/*
 * One step of the switch from the crystal clock to the PLL clock. The step
 * counter is the byte dp_power_up_request (0xA6EE), which other code also
 * sets to 1 and clears. Step 1: sys_setup_pll_regs, then 2. Step 0 and 2:
 * counter + 1. Step 3: counter = 4, then sys_switch_to_pll_clock and
 * sys_scale_timing_to_clock. From 4 on nothing changes. Only caller: the
 * code at 0xC217, on its path where 0xD511 is not 0x20.
 */
void sys_step_clock_switch(void) using 3
{
    if (dp_power_up_request == 1) {
        sys_setup_pll_regs();
        dp_power_up_request++;
    } else if (dp_power_up_request < 3) {
        dp_power_up_request++;
    } else if (dp_power_up_request == 3) {
        dp_power_up_request = 4;
        sys_switch_to_pll_clock();
        sys_scale_timing_to_clock();
    }
}
