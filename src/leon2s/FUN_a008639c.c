/* leon2s FUN_a008639c @ 0xa008639c-0xa00863d4 (14 words), flags -mcpu=v8 -Os -g.
 * r = FUN_a00862e4((u8)a, (u8)b, c, 0, d) (5 args, %o3 = 0); returns 0 if (u8)r == 1, else 0xff
 * (firmware xor 1 / cmp / subx / and 0xff).
 */
extern unsigned char FUN_a00862e4(unsigned char, unsigned char, unsigned int, int, unsigned int);

unsigned char FUN_a008639c(unsigned char a, unsigned char b, unsigned int c, unsigned int d)
{
    if (FUN_a00862e4(a, b, c, 0, d) == 1)
        return 0;
    return 0xff;
}
