/* leon2s FUN_a00d2e00 @ 0xa00d2e00-0xa00d2e9c (39 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/39 mismatches.
 * Code facts: m = byte DAT_a8078c37. m 0/1: r = func_0xa0fa0f0c(0/1); m 2/3: r =
 * func_0xa0fb268c(0/1); m 4/5: r = 1 if bit 3 of func_0xa0fb6f78(0/1, 5) is set, else 0; other m:
 * r = 0. Returns r (u8). Each callee pair shares one call (crossjump; the 0/1 arg is set in the
 * branch delay slots).
 * Fix vs the autoc draft (81.40): BEHAVIOUR: m == 4 also tests bit 3 of the 6f78 result (the draft
 * returned the raw result for 4). Aids: none.
 */
extern unsigned char DAT_a8078c37;
extern unsigned char func_0xa0fa0f0c(unsigned char);
extern unsigned char func_0xa0fb268c(unsigned char);
extern unsigned int func_0xa0fb6f78(unsigned char, unsigned char);

unsigned char FUN_a00d2e00(void)
{
    unsigned char r = 0;
    unsigned char m = DAT_a8078c37;

    if (m == 0)
        r = func_0xa0fa0f0c(0);
    else if (m == 1)
        r = func_0xa0fa0f0c(1);
    else if (m == 2)
        r = func_0xa0fb268c(0);
    else if (m == 3)
        r = func_0xa0fb268c(1);
    else if (m == 4) {
        if (func_0xa0fb6f78(0, 5) & 8)
            r = 1;
    } else if (m == 5) {
        if (func_0xa0fb6f78(1, 5) & 8)
            r = 1;
    }
    return r;
}
