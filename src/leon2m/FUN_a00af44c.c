/* leon2m FUN_a00af44c @ 0xa00af44c-0xa00b0034 (-mcpu=v8 -O3 -g -msoft-float)
 * Draws the rows of one settings page. Calls FUN_a00a8c88(), then by page (0xb, 0xe, 0x15, 0x18, 0x23, 0x26, 0x2a,
 * 0x34) and sel: either calls the page's own routine, or clears the area (FUN_a0146b50(0x111, 0), FUN_a0146b6c(0,
 * 0)) and writes row i at line i * 2 + 6 with FUN_a00a31a4(0, 0x2a, line, 1, FUN_a00a3844(table, index), 0), where
 * index = i * 29 + byte +8 of the record DAT_a802d290 (29 entries per row). mark(v) puts the two markers at
 * line v * 2 + 6 (v < 7) or v * 2 - 8 with FUN_a0146b20 in columns 0x28 and 0x29; FUN_a00a9650(v, 2) follows with
 * the selected value (a byte or bit field of DAT_a802d290, or DAT_a802d40c/d412/d430/d2da). Page 0x18 sel 4 sets
 * DAT_a802b08f to 0xe around its rows and marks rows that FUN_a00aad30(i) rejects with FUN_a0146a80. Page 0x34
 * calls FUN_a00ac718(sel + 0x34).
 * Source form: the word table at 0x190cec is named ARR_00190cec. GCSE (gcse.c) numbers the registers it creates
 * in the order of its expression hash buckets, and the bucket of a symbol depends on the characters of its name;
 * with this name the table address and the record base of page 0x18 sel 5 get %i5 and %i4 as in the firmware.
 */
struct R290 {
    unsigned char p000[8];
    unsigned char b008;
    unsigned char p009[0x11 - 0x09];
    unsigned char b011;
    unsigned char p012[0x1e - 0x12];
    unsigned char b01e;
    unsigned char p01f;
    unsigned char b020;
    unsigned char p021[0xa8 - 0x21];
    unsigned int w0a8;
    unsigned int w0ac;
    unsigned char p0b0[0x15b - 0xb0];
    unsigned char b15b;
    unsigned char p15c[0x181 - 0x15c];
    unsigned char b181;
    unsigned char p182[0x18a - 0x182];
    unsigned char a18a[0x1a3 - 0x18a];
    unsigned char b1a3;
    unsigned char b1a4;
};
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802d40c, DAT_a802d412, DAT_a802d430, DAT_a802d2da, DAT_a802b08f;
struct W2c4 {
    unsigned int hi : 12;
    unsigned int f16 : 4;
    unsigned int f12 : 4;
    unsigned int lo : 12;
};
extern struct W2c4 DAT_a802d2c4;
extern unsigned int DAT_0018f984[], ARR_00190cec[], DAT_0018db28[], DAT_001910b0[], DAT_001828c0[],
    DAT_001890d4[], DAT_0018e9f8[], DAT_00193248[], DAT_00190748[];

extern void FUN_a00a8c88(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00ac718(unsigned int);
extern void FUN_a00aee44(unsigned char, unsigned char);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);
extern void FUN_a00b6bec(unsigned char);
extern void FUN_a00b7b8c(unsigned char);
extern void FUN_a00a87cc(unsigned char);
extern void FUN_a00ac388(int);
extern void FUN_a00a9abc(void);
extern void FUN_a00b617c(void);
extern void FUN_a00b6e1c(void);
extern void FUN_a00b6f20(int);
extern void FUN_a00b7054(void);
extern void FUN_a00b7188(int);
extern void FUN_a00b7530(int);
extern void FUN_a00b7674(int);
extern void FUN_a00b77b4(void);
extern void FUN_a00b789c(void);
extern void FUN_a00b7a44(void);
extern void FUN_a00b7ae4(void);

static void mark(unsigned char b)
{
    unsigned char y;

    if (b < 7)
        y = b * 2 + 6;
    else
        y = b * 2 - 8;
    FUN_a0146b20(0, 0x28, y, 1, 0xf, 0);
    FUN_a0146b20(0, 0x29, y, 1, 0x10, 0);
}

void FUN_a00af44c(unsigned short page, unsigned char sel)
{
    unsigned char i;

    FUN_a00a8c88();
    switch (page) {
    case 0xb:
        if (sel == 0) {
            FUN_a00b7a44();
            FUN_a00a9650(DAT_a802d40c, 2);
        } else if (sel == 1) {
            FUN_a0146b50(0x111, 0);
            FUN_a0146b6c(0, 0);
            for (i = 0; i <= 3; i++)
                FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018f984, DAT_a802d290.b008 + 29 + i * 29), 0);
        } else if (sel == 2) {
            FUN_a00b7ae4();
            FUN_a00a9650(DAT_a802d2da + 2, 2);
        }
        break;
    case 0xe:
        if (sel == 0) {
            FUN_a00b617c();
            FUN_a00a9650(DAT_a802d412, 2);
        } else if (sel == 1) {
            FUN_a0146b50(0x111, 0);
            FUN_a0146b6c(0, 0);
            for (i = 0; i <= 4; i++)
                FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_001890d4, i * 29 + DAT_a802d290.b008), 0);
            mark(DAT_a802d290.b15b);
            FUN_a00a9650(DAT_a802d290.b15b, 2);
        } else if (sel == 2)
            FUN_a00aee44(page, sel);
        else if (sel == 3) {
            FUN_a0146b50(0x111, 0);
            FUN_a0146b6c(0, 0);
            FUN_a00a31a4(0, 0x2a, 6, 1, FUN_a00a3844(DAT_0018e9f8, DAT_a802d290.b008 + 5 * 29), 0);
            for (i = 1; i <= 2; i++)
                FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_00193248, (i - 1) * 29 + DAT_a802d290.b008), 0);
            mark(((DAT_a802d290.w0a8 >> 12) & 1) + 1);
            FUN_a00a9650(((DAT_a802d290.w0a8 >> 12) & 1) + 1, 2);
        } else if (sel == 4) {
            FUN_a00ac388(1);
            FUN_a00a9650(DAT_a802d430 + 1, 2);
        } else if (sel == 5)
            FUN_a00aee44(page, sel);
        else if (sel == 6)
            FUN_a00aee44(page, sel);
        break;
    case 0x15:
        if (sel == 0) {
            FUN_a00b6bec(FUN_a00b6b88(DAT_a802d290.b181, 0) / 7);
            mark(FUN_a00b6b88(DAT_a802d290.b181, 0) % 7);
            FUN_a00a9650(FUN_a00b6b88(DAT_a802d290.b181, 0) % 7, 2);
        } else if (sel == 2) {
            FUN_a00b6e1c();
            FUN_a00a9650(DAT_a802d2c4.f16, 2);
        }
        break;
    case 0x18:
        if (sel == 0)
            FUN_a00b7054();
        else if (sel == 1)
            FUN_a00b6f20(0);
        else if (sel == 2)
            FUN_a00b7188(0);
        else if (sel == 3) {
            FUN_a0146b50(0x111, 0);
            FUN_a0146b6c(0, 0);
            for (i = 0; i <= 3; i++)
                FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018db28, i * 29 + DAT_a802d290.b008), 0);
            mark(DAT_a802d290.b011);
            FUN_a00a9650(DAT_a802d290.b011, 2);
        } else if (sel == 4) {
            unsigned char save, n;

            FUN_a0146b50(0x111, 0);
            FUN_a0146b6c(0, 0);
            save = DAT_a802b08f;
            DAT_a802b08f = 0xe;
            n = 7;
            for (i = 0; i < n; i++) {
                if (FUN_a00aad30(i) == 0)
                    FUN_a0146a80(0x2a, i * 2 + 6, 0xa, 0x296, 0);
                FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_001910b0, i * 29 + DAT_a802d290.b008), 0);
            }
            mark(DAT_a802d290.b1a4);
            DAT_a802b08f = save;
            FUN_a00a9650(DAT_a802d290.b1a4, 2);
        } else if (sel == 5) {
            FUN_a0146b50(0x111, 0);
            FUN_a0146b6c(0, 0);
            for (i = 0; i <= 2; i++)
                FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(ARR_00190cec, i * 29 + DAT_a802d290.b008), 0);
            mark((DAT_a802d290.w0ac >> 18) & 3);
            FUN_a00a9650((DAT_a802d290.w0ac >> 18) & 3, 2);
        }
        break;
    case 0x23:
        if (sel == 1) {
            FUN_a0146b50(0x111, 0);
            FUN_a0146b6c(0, 0);
            if (DAT_a802d290.b01e == DAT_a802d290.b020) {
                FUN_a0146a80(0x2a, 0xc, 0xb, 0x296, 0);
                FUN_a0146a80(0x2a, 0xe, 0xb, 0x296, 0);
            }
            for (i = 0; i <= 4; i++)
                FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_001828c0, i * 29 + DAT_a802d290.b008), 0);
        } else if (sel == 2)
            FUN_a00a9abc();
        else
            FUN_a00aee44(page, sel);
        break;
    case 0x26:
        if (DAT_a802d290.a18a[DAT_a802d290.b1a3] > 6)
            FUN_a00b7b8c(1);
        else
            FUN_a00b7b8c(0);
        FUN_a00a9650(DAT_a802d290.a18a[DAT_a802d290.b1a3] % 7, 2);
        mark(DAT_a802d290.a18a[DAT_a802d290.b1a3] % 7);
        break;
    case 0x2a:
        if (sel == 0) {
            FUN_a00a87cc(DAT_a802d290.b008 / 7);
            FUN_a00a9650(DAT_a802d290.b008 % 7, 2);
            mark(DAT_a802d290.b008 % 7);
        } else if (sel == 1)
            FUN_a00b7530(0);
        else if (sel == 2)
            FUN_a00b7674(0);
        else if (sel == 3)
            FUN_a00b77b4();
        else if (sel == 4) {
            FUN_a00b789c();
            FUN_a00a9650((DAT_a802d290.w0a8 >> 15) & 1, 2);
        } else if (sel == 9) {
            unsigned char j;

            FUN_a0146b50(0x111, 0);
            FUN_a0146b6c(0, 0);
            for (j = 0; j <= 1; j++)
                FUN_a00a31a4(0, 0x2a, j * 2 + 6, 1, FUN_a00a3844(DAT_00190748, j * 29 + DAT_a802d290.b008), 0);
        }
        break;
    case 0x34:
        FUN_a00ac718((unsigned short)(sel + 0x34));
        break;
    }
}
