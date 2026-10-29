/* FUN_a0070b7c (leon2s 0xa0070b7c-0xa0072900, 7556 bytes), flags -mcpu=v8 -Os -g.
 * void (struct Cmd *c), called by FUN_a0072900 with a 32-byte record read by FUN_a006faa8(8, 0, buf, 8).
 * Clears the 28-byte local buffer buf (FUN_a00b15ac), saves the low bytes of the registers 0xcf03d004, 008,
 * 00c and 010, and dispatches on byte 2 of the record (jump table switchdataD_a007077c, 256 entries, 109
 * case blocks; case 3 uses switchdataD_a0070758, 0xa0 and 0xa1 use switchdataD_a0070740 / a0070728).
 * The cases pass bytes, halfwords and bit fields of the words at c+4 .. c+0x18 to callees, store them into
 * the records ARR_a807dc18 (300 bytes), ARR_a807a8fc (20 bytes, halfword bit fields at +0 and +2) and
 * ARR_a807a928 (40 bytes, word bit fields at +0 and +0x20), or read values into buf. Cases that fill buf set
 * a flag; then FUN_a006fd78(byte 2, 0x1c, buf) is called. Every path ends with FUN_a006fad4(8, 0, &w, 1)
 * on a cleared word and writes the four saved bytes back. Cases 0x72 and 0x73 end in an endless loop.
 * Source forms: the case blocks are written in the firmware's block order (-Os keeps source order); most
 * cases copy the word at c+4 into a local and its bytes into unsigned char locals (direct (unsigned char)
 * casts of c->w4 >> n are narrowed to byte loads), and the order of those declarations and of the stores
 * decides the schedule; one function-scope unsigned char b holds the second byte in many cases, and two
 * more function-scope unsigned char variables t1 and t2 hold byte arguments in cases 0x13, 0x16, 0x27,
 * 0x29, 0x59, 0x92 and 0xf4 (one register each for the whole function); case 3 reads the word into an
 * unsigned short; case 0x12 passes an unsigned short copy of the word to the final call; case 0x50 reads
 * the low halfword of c->d[0] before the other words; the saved bytes are an initialised array in an inner
 * block opened after the first call; copies of the ARR_a807a928 sub-record go through a block-local record
 * pointer; the halfword result of case 3 is split as '(v % 65536) >> 8' and 'v % 256'.
 */
struct Cmd {
    unsigned char b0, b1, cmd, b3;
    unsigned int w4;
    unsigned int d[6];
};

struct P300 {
    unsigned char pad[0x110];
    unsigned char b110, b111, b112, b113, b114, b115, b116, b117;
    unsigned char b118, b119, b11a, b11b, b11c, b11d, b11e, b11f;
    unsigned short h120;
    unsigned char b122, b123, b124, b125, b126, b127, b128, b129;
    unsigned char pad2[2];
};
extern struct P300 ARR_a807dc18[];

struct R8fc {
    unsigned short f15 : 1;
    unsigned short f14 : 1;
    unsigned short f13 : 1;
    unsigned short f12 : 1;
    unsigned short f11 : 1;
    unsigned short f10 : 1;
    unsigned short f9 : 1;
    unsigned short f8 : 1;
    unsigned short f7 : 1;
    unsigned short f6 : 1;
    unsigned short f5 : 1;
    unsigned short f4 : 1;
    unsigned short f3 : 1;
    unsigned short f2 : 1;
    unsigned short f1 : 1;
    unsigned short f0 : 1;
    union {
        struct {
            unsigned short g15 : 1;
            unsigned short g14 : 1;
            unsigned short g13 : 1;
            unsigned short g8 : 5;
            unsigned short g0 : 8;
        } f;
        unsigned char b[2];
    } u2;
    unsigned short h4;
    unsigned char b6, b7, b8, b9, ba, bb, bc, bd, be, bf, b10, b11, b12, b13;
};
extern struct R8fc ARR_a807a8fc[];

struct R928 {
    unsigned int b31 : 1;
    unsigned int b30 : 1;
    unsigned int b29 : 1;
    unsigned int b28 : 1;
    unsigned int b27 : 1;
    unsigned int b26 : 1;
    unsigned int b25 : 1;
    unsigned int b24 : 1;
    unsigned int b16 : 8;
    unsigned int b0 : 16;
    unsigned short h4, h6, h8, ha, hc, he, h10, h12;
    unsigned short b14 : 8;
    unsigned short b15 : 8;
    unsigned short h16;
    unsigned int w18;
    unsigned int w1c;
    unsigned int c15 : 17;
    unsigned int c13 : 2;
    unsigned int c12 : 1;
    unsigned int c11 : 1;
    unsigned int c8 : 3;
    unsigned int c0 : 8;
    unsigned char y24, y25, y26, y27;
};
extern struct R928 ARR_a807a928[];

struct R580 {
    unsigned char b0, b1, b2, b3;
    unsigned char pad[0x13];
    unsigned char b17;
    unsigned char pad2[4];
};
extern struct R580 ARR_a807d580[];

struct R24 {
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7;
    unsigned char pad[16];
};
extern struct R24 ARR_a807cc64[];

struct Bits {
    unsigned char a7 : 1;
    unsigned char a6 : 1;
    unsigned char a5 : 1;
    unsigned char a4 : 1;
    unsigned char a3 : 1;
    unsigned char a2 : 1;
    unsigned char a1 : 1;
    unsigned char a0 : 1;
    unsigned char x : 2;
    unsigned char y : 2;
    unsigned char : 4;
    unsigned char b;
};

extern const unsigned short ARR_a80760f0[];
extern unsigned char ARR_a80788d0[];
extern unsigned char DAT_a80788dc;
extern unsigned char DAT_a80788dd;
extern unsigned char DAT_a8079228;
extern unsigned char DAT_a8078748;
extern unsigned char DAT_a8078a0c;
extern unsigned short DAT_a807a8f6;
extern unsigned short DAT_a807a8f8;
extern unsigned int DAT_a807a924;
extern unsigned char DAT_a807cd80;
extern unsigned char DAT_a807cd2d;
extern unsigned char DAT_a80761c0;
extern unsigned char DAT_a80761bf;
extern unsigned char DAT_a80761a8;
extern unsigned char DAT_a807d681;
extern unsigned char DAT_a807d731;
extern unsigned char DAT_a8078c48;
extern unsigned char DAT_a8078c49;
extern unsigned char DAT_a8078a0a;

#define R04 (*(volatile unsigned int *)0xcf03d004)
#define R08 (*(volatile unsigned int *)0xcf03d008)
#define R0C (*(volatile unsigned int *)0xcf03d00c)
#define R10 (*(volatile unsigned int *)0xcf03d010)

extern void *FUN_a00b15ac(void *, int, unsigned int);
extern void *FUN_a00b15d8(void *dst, const void *src, unsigned int n);
extern void FUN_a006fd78(int id, unsigned char len, unsigned char *d);
extern void FUN_a006faa8(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void FUN_a006fad4(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern int FUN_a0073044(const char *fmt, ...);
extern void FUN_a00734d8(unsigned char);
extern void FUN_a006d414(unsigned char n, unsigned char type);
extern int FUN_a00910ec(unsigned char port);
extern int FUN_a00a20c4(unsigned char idx);
extern int FUN_a00acc54(unsigned char port);
extern void func_0x9f1c65a0(unsigned char, unsigned char);
extern void FUN_a007ae30(unsigned char, unsigned char);
extern void FUN_a008ffa4(unsigned char);
extern void FUN_a00a22d4(unsigned char);
extern void FUN_a00a29ec(unsigned char);
extern void FUN_a00a65c4(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a69fc(unsigned char, unsigned short, unsigned char);
extern void func_0x9f1b19b8(unsigned char, unsigned char);
extern void FUN_a00a2418(unsigned char, unsigned char);
extern void FUN_a00a2564(unsigned char);
extern void FUN_a00b1028(unsigned char port, unsigned char flag);
extern void FUN_a00abff0(unsigned char port);
extern void FUN_a00ac66c(unsigned char port);
extern void FUN_a00af98c(unsigned char port);
extern void func_0x9f1cc264(unsigned char);
extern void func_0x9f1cc0a8(void);
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00ac4ec(unsigned char port, unsigned short reg, unsigned char val);
extern void FUN_a00afd74(unsigned char, unsigned char);
extern void FUN_a00abe20(unsigned char port);
extern void FUN_a00afd04(unsigned char, unsigned char);
extern void FUN_a00aea3c(unsigned char, unsigned char, unsigned char);
extern void FUN_a00ae344(unsigned char);
extern void FUN_a00ae1c0(unsigned char);
extern void FUN_a00ad764(unsigned char);
extern void FUN_a00ac5a4(unsigned char);
extern void FUN_a00ae254(unsigned char, unsigned char);
extern void FUN_a00afd3c(unsigned char, unsigned char);
extern void FUN_a00857d0(unsigned char, unsigned char);
extern unsigned char FUN_a008d800(void);
extern void FUN_a0083f04(unsigned char, unsigned char, unsigned char);
extern void FUN_a00ae3a0(unsigned char);
extern void func_0x9f1c66b0(unsigned char);
extern unsigned char FUN_a00ad3e0(unsigned char);
extern void FUN_a00acff4(void);
extern void FUN_a00b14dc(unsigned char, unsigned char);
extern void FUN_a0094594(unsigned char);
extern void FUN_a00918ec(unsigned char);
extern unsigned char FUN_a00a7fd8(unsigned char, unsigned short, unsigned short);
extern unsigned int FUN_a0095ef8(unsigned char);
extern void FUN_a0094308(unsigned char, unsigned char);
extern void FUN_a0087ec8(unsigned int arg, unsigned short *p);
extern void FUN_a0089758(unsigned char, unsigned char);
extern void FUN_a0088f90(unsigned char port, unsigned short bits);
extern unsigned char FUN_a0088f28(unsigned char);
extern void FUN_a00ab548(unsigned char, unsigned char, unsigned char);
extern void FUN_a008983c(unsigned char, unsigned short);
extern void FUN_a0087d50(unsigned char port, unsigned char v);
extern unsigned char FUN_a0088ea0(unsigned char);
extern void func_0x9f1b68f8(unsigned char);
extern void FUN_a00aa45c(unsigned char, unsigned char);
extern void FUN_a00aa49c(unsigned char, unsigned char);
extern void FUN_a0085830(unsigned char, unsigned char);
extern void FUN_a0085888(unsigned char, unsigned char);
extern void FUN_a00858cc(unsigned char, unsigned char);
extern void FUN_a0088ee0(unsigned char, unsigned char);
extern void FUN_a0089e24(unsigned char);
extern void FUN_a0089e54(unsigned char, unsigned char);
extern void FUN_a0070434(struct Cmd *s, unsigned char *d);
extern int FUN_a00865b8(int a, int b);
extern void FUN_a00b1fe0(unsigned char on);
extern void FUN_a006d204(void);
extern void FUN_a006d0fc(void);
extern void FUN_a006fedc(void);
extern unsigned char FUN_a006ffb4(void);
extern unsigned char FUN_a006ffc4(void);
extern unsigned char FUN_a006ffd4(void);
extern unsigned char FUN_a006ffe4(void);
extern void FUN_a0088fd4(unsigned char);
extern void func_0x9f1c3eb0(unsigned short);
extern unsigned char FUN_a006d5a8(unsigned char code);
extern void func_0x9f1c25f4(unsigned char);
extern void func_0x9f1c2618(unsigned char, unsigned char);
extern unsigned char func_0x9f1c3efc(void);
extern void func_0x9f1c3f30(unsigned char);
extern void func_0x9f1c3f54(void);
extern unsigned int FUN_a00ac620(unsigned char ch);
extern void FUN_a006fff4(unsigned char);
extern void FUN_a0070000(unsigned int v);
extern void FUN_a006d46c(unsigned char mask);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a008d8d8(void);
extern void func_0x9f1c3f88(unsigned char);
extern unsigned char FUN_a00a28a4(unsigned char);
extern unsigned char FUN_a00910d0(unsigned char);
extern unsigned char FUN_a00a29b0(unsigned char port);
extern void FUN_a008cba8(struct Bits s);
extern void FUN_a008a868(unsigned char on);
extern void FUN_a008c9a8(unsigned char sel, unsigned char a, unsigned char port, unsigned char c);
extern void FUN_a008b53c(unsigned char, unsigned char);
extern void FUN_a008aaf8(unsigned short v, unsigned char);
extern void FUN_a008aa18(unsigned short v);
extern void FUN_a008a9b0(void);
extern unsigned char FUN_a00a26c4(unsigned char);
extern unsigned char FUN_a00ad7c8(unsigned char ch);
extern unsigned char FUN_a00a26a8(unsigned char);
extern void FUN_a0063950(void);
extern void func_0x9f1c27fc(unsigned char);
extern void func_0x9f1c3f70(unsigned char);
extern void func_0x9f1ce8ac(struct Cmd *);
extern void FUN_a00a72c0(unsigned char ch, unsigned short reg, unsigned char val);
extern unsigned char FUN_a00a657c(unsigned char, unsigned short);
extern unsigned char FUN_a00a69b4(unsigned char, unsigned short);
extern void FUN_a0090380(unsigned char port, unsigned char sel, unsigned char *buf);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a00ac584(unsigned char, unsigned short, unsigned char);
extern void FUN_a00ac550(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00a78b4(unsigned char, unsigned short);
extern void FUN_a00a78fc(unsigned char, unsigned short, unsigned char);
extern void FUN_a006cfac(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned char mode);
extern unsigned char func_0x9f1b6968(unsigned char);
extern void func_0x9f1cd398(struct Cmd *);
extern void FUN_a00afdf4(unsigned char port, unsigned char mode);

void FUN_a0070b7c(struct Cmd *c)
{
    unsigned char buf[0x1c];
    unsigned char *out = buf;
    unsigned char cmd;
    unsigned char reply;
    unsigned char i;
    unsigned char a;
    unsigned char b;
    unsigned char t1;
    unsigned char t2;
    unsigned short v;

    FUN_a00b15ac(out, 0, 0x1c);
    {
        unsigned char save[4] = { 0 };

        save[0] = R04;
        save[1] = R08;
        save[2] = R0C;
        save[3] = R10;
        cmd = c->cmd;
        reply = 0;
        switch (cmd) {
        case 0x00:
            for (i = 0; i < 0x1c; i++)
                buf[i] = i;
            reply = 1;
            break;
        case 0x01:
            FUN_a00734d8(c->w4);
            break;
        case 0x02:
            b = c->w4 >> 8;
            FUN_a006d414(c->w4, b);
            break;
        case 0x03:
            {
                unsigned short x = c->w4;
                v = 0;
                switch (x & 0xff) {
                case 0:
                case 1:
                    v = FUN_a00910ec(x);
                    break;
                case 2:
                case 3:
                    v = FUN_a00a20c4(x - 2);
                    break;
                case 4:
                case 5:
                    v = FUN_a00acc54(x - 4);
                    break;
                case 6:
                    func_0x9f1c65a0(0, 1);
                    v = FUN_a00acc54(0);
                    func_0x9f1c65a0(0, 0);
                    break;
                case 7:
                    func_0x9f1c65a0(0, 2);
                    v = FUN_a00acc54(0);
                    func_0x9f1c65a0(0, 0);
                    break;
                case 8:
                    func_0x9f1c65a0(0, 3);
                    v = FUN_a00acc54(0);
                    func_0x9f1c65a0(0, 0);
                    break;
                }
                buf[1] = (v % 65536) >> 8;
                buf[0] = v % 256;
                reply = 1;
            }
            break;
        case 0x11:
            b = c->w4 >> 8;
            FUN_a007ae30(c->w4, b);
            break;
        case 0x12:
            {
                unsigned int w = c->w4;
                unsigned short x = w;
                if ((unsigned char)w > 1) {
                    a = w - 2;
                    FUN_a00a22d4(a);
                    FUN_a00a29ec(a);
                } else
                    FUN_a008ffa4(w);
                FUN_a00734d8(x);
            }
            break;
        case 0x13:
            {
                unsigned int x = c->w4;
                unsigned char p = x;
                unsigned short r = ARR_a80760f0[(x >> 8) & 0xff];
                t1 = x >> 16;
                if (p > 1)
                    FUN_a00a69fc(x - 2, r, t1);
                else
                    FUN_a00a65c4(p, r, t1);
            }
            break;
        case 0x20:
            a = c->w4;
            ARR_a807dc18[a].b110 = c->w4 >> 8;
            ARR_a807dc18[a].b111 = c->w4 >> 16;
            ARR_a807dc18[a].b112 = (unsigned char)(c->w4 >> 24) & 1;
            ARR_a807dc18[a].b113 = ((unsigned char)(c->w4 >> 24) >> 1) & 1;
            ARR_a807dc18[a].b114 = ((unsigned char)(c->w4 >> 24) >> 2) & 1;
            ARR_a807dc18[a].b115 = ((unsigned char)(c->w4 >> 24) >> 3) & 1;
            ARR_a807dc18[a].b116 = ((unsigned char)(c->w4 >> 24) >> 4) & 1;
            ARR_a807dc18[a].b118 = c->d[0];
            ARR_a807dc18[a].b119 = (c->d[0] >> 8) & 1;
            ARR_a807dc18[a].b11b = ((unsigned char)(c->d[0] >> 8) >> 2) & 1;
            ARR_a807dc18[a].b11c = ((unsigned char)(c->d[0] >> 8) >> 3) & 1;
            ARR_a807dc18[a].b11d = ((unsigned char)(c->d[0] >> 8) >> 4) & 1;
            ARR_a807dc18[a].b11e = ((unsigned char)(c->d[0] >> 8) >> 5) & 1;
            ARR_a807dc18[a].b11f = ((unsigned char)(c->d[0] >> 8) >> 6) & 1;
            ARR_a807dc18[a].b126 = (unsigned char)(c->d[0] >> 8) >> 7;
            ARR_a807dc18[a].h120 = c->d[0] >> 16;
            ARR_a807dc18[a].b117 = c->d[1];
            ARR_a807dc18[a].b122 = 1;
            FUN_a00b1028(a, 0);
            break;
        case 0x21:
            a = c->w4;
            ARR_a807dc18[a].b110 = c->w4 >> 8;
            ARR_a807dc18[a].b111 = c->w4 >> 16;
            ARR_a807dc18[a].b112 = (unsigned char)(c->w4 >> 24) & 1;
            ARR_a807dc18[a].b113 = ((unsigned char)(c->w4 >> 24) >> 1) & 1;
            ARR_a807dc18[a].b114 = ((unsigned char)(c->w4 >> 24) >> 2) & 1;
            ARR_a807dc18[a].b115 = ((unsigned char)(c->w4 >> 24) >> 3) & 1;
            ARR_a807dc18[a].b116 = ((unsigned char)(c->w4 >> 24) >> 4) & 1;
            ARR_a807dc18[a].b117 = c->d[1];
            ARR_a807dc18[a].b122 = 1;
            FUN_a00abff0(a);
            FUN_a00ac66c(a);
            FUN_a00af98c(a);
            func_0x9f1cc264(c->w4);
            func_0x9f1cc0a8();
            break;
        case 0x22:
            {
                unsigned int x = c->w4;
                unsigned char p = x;
                unsigned short r = x >> 8;
                if (r < 0x200 || r >= 0x400)
                    buf[0] = 0;
                else
                    buf[0] = FUN_a00a6bb8(p, r);
            }
            reply = 1;
            break;
        case 0x23:
            FUN_a00ac4ec(c->w4, c->w4 >> 8, c->w4 >> 24);
            break;
        case 0x24:
            a = c->w4;
            i = c->w4 >> 8;
            ARR_a807a928[0].b29 = i;
            ARR_a807dc18[a].b112 = i;
            FUN_a0073044("_SetDPMST %d\r\n", i);
            FUN_a00afd74(a, i);
            func_0x9f1cc264(a);
            func_0x9f1cc0a8();
            break;
        case 0x2f:
            FUN_a0073044("\033[1;32mMSTLogicalNum : %d\r\n\033[m", (unsigned char)c->w4);
            func_0x9f1c66b0(c->w4);
            break;
        case 0x25:
            {
                unsigned int x = c->w4;
                unsigned char p = x, q = x >> 8, r = x >> 16;
                ARR_a807dc18[p].b117 = q;
                ARR_a807dc18[p].b110 = r;
                FUN_a00abe20(p);
            }
            break;
        case 0x26:
            b = c->w4 >> 8;
            FUN_a00afd04(c->w4, b);
            break;
        case 0x27:
            {
                unsigned int x = c->w4;
                b = x >> 8;
                t1 = x >> 16;
                FUN_a00aea3c(x, b, t1);
            }
            break;
        case 0x28:
            FUN_a00ae344(c->w4);
            break;
        case 0x29:
            t1 = c->w4 >> 8;
            func_0x9f1c65a0(c->w4, t1);
            break;
        case 0x2a:
            FUN_a00ae1c0(c->w4);
            break;
        case 0x2b:
            a = c->w4;
            FUN_a00ad764(a);
            FUN_a00ac5a4(a);
            break;
        case 0x2c:
            b = c->w4 >> 8;
            FUN_a00ae254(c->w4, b);
            break;
        case 0x2d:
            b = c->w4 >> 8;
            FUN_a00afd3c(c->w4, b);
            break;
        case 0x33:
            a = c->w4;
            b = c->w4 >> 8;
            FUN_a00b14dc(a, b);
            FUN_a00abff0(a);
            break;
        case 0x2e:
            {
                unsigned int x = c->w4;
                unsigned char p = x, q = x >> 8, r = x >> 16, t = x >> 24, m = c->d[0];
                ARR_a807dc18[p].b118 = q;
                ARR_a807dc18[p].b11a = r;
                ARR_a807dc18[p].b11b = t;
                if (m == 0) {
                    FUN_a00857d0(p, 0);
                    if (FUN_a008d800() > 0xdf)
                        FUN_a0083f04(p, 0, 1);
                } else {
                    FUN_a00857d0(p, 1);
                    if (FUN_a008d800() > 0xdf)
                        FUN_a0083f04(p, 1, 1);
                }
                FUN_a00ae3a0(p);
            }
            break;
        case 0x30:
            a = c->w4;
            if (a < 2)
                ARR_a807dc18[a].b128 = 1;
            break;
        case 0x31:
            if (FUN_a00ad3e0(0) == 1 || FUN_a00ad3e0(1) == 1) {
                buf[0] = 1;
                FUN_a00acff4();
            } else
                buf[0] = 0;
            reply = 1;
            break;
        case 0x32:
            {
                unsigned int x = c->w4;
                unsigned char p = x, q = x >> 8;
                if (p < 2)
                    ARR_a807dc18[p].b129 = q;
            }
            break;
        case 0x40:
            {
                unsigned int x = c->w4;
                unsigned char p = x, q = x >> 8, r = x >> 16, t = x >> 24, m = c->d[0];
                ARR_a807a8fc[p].b10 = q;
                ARR_a807a8fc[p].b11 = r;
                ARR_a807a8fc[p].b12 = t;
                ARR_a807a8fc[p].b13 = m;
                if (p < 2)
                    FUN_a0094594(p);
            }
            break;
        case 0x41:
            a = c->w4;
            b = c->w4 >> 8;
            ARR_a807a8fc[a].f12 = b;
            if (a < 2)
                FUN_a00918ec(a);
            break;
        case 0x42:
            b = c->w4;
            if (b < 2) {
                unsigned char f, g, h, t;
                unsigned short x;
                ARR_a807a8fc[b].u2.b[1] = c->w4 >> 8;
                ARR_a807a8fc[b].h4 = c->w4 >> 16;
                f = c->d[0];
                ARR_a807a8fc[b].f13 = f >> 7;
                ARR_a807a8fc[b].f11 = f >> 6;
                ARR_a807a8fc[b].f10 = f >> 5;
                ARR_a807a8fc[b].b6 = f & 0x1f;
                ARR_a807a8fc[b].b7 = c->d[0] >> 8;
                x = c->d[0] >> 16;
                ARR_a807a8fc[b].b9 = x & 0xf;
                ARR_a807a8fc[b].ba = (x & 0xf0) >> 4;
                g = c->d[0] >> 24;
                ARR_a807a8fc[b].f12 = g;
                ARR_a807a8fc[b].f9 = g >> 1;
                ARR_a807a8fc[b].f8 = g >> 2;
                ARR_a807a8fc[b].f14 = g >> 3;
                ARR_a807a8fc[b].f5 = g >> 4;
                ARR_a807a8fc[b].f4 = g >> 5;
                ARR_a807a8fc[b].f3 = g >> 6;
                ARR_a807a8fc[b].u2.f.g13 = g >> 7;
                if ((unsigned char)(ARR_a807a8fc[b].u2.b[1] + 0x1f) < 2)
                    t = ARR_a807d580[b].b17;
                else
                    t = ARR_a807d580[b].b1;
                switch (t) {
                case 0x71:
                case 0x81:
                    if (ARR_a807a8fc[b].b9 < 8)
                        ARR_a807a8fc[b].b9 = 8;
                    break;
                }
                ARR_a807a8fc[b].b8 = c->d[1];
                x = c->d[1] >> 16;
                h = x;
                ARR_a807a8fc[b].f7 = x;
                ARR_a807a8fc[b].f6 = h >> 1;
                ARR_a807a8fc[b].f2 = h >> 3;
                ARR_a807a8fc[b].f1 = h >> 4;
                ARR_a807a8fc[b].f0 = h >> 5;
                ARR_a807a8fc[b].u2.f.g15 = (h >> 6) & 1;
                ARR_a807a8fc[b].u2.f.g14 = h >> 7;
                ARR_a807a8fc[b].bd = c->d[1] >> 24;
                ARR_a807a8fc[b].be = c->d[2];
                ARR_a807a8fc[b].bf = c->d[2] >> 8;
                ARR_a807a8fc[b].bc = c->d[3] >> 16;
                FUN_a00918ec(b);
            }
            break;
        case 0x43:
            a = c->w4;
            if (a < 2) {
                ARR_a807a8fc[a].f14 = 0;
                FUN_a00918ec(a);
            }
            break;
        case 0x44:
            {
                unsigned int x = c->w4;
                unsigned char p = x, q = x >> 8, r = x >> 16, t = x >> 24, m = c->d[0];
                ARR_a807a8fc[p].b10 = q;
                ARR_a807a8fc[p].b11 = r;
                ARR_a807a8fc[p].b12 = t;
                ARR_a807a8fc[p].b13 = m;
                if (p < 2)
                    FUN_a00918ec(p);
            }
            break;
        case 0x45:
            a = c->w4;
            if (a < 2) {
                buf[0] = FUN_a00a7fd8(a, 0, 0x3a);
                buf[1] = FUN_a00a7fd8(a, 0, 0x3b);
                buf[2] = FUN_a00a7fd8(a, 0, 0x3c);
                buf[3] = FUN_a00a7fd8(a, 0, 0x3d);
                buf[4] = FUN_a00a7fd8(a, 0, 0x60);
                buf[5] = FUN_a00a7fd8(a, 0, 0x61);
                buf[6] = FUN_a00a7fd8(a, 0, 0x62);
                buf[7] = FUN_a00a7fd8(a, 0, 0x63);
            }
            reply = 1;
            break;
        case 0x50:
            b = c->w4;
            ARR_a807a928[b].b31 = c->w4 >> 8;
            ARR_a807a928[b].b30 = c->w4 >> 9;
            ARR_a807a928[b].b29 = c->w4 >> 10;
            ARR_a807a928[b].b28 = c->w4 >> 11;
            ARR_a807a928[b].b27 = c->w4 >> 12;
            ARR_a807a928[b].b25 = c->w4 >> 13;
            ARR_a807a928[b].b16 = (c->w4 & 0xff0000) >> 16;
            {
                unsigned int k = (unsigned short)c->d[0];
                unsigned int d1, d2, d3, d4;
                ARR_a807a928[b].b14 = (c->d[0] & 0xff0000) >> 16;
                ARR_a807a928[b].b15 = c->d[0] >> 24;
                d1 = c->d[1];
                d2 = c->d[2];
                d3 = c->d[3];
                d4 = c->d[4];
                ARR_a807a928[b].h4 = d1;
                ARR_a807a928[b].h6 = d1 >> 16;
                ARR_a807a928[b].h8 = d2;
                ARR_a807a928[b].ha = d2 >> 16;
                ARR_a807a928[b].hc = d3;
                ARR_a807a928[b].he = d3 >> 16;
                ARR_a807a928[b].h10 = d4;
                ARR_a807a928[b].h12 = d4 >> 16;
                ARR_a807a928[b].w18 = k;
            }
            ARR_a807a928[b].y25 = 0;
            {
                struct R928 *r = &ARR_a807a928[b];
                unsigned short t[14];
                FUN_a00b15d8(t, &r->h4, 0x1c);
                FUN_a0087ec8(b, t);
            }
            break;
        case 0x51:
            {
                unsigned int x = c->w4;
                unsigned char p = x, q = x >> 8, s = x >> 16;
                ARR_a807a928[p].b14 = q;
                ARR_a807a928[p].b15 = s;
                a = p;
            }
            {
                struct R928 *r = &ARR_a807a928[a];
                unsigned short t[14];
                FUN_a00b15d8(t, &r->h4, 0x1c);
                FUN_a0087ec8(a, t);
            }
            break;
        case 0x52:
            a = c->w4;
            b = c->w4 >> 8;
            ARR_a807a928[a].b27 = b;
            {
                struct R928 *r = &ARR_a807a928[a];
                unsigned short t[14];
                FUN_a00b15d8(t, &r->h4, 0x1c);
                FUN_a0087ec8(a, t);
            }
            break;
        case 0x53:
            a = c->w4;
            b = c->w4 >> 8;
            ARR_a807a928[a].b28 = b;
            {
                struct R928 *r = &ARR_a807a928[a];
                unsigned short t[14];
                FUN_a00b15d8(t, &r->h4, 0x1c);
                FUN_a0087ec8(a, t);
            }
            break;
        case 0x54:
            a = c->w4;
            b = c->w4 >> 8;
            ARR_a807a928[a].b30 = b;
            break;
        case 0x55:
            a = c->w4;
            b = c->w4 >> 8;
            ARR_a807a928[a].b31 = b;
            FUN_a0089758(a, ARR_a807a928[a].b31);
            break;
        case 0x57:
            buf[0] = FUN_a0088f28(c->w4);
            reply = 1;
            break;
        case 0x56:
            FUN_a0088f90(c->w4, c->w4 >> 8);
            break;
        case 0x59:
            b = c->w4;
            for (i = 0; i < 4; i++)
            {
                unsigned int v = c->d[i >> 1];
                unsigned char sh = (i & 1) * 16;
                t1 = v >> sh;
                t2 = v >> (sh + 8);
                FUN_a00ab548((b & 0xf) | (i << 4), t1, t2);
            }
            break;
        case 0x5a:
            FUN_a008983c(c->w4, c->w4 >> 8);
            break;
        case 0x5b:
            a = c->w4;
            b = c->w4 >> 8;
            ARR_a807a928[a].b25 = b;
            FUN_a0087d50(a, b);
            break;
        case 0xfd:
            buf[0] = func_0x9f1b6968(c->w4);
            reply = 1;
            break;
        case 0x5c:
            buf[0] = FUN_a0088ea0(c->w4);
            reply = 1;
            break;
        case 0x5d:
            func_0x9f1b68f8(c->w4 >> 8);
            reply = 1;
            break;
        case 0x70:
            DAT_a80788dd = c->w4;
            break;
        case 0x72:
            FUN_a00865b8(0, 0);
            FUN_a00b1fe0(1);
            FUN_a006d204();
            DAT_a80788dc = 1;
            FUN_a006fedc();
            FUN_a00b1fe0(0);
            for (;;)
                ;
        case 0x80:
            a = c->w4;
            ARR_a807dc18[a].b11f = c->w4 >> 8;
            FUN_a00b1028(a, 0);
            break;
        case 0x81:
            {
                unsigned int m = c->w4;
                unsigned int t = 0;
                FUN_a006faa8(0, 3, &t, 1);
                t = (t & ~0xff0000) | (((t >> 16) & ~m & 0xff) << 16);
                FUN_a006fad4(0, 3, &t, 1);
            }
            break;
        case 0x96:
            ARR_a80788d0[(unsigned char)c->w4] = c->w4 >> 8;
            break;
        case 0xa0:
            switch ((unsigned char)c->w4) {
            case 0:
            case 1:
                buf[0] = 0;
                break;
            case 2:
                buf[0] = FUN_a00a26c4(0);
                break;
            case 3:
                buf[0] = FUN_a00a26c4(1);
                break;
            case 4:
                buf[0] = FUN_a00ad7c8(0);
                break;
            case 5:
                buf[0] = FUN_a00ad7c8(1);
                break;
            }
            reply = 1;
            break;
        case 0xa4:
            b = c->w4;
            buf[0] = 0;
            switch (b) {
            case 2:
                buf[0] = DAT_a807d681;
                break;
            case 3:
                buf[0] = DAT_a807d731;
                break;
            }
            reply = 1;
            break;
        case 0xa1:
            switch ((unsigned char)c->w4) {
            case 0:
            case 1:
                buf[0] = 0;
                break;
            case 2:
                buf[0] = FUN_a00a26a8(0);
                break;
            case 3:
                buf[0] = FUN_a00a26a8(1);
                break;
            case 4:
            case 5:
                buf[0] = 8;
                break;
            }
            reply = 1;
            break;
        case 0x82:
            for (i = 0; i < 0x1c; i++)
                buf[i] = i;
            reply = 1;
            break;
        case 0x83:
            {
                unsigned char p = c->w4;
                unsigned char hi = 0;
                unsigned char s = c->w4 >> 8;
                if ((unsigned char)c->w4 >= 2) {
                    p = c->w4 - 2;
                    hi = 1;
                }
                switch (s) {
                case 0:
                    if (!(hi ? FUN_a00a28a4(p) : FUN_a00910d0(p)))
                        out[0] = 0;
                    else
                        out[0] = 1;
                    break;
                case 1:
                    if (hi)
                        FUN_a00a29b0(p);
                    out[0] = 0;
                    out[1] = 0;
                    out[2] = 0;
                    out[3] = 0;
                    out[4] = 0;
                    out[5] = 0;
                    break;
                }
            }
            reply = 1;
            break;
        case 0x84:
            for (i = 0; i < 0x1c; i++)
                buf[i] = i;
            reply = 1;
            break;
        case 0x87:
            reply = 1;
            buf[0] = FUN_a008d8d8();
            break;
        case 0x85:
            for (i = 0; i < 0x1c; i++)
                buf[i] = i;
            reply = 1;
            break;
        case 0x86:
            FUN_a00a6c00(c->w4, 0x252, (c->w4 >> 3) & 0xe0);
            break;
        case 0x74:
            DAT_a8079228 = c->w4;
            DAT_a8078748 = 1;
            break;
        case 0x71:
            FUN_a0070434(c, buf);
            reply = 1;
            break;
        case 0x14:
            func_0x9f1b19b8(c->w4 >> 8, c->w4);
            break;
        case 0x5e:
            a = c->w4;
            ARR_a807a928[a].c13 = c->w4 >> 8;
            ARR_a807a928[a].c12 = (unsigned char)(c->w4 >> 8) >> 2;
            if (a != 0)
                DAT_a807cd2d = c->w4 >> 16;
            ARR_a807a928[a].c0 = c->d[0];
            ARR_a807a928[a].y24 = c->d[0] >> 8;
            if (a != 0) {
                DAT_a80761c0 = c->d[0] >> 16;
                DAT_a80761bf = c->d[0] >> 24;
                DAT_a80761a8 = c->d[1];
            }
            ARR_a807a928[a].c11 = (unsigned char)(c->d[1] >> 8);
            FUN_a00aa45c(a, ARR_a807a928[a].c12);
            FUN_a00aa49c(a, ARR_a807a928[a].c13);
            FUN_a0085830(a, ARR_a807a928[a].c0);
            FUN_a0085888(a, ARR_a807a928[a].y24);
            FUN_a00858cc(a, ARR_a807a928[a].c11);
            break;
        case 0xa5:
            func_0x9f1ce8ac(c);
            break;
        case 0x5f:
            b = c->w4 >> 8;
            FUN_a0088ee0(c->w4, b);
            break;
        case 0x60:
            a = c->w4;
            if (a < 5)
                FUN_a0089e24(a);
            break;
        case 0x63:
            b = c->w4 >> 8;
            FUN_a0089e54(c->w4, b);
            break;
        case 0x75:
            {
                unsigned int x = c->w4;
                DAT_a8078a0c = x;
                if ((unsigned char)x == 0) {
                    if (FUN_a006ffb4())
                        FUN_a0088fd4(1);
                    if (FUN_a006ffc4())
                        FUN_a0088fd4(2);
                    if (FUN_a006ffd4())
                        FUN_a0088fd4(3);
                    if (FUN_a006ffe4())
                        FUN_a0088fd4(4);
                }
            }
            break;
        case 0x76:
            DAT_a807a8f6 = c->w4;
            func_0x9f1c3eb0(c->w4);
            DAT_a807a8f8 = c->w4 >> 16;
            break;
        case 0x77:
            func_0x9f1c25f4(FUN_a006d5a8(c->w4));
            break;
        case 0x78:
            func_0x9f1c2618(FUN_a006d5a8(c->w4), c->w4 >> 8);
            break;
        case 0x79:
            reply = 1;
            buf[0] = func_0x9f1c3efc();
            break;
        case 0x7a:
            func_0x9f1c3f30(c->w4);
            break;
        case 0x7b:
            func_0x9f1c3f54();
            break;
        case 0x88:
            func_0x9f1c3f88(c->w4);
            break;
        case 0xa2:
            FUN_a0063950();
            func_0x9f1c27fc(0);
            break;
        case 0xa3:
            func_0x9f1c3f70(c->w4);
            break;
        case 0x7c:
            switch ((unsigned char)c->w4) {
            case 4:
            case 6:
            case 7:
            case 8:
                DAT_a807a924 = FUN_a00ac620(0);
                break;
            case 5:
                DAT_a807a924 = FUN_a00ac620(1);
                break;
            default:
                DAT_a807a924 = 0;
                break;
            }
            buf[0] = DAT_a807a924;
            buf[1] = DAT_a807a924 >> 8;
            buf[2] = DAT_a807a924 >> 16;
            buf[3] = 0;
            reply = 1;
            break;
        case 0x7d:
            FUN_a006fff4(c->w4);
            break;
        case 0x7f:
            FUN_a006d46c(c->w4);
            break;
        case 0x7e:
            FUN_a0070000(c->w4);
            break;
        case 0x73:
            FUN_a0073044("_SetLeonSPowerDown %d\r\n", 999);
            FUN_a00865b8(0, 0);
            FUN_a00b1fe0(1);
            FUN_a006d0fc();
            DAT_a80788dc = 1;
            FUN_a006fedc();
            FUN_a00b1fe0(0);
            for (;;)
                ;
        case 0x46:
            a = c->w4;
            if (a < 2) {
                reply = 1;
                buf[0] = FUN_a0095ef8(a) & 1;
            }
            break;
        case 0x47:
            a = c->w4;
            b = c->w4 >> 8;
            if (a < 2)
                FUN_a0094308(a, b);
            break;
        case 0x15:
            ARR_a807cc64[(unsigned char)c->w4].b7 = c->w4 >> 8;
            break;
        case 0x16:
            {
                unsigned int x = c->w4;
                unsigned char p = x, t;
                t1 = x >> 8;
                t2 = x >> 16;
                t = 0;
                if (p != 2)
                    t = p == 3 ? 1 : 0xff;
                if (t1 == 1 && t != 0xff)
                    FUN_a00a2418(t, t2);
                else
                    FUN_a00a2564(t2);
            }
            break;
        case 0x90:
            {
                struct Bits s;
                unsigned int x = c->w4;
                unsigned char p;
                s.a7 = x & 1;
                p = x;
                s.a6 = p >> 1;
                s.a5 = p >> 2;
                s.a4 = p >> 3;
                s.a3 = p >> 4;
                s.a2 = p >> 5;
                s.a1 = p >> 6;
                s.a0 = p >> 7;
                s.b = x >> 8;
                s.x = x >> 16;
                s.y = x >> 24;
                FUN_a008cba8(s);
            }
            break;
        case 0x91:
            DAT_a807cd80 = c->w4;
            FUN_a008a868(DAT_a807cd80);
            break;
        case 0x92:
            {
                unsigned int x = c->w4;
                unsigned char x0 = x, x3 = x >> 24;
                t1 = x >> 8;
                t2 = x >> 16;
                FUN_a008c9a8(x0, t1, t2, x3);
            }
            break;
        case 0x93:
            FUN_a008b53c(c->w4, c->w4 >> 8);
            break;
        case 0x94:
            {
                unsigned int x = c->w4;
                unsigned char p = x;
                unsigned short r = x >> 8;
                if (p == 1)
                    FUN_a008aaf8(r, 1);
                else if (p == 0)
                    FUN_a008aa18(r);
            }
            break;
        case 0x95:
            FUN_a008a9b0();
            break;
        case 0xf0:
            FUN_a00a72c0(c->w4, c->w4 >> 8, c->w4 >> 24);
            break;
        case 0xf1:
            {
                unsigned int x = c->w4;
                unsigned short r = x >> 8;
                unsigned char k = x >> 24;
                if ((unsigned char)x > 1)
                    FUN_a00a69fc(x - 2, r, k);
                else
                    FUN_a00a65c4(x, r, k);
            }
            break;
        case 0xf2:
            {
                unsigned int x = c->w4;
                unsigned short r = x >> 8;
                if ((unsigned char)x > 1)
                    buf[0] = FUN_a00a69b4(x - 2, r);
                else
                    buf[0] = FUN_a00a657c(x, r);
            }
            reply = 1;
            break;
        case 0xf3:
            FUN_a0090380(c->w4, c->w4 >> 8, buf);
            reply = 1;
            break;
        case 0xf4:
            {
                unsigned int x = c->w4;
                unsigned char x0 = x;
                t1 = x >> 8;
                FUN_a00a8054(x0, t1, x >> 16, c->d[0]);
            }
            break;
        case 0xf5:
            FUN_a00ac584(c->w4, c->w4 >> 8, c->w4 >> 24);
            break;
        case 0xf6:
            FUN_a00ac550(c->w4, c->w4 >> 8, c->w4 >> 24);
            break;
        case 0xf7:
            buf[0] = FUN_a00a6bb8(c->w4, c->w4 >> 8);
            reply = 1;
            break;
        case 0xf8:
            buf[0] = FUN_a00a78b4(c->w4, c->w4 >> 8);
            reply = 1;
            break;
        case 0xf9:
            FUN_a00a78fc(c->w4, c->w4 >> 8, c->w4 >> 24);
            break;
        case 0xfa:
            FUN_a006cfac(c->w4, c->d[0], c->d[1], c->d[2], c->d[3]);
            break;
        case 0xfb:
            a = c->w4;
            if (a & 1)
                DAT_a8078c48 = 0;
            if (a & 2)
                DAT_a8078c49 = 0;
            if (a & 4)
                DAT_a8078a0a = 0;
            break;
        case 0xfe:
            func_0x9f1cd398(c);
            break;
        case 0xff:
            FUN_a00afdf4(c->w4, 0);
            break;
        case 0xa6:
            FUN_a0073044("=====AT Prepare Timing Change %08lX %08lX %08lX=====\r\n", c->w4, c->d[0], c->d[1]);
            break;
        }
        if (reply)
            FUN_a006fd78(cmd, 0x1c, buf);
        {
            unsigned int w = 0;
            FUN_a006fad4(8, 0, &w, 1);
        }
        R04 = save[0];
        R08 = save[1];
        R0C = save[2];
        R10 = save[3];
    }
}
