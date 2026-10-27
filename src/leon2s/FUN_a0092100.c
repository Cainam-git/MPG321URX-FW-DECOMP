/* FUN_a0092100 (leon2s 0xa0092100-0xa00924d8, 984 bytes), flags -mcpu=v8 -Os -g. void (u8 port).
 * Record r = ARR_a807d580[port] (28 bytes). type = byte 1 of r, or byte 0x17 when byte 1 is 0xe1 or 0xe2; for
 * type 0x71 / 0x81 a nonzero FUN_a00ad7c8(0 / 1) adds 2 to cs (byte 0xd) and prints s_a0068ef8 "AVI 422".
 * cs selects one of the FUN_a00734c4 color-space prints and is mapped to 0..4 (<2 -> 0; 8,9,0x14,0x15 -> 1;
 * 2,3,0xe,0xf -> 3; 10,11,0x16,0x17 -> 2; 4,5,0x10,0x11 -> 4; else unchanged with the "NG" print).
 * Writes via FUN_a00a8054(port, 0, reg, value): FUN_a00a80cc(port, 0, 0x13e, 3, 0) first, then 0x140..0x142 =
 * 0x82, 2, 0x0d; 0x144..0x147 = b4, b5, b6, byte 0xe of r, where b4/b5/b6 come from cs (0: 2,0,0; 1: 0x42,0xc0,
 * 0x10; 2: 0x22,0xc0,0x10; 3: 0x42,0xc0,0; 4: 0x22,0xc0,0) and b6 gets bit 2 (word 0xc of r negative) or bit 3;
 * b8 = 0 or 0x40 likewise, | 3 for word 8 <= 0xc or | 1 for <= 0x19 unless bit 3 of word 0 is set; then
 * FUN_a0092064(port, b8), 0x148 = b8, 0x149..0x152 = 0, 0x143 = minus the 8-bit sum of 0x91 and the written
 * bytes, and the tail call FUN_a00a80cc(port, 0, 0x13e, 3, 1).
 * Source forms the exact build depends on: type assigned in both arms of the e1/e2 test, which reads byte 1
 * itself (an assignment before the test gives the switch index its own register); the zero initialisers of
 * b4..b6 declared between the sign flag and the byte reads; case order 0, 1, 3, 2, 4;
 * the checksum accumulated statement by statement and negated in place.
 */
struct Rec28 {
    union {
        unsigned int w;
        unsigned char b[4];
    } u0;
    unsigned int w4;
    int w8;
    union {
        int w;
        unsigned char b[4];
    } uc;
    unsigned int w10;
    unsigned char b14[4];
    unsigned int w18;
};
extern struct Rec28 ARR_a807d580[];
extern const char s_a0068ef8[];
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned int FUN_a00ad7c8(unsigned char);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a0092064(unsigned char, unsigned int);

void FUN_a0092100(unsigned char port)
{
    struct Rec28 *r = &ARR_a807d580[port];
    unsigned char type;
    int neg = r->uc.w < 0;
    unsigned char b4 = 0;
    unsigned char b5 = 0;
    unsigned char b6 = 0;
    unsigned char e = r->uc.b[2];
    unsigned char cs = r->uc.b[1];
    int v8 = r->w8;
    unsigned char b8;
    unsigned char sum;
    unsigned short i;

    if ((unsigned char)(r->u0.b[1] - 0xe1) < 2)
        type = r->b14[3];
    else
        type = r->u0.b[1];
    switch (type) {
    case 0x71:
        if (FUN_a00ad7c8(0) & 0xff) {
            cs += 2;
            FUN_a0073044(s_a0068ef8);
        }
        break;
    case 0x81:
        if (FUN_a00ad7c8(1) & 0xff) {
            cs += 2;
            FUN_a0073044(s_a0068ef8);
        }
        break;
    }
    if (cs < 2) {
        FUN_a00734c4("\x1b[0m\t\t - Color Space = RGB\n");
        cs = 0;
    } else if ((unsigned char)(cs - 8) < 2 || cs == 0x14 || cs == 0x15) {
        FUN_a00734c4("\x1b[0m\t\t - Color Space = YUV 709 444\n");
        cs = 1;
    } else if ((unsigned char)(cs - 2) < 2 || cs == 0xe || cs == 0xf) {
        FUN_a00734c4("\x1b[0m\t\t - Color Space = YUV 601 444\n");
        cs = 3;
    } else if ((unsigned char)(cs - 10) < 2 || cs == 0x16 || cs == 0x17) {
        FUN_a00734c4("\x1b[0m\t\t - Color Space = YUV 709 422\n");
        cs = 2;
    } else if ((unsigned char)(cs - 4) < 2 || cs == 0x10 || cs == 0x11) {
        FUN_a00734c4("\x1b[0m\t\t - Color Space = YUV 601 422\n");
        cs = 4;
    } else
        FUN_a00734c4("\x1b[0m\t\t - Color Space = NG\n");
    FUN_a00a80cc(port, 0, 0x13e, 3, 0);
    FUN_a00a8054(port, 0, 0x140, 0x82);
    FUN_a00a8054(port, 0, 0x141, 2);
    FUN_a00a8054(port, 0, 0x142, 0xd);
    switch (cs) {
    case 0:
        b4 = 2;
        b5 = 0;
        b6 = 0;
        break;
    case 1:
        b4 = 0x42;
        b5 = 0xc0;
        b6 = 0x10;
        break;
    case 3:
        b4 = 0x42;
        b5 = 0xc0;
        b6 = 0;
        break;
    case 2:
        b4 = 0x22;
        b5 = 0xc0;
        b6 = 0x10;
        break;
    case 4:
        b4 = 0x22;
        b5 = 0xc0;
        b6 = 0;
        break;
    }
    if (neg) {
        b6 |= 4;
        b8 = 0;
    } else {
        b6 |= 8;
        b8 = 0x40;
    }
    FUN_a00a8054(port, 0, 0x144, b4);
    FUN_a00a8054(port, 0, 0x145, b5);
    FUN_a00a8054(port, 0, 0x146, b6);
    FUN_a00a8054(port, 0, 0x147, e);
    sum = 0x82 + 2 + 0xd;
    sum += b4;
    sum += b5;
    sum += b6;
    sum += e;
    if (!(ARR_a807d580[port].u0.w & 8)) {
        if (v8 <= 0xc)
            b8 |= 3;
        else if (v8 <= 0x19)
            b8 |= 1;
    }
    FUN_a0092064(port, b8);
    FUN_a00a8054(port, 0, 0x148, b8);
    sum += b8;
    for (i = 9; i < 0x13; i++)
        FUN_a00a8054(port, 0, i + 0x140, 0);
    sum = -sum;
    FUN_a00a8054(port, 0, 0x143, sum);
    FUN_a00a80cc(port, 0, 0x13e, 3, 1);
}
