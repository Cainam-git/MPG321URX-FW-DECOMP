/* leon2m FUN_a01107b8 @ 0xa01107b8-0xa0110d64 (1452 bytes)  BYTE-EXACT at -mcpu=v8 -O3 -g
 * (jf 100 match=True, rawcmp 0 of 363 words, no compiler aids). Hand, from earlier drafts.
 *
 * What it does (panel-row reader): void(u8 ch). Picks the window record for ch (1: 0xA802D7C4, 2: 0xA802D784,
 * else 0xA802D744; idx 1/2/0); returns if its width (+0x16) is 0. Splits the window at the column
 * half = row->h08 >> 1 (row = *DAT_a802d6a4, the transformed panel row, re-read 3 times) into part 1 / part 2,
 * sets the per-ch enable bits in 0xD0030004 (window fully right of the split) or 0xD0038004 (fully left), scales
 * +0x0C by each part's share of the width, programs the two table blocks at 0x19AED8 / 0x19AECC (+0x10, +0x14),
 * mirrors positions when +0x3E bit 0 is set, calls FUN_a010baf4 / FUN_a010bee4 per part, and when
 * DAT_a8027a88 == 1 writes the update mask to 0xD003B000 and waits up to 100 ticks (func_0x4008d588) for it
 * to clear.
 * Helpers are the firmware's own functions, inlined by gcc: set_fmt = FUN_a010c194, set_pos = FUN_a010bdcc,
 *   upd = FUN_a011023c. set_pos and upd bodies here also compile byte-exact standalone. set_fmt here has
 *   u8 fmt/val; the standalone FUN_a010c194 (src/leon2m) needs u32 fmt/val + u8 casts (u32 here: 70.80; u8
 *   standalone: 73.23), so the two are separate bodies.
 * Keys (plain C, same calculations):
 *  - the split block, the 'w > first' test and the mirror block each read the record into their OWN unsigned short
 *    locals (x1/w1, w2, x3/w3), so each keeps its own zero-extension; 'w > first' is an inlined static int helper.
 *  - a2 fully defined in each arm ('a1 = c->w0; if (wider) a2 = c->w0 + k; else a2 = c->w0;'): with 'a2 = a1 = ...;
 *    a2 += k' the a2 hard reg stays in bb->global_live_at_start after post-reload copy-prop and regrename skips it.
 *  - the table bases are 'volatile unsigned int *const TAB[3]' (const pointer tables, as the sister FUN_a0110318).
 *  - record fields +0x18/+0x1a/+0x20/+0x22 are plain unsigned short (with const tables this gives the fw store order).
 *  - mirror arm computes l3 before l5.
 */
struct Ctx {
    unsigned int w0;             /* +0x00 base address */
    unsigned char pad4[8];
    unsigned short wc, we;       /* +0x0c, +0x0e */
    unsigned char pad10[4];
    unsigned short x, w;         /* +0x14, +0x16 */
    unsigned short w18, w1a;
    unsigned char pad1c[4];
    unsigned short w20, w22;
    unsigned char bpp, b25, b26; /* +0x24.. */
    unsigned char pad27[0x17];
    unsigned char b3e, pad3f;    /* +0x3e */
};
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct PanelParam *DAT_a802d6a4;
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *const DAT_0019aed8[3], *const DAT_0019aecc[3];
extern unsigned char DAT_a802d700, DAT_a8027a88;
extern void FUN_a010baf4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void FUN_a010bee4(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short func_0x4008d588(void);
#define R(a) (*(volatile unsigned int *)(a))

static unsigned int scale(unsigned short a, unsigned int b, unsigned short d)
{
    return a * b / d;
}

static int wider(unsigned short w, unsigned int first)
{
    if (w > first)
        return 1;
    return 0;
}

static struct Ctx *ctx(unsigned char ch)
{
    struct Ctx *p;
    switch (ch) {
    case 1: p = &DAT_a802d7c4; break;
    case 2: p = &DAT_a802d784; break;
    default: p = &DAT_a802d744; break;
    }
    return p;
}

static void upd(unsigned char idx)
{
    unsigned short t0;

    if (DAT_a8027a88 == 1) {
        if (idx == 8)
            R(0xd003b000) = 0x1ff;
        else if (idx == 0)
            R(0xd003b000) = 1;
        else if (idx == 1)
            R(0xd003b000) = 2;
        else if (idx == 2)
            R(0xd003b000) = 4;
        else if (idx == 3)
            R(0xd003b000) = 8;
        else if (idx == 4)
            R(0xd003b000) = 0x10;
        else if (idx == 5)
            R(0xd003b000) = 0x20;
        else if (idx == 6)
            R(0xd003b000) = 0x40;
        else if (idx == 7)
            R(0xd003b000) = 0x100;
        t0 = func_0x4008d588();
        while (R(0xd003b000) != 0 && (unsigned short)(func_0x4008d588() - t0) < 100)
            ;
    }
}

static void set_fmt(unsigned char ch, unsigned char fmt, unsigned char val)
{
    struct Ctx *q;
    unsigned int v, j;
    unsigned char k;

    q = ctx(ch);
    q->b26 = val;
    q->b25 = fmt;
    k = ch;
    if (ch > 2)
        k = 0;
    v = (DAT_0019aed8[k][4] & 0xff0000ff) | (val << 16);
    switch (fmt) {
    case 0: q->bpp = 8; break;
    case 1: q->bpp = 0x10; v |= 0x100; break;
    case 2: q->bpp = 0x10; v |= 0x2100; break;
    case 3: q->bpp = 0x10; v |= 0x4100; break;
    case 4: q->bpp = 0x10; v |= 0x6100; break;
    case 5: q->bpp = 0x10; v |= 0x8100; break;
    case 6: q->bpp = 0x10; v |= 0xa100; break;
    case 8: q->bpp = 0x20; v |= 0x1200; break;
    case 9: q->bpp = 0x20; v |= 0xa00; break;
    default: q->bpp = 0x20; v |= 0x200; break;
    }
    v |= 1;
    if (ch > 2)
        for (j = 0; j <= 2; j++)
            DAT_0019aed8[j][4] = v;
    else
        DAT_0019aed8[ch][4] = v;
    if (ch > 2)
        for (j = 0; j <= 2; j++)
            DAT_0019aecc[j][4] = v;
    else
        DAT_0019aecc[ch][4] = v;
}

static void set_pos(unsigned char ch, unsigned char which, unsigned short pos, unsigned short w20)
{
    struct Ctx *q;
    unsigned int v;

    q = ctx(ch);
    if (which == 0) { q->w18 = pos; v = pos; }
    else {
        q->w1a = pos;
        if (q->b3e & 1) v = pos - DAT_a802d700; else v = pos + DAT_a802d700;
    }
    q->w20 = w20;
    v = v << 16 | w20;
    if (which == 0) DAT_0019aed8[ch][5] = v; else DAT_0019aecc[ch][5] = v;
}

void FUN_a01107b8(unsigned char ch)
{
    struct Ctx *c;
    unsigned char idx;
    unsigned short x, w;
    int half;
    unsigned int uhalf;
    unsigned int l3, l5, first, second, h1, h2, a1, a2;

    switch (ch) {
    case 1:
        c = &DAT_a802d7c4;
        idx = 1;
        break;
    case 2:
        c = &DAT_a802d784;
        idx = 2;
        break;
    default:
        c = &DAT_a802d744;
        idx = 0;
        break;
    }
    w = c->w;
    if (c->w == 0)
        return;
    uhalf = DAT_a802d6a4->h08 >> 1;
    if (c->x >= uhalf) {
        l3 = uhalf;
        l5 = c->x - uhalf;
        switch (ch) {
        case 0: R(0xd0030004) |= 0x100; R(0xd0030004) &= ~2; break;
        case 1: R(0xd0030004) |= 0x200; R(0xd0030004) &= ~4; break;
        case 2: R(0xd0030004) |= 0x400; R(0xd0030004) &= ~8; break;
        }
    } else {
        l3 = c->x;
        l5 = 0;
        if (c->x + c->w <= (DAT_a802d6a4->h08 >> 1)) {
            switch (ch) {
            case 0: R(0xd0038004) |= 0x100; R(0xd0038004) &= ~2; break;
            case 1: R(0xd0038004) |= 0x200; R(0xd0038004) &= ~4; break;
            case 2: R(0xd0038004) |= 0x400; R(0xd0038004) &= ~8; break;
            }
        }
    }
    x = c->x;
    half = DAT_a802d6a4->h08 >> 1;
    {
        unsigned short x1 = c->x, w1 = c->w;
        if (x1 + w1 > half) {
            first = half - l3;
            second = w1 - first;
        } else {
            first = w1;
            second = 0;
        }
    }
    h1 = scale(c->wc, first, c->w);
    h2 = scale(c->wc, second, c->w);
    set_fmt(ch, 7, c->b26);
    a1 = c->w0;
    if (wider(c->w, first))
        a2 = c->w0 + (c->bpp >> 3) * h1;
    else
        a2 = c->w0;
    if (c->b3e & 1) {
        unsigned short x3 = c->x, w3 = c->w;
        if (x3 + w3 > (half = DAT_a802d6a4->h08 >> 1)) {
            if ((unsigned int)x3 < (unsigned int)half) {
                l3 = (half - first) - l3;
                l5 = (half - second) - l5;
                a1 += (c->bpp >> 3) * h2;
                a2 = c->w0;
            } else {
                l5 = (half - second) - l5;
            }
        } else {
            l3 = (half - first) - l3;
        }
    }
    FUN_a010baf4(ch, 0, h1, c->we, a1);
    FUN_a010baf4(ch, 1, h2, c->we, a2);
    set_pos(ch, 0, l3, c->w20);
    set_pos(ch, 1, l5, c->w20);
    FUN_a010bee4(ch, 0, first, c->w22);
    FUN_a010bee4(ch, 1, second, c->w22);
    upd(idx);
}
