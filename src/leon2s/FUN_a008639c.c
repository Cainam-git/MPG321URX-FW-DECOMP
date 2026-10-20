/* leon2s FUN_a008639c @ 0xa008639c-0xa00863d4 (14 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches / 14 words.
 * Code facts: r = FUN_a00862e4((u8)a, (u8)b, c, 0, d) (5 args, %o3 = 0); returns 0 if (u8)r == 1, else 0xff
 * (fw xor 1 / cmp / subx / and 0xff).
 * Fix vs the autoc draft (78.57): BEHAVIOUR - the result is 0 / 0xff on r == 1 (the draft returned r == 0 as 0/1).
 * Aids: none.
 */
extern unsigned char FUN_a00862e4(unsigned char, unsigned char, unsigned int, int, unsigned int);

unsigned char FUN_a008639c(unsigned char a, unsigned char b, unsigned int c, unsigned int d)
{
    if (FUN_a00862e4(a, b, c, 0, d) == 1)
        return 0;
    return 0xff;
}
