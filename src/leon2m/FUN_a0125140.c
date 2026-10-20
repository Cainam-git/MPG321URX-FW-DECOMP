/* leon2m FUN_a0125140 @ 0xa0125140-0xa0125198 (22 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/22 mismatches.
 * Code facts: leaf getter, n = (u8)param. n <= 7 -> byte +0 of the 0x16-byte ROM record
 * DAT_001a42a8[n] (smul 0x16, ldub); n == 0xfc -> 0x12, 0xfd -> 0x13, 0xfe -> 0x14; anything else
 * 0xff. Returns u8 (retl; and 0xff).
 * Required forms: the table is the ROM struct array DAT_001a42a8 (the a0125264
 * layout); the 0xfc..0xfe values are a switch (case tree root 0xfd, signed bg); the n >= 8 arm comes
 * first in the source, so the table read is the out-of-line block like in the fw. Aids: none.
 */
struct rec { unsigned char b00, b01; unsigned char b02[0x10]; unsigned char b12; unsigned char b13[3]; };
extern const struct rec DAT_001a42a8[];

unsigned char FUN_a0125140(unsigned char n)
{
    unsigned char r = 0xff;

    if (n >= 8) {
        switch (n) {
        case 0xfc: r = 0x12; break;
        case 0xfd: r = 0x13; break;
        case 0xfe: r = 0x14; break;
        }
    } else
        r = DAT_001a42a8[n].b00;
    return r;
}
