/* leon2m FUN_a010de54 @ 0xa010de54-0xa010e0f4 (672 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010de54(ch, which, p, w): q = record 0xA802D804 when ch == 1, else 0xA802D704 (same ctx() as
 * FUN_a010d914). which == 0 stores p at q +0x1C and compares p with q +0x10 later; which != 0 uses +0x1E and +0x12.
 * Stores w at q +0x22. Register block base B = 0xD0032000 (which == 0) or 0xD003A000; channel offsets are
 * 0x30/0x34/0x04 for ch == 0 and 0xA0/0xA4/0x08 otherwise:
 *   B+0x30|0xA0 = p << 16 | w;
 *   B+0x34|0xA4 = ((q->h0c - 1) << 16) / (q->h16 - 1);
 *   bit 2 of B+0x04|0x08 cleared when p equals the compared field, else set.
 *   Then n = q +0x22 (read back), s = ((q->h0e - 1) << 16) / (n - 1) to 0xD0032038 and 0xD003A038 (ch == 0) or
 *   0xD00320A8 and 0xD003A0A8, and bit 1 of 0xD0032004/0xD003A004 (ch == 0) or 0xD0032008/0xD003A008 cleared when
 *   q->h0e == n, else set.
 * Called by FUN_a0110318 (with which = 0 and which = 1).
 * Source form: the +0x34/+0xA4 store and the bit-2 update written in full in each of the four arms (gives the
 *   firmware's duplicated compare blocks); the second divisor and compare use 'n = q->h22' read back after the
 *   store (the firmware zero-extends w again there instead of reusing w << 16; n as a local keeps the operand order
 *   'cmp h0e, n').
 */
#define R(a) (*(volatile unsigned int *)(a))
struct OutCh { unsigned int w0; unsigned char p04[8]; unsigned short h0c, h0e, h10, h12, h14, h16, h18, h1a, h1c, h1e;
               unsigned short h20, h22; };
extern struct OutCh DAT_a802d704, DAT_a802d804;

static struct OutCh *ctx(unsigned char ch)
{
    if (ch != 1) return &DAT_a802d704;
    return &DAT_a802d804;
}

void FUN_a010de54(unsigned char ch, unsigned char which, unsigned short p, unsigned short w)
{
    struct OutCh *q;
    unsigned int old;
    unsigned int v, s, n;

    q = ctx(ch);
    if (which == 0) { q->h1c = p; old = q->h10; } else { q->h1e = p; old = q->h12; }
    q->h22 = w;
    v = p << 16 | w;
    if (ch == 0) {
        if (which == 0) R(0xd0032030) = v; else R(0xd003a030) = v;
    } else {
        if (which == 0) R(0xd00320a0) = v; else R(0xd003a0a0) = v;
    }
    s = ((q->h0c - 1) << 16) / (unsigned int)(q->h16 - 1);
    if (ch == 0) {
        if (which == 0) { R(0xd0032034) = s; if (p == old) R(0xd0032004) &= ~4; else R(0xd0032004) |= 4; }
        else { R(0xd003a034) = s; if (p == old) R(0xd003a004) &= ~4; else R(0xd003a004) |= 4; }
    } else {
        if (which == 0) { R(0xd00320a4) = s; if (p == old) R(0xd0032008) &= ~4; else R(0xd0032008) |= 4; }
        else { R(0xd003a0a4) = s; if (p == old) R(0xd003a008) &= ~4; else R(0xd003a008) |= 4; }
    }
    old = q->h0e;
    n = q->h22;
    s = ((old - 1) << 16) / (n - 1);
    if (ch == 0) {
        R(0xd0032038) = s;
        R(0xd003a038) = s;
        if (old == n) { R(0xd0032004) &= ~2; R(0xd003a004) &= ~2; }
        else { R(0xd0032004) |= 2; R(0xd003a004) |= 2; }
    } else {
        R(0xd00320a8) = s;
        R(0xd003a0a8) = s;
        if (old == n) { R(0xd0032008) &= ~2; R(0xd003a008) &= ~2; }
        else { R(0xd0032008) |= 2; R(0xd003a008) |= 2; }
    }
}
