/* leon2m FUN_a00bae38 @ 0xa00bae38-0xa00baee8 (44 words).
 * Converts the three ASCII digits at bytes 7, 8 and 9 of a UART receive record into a number 0..199 and returns it;
 * returns 0xff when byte 7 is not '0' or '1', or byte 8 or 9 is not a decimal digit. The record is selected by the
 * port: 2 -> 0xa802d040, 3 -> 0xa802d098, any other -> 0xa802d0d0. Called by FUN_a00c1608, FUN_a00c165c,
 * FUN_a00c16b0 and FUN_a00ccf34; FUN_a00c6690 and others contain inlined copies.
 * Source forms the exact build depends on: each port arm loads the three bytes itself (the compiler merges the
 * port 2 and default arms and keeps the port 3 arm as a separate copy); the digits are range-tested as characters
 * before '0' is subtracted; the sum goes through an unsigned short local, which keeps the zero extension of the
 * last digit before the final add.
 */
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];

unsigned char FUN_a00bae38(unsigned char port)
{
    unsigned char h, t, o;
    unsigned short r;

    if (port == 2) {
        h = DAT_a802d040[7];
        t = DAT_a802d040[8];
        o = DAT_a802d040[9];
    } else if (port == 3) {
        h = DAT_a802d098[7];
        t = DAT_a802d098[8];
        o = DAT_a802d098[9];
    } else {
        h = DAT_a802d0d0[7];
        t = DAT_a802d0d0[8];
        o = DAT_a802d0d0[9];
    }
    if (h < '0' || h > '1')
        return 0xff;
    if (t < '0' || t > '9')
        return 0xff;
    if (o < '0' || o > '9')
        return 0xff;
    h -= '0';
    t -= '0';
    o -= '0';
    r = h * 100 + t * 10 + o;
    return r;
}
