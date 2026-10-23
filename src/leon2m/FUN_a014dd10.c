/* FUN_a014dd10 (leon2m 0xa014dd10-0xa014dd20, 16 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls func_0x4008ced8() as a tail call ('mov %o7, %g1; call; mov %g1, %o7'); the nop after it is the -g line nop.
 * func_0x4008ced8 is the start-up routine FUN_a002ced8: main-program code runs at its name address - 0xa0060000, so
 * the call reaches 0xa002ced8 (0x4008ced8 = 0xa002ced8 + 0xa0060000 mod 2^32). Called by FUN_a0127c78 (2 calls). It
 * lies between FUN_a014dc74 and FUN_a014dd20. Source form: a void wrapper; whatever arguments are in %o0..%o5 reach
 * the callee unchanged.
 */
extern void func_0x4008ced8(void);

void FUN_a014dd10(void)
{
    func_0x4008ced8();
}
