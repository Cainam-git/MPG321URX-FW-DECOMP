/* FUN_a007b2a0 (leon2s 0xa007b2a0-0xa007b394, 244 bytes), flags -mcpu=v8 -Os -g.
 * p (u8). Returns 0 when byte +7 of the 0x18-byte record ARR_a807cc64[p] is 1. When FUN_a007517c(p) is not 0:
 * returns 0 for p == 2, else FUN_a007ae94(p) (u8). Otherwise returns DAT_a8076198[p] when DAT_a8078980[p] is 1;
 * else the FUN_a007af6c test written in place: FUN_a0073520(p) != 0 gives FUN_a00a7408(9, word +0xc of the
 * 0x34-byte record ARR_a807db00[p != 2] + 0x60) != 0, and otherwise 1 when bit 1 of FUN_a00a657c(p, 0x2e1)
 * is set, else 0. Same source form as FUN_a007d054.
 * Source form: early returns; FUN_a007ae94 declared returning unsigned char (its result is 0 or 1 and the
 * firmware masks it); the last test as if/return 1/return 0 (a '!= 0' expression changes the shared tail).
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
extern unsigned char FUN_a007ae94(unsigned char);
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

unsigned int FUN_a007b2a0(unsigned char p)
{
    if (ARR_a807cc64[p].b7 == 1)
        return 0;
    if (FUN_a007517c(p)) {
        if (p == 2)
            return 0;
        return FUN_a007ae94(p);
    }
    if (DAT_a8078980[p] == 1)
        return DAT_a8076198[p];
    if (FUN_a0073520(p) != 0) {
        unsigned int i = p != 2;
        return FUN_a00a7408(9, ARR_a807db00[i].base + 0x60) != 0;
    }
    if (FUN_a00a657c(p, 0x2e1) & 2)
        return 1;
    return 0;
}
