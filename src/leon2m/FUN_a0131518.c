/* leon2m FUN_a0131518 @ 0xa0131518..0xa0132768  GlobalModeHandler (1172 words)
 * What it does (code facts from the asm; names are interpretation):
 *  - 4 port records DAT_a802df30[p] (0x78 bytes): w0 bit fields state (31..28), prev (27..24), mode (23..20),
 *    src (15..12), on (bit 0); +0x08/+0x12/+0x14 u16, +0x54 u16, +0x60 u64 clock, +0x70 flag word.
 *  - per port: link check (FUN_a01241fc row type 2), state-entry handlers (A: FUN_a01516b0, B: FUN_a0151674,
 *    C: FUN_a0151818, 5: FUN_a01518c8 ...), state-9 timer via the ms tick (func_0x4008d588/594), FRC checks on port
 *    0
 *    ("FRC Back Check" against the window DAT_a802e378 +0x10/+0x18), then prev = state.
 *  - then the 7 entries of DAT_a802e116 (bit 0x800 = FUN_a0129a10(i)), then the "main source" selection
 *    DAT_a802a44c / DAT_a802a44d with FUN_a00fd594 / FUN_a00fd9a0.
 * Inputs: none; globals only. Caller: FUN_a0153018.
 * FLAGS -mcpu=v8 -O3 -g -msoft-float (only this gives the firmware's single .LLC constant 0x0fffffff). Compiles
 * -Wall clean.
 * Code facts (asm addresses): each per-port section uses its own fresh pointer &D[p] (port_step s, state-9
 *   section t a01315b4, 0x70/q-loop section u a0131644, FRC tail s a0131684) besides the loop pointer r;
 *   other_above/none_above test 'p == q' (a0131e4c), the q-loop 'q == p' (a01321b8); q-loop 'state > 5U' (bleu
 *   a0132728); src check 'if (a != b || c != d) {state 6, mode 0} else {...}' (one RMW a0131d7c); FUN_a01312d4
 *   called
 *   as 'if (c) f(p, 1); else f(p, 0);'; pick: f5 re-load (a0132598) = 'if (a44d != v && a44c != 0xff) m = 3; else';
 *   'out' block stores w70 first in source (fw: st w, then st w70 in the b delay slot, a0131a44).
 *   Address operand order: fw '[off + base]' everywhere (a0131538, a01315d8, a01315fc, a0131688/90, a0131d30,
 *   other_above loops a0131e78...) = accesses through a pointer '= &D[x]' (ADDR_EXPR expands offset-first; D[x].f is
 *   base-first): first loop r = &D[i], src-check block v0 = &D[p], u before x, s->on in the p != 0 arm,
 *   e = &D[q] in other_above/none_above.
 * Behaviour-neutral constructs / compiler aids (no code emitted):
 *  - no 'do continue; while (0);' hint in the p != 0 arm (with the source forms below such a hint moves the
 *    'w70 &= ~0x80000' arm away from fw a0131df8).
 *  - identical-arm diamonds 'if (s->on) { s->mode = 0; s->on = 0; } else s->on = 0;' (and the on = 1 twin):
 *    fw single RMW store with the and/or in the annulled slot (a01326bc..a01326e4, a0131a50..a0131a78).
 *  - 'unsigned short th = DAT_001a30da;' read once for the print and the compare: DAT_001a30da is ROM (0x001a30da),
 *    fw keeps it in %l3 across the printf (a0132620 / a013268c).
 *  - pick() writes sel through a 'volatile unsigned char *' (reproduces the [fp-9] slot, frame -120).
 * Further source forms (no behaviour change):
 *  - link check arms in this order: 'if ((*FUN_a01241fc() & 0x700000) != 0x200000) {print arm} else {...}'
 *    (rnreg gives the print arm a0131888 the fresher registers = it comes first in source).
 *  - port_step re-checks are separate ifs, not nested: 'if (st == A) f(p); if (st == A && !other_above()) g();'
 *    (fw keeps the 0xa0000000 constant in %l0 across the call a0131768/a0131fb8; nesting lets cse2 swap in the
 *    and-result instead).
 *  - FUN_a013f1e4 / FUN_a013f204 are declared returning unsigned char here (fw cmp %o1,%o3 a0131d68 with the
 *    f1e4 result first; both callees return a 0/1 bit, so their own code does not show the type).
 *  - 7-entry loop: 'int k = i;' and FUN_a0129a10 declared (unsigned char) at this site: the test call and
 *    FUN_a0142360 get a re-zero-extended copy (fw 'and %l0,0xff,%l2' a0131af4); other calls take i.
 *  - FRC tail: 'out = 0;' before 's = &D[p];' (fw add in the be delay slot a0131684).
 *  - pick(): 'if (v == 0xff) return 0;' inside pick (fw clr %o2 in the be delay slot a0131bc4), 'type != 5' tested
 *    first with 'm = (DAT_a802a44c != 0xff) ? 3 : 0;' (fw addx/and -3/add 3 a01321f4), '*psel = 0;' after
 *    'm = DAT_a802a44c != 0;' (fw stb a44d, then clrb [fp-9] a01325c4).
 *  - the q-loop is an inlined helper claim(p, u) whose 'if (q < p) return;' replaces 'goto skip;' (fw bcs,a
 *    a0132704 annulled with the target insn = predicted taken; a goto is predicted not taken).
 *  - mode == 0 block: 'if (DAT_a802a44c != 0xff) if (FUN_a00fd820(...) != 0xb1) {...}'.
 */
struct PortF { unsigned int state:4, prev:4, mode:4, b16:4, src:4, b1:11, on:1; };
struct Port {
    union { unsigned int w; struct PortF f; } u;                        /* +0x00 */
    unsigned int w04;
    unsigned short h08;
    unsigned char p0a[0x12 - 0x0a];
    unsigned short h12, h14;
    unsigned char p16[0x54 - 0x16];
    unsigned short h54;
    unsigned char p56[0x60 - 0x56];
    unsigned long long clk;                                               /* +0x60 */
    unsigned char p68[0x70 - 0x68];
    unsigned int w70;                                                     /* +0x70 */
    unsigned int w74;
};
struct Glob {                       /* 0xA802E3D0 */
    union { unsigned int w; unsigned char b[4]; } u0;
    unsigned int w4;
    unsigned char p08[0x2e - 0x08];
    unsigned char b2e, b2f;
    unsigned char p30[0x34 - 0x30];
    unsigned char b34, p35;
    unsigned short h36;
};
struct Win { unsigned char p00[0x10]; unsigned long long lo, hi; };   /* 0xA802E378 */
struct SrcT { unsigned short h0; unsigned char p02[0x0a - 0x02]; unsigned char b0a; unsigned char p0b[0x2a - 0x0b]; };
struct EntF { unsigned short type:4, f11:1, f10_6:5, f5:1, f4:1, f3_0:4; };
struct Ent { union { unsigned short h0; struct EntF f; } u; unsigned char p02[0x12 - 0x02]; };

extern struct Port DAT_a802df30[4];
extern struct Glob DAT_a802e3d0;
extern struct Win DAT_a802e378;
extern struct SrcT DAT_a802e224[];
extern struct Ent DAT_a802e116[];
extern unsigned short DAT_a802cb82[];
extern unsigned char DAT_a802a44c, DAT_a802a44d;
extern unsigned char DAT_a802e1a0[];
extern unsigned short DAT_001a30da;
extern char s_001a5260[], s_001a5278[], s_001a5288[], s_001a52b8[], s_001a52e8[], s_001a5308[];

extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int *FUN_a01241fc(void);
extern unsigned char FUN_a0141a98(void);
extern unsigned char FUN_a0141ad0(void);
extern void FUN_a01412b8(int);
extern unsigned char FUN_a0124a40(void);
extern void FUN_a01249ec(void);
extern void FUN_a0151494(unsigned char);
extern void FUN_a01516b0(unsigned char);
extern void FUN_a015149c(void);
extern void FUN_a0151674(void);
extern void FUN_a0151818(unsigned char);
extern void FUN_a01517f4(void);
extern void FUN_a01518c8(unsigned char);
extern void FUN_a01519b4(void);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short);
extern unsigned char FUN_a013f1e4(unsigned int);
extern unsigned char FUN_a013f204(unsigned int);
extern unsigned char FUN_a0140098(unsigned char);
extern unsigned char FUN_a01400bc(unsigned char);
extern void FUN_a01312d4(unsigned char, unsigned char);
extern unsigned char FUN_a0142168(unsigned char);
extern unsigned char FUN_a0142360(unsigned char);
extern unsigned char FUN_a0121258(unsigned char);
extern unsigned char FUN_a0105d58(unsigned short, unsigned short, unsigned short);
extern void FUN_a0106ba8(unsigned char);
extern void FUN_a011433c(unsigned char);
extern int FUN_a0129a10(unsigned char);
extern int FUN_a01422f4(unsigned int);
extern void FUN_a0137920(unsigned char);
extern void FUN_a0137c4c(unsigned char);
extern void FUN_a012f7a8(void);
extern void FUN_a00fd594(unsigned char, unsigned char);
extern void FUN_a00fd9a0(unsigned char, unsigned char);
extern unsigned char FUN_a00fd820(unsigned char);
extern unsigned char FUN_a0104c34(unsigned char);
extern void FUN_a00fe4a4(unsigned char, unsigned char);
extern void FUN_a0137d6c(unsigned char);

#define D DAT_a802df30

/* 1 = another active port (not p) is in a state above lvl */
static unsigned char other_above(unsigned char p, unsigned int lvl)
{
    unsigned char q;
    struct Port *e;
    for (q = 0; q < 4; q++) {
        if (p == q) continue;
        if (q != 0 && DAT_a802e3d0.b2f == 0) continue;
        if (q == 3 && (DAT_a802e3d0.u0.w & 0x200000)) continue;
        e = &D[q];
        if ((e->u.w >> 28) > lvl) return 1;
    }
    return 0;
}

/* 1 = no other port is in a state above lvl */
static unsigned char none_above(unsigned char p, unsigned int lvl)
{
    unsigned char q;
    struct Port *e;
    for (q = 0; q < 4; q++) {
        if (p == q) continue;
        e = &D[q];
        if ((e->u.w >> 28) > lvl) return 0;
    }
    return 1;
}

static void port_step(unsigned char p, unsigned char prev)
{
    struct Port *s = &D[p];

    if (p == 0xff) return;
    if (prev == s->u.f.state) return;
    if (prev == 5 && (D[p].u.w & 0xf0000000) == 0x60000000) FUN_a0151494(p);
    if ((s->u.w & 0xf0000000) == 0xa0000000) FUN_a01516b0(p);
    if ((s->u.w & 0xf0000000) == 0xa0000000 && !other_above(p, 9)) FUN_a015149c();
    if ((s->u.w & 0xf0000000) == 0xb0000000 && !other_above(p, 9)) FUN_a0151674();
    if ((s->u.w & 0xf0000000) == 0xc0000000) FUN_a0151818(p);
    if ((s->u.w & 0xf0000000) == 0xc0000000 && !other_above(p, 0xb)) FUN_a01517f4();
    if ((s->u.w & 0xf0000000) == 0x50000000) FUN_a01518c8(p);
    if ((s->u.w & 0xf0000000) == 0x50000000 && none_above(p, 5)) FUN_a01519b4();
}

static unsigned int pick(unsigned char v, volatile unsigned char *psel)
{
    unsigned int m = 0;
    if (v == 0xff) return 0;
    if (DAT_a802e116[v].u.f.type != 5) {
        m = (DAT_a802a44c != 0xff) ? 3 : 0;
    } else {
        if (DAT_a802a44d != v && DAT_a802a44c != 0xff) {
            m = 3;
        } else {
            if (DAT_a802e116[v].u.f.f5) {
                DAT_a802a44d = v;
                m = DAT_a802a44c != 0;
                *psel = 0;
            }
        }
    }
    return m;
}

static void claim(unsigned char p, struct Port *u)
{
    unsigned char q;
    for (q = 0; q < 4; q++) {
        if (q == p) continue;
        if (D[q].w70 & 0x80000000) {
            if (q < p) return;
            D[q].w70 &= 0x7fffffff;
            if (D[q].u.f.state > 5U) {
                D[q].u.f.state = 6;
                D[q].u.f.mode = 0;
                FUN_a0106ba8(D[q].u.f.src);
            }
            break;
        }
    }
    u->w70 |= 0x80000000;
    FUN_a011433c(D[p].u.f.src);
}

void FUN_a0131518(void)
{
    struct Port *r, *s, *t, *u, *v0;
    unsigned char p, i, x, v, b, prev, out;
    unsigned char sel;
    unsigned int mode;

    for (i = 0; i < 4; i++) {
        r = &D[i];
        if ((r->u.w >> 28) > 8) break;
    }

    for (p = 0; p < 4; p++) {
        r = &D[p];
        if ((DAT_a802e3d0.b2e == 0 && p == 0) || DAT_a802e3d0.b2e == 1) {
            prev = r->u.f.prev;
            if ((*FUN_a01241fc() & 0x700000) != 0x200000) {
                if (prev != r->u.f.state && (D[p].u.w & 0xf0000000) == 0xa0000000) {
                    FUN_a01412b8(1);
                    FUN_a00df170(s_001a5288);
                }
            } else if (prev != r->u.f.state && (D[p].u.w & 0xf0000000) == 0xa0000000 && !FUN_a0141a98()) FUN_a01412b8(1);
            if ((r->u.w & 0xf0000000) == 0xb0000000 && FUN_a0141ad0()) r->u.f.state = 9;
            if (FUN_a0141a98() == 1) r->w70 |= 0x4000000; else r->w70 &= ~0x4000000;
            if (prev != r->u.f.state && (r->u.w & 0xf0000000) == 0xc0000000 && FUN_a0141a98() == 1 && !FUN_a0124a40()) FUN_a01249ec();
        } else {
            r->w70 |= 0x4000000;
        }
        if ((DAT_a802e3d0.b2f == 0 && p == 0) || DAT_a802e3d0.b2f == 1)
            port_step(p, r->u.f.prev);

        t = &D[p];
        if (r->u.f.prev != t->u.f.state) {
            if ((t->u.w & 0xf0000000) == 0x90000000) {
                if (((DAT_a802e3d0.b34 >> (p + 4)) & 1) && (DAT_a802e3d0.b34 & 0xf)) {
                    DAT_a802cb82[p] = func_0x4008d588();
                    t->w70 &= ~0x8000000;
                    FUN_a00df170(s_001a5278);
                } else {
                    t->w70 |= 0x8000000;
                }
            }
        } else if ((t->u.w & 0xf0000000) == 0x90000000 && DAT_a802e3d0.b34 != 0 && func_0x4008d594(DAT_a802cb82[p]) > DAT_a802e3d0.h36) {
            if ((DAT_a802e3d0.b34 & 0xf) == 1) DAT_a802e3d0.b34 &= ~(1 << (p + 4));
            t->w70 |= 0x8000000;
        }

        v0 = &D[p];
        if ((v0->u.w & 0xf0000000) == 0x90000000) {
            if (FUN_a013f1e4(v0->u.f.src) != FUN_a0140098(v0->u.f.src)
                || FUN_a013f204(v0->u.f.src) != FUN_a01400bc(v0->u.f.src)) {
                v0->u.f.state = 6;
                v0->u.f.mode = 0;
            } else {
                if (FUN_a0140098(v0->u.f.src) || FUN_a01400bc(v0->u.f.src) || (DAT_a802e224[v0->u.f.src].h0 & 0x10)) FUN_a01312d4(p, 1); else FUN_a01312d4(p, 0);
            }
        }

        prev = r->u.f.prev;
        u = &D[p];
        x = FUN_a0142360(FUN_a0142168(DAT_a802e224[u->u.f.src].b0a));
        if (prev != u->u.f.state && (u->u.w & 0xf0000000) == 0x70000000 && (u->u.w & 0xf00000) == 0x000000 && FUN_a0121258(u->u.f.src) == 1 && x == 0
            && FUN_a0105d58(u->h12, u->h14, u->h08) == 1 && p != 2) if (p != 3) claim(p, u);
        prev = r->u.f.prev;
        out = 0;
        s = &D[p];
        if (p != 0) {
            s->u.f.on = 0;
        } else {
            if (prev != s->u.f.state && (s->u.w & 0xf0000000) == 0x80000000) s->w70 &= ~0x80000;
            if (DAT_a802e224[s->u.f.src].h0 & 0x80) {
                s->u.f.on = 0;
            } else if ((s->u.w & 0xf0000000) == 0x80000000 && !(s->w70 & 0x80000)) {
                if ((s->u.w & 0xf00000) == 0x100000) {
                    unsigned short th = DAT_001a30da;
                    FUN_a00df170(s_001a52e8, 0, DAT_a802e1a0[7], s->h54, th, DAT_a802e3d0.w4 >> 28,
                                 DAT_a802e3d0.u0.b[3], (DAT_a802e3d0.u0.w >> 27) & 1);
                    if ((DAT_a802e1a0[7] == 0 || DAT_a802e1a0[7] == 2) && s->h54 >= th
                        && !(DAT_a802e3d0.w4 & 0xf0000000) && !(DAT_a802e3d0.u0.w & 0x80000ff)) {
                        FUN_a00df170(s_001a5260);
                        if (!s->u.f.on) { s->u.f.mode = 0; s->u.f.on = 1; } else s->u.f.on = 1;
                    } else {
                        FUN_a00df170(s_001a5308);
                        if (s->u.f.on) { s->u.f.mode = 0; s->u.f.on = 0; } else s->u.f.on = 0;
                    }
                } else if ((s->u.w & 0xf00000) == 0x500000 && s->u.f.on) {
                    if (s->clk < DAT_a802e378.lo || s->clk > DAT_a802e378.hi) {
                        FUN_a00df170(s_001a52b8, s->clk, DAT_a802e378.lo, DAT_a802e378.hi);
                        out = 1;
                    }
                    if (out) {
                        s->w70 |= 0x80000;
                        s->u.f.on = 0;
                        s->u.f.mode = 0;
                    }
                }
            }
        }
        r->u.f.prev = r->u.f.state;
    }
    for (i = 0; i < 7; i++) {
        struct Ent *e = &DAT_a802e116[i];
        int k = i;
        if (e->u.f.f11 && !(unsigned char)FUN_a0129a10(k)) {
            if ((unsigned char)FUN_a01422f4(i) == 1) FUN_a0137920(i);
            if (FUN_a0142360(k)) FUN_a0137c4c(i);
        }
        e->u.f.f11 = FUN_a0129a10(i);
    }

    FUN_a012f7a8();
    sel = 0xff;
    mode = 0;
    v = FUN_a0142168(DAT_a802e224[DAT_a802df30[0].u.f.src].b0a);
    mode = pick(v, &sel);
    if (mode == 2 || mode == 3) {
        FUN_a00fd594(DAT_a802a44c, DAT_a802e224[DAT_a802df30[DAT_a802a44c].u.f.src].b0a);
        FUN_a00fd9a0(DAT_a802a44c, DAT_a802e224[DAT_a802df30[DAT_a802a44c].u.f.src].b0a);
        DAT_a802a44c = 0xff;
        for (i = 1; i < 4; i++) {
            if (FUN_a00fd820(DAT_a802df30[i].u.f.src) == 0xb1) {
                if (!FUN_a0104c34(DAT_a802df30[i].u.f.src)) FUN_a0106ba8(DAT_a802df30[i].u.f.src);
                FUN_a00fd594(DAT_a802df30[i].u.f.src, DAT_a802e224[DAT_a802df30[i].u.f.src].b0a);
                FUN_a00fd9a0(DAT_a802df30[i].u.f.src, DAT_a802e224[DAT_a802df30[i].u.f.src].b0a);
            }
        }
    }
    if (mode == 1 || mode == 2) {
        b = DAT_a802e224[DAT_a802df30[sel].u.f.src].b0a;
        FUN_a00fe4a4(sel, b);
        FUN_a00fd594(sel, 0xb1);
        FUN_a00fd9a0(sel, 0xb1);
        FUN_a0137d6c(b);
        DAT_a802a44c = sel;
    }
    if (mode == 0) {
        if (DAT_a802a44c != 0xff) if (FUN_a00fd820(DAT_a802a44c) != 0xb1) {
            FUN_a00fd594(DAT_a802a44c, 0xb1);
            FUN_a00fd9a0(DAT_a802a44c, 0xb1);
        }
    }
    if (DAT_a802a44c != 0xff) {
        for (i = 1; i < 4; i++) {
            if (FUN_a00fd820(DAT_a802df30[i].u.f.src) != 0xb1 && FUN_a00fd820(DAT_a802df30[0].u.f.src) == 0xb1
                && FUN_a00fd820(DAT_a802df30[i].u.f.src) == DAT_a802e224[DAT_a802df30[DAT_a802a44c].u.f.src].b0a) {
                FUN_a00fd594(DAT_a802df30[i].u.f.src, 0xb1);
                FUN_a00fd9a0(DAT_a802df30[i].u.f.src, 0xb1);
            }
        }
    }
}
