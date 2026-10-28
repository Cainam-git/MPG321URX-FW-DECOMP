/* leon2m FUN_a0124d24 @ 0xa0124d24-0xa0124da4 (32 words), flags -mcpu=v8 -O3 -g. Called by FUN_a0129980.
 * Returns 1 for n = 0xfc..0xfe. For n == 0xff or n > 7 it returns 0. Otherwise r = ROM record DAT_001a42a8[n]
 * (0x16 bytes, the table of FUN_a0124e44): 0 when r->b0b is 0xff, else 1 when the low byte of
 * func_0x4008cd38(r->b0b, r->b0c) equals r->b0d, else 0. The result goes through 'res & 1' (fw 'and %o4,1').
 * Source form: res initialised to 0 in its declaration, the n == 0xff and n <= 7 tests as separate nested ifs, and
 * the record test with the call as one '&&' condition with an explicit 'else res = 0;' (res is then set after
 * the call on that path and is not kept across it).
 */
struct rec { unsigned char b00[0xb]; unsigned char b0b, b0c, b0d; unsigned char b0e[8]; };
extern const struct rec DAT_001a42a8[];
extern unsigned int func_0x4008cd38(int, int);

unsigned char FUN_a0124d24(unsigned char n)
{
    const struct rec *r;
    unsigned char res = 0;

    if ((unsigned char)(n + 4) <= 2)
        res = 1;
    else if (n != 0xff) {
        if (n <= 7) {
            r = &DAT_001a42a8[n];
            if (r->b0b != 0xff && (func_0x4008cd38(r->b0b, r->b0c) & 0xff) == r->b0d)
                res = 1;
            else
                res = 0;
        }
    }
    return res & 1;
}
