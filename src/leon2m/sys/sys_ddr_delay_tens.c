/* sys_ddr_delay_tens  (FUN_a00e222c)
 *
 * Wait for ten times the given number of delay units.
 * Name basis: descriptive - tail call to the delay routine; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e222c @ 0xa00e222c-0xa00e2248 (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a plain call, compiled as a tail call (the multiply is done as ((n << 2) + n) * 2). The caller's
 * return address is handed on, so the callee returns straight to this routine's caller. The last word is the nop
 * the compiler places behind such a call sequence.
 */
extern void sys_ddr_delay(unsigned int n);

/*
 * Wait n * 10 delay units (sys_ddr_delay). sys_ddr_run_script makes the same call for its command 6. Nothing in
 * the image calls this routine.
 */
void sys_ddr_delay_tens(unsigned int n)
{
    sys_ddr_delay(n * 10);
}
