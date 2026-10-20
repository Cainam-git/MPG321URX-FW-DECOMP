/* leon2m FUN_a010d914 @ 0xa010d914-0xa010daf8 (344 bytes, 121 insns)  BYTE-EXACT at -mcpu=v8 -O3 -g
 * (jf 100 match=True, rawcmp 0 of 121 words).
 * void FUN_a010d914(u8 ch, u8 fmt, u8 val): record q = ctx(ch); q->b26 = val; q->b25 = fmt; table words +0x14 of
 * DAT_0019aec4[] and DAT_0019aebc[] = val (both entries when ch > 1); switch(fmt) -> q->b24 (0x10/0x20) and m;
 * 0xD0032004/0xD003A004 (ch 0) or ...008 = m << 16 | m | 1. Inlined in FUN_a0110318 as set_fmt(ch, 7, 0xff).
 * Facts: the SET else arm reuses the loop counter ('i = ch; tab[i]') -> register order of fw; 't = m << 16; v = m | t | 1'
 * -> fw 'or m, t' operand order. Static helpers set_pos/wider/scale in this file are unused here. No compiler aids.
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

void FUN_a010d914(unsigned char ch, unsigned char fmt, unsigned char val)
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

