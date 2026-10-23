/* leon2s FUN_a00d6724 @ 0xa00d6724-0xa00d6890, -mcpu=v8 -Os -g (leaf).
 * (struct Out *o, const u8 *s), void; callers: FUN_a00da6ac, FUN_a00d9edc, FUN_a00daa98 (o = their 24-byte
 * stack buffer, s = a packed record). Clears o->n[0..15]; copies the two nibbles of s[0] into o's byte 0
 * (high nibble h first); with k = h - 1 unpacks k nibbles from s[1..] into o->n (high nibble of each byte
 * first); then, from the bytes at s[off + 1] and s[off + 2] (off = k / 2 rounded up), copies bit-fields into
 * o byte +0x11 (bit 7, bit 6, bits 0..5) and byte +0x12 (bit 7, bit 6, bit 4, bits 0..3; bit 5 kept).
 * Source form: byte-wide bit-fields copied field by field (each copy is a separate load/and/or/store).
 */
struct B0 { unsigned char hi : 4; unsigned char lo : 4; };
struct B11 { unsigned char a : 1; unsigned char b : 1; unsigned char c : 6; };
struct B12 { unsigned char a : 1; unsigned char b : 1; unsigned char x : 1; unsigned char d : 1; unsigned char e : 4; };
struct Out { struct B0 h; unsigned char n[16]; struct B11 f11; struct B12 f12; unsigned char pad[5]; };

void FUN_a00d6724(struct Out *o, unsigned char *s)
{
    unsigned char i, off;
    int k;
    struct B11 *p11;
    struct B12 *p12;

    for (i = 0; i <= 0xf; i++)
        o->n[i] = 0;
    o->h.hi = ((struct B0 *)s)->hi;
    o->h.lo = ((struct B0 *)s)->lo;
    k = o->h.hi - 1;
    off = k / 2;
    if (k & 1)
        off = k / 2 + 1;
    for (i = 0; i < o->h.hi - 1; i++) {
        if ((i & 1) == 0)
            o->n[i] = s[1 + (i >> 1)] >> 4;
        else
            o->n[i] = s[1 + (i >> 1)] & 0xf;
    }
    p11 = (struct B11 *)&s[off + 1];
    p12 = (struct B12 *)&s[off + 2];
    o->f11.a = p11->a;
    o->f11.b = p11->b;
    o->f11.c = p11->c;
    o->f12.a = p12->a;
    o->f12.b = p12->b;
    o->f12.d = p12->d;
    o->f12.e = p12->e;
}
