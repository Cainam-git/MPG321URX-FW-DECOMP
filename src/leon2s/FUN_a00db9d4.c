/* FUN_a00db9d4 (leon2s 0xa00db9d4-0xa00dba70, 156 bytes), flags -mcpu=v8 -Os -g.
 * Clears the first 0x13 bytes of a stack message m with the ROM memset func_0xa0fc15ac, sets header bits
 * 28..31 = 1 and 24..27 = 7 of word 0, and in word 4 sets bit 23, clears bit 22, writes 0x14 to bits 16..21,
 * sets bits 15 and 14 and clears bit 12; then passes m to FUN_a00d6a54(&m, 1, 1). The trailing nop after the
 * final call is the -g epilogue.
 * Source forms: big-endian bit-fields (first field = most significant bit) in a union with the byte view;
 * the word 0 fields are written before the word 4 fields; the memset returns void *.
 */
union Msg {
    struct {
        unsigned int hi : 4, cnt : 4, rest : 24;
        unsigned int w1, w2, w3;
        unsigned int a : 8, b23 : 1, b22 : 1, f16 : 6, b15 : 1, b14 : 1, b13 : 1, b12 : 1, low : 12;
    } h;
    unsigned char b[0x18];
};
extern void *func_0xa0fc15ac(void *, int, unsigned int);
extern void FUN_a00d6a54(union Msg *, int, int);

void FUN_a00db9d4(void)
{
    union Msg m;

    func_0xa0fc15ac(&m, 0, 0x13);
    m.h.hi = 1;
    m.h.cnt = 7;
    m.h.b23 = 1;
    m.h.b22 = 0;
    m.h.f16 = 0x14;
    m.h.b15 = 1;
    m.h.b14 = 1;
    m.h.b12 = 0;
    FUN_a00d6a54(&m, 1, 1);
}
