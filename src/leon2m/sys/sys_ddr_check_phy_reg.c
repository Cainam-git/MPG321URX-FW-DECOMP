/* sys_ddr_check_phy_reg  (FUN_a00e0788)
 *
 * Poll a register of a memory interface until it shows the expected value.
 * Returns: pass or fail
 * Name basis: proven - prints the 'checkphy' trace lines; up to ten rounds
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0788 @ 0xa00e0788 (-mcpu=v8 -O3 -g -msoft-float)
 * Build: -msoft-float changes the loop's hoisting of the flag loads and string addresses (the image has no FPU code).
 */
extern int sys_ddr_register_trace_enabled;                /* trace switch */
extern void sys_ddr_delay(unsigned int);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read(int phy, unsigned int addr);

/*
 * Wait until (register addr of memory interface phy & mask) equals `expect`. Up to 10 rounds: each waits 2 delay
 * units and reads the register. Returns 1 when the value matched, 0 after 10 failed rounds (silently, apart from
 * the trace). When sys_ddr_register_trace_enabled is non-zero the "checkphy" lines are printed: start, every value read, pass or
 * error.
 */
int sys_ddr_check_phy_reg(int phy, unsigned int addr, unsigned int mask, unsigned int expect)
{
    int round;
    unsigned int value;

    if (sys_ddr_register_trace_enabled != 0)
        dbg_printf("checkphy wait [0x%08x] & 0x%08x = %08x\n", addr, mask, expect);
    for (round = 0; round < 10; round++) {
        sys_ddr_delay(2);
        value = sys_ddr_phy_read(phy, addr) & mask;
        if (sys_ddr_register_trace_enabled != 0)
            dbg_printf("checkphy current=0x%08x\n", value);
        if (value == expect) {
            if (sys_ddr_register_trace_enabled != 0)
                dbg_printf("checkphy [0x%08x] pass\n", addr);
            return 1;
        }
    }
    if (sys_ddr_register_trace_enabled != 0)
        dbg_printf("checkphy [0x%08x]=%08x error: %08x\n", addr, expect, value);
    return 0;
}
