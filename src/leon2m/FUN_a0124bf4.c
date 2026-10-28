/* leon2m FUN_a0124bf4 @ 0xa0124bf4-0xa0124d24 (76 words), flags -mcpu=v8 -O3 -g.
 * Returns 1 for n = 0xfc..0xfe and 0 for n == 0xff or n > 7. Otherwise r = ROM record DAT_001a42a8[n] (0x16
 * bytes): when r->b01 is 1, the 4 bytes at +0x12 are copied to a local structure s; if s.b != 0xff and the byte
 * DAT_a802c9f9 is 0, the result is 1 when the low byte of func_0x4008cd38(s.b, s.c) equals bit 7 of the fourth
 * byte (field d), else 0. In every other case (and when r->b01 is not 1) the result is the record test of
 * FUN_a0124d24: 0 when byte +0x0b is 0xff, else 1 when the low byte of func_0x4008cd38(+0x0b, +0x0c) equals +0x0d.
 * The result goes through 'res & 1'.
 * Source form: the copy is memcpy(&s, r->s, 4) (expanded inline, byte by byte, as the record is byte-aligned) into
 * an 8-byte structure whose second word this function does not use (frame size); the field d is read through its
 * unsigned int container (word load). The record pointer is set up as 't = DAT_001a42a8; r = t + n;' (table before
 * the index multiply); the record test after the s.b check is written with DAT_001a42a8[n] (the firmware rebuilds
 * the record address there), the other one with r.
 */
struct rec { unsigned char b00; unsigned char b01; unsigned char b02[9]; unsigned char b0b, b0c, b0d; unsigned char b0e[4];
             unsigned char s[4]; };
struct sub { unsigned char a, b, c; unsigned int d : 1, e : 7; unsigned int w; };
extern const struct rec DAT_001a42a8[];
extern unsigned char DAT_a802c9f9;
extern unsigned int func_0x4008cd38(int, int);
extern void *memcpy(void *, const void *, unsigned int);

unsigned char FUN_a0124bf4(unsigned char n)
{
    const struct rec *t;
    const struct rec *r;
    unsigned char res = 0;
    struct sub s;

    if ((unsigned char)(n + 4) <= 2)
        res = 1;
    else if (n != 0xff) {
        if (n <= 7) {
            t = DAT_001a42a8;
            r = t + n;
            if (r->b01 == 1) {
                memcpy(&s, r->s, 4);
                if (s.b != 0xff && DAT_a802c9f9 == 0)
                    res = (func_0x4008cd38(s.b, s.c) & 0xff) == s.d;
                else if (DAT_001a42a8[n].b0b != 0xff && (func_0x4008cd38(DAT_001a42a8[n].b0b, DAT_001a42a8[n].b0c) & 0xff) == DAT_001a42a8[n].b0d)
                    res = 1;
                else
                    res = 0;
            } else if (r->b0b != 0xff && (func_0x4008cd38(r->b0b, r->b0c) & 0xff) == r->b0d)
                res = 1;
            else
                res = 0;
        }
    }
    return res & 1;
}
