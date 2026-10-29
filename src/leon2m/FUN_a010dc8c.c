/* leon2m FUN_a010dc8c @ 0xa010dc8c-0xa010de54 (456 bytes), flags -mcpu=v8 -O3 -g.
 * q = record 0xa802d804 for ch 1, else 0xa802d704 (b24 = bits per pixel). x = (addr & 31) / (b24 / 8). which 0:
 * q->w4 = addr >> 5, q->h10 = a; otherwise q->w8 = addr >> 5, q->h12 = a. q->h0e = b. Into the block whose pointer
 * is DAT_0019aec4[ch] (which 0) or DAT_0019aebc[ch] (otherwise): word 1 = q->h0c << 16, word 6 = x, word 8 = a.
 * ppw = 32 / (b24 / 8); n = q->h0c rounded up to a multiple of ppw; size = b * n * b24 >> 7. Then the register
 * 0xd0032280 / 0xd003a280 (ch 0) or 0xd0032284 / 0xd003a284 (other ch; 0xd0032... for which 0, 0xd003a... otherwise)
 * gets q->w4 (which 0) or q->w8, and 0xd00320e8 / 0xd003a0e8 or 0xd00320ec / 0xd003a0ec gets size.
 * Source form: each table store is its own 'if (which == 0) ... else ...' (as in FUN_a010baf4); q->h0c is read
 * where it is used; the round-up test is 'h0c % ppw != 0' (a compare with zero carries no equality prediction).
 */
#define R(a) (*(volatile unsigned int *)(a))
struct Rec { unsigned int w0, w4, w8; unsigned short h0c, h0e, h10, h12; unsigned char p14[0x10]; unsigned char b24; };
extern struct Rec DAT_a802d704, DAT_a802d804;
extern volatile unsigned int *DAT_0019aec4[], *DAT_0019aebc[];

static struct Rec *ctx(unsigned char ch)
{
    if (ch != 1) return &DAT_a802d704;
    return &DAT_a802d804;
}

void FUN_a010dc8c(unsigned char ch, unsigned char which, unsigned short a, unsigned short b, unsigned int addr)
{
    struct Rec *q;
    unsigned int x, ppw, n, size, v;

    q = ctx(ch);
    x = (addr & 0x1f) / (q->b24 >> 3);
    if (which == 0) {
        q->w4 = addr >> 5;
        q->h10 = a;
    } else {
        q->w8 = addr >> 5;
        q->h12 = a;
    }
    q->h0e = b;
    v = q->h0c << 16;
    if (which == 0) DAT_0019aec4[ch][1] = v; else DAT_0019aebc[ch][1] = v;
    if (which == 0) DAT_0019aec4[ch][6] = x; else DAT_0019aebc[ch][6] = x;
    v = a;
    if (which == 0) DAT_0019aec4[ch][8] = v; else DAT_0019aebc[ch][8] = v;
    ppw = 32 / (q->b24 >> 3);
    n = q->h0c / ppw * ppw;
    if (q->h0c % ppw != 0)
        n = (q->h0c / ppw + 1) * ppw;
    size = b * n * q->b24 >> 7;
    if (ch == 0) {
        if (which == 0) {
            R(0xd0032280) = q->w4;
            R(0xd00320e8) = size;
        } else {
            R(0xd003a280) = q->w8;
            R(0xd003a0e8) = size;
        }
    } else {
        if (which == 0) {
            R(0xd0032284) = q->w4;
            R(0xd00320ec) = size;
        } else {
            R(0xd003a284) = q->w8;
            R(0xd003a0ec) = size;
        }
    }
}
