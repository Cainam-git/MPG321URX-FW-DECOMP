/* CED_ALL_3 (leon2s 0xa00b24b0-0xa00b258c, 220 bytes), flags -mcpu=v8 -Os -g.
 * For a non-zero addr and n words (n = 0 means 32): steps a row pointer in 16-byte steps from addr & ~0x1f up to
 * (addr & ~3) + 4 * n rounded up to 32 bytes. Per row: FUN_a0061348(row), FUN_a0061280(DAT_a006c660), then for four
 * words p: FUN_a0061280(DAT_a006c688) when p is outside [addr & ~3, addr & ~3 + 4 * n), otherwise
 * FUN_a0061348(FUN_a00b22fc(p)) and FUN_a0061280(DAT_a006c690); then FUN_a0061280 with the string at 0xa0069ee8
 * (the last bytes of s_a0069eb8), which is also passed once before and once after the rows. Source forms: addr is masked in place before the n test; the row
 * limit is computed before the loop; each word case makes its own calls.
 */
extern char DAT_a006c660[], DAT_a006c688[], DAT_a006c690[], DAT_a0069ee8[];
extern void FUN_a0061280(const char *);
extern void FUN_a0061348(unsigned int);
extern unsigned int FUN_a00b22fc(unsigned int *);

void CED_ALL_3(unsigned int addr, unsigned int n)
{
    unsigned int *start, *end, *p, *row, *last;
    int j;

    if (addr == 0)
        return;
    addr &= ~3;
    if (n == 0)
        n = 32;
    start = (unsigned int *)addr;
    end = start + n;
    last = (unsigned int *)(((unsigned int)end + 0x1f) & ~0x1f);
    p = (unsigned int *)(addr & ~0x1f);
    FUN_a0061280(DAT_a0069ee8);
    for (row = p; row < last; row += 4) {
        FUN_a0061348((unsigned int)row);
        FUN_a0061280(DAT_a006c660);
        for (j = 0; j < 4; j++) {
            if (p < start || p >= end) {
                FUN_a0061280(DAT_a006c688);
            } else {
                FUN_a0061348(FUN_a00b22fc(p));
                FUN_a0061280(DAT_a006c690);
            }
            p++;
        }
        FUN_a0061280(DAT_a0069ee8);
    }
    FUN_a0061280(DAT_a0069ee8);
}
