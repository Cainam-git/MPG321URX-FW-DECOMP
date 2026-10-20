/* FUN_a00d9524 (leon2s 0xa00d9524-0xa00d95e4, 192 bytes), flags -mcpu=v8 -Os -g.
 * Copies 0x13 bytes from src into a stack message m with the ROM copy func_0xa0fc15d8. When the 4-bit field
 * cnt (bits 24..27 of word 0) is not below the 4-bit field hi (bits 28..31), hi = 1 and cnt = 0; otherwise
 * cnt = (high nibble of src[0]) - (low nibble of src[0]) - 1. Then clears bits 16..21, 15, 14 and 8..11 of
 * word 4 and passes m to FUN_a00d6a54(&m, 1, 1).
 * Source forms: big-endian bit-fields in a union (first field = most significant bit); cnt and hi are copied
 * into unsigned int locals for the compare (unsigned bcs); src is read as a byte of two 4-bit bit-fields
 * (ldub, and 0xff, srl 4 / and 0xf); the hi = 1 arm is written first.
 */
union Msg {
    struct {
        unsigned int hi : 4, cnt : 4, rest : 24;
        unsigned int w1, w2, w3;
        unsigned int a : 8, b23 : 1, b22 : 1, f16 : 6, b15 : 1, b14 : 1, b13 : 1, b12 : 1, n8 : 4, low : 8;
    } h;
    unsigned char b[0x18];
};
struct nib {
    unsigned char hi : 4, lo : 4;
};
extern void *func_0xa0fc15d8(void *, const void *, unsigned int);
extern void FUN_a00d6a54(union Msg *, int, int);

void FUN_a00d9524(struct nib *src)
{
    union Msg m;
    unsigned int n, h;

    func_0xa0fc15d8(&m, src, 0x13);
    n = m.h.cnt;
    h = m.h.hi;
    if (n >= h) {
        m.h.hi = 1;
        m.h.cnt = 0;
    } else {
        m.h.cnt = src->hi - src->lo - 1;
    }
    m.h.f16 = 0;
    m.h.b15 = 0;
    m.h.b14 = 0;
    m.h.n8 = 0;
    FUN_a00d6a54(&m, 1, 1);
}
