/* leon2m FUN_a00d2a98 @ 0xa00d2a98-0xa00d3650 (3000 bytes), flags -mcpu=v8 -O3 -g. FUN_a00d2a98(port, req) selects
 * on bytes 3 and 5 of the record req and passes a 40-byte result record to FUN_a00d1220 and FUN_a01486a8.
 *
 * A 40-byte record r on the stack is cleared, r[0..2] = 0x6e, 0x86, 0xc0 and r[3..6] = req[3..6]; code = 0, len = 10.
 * req[3] == 'c': a switch on req[5] runs the functions FUN_a00d1a34 (1), FUN_a00d1ad4 (2), FUN_a00d1ce4 (8),
 *   FUN_a00d1e08 (0x0b), FUN_a00d1e3c (0x0d), FUN_a00d1ed8 (0x0e), FUN_a00d1f20 (0x0f), FUN_a00d20a4 (0x6a),
 *   FUN_a00d2334 (0x6b), FUN_a00d2384 (0x6c), FUN_a00d23b8 (0x6d), FUN_a00d24d8 (0x6e), FUN_a00d24e0 (0x70),
 *   FUN_a00d2884 (0x74), FUN_a00d28d4 (0xaa), FUN_a00d2974 (0x55), FUN_a00d2994 (0xc4), FUN_a00d29c0 (0x22) and
 *   FUN_a00d2a28 (0x23) (all inlined) and calls FUN_a00d1b48 (3), FUN_a00d1d34 (0x0a), FUN_a00d1f58 (0x11),
 *   FUN_a00d253c (0x6f), FUN_a00d25f4 (0x72), FUN_a00d27ac (0x73); code = their result. 4: FUN_a014aed0(0x30,
 *   &DAT_a802d290, 0, 0x1fc), code 0xe0; 5 and 0x80: code 0xe0; 0x13: code stays 0; 0x69: byte 0xa802d284 = 0,
 *   FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c), code 0xe0; 0xd0: clears bits 8..31 of word 0xa802e1a8 and calls
 *   FUN_a0153970(&DAT_a802e1a0, 1), code stays 0; any other value: code 0xe3.
 * req[3] == 's': code = 2, 8, 10, 0x92 (len 13), 0x93, 0x97, 0x1f, 0x69, 0x6a, 0x6b (len 21), 0x6e, 0x6f, 0xaa,
 *   0xc2, 0xd0, 0xfe for req[5] = 2, 8, 0x0a, 0x11, 0x1c, 0x1d, 0x1f, 0x69, 0x6a, 0x6b, 0x6e, 0x6f, 0xaa, 0xc2, 0xd0,
 *   0xfe; 0x1e leaves code 0; 0x0e / 0x0f / 0x6c / 0x73 / 0x74 / 0xc3 store byte 0xa802d299 / 0xa802d29a / 0xa802d2a0 /
 *   0xa802e1ab / 0xa802d288 / bit 15 of halfword 0xa802d28c in r[6] with code 0xe0; 0xc1 stores byte 0xa802d289 in
 *   r[6], sets bit 15 of halfword 0xa802d28c, calls FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c), code 0xe0; any
 *   other value: code 0xe3.
 * Then FUN_a00d1220(req, r, code), FUN_a0089f60(0x50) and FUN_a01486a8(port, len, r).
 * Source form: r is a structure whose byte 6 is an 8-bit bit-field (r.b6) written by the 's' cases, while the clear
 * loop and the header stores use the byte view R of r (with a plain byte array GCC's store motion sinks the
 * r[6] = req[6] store into the 's' cases); the 'c' cases are listed in the definition order of the called functions
 * (static copies of the neighbouring functions, inlined); the source order of the 's' cases sets the block order;
 * bit 15 of halfword 0xa802d28c is a 1-bit bit-field, set after the r[6] store in case 0xc1; FUN_a00d28d4's copy
 * sets bit 14 of word 0xa802d290 through a 1-bit bit-field.
 */
struct S290 {
    union { unsigned int w; struct { unsigned int hi : 22, b9 : 1, lo : 9; } b; struct { unsigned int h : 17, f14 : 1, l : 14; } c; } w0;
    unsigned char p004[4];
    unsigned char b08, b09, b0a;
    unsigned char p00b[5];
    unsigned char b10, b11;
    unsigned char p012[0xa8 - 0x12];
    unsigned int wa8;
    unsigned char p0ac[0x1d5 - 0xac];
    unsigned char b1d5, b1d6;
    unsigned char p1d7[0x1ec - 0x1d7];
    union { unsigned int w; struct { unsigned int hi : 24, b7 : 1, lo : 7; } b; } w1ec;
    unsigned char p1f0[6];
    unsigned short h1f6;
    unsigned char p1f8[4];
};
struct S274 {
    unsigned char b00, b01, b02;
    unsigned char d[0xd];
    unsigned char b10;
    unsigned char p11[3];
    unsigned char b14, b15;
    unsigned short h16;
    unsigned short f15 : 1, h18lo : 15;
    unsigned char p1a[2];
};
struct Rgb { unsigned char c0, c1, c2; };
struct E1f0 { unsigned char p00[6]; struct Rgb s06; struct Rgb s09; unsigned char p0c[0x12 - 0xc]; struct Rgb s12;
              unsigned char p15[0x21 - 0x15]; struct Rgb s21; };
struct S1a0 {
    unsigned int w0, w4;
    unsigned int sec : 8, min : 16, lo : 8;
};
extern struct S290 DAT_a802d290;
extern struct S274 DAT_a802d274;
extern struct E1f0 DAT_a802e1f0;
extern struct S1a0 DAT_a802e1a0;
extern unsigned char DAT_a802b09d, DAT_a802b09e, DAT_a802b09f, DAT_a802b08e, DAT_a8025c56;
extern int FUN_a014aed0(unsigned char, void *, unsigned short, unsigned short);
extern void FUN_a0081ea8(unsigned int);
extern unsigned char FUN_a013ce6c(unsigned char);
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a00cea18(void);
extern void FUN_a00cea44(void);
extern void FUN_a0145360(unsigned char);
extern unsigned char FUN_a00d1b48(void);
extern int FUN_a00d1d34(unsigned char *);
extern int FUN_a00d1f58(unsigned char *);
extern int FUN_a00d253c(unsigned char *);
extern int FUN_a00d25f4(unsigned char *);
extern int FUN_a00d27ac(unsigned char *);
extern void FUN_a00d9764(void);
extern void FUN_a0089f10(void);
extern void FUN_a00d8cd4(void);
extern void FUN_a00d7de0(void);
extern void FUN_a00d4970(void);
extern void FUN_a0125aac(void);
extern void FUN_a0125ac8(void);
extern void FUN_a00d5918(void);
extern void FUN_a00db12c(unsigned char);
extern void FUN_a0153970(void *, unsigned char);
extern void FUN_a00d1220(unsigned char *, unsigned char *, unsigned char);
extern void FUN_a0089f60(unsigned char);
extern void FUN_a01486a8(unsigned char, unsigned short, unsigned char *);

static int FUN_a00d1a34(unsigned char *msg)
{
    unsigned char c = msg[7];

    if (c == 1) {
        if (FUN_a0143c14(0) == 0)
            FUN_a0081ea8(2);
    } else if (c == 0) {
        if (FUN_a0143c14(0) != 0)
            FUN_a0081ea8(1);
    } else if (c == 2) {
        if (FUN_a013ce6c(0) != 1)
            FUN_a0081ea8(3);
    }
    FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    return 0xe0;
}

static int FUN_a00d1ad4(unsigned char *p)
{
    if (p[7] == 1) {
        FUN_a00cea18();
        DAT_a802d290.h1f6 = 0x55aa;
        FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    } else if (p[7] == 0) {
        FUN_a00cea44();
        DAT_a802d290.h1f6 = 0xbb99;
    }
    FUN_a0145360(1);
    return 0xe0;
}

static int FUN_a00d1ce4(unsigned char *p)
{
    if (p[7] == 1)
        DAT_a802d290.b1d5 = 1;
    else if (p[7] == 0)
        DAT_a802d290.b1d5 = 0;
    FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    return 0xe0;
}

static unsigned char FUN_a00d1e08(unsigned char *p)
{
    if (p[7] == 1)
        DAT_a802b09d = 0;
    else if (p[7] == 0)
        DAT_a802b09d = 1;
    return 0xe0;
}

static int FUN_a00d1e3c(unsigned char *p)
{
    unsigned char v;

    switch (p[7]) {
    case 1:
        v = 2;
        break;
    case 2:
        v = 0;
        break;
    case 3:
        v = 1;
        break;
    case 4:
        v = 3;
        break;
    default:
        return 0xe3;
    }
    if (DAT_a802d290.b11 != v) {
        DAT_a802d290.b11 = v;
        FUN_a00d9764();
        FUN_a0089f10();
        FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    }
    return 0xe0;
}

static int FUN_a00d1ed8(unsigned char *p)
{
    struct S290 *r = &DAT_a802d290;

    if (p[7] > 100)
        r->b09 = 100;
    else
        r->b09 = p[7];
    FUN_a00d8cd4();
    DAT_a802b08e |= 4;
    return 0xe0;
}

static int FUN_a00d1f20(unsigned char *p)
{
    struct S290 *r = &DAT_a802d290;

    if (p[7] > 100)
        r->b0a = 100;
    else
        r->b0a = p[7];
    FUN_a00d7de0();
    return 0xe0;
}

static unsigned char FUN_a00d20a4(unsigned char *p)
{
    switch (p[7]) {
    case 0x0:
        DAT_a802d290.b08 = 0x1;
        break;
    case 0x1:
        DAT_a802d290.b08 = 0x3;
        break;
    case 0x2:
        DAT_a802d290.b08 = 0x2;
        break;
    case 0x3:
        DAT_a802d290.b08 = 0x5;
        break;
    case 0x4:
        DAT_a802d290.b08 = 0x4;
        break;
    case 0x5:
        DAT_a802d290.b08 = 0x19;
        break;
    case 0x6:
        DAT_a802d290.b08 = 0x16;
        break;
    case 0x7:
        DAT_a802d290.b08 = 0x9;
        break;
    case 0x8:
        DAT_a802d290.b08 = 0x18;
        break;
    case 0x9:
        DAT_a802d290.b08 = 0x8;
        break;
    case 0xc:
        DAT_a802d290.b08 = 0x0;
        break;
    case 0xd:
        DAT_a802d290.b08 = 0x7;
        break;
    case 0xe:
        DAT_a802d290.b08 = 0x6;
        break;
    case 0x10:
        DAT_a802d290.b08 = 0xd;
        break;
    case 0x11:
        DAT_a802d290.b08 = 0xa;
        break;
    case 0x12:
        DAT_a802d290.b08 = 0xb;
        break;
    case 0x13:
        DAT_a802d290.b08 = 0xc;
        break;
    case 0x14:
        DAT_a802d290.b08 = 0xe;
        break;
    case 0x15:
        DAT_a802d290.b08 = 0xf;
        break;
    case 0x16:
        DAT_a802d290.b08 = 0x10;
        break;
    case 0x17:
        DAT_a802d290.b08 = 0x11;
        break;
    case 0x18:
        DAT_a802d290.b08 = 0x12;
        break;
    case 0x19:
        DAT_a802d290.b08 = 0x13;
        break;
    case 0x1a:
        DAT_a802d290.b08 = 0x14;
        break;
    case 0x1b:
        DAT_a802d290.b08 = 0x15;
        break;
    case 0x1c:
        DAT_a802d290.b08 = 0x17;
        break;
    case 0x1d:
        DAT_a802d290.b08 = 0x1a;
        break;
    case 0x1e:
        DAT_a802d290.b08 = 0x1b;
        break;
    case 0x1f:
        DAT_a802d290.b08 = 0x1c;
        break;
    }
    FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    FUN_a0145360(1);
    return 0xe0;
}

static int FUN_a00d2334(unsigned char *src)
{
    unsigned int n = 0;
    unsigned char i = 0;

    do {
        n = n + 1;
        DAT_a802d274.d[i] = src[i + 6];
        i = n & 0xff;
    } while (i < 0xd);
    FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
    return 0xe0;
}

static int FUN_a00d2384(unsigned char *p)
{
    DAT_a802d290.b10 = p[7];
    FUN_a00d4970();
    FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    return 0xe0;
}

static int FUN_a00d23b8(unsigned char *p)
{
    unsigned char c0, c1, c2;

    switch (p[6]) {
    case 1:
        c0 = DAT_a802e1f0.s06.c0;
        c1 = DAT_a802e1f0.s06.c1;
        c2 = DAT_a802e1f0.s06.c2;
        break;
    case 3:
        c0 = DAT_a802e1f0.s09.c0;
        c1 = DAT_a802e1f0.s09.c1;
        c2 = DAT_a802e1f0.s09.c2;
        break;
    case 2:
        c0 = DAT_a802e1f0.s12.c0;
        c1 = DAT_a802e1f0.s12.c1;
        c2 = DAT_a802e1f0.s12.c2;
        break;
    case 5:
        c0 = DAT_a802e1f0.s21.c0;
        c1 = DAT_a802e1f0.s21.c1;
        c2 = DAT_a802e1f0.s21.c2;
        break;
    default:
        return 0xe3;
    }
    switch (p[7]) {
    case 1:
        DAT_a802e1f0.s06.c0 = c0;
        DAT_a802e1f0.s06.c1 = c1;
        DAT_a802e1f0.s06.c2 = c2;
        break;
    case 3:
        DAT_a802e1f0.s09.c0 = c0;
        DAT_a802e1f0.s09.c1 = c1;
        DAT_a802e1f0.s09.c2 = c2;
        break;
    case 2:
        DAT_a802e1f0.s12.c0 = c0;
        DAT_a802e1f0.s12.c1 = c1;
        DAT_a802e1f0.s12.c2 = c2;
        break;
    case 5:
        DAT_a802e1f0.s21.c0 = c0;
        DAT_a802e1f0.s21.c1 = c1;
        DAT_a802e1f0.s21.c2 = c2;
        break;
    default:
        return 0xe3;
    }
    FUN_a0145360(0);
    return 0xe0;
}

static int FUN_a00d24d8(void)
{
    return 0;
}

static int FUN_a00d24e0(unsigned char *p)
{
    if (p[7] == 0) {
        DAT_a802d290.wa8 &= ~0x40;
        FUN_a0125ac8();
    } else {
        DAT_a802d290.wa8 |= 0x40;
        FUN_a0125aac();
    }
    FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    return 0xe0;
}

static int FUN_a00d2884(unsigned char *p)
{
    if (p[7] == 1)
        DAT_a802d274.b14 = 1;
    else if (p[7] == 0)
        DAT_a802d274.b14 = 0;
    FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
    return 0xe0;
}

static int FUN_a00d28d4(unsigned char *p)
{
    unsigned char v = p[7];
    int r = 0xe4;

    if (v == 1) {
        DAT_a802d290.w0.c.f14 = 1;
        DAT_a802d290.b1d5 = v;
        DAT_a802d290.h1f6 = 0x55aa;
        DAT_a802d290.b1d6 = 0x55;
        FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
        if ((DAT_a802d290.w0.w & 0x4000) && DAT_a802d290.b1d5 == 1 && DAT_a802d290.h1f6 == 0x55aa)
            r = 0xe0;
        else
            r = 0xe4;
    }
    return r;
}

static unsigned char FUN_a00d2974(unsigned char *p)
{
    DAT_a802b09f = p[6];
    DAT_a802b09e = p[7];
    return 0xe0;
}

static int FUN_a00d2994(void)
{
    DAT_a802d274.b15 = 0;
    DAT_a802d274.h16 = 0;
    FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
    return 0xe0;
}

static int FUN_a00d29c0(unsigned char *p)
{
    DAT_a8025c56 = DAT_a802d290.w0.b.b9;
    DAT_a802d290.w0.b.b9 = p[7] != 0;
    if (DAT_a8025c56 != DAT_a802d290.w0.b.b9) {
        FUN_a00d5918();
        DAT_a802b08e |= 2;
    }
    return 0xe0;
}

static int FUN_a00d2a28(unsigned char *p)
{
    DAT_a8025c56 = DAT_a802d290.w1ec.b.b7;
    DAT_a802d290.w1ec.b.b7 = p[7] != 0;
    if (DAT_a8025c56 != DAT_a802d290.w1ec.b.b7) {
        FUN_a00db12c(0);
        DAT_a802b08e |= 2;
    }
    return 0xe0;
}

struct Rec40 { unsigned char h[6]; unsigned int b6 : 8; unsigned char t[33]; };
#define R ((unsigned char *)&r)
void FUN_a00d2a98(unsigned char port, unsigned char *req)
{
    struct Rec40 r;
    unsigned char i;
    char code = 0;
    unsigned short len = 10;
    unsigned char *q;

    for (i = 0; i < 40; i++)
        R[i] = 0;
    R[0] = 0x6e;
    R[1] = 0x86;
    R[2] = 0xc0;
    R[3] = req[3];
    R[4] = req[4];
    R[5] = req[5];
    R[6] = req[6];
    q = R;
    if (R[3] == 'c') {
        switch (R[5]) {
        case 0x01: code = FUN_a00d1a34(req); break;
        case 0x02: code = FUN_a00d1ad4(req); break;
        case 0x03: code = FUN_a00d1b48(); break;
        case 0x04:
            FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
            code = 0xe0;
            break;
        case 0x05: code = 0xe0; break;
        case 0x08: code = FUN_a00d1ce4(req); break;
        case 0x0a: code = FUN_a00d1d34(req); break;
        case 0x0b: code = FUN_a00d1e08(req); break;
        case 0x0d: code = FUN_a00d1e3c(req); break;
        case 0x0e: code = FUN_a00d1ed8(req); break;
        case 0x0f: code = FUN_a00d1f20(req); break;
        case 0x69:
            DAT_a802d274.b10 = 0;
            FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
            code = 0xe0;
            break;
        case 0x11: code = FUN_a00d1f58(req); break;
        case 0x13: break;
        case 0x6a: code = FUN_a00d20a4(req); break;
        case 0x6b: code = FUN_a00d2334(req); break;
        case 0x6c: code = FUN_a00d2384(req); break;
        case 0x6d: code = FUN_a00d23b8(req); break;
        case 0x6e: code = FUN_a00d24d8(); break;
        case 0x70: code = FUN_a00d24e0(req); break;
        case 0x6f: code = FUN_a00d253c(req); break;
        case 0x72: code = FUN_a00d25f4(req); break;
        case 0x73: code = FUN_a00d27ac(req); break;
        case 0x74: code = FUN_a00d2884(req); break;
        case 0xaa: code = FUN_a00d28d4(req); break;
        case 0x55: code = FUN_a00d2974(req); break;
        case 0xc4: code = FUN_a00d2994(); break;
        case 0xd0:
            DAT_a802e1a0.min = 0;
            DAT_a802e1a0.sec = 0;
            FUN_a0153970(&DAT_a802e1a0, 1);
            break;
        case 0x22: code = FUN_a00d29c0(req); break;
        case 0x23: code = FUN_a00d2a28(req); break;
        case 0x80: code = 0xe0; break;
        default: code = 0xe3; break;
        }
    } else if (R[3] == 's') {
        switch (R[5]) {
        case 0xfe: code = 0xfe; break;
        case 0x1d: code = 0x97; break;
        case 0x6e: code = 0x6e; break;
        case 0x1e: break;
        case 0x0e: r.b6 = DAT_a802d290.b09; code = 0xe0; break;
        case 0x0f: r.b6 = DAT_a802d290.b0a; code = 0xe0; break;
        case 0x0a: code = 10; break;
        case 0xaa: code = 0xaa; break;
        case 0x6c: r.b6 = DAT_a802d290.b10; code = 0xe0; break;
        case 0x1f: code = 0x1f; break;
        case 0x02: code = 2; break;
        case 0x73: r.b6 = DAT_a802e1a0.lo; code = 0xe0; break;
        case 0x11: code = 0x92; len = 0xd; break;
        case 0x1c: code = 0x93; break;
        case 0x74: r.b6 = DAT_a802d274.b14; code = 0xe0; break;
        case 0xd0: code = 0xd0; break;
        case 0xc1:
            r.b6 = DAT_a802d274.b15;
            DAT_a802d274.f15 = 1;
            FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
            code = 0xe0;
            break;
        case 0xc2: code = 0xc2; break;
        case 0x6a: code = 0x6a; break;
        case 0xc3: r.b6 = DAT_a802d274.f15; code = 0xe0; break;
        case 0x6b: code = 0x6b; len = 0x15; break;
        case 0x69: code = 0x69; break;
        case 0x6f: code = 0x6f; break;
        case 0x08: code = 8; break;
        default: code = 0xe3; break;
        }
    }
    FUN_a00d1220(req, q, code);
    FUN_a0089f60(0x50);
    FUN_a01486a8(port, len, q);
}
