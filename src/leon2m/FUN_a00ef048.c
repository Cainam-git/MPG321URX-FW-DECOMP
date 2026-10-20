/* leon2m FUN_a00ef048 @ 0xa00ef048-0xa00ef1b0 (90 words; Ghidra's header says -0xa00ef140, see below).
 * Flags -mcpu=v8 -O3 -g, over the real range 0xa00ef048-0xa00ef1b0; over that range the compiled jump table equals
 * the firmware table. Written from the assembly.
 * The function really ends at 0xa00ef1b0. Ghidra cut it: FUN_a00ef140 (0xa00ef140-0xa00ef164, no callers, only a
 * jump-table target) and the unlisted 0xa00ef164-0xa00ef1b0 are its case blocks. The switch table (fw 0x8ef5c,
 * run-time words) sends p 0 -> 0xef164, 1 -> 0xef170, 2 -> 0xef07c, 3 -> 0xef180, 4/5 -> 0xef194 (no action), 6 ->
 * 0xef19c, 7 -> 0xef140; p > 7 skips the switch.
 * What it does (dc6c state 5 'port ready' step, bit 17; called as FUN_a00ef048(PORT(c))):
 *   DAT_a8026a79 = p;
 *   p 0: DAT_a8026a78 = 0;                 p 1: DAT_a8026a78 = 1;
 *   p 2: 0xcf014750 &= ~1, a78 = 2;        p 6: 0xcf014750 |= 1, a78 = 2;
 *   p 3: 0xcf014750 &= ~4, a78 = 3;        p 7: 0xcf014750 |= 4, a78 = 3;   (p 4, 5, > 7: a78 kept)
 *   then a78 == 8: write 0x16 to all 4 registers named by the u16 table DAT_00199ffc (0xcf000000 | idx << 2);
 *   else a78 < 4: write 0x16 to the one register DAT_00199ffc[a78];
 *   last: FUN_a00f232c(DAT_a8026a79, 0x88, 0x20, 0) = clear bit 5 of reg 0x88 of block a79 (tail call).
 * Nothing here depends on the input rate; it is the per-port select step before state 6.
 * DAT_a8026a79 is read back for the call (the register stores may alias it: fw 'ldub [%o7+0x279]' after them).
 * Source form: case order 0, 1, 2, 6, 3, 7 (the two 'a78 = 2' cases, then the two 'a78 = 3' cases); 3 before 6 swaps
 * the registers of those two blocks. volatile only on real hardware registers. Compiler aids: none.
 */
extern void FUN_a00f232c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char DAT_a8026a78, DAT_a8026a79;
extern const unsigned short DAT_00199ffc[4];
#define R(a) (*(volatile unsigned int *)(a))
#define REG16(i) (*(volatile unsigned int *)(0xcf000000 | (DAT_00199ffc[i] << 2)))

void FUN_a00ef048(unsigned char p)
{
    unsigned char i;

    DAT_a8026a79 = p;
    switch (p) {
    case 0: DAT_a8026a78 = 0; break;
    case 1: DAT_a8026a78 = 1; break;
    case 2: R(0xcf014750) &= ~1; DAT_a8026a78 = 2; break;
    case 6: R(0xcf014750) |= 1; DAT_a8026a78 = 2; break;
    case 3: R(0xcf014750) &= ~4; DAT_a8026a78 = 3; break;
    case 7: R(0xcf014750) |= 4; DAT_a8026a78 = 3; break;
    }
    if (DAT_a8026a78 == 8) {
        for (i = 0; i < 4; i++)
            REG16(i) = 0x16;
    } else if (DAT_a8026a78 < 4) {
        REG16(DAT_a8026a78) = 0x16;
    }
    FUN_a00f232c(DAT_a8026a79, 0x88, 0x20, 0);
}
