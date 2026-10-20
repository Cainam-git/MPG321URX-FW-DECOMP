/* CED_ALL_3 (leon2s 0xa00b24b0-0xa00b258c, 220 bytes), flags -mcpu=v8 -Os -g.
 * Memory dump on the UART: for a non-zero address addr and n words (n = 0 means 32), prints rows of four words
 * from addr & ~0x1f up to the end rounded up to 32 bytes. Each row: the row address in hex (FUN_a0061348) and
 * DAT_a006c660; per word either DAT_a006c688 (outside [addr & ~3, addr + n words)) or the word read by
 * FUN_a00b22fc in hex and DAT_a006c690. Rows and the dump end with the string at 0xa0069ee8 (the last bytes of
 * s_a0069eb8). Strings go through FUN_a0061280. Source forms: addr is masked in place before the n test; the row
 * limit is computed before the loop; each word case calls the print routines itself.
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
