/* leon2m FUN_a010bee4 @ 0xa010bee4-0xa010c194 (688 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010bee4(ch, which, p, w): q = record 0xA802D7C4 (ch 1), 0xA802D784 (ch 2), else 0xA802D744 (same ctx()
 * as FUN_a010c194). which == 0 stores p at q +0x1C and compares with q +0x10; which != 0 uses +0x1E and +0x12.
 * Stores w at q +0x22. B = DAT_0019aed8[ch] (which == 0) or DAT_0019aecc[ch] (register block, word index):
 *   B[1] = (B[1] & ~0x3FF) | 0x14 if p > compared field | 0x20 if q +0x22 > q +0x0E;
 *   B[6] = p << 16 | q +0x22;  B[0x34] = ((q->h0e - 1) << 16) / (q->h22 - 1);
 *   B[0x35] = ((q->h0c - 1) << 16) / (q->h16 - 1).
 * Then the word 0xD0030008 (which == 0) or 0xD0038008 is read, bit 16 / 20 / 24 (ch 0 / 1 / 2) set when p equals
 * the compared field and q->h0e == q->h22, cleared otherwise (other ch: unchanged), and written back.
 * Called by FUN_a01107b8 (with which = 0 and which = 1). Counterpart of FUN_a010de54 for the three-record set.
 * Source form: after the store of w every use reads q +0x22 back (the firmware zero-extends w again each time);
 *   q->h0e is read in place each time; the first block word is read through a pointer chosen by which
 *   (the other writes select the table per statement); equality written 'q->h0e == q->h22'.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct Ctx { unsigned int w0; unsigned char p04[8]; unsigned short h0c, h0e, h10, h12, h14, h16, h18, h1a, h1c, h1e;
             unsigned short h20, h22; };
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *DAT_0019aed8[], *DAT_0019aecc[];

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

void FUN_a010bee4(unsigned char ch, unsigned char which, unsigned short p, unsigned short w)
{
    struct Ctx *q;
    unsigned int old;
    unsigned int t, v, s, x;
    volatile unsigned int *b;

    q = ctx(ch);
    if (which == 0) { q->h1c = p; old = q->h10; } else { q->h1e = p; old = q->h12; }
    q->h22 = w;
    if (which == 0) b = DAT_0019aed8[ch]; else b = DAT_0019aecc[ch];
    t = b[1] & ~0x3ff;
    if (p > old) t |= 0x14;
    if (q->h22 > q->h0e) t |= 0x20;
    if (which == 0) DAT_0019aed8[ch][1] = t; else DAT_0019aecc[ch][1] = t;
    v = p << 16 | q->h22;
    if (which == 0) DAT_0019aed8[ch][6] = v; else DAT_0019aecc[ch][6] = v;
    s = ((q->h0e - 1) << 16) / (unsigned int)(q->h22 - 1);
    if (which == 0) DAT_0019aed8[ch][0x34] = s; else DAT_0019aecc[ch][0x34] = s;
    s = ((q->h0c - 1) << 16) / (unsigned int)(q->h16 - 1);
    if (which == 0) { DAT_0019aed8[ch][0x35] = s; x = R(0xd0030008); }
    else { DAT_0019aecc[ch][0x35] = s; x = R(0xd0038008); }
    if (p == old && q->h0e == q->h22) {
        switch (ch) {
        case 0: x |= 0x10000; break;
        case 1: x |= 0x100000; break;
        case 2: x |= 0x1000000; break;
        }
    } else {
        switch (ch) {
        case 0: x &= ~0x10000; break;
        case 1: x &= ~0x100000; break;
        case 2: x &= ~0x1000000; break;
        }
    }
    if (which == 0) R(0xd0030008) = x; else R(0xd0038008) = x;
}
