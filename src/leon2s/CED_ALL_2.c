/* CED_ALL_2 (leon2s 0xa00b2324-0xa00b24b0, 396 bytes), flags -mcpu=v8 -Os -g.
 * Same row walk as CED_ALL_3, with 16-byte rows: for a non-zero addr and n words (n = 0 means 32), steps a row
 * pointer from addr & ~0xf up to (addr & ~3) + 4 * n rounded up to 16 bytes. Per row: FUN_a0061348(row) and
 * FUN_a0061280(DAT_a006c660); for each of the four words p: outside [addr & ~3, addr & ~3 + 4 * n) the local word
 * buf[j] = 0 and FUN_a0061280(s_a006c668), otherwise buf[j] = FUN_a00b22fc(p) and, for its four bytes low byte
 * first, FUN_a00613cc(byte) and FUN_a0061280(DAT_a006c690). Then FUN_a0061280(DAT_a006c678) and for the 16 bytes
 * of buf FUN_a006122c(byte) when the byte is 0x20..0x7e, else FUN_a0061280(DAT_a006c680). The string at
 * 0xa0069ee8 is passed after every row and once before and once after the rows.
 * Source form: one unsigned char variable c holds the shifted byte in both byte loops.
 */
extern char DAT_a006c660[], s_a006c668[], DAT_a006c678[], DAT_a006c680[], DAT_a006c690[], DAT_a0069ee8[];
extern void FUN_a0061280(const char *);
extern void FUN_a0061348(unsigned int);
extern void FUN_a00613cc(unsigned char);
extern void FUN_a006122c(unsigned char);
extern unsigned int FUN_a00b22fc(unsigned int *);

void CED_ALL_2(unsigned int addr, unsigned int n)
{
    unsigned int *start, *end, *p, *row, *last;
    unsigned int buf[4];
    unsigned int w;
    int j, k;
    unsigned char c;

    if (addr == 0)
        return;
    addr &= ~3;
    if (n == 0)
        n = 32;
    start = (unsigned int *)addr;
    end = start + n;
    last = (unsigned int *)(((unsigned int)end + 0xf) & ~0xf);
    p = (unsigned int *)(addr & ~0xf);
    FUN_a0061280(DAT_a0069ee8);
    for (row = p; row < last; row += 4) {
        FUN_a0061348((unsigned int)row);
        FUN_a0061280(DAT_a006c660);
        for (j = 0; j < 4; j++) {
            if (p < start || p >= end) {
                buf[j] = 0;
                FUN_a0061280(s_a006c668);
            } else {
                w = buf[j] = FUN_a00b22fc(p);
                for (k = 0; k < 4; k++) {
                    c = w >> (k * 8);
                    FUN_a00613cc(c);
                    FUN_a0061280(DAT_a006c690);
                }
            }
            p++;
        }
        FUN_a0061280(DAT_a006c678);
        for (j = 0; j < 4; j++) {
            w = buf[j];
            for (k = 0; k < 4; k++) {
                c = w >> (k * 8);
                if ((unsigned char)(c - 0x20) < 0x5f)
                    FUN_a006122c(c);
                else
                    FUN_a0061280(DAT_a006c680);
            }
        }
        FUN_a0061280(DAT_a0069ee8);
    }
    FUN_a0061280(DAT_a0069ee8);
}
