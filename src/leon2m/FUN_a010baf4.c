/* leon2m FUN_a010baf4 @ 0xa010baf4-0xa010bdcc (182 words), flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010baf4(ch, which, a, b, m): q = record 0xA802D7C4 (ch 1), 0xA802D784 (ch 2), else 0xA802D744 (same
 * ctx() as FUN_a010bee4). which == 0 stores m >> 5 at q +0x04 and a at q +0x10, which != 0 at q +0x08 / +0x12;
 * b goes to q +0x0E. B = DAT_0019aed8[ch] (which == 0) or DAT_0019aecc[ch] (register block, word index):
 *   B[7] = a << 16 | b;
 *   B[8] = ((m & 0x1F) / (q->b24 >> 3)) << 16 | t, t = q->h0c rounded up to a multiple of k = 0x20 / (q->b24 >> 3);
 *   B[9] = q +0x04 (or +0x08) with bit 26 (ch 1) or bit 27 (ch 2) set;
 *   B[10] = b * t * q->b24 >> 7.
 * Then u = a * 220 / 320 + 1, limited to 0x4FF / 0x6BF / 0x9FF for ch 1 / 2 / 0, is written as u << 16 to
 * 0xD0030094 / 0xD0030098 / 0xD0030090 (which == 0) or 0xD0038094 / 0xD0038098 / 0xD0038090. Called by FUN_a01107b8.
 * Source form: every block-word store selects the table in its own if/else (both arms store, GCC merges the
 *   common load/store tail); the stored values are computed before the which test; 'd <<= 16' is done before t
 *   is computed; which is a byte parameter; a * 220 is unsigned.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct Ctx { unsigned int w0, w4, w8; unsigned short h0c, h0e, h10, h12, h14, h16, h18, h1a, h1c, h1e;
             unsigned short h20, h22; unsigned char b24; };
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

void FUN_a010baf4(unsigned char ch, unsigned char which, unsigned short a, unsigned short b, unsigned int m)
{
    struct Ctx *q;
    unsigned int d, k, t, y, u, v;

    q = ctx(ch);
    d = (m & 0x1f) / (q->b24 >> 3);
    if (which == 0) {
        q->w4 = m >> 5;
        q->h10 = a;
    } else {
        q->w8 = m >> 5;
        q->h12 = a;
    }
    q->h0e = b;
    v = a << 16 | b;
    if (which == 0) DAT_0019aed8[ch][7] = v; else DAT_0019aecc[ch][7] = v;
    k = 0x20 / (q->b24 >> 3);
    d <<= 16;
    t = q->h0c / k * k;
    if (q->h0c != t)
        t = (q->h0c / k + 1) * k;
    v = d | t;
    if (which == 0) {
        DAT_0019aed8[ch][8] = v;
        y = q->w4;
    } else {
        DAT_0019aecc[ch][8] = v;
        y = q->w8;
    }
    if (ch == 1)
        y |= 0x4000000;
    else if (ch == 2)
        y |= 0x8000000;
    if (which == 0) DAT_0019aed8[ch][9] = y; else DAT_0019aecc[ch][9] = y;
    v = b * t * q->b24 >> 7;
    if (which == 0) DAT_0019aed8[ch][10] = v; else DAT_0019aecc[ch][10] = v;
    u = (unsigned int)a * 220 / 320 + 1;
    switch (ch) {
    case 1:
        if (u > 0x4ff)
            u = 0x4ff;
        if (which == 0)
            R(0xd0030094) = u << 16;
        else
            R(0xd0038094) = u << 16;
        break;
    case 2:
        if (u > 0x6bf)
            u = 0x6bf;
        if (which == 0)
            R(0xd0030098) = u << 16;
        else
            R(0xd0038098) = u << 16;
        break;
    case 0:
        if (u > 0x9ff)
            u = 0x9ff;
        if (which == 0)
            R(0xd0030090) = u << 16;
        else
            R(0xd0038090) = u << 16;
        break;
    }
}
