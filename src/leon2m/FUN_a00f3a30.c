/* leon2m FUN_a00f3a30 @ 0xa00f3a30-0xa00f3c18 (488 bytes), flags -mcpu=v8 -O3 -g.
 * a = FUN_a00f8df0(p), b = FUN_a00f8dd4(p); six register reads FUN_a00f1ce4(p, reg): r0c, r3c, r38 (reg 0x0c,
 * 0x3c, 0x38, masked 0x7ff) and r12, r40, r3e (reg 0x12, 0x40, 0x3e, masked 0xfff). x = r0c; when r3c < a and
 * FUN_a0120c90(p) > r38: x = r38 if r38 <= r0c, else t = r3c + r38 - r0c and x = r0c + (t - a) when t > a.
 * Likewise with r12, r40, r3e, b and FUN_a00f3528() for r12. Then r12 becomes halfword s+0x2c when that is
 * above r12, or halfword s+0x2e when r12 + b is above s+0x2e + s+0x0c; FUN_a00f8e0c(p, r12), FUN_a00f8e44(p, x),
 * s+0x14 = FUN_a00f88ac(p), v = FUN_a00f88cc(p), s+0x16 = v, s+0x18 = s+0x14, s+0x1a = v (halfwords).
 * Source form: the second limit updates r12 in place (its zero-extension is then computed on every path, the
 * shifted value kept in %o0); the compute arm of each limit is the 'if' arm ('if (r38 > r0c) { ... } else');
 * the three tail stores are written in the order 0x16, 0x18, 0x1a.
 */
struct Win { unsigned char p00[0xc]; unsigned short h0c; unsigned char p0e[0x14 - 0xe];
             unsigned short h14, h16, h18, h1a; unsigned char p1c[0x2c - 0x1c]; unsigned short h2c, h2e; };
extern int FUN_a00f8df0(int);
extern unsigned int FUN_a00f8dd4(unsigned int);
extern unsigned short FUN_a00f1ce4(unsigned char blk, unsigned char reg);
extern unsigned short FUN_a0120c90(unsigned char port);
extern unsigned short FUN_a00f3528(void);
extern void FUN_a00f8e0c(unsigned char, unsigned short);
extern void FUN_a00f8e44(unsigned char blk, unsigned short v);
extern unsigned short FUN_a00f88ac(unsigned int);
extern unsigned int FUN_a00f88cc(unsigned int);

void FUN_a00f3a30(unsigned char p, struct Win *s)
{
    unsigned short a = FUN_a00f8df0(p);
    unsigned short b = FUN_a00f8dd4(p);
    unsigned short r0c = FUN_a00f1ce4(p, 0xc) & 0x7ff;
    unsigned short r12 = FUN_a00f1ce4(p, 0x12) & 0xfff;
    unsigned short r3c = FUN_a00f1ce4(p, 0x3c) & 0x7ff;
    unsigned short r40 = FUN_a00f1ce4(p, 0x40) & 0xfff;
    unsigned short r38 = FUN_a00f1ce4(p, 0x38) & 0x7ff;
    unsigned short r3e = FUN_a00f1ce4(p, 0x3e) & 0xfff;
    unsigned short x = r0c, t, v;

    if (r3c < a && FUN_a0120c90(p) > r38) {
        if (r38 > r0c) {
            t = r3c + r38 - r0c;
            if (t > a)
                x = r0c + (t - a);
        } else
            x = r38;
    }
    if (r40 < b && FUN_a00f3528() > r3e) {
        if (r3e > r12) {
            t = r40 + r3e - r12;
            if (t > b)
                r12 = r12 + (t - b);
        } else
            r12 = r3e;
    }
    if (s->h2c > r12)
        r12 = s->h2c;
    else if (r12 + b > s->h2e + s->h0c)
        r12 = s->h2e;
    FUN_a00f8e0c(p, r12);
    FUN_a00f8e44(p, x);
    s->h14 = FUN_a00f88ac(p);
    v = FUN_a00f88cc(p);
    s->h16 = v;
    s->h18 = s->h14;
    s->h1a = v;
}
