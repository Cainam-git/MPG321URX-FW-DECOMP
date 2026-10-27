/* leon2m FUN_a008ce90 @ 0xa008ce90-0xa008d2e0 (276 words), flags -mcpu=v8 -O3 -g. Called by FUN_a008d2e0.
 * Sets byte 0xa802afbb to 1 and runs a fixed call sequence: FUN_a0146648(0, 0, 0, 0, 0), FUN_a0146298(4, 0),
 * FUN_a0146354(0x18, 0x24, 0), FUN_a0146370(0, FUN_a0146194(0x1c, 0xd), 0), FUN_a00a28bc(), FUN_a0146dc0(0, 0),
 * FUN_a0146c40(8, 0, 0), FUN_a014613c(0x1c, 0xd, 0), FUN_a0146518(1, 0x62, 0), FUN_a0146ab0(0x790, 0),
 * func_0x4008e2a4() three times, FUN_a0146108(0), FUN_a0146518(0x61, 5, 0), FUN_a0146b50(0xb, 0) and
 * FUN_a0146b6c(0, 0). Then seven ROM strings (0x100300, 0x1002f8, 0x1002e8, 0x1002e0, 0x1002d8, 0x1002c0, 0x1002b0)
 * go to FUN_a00a31a4 with fixed (x, y, length) values.
 * The n = byte 0xa802d276 bytes from 0xa802d277 are copied into a variable-length buffer v[n + 1] (after
 * FUN_a0146b50(0xbb, 0) and FUN_a0146b6c(0, 0)); v[0] becomes the index of the first 0 byte (or n), 0xff bytes
 * become ' ', and v goes to FUN_a00a31a4(0, 6, 3, n + 1, v, 0). Then bits 8..23 of word 0xa802e1a8 (5 digits,
 * format 0x100510) and its top byte (2 digits, format 0x100508) are formatted with FUN_a01577f4, mapped
 * (' ' -> 0, others - 47) and passed to FUN_a0146af4(0, 0xe / 0x14, 5, 5 / 2, buf, 0). Ends with FUN_a00a45a8().
 * Source form: the two number fields are the same-file functions FUN_a008cdf0 / FUN_a008ccc0, defined here as
 * static copies (put5 / put2, as in FUN_a008d2f8) and inlined.
 */
struct Log274 {                         /* 0xA802D274 */
    unsigned char b0, b1, n;
    unsigned char d[0x12];              /* +0x03 */
};
struct E1a0 { unsigned int w0, w4, w8; };

extern unsigned char DAT_a802afbb;
extern struct Log274 DAT_a802d274;
extern struct E1a0 DAT_a802e1a0;
extern const char s_001002b0[], s_001002c0[], s_001002d8[], s_001002e0[], s_001002e8[], s_001002f8[], s_00100300[];
extern const char s_00100508[], s_00100510[];

extern void FUN_a0146648(int, int, int, int, int);
extern void FUN_a0146298(int, int);
extern void FUN_a0146354(int, int, int);
extern unsigned short FUN_a0146194(int, int);
extern void FUN_a0146370(unsigned char, unsigned int, unsigned char);
extern void FUN_a00a28bc(void);
extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146518(unsigned short, unsigned short, unsigned char);
extern void FUN_a0146ab0(int, int);
extern void func_0x4008e2a4(void);
extern void FUN_a0146108(int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);
extern void FUN_a01577f4(unsigned char *, const char *, unsigned short);
extern void FUN_a0146af4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
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



void FUN_a008ce90(void)
{
    unsigned char i;

    DAT_a802afbb = 1;
    FUN_a0146648(0, 0, 0, 0, 0);
    FUN_a0146298(4, 0);
    FUN_a0146354(0x18, 0x24, 0);
    FUN_a0146370(0, FUN_a0146194(0x1c, 0xd), 0);
    FUN_a00a28bc();
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    FUN_a014613c(0x1c, 0xd, 0);
    FUN_a0146518(1, 0x62, 0);
    FUN_a0146ab0(0x790, 0);
    func_0x4008e2a4();
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a0146108(0);
    FUN_a0146518(0x61, 5, 0);
    FUN_a0146b50(0xb, 0);
    FUN_a0146b6c(0, 0);
    FUN_a00a31a4(0, 1, 1, 0xe, s_00100300, 0);
    FUN_a00a31a4(0, 1, 2, 7, s_001002f8, 0);
    FUN_a00a31a4(0, 8, 2, 0xf, s_001002e8, 0);
    FUN_a00a31a4(0, 1, 3, 3, s_001002e0, 0);
    FUN_a00a31a4(0, 1, 4, 6, s_001002d8, 0);
    FUN_a00a31a4(0, 6, 4, 0x12, s_001002c0, 0);
    FUN_a00a31a4(0, 1, 5, 1, s_001002b0, 0);
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
        FUN_a00a31a4(0, 6, 3, DAT_a802d274.n + 1, (const char *)v, 0);
    }
    put5(0xe, 5);
    put2(0x14, 5);
    FUN_a00a45a8();
}
