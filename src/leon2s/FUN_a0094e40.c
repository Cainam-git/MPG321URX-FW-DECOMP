/* FUN_a0094e40 (leon2s 0xa0094e40-0xa0094f64, 292 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00a80cc(p, 4, 0, 2, m) with m = 0 for b = 1, 2 or 10 and m = 1 otherwise; FUN_a00a80cc(p, 4, 0, 1,
 * bit 15 of word +0x14 of the 0x1c-byte record ARR_a807d580[p]); for c == 1 FUN_a00a80cc(p, 0, 8, 0x10, 0) and
 * FUN_a00a8260(p, 0xa3, 0x10, 1), else FUN_a00a80cc(p, 0, 8, 0x10, 1); ends with the sibling call
 * FUN_a00a80cc(p, 0, 8, 0x20, 1).
 * Source form: bit 15 of word +0x14 is a 1-bit bit-field (srl 15 / btst 1), tested with the 0 arm first;
 * each test selects between two full calls.
 */
struct Ch1c {
    unsigned char b0, b1, b2, b3;
    unsigned int w[4];
    unsigned int : 16;
    unsigned int b15 : 1;
    unsigned int : 15;
    unsigned int w5;
};
extern struct Ch1c ARR_a807d580[];
extern void FUN_a00a80cc(unsigned int port, unsigned int sub, short reg, unsigned int mask, unsigned int mode);
extern void FUN_a00a8260(unsigned int param_1, short param_2, unsigned int param_3, unsigned int param_4);

void FUN_a0094e40(unsigned char p, unsigned char b, unsigned char c)
{
    if (b == 1 || b == 2 || b == 10)
        FUN_a00a80cc(p, 4, 0, 2, 0);
    else
        FUN_a00a80cc(p, 4, 0, 2, 1);
    if (!ARR_a807d580[p].b15)
        FUN_a00a80cc(p, 4, 0, 1, 0);
    else
        FUN_a00a80cc(p, 4, 0, 1, 1);
    if (c == 1) {
        FUN_a00a80cc(p, 0, 8, 0x10, 0);
        FUN_a00a8260(p, 0xa3, 0x10, 1);
    } else
        FUN_a00a80cc(p, 0, 8, 0x10, 1);
    FUN_a00a80cc(p, 0, 8, 0x20, 1);
}
