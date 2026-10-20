/* leon2m FUN_a0149f44 @ 0xa0149f44-0xa0149fb8 (29 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/29 mismatches.
 * Code facts: ch = port for port 0..3, else 0xff (case tree root 1, the FUN_a014ba68 switch form);
 * ch <= 3 -> sibcall FUN_a013d684(ch); else log FUN_a00df170(s_001a6dd8) and sibcall FUN_a013d684(0).
 * port is a u8 param. Fixes vs the autoc draft (51.72): FUN_a013d684 takes 1 arg (the draft passed
 * 4), the string is a symbol, and the ch <= 3 arm comes first in the source. Aids: none.
 */
extern const char s_001a6dd8[];
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a013d684(unsigned char);

void FUN_a0149f44(unsigned char port)
{
    unsigned char ch;

    switch (port) {
    case 0: ch = 0; break;
    case 1: ch = 1; break;
    case 2: ch = 2; break;
    case 3: ch = 3; break;
    default: ch = 0xff; break;
    }
    if (ch <= 3) {
        FUN_a013d684(ch);
        return;
    }
    FUN_a00df170(s_001a6dd8);
    FUN_a013d684(0);
}
