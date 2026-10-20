/* leon2s FUN_a00a6190 @ 0xa00a6190-0xa00a61d4 (17 words), flags -mcpu=v8 -Os -g.
 * Code facts: leaf. port 'Q' (0x51): returns 1 if byte DAT_a807d80d == 1; port 'a' (0x61):
 * returns 1 if byte DAT_a807d99d == 1; any other port returns 0 (u8, '& 1'). The two flags are
 * +0xd of two 0x190-byte records from 0xa807d800 (both loads crossjump into one compare).
 * Fix vs the autoc draft (83.33): BEHAVIOUR: an unknown port returns 0 (the draft set the value to
 * 1 and returned 1); nested 'if (flag == 1) r = 1' per port arm. Aids: none.
 */
extern unsigned char DAT_a807d80d;
extern unsigned char DAT_a807d99d;

unsigned char FUN_a00a6190(unsigned char port)
{
    unsigned char r = 0;

    if (port == 'Q') {
        if (DAT_a807d80d == 1)
            r = 1;
    } else if (port == 'a') {
        if (DAT_a807d99d == 1)
            r = 1;
    }
    return r & 1;
}
