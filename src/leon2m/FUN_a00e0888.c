/* leon2m FUN_a00e0888 @ 0xa00e0888-0xa00e09b8 (76 words), -mcpu=v8 -O3 -g -msoft-float.
 * Polls a PHY register like FUN_a00e0788: up to 10 rounds of FUN_a00dffa4(2) followed by FUN_a00e02ec(phy, addr).
 * Returns 1 when (value & mask) == expect. When the word DAT_a802b550 is non-zero it prints the "checkphy ..."
 * trace lines (start, every value read, pass or error) through FUN_a00df170.
 * After 10 failed rounds it calls FUN_a00df80c and FUN_a00e0bc0, reads the register once more with
 * FUN_a00e02ec(phy, addr), prints "checkphy [addr]=expect error: value" with that value (always) and returns 0.
 * Called by FUN_a00e0e44.
 * Source form: one return statement for both results: a match sets ret = 1 and jumps to it, the error path sets
 * ret = 0 before its last print. The unconditional error print takes its format from the read-only array err_ (same
 * text as the trace line; the firmware holds one copy), so the two prints load the address separately.
 * Build: -msoft-float, as FUN_a00e0788.
 */
extern int DAT_a802b550;
extern void FUN_a00dffa4(unsigned int);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e02ec(int phy, unsigned int addr);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);

static const char err_[] = "checkphy [0x%08x]=%08x error: %08x\n";

int FUN_a00e0888(int phy, unsigned int addr, unsigned int mask, unsigned int expect)
{
    int n;
    unsigned int v;
    int ret;

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
            ret = 1;
            goto out;
        }
    }
    if (DAT_a802b550 != 0)
        FUN_a00df170("checkphy [0x%08x]=%08x error: %08x\n", addr, expect, v);
    FUN_a00df80c();
    FUN_a00e0bc0();
    ret = 0;
    FUN_a00df170(err_, addr, expect, FUN_a00e02ec(phy, addr));
out:
    return ret;
}
