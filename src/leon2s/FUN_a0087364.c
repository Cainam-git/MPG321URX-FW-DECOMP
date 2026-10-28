/* FUN_a0087364 (leon2s 0xa0087364-0xa008743c, 216 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns a 4-bit code from the low nibble t of the first argument and bytes 4 and 5 of p (default 6).
 * t == 4: 5 when both bytes have all of bits 0x77 set; when neither byte has both bits 0x11 set: 9 when both
 * have one of them set, else 8. t == 2: from byte 4 only, 5 for bits 0x77; when bits 0x11 are not both set:
 * 9 when one is set, else 8. Other t: 5 when bits 0..2 of byte 4 are set; 8 when bit 0 is clear.
 * Source form: one exit returning r & 0xf; byte 4 is read into an unsigned int inside each arm of the t == 2
 * test (GCC hoists the load above that test only).
 */
unsigned char FUN_a0087364(unsigned int t, unsigned char *p)
{
    unsigned char r = 6;
    unsigned char a;
    unsigned char b;
    unsigned int d;

    t &= 0xf;
    if (t == 4) {
        a = p[4];
        if ((a & 0x77) == 0x77 && (p[5] & 0x77) == 0x77)
            r = 5;
        a &= 0x11;
        if (a != 0x11) {
            b = p[5] & 0x11;
            if (b != 0x11) {
                r = 8;
                if (a != 0)
                    if (b != 0)
                        r = 9;
            }
        }
    } else {
        if (t == 2) {
            d = p[4];
            if ((d & 0x77) == 0x77)
                r = 5;
            b = d & 0x11;
            if (b != 0x11) {
                r = 8;
                if (b != 0)
                    r = 9;
            }
        } else {
            d = p[4];
            if ((d & 7) == 7)
                r = 5;
            if (!(d & 1))
                r = 8;
        }
    }
    return r & 0xf;
}
