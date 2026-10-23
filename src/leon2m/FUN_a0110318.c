/* leon2m FUN_a0110318 @ 0xa0110318-0xa01107b8 (1184 bytes, 296 words), flags -mcpu=v8 -O3 -g.
 * What it does (sister of FUN_a01107b8): void(u8 ch). Record c = ctx(ch) (0xA802D704, ch 1:
 * 0xA802D804);
 * returns if c->h16 (width) is 0; splits [x, x+w) at half = (*DAT_a802d6a4)->h08 >> 1 into first/second, sets the
 * side
 * enable bits (0xD0032000/0xD003A000 +0x270), scales h0c by each part (udiv), inlined FUN_a010d914(ch, 7, 0xff)
 * (set_fmt),
 * mirror (+0x3E bit 0), FUN_a010dc8c x2, inlined FUN_a010dbc4(ch, 0/1, pos, c->h20) (set_pos), FUN_a010de54 x2, and
 * the
 * optional 0xD003B000 wait loop.
 * Helpers are the firmware's own functions, inlined by gcc: ctx() (early-return record getter), set_fmt() =
 * FUN_a010d914 (the same body is src/leon2m/FUN_a010d914.c), set_pos() = FUN_a010dbc4.
 * Required source forms (plain C, same calculations, no compiler aids):
 *  - SET's else arm reuses the loop counter: 'unsigned int i; if (ch > 1) for (i...) ...; else { i = ch; tab[i]->f =
 *    val; }'
 *    (flips global-alloc order: table-base pseudos before the record pointer q, as in the fw).
 *  - set_fmt: 't = m << 16; v = m | t | 1;' (fw operand order 'or m, t'; needed for the standalone FUN_a010d914).
 *  - 'a2 = a1 = c->w0;' then 'a2 += ...' / 'a1 += ...' (one c->w0 load, as the sister FUN_a01107b8).
 */
#define R(a) (*(volatile unsigned int *)(a))
struct OutCh { unsigned int w0; unsigned char p04[8]; unsigned short h0c, h0e; unsigned char p10[4];
               unsigned short h14, h16, h18, h1a; unsigned char p1c[4]; unsigned short h20, h22;
               unsigned char b24, b25, b26; unsigned char p27[0x17]; unsigned char b3e; };
struct Regs { unsigned int w0, w4, w8, wc, w10, w14; };
struct PanelParam { unsigned char p00[8]; unsigned short h08; };
extern struct OutCh DAT_a802d704, DAT_a802d804;
extern unsigned char DAT_a802d700, DAT_a8027a88;
extern struct PanelParam *DAT_a802d6a4;
extern volatile struct Regs *const DAT_0019aec4[2];
extern volatile struct Regs *const DAT_0019aebc[2];
extern void FUN_a010dc8c(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void FUN_a010de54(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short func_0x4008d588(void);

#define SET(tab, f, val) do { unsigned int i; if (ch > 1) { for (i = 0; i <= 1; i++) tab[i]->f = val; } else { i = ch; tab[i]->f = val; } } while (0)

static struct OutCh *ctx(unsigned char ch)
{
    if (ch != 1) return &DAT_a802d704;
    return &DAT_a802d804;
}

static void set_fmt(unsigned char ch, unsigned char fmt, unsigned char val)
{
    struct OutCh *q;
    unsigned int m, v, t;

    q = ctx(ch);
    q->b26 = val;
    q->b25 = fmt;
    v = val;
    SET(DAT_0019aec4, w14, v);
    SET(DAT_0019aebc, w14, v);
    switch (fmt)
    {
    case 1: q->b24 = 0x10; m = 0x100; break;
    case 2: q->b24 = 0x10; m = 0x2100; break;
    case 3: q->b24 = 0x10; m = 0x4100; break;
    case 4: q->b24 = 0x10; m = 0x6100; break;
    case 5: q->b24 = 0x10; m = 0x8100; break;
    case 6: q->b24 = 0x10; m = 0xa100; break;
    case 8: q->b24 = 0x20; m = 0x1200; break;
    default: q->b24 = 0x20; m = 0x200; break;
    }
    if (ch == 0) { t = m << 16; v = m | t | 1; R(0xd0032004) = v; R(0xd003a004) = v; }
    else { t = m << 16; v = m | t | 1; R(0xd0032008) = v; R(0xd003a008) = v; }
}

static void set_pos(unsigned char ch, unsigned char which, unsigned short p, unsigned short w20)
{
    struct OutCh *q;
    unsigned int v;

    q = ctx(ch);
    if (which == 0) { q->h18 = p; v = p; }
    else
    {
        q->h1a = p;
        if (q->b3e & 1) v = p - DAT_a802d700; else v = p + DAT_a802d700;
    }
    q->h20 = w20;
    v = v << 16 | w20;
    if (which == 0) DAT_0019aec4[ch]->w0 = v; else DAT_0019aebc[ch]->w0 = v;
}

static int wider(unsigned short w, unsigned int first)
{
    if (w > first)
        return 1;
    return 0;
}

static unsigned int scale(unsigned short a, unsigned int b, unsigned short d)
{
    return a * b / d;
}

void FUN_a0110318(unsigned char ch)
{
    struct OutCh *c;
    unsigned short len, t0;
    int half;
    unsigned int l3, l5, first, second, h1, h2, a1, a2;

    c = ctx(ch);
    len = c->h16;
    if (c->h16 == 0) return;
    half = DAT_a802d6a4->h08 >> 1;
    if (c->h14 >= (unsigned int) half)
    {
        l5 = c->h14 - half;
        l3 = half;
        if (ch == 1) { R(0xd0032000) &= ~4; R(0xd0032270) |= 2; }
        else { R(0xd0032000) &= ~2; R(0xd0032270) |= 1; }
    }
    else
    {
        l3 = c->h14;
        l5 = 0;
        if (c->h14 + c->h16 <= half)
        {
            if (ch == 1) { R(0xd003a000) &= ~4; R(0xd003a270) |= 2; }
            else { R(0xd003a000) &= ~2; R(0xd003a270) |= 1; }
        }
    }
    {
        unsigned short x1 = c->h14, w1 = c->h16;
        if (x1 + w1 > (half = DAT_a802d6a4->h08 >> 1)) { first = half - l3; second = w1 - first; }
        else { first = w1; second = 0; }
    }
    h1 = scale(c->h0c, first, c->h16);
    h2 = scale(c->h0c, second, c->h16);
    set_fmt(ch, 7, 0xff);
    a2 = a1 = c->w0;
    if (wider(c->h16, first)) a2 += (c->b24 >> 3) * h1;
    if (c->b3e & 1)
    {
        unsigned short x3 = c->h14, w3 = c->h16;
        if (x3 + w3 > (half = DAT_a802d6a4->h08 >> 1))
        {
            if ((unsigned int)x3 < (unsigned int)half)
            {
                l3 = (half - first) - l3;
                l5 = (half - second) - l5;
                a1 += (c->b24 >> 3) * h2;
                a2 = c->w0;
            }
            else l5 = (half - second) - l5;
        }
        else l3 = (half - first) - l3;
    }
    FUN_a010dc8c(ch, 0, h1, c->h0e, a1);
    FUN_a010dc8c(ch, 1, h2, c->h0e, a2);
    set_pos(ch, 0, l3, c->h20);
    set_pos(ch, 1, l5, c->h20);
    FUN_a010de54(ch, 0, first, c->h22);
    FUN_a010de54(ch, 1, second, c->h22);
    if (DAT_a8027a88 == 1)
    {
        R(0xd003b000) = 0x10;
        t0 = func_0x4008d588();
        while (R(0xd003b000) != 0 && (unsigned short)(func_0x4008d588() - t0) < 100)
            ;
    }
}
