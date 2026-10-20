/* leon2m FUN_a010bdcc  BYTE-EXACT (hand, -mcpu=v8 -O3 -g). Channel window position set; gcc inlines it into
 * FUN_a01107b8 (set_pos there).
 * void(u8 ch, u8 which, u16 pos, u16 w20). Picks the window record for ch (1: 0xA802D7C4, 2: 0xA802D784, else
 * 0xA802D744). which == 0: record +0x18 = pos, v = pos. Otherwise: record +0x1A = pos, v = pos - DAT_a802d700 when
 * bit 0 of +0x3E is set, else pos + DAT_a802d700. Then record +0x20 = w20 and word 5 of the layer table entry
 * DAT_0019aed8[ch] (which == 0) or DAT_0019aecc[ch] (otherwise) = v << 16 | w20.
 * struct Ctx is declared as in FUN_a01107b8 (+0x18 bitfields, +0x20 union with an unsigned int view).
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

void FUN_a010bdcc(unsigned char ch, unsigned char which, unsigned short pos, unsigned short w20)
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
    if (which == 0) DAT_0019aed8[ch][5] = v; else DAT_0019aecc[ch][5] = v;
}

