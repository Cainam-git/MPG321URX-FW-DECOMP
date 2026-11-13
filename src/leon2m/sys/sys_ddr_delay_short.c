/* sys_ddr_delay_short  (FUN_a00dff94)
 *
 * Wait in the long delay loop, with the caller's argument (1) as the number of rounds.
 * Name basis: descriptive - forwards to the delay routine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dff94 @ 0xa00dff94 (-mcpu=v8 -O2 -g)
 * Source form: the routine has no parameter and calls the long delay loop without an argument; its callers pass 1,
 * which stays in the argument register for the long delay loop.
 */
extern int sys_delay_loop_long();

/*
 * Wait in the long delay loop (n times 64,000 passes). The routine itself takes no argument: the argument
 * register of its callers (the memory training steps, which pass 1) reaches the delay loop untouched, so the
 * wait is one round of the long loop.
 */
void sys_ddr_delay_short(void)
{
    sys_delay_loop_long();
}
