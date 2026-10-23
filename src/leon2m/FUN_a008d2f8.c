/* leon2m FUN_a008d2f8 @ 0xa008d2f8-0xa008e270 (990 words), flags -mcpu=v8 -O3 -g. Called from FUN_a008e270,
 * FUN_a009e91c and FUN_a009eb38. No parameters, no return value.
 * Clears bit 6 of halfword 0xa802cff8 and sets byte 0xa802afbb to 1, runs a fixed call sequence (FUN_a0146dc0,
 * func_0x4008e2a4 three times, FUN_a0146298 ... FUN_a0146b6c), then passes ROM strings (0x1002a0-0x100470) with
 * fixed (x, y, length) values, or with positions from the 3-byte records {col, row, len} of the ROM table 0x100242,
 * to FUN_a00a31a4. Values go to FUN_a008a568(id, v): the bytes 0xa802e1f6-e1fb / e202-e204, (b * 255 + 50) / 100 of
 * the bytes 0xa802d2a2-d2a4, bytes 0xa802d299 / d29a, FUN_a01266b0(), 0xa802afba, 0xa802afb9, halfword 0xa802d46a.
 * On/off pairs choose 0x1002a8 or 0x1002a0 (byte 0xa802d465 == 1, halfword 0xa802d486 == 0x55aa, FUN_a0145af8(2)
 * and (0x10), bit 7 of word 0xa802d464, byte 0xa8024040 == 1) and 0x100468 or 0x100470 (FUN_a0145af8(0x11)).
 * Sets byte 0xa802afbd to 0x1a and passes record afbd of 0x100242 to FUN_a0146a80(col, row, len, 0x90, 0).
 * The n = byte 0xa802d276 bytes from 0xa802d277 are copied into a variable-length buffer v[n + 1]; v[0] becomes the
 * index of the first 0 byte (or n), 0xff bytes become ' ', and v goes to FUN_a00a31a4(0, 6, 0x19, n + 1, v, 0).
 * Number fields are formatted with FUN_a01577f4 (format strings 0x100510 5 digits, 0x100508 2 digits, 0x100480 3
 * digits; characters mapped ' ' -> 0, others - 47) and passed to FUN_a0146af4; two fields use format 0x100518 into
 * a zeroed 7-byte buffer whose byte 0 is then set to (index of the first 0 byte) - 1 before FUN_a00a31a4. Ends with
 * FUN_a00a45a8().
 * Source form: the number fields are static helpers inlined by GCC (put5/put2 read word 0xa802e1a0+8 like
 * FUN_a008cdf0 / FUN_a008ccc0); the value argument of putn is read before its clearing loop; the format strings
 * and texts are separate ROM symbols (one sethi per symbol, shared between uses of the same symbol); record 26 of
 * 0x100242 for FUN_a0146a80 is indexed by DAT_a802afbd after the store; the 0x11 choice is written
 * 'if (!FUN_a0145af8(0x11))' with the 0x100470 arm first; bit 6 of 0xa802cff8 is cleared through a bit-field
 * (the mask form schedules the halfword store after the next one).
 */
struct CFF4 { unsigned short h0, h2; struct { unsigned short b15_7 : 9, b6 : 1, b5_0 : 6; } h4; };
struct Fac290 {                         /* 0xA802D290 */
    unsigned char b000[9];
    unsigned char b009, b00a;           /* +0x009 */
    unsigned char b00b[7];
    unsigned char b012, b013, b014;     /* +0x012 */
    unsigned char b015[0x1bf];
    union {
        unsigned int w;
        unsigned char b[4];             /* b[1] = +0x1d5 */
    } u1d4;                             /* +0x1d4 */
    unsigned short h1d8, h1da;          /* +0x1d8 */
    unsigned char b1dc[0x1a];
    unsigned short h1f6;                /* +0x1f6 */
};
struct Fac1f0 {                         /* 0xA802E1F0 */
    unsigned char b0[6];
    unsigned char f6, f7, f8, f9, fa, fb;     /* +0x06 */
    unsigned char b0c[6];
    unsigned char f12, f13, f14;              /* +0x12 */
};
struct Log274 {                         /* 0xA802D274 */
    unsigned char b0, b1, n;
    unsigned char d[0x12];              /* +0x03 */
    unsigned char b15;                  /* +0x15 */
    unsigned short h16, h18;            /* +0x16 */
};
struct E1a0 { unsigned int w0, w4, w8; };
struct Pos { unsigned char col, row, len; };

extern struct CFF4 DAT_a802cff4;
extern unsigned char DAT_a802afbb, DAT_a802afbd, DAT_a802afba, DAT_a802afb9, DAT_a8024040;
extern struct Fac290 DAT_a802d290;
extern struct Fac1f0 DAT_a802e1f0;
extern struct Log274 DAT_a802d274;
extern struct E1a0 DAT_a802e1a0;
extern const struct Pos DAT_00100242[];
extern const char s_001002a0[], s_001002a8[], s_001002b0[], s_001002c0[], s_001002e8[], s_00100300[];
extern const char s_00100330[], s_00100340[], s_00100348[], s_00100350[], s_00100358[], s_00100360[];
extern const char s_00100370[], s_00100378[], s_00100380[], s_00100388[], s_00100390[], s_00100398[];
extern const char s_001003a0[], s_001003a8[], s_001003b8[], s_001003c8[], s_001003d0[], s_001003e0[];
extern const char s_001003f0[], s_00100400[], s_00100408[], s_00100410[], s_00100418[], s_00100420[];
extern const char s_00100428[], s_00100430[], s_00100438[], s_00100440[], s_00100450[], s_00100458[];
extern const char s_00100460[], s_00100468[], s_00100470[], s_00100480[], s_00100508[], s_00100510[];
extern const char s_00100518[];

extern void FUN_a0146dc0(int, int);
extern void func_0x4008e2a4(void);
extern void FUN_a0146298(int, int);
extern void FUN_a0146354(int, int, int);
extern unsigned short FUN_a0146194(int, int);
extern void FUN_a0146370(unsigned char, unsigned int, unsigned char);
extern void FUN_a00a28bc(void);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146518(unsigned short, unsigned short, unsigned char);
extern void FUN_a0146ab0(int, int);
extern void FUN_a0146108(int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a008a568(unsigned char, unsigned short);
extern unsigned short FUN_a0145af8(unsigned int id);
extern unsigned short FUN_a01266b0(void);
extern void FUN_a008b380(void);
extern void FUN_a008b5e0(void);
extern void FUN_a01577f4(unsigned char *, const char *, unsigned short);
extern void FUN_a0146af4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern unsigned short FUN_a00dab30(void);
extern void FUN_a00a45a8(void);

static void put5(unsigned char a, unsigned char b)
{
    unsigned char buf[8];
    unsigned char i;

    FUN_a01577f4(buf, s_00100510, DAT_a802e1a0.w8 >> 8);
    for (i = 0; i < 5; i++) {
        if (buf[i] == ' ')
            buf[i] = 0;
        else
            buf[i] -= 47;
    }
    FUN_a0146af4(0, a, b, 5, buf, 0);
}

static void put2(unsigned char a, unsigned char b)
{
    unsigned char buf[8];
    unsigned char i;

    FUN_a01577f4(buf, s_00100508, DAT_a802e1a0.w8 >> 24);
    for (i = 0; i < 2; i++) {
        if (buf[i] == ' ')
            buf[i] = 0;
        else
            buf[i] -= 47;
    }
    FUN_a0146af4(0, a, b, 2, buf, 0);
}

static void putn(unsigned char a, unsigned char b, unsigned short v)
{
    unsigned char buf[8];
    unsigned char i;

    for (i = 0; i < 7; i++)
        buf[i] = 0;
    FUN_a01577f4(buf, s_00100518, v);
    for (i = 0; i < 7; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    FUN_a00a31a4(0, a, b, buf[0], (const char *)buf, 0);
}

static void put3(unsigned char a, unsigned char b, unsigned short v)
{
    unsigned char buf[8];
    unsigned char i;

    FUN_a01577f4(buf, s_00100480, v);
    for (i = 0; i < 3; i++) {
        if (buf[i] == ' ')
            buf[i] = 0;
        else
            buf[i] -= 47;
    }
    FUN_a0146af4(0, a, b, 3, buf, 0);
}

void FUN_a008d2f8(void)
{
    unsigned char i;
    unsigned char x, y;

    DAT_a802cff4.h4.b6 = 0;
    DAT_a802afbb = 1;
    FUN_a0146dc0(0, 0);
    func_0x4008e2a4();
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a0146dc0(0, 0);
    FUN_a0146298(4, 0);
    FUN_a0146354(0x18, 0x24, 0);
    FUN_a0146370(0, FUN_a0146194(0x18, 0x25), 0);
    FUN_a00a28bc();
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    FUN_a014613c(0x18, 0x25, 0);
    FUN_a0146518(1, 0x62, 0);
    FUN_a0146ab0(0x790, 0);
    func_0x4008e2a4();
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a0146108(0);
    FUN_a0146b50(0xb, 0);
    FUN_a0146b6c(0, 0);
    FUN_a00a31a4(0, 1, 5, 6, s_00100460, 0);
    FUN_a00a31a4(0, 1, 6, 6, s_00100458, 0);
    FUN_a00a31a4(0, 1, 7, 4, s_00100450, 0);
    FUN_a00a31a4(0, 1, 8, 8, s_00100440, 0);
    FUN_a00a31a4(0, 6, 9, 3, s_00100438, 0);
    FUN_a00a31a4(0, 0xe, 9, 3, s_00100430, 0);
    FUN_a00a31a4(0, 1, 0xb, 3, s_00100428, 0);
    FUN_a00a31a4(0, DAT_00100242[16].col, DAT_00100242[16].row, 5, s_00100420, 0);
    FUN_a00a31a4(0, DAT_00100242[15].col, DAT_00100242[15].row, 4, s_00100418, 0);
    FUN_a00a31a4(0, 1, 0xd, 7, s_00100410, 0);
    FUN_a00a31a4(0, 1, 0xe, 5, s_00100408, 0);
    FUN_a00a31a4(0, 1, 0xf, 1, s_00100400, 0);
    FUN_a00a31a4(0, DAT_00100242[20].col, DAT_00100242[20].row, 0xe, s_001003f0, 0);
    FUN_a00a31a4(0, DAT_00100242[23].col, DAT_00100242[23].row, 0xc, s_001003e0, 0);
    FUN_a00a31a4(0, 1, 0x11, 9, s_001003d0, 0);
    FUN_a00a31a4(0, 1, 0x12, 5, s_001003c8, 0);
    FUN_a00a31a4(0, 1, 0x14, 0xc, s_001003b8, 0);
    FUN_a00a31a4(0, DAT_00100242[26].col, DAT_00100242[26].row, 8, s_001003a8, 0);
    for (i = 5; i < 9; i++) {
        FUN_a0146a80(1, i, 0x16, 0x290, 0);
        FUN_a00a31a4(0, 8, i, 1, s_001003a0, 0);
        FUN_a00a31a4(0, 0xc, i, 1, s_00100398, 0);
        FUN_a00a31a4(0, 0x10, i, 1, s_00100390, 0);
    }
    FUN_a008a568(1, DAT_a802e1f0.f6);
    FUN_a008a568(2, DAT_a802e1f0.f7);
    FUN_a008a568(3, DAT_a802e1f0.f8);
    FUN_a008a568(4, DAT_a802e1f0.f12);
    FUN_a008a568(5, DAT_a802e1f0.f13);
    FUN_a008a568(6, DAT_a802e1f0.f14);
    FUN_a008a568(7, (DAT_a802d290.b012 * 255u + 50) / 100);
    FUN_a008a568(8, (DAT_a802d290.b013 * 255u + 50) / 100);
    FUN_a008a568(9, (DAT_a802d290.b014 * 255u + 50) / 100);
    FUN_a008a568(0xa, DAT_a802e1f0.f9);
    FUN_a008a568(0xb, DAT_a802e1f0.fa);
    FUN_a008a568(0xc, DAT_a802e1f0.fb);
    FUN_a008a568(0xd, DAT_a802d290.b009);
    FUN_a008a568(0xe, DAT_a802d290.b00a);
    FUN_a0146b50(0xca, 0);
    FUN_a0146b6c(0, 0);
    if (DAT_a802d290.u1d4.b[1] == 1)
        FUN_a00a31a4(0, DAT_00100242[19].col + 8, 0xf, 3, s_001002a8, 0);
    else
        FUN_a00a31a4(0, DAT_00100242[19].col + 8, 0xf, 3, s_001002a0, 0);
    FUN_a0146b50(0xd6, 0);
    if (DAT_a802d290.h1f6 == 0x55aa)
        FUN_a00a31a4(0, 9, 0xd, 3, s_001002a8, 0);
    else
        FUN_a00a31a4(0, 9, 0xd, 3, s_001002a0, 0);
    FUN_a0146b50(0xd3, 0);
    if (FUN_a0145af8(2))
        FUN_a00a31a4(0, DAT_00100242[24].col + 0xb, 0x14, 3, s_001002a8, 0);
    else
        FUN_a00a31a4(0, DAT_00100242[24].col + 0xb, 0x14, 3, s_001002a0, 0);
    FUN_a008a568(0x15, FUN_a01266b0());
    FUN_a008a568(0x16, DAT_a802afba);
    FUN_a0146b50(0xf7, 0);
    if (FUN_a0145af8(0x10))
        FUN_a00a31a4(0, DAT_00100242[23].col + 0xb, 0x13, 3, s_001002a8, 0);
    else
        FUN_a00a31a4(0, DAT_00100242[23].col + 0xb, 0x13, 3, s_001002a0, 0);
    FUN_a008b380();
    FUN_a008b5e0();
    FUN_a008a568(0x10, DAT_a802afb9);
    FUN_a008b5e0();
    FUN_a0146b50(0xea, 0);
    FUN_a0146b6c(0, 0);
    x = DAT_00100242[25].col;
    y = DAT_00100242[25].row;
    FUN_a00a31a4(0, x, y, 8, s_00100330, 0);
    if (DAT_a802d290.u1d4.w & 0x80)
        FUN_a00a31a4(0, x + 0xc, y, 3, s_001002a8, 0);
    else
        FUN_a00a31a4(0, x + 0xc, y, 3, s_001002a0, 0);
    FUN_a008a568(0x14, DAT_a802d290.h1da);
    FUN_a0146b50(0xf4, 0);
    FUN_a0146b6c(0, 0);
    if (DAT_a8024040 == 1)
        FUN_a00a31a4(0, DAT_00100242[26].col + 8, DAT_00100242[26].row, 3, s_001002a8, 0);
    else
        FUN_a00a31a4(0, DAT_00100242[26].col + 8, DAT_00100242[26].row, 3, s_001002a0, 0);
    DAT_a802afbd = 0x1a;
    FUN_a0146a80(DAT_00100242[DAT_a802afbd].col, DAT_00100242[DAT_a802afbd].row, DAT_00100242[DAT_a802afbd].len,
                 0x90, 0);
    FUN_a0146ab0(0x794, 0);
    FUN_a0146b50(0x100, 0);
    FUN_a00a31a4(1, 1, 4, 3, s_00100388, 0);
    FUN_a00a31a4(1, 1, 1, 0xf, s_001002e8, 0);
    FUN_a00a31a4(1, 1, 2, 0x12, s_001002c0, 0);
    FUN_a00a31a4(1, 1, 3, 0xe, s_00100300, 0);
    FUN_a00a31a4(1, 0xf, 3, 7, s_00100380, 0);
    FUN_a00a31a4(1, 1, 0x18, 0xf, s_001002b0, 0);
    FUN_a00a31a4(1, 1, 0x19, 3, s_00100378, 0);
    FUN_a00a31a4(1, 1, 0x1a, 6, s_00100370, 0);
    FUN_a00a31a4(1, 1, 0x1b, 0xf, s_00100360, 0);
    FUN_a00a31a4(1, 1, 0x1c, 6, s_00100358, 0);
    FUN_a00a31a4(1, 0xd, 0x1c, 5, s_00100350, 0);
    FUN_a00a31a4(1, 1, 0x1d, 4, s_00100348, 0);
    FUN_a00a31a4(1, 1, 0x1e, 7, s_00100340, 0);
    {
        unsigned char v[DAT_a802d274.n + 1];

        v[0] = DAT_a802d274.n;
        FUN_a0146b50(0xbb, 0);
        FUN_a0146b6c(0, 0);
        for (i = 0; i < DAT_a802d274.n; i++)
            v[i + 1] = DAT_a802d274.d[i];
        for (i = 0; i < DAT_a802d274.n; i++)
            if (v[i + 1] == 0)
                break;
        v[0] = i;
        for (i = 0; i < DAT_a802d274.n; i++)
            if (v[i + 1] == 0xff)
                v[i + 1] = ' ';
        FUN_a00a31a4(0, 6, 0x19, DAT_a802d274.n + 1, (const char *)v, 0);
    }
    put5(0xe, 0x18);
    put2(0x14, 0x18);
    put3(0x10, 0x1b, DAT_a802d274.b15);
    putn(7, 0x1c, DAT_a802d274.h16);
    put3(0x12, 0x1c, DAT_a802d274.h18 >> 15);
    put3(5, 0x1d, FUN_a00dab30());
    FUN_a0146b50(0xfa, 0);
    FUN_a0146b6c(0, 0);
    if (!FUN_a0145af8(0x11))
        FUN_a00a31a4(0, 9, 0x1a, 3, s_00100470, 0);
    else
        FUN_a00a31a4(0, 9, 0x1a, 3, s_00100468, 0);
    putn(9, 0x1e, (DAT_a802d290.u1d4.w >> 8) & 0xff);
    FUN_a00a45a8();
}
