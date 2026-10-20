/* FUN_a00ab548 (leon2s 0xa00ab548-0xa00ab584, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Splits the byte sel into lo = sel & 0xf and hi = sel >> 4. For lo <= 4 stores b at byte 0xc + hi and a at
 * byte 4 + hi of the 16-byte record lo of DAT_a80792b4.
 */
struct Rec16 { unsigned char _0[4]; unsigned char a[8]; unsigned char b[4]; };
extern struct Rec16 DAT_a80792b4[];

void FUN_a00ab548(unsigned char sel, unsigned char a, unsigned char b)
{
    unsigned char lo = sel & 0xf;
    unsigned char hi = sel >> 4;

    if (lo <= 4) {
        DAT_a80792b4[lo].a[hi] = a;
        DAT_a80792b4[lo].b[hi] = b;
    }
}
