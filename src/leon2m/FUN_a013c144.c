/* leon2m FUN_a013c144 @ 0xa013c144-0xa013c894 (1872 bytes = 468 insns)  apply the output timing of one port
 * (writer of record byte +0x68). Hand; -mcpu=v8 -O3 -g
 * (jf.py 100 % match=True, rawcmp.py 468 words / 0 mismatches; -msoft-float gives the same bytes).
 *
 * int FUN_a013c144(unsigned char a, unsigned char port, unsigned char c), returns 1. rec = FUN_a013cd4c(port).
 * 1. t = FUN_a00fd820(port) (t == 0xB1 -> t = FUN_a012fc20()); flag = a != 0xFF and t in {0x31,0x41,0x51,0x61}.
 *    FUN_a00f8e2c(port, 0); if FUN_a0142e8c(port) == 5: [flag: FUN_a0121f20(a, port)], FUN_a00f40e4(port),
 *    FUN_a013bfa8(port, c), [flag: FUN_a0132a14(a)].
 * 2. hook 0xA802CC34 (DAT_a802cc1c[6]) if set: i = first of 0..3 with bits 12-15 of word 0xA802DF30 + 0x78*i == port
 *    (port <= 3 only), then the j in 0..3 with FUN_a01436b4(j) == i; hook(j), or hook(0xFF) when none.
 * 3. big = ((rec+0x10 - rec+0x14) * rec+0x0E) / 2 (unsigned) > 0x1FFF; FUN_a00f8918(port);
 *    if rec+0x12 != +0x16 or +0x14 != +0x18: [big: FUN_a00f88e8(port, +0x20 >= +0x1C ? +0x20 - +0x1C : +0x20)],
 *    FUN_a00f8ef4(port); else FUN_a0121d4c(port) == 1 -> FUN_a00f8918(port), else big -> FUN_a00f88e8(port, 0).
 * 4. w = rec+0x16, h = rec+0x18. Port 0 with FUN_a00f8f34(0) == 1 (fix0, port-0 record r):
 *    pad = 0, odd = 0; if FUN_a010a874(): pad = (16 - r+0x16 % 16) % 16, clamp r+0x1E to r+0x0E - r+0x16 - pad;
 *    odd = r+0x18 & 1; clamp r+0x20 to (FUN_a0121258(0) ? 2 * r+0x10 : r+0x10) - r+0x18 - odd.
 *    w = r+0x16 + pad, h = r+0x18 + odd, and ALWAYS (also when FUN_a010a874() == 0, then odd = 0 -> byte 0)
 *    r byte +0x68 = RAW row 0xA802E378 +0x0A * odd * 110 / 100 / r+0x18 (unsigned) (0xA013C824).
 * 5. FUN_a00f8938(port, w, h); rec+0x3E == 1 && FUN_a013cecc(rec+0 low nibble) ? FUN_a00f896c : FUN_a00f8a98
 *    (port, +0x0E, +0x12, +0x14); FUN_a00f8cc4(port, +0x0E).
 * 6. 0xA802E3D0 bit 25 && rec+0x70 bit 31 && FUN_a0121258(port) == 1: FUN_a0114420(w, h), FUN_a0105e60(w, h, +0x08),
 *    FUN_a010a824(port), delay 50, FUN_a0105d20(); else FUN_a010a83c(port).
 * 7. FUN_a00f8e0c(port, FUN_a00f8f34(port) ? +0x1E - +0x1A : +0x1E); FUN_a00f8e44(port, +0x20);
 *    rec+0x70 bit 30: FUN_a0142518(port, w, h).
 * 8. FUN_a013c040(port, w, h) INLINED (0xA013C3D4..0xA013C45C, 0xA013C66C..C6C0: the byte-exact sister, copied here).
 * 9. FUN_a00f8ce4(port, (rec+0x3E != 0 && port > 3) ? +0x16 >> 1 : +0x16, h, 0); FUN_a0121e3c(port).
 *
 * SOURCE FORMS (all needed for the exact bytes, none is a no-code hint):
 *  - FUN_a013c040 is in the same file and declared 'inline' (gcc 3.4 -O3 inlines it; without 'inline' it stays a call).
 *  - w and h are addressable locals (fp-138 / fp-140, reloaded after every call): they are passed by address to a
 *    static function (fix0) that gcc inlines. Declaration order h, w.
 *  - record +0x70 bit 31 is a 1-bit BITFIELD (union with the word; bit 30 is tested as a word mask). With 'w70 < 0'
 *    the FRC block and the interlace block are laid out in the wrong place (84 % instead of 100 %).
 *    FUN_a013c040 stays byte-exact with this record type (jf FUN_a013c040 on this file = 100 %).
 *  - record +0 low nibble read as a 4-bit bitfield (lduh; a plain '& 0xf' becomes ldub +1).
 *  - 'big = 0; if (x > 0x1fff) big = 1;' with x an unsigned int local (reused for the FUN_a00f8ce4 argument).
 *  - 'pad = 0x10 - h16 % 16; pad %= 16;' two statements (one expression folds 16 - y to neg); 'odd = h18 % 2'.
 *  - FUN_a00f88e8 / FUN_a00f8e0c written as two calls in if/else (gcc merges them).
 *  - the step-3 test is written 'h12 != h16 || h14 != h18' with the big arm FIRST (rnreg LRU tick order; the
 *    opposite arm order is 98.93 % with two register differences).
 */
struct Timing { unsigned char d[0x3c]; };
struct Out {
    union {
        struct { unsigned char pad0[6]; struct Timing t; } a;
        struct {
            unsigned short h00_hi : 12, h00_lo : 4;
            unsigned short h02, h04, h06, h08, h0a, h0c, h0e, h10, h12, h14, h16, h18, h1a, h1c, h1e, h20;
            unsigned char p22[0x1c];
            unsigned char b3e;
        } b;
    } u;
    unsigned char pad42[0x26];
    union { unsigned int w; unsigned char b[4]; } r68;
    unsigned int w6c;
    union { unsigned int w; struct { unsigned int b31 : 1, rest : 31; } f; } w70;
};
struct RawRow { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; };
struct Port { unsigned int w0; unsigned char p04[0x74]; };
extern struct RawRow DAT_a802e378;
extern unsigned int DAT_a802e3d0;
extern void (*DAT_a802cc1c[15])(unsigned char);
extern struct Port DAT_a802df30[];
extern struct Out *FUN_a013cd4c(unsigned char port);
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern unsigned char FUN_a0121258(unsigned char port);
extern void FUN_a01086fc(unsigned char a, struct Timing *t, unsigned short w, unsigned short h, unsigned char il, unsigned char x, unsigned char y);
extern void FUN_a00f9880(void);
extern unsigned char FUN_a00fd820(unsigned char);
extern unsigned char FUN_a012fc20(void);
extern void FUN_a00f8e2c(unsigned char, unsigned short);
extern unsigned char FUN_a0142e8c(unsigned int);
extern void FUN_a0121f20(unsigned char, unsigned char);
extern void FUN_a00f40e4(unsigned char);
extern void FUN_a013bfa8(unsigned char, unsigned char);
extern void FUN_a0132a14(unsigned char);
extern unsigned char FUN_a01436b4(unsigned char);
extern void FUN_a00f8918(unsigned char);
extern unsigned char FUN_a0121d4c(unsigned char);
extern void FUN_a00f88e8(unsigned char, unsigned short);
extern void FUN_a00f8ef4(unsigned char);
extern unsigned char FUN_a00f8f34(unsigned char);
extern unsigned char FUN_a010a874(void);
extern void FUN_a00f8938(unsigned char, unsigned short, unsigned short);
extern unsigned char FUN_a013cecc(unsigned char);
extern void FUN_a00f896c(unsigned char, unsigned short, unsigned short, unsigned short);
extern void FUN_a00f8a98(unsigned char, unsigned short, unsigned short, unsigned short);
extern void FUN_a00f8cc4(unsigned char, unsigned short);
extern void FUN_a0114420(unsigned short, unsigned short);
extern void FUN_a0105e60(unsigned short, unsigned short, unsigned short);
extern void FUN_a010a824(unsigned char);
extern void func_0x4008d1a0(int ms);
extern void FUN_a0105d20(void);
extern void FUN_a010a83c(unsigned char);
extern void FUN_a00f8e0c(unsigned char, unsigned short);
extern void FUN_a00f8e44(unsigned char, unsigned short);
extern void FUN_a0142518(unsigned char, unsigned short, unsigned short);
extern void FUN_a00f8ce4(unsigned char, unsigned short, unsigned short, unsigned char);
extern void FUN_a0121e3c(unsigned char);

inline void FUN_a013c040(unsigned char port, unsigned short w, unsigned short h)
{
    struct Out *o;
    struct Timing t2;
    struct Timing t1;

    o = FUN_a013cd4c(port);
    if (port != 0)
        return;
    if ((DAT_a802e3d0 & 0x2000000) && o->w70.f.b31 && FUN_a0121258(0) == 1) {
        FUN_a013c910(&t2, &o->u.a.t, 0x3c);
        FUN_a01086fc(0, &t2, w, o->u.b.h18, 1, 0, 0);
        o->r68.b[0] = 0;
    } else {
        FUN_a013c910(&t1, &o->u.a.t, 0x3c);
        FUN_a01086fc(0, &t1, w, h, 0, 0, 0);
    }
    o->r68.w &= ~0x400000;
    o->r68.w &= ~0x200000;
    FUN_a00f9880();
}

static void fix0(unsigned short *w, unsigned short *h)
{
    struct Out *r;
    unsigned char pad, odd;

    r = FUN_a013cd4c(0);
    pad = 0;
    odd = 0;
    if (FUN_a010a874()) {
        pad = 0x10 - r->u.b.h16 % 16;
        pad %= 16;
        if (r->u.b.h1e + r->u.b.h16 + pad > r->u.b.h0e)
            r->u.b.h1e = r->u.b.h0e - r->u.b.h16 - pad;
        odd = r->u.b.h18 % 2;
        if (FUN_a0121258(0)) {
            if (r->u.b.h20 + r->u.b.h18 + odd > r->u.b.h10 * 2)
                r->u.b.h20 = r->u.b.h10 * 2 - r->u.b.h18 - odd;
        } else {
            if (r->u.b.h20 + r->u.b.h18 + odd > r->u.b.h10)
                r->u.b.h20 = r->u.b.h10 - r->u.b.h18 - odd;
        }
    }
    *w = r->u.b.h16 + pad;
    *h = r->u.b.h18 + odd;
    r->r68.b[0] = DAT_a802e378.h0a * odd * 110u / 100 / r->u.b.h18;
}

int FUN_a013c144(unsigned char a, unsigned char port, unsigned char c)
{
    struct Out *rec;
    struct Out *r;
    unsigned char t, flag, i, idx, found, big;
    unsigned int x;
    unsigned short h;
    unsigned short w;

    rec = FUN_a013cd4c(port);
    t = FUN_a00fd820(port);
    flag = 0;
    if (t == 0xb1)
        t = FUN_a012fc20();
    if (a != 0xff && (t == 0x31 || t == 0x41 || t == 0x51 || t == 0x61))
        flag = 1;
    FUN_a00f8e2c(port, 0);
    if (FUN_a0142e8c(port) == 5) {
        if (flag)
            FUN_a0121f20(a, port);
        FUN_a00f40e4(port);
        FUN_a013bfa8(port, c);
        if (flag)
            FUN_a0132a14(a);
    }
    if (DAT_a802cc1c[6] != 0) {
        i = 0;
        found = 0;
        if (port < 4) {
            for (i = 0; i < 4; i++)
                if (port == ((DAT_a802df30[i].w0 >> 12) & 0xf))
                    break;
            if (i < 4) {
                idx = i;
                for (i = 0; i < 4; i++)
                    if (FUN_a01436b4(i) == idx) {
                        found = 1;
                        break;
                    }
            }
        }
        if (!found)
            i = 0xff;
        DAT_a802cc1c[6](i);
    }
    r = FUN_a013cd4c(port);
    x = (unsigned int)((r->u.b.h10 - r->u.b.h14) * r->u.b.h0e) >> 1;
    big = 0;
    if (x > 0x1fff)
        big = 1;
    FUN_a00f8918(port);
    r = FUN_a013cd4c(port);
    if (r->u.b.h12 != r->u.b.h16 || r->u.b.h14 != r->u.b.h18) {
        if (big) {
            if (r->u.b.h1c <= r->u.b.h20)
                FUN_a00f88e8(port, r->u.b.h20 - r->u.b.h1c);
            else
                FUN_a00f88e8(port, r->u.b.h20);
        }
        FUN_a00f8ef4(port);
    } else {
        if (FUN_a0121d4c(port) == 1)
            FUN_a00f8918(port);
        else if (big)
            FUN_a00f88e8(port, 0);
    }
    w = rec->u.b.h16;
    h = rec->u.b.h18;
    if (port == 0 && FUN_a00f8f34(0) == 1)
        fix0(&w, &h);
    FUN_a00f8938(port, w, h);
    if (rec->u.b.b3e == 1 && FUN_a013cecc(rec->u.b.h00_lo))
        FUN_a00f896c(port, rec->u.b.h0e, rec->u.b.h12, rec->u.b.h14);
    else
        FUN_a00f8a98(port, rec->u.b.h0e, rec->u.b.h12, rec->u.b.h14);
    FUN_a00f8cc4(port, rec->u.b.h0e);
    if ((DAT_a802e3d0 & 0x2000000) && rec->w70.f.b31 && FUN_a0121258(port) == 1) {
        FUN_a0114420(w, h);
        FUN_a0105e60(w, h, rec->u.b.h08);
        FUN_a010a824(port);
        func_0x4008d1a0(0x32);
        FUN_a0105d20();
    } else {
        FUN_a010a83c(port);
    }
    if (FUN_a00f8f34(port))
        FUN_a00f8e0c(port, rec->u.b.h1e - rec->u.b.h1a);
    else
        FUN_a00f8e0c(port, rec->u.b.h1e);
    FUN_a00f8e44(port, rec->u.b.h20);
    if (rec->w70.w & 0x40000000)
        FUN_a0142518(port, w, h);
    FUN_a013c040(port, w, h);
    if (rec->u.b.b3e != 0 && port > 3)
        x = rec->u.b.h16 >> 1;
    else
        x = rec->u.b.h16;
    FUN_a00f8ce4(port, x, h, 0);
    FUN_a0121e3c(port);
    return 1;
}
