/* leon2m FUN_a00a31a4 @ 0xa00a31a4-0xa00a3838 (421 words), flags -mcpu=v8 -O3 -g -msoft-float. Called by many screen functions
 * (FUN_a008ac00, FUN_a00aa9d8, FUN_a00b9750, ...).
 * Draws the length-prefixed byte string s (s[0] = length): DAT_a802aff4 = p4; pass 1 sums FUN_a00a3024(font, c)
 * over the bytes that are not font codes (0xf0..0xfe select the font, start 0xf0) into DAT_a802b088; the start
 * position pos from FUN_a0146bb4(p6): 0 -> 0, 1 -> (p4 * FUN_a0146e24() - w) % FUN_a0146e24(), 2 -> the remainder
 * plus FUN_a0146e24() when the quotient is odd, halved; FUN_a0146324(p6) words of DAT_a802aff8 cleared and
 * FUN_a0146be8(p6); pass 2 ORs the glyph columns FUN_a00a2eec(font, k + c * h) shifted by pos into DAT_a802aff8 and
 * flushes full columns with FUN_a0146c00(DAT_a802aff8, p6); a final flush when pos != 0, then
 * FUN_a0146c14(p1, x, y, p4, p6).
 * Source form: m = p6 copy for the calls (p6 itself only in the final call: fw stb %i5 to its stack slot at
 * 0xa00a31d4, reloaded for the final call at 0xa00a33f4 and 0xa00a3534); base as unsigned short (only used as
 * k + base for FUN_a00a2eec's 16-bit index); in the 2 case the remainder, the odd-quotient addition and the
 * halving are computed in pos itself (no separate local); wd as unsigned char (FUN_a00a3024's return type); for
 * pos < 0x10 and for larger pos the same OR loop is written in two arms (two fw copies: 0xa00a3778-0xa00a37cc and
 * 0xa00a37e0-0xa00a3834).
 */
extern unsigned char DAT_a802aff4;
extern unsigned short DAT_a802b088;
extern unsigned int DAT_a802aff8[];
extern unsigned char FUN_a00a3024(unsigned char c, unsigned short n);
extern unsigned int FUN_a00a2eec(unsigned char sel, unsigned short n);
extern unsigned char FUN_a0146bb4(unsigned char);
extern unsigned char FUN_a0146e24(void);
extern unsigned char FUN_a0146324(unsigned char);
extern void FUN_a0146be8(unsigned char);
extern void FUN_a0146c00(unsigned int *, unsigned char);
extern void FUN_a0146c14(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char);

void FUN_a00a31a4(unsigned char p1, unsigned short x, unsigned short y, unsigned char p4, unsigned char *s,
                  unsigned char p6)
{
    unsigned char len, i, k, h, pos;
    unsigned char wd;
    char font;
    unsigned short w;
    unsigned short t;
    unsigned short base;
    unsigned char c;
    unsigned char m;

    m = p6;
    DAT_a802aff4 = p4;
    len = s[0] + 1;
    font = 0xf0;
    w = 0;
    for (i = 1; i < len; i++) {
        if (s[i] == 0xf0)
            font = 0xf0;
        else if (s[i] == 0xf2)
            font = 0xf2;
        else if (s[i] == 0xf1)
            font = 0xf1;
        else if (s[i] == 0xf4)
            font = 0xf4;
        else if (s[i] == 0xf3)
            font = 0xf3;
        else if (s[i] == 0xf5)
            font = 0xf5;
        else if (s[i] == 0xf6)
            font = 0xf6;
        else if (s[i] == 0xf7)
            font = 0xf7;
        else if (s[i] == 0xf8)
            font = 0xf8;
        else if (s[i] == 0xf9)
            font = 0xf9;
        else if (s[i] == 0xfa)
            font = 0xfa;
        else if (s[i] == 0xfb)
            font = 0xfb;
        else if (s[i] == 0xfc)
            font = 0xfc;
        else if (s[i] == 0xfd)
            font = 0xfd;
        else if (s[i] == 0xfe)
            font = 0xfe;
        else
            w += FUN_a00a3024(font, s[i]);
    }
    DAT_a802b088 = w;
    if (FUN_a0146bb4(m) == 0)
        pos = 0;
    else if (FUN_a0146bb4(m) == 1) {
        t = DAT_a802aff4 * FUN_a0146e24() - w;
        pos = (int)t % FUN_a0146e24();
    } else if (FUN_a0146bb4(m) == 2) {
        t = DAT_a802aff4 * FUN_a0146e24() - w;
        k = (int)t / FUN_a0146e24();
        pos = (int)t % FUN_a0146e24();
        if (k & 1)
            pos += FUN_a0146e24();
        pos = pos >> 1;
    }
    h = FUN_a0146324(m);
    for (k = 0; k < h; k++)
        DAT_a802aff8[k] = 0;
    FUN_a0146be8(m);
    font = 0xf0;
    for (i = 1; i < len; i++) {
        if (s[i] == 0xf0)
            font = 0xf0;
        else if (s[i] == 0xf2)
            font = 0xf2;
        else if (s[i] == 0xf1)
            font = 0xf1;
        else if (s[i] == 0xf4)
            font = 0xf4;
        else if (s[i] == 0xf3)
            font = 0xf3;
        else if (s[i] == 0xf5)
            font = 0xf5;
        else if (s[i] == 0xf6)
            font = 0xf6;
        else if (s[i] == 0xf7)
            font = 0xf7;
        else if (s[i] == 0xf8)
            font = 0xf8;
        else if (s[i] == 0xf9)
            font = 0xf9;
        else {
            c = s[i];
            if (c == 0xfa)
                font = 0xfa;
            else if (c == 0xfb)
                font = 0xfb;
            else if (c == 0xfc)
                font = 0xfc;
            else if (c == 0xfd)
                font = 0xfd;
            else if (c == 0xfe)
                font = 0xfe;
            else {
            wd = FUN_a00a3024(font, c);
            base = c * h;
            if (pos == 0) {
                for (k = 0; k < h; k++)
                    DAT_a802aff8[k] = FUN_a00a2eec(font, k + base);
            } else if (pos < 0x10) {
                for (k = 0; k < h; k++)
                    DAT_a802aff8[k] |= FUN_a00a2eec(font, k + base) >> pos;
            } else {
                for (k = 0; k < h; k++)
                    DAT_a802aff8[k] |= FUN_a00a2eec(font, k + base) >> pos;
            }
            pos += wd;
            do {
                if (FUN_a0146e24() == pos) {
                    FUN_a0146c00(DAT_a802aff8, m);
                    pos = 0;
                } else if (FUN_a0146e24() < pos) {
                    FUN_a0146c00(DAT_a802aff8, m);
                    pos -= FUN_a0146e24();
                    for (k = 0; k < h; k++)
                        DAT_a802aff8[k] = FUN_a00a2eec(font, k + base) << (wd - pos);
                }
            } while (pos > FUN_a0146e24() - 1);
            }
        }
    }
    if (pos != 0)
        FUN_a0146c00(DAT_a802aff8, m);
    FUN_a0146c14(p1, x, y, p4, p6);
}
