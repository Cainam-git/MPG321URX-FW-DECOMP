/* leon2m FUN_a0104d18 @ 0xa0104d18-0xa0104e50 (78 words).
 * a outside 25..500 is replaced by 100, b outside 5..5000 by 150. d = 1500 / a and v = ((a * b) << 15) / 15000000
 * (both as bytes) go to the register pairs 0xcf012898 / 0xcf01289c and 0xcf012998 / 0xcf01299c; bit 7 of
 * 0xcf012898 and 0xcf012998 is then set. Bit 0 of 0xcf012890 and 0xcf012990 is set when bit 26 of the word that
 * DAT_a802d6a4 points to is set, and cleared otherwise.
 * Source form: range tests written as !(x >= lo && x <= hi) (a || of the two compares gives other code).
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned int *DAT_a802d6a4;

void FUN_a0104d18(unsigned short a, unsigned short b)
{
    unsigned char d, v;

    if (!(a >= 25 && a <= 500))
        a = 100;
    if (!(b >= 5 && b <= 5000))
        b = 150;
    d = 1500 / a;
    v = ((unsigned int)(b * a) << 15) / 15000000;
    R(0xcf012898) = d;
    R(0xcf01289c) = v;
    R(0xcf012898) |= 0x80;
    R(0xcf012998) = d;
    R(0xcf01299c) = v;
    R(0xcf012998) |= 0x80;
    if (*DAT_a802d6a4 & 0x4000000) {
        R(0xcf012890) |= 1;
        R(0xcf012990) |= 1;
    } else {
        R(0xcf012890) &= ~1;
        R(0xcf012990) &= ~1;
    }
}
