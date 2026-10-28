/* leon2m FUN_a0124e44 @ 0xa0124e44-0xa0124ea4 (24 words), flags -mcpu=v8 -O3 -g.
 * Code facts: r = ROM record DAT_001a42a8[n] (0x16 bytes, as in FUN_a0124da4); returns 1 unless n <= 7 and
 * r->b0e != 0xff, in which case it returns 1 when the low byte of func_0x4008cd38(r->b0e, r->b0f) equals
 * r->b10, else 0 (scc, then 'and 1').
 * The ROM routine's result is an unsigned int masked with 0xff before the compare (fw 'and 0xff' ahead of the
 * xor). Compiler aids: none.
 */
struct rec { unsigned char b00[0xe]; unsigned char b0e, b0f, b10; unsigned char b11[5]; };
extern const struct rec DAT_001a42a8[];
extern unsigned int func_0x4008cd38(int, int);

unsigned char FUN_a0124e44(unsigned char n)
{
    const struct rec *r = &DAT_001a42a8[n];
    unsigned char res = 1;
    unsigned int c;

    if (n <= 7 && r->b0e != 0xff) {
        c = func_0x4008cd38(r->b0e, r->b0f);
        res = (c & 0xff) == r->b10;
    }
    return res & 1;
}
