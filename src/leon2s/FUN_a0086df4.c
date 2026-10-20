/* FUN_a0086df4 (leon2s 0xa0086df4-0xa0086e58, 100 bytes), flags -mcpu=v8 -Os -g.
 * Builds a 2-byte buffer {lo, hi} on the stack, with bit 7 of hi set when bit 4 of byte 0 of the 6-byte record
 * port of ARR_a807cd2e is set, and passes it to FUN_a00863d4(port, 0x80, 0x100, 1, buf). Returns 1 when that
 * call returns non-zero, else 0.
 */
struct Rec6 { unsigned char b0; unsigned char _1[5]; };
extern struct Rec6 ARR_a807cd2e[];
extern unsigned char FUN_a00863d4(unsigned char, unsigned char, unsigned int, signed char, unsigned char *);

int FUN_a0086df4(unsigned char port, unsigned char hi, unsigned char lo)
{
    unsigned char buf[2];

    buf[1] = hi;
    buf[0] = lo;
    if (ARR_a807cd2e[port].b0 & 0x10)
        buf[1] = hi | 0x80;
    return FUN_a00863d4(port, 0x80, 0x100, 1, buf) != 0;
}
