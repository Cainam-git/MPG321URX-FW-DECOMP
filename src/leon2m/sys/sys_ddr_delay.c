/* sys_ddr_delay  (FUN_a00dffa4)
 *
 * Wait for a number of delay units.
 * Name basis: derived - forwards to the delay routine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dffa4 @ 0xa00dffa4-0xa00dffb0 (3 words), flags -mcpu=v8 -O2 -g.
 * Source form: a plain call of the short delay loop, compiled as a tail call.
 */
extern void sys_delay_loop_short(unsigned int n);

/*
 * Wait n rounds of the short delay loop (64 passes each). Used between the register writes of the memory
 * interface code, for example by sys_ddr_reset_fifos (n = 1) and sys_ddr_check_phy_reg (n = 2).
 */
void sys_ddr_delay(unsigned int n)
{
    sys_delay_loop_short(n);
}
