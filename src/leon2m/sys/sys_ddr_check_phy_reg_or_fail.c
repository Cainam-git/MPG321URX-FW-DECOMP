/* sys_ddr_check_phy_reg_or_fail  (FUN_a00e0888)
 *
 * Poll a register of a memory interface for the expected value and report a failure.
 * Name basis: proven - prints the 'checkphy' trace lines and the error prefix
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0888 @ 0xa00e0888-0xa00e09b8 (76 words), -mcpu=v8 -O3 -g -msoft-float (as sys_ddr_check_phy_reg).
 * Source form: one return statement for both results: a match sets ret = 1 and jumps to it, the error path sets
 * ret = 0 before its last print. The unconditional error print takes its format from the read-only array err_ (same
 * text as the trace line; the firmware holds one copy), so the two prints load the address separately.
 */
extern int sys_ddr_register_trace_enabled;                /* trace switch */
extern void sys_ddr_delay(unsigned int);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read(int phy, unsigned int addr);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);

static const char err_[] = "checkphy [0x%08x]=%08x error: %08x\n";

/*
 * Same wait as sys_ddr_check_phy_reg (up to 10 rounds of 2 delay units and a read, until (value & mask) equals
 * `expect`; returns 1 on a match). After 10 failed rounds this one also prints the current training step and
 * the "ddr_err: " prefix, reads the register once more, prints "checkphy [addr]=expect error: value" (not
 * only when the trace switch sys_ddr_register_trace_enabled is set) and returns 0.
 */
int sys_ddr_check_phy_reg_or_fail(int phy, unsigned int addr, unsigned int mask, unsigned int expect)
{
    int round;
    unsigned int value;
    int ret;

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
            ret = 1;
            goto out;
        }
    }
    if (sys_ddr_register_trace_enabled != 0)
        dbg_printf("checkphy [0x%08x]=%08x error: %08x\n", addr, expect, value);
    sys_ddr_print_step();
    sys_ddr_print_error_prefix();
    ret = 0;
    dbg_printf(err_, addr, expect, sys_ddr_phy_read(phy, addr));
out:
    return ret;
}
