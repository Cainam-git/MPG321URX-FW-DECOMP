/* leon2m FUN_a00e0788 @ 0xa00e0788 (-mcpu=v8 -O3 -g -msoft-float)
 * Polls a PHY register until (value & mask) == expect: up to 10 rounds of FUN_a00dffa4(2) followed by
 * FUN_a00e02ec(phy, addr). Returns 1 when the value matched, 0 after 10 failed rounds.
 * When the word DAT_a802b550 is non-zero it prints the "checkphy ..." trace lines (start, every value read, pass or
 * error) through FUN_a00df170.
 * Build: -msoft-float changes the loop's hoisting of the flag loads and string addresses (the image has no FPU code).
 */
extern int DAT_a802b550;
extern void FUN_a00dffa4(unsigned int);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e02ec(int phy, unsigned int addr);

int FUN_a00e0788(int phy, unsigned int addr, unsigned int mask, unsigned int expect)
{
    int n;
    unsigned int v;

    if (DAT_a802b550 != 0)
        FUN_a00df170("checkphy wait [0x%08x] & 0x%08x = %08x\n", addr, mask, expect);
    for (n = 0; n < 10; n++) {
        FUN_a00dffa4(2);
        v = FUN_a00e02ec(phy, addr) & mask;
        if (DAT_a802b550 != 0)
            FUN_a00df170("checkphy current=0x%08x\n", v);
        if (v == expect) {
            if (DAT_a802b550 != 0)
                FUN_a00df170("checkphy [0x%08x] pass\n", addr);
            return 1;
        }
    }
    if (DAT_a802b550 != 0)
        FUN_a00df170("checkphy [0x%08x]=%08x error: %08x\n", addr, expect, v);
    return 0;
}
