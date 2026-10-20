/* leon2s FUN_a00c9798 @ 0xa00c9798-0xa00c9810 (30 words), flags -mcpu=v8 -Os -g.
 * Code facts: r = (u8)FUN_a00c8048(port, 0x74, 0x70, 2); r != 0 -> log func_0xa0f83044(s_9f1c20b8, r),
 * return r. Else r = (u8)FUN_a00c81f8(port, buf, 2); r != 0 -> log(s_9f1c20d8, r), return r; else 0.
 * Returns u8. Fixes vs the autoc draft (53.33): two early-return checks (the draft mixed the two
 * results), the strings as symbols, 2nd param is the buffer pointer passed through. Aids: none.
 */
extern const char s_9f1c20b8[];
extern const char s_9f1c20d8[];
extern unsigned int FUN_a00c8048(unsigned char, int, int, int);
extern unsigned int FUN_a00c81f8(unsigned char, unsigned char *, unsigned char);
extern int func_0xa0f83044(const char *, ...);

unsigned char FUN_a00c9798(unsigned char port, unsigned char *buf)
{
    unsigned char r;

    r = FUN_a00c8048(port, 0x74, 0x70, 2);
    if (r != 0) {
        func_0xa0f83044(s_9f1c20b8, r);
        return r;
    }
    r = FUN_a00c81f8(port, buf, 2);
    if (r != 0) {
        func_0xa0f83044(s_9f1c20d8, r);
        return r;
    }
    return 0;
}
