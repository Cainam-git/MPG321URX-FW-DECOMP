/* FUN_a007d054 (leon2s 0xa007d054-0xa007d140, 236 bytes), flags -mcpu=v8 -Os -g.
 * p (u8). Returns 0 when byte +7 of the 0x18-byte record ARR_a807cc64[p] is 1. When FUN_a007517c(p) is not 0:
 * returns 1 for p == 2, else FUN_a007cfec(p) (u8). Otherwise returns DAT_a8076198[p] when DAT_a8078980[p] is 1;
 * else the FUN_a007af04 test written in place: FUN_a0073520(p) != 0 gives FUN_a00a7408(8, word +0xc of the
 * 0x34-byte record ARR_a807db00[p != 2] + 0x60) != 0, and otherwise FUN_a00a657c(p, 0x2e1) & 1.
 * Source form: early returns with an unsigned int result; FUN_a007cfec declared returning unsigned char (the
 * firmware masks its result); the record index is a separate local 'i = p != 2' as in FUN_a007af04.
 */
struct sel_rec {
    unsigned char b[7];
    unsigned char b7;
    unsigned char _8[0x18 - 8];
};
struct Port34 { unsigned char pad[0xc]; unsigned int base; unsigned char rest[0x34 - 0x10]; };
extern struct sel_rec ARR_a807cc64[];
extern struct Port34 ARR_a807db00[];
extern unsigned char DAT_a8078980[];
extern unsigned char DAT_a8076198[];
extern unsigned char FUN_a007517c(unsigned int);
extern unsigned char FUN_a007cfec(unsigned char);
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

unsigned int FUN_a007d054(unsigned char p)
{
    if (ARR_a807cc64[p].b7 == 1)
        return 0;
    if (FUN_a007517c(p)) {
        if (p == 2)
            return 1;
        return FUN_a007cfec(p);
    }
    if (DAT_a8078980[p] == 1)
        return DAT_a8076198[p];
    if (FUN_a0073520(p) != 0) {
        unsigned int i = p != 2;
        return FUN_a00a7408(8, ARR_a807db00[i].base + 0x60) != 0;
    }
    return FUN_a00a657c(p, 0x2e1) & 1;
}
