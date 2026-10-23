/* leon2m FUN_a00b1700 @ 0xa00b1700-0xa00b1ba4 (297 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a009f184, FUN_a009f42c.
 * FUN_a00b1700(id, m): FUN_a0090fd8(), FUN_a00b50d8(5). id 0x1e/0x32/0x37: rows = 8, k = 0/1/2; id 0: rows = 11,
 * k = 3 + (m >= 3); other ids: rows = 0, k = 0. FUN_a00b52f8(w, rows, 0x792) with w = 0x37, FUN_a0146ab0(0x91ae, 0);
 * for each row i < rows and column j < w the byte c of the table 0x197f50 (row i, or row i + 3 when i > 2 and
 * rows == 8) plus 0x3f goes to FUN_a0146b20(1, j, i, 1, c, 0) unless it is 0x54. Then FUN_a0146b50(0x60, 0),
 * FUN_a0146b6c(2, 0), two FUN_a00b32e4 calls (ids 0x40 and 0x4f), FUN_a00a31a4(0, 1, 4, 0x35, entry k of the table
 * 0x16dde8 via FUN_a00a3844, 0). For k 3 or 4: FUN_a00b0710(3, 0) and three (byte 0xa802d033 == 2) or four entries of
 * the table 0x190184 (index byte 0xa802d290+8 plus 0, 0x1d, [0x3a,] 0x57) to FUN_a00a31a4 at x 0xb/0x18/0x25 or
 * 5/0x11/0x1d/0x29, plus FUN_a0146a80(x, 8, 8, 0x2c2, 0) at the second x when m == 3. Finally
 * FUN_a014654c((FUN_a014837c(0) - 1320) / 2, FUN_a014837c(1) - rows * 36 - 144, 0) and FUN_a0146dc0(1, 0).
 * Source form: k from the comparison value (cmp 3; subx), the width w = 0x37 in a variable (smul by 0x37, cmp 0x37;
 * bcc), the column test with continue; GCC unswitches the column loop on i > 2.
 * Compiler aid: the empty 'if (c) { }' in the k == 3 or 4 block emits no instructions; that block is reached only
 * with rows = 11, after the row loop has set c. It keeps c live there, which gives c %g1 in the second column loop.
 */
struct R290 { unsigned char p000[8]; unsigned char b008; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802d033;
extern unsigned char DAT_00197f50[];
extern unsigned int DAT_0016dde8[], DAT_00190184[];
extern void FUN_a0090fd8(void);
extern void FUN_a00b50d8(unsigned int);
extern void FUN_a00b52f8(int, int, int);
extern void FUN_a0146ab0(int, int);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, unsigned short, unsigned short, int, unsigned int, int);
extern void FUN_a00b0710(unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned short FUN_a014837c(int);
extern void FUN_a014654c(int, int, int);
extern void FUN_a0146dc0(int, int);

void FUN_a00b1700(unsigned char id, unsigned char m)
{
    unsigned char k, rows, i, j, c, w;

    FUN_a0090fd8();
    FUN_a00b50d8(5);
    k = 0;
    rows = 0;
    if (id == 0x1e || id == 0x32 || id == 0x37) {
        rows = 8;
        if (id == 0x1e)
            k = 0;
        else if (id == 0x32)
            k = 1;
        else if (id == 0x37)
            k = 2;
    } else if (id == 0) {
        k = 3 + (m >= 3);
        rows = 0xb;
    }
    w = 0x37;
    FUN_a00b52f8(w, rows, 0x792);
    FUN_a0146ab0(0x91ae, 0);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < w; j++) {
            if (i > 2 && rows == 8)
                c = DAT_00197f50[(i + 3) * w + j];
            else
                c = DAT_00197f50[i * w + j];
            c += 0x3f;
            if (c == 0x54)
                continue;
            FUN_a0146b20(1, j, i, 1, c, 0);
        }
    }
    FUN_a0146b50(0x60, 0);
    FUN_a0146b6c(2, 0);
    FUN_a00b32e4(1, 1, 0x792, 0x14, 1, 0xf, 0x40);
    FUN_a00b32e4(1, 1, 0x792, 0x14, 2, 0xf, 0x4f);
    FUN_a00a31a4(0, 1, 4, 0x35, FUN_a00a3844(DAT_0016dde8, k), 0);
    if (k == 3 || k == 4) {
        if (DAT_a802d033 == 2) {
            FUN_a00b0710(3, 0);
            FUN_a00a31a4(0, 0xb, 8, 8, FUN_a00a3844(DAT_00190184, DAT_a802d290.b008), 0);
            FUN_a00a31a4(0, 0x18, 8, 8, FUN_a00a3844(DAT_00190184, DAT_a802d290.b008 + 0x1d), 0);
            FUN_a00a31a4(0, 0x25, 8, 8, FUN_a00a3844(DAT_00190184, DAT_a802d290.b008 + 0x57), 0);
            if (m == 3)
                FUN_a0146a80(0x18, 8, 8, 0x2c2, 0);
        } else {
            FUN_a00b0710(3, 0);
            FUN_a00a31a4(0, 5, 8, 8, FUN_a00a3844(DAT_00190184, DAT_a802d290.b008), 0);
            FUN_a00a31a4(0, 0x11, 8, 8, FUN_a00a3844(DAT_00190184, DAT_a802d290.b008 + 0x1d), 0);
            FUN_a00a31a4(0, 0x1d, 8, 8, FUN_a00a3844(DAT_00190184, DAT_a802d290.b008 + 0x3a), 0);
            FUN_a00a31a4(0, 0x29, 8, 8, FUN_a00a3844(DAT_00190184, DAT_a802d290.b008 + 0x57), 0);
            if (m == 3)
                FUN_a0146a80(0x11, 8, 8, 0x2c2, 0);
        }
        if (c) {
        }
    }
    FUN_a014654c((unsigned short)((FUN_a014837c(0) - 1320) / 2), (unsigned short)(FUN_a014837c(1) - rows * 36 - 144), 0);
    FUN_a0146dc0(1, 0);
}
