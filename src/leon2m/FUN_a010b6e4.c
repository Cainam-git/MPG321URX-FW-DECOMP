/* leon2m FUN_a010b6e4 @ 0xa010b6e4-0xa010b77c (38 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/38 mismatches.
 * What it does: a set-then-clear pulse of bits 10 (0x400) and 14 (0x4000) in the twin hardware
 * registers 0xd00300f0 and 0xd00380f0 (two blocks 0x8000 apart; volatile = real registers).
 * Order (fw): set bit 10 in 300f0, then 380f0; set bit 14 in 300f0, then 380f0; call the ROM routine
 * func_0x4008e2a4() twice (no args; it is called 2-3 times back to back in FUN_a0106b08 and
 * FUN_a008a434 too); clear bit 10 in both, then bit 14 in both. Every step is its own read-modify-write.
 * Caller: the output rate set-up FUN_a0106b08, only for block 0 (param == 0), after FUN_a0106920.
 * Nothing depends on the input; the same pulse is sent for every rate set-up on block 0.
 * Fix vs the autoc draft (Ghidra merged the RMWs into '|= 0x4400' and returned a param): four
 * separate RMW pairs per phase, void(void). Aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void func_0x4008e2a4(void);

void FUN_a010b6e4(void)
{
    R(0xd00300f0) |= 0x400;
    R(0xd00380f0) |= 0x400;
    R(0xd00300f0) |= 0x4000;
    R(0xd00380f0) |= 0x4000;
    func_0x4008e2a4();
    func_0x4008e2a4();
    R(0xd00300f0) &= ~0x400;
    R(0xd00380f0) &= ~0x400;
    R(0xd00300f0) &= ~0x4000;
    R(0xd00380f0) &= ~0x4000;
}
