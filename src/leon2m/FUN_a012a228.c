/* leon2m FUN_a012a228 @ 0xa012a228-0xa012a2f0 (50 words).
 * Returns 0 when the word DAT_a802ca0c is 0. Otherwise compares the 16 words DAT_a802ca9c[i] with DAT_a802ca5c[i]:
 * n counts the entries whose absolute difference (taken as unsigned short) is above 0x40; the byte run counts
 * such entries in a row in its low bits (reset to its bit 7 on an entry within 0x40) and gets bit 7 set once
 * more than one were in a row. Returns 0 when n < 3 and bit 7 of run is set, else 1 when n != 0, else 0.
 * No direct callers (reached through a pointer).
 * Source form: the two final conditions are int locals combined with '&' (the firmware computes both as values
 * and tests their AND); bit 7 of run is computed before n < 3.
 */
extern int abs(int);
extern int DAT_a802ca0c;
extern int DAT_a802ca5c[16];
extern int DAT_a802ca9c[16];

unsigned char FUN_a012a228(void)
{
    unsigned char i, n, run;
    unsigned short d;
    int a;
    int hit, few;

    if (DAT_a802ca0c == 0)
        return 0;
    n = 0;
    run = 0;
    for (i = 0; i < 16; i++) {
        a = DAT_a802ca9c[i] - DAT_a802ca5c[i];
        d = abs(a);
        if (d > 0x40) {
            n++;
            run++;
            if (run > 1)
                run |= 0x80;
        } else
            run &= 0x80;
    }
    hit = (run & 0x80) != 0;
    few = n < 3;
    if (few & hit)
        return 0;
    return n != 0;
}
