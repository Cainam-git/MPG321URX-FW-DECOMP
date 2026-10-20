/* FUN_a0083ed0 (leon2s, 0xa0083ed0-0xa0083f04, 13 words). Flags -mcpu=v8 -Os -g.
 * u8 a. If (u8)FUN_a0083ec4() == 1 returns a != 0, else a == 0 (cmp %g0 + addx / subx), masked & 1.
 * FUN_a0083ec4 takes no argument (the firmware never sets %o0 after the save; the 'and %i0,0xff' in the call
 * delay slot is for a). u8 types.
 */
extern unsigned char FUN_a0083ec4(void);

unsigned char FUN_a0083ed0(unsigned char a)
{
    unsigned char result;

    if (FUN_a0083ec4() == 1)
        result = (a != 0);
    else
        result = (a == 0);
    return result & 1;
}
