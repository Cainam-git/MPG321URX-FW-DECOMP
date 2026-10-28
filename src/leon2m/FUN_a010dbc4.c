/* leon2m FUN_a010dbc4 @ 0xa010dbc4-0xa010dc8c (200 bytes), flags -mcpu=v8 -O3 -g.
 * Context q = DAT_a802d804 for ch == 1, else DAT_a802d704. which == 0: q->w18 = pos, v = pos; otherwise
 * q->w1a = pos and v = pos - DAT_a802d700 (bit 0 of q->b3e set) or pos + DAT_a802d700. q->w20 = w20, then
 * (v << 16) | w20 goes to word 0 of the block DAT_0019aec4[ch] (which == 0) or DAT_0019aebc[ch].
 * Same form as FUN_a010bdcc (16-bit bit-fields w18/w1a, the w20 union view, the ctx() selector as an inline
 * helper); here the selector is a two-way default-then-override.
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
extern struct Ctx DAT_a802d704, DAT_a802d804;
extern volatile unsigned int *DAT_0019aec4[], *DAT_0019aebc[];
extern unsigned char DAT_a802d700, DAT_a8027a88;

static struct Ctx *ctx(unsigned char ch)
{
    struct Ctx *p = &DAT_a802d704;
    if (ch == 1)
        p = &DAT_a802d804;
    return p;
}

void FUN_a010dbc4(unsigned char ch, unsigned char which, unsigned short pos, unsigned short w20)
{
    struct Ctx *q;
    unsigned int v;

    q = ctx(ch);
    if (which == 0) { q->w18 = pos; v = pos; }
    else {
        q->w1a = pos;
        if (q->b3e & 1) v = pos - DAT_a802d700; else v = pos + DAT_a802d700;
    }
    q->u20.h.w20 = w20;
    v = v << 16 | w20;
    if (which == 0) DAT_0019aec4[ch][0] = v; else DAT_0019aebc[ch][0] = v;
}
