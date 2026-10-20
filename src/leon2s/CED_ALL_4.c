/* CED_ALL_4 (leon2s 0xa00b258c-0xa00b25f8, 108 bytes), flags -mcpu=v8 -Os -g.
 * For a non-zero address addr: prints DAT_a006c698, addr as 8 hex digits (FUN_a0061348) and DAT_a006c6b0 on the
 * UART (FUN_a0061280). An address that is not word aligned prints s_a006c6a0 ("Address Fail" per Ghidra);
 * otherwise stores val through FUN_a00b2304(addr, val), prints val in hex and the string at 0xa0069ee8 (the
 * last bytes of the string s_a0069eb8).
 */
extern char DAT_a006c698[], DAT_a006c6b0[], s_a006c6a0[], DAT_a0069ee8[];
extern void FUN_a0061280(const char *);
extern void FUN_a0061348(unsigned int);
extern void FUN_a00b2304(unsigned int *, unsigned int);

void CED_ALL_4(unsigned int addr, unsigned int val)
{
    if (addr == 0)
        return;
    FUN_a0061280(DAT_a006c698);
    FUN_a0061348(addr);
    FUN_a0061280(DAT_a006c6b0);
    if (addr & 3) {
        FUN_a0061280(s_a006c6a0);
    } else {
        FUN_a00b2304((unsigned int *)addr, val);
        FUN_a0061348(val);
        FUN_a0061280(DAT_a0069ee8);
    }
}
