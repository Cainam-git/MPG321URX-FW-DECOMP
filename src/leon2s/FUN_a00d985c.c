/* FUN_a00d985c (leon2s 0xa00d985c-0xa00d9988, 300 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00d95e4() and clears DAT_a8078847 when its result minus 0x10, as a byte, is 0 or 1. Takes record
 * rec = ARR_a807963d[DAT_a8078832][DAT_a8078828[DAT_a8078832] & 0xf] (16 records of 0x30 bytes per
 * DAT_a8078832 value); k = (rec[0] >> 4) - 1 (int), off = k / 2, plus 1 when k is odd; n = rec[off + 1] & 0x3f;
 * d = (DAT_a80787ff & 0xf) * 3. Copies rec[off + 3 + i] to ARR_a807a520[d][off + 3 + i] (16-byte rows) for
 * i = 0..n-1, then stores off + n + 3 in DAT_a8079c88[DAT_a80787ff] and sets DAT_a80787ff to
 * (DAT_a80787ff + 1) & 0xf.
 * Source form: the copy loop is an inlined helper put(d, off, rec, n) with n unsigned int that reads
 * (rec + off)[i + 3] inside the loop (this gives the register copy of rec + off before the loop); the caller
 * reads n through p = &rec[off].
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078828[];
extern unsigned char DAT_a8078847;
extern unsigned char DAT_a80787ff;
extern unsigned char ARR_a807963d[][16][0x30];
extern unsigned char ARR_a807a520[][16];
extern unsigned char DAT_a8079c88[];
extern unsigned char FUN_a00d95e4(void);

static inline void put(unsigned int d, unsigned char off, unsigned char *rec, unsigned int n)
{
    unsigned char i;

    for (i = 0; i < n; i++)
        ARR_a807a520[d][i + off + 3] = (rec + off)[i + 3];
}

void FUN_a00d985c(void)
{
    unsigned char (*row)[0x30];
    unsigned int c;
    unsigned char *p;
    unsigned char i, n, off;
    unsigned int j;
    unsigned int d;
    int k, h;

    if ((unsigned char)(FUN_a00d95e4() - 0x10) <= 1)
        DAT_a8078847 = 0;
    row = ARR_a807963d[DAT_a8078832];
    c = DAT_a8078828[DAT_a8078832] & 0xf;
    k = (row[c][0] >> 4) - 1;
    d = (DAT_a80787ff & 0xf) * 3;
    h = k / 2;
    off = h;
    if (k & 1)
        off = h + 1;
    p = &row[c][off];
    n = p[1] & 0x3f;
    put(d, off, row[c], n);
    j = DAT_a80787ff;
    DAT_a8079c88[j] = off + n + 3;
    DAT_a80787ff = (j + 1) & 0xf;
}
