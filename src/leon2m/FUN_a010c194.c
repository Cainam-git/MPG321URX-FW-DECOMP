/* leon2m FUN_a010c194 @ 0xa010c194  channel format set. BYTE-EXACT at -mcpu=v8 -O3 -g.
 *
 * FUN_a010c194(ch, fmt, val): stores val and fmt in bytes +0x26 / +0x25 of the channel record (ch 1: 0xA802D7C4,
 * ch 2: 0xA802D784, otherwise 0xA802D744) and sets its bits-per-pixel byte (+0x24): fmt 0 -> 8, fmt 1..6 -> 16,
 * other formats -> 32. It builds the layer format word from word +0x10 of the layer table entry (bits 8..23 replaced
 * by val << 16 and the format code: 0x100, 0x2100 .. 0xA100 in steps of 0x2000 for fmt 1..6, 0x1200 for 8, 0xA00 for
 * 9, 0x200 otherwise; bit 0 set) and writes it to word +0x10 of the entries in both layer tables 0x19AED8 and
 * 0x19AECC: entry ch, or entries 0..2 when ch > 2. Inlined by FUN_a01107b8. The record and callee declarations are
 * shared with that caller's source.
 */
struct Ctx {
    unsigned int w0;             /* +0x00 base address */
    unsigned char pad4[8];
    unsigned short wc, we;       /* +0x0c, +0x0e */
    unsigned char pad10[4];
    unsigned short x, w;         /* +0x14, +0x16 */
    unsigned int w18:16, w1a:16;     /* +0x18, +0x1a */
    unsigned char pad1c[4];
    union { struct { unsigned short w20, w22; } h; struct { unsigned int w20:16, w22:16; } b; } u20; /* +0x20, +0x22 */
    unsigned char bpp, b25, b26; /* +0x24.. */
    unsigned char pad27[0x17];
    unsigned char b3e, pad3f;    /* +0x3e */
};
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct PanelParam *DAT_a802d6a4;
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *DAT_0019aed8[], *DAT_0019aecc[];
extern unsigned char DAT_a802d700, DAT_a8027a88;
extern void FUN_a010baf4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void FUN_a010bee4(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short func_0x4008d588(void);
#define R(a) (*(volatile unsigned int *)(a))

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

void FUN_a010c194(unsigned char ch, unsigned int fmt, unsigned int val)
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
    v = (DAT_0019aed8[k][4] & 0xff0000ff) | ((unsigned char)val << 16);
    switch ((unsigned char)fmt) {
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

